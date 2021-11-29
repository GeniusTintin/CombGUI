#pragma once
#include "FileReader.h"
#include "UserSize.h"
#include <string>
//#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <msclr/marshal_cppstd.h>

#define COMB_FTYPE CV_64FC1

namespace CombFilter {
	class combFilter {
	public:


		struct flickerInfo {

			bool flicker_gen;
			int32_t flicker_freq;
			int32_t startx;
			int32_t starty;
			int32_t side_len;
			int32_t noise_range;
		};

		combFilter(std::string path, std::string filename, double basefreq, int32_t filtering_method, double publish_framerate, double mtr, flickerInfo flicker_profile);

		virtual ~combFilter();
		void eventsCallback();

	private:

		void initialise_image_states(const uint32_t& rows, const uint32_t& columns);
		void initialise_buffer(const uint32_t& rows, const uint32_t& columns);
		void integral_tracking(const int x, const int y, const double ts, const bool polarity, int filtering_method);
		void store2buffer(const cv::Mat& figx, const cv::Mat& figy);
		void grab_delay(cv::Mat& sel, const int delay, const int which_buffer);
		void exp_of_log(cv::Mat& converted_image);
		inline void wait_on_enter();
		void write_log(std::string filename, std::string content);
		void publish_intensity_estimate();

		// flickering generator
		void initialise_flickering_generator();
		void flickering_generator(); // used for flickering generating

		FileReader::fileReader* myReaderPtr_;

		bool initialised_ = false;
		double base_frequency_;
		int filtering_method_ = 0;

		// ring buffer
		cv::Mat* ring_buffer1_ = nullptr;
		cv::Mat* ring_buffer2_ = nullptr;
		uint32_t buffer_length_ = 0;
		uint32_t buffer_index_ = 0;

		uint32_t img_height_ = 0;
		uint32_t img_width_ = 0;
		std::string window_name_ = "My Image Window";

		// delayed integrated events
		cv::Mat x0_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat x_d1_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat x_d2_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat x_d12_ = cv::Mat::zeros(1, 1, COMB_FTYPE);

		// delayed output
		cv::Mat y0_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat y_d1_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat y_d2_ = cv::Mat::zeros(1, 1, COMB_FTYPE);
		cv::Mat y_d12_ = cv::Mat::zeros(1, 1, COMB_FTYPE);

		cv::Mat ts_ = cv::Mat::zeros(1, 1, COMB_FTYPE);

		// user defined size
		bool user_defined_size_ = false;

		// time delay
		double d1_ = 0;
		double d2_ = 0;
		double d12_ = 0;

		// delay gain
		double rho1_ = 0;
		double rho2_ = 0;

		// minimul time resolution
		double mtr_ = 1e2;
		double t_next_store_ = 0.0;

		// publish parameters
		double publish_framerate_ = 1e3;
		double t_next_publish_ = 0.0;

		// cutoff frequency
		double cutoff_freq_global_ = 0;
		double cutoff_freq_per_event_component_ = 0;
		double event_count_cutoff_freq_ = 0;

		// contrast threshold 
		double contrast_threshold_on_user_defined_ = 0.1;
		double contrast_threshold_off_user_defined_ = 0.1;


		// for flickering generator
		bool first_ts_ = 0;
		bool skipped_ = 0; // whether to skip read of next line
		bool current_ts_checked_ = 0;
		int64_t current_ts_ = 0;
		int flickering_polarity_ = 1; // the on and off of the generated flickering
		bool first_flicker_ = true;

		int32_t flickering_frequency_ = 0;
		bool flicker_gen_ = false;
		int32_t startx_;
		int32_t starty_;
		int32_t side_len_;
		int32_t noise_range_;

	};

} // CombFilter 

// Dingran Yuan
