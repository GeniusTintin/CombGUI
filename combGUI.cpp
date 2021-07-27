#include "combGUI.h"

[System::STAThreadAttribute]

void extract_number_from_string(std::string target_str, int32_t& x, int32_t& y, char c);



void main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	CombGUI::combGUI form;
	//form.Show();
	System::Windows::Forms::Application::Run(% form);

	std::string path = *form.pathPtr;
	std::string filename = *form.filenamePtr;
	int32_t filtering_method = form.filtering_method;
	double basefreq = form.basefreq;
	double publish_framerate = form.publish_framerate;
	double mtr = form.mtr;

	// flickering generator
	bool flicker_gen = form.flickering_gen;
	int32_t flicker_freq = form.flickering_freq;
	int32_t side_len = form.side_length;
	std::string starting_point = *form.starting_point;

	int32_t startx, starty;
	char c = ',';
	extract_number_from_string(starting_point, startx, starty, c);

	CombFilter::combFilter::flickerInfo flicker_profile;

	flicker_profile.flicker_gen = flicker_gen;
	flicker_profile.flicker_freq = flicker_freq;
	flicker_profile.startx = startx;
	flicker_profile.starty = starty;
	flicker_profile.side_len = side_len;

	CombFilter::combFilter myFilter(path, filename, basefreq, filtering_method, publish_framerate, mtr, flicker_profile);

	myFilter.eventsCallback();
	
}

void extract_number_from_string(std::string target_str, int32_t& x, int32_t& y, char c) {
	// extract number from target_str separated by c

	int i = 0;
	while (target_str.at(i) != c) {
		i++; // it will return the position where target_str[i] == c
	}

	x = std::stoi(target_str.substr(0, i + 1)); // separate out the x position
	y = std::stoi(target_str.substr(i + 1, target_str.length() - i - 1)); // separate out the y position

}
