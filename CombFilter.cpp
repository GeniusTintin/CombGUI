#define _USE_MATH_DEFINES
#include "CombFilter.h"
#include "combGUI.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <msclr/marshal_cppstd.h>
#include <random>
#include <chrono>

namespace CombFilter {

	combFilter::combFilter(std::string path, std::string filename, double basefreq, int32_t filtering_method, double publish_framerate, double mtr, flickerInfo flicker_profile) {

		static FileReader::fileReader eventReader(path, filename);
		myReaderPtr_ = &eventReader;
		base_frequency_ = basefreq;
		filtering_method_ = filtering_method;
		publish_framerate_ = publish_framerate;
		mtr_ = mtr;

		// flickering generator information
		flicker_gen_ = flicker_profile.flicker_gen;
		flickering_frequency_ = flicker_profile.flicker_freq;
		startx_ = flicker_profile.startx;
		starty_ = flicker_profile.starty;
		side_len_ = flicker_profile.side_len;
		noise_range_ = flicker_profile.noise_range;
	}

	combFilter::~combFilter() {

		// free the buffer space before exit
		delete[] ring_buffer1_;
		delete[] ring_buffer2_;
	}

	void combFilter::eventsCallback() {

		//FileReader::fileReader myReader;
		// the first line of the dataset is designed to be the image information state

		bool iseof = false;
		myReaderPtr_->readOneLine(iseof);
		if (iseof) {
			//std::cout << "ERROR: Void package." << std::endl;
			return;
		}

		uint8_t title = myReaderPtr_->eData_.polarity;

		if (title >= 2) {

			img_height_ = myReaderPtr_->eData_.y;
			img_width_ = myReaderPtr_->eData_.x;
		}
		else {

			//user_size_input();
			CombGUI::UserSize userform;
			System::Windows::Forms::Application::Run(% userform);


			img_height_ = userform.height;
			img_width_ = userform.width;
		}

		if (!initialised_) {

			// initialise image parameters
			initialise_image_states(img_height_, img_width_);
		}

			int32_t x = -1; // set a marker that will trigger a flickering generator
			int32_t y = -1;
			int64_t ts = -1;
			int8_t polarity = -1;

																									
		while (!iseof) {

			// setup flickering generator information

			if (flicker_gen_) {
				if (ts > current_ts_  /*+ myReaderPtr_->timeResolution_ / (flickering_frequency_ * 2)*/ ) {
					skipped_ = 1;
					if (first_ts_) {
						current_ts_ = myReaderPtr_->eData_.ts;
						first_ts_ = false;
						skipped_ = 0;
					}
				}
				else {
					skipped_ = 0;
				}
			}
			else {
				skipped_ = 0;
			}
			
			

			if (!skipped_) {
				myReaderPtr_->readOneLine(iseof);

				// declear variable
				x = myReaderPtr_->eData_.x;
				y = myReaderPtr_->eData_.y;
				ts = myReaderPtr_->eData_.ts;
				polarity = myReaderPtr_->eData_.polarity;

				current_ts_ = ts;

				
			}
			
			
			// travel through all the possible x and y
			if ((x >= 0 && x < img_width_ && y >= 0 && y < img_height_) || (x==-1 || y==-1)) {
	
				// if is the first ts, note that down to save it for later flickering genreator reference
				// current_ts_ is the current flickering time stamp
				// first_ts_ is the boolean type that suggest that if it's at the beginning of the event file
				if (first_ts_) {
					current_ts_ = ts;
					first_ts_ = false;
				}
				

				// grab delay and calculate y0_
				while (current_ts_ > t_next_store_/*|| current_ts_ < ts*/) {
					if (t_next_store_ == 0) {
						t_next_store_ = ts;
					}

					cv::Mat x0_e = cv::Mat::zeros(img_height_, img_width_, COMB_FTYPE);
					exp_of_log(x0_e);

					grab_delay(x_d1_, int(d1_), 1);
					grab_delay(x_d2_, int(d2_), 1);
					grab_delay(x_d12_, int(d12_), 1);

					grab_delay(y_d1_, int(d1_), 2);
					grab_delay(y_d2_, int(d2_), 2);
					grab_delay(y_d12_, int(d12_), 2);

					// calculate new y0_
					switch (filtering_method_) {
					case 1: {
						y0_ = x0_e; // direct integration
						break;
					}
					case 2: {
						y0_ = x0_e - x_d1_; // simple version of comb (no dc)
						break;
					}
					default: {
						y0_ = x0_e - x_d1_ - rho2_ * x_d2_ + rho2_ * x_d12_ + rho1_ * y_d1_ + y_d2_ - rho1_ * y_d12_;
					}
					}
					
					
					store2buffer(x0_e, y0_);
					t_next_store_ += myReaderPtr_->timeResolution_ / mtr_;


					// publish frame between generated flickers
					if (publish_framerate_ > 0 && (ts >= t_next_publish_ || current_ts_ >= t_next_publish_)) {

						publish_intensity_estimate();
						t_next_publish_ = ts + myReaderPtr_->timeResolution_ / publish_framerate_;
					}

				}
				// integral tracking
				if (!skipped_) {
					integral_tracking(x, y, ts, polarity, filtering_method_);
				}
				else{
					if (side_len_ >= img_height_ || side_len_ >= img_width_) {
						System::Windows::Forms::MessageBox::Show("Flickering region out of boundary", "Warning", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
						break;
					}
					flickering_generator();
					if (noise_range_) {
						unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
						std::default_random_engine generator(seed);
						// noise_range/3 (3 * sigma)
						std::normal_distribution<double> distribution(0.0, noise_range_ / 3);
						//distribution(generator);
						//current_ts_ += myReaderPtr_->timeResolution_ /((flickering_frequency_ + rand() % (2*noise_range_) - noise_range_ )*2);
						current_ts_ += myReaderPtr_->timeResolution_ / ((flickering_frequency_ + distribution(generator)) * 2);
						
					}
					else {
						current_ts_ += myReaderPtr_->timeResolution_ / (flickering_frequency_ * 2);
					}
					
				}	

			}
		}
	}

	void combFilter::initialise_image_states(const uint32_t& rows, const uint32_t& columns) {

		t_next_publish_ = 0.0;

		cutoff_freq_global_ = 0.06 * 2 * M_PI;
		cutoff_freq_per_event_component_ = 0.06;
		contrast_threshold_on_user_defined_ = 0.1;
		contrast_threshold_off_user_defined_ = -0.1;

		// delayed version of integrated events
		x0_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		x_d1_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		x_d2_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		x_d12_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);

		// delayed version of output
		y0_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		y_d1_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		y_d2_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);
		y_d12_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);

		ts_ = cv::Mat::zeros(rows, columns, COMB_FTYPE);

		d1_ = 1 * myReaderPtr_->timeResolution_ / base_frequency_;
		d2_ = d1_ / 10;
		d12_ = d1_ + d2_;

		// delay gain
		rho1_ = 0.9;
		rho2_ = 0.99;

		cv::namedWindow(window_name_, cv::WINDOW_NORMAL);

		// TODO:
		initialise_flickering_generator();

		initialise_buffer(rows, columns);

		initialised_ = true;

	}

	void combFilter::initialise_buffer(const uint32_t& rows, const uint32_t& columns) {

		// minimum time resolution
		//mtr_ = 1e5; // NOTE: this should be 1e-5, but due to the accuracy of the floating point number we use positive index here!
		t_next_store_ = 0.0;
		buffer_length_ = int(d12_ * mtr_ / myReaderPtr_->timeResolution_ + 1);
		buffer_index_ = 0;

		// FIXME: validate that the buffer size is correctly constructed
		/*
		std::cout << "tao1:" << d1_ / myReaderPtr_->timeResolution_ << " tao2:" << d2_ / myReaderPtr_->timeResolution_ << " tao12:" << d12_ / myReaderPtr_->timeResolution_ << std::endl;
		std::cout << "mtr_ = " << 1 / mtr_ << std::endl;
		std::cout << "Buffer length:" << buffer_length_ << std::endl;
		wait_on_enter();
		*/
		

		ring_buffer1_ = new cv::Mat[buffer_length_];
		ring_buffer2_ = new cv::Mat[buffer_length_];

		// zero initialisation for all buffers
		for (int i = 0; i < buffer_length_; i++) {

			cv::Mat temp = cv::Mat::zeros(rows, columns, COMB_FTYPE);
			temp.copyTo(ring_buffer1_[i]);
			temp.copyTo(ring_buffer2_[i]);
		}
	}

	void combFilter::integral_tracking(const int x, const int y, double ts, const bool polarity, const int filtering_method) {

		double c_times_p;

		c_times_p = (polarity) ? contrast_threshold_on_user_defined_ : contrast_threshold_off_user_defined_;

		ts = ts / myReaderPtr_->timeResolution_;

		if (filtering_method == 1 && filtering_method == 2) {
			x0_.at<double>(y, x) = x0_.at<double>(y, x) + c_times_p;
		}
		else {
			x0_.at<double>(y, x) = x0_.at<double>(y, x) * exp(-(ts - ts_.at<double>(y, x)) * 5 * M_PI) + c_times_p;
			ts_.at<double>(y, x) = ts;
		}
		

	}

	void combFilter::store2buffer(const cv::Mat& figx, const cv::Mat& figy) {

		// buffer index of input and output is the same
		figx.convertTo(figx, CV_64FC1, 1);

		figx.copyTo(ring_buffer1_[buffer_index_]);
		figy.copyTo(ring_buffer2_[buffer_index_]);

		buffer_index_++;

		if (buffer_index_ == buffer_length_) {
			buffer_index_ = 0;
		}

		// after storing, the index is pointing to the next store location
	}

	void combFilter::grab_delay(cv::Mat& sel, const int delay, const int which_buffer) {

		int index_offset = delay * mtr_ / myReaderPtr_->timeResolution_;
		int index = buffer_index_ - index_offset;

		if (index < 0) {
			index = buffer_length_ + index;
		}

		if (which_buffer == 1) {
			ring_buffer1_[index].copyTo(sel);
		}
		else {
			ring_buffer2_[index].copyTo(sel);
		}
	}

	void combFilter::exp_of_log(cv::Mat& converted_image) {

		double LOG_INTENSITY_OFFSET = std::log(1.5);

		x0_.copyTo(converted_image);

		converted_image += LOG_INTENSITY_OFFSET;
		cv::exp(converted_image, converted_image);
		converted_image -= 1;
	}

	void combFilter::publish_intensity_estimate() {

		cv::Mat display_image;
		if (filtering_method_ == 2) {
			y0_.copyTo(display_image);
			display_image += 0.5;
			display_image.convertTo(display_image, CV_8UC1, 255.0);
		}
		else {
			y0_.convertTo(display_image, CV_8UC1, 255.0);
		}
		
		cv::imshow(window_name_, display_image);
		cv::waitKey(1);
	}

	inline void combFilter::wait_on_enter() {

		std::cout << "Enter to continue..." << std::endl;
		std::cin.ignore().get();
	}

	void combFilter::write_log(std::string filename, std::string content) {

		std::string path = "D:\\Home\\MyProjects\\VisualStudio\\repos\\CombConsole\\";
		path += filename;
		std::ofstream file2write;
		file2write.open(path, std::ios_base::app); // append instead of overwrite
		file2write << content << std::endl;
	}


	// flickering generator

	void combFilter::initialise_flickering_generator() {
		// for flickering generator

		first_ts_ = true;
		skipped_ = false; // whether to skip read of next line
		current_ts_checked_ = false;
		current_ts_ = 0;
		flickering_polarity_ = 1; // the on and off of the generated flickering
		first_flicker_ = true;
	}

	void combFilter::flickering_generator() {

		// generate flickering for all pixels
		int multiplier = 0;
		if (first_flicker_) {
			multiplier = 1;
			first_flicker_ = false;
		}
		else {
			multiplier = 2;
		}

		for (int i = startx_; i < startx_ + side_len_; i++) {
			for (int j = starty_; j < starty_ + side_len_; j++) {
				// generated events for selected pixel
				x0_.at<double>(i, j) += multiplier * flickering_polarity_ * contrast_threshold_on_user_defined_;
				
			}
		}

		// flip the polarity after each flickering
		flickering_polarity_ = -flickering_polarity_; 
	}
}

// Dingran Yuan