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
		
		double basefreq;
		int32_t filtering_method;
		int32_t publish_framerate;
		std::string* pathPtr;
		std::string* filenamePtr;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(30, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(391, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
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
			this->textBox1->Text = L"square_generated.txt";
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
			this->textBox2->Text = L"D:\\Home\\MyProjects\\VisualStudio\\repos\\CombGUI\\";
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
			this->radioButton1->Location = System::Drawing::Point(124, 205);
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
			this->radioButton2->Location = System::Drawing::Point(124, 228);
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
			this->radioButton3->Location = System::Drawing::Point(124, 251);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(98, 17);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Improved comb";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(124, 132);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"100";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Base Frequency";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Filtering Method";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(394, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 20);
			this->button2->TabIndex = 12;
			this->button2->Text = L"X";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &combGUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(394, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 20);
			this->button3->TabIndex = 13;
			this->button3->Text = L"X";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &combGUI::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(230, 132);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(20, 20);
			this->button4->TabIndex = 14;
			this->button4->Text = L"X";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &combGUI::button4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 168);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Publish Framerate";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(124, 164);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->Text = L"1000";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(230, 164);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(20, 20);
			this->button5->TabIndex = 17;
			this->button5->Text = L"X";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &combGUI::button5_Click);
			// 
			// combGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 320);
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
 
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//CombGUI::UserSize userform;
		//System::Windows::Forms::Application::Run(% userform);
		//userform.Show();
		static std::string path = msclr::interop::marshal_as<std::string>(this->textBox2->Text);
		static std::string filename = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		pathPtr = &path;
		filenamePtr = &filename;

		//extern FileReader::fileReader eventReader;
		publish_framerate = Convert::ToInt32(this->textBox4->Text);
		basefreq = Convert::ToDouble(this->textBox3->Text);
	
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
};
}
// Dingran Yuan