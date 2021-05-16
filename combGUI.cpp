#include "combGUI.h"

[System::STAThreadAttribute]

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

	CombFilter::combFilter myFilter(path, filename, basefreq, filtering_method, publish_framerate, mtr);

	myFilter.eventsCallback();

	
}