#pragma once
#include "UserSize.h"
#include "CombFilter.h"
#include "FileReader.h"

namespace CombGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CombGUI
	/// </summary>
	public ref class combGUI : public System::Windows::Forms::Form
	{
	public:
		combGUI(){
			InitializeComponent();
			//
			
			//
		}
		
		int32_t filtering_method;

		double basefreq;
		double publish_framerate;
		std::string* pathPtr;
		std::string* filenamePtr;
		double mtr;

		// parameter for flickering generator
		bool flickering_gen;  // add another bit for filter detector
		int32_t flickering_freq;
		std::string* starting_point;
		int32_t side_length;
		int32_t noise_range;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::CheckBox^ checkBox2;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox9;

	private: System::Windows::Forms::Button^ button5;
	public:
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~combGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(combGUI::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->button1->Location = System::Drawing::Point(30, 429);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(391, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &combGUI::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(124, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(264, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"events.txt";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(64, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"File Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(64, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"File Path";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(124, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(264, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"C:\\Users\\Tintin\\OneDrive - Australian National University\\ANU_D\\ENGN4200 Individu"
				L"al Project\\Dataset\\";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(124, 91);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(85, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Default Path";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &combGUI::checkBox1_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(124, 236);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(105, 17);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Direct integration";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(124, 259);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(52, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Comb";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Checked = true;
			this->radioButton3->Location = System::Drawing::Point(124, 282);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(98, 17);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Improved comb";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Location = System::Drawing::Point(124, 124);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"100";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Base Frequency";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 236);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Filtering Method";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::Azure;
			this->button2->ForeColor = System::Drawing::Color::DarkRed;
			this->button2->Location = System::Drawing::Point(394, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 20);
			this->button2->TabIndex = 12;
			this->button2->Text = L"X";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &combGUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::Azure;
			this->button3->ForeColor = System::Drawing::Color::DarkRed;
			this->button3->Location = System::Drawing::Point(394, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 20);
			this->button3->TabIndex = 13;
			this->button3->Text = L"X";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &combGUI::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::Azure;
			this->button4->ForeColor = System::Drawing::Color::DarkRed;
			this->button4->Location = System::Drawing::Point(230, 124);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(20, 20);
			this->button4->TabIndex = 14;
			this->button4->Text = L"X";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &combGUI::button4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Publish Framerate";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->Location = System::Drawing::Point(124, 156);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->Text = L"1000";
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button5->BackColor = System::Drawing::Color::Azure;
			this->button5->ForeColor = System::Drawing::Color::DarkRed;
			this->button5->Location = System::Drawing::Point(230, 156);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(20, 20);
			this->button5->TabIndex = 17;
			this->button5->Text = L"X";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &combGUI::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(352, 126);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(60, 60);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(27, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"MTR";
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->Location = System::Drawing::Point(124, 189);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 20;
			this->textBox5->Text = L"1e5";
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackColor = System::Drawing::Color::Azure;
			this->button6->ForeColor = System::Drawing::Color::DarkRed;
			this->button6->Location = System::Drawing::Point(230, 188);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(20, 20);
			this->button6->TabIndex = 21;
			this->button6->Text = L"X";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &combGUI::button6_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->checkBox2->Location = System::Drawing::Point(124, 322);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(208, 23);
			this->checkBox2->TabIndex = 22;
			this->checkBox2->Text = L"Flickering Generator";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &combGUI::checkBox2_CheckedChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(122, 351);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 24;
			this->textBox6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 354);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"Flickering Frequency";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(349, 350);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(69, 20);
			this->textBox7->TabIndex = 26;
			this->textBox7->Text = L"0,0";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(349, 386);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(69, 20);
			this->textBox8->TabIndex = 27;
			this->textBox8->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(276, 354);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Starting Point";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(282, 389);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Side Length";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(22, 389);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(87, 13);
			this->label10->TabIndex = 30;
			this->label10->Text = L"Noise Range (+-)";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(122, 386);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 31;
			this->textBox9->Text = L"0";
			// 
			// combGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(447, 476);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"combGUI";
			this->Text = L"CombGUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: 
	System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked) {
			textBox2->Text = "D:\\Home\\MyProjects\\VisualStudio\\repos\\CombGUI\\";
		}
		else {
			textBox2->Text = "";
		}
	}

	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox2->Checked) {
			textBox6->Text = "100"; // flickering frequency
			textBox7->Text = "0,0"; // starting point
			textBox8->Text = "100"; // side length
			textBox9->Text = "0";	// Noise range

			flickering_gen = true;
		}
		else {
			textBox6->Text = "0"; // flickering frequency
			textBox7->Text = "0,0"; // starting point
			textBox8->Text = "0"; // side length
			textBox9->Text = "0"; // Noise range

			flickering_gen = false;
		}
	}
 
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//CombGUI::UserSize userform;
		//System::Windows::Forms::Application::Run(% userform);
		//userform.Show();
		static std::string path = msclr::interop::marshal_as<std::string>(this->textBox2->Text);
		static std::string filename = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		static std::string starting_p = msclr::interop::marshal_as<std::string>(this->textBox7->Text);
		
		pathPtr = &path;
		filenamePtr = &filename;

		//extern FileReader::fileReader eventReader;
		publish_framerate = Convert::ToDouble(this->textBox4->Text);
		basefreq = Convert::ToDouble(this->textBox3->Text);
		mtr = Convert::ToDouble(this->textBox5->Text);
		//parameters for flickering generator
		flickering_freq = Convert::ToInt32(this->textBox6->Text); //int32_t
		side_length = Convert::ToInt32(this->textBox8->Text); //int32_t
		noise_range = Convert::ToInt32(this->textBox9->Text); //int32_t

		starting_point = &starting_p;

		if (this->checkBox2->Checked) {
			flickering_gen = true;
		}
		else {
			flickering_gen = false;
		}
	
		if (this->radioButton1->Checked) {
			filtering_method = 1;
		}
		else if(this->radioButton2->Checked){
			filtering_method = 2;
		}
		else {
			filtering_method = 3;
		}

		//eventReader.setParameter(path, filename);

		this->Close();
	}

	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		textBox1->Text = "";
	}

	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = "";
	}

	System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox3->Text = "";
	}

	System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox4->Text = "";
	}


	System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox5->Text = "";
	}



};
}
// Dingran Yuan