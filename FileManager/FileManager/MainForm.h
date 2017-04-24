#pragma once

#include <iostream>
#include <sstream>
#include "../../FileAndString/FileAndDirs.h"
#include "../../FileAndString/String.h"

namespace FileManager {

#define	NUM_ITEM				15
#define IMAGEPATH_TRUEIMAGE		"res\\true.png"
#define IMAGEPATH_FALSEIMAGE	"res\\false.png"
#define IMAGEPATH_MAINFORM		"res\\form.ico"
#define FILEPATH_CONFIG			"config.dat"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace TFileAndDirs;
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			this->Icon = gcnew System::Drawing::Icon(IMAGEPATH_MAINFORM);

			AddToArray();
			InitializeFilePath();
			LoadFromFile();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  FilePath1;
	private: System::Windows::Forms::Button^  btnConform1;
	private: System::Windows::Forms::Button^  btnConform2;
	private: System::Windows::Forms::TextBox^  FilePath2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnConform3;
	private: System::Windows::Forms::TextBox^  FilePath3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnConform4;
	private: System::Windows::Forms::TextBox^  FilePath4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnConform5;
	private: System::Windows::Forms::TextBox^  FilePath5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnConform6;
	private: System::Windows::Forms::TextBox^  FilePath6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  btnConform7;
	private: System::Windows::Forms::TextBox^  FilePath7;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  btnConform8;
	private: System::Windows::Forms::TextBox^  FilePath8;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btnConform9;
	private: System::Windows::Forms::TextBox^  FilePath9;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  btnConform10;
	private: System::Windows::Forms::TextBox^  FilePath10;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btnConform11;
	private: System::Windows::Forms::TextBox^  FilePath11;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Button^  btnConform12;
	private: System::Windows::Forms::TextBox^  FilePath12;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  btnConform13;
	private: System::Windows::Forms::TextBox^  FilePath13;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  btnConform14;
	private: System::Windows::Forms::TextBox^  FilePath14;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Button^  btnConform15;
	private: System::Windows::Forms::TextBox^  FilePath15;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::TextBox^  FolderName1;
	private: System::Windows::Forms::TextBox^  FolderName2;
	private: System::Windows::Forms::TextBox^  FolderName3;
	private: System::Windows::Forms::TextBox^  FolderName4;
	private: System::Windows::Forms::TextBox^  FolderName5;
	private: System::Windows::Forms::TextBox^  FolderName10;
	private: System::Windows::Forms::TextBox^  FolderName9;
	private: System::Windows::Forms::TextBox^  FolderName8;
	private: System::Windows::Forms::TextBox^  FolderName7;
	private: System::Windows::Forms::TextBox^  FolderName6;
	private: System::Windows::Forms::TextBox^  FolderName15;
	private: System::Windows::Forms::TextBox^  FolderName14;
	private: System::Windows::Forms::TextBox^  FolderName13;
	private: System::Windows::Forms::TextBox^  FolderName12;
	private: System::Windows::Forms::TextBox^  FolderName11;
	private: System::Windows::Forms::Button^  btnEdit1;
	private: System::Windows::Forms::Button^  btnEdit2;
	private: System::Windows::Forms::Button^  btnEdit3;
	private: System::Windows::Forms::Button^  btnEdit4;
	private: System::Windows::Forms::Button^  btnEdit8;
	private: System::Windows::Forms::Button^  btnEdit7;
	private: System::Windows::Forms::Button^  btnEdit6;
	private: System::Windows::Forms::Button^  btnEdit5;
	private: System::Windows::Forms::Button^  btnEdit12;
	private: System::Windows::Forms::Button^  btnEdit11;
	private: System::Windows::Forms::Button^  btnEdit10;
	private: System::Windows::Forms::Button^  btnEdit9;
	private: System::Windows::Forms::Button^  btnEdit15;
	private: System::Windows::Forms::Button^  btnEdit14;
	private: System::Windows::Forms::Button^  btnEdit13;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnSaveConfig;
	private:
		System::ComponentModel::Container ^components;
		String^		DestFolderName;
		array<System::Windows::Forms::Button^>^				btnConformArray;
		array<System::Windows::Forms::Button^>^				btnEditArray;
		array<System::Windows::Forms::TextBox^>^			txbFilePathArray;
		array<System::Windows::Forms::TextBox^>^			txbFolderNameArray;
		array<System::Windows::Forms::PictureBox^>^			pboxStatusArray;
		System::Drawing::Image^								picTrue;
		System::Drawing::Image^								picFalse;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FilePath1 = (gcnew System::Windows::Forms::TextBox());
			this->btnConform1 = (gcnew System::Windows::Forms::Button());
			this->btnConform2 = (gcnew System::Windows::Forms::Button());
			this->FilePath2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnConform3 = (gcnew System::Windows::Forms::Button());
			this->FilePath3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnConform4 = (gcnew System::Windows::Forms::Button());
			this->FilePath4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnConform5 = (gcnew System::Windows::Forms::Button());
			this->FilePath5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnConform6 = (gcnew System::Windows::Forms::Button());
			this->FilePath6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnConform7 = (gcnew System::Windows::Forms::Button());
			this->FilePath7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnConform8 = (gcnew System::Windows::Forms::Button());
			this->FilePath8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnConform9 = (gcnew System::Windows::Forms::Button());
			this->FilePath9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->btnConform10 = (gcnew System::Windows::Forms::Button());
			this->FilePath10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btnConform11 = (gcnew System::Windows::Forms::Button());
			this->FilePath11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->btnConform12 = (gcnew System::Windows::Forms::Button());
			this->FilePath12 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnConform13 = (gcnew System::Windows::Forms::Button());
			this->FilePath13 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->btnConform14 = (gcnew System::Windows::Forms::Button());
			this->FilePath14 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->btnConform15 = (gcnew System::Windows::Forms::Button());
			this->FilePath15 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->FolderName1 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName2 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName3 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName4 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName5 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName10 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName9 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName8 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName7 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName6 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName15 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName14 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName13 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName12 = (gcnew System::Windows::Forms::TextBox());
			this->FolderName11 = (gcnew System::Windows::Forms::TextBox());
			this->btnEdit1 = (gcnew System::Windows::Forms::Button());
			this->btnEdit2 = (gcnew System::Windows::Forms::Button());
			this->btnEdit3 = (gcnew System::Windows::Forms::Button());
			this->btnEdit4 = (gcnew System::Windows::Forms::Button());
			this->btnEdit8 = (gcnew System::Windows::Forms::Button());
			this->btnEdit7 = (gcnew System::Windows::Forms::Button());
			this->btnEdit6 = (gcnew System::Windows::Forms::Button());
			this->btnEdit5 = (gcnew System::Windows::Forms::Button());
			this->btnEdit12 = (gcnew System::Windows::Forms::Button());
			this->btnEdit11 = (gcnew System::Windows::Forms::Button());
			this->btnEdit10 = (gcnew System::Windows::Forms::Button());
			this->btnEdit9 = (gcnew System::Windows::Forms::Button());
			this->btnEdit15 = (gcnew System::Windows::Forms::Button());
			this->btnEdit14 = (gcnew System::Windows::Forms::Button());
			this->btnEdit13 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnSaveConfig = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Item1:";
			// 
			// FilePath1
			// 
			this->FilePath1->Location = System::Drawing::Point(59, 6);
			this->FilePath1->Name = L"FilePath1";
			this->FilePath1->Size = System::Drawing::Size(402, 21);
			this->FilePath1->TabIndex = 1;
			// 
			// btnConform1
			// 
			this->btnConform1->Location = System::Drawing::Point(548, 4);
			this->btnConform1->Name = L"btnConform1";
			this->btnConform1->Size = System::Drawing::Size(75, 23);
			this->btnConform1->TabIndex = 2;
			this->btnConform1->Text = L"Conform";
			this->btnConform1->UseVisualStyleBackColor = true;
			this->btnConform1->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// btnConform2
			// 
			this->btnConform2->Location = System::Drawing::Point(548, 33);
			this->btnConform2->Name = L"btnConform2";
			this->btnConform2->Size = System::Drawing::Size(75, 23);
			this->btnConform2->TabIndex = 5;
			this->btnConform2->Text = L"Conform";
			this->btnConform2->UseVisualStyleBackColor = true;
			this->btnConform2->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath2
			// 
			this->FilePath2->Location = System::Drawing::Point(59, 35);
			this->FilePath2->Name = L"FilePath2";
			this->FilePath2->Size = System::Drawing::Size(402, 21);
			this->FilePath2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Item2:";
			// 
			// btnConform3
			// 
			this->btnConform3->Location = System::Drawing::Point(548, 62);
			this->btnConform3->Name = L"btnConform3";
			this->btnConform3->Size = System::Drawing::Size(75, 23);
			this->btnConform3->TabIndex = 8;
			this->btnConform3->Text = L"Conform";
			this->btnConform3->UseVisualStyleBackColor = true;
			this->btnConform3->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath3
			// 
			this->FilePath3->Location = System::Drawing::Point(59, 64);
			this->FilePath3->Name = L"FilePath3";
			this->FilePath3->Size = System::Drawing::Size(402, 21);
			this->FilePath3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 12);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Item3:";
			// 
			// btnConform4
			// 
			this->btnConform4->Location = System::Drawing::Point(548, 91);
			this->btnConform4->Name = L"btnConform4";
			this->btnConform4->Size = System::Drawing::Size(75, 23);
			this->btnConform4->TabIndex = 11;
			this->btnConform4->Text = L"Conform";
			this->btnConform4->UseVisualStyleBackColor = true;
			this->btnConform4->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath4
			// 
			this->FilePath4->Location = System::Drawing::Point(59, 93);
			this->FilePath4->Name = L"FilePath4";
			this->FilePath4->Size = System::Drawing::Size(402, 21);
			this->FilePath4->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 96);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 12);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Item4:";
			// 
			// btnConform5
			// 
			this->btnConform5->Location = System::Drawing::Point(548, 120);
			this->btnConform5->Name = L"btnConform5";
			this->btnConform5->Size = System::Drawing::Size(75, 23);
			this->btnConform5->TabIndex = 14;
			this->btnConform5->Text = L"Conform";
			this->btnConform5->UseVisualStyleBackColor = true;
			this->btnConform5->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath5
			// 
			this->FilePath5->Location = System::Drawing::Point(59, 122);
			this->FilePath5->Name = L"FilePath5";
			this->FilePath5->Size = System::Drawing::Size(402, 21);
			this->FilePath5->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 12);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Item5:";
			// 
			// btnConform6
			// 
			this->btnConform6->Location = System::Drawing::Point(548, 149);
			this->btnConform6->Name = L"btnConform6";
			this->btnConform6->Size = System::Drawing::Size(75, 23);
			this->btnConform6->TabIndex = 17;
			this->btnConform6->Text = L"Conform";
			this->btnConform6->UseVisualStyleBackColor = true;
			this->btnConform6->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath6
			// 
			this->FilePath6->Location = System::Drawing::Point(59, 151);
			this->FilePath6->Name = L"FilePath6";
			this->FilePath6->Size = System::Drawing::Size(402, 21);
			this->FilePath6->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 154);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 12);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Item6:";
			// 
			// btnConform7
			// 
			this->btnConform7->Location = System::Drawing::Point(548, 178);
			this->btnConform7->Name = L"btnConform7";
			this->btnConform7->Size = System::Drawing::Size(75, 23);
			this->btnConform7->TabIndex = 20;
			this->btnConform7->Text = L"Conform";
			this->btnConform7->UseVisualStyleBackColor = true;
			this->btnConform7->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath7
			// 
			this->FilePath7->Location = System::Drawing::Point(59, 180);
			this->FilePath7->Name = L"FilePath7";
			this->FilePath7->Size = System::Drawing::Size(402, 21);
			this->FilePath7->TabIndex = 19;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 183);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 12);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Item7:";
			// 
			// btnConform8
			// 
			this->btnConform8->Location = System::Drawing::Point(548, 207);
			this->btnConform8->Name = L"btnConform8";
			this->btnConform8->Size = System::Drawing::Size(75, 23);
			this->btnConform8->TabIndex = 23;
			this->btnConform8->Text = L"Conform";
			this->btnConform8->UseVisualStyleBackColor = true;
			this->btnConform8->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath8
			// 
			this->FilePath8->Location = System::Drawing::Point(59, 209);
			this->FilePath8->Name = L"FilePath8";
			this->FilePath8->Size = System::Drawing::Size(402, 21);
			this->FilePath8->TabIndex = 22;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 212);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 12);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Item8:";
			// 
			// btnConform9
			// 
			this->btnConform9->Location = System::Drawing::Point(548, 236);
			this->btnConform9->Name = L"btnConform9";
			this->btnConform9->Size = System::Drawing::Size(75, 23);
			this->btnConform9->TabIndex = 26;
			this->btnConform9->Text = L"Conform";
			this->btnConform9->UseVisualStyleBackColor = true;
			this->btnConform9->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath9
			// 
			this->FilePath9->Location = System::Drawing::Point(59, 238);
			this->FilePath9->Name = L"FilePath9";
			this->FilePath9->Size = System::Drawing::Size(402, 21);
			this->FilePath9->TabIndex = 25;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 241);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 12);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Item9:";
			// 
			// btnConform10
			// 
			this->btnConform10->Location = System::Drawing::Point(548, 265);
			this->btnConform10->Name = L"btnConform10";
			this->btnConform10->Size = System::Drawing::Size(75, 23);
			this->btnConform10->TabIndex = 29;
			this->btnConform10->Text = L"Conform";
			this->btnConform10->UseVisualStyleBackColor = true;
			this->btnConform10->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath10
			// 
			this->FilePath10->Location = System::Drawing::Point(59, 267);
			this->FilePath10->Name = L"FilePath10";
			this->FilePath10->Size = System::Drawing::Size(402, 21);
			this->FilePath10->TabIndex = 28;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 270);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(47, 12);
			this->label10->TabIndex = 27;
			this->label10->Text = L"Item10:";
			// 
			// btnConform11
			// 
			this->btnConform11->Location = System::Drawing::Point(548, 294);
			this->btnConform11->Name = L"btnConform11";
			this->btnConform11->Size = System::Drawing::Size(75, 23);
			this->btnConform11->TabIndex = 32;
			this->btnConform11->Text = L"Conform";
			this->btnConform11->UseVisualStyleBackColor = true;
			this->btnConform11->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath11
			// 
			this->FilePath11->Location = System::Drawing::Point(59, 296);
			this->FilePath11->Name = L"FilePath11";
			this->FilePath11->Size = System::Drawing::Size(402, 21);
			this->FilePath11->TabIndex = 31;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 299);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 12);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Item11:";
			// 
			// btnConform12
			// 
			this->btnConform12->Location = System::Drawing::Point(548, 323);
			this->btnConform12->Name = L"btnConform12";
			this->btnConform12->Size = System::Drawing::Size(75, 23);
			this->btnConform12->TabIndex = 35;
			this->btnConform12->Text = L"Conform";
			this->btnConform12->UseVisualStyleBackColor = true;
			this->btnConform12->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath12
			// 
			this->FilePath12->Location = System::Drawing::Point(59, 325);
			this->FilePath12->Name = L"FilePath12";
			this->FilePath12->Size = System::Drawing::Size(402, 21);
			this->FilePath12->TabIndex = 34;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 328);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(47, 12);
			this->label12->TabIndex = 33;
			this->label12->Text = L"Item12:";
			// 
			// btnConform13
			// 
			this->btnConform13->Location = System::Drawing::Point(548, 352);
			this->btnConform13->Name = L"btnConform13";
			this->btnConform13->Size = System::Drawing::Size(75, 23);
			this->btnConform13->TabIndex = 38;
			this->btnConform13->Text = L"Conform";
			this->btnConform13->UseVisualStyleBackColor = true;
			this->btnConform13->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath13
			// 
			this->FilePath13->Location = System::Drawing::Point(59, 354);
			this->FilePath13->Name = L"FilePath13";
			this->FilePath13->Size = System::Drawing::Size(402, 21);
			this->FilePath13->TabIndex = 37;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(12, 357);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(47, 12);
			this->label13->TabIndex = 36;
			this->label13->Text = L"Item13:";
			// 
			// btnConform14
			// 
			this->btnConform14->Location = System::Drawing::Point(548, 381);
			this->btnConform14->Name = L"btnConform14";
			this->btnConform14->Size = System::Drawing::Size(75, 23);
			this->btnConform14->TabIndex = 41;
			this->btnConform14->Text = L"Conform";
			this->btnConform14->UseVisualStyleBackColor = true;
			this->btnConform14->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath14
			// 
			this->FilePath14->Location = System::Drawing::Point(59, 383);
			this->FilePath14->Name = L"FilePath14";
			this->FilePath14->Size = System::Drawing::Size(402, 21);
			this->FilePath14->TabIndex = 40;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(12, 386);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(47, 12);
			this->label14->TabIndex = 39;
			this->label14->Text = L"Item14:";
			// 
			// btnConform15
			// 
			this->btnConform15->Location = System::Drawing::Point(548, 410);
			this->btnConform15->Name = L"btnConform15";
			this->btnConform15->Size = System::Drawing::Size(75, 23);
			this->btnConform15->TabIndex = 44;
			this->btnConform15->Text = L"Conform";
			this->btnConform15->UseVisualStyleBackColor = true;
			this->btnConform15->Click += gcnew System::EventHandler(this, &MainForm::btnConform_Click);
			// 
			// FilePath15
			// 
			this->FilePath15->Location = System::Drawing::Point(59, 412);
			this->FilePath15->Name = L"FilePath15";
			this->FilePath15->Size = System::Drawing::Size(402, 21);
			this->FilePath15->TabIndex = 43;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(12, 415);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(47, 12);
			this->label15->TabIndex = 42;
			this->label15->Text = L"Item15:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(645, 9);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(47, 12);
			this->label16->TabIndex = 45;
			this->label16->Text = L"Folder:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(645, 38);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(47, 12);
			this->label17->TabIndex = 46;
			this->label17->Text = L"Folder:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(645, 67);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(47, 12);
			this->label18->TabIndex = 47;
			this->label18->Text = L"Folder:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(645, 96);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(47, 12);
			this->label19->TabIndex = 48;
			this->label19->Text = L"Folder:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(645, 125);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(47, 12);
			this->label20->TabIndex = 49;
			this->label20->Text = L"Folder:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(645, 154);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(47, 12);
			this->label21->TabIndex = 50;
			this->label21->Text = L"Folder:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(645, 183);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(47, 12);
			this->label22->TabIndex = 51;
			this->label22->Text = L"Folder:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(645, 212);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(47, 12);
			this->label23->TabIndex = 52;
			this->label23->Text = L"Folder:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(645, 241);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(47, 12);
			this->label24->TabIndex = 53;
			this->label24->Text = L"Folder:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(645, 270);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(47, 12);
			this->label25->TabIndex = 54;
			this->label25->Text = L"Folder:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(645, 299);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(47, 12);
			this->label26->TabIndex = 55;
			this->label26->Text = L"Folder:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(645, 328);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(47, 12);
			this->label27->TabIndex = 56;
			this->label27->Text = L"Folder:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(645, 357);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(47, 12);
			this->label28->TabIndex = 57;
			this->label28->Text = L"Folder:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(645, 386);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(47, 12);
			this->label29->TabIndex = 58;
			this->label29->Text = L"Folder:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(645, 415);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(47, 12);
			this->label30->TabIndex = 59;
			this->label30->Text = L"Folder:";
			// 
			// FolderName1
			// 
			this->FolderName1->Location = System::Drawing::Point(698, 6);
			this->FolderName1->Name = L"FolderName1";
			this->FolderName1->Size = System::Drawing::Size(132, 21);
			this->FolderName1->TabIndex = 60;
			// 
			// FolderName2
			// 
			this->FolderName2->Location = System::Drawing::Point(698, 35);
			this->FolderName2->Name = L"FolderName2";
			this->FolderName2->Size = System::Drawing::Size(132, 21);
			this->FolderName2->TabIndex = 61;
			// 
			// FolderName3
			// 
			this->FolderName3->Location = System::Drawing::Point(698, 64);
			this->FolderName3->Name = L"FolderName3";
			this->FolderName3->Size = System::Drawing::Size(132, 21);
			this->FolderName3->TabIndex = 62;
			// 
			// FolderName4
			// 
			this->FolderName4->Location = System::Drawing::Point(698, 93);
			this->FolderName4->Name = L"FolderName4";
			this->FolderName4->Size = System::Drawing::Size(132, 21);
			this->FolderName4->TabIndex = 63;
			// 
			// FolderName5
			// 
			this->FolderName5->Location = System::Drawing::Point(698, 122);
			this->FolderName5->Name = L"FolderName5";
			this->FolderName5->Size = System::Drawing::Size(132, 21);
			this->FolderName5->TabIndex = 64;
			// 
			// FolderName10
			// 
			this->FolderName10->Location = System::Drawing::Point(698, 267);
			this->FolderName10->Name = L"FolderName10";
			this->FolderName10->Size = System::Drawing::Size(132, 21);
			this->FolderName10->TabIndex = 69;
			// 
			// FolderName9
			// 
			this->FolderName9->Location = System::Drawing::Point(698, 238);
			this->FolderName9->Name = L"FolderName9";
			this->FolderName9->Size = System::Drawing::Size(132, 21);
			this->FolderName9->TabIndex = 68;
			// 
			// FolderName8
			// 
			this->FolderName8->Location = System::Drawing::Point(698, 209);
			this->FolderName8->Name = L"FolderName8";
			this->FolderName8->Size = System::Drawing::Size(132, 21);
			this->FolderName8->TabIndex = 67;
			// 
			// FolderName7
			// 
			this->FolderName7->Location = System::Drawing::Point(698, 180);
			this->FolderName7->Name = L"FolderName7";
			this->FolderName7->Size = System::Drawing::Size(132, 21);
			this->FolderName7->TabIndex = 66;
			// 
			// FolderName6
			// 
			this->FolderName6->Location = System::Drawing::Point(698, 151);
			this->FolderName6->Name = L"FolderName6";
			this->FolderName6->Size = System::Drawing::Size(132, 21);
			this->FolderName6->TabIndex = 65;
			// 
			// FolderName15
			// 
			this->FolderName15->Location = System::Drawing::Point(698, 412);
			this->FolderName15->Name = L"FolderName15";
			this->FolderName15->Size = System::Drawing::Size(132, 21);
			this->FolderName15->TabIndex = 74;
			// 
			// FolderName14
			// 
			this->FolderName14->Location = System::Drawing::Point(698, 383);
			this->FolderName14->Name = L"FolderName14";
			this->FolderName14->Size = System::Drawing::Size(132, 21);
			this->FolderName14->TabIndex = 73;
			// 
			// FolderName13
			// 
			this->FolderName13->Location = System::Drawing::Point(698, 354);
			this->FolderName13->Name = L"FolderName13";
			this->FolderName13->Size = System::Drawing::Size(132, 21);
			this->FolderName13->TabIndex = 72;
			// 
			// FolderName12
			// 
			this->FolderName12->Location = System::Drawing::Point(698, 325);
			this->FolderName12->Name = L"FolderName12";
			this->FolderName12->Size = System::Drawing::Size(132, 21);
			this->FolderName12->TabIndex = 71;
			// 
			// FolderName11
			// 
			this->FolderName11->Location = System::Drawing::Point(698, 296);
			this->FolderName11->Name = L"FolderName11";
			this->FolderName11->Size = System::Drawing::Size(132, 21);
			this->FolderName11->TabIndex = 70;
			// 
			// btnEdit1
			// 
			this->btnEdit1->Location = System::Drawing::Point(467, 4);
			this->btnEdit1->Name = L"btnEdit1";
			this->btnEdit1->Size = System::Drawing::Size(75, 23);
			this->btnEdit1->TabIndex = 75;
			this->btnEdit1->Text = L"Edit";
			this->btnEdit1->UseVisualStyleBackColor = true;
			this->btnEdit1->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit2
			// 
			this->btnEdit2->Location = System::Drawing::Point(467, 33);
			this->btnEdit2->Name = L"btnEdit2";
			this->btnEdit2->Size = System::Drawing::Size(75, 23);
			this->btnEdit2->TabIndex = 76;
			this->btnEdit2->Text = L"Edit";
			this->btnEdit2->UseVisualStyleBackColor = true;
			this->btnEdit2->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit3
			// 
			this->btnEdit3->Location = System::Drawing::Point(467, 62);
			this->btnEdit3->Name = L"btnEdit3";
			this->btnEdit3->Size = System::Drawing::Size(75, 23);
			this->btnEdit3->TabIndex = 77;
			this->btnEdit3->Text = L"Edit";
			this->btnEdit3->UseVisualStyleBackColor = true;
			this->btnEdit3->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit4
			// 
			this->btnEdit4->Location = System::Drawing::Point(467, 91);
			this->btnEdit4->Name = L"btnEdit4";
			this->btnEdit4->Size = System::Drawing::Size(75, 23);
			this->btnEdit4->TabIndex = 78;
			this->btnEdit4->Text = L"Edit";
			this->btnEdit4->UseVisualStyleBackColor = true;
			this->btnEdit4->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit8
			// 
			this->btnEdit8->Location = System::Drawing::Point(467, 207);
			this->btnEdit8->Name = L"btnEdit8";
			this->btnEdit8->Size = System::Drawing::Size(75, 23);
			this->btnEdit8->TabIndex = 82;
			this->btnEdit8->Text = L"Edit";
			this->btnEdit8->UseVisualStyleBackColor = true;
			this->btnEdit8->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit7
			// 
			this->btnEdit7->Location = System::Drawing::Point(467, 178);
			this->btnEdit7->Name = L"btnEdit7";
			this->btnEdit7->Size = System::Drawing::Size(75, 23);
			this->btnEdit7->TabIndex = 81;
			this->btnEdit7->Text = L"Edit";
			this->btnEdit7->UseVisualStyleBackColor = true;
			this->btnEdit7->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit6
			// 
			this->btnEdit6->Location = System::Drawing::Point(467, 149);
			this->btnEdit6->Name = L"btnEdit6";
			this->btnEdit6->Size = System::Drawing::Size(75, 23);
			this->btnEdit6->TabIndex = 80;
			this->btnEdit6->Text = L"Edit";
			this->btnEdit6->UseVisualStyleBackColor = true;
			this->btnEdit6->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit5
			// 
			this->btnEdit5->Location = System::Drawing::Point(467, 120);
			this->btnEdit5->Name = L"btnEdit5";
			this->btnEdit5->Size = System::Drawing::Size(75, 23);
			this->btnEdit5->TabIndex = 79;
			this->btnEdit5->Text = L"Edit";
			this->btnEdit5->UseVisualStyleBackColor = true;
			this->btnEdit5->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit12
			// 
			this->btnEdit12->Location = System::Drawing::Point(467, 323);
			this->btnEdit12->Name = L"btnEdit12";
			this->btnEdit12->Size = System::Drawing::Size(75, 23);
			this->btnEdit12->TabIndex = 86;
			this->btnEdit12->Text = L"Edit";
			this->btnEdit12->UseVisualStyleBackColor = true;
			this->btnEdit12->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit11
			// 
			this->btnEdit11->Location = System::Drawing::Point(467, 294);
			this->btnEdit11->Name = L"btnEdit11";
			this->btnEdit11->Size = System::Drawing::Size(75, 23);
			this->btnEdit11->TabIndex = 85;
			this->btnEdit11->Text = L"Edit";
			this->btnEdit11->UseVisualStyleBackColor = true;
			this->btnEdit11->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit10
			// 
			this->btnEdit10->Location = System::Drawing::Point(467, 265);
			this->btnEdit10->Name = L"btnEdit10";
			this->btnEdit10->Size = System::Drawing::Size(75, 23);
			this->btnEdit10->TabIndex = 84;
			this->btnEdit10->Text = L"Edit";
			this->btnEdit10->UseVisualStyleBackColor = true;
			this->btnEdit10->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit9
			// 
			this->btnEdit9->Location = System::Drawing::Point(467, 236);
			this->btnEdit9->Name = L"btnEdit9";
			this->btnEdit9->Size = System::Drawing::Size(75, 23);
			this->btnEdit9->TabIndex = 83;
			this->btnEdit9->Text = L"Edit";
			this->btnEdit9->UseVisualStyleBackColor = true;
			this->btnEdit9->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit15
			// 
			this->btnEdit15->Location = System::Drawing::Point(467, 410);
			this->btnEdit15->Name = L"btnEdit15";
			this->btnEdit15->Size = System::Drawing::Size(75, 23);
			this->btnEdit15->TabIndex = 89;
			this->btnEdit15->Text = L"Edit";
			this->btnEdit15->UseVisualStyleBackColor = true;
			this->btnEdit15->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit14
			// 
			this->btnEdit14->Location = System::Drawing::Point(467, 381);
			this->btnEdit14->Name = L"btnEdit14";
			this->btnEdit14->Size = System::Drawing::Size(75, 23);
			this->btnEdit14->TabIndex = 88;
			this->btnEdit14->Text = L"Edit";
			this->btnEdit14->UseVisualStyleBackColor = true;
			this->btnEdit14->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// btnEdit13
			// 
			this->btnEdit13->Location = System::Drawing::Point(467, 352);
			this->btnEdit13->Name = L"btnEdit13";
			this->btnEdit13->Size = System::Drawing::Size(75, 23);
			this->btnEdit13->TabIndex = 87;
			this->btnEdit13->Text = L"Edit";
			this->btnEdit13->UseVisualStyleBackColor = true;
			this->btnEdit13->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(836, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(20, 20);
			this->pictureBox1->TabIndex = 90;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(836, 36);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(20, 20);
			this->pictureBox2->TabIndex = 91;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(836, 94);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(20, 20);
			this->pictureBox4->TabIndex = 93;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(836, 64);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(20, 20);
			this->pictureBox3->TabIndex = 92;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(836, 210);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(20, 20);
			this->pictureBox8->TabIndex = 97;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(836, 180);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(20, 20);
			this->pictureBox7->TabIndex = 96;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(836, 152);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(20, 20);
			this->pictureBox6->TabIndex = 95;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(836, 122);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(20, 20);
			this->pictureBox5->TabIndex = 94;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(836, 327);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(20, 20);
			this->pictureBox12->TabIndex = 101;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(836, 297);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(20, 20);
			this->pictureBox11->TabIndex = 100;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(836, 269);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(20, 20);
			this->pictureBox10->TabIndex = 99;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(836, 239);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(20, 20);
			this->pictureBox9->TabIndex = 98;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Location = System::Drawing::Point(836, 354);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(20, 20);
			this->pictureBox13->TabIndex = 102;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Location = System::Drawing::Point(836, 412);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(20, 20);
			this->pictureBox15->TabIndex = 104;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Location = System::Drawing::Point(836, 384);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(20, 20);
			this->pictureBox14->TabIndex = 103;
			this->pictureBox14->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(862, 6);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(306, 410);
			this->richTextBox1->TabIndex = 106;
			this->richTextBox1->Text = L"";
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(1063, 422);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(105, 23);
			this->btnSave->TabIndex = 108;
			this->btnSave->Text = L"Copy item";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// btnSaveConfig
			// 
			this->btnSaveConfig->Location = System::Drawing::Point(952, 422);
			this->btnSaveConfig->Name = L"btnSaveConfig";
			this->btnSaveConfig->Size = System::Drawing::Size(105, 23);
			this->btnSaveConfig->TabIndex = 109;
			this->btnSaveConfig->Text = L"Save config";
			this->btnSaveConfig->UseVisualStyleBackColor = true;
			this->btnSaveConfig->Click += gcnew System::EventHandler(this, &MainForm::btnSaveConfig_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1180, 457);
			this->Controls->Add(this->btnSaveConfig);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnEdit15);
			this->Controls->Add(this->btnEdit14);
			this->Controls->Add(this->btnEdit13);
			this->Controls->Add(this->btnEdit12);
			this->Controls->Add(this->btnEdit11);
			this->Controls->Add(this->btnEdit10);
			this->Controls->Add(this->btnEdit9);
			this->Controls->Add(this->btnEdit8);
			this->Controls->Add(this->btnEdit7);
			this->Controls->Add(this->btnEdit6);
			this->Controls->Add(this->btnEdit5);
			this->Controls->Add(this->btnEdit4);
			this->Controls->Add(this->btnEdit3);
			this->Controls->Add(this->btnEdit2);
			this->Controls->Add(this->btnEdit1);
			this->Controls->Add(this->FolderName15);
			this->Controls->Add(this->FolderName14);
			this->Controls->Add(this->FolderName13);
			this->Controls->Add(this->FolderName12);
			this->Controls->Add(this->FolderName11);
			this->Controls->Add(this->FolderName10);
			this->Controls->Add(this->FolderName9);
			this->Controls->Add(this->FolderName8);
			this->Controls->Add(this->FolderName7);
			this->Controls->Add(this->FolderName6);
			this->Controls->Add(this->FolderName5);
			this->Controls->Add(this->FolderName4);
			this->Controls->Add(this->FolderName3);
			this->Controls->Add(this->FolderName2);
			this->Controls->Add(this->FolderName1);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->btnConform15);
			this->Controls->Add(this->FilePath15);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->btnConform14);
			this->Controls->Add(this->FilePath14);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->btnConform13);
			this->Controls->Add(this->FilePath13);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->btnConform12);
			this->Controls->Add(this->FilePath12);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->btnConform11);
			this->Controls->Add(this->FilePath11);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->btnConform10);
			this->Controls->Add(this->FilePath10);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->btnConform9);
			this->Controls->Add(this->FilePath9);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->btnConform8);
			this->Controls->Add(this->FilePath8);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnConform7);
			this->Controls->Add(this->FilePath7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnConform6);
			this->Controls->Add(this->FilePath6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->btnConform5);
			this->Controls->Add(this->FilePath5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnConform4);
			this->Controls->Add(this->FilePath4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnConform3);
			this->Controls->Add(this->FilePath3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnConform2);
			this->Controls->Add(this->FilePath2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnConform1);
			this->Controls->Add(this->FilePath1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"FileManager V1.0.1704181";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
	void InitializeFilePath()
	{
		DestFolderName = "DestRepo";

		for (unsigned int i = 1; i <= 15; ++i)
		{
			SetItemEnable(i, false);
		}
	}
	void LoadFromFile()
	{
		if (File::Exists(FILEPATH_CONFIG))
		{
			StreamReader^ sr = gcnew StreamReader(FILEPATH_CONFIG);
			int i = 0;
			try
			{
				String^ str = "";
				while ((str = sr->ReadLine()) && (i < NUM_ITEM))
				{
					int pos = str->IndexOf("<<");
					if (pos <= 0)
					{
						continue;
					}
					txbFilePathArray[i]->Text = str->Substring(0, pos);
					txbFolderNameArray[i]->Text = str->Substring(pos + 2);
					i++;
				}
			}
			finally
			{
				if (sr)
					delete (IDisposable^)sr;
			}
		}
	}
	
	void AddToArray()
	{
		// array<System::Windows::Forms::Button^>^				btnConformArray;
		// array<System::Windows::Forms::Button^>^				btnEditArray;
		// array<System::Windows::Forms::TextBox^>^			txbFilePathArray;
		// array<System::Windows::Forms::TextBox^>^			txbFolderNameArray;
		// array<System::Windows::Forms::PictureBox^>^			pboxStatusArray;

		btnConformArray = gcnew array<System::Windows::Forms::Button^>(NUM_ITEM);
		btnEditArray = gcnew array<System::Windows::Forms::Button^>(NUM_ITEM);
		txbFilePathArray = gcnew array<System::Windows::Forms::TextBox^>(NUM_ITEM);
		txbFolderNameArray = gcnew array<System::Windows::Forms::TextBox^>(NUM_ITEM);
		pboxStatusArray = gcnew array<System::Windows::Forms::PictureBox^>(NUM_ITEM);

		int i = 0;
		// add conform button to array
		btnConformArray[i] = btnConform1;
		btnConformArray[++i] = btnConform2;
		btnConformArray[++i] = btnConform3;
		btnConformArray[++i] = btnConform4;
		btnConformArray[++i] = btnConform5;

		btnConformArray[++i] = btnConform6;
		btnConformArray[++i] = btnConform7;
		btnConformArray[++i] = btnConform8;
		btnConformArray[++i] = btnConform9;
		btnConformArray[++i] = btnConform10;

		btnConformArray[++i] = btnConform11;
		btnConformArray[++i] = btnConform12;
		btnConformArray[++i] = btnConform13;
		btnConformArray[++i] = btnConform14;
		btnConformArray[++i] = btnConform15;

		// add edit buttomn to array
		i = 0;
		btnEditArray[i] = btnEdit1;
		btnEditArray[++i] = btnEdit2;
		btnEditArray[++i] = btnEdit3;
		btnEditArray[++i] = btnEdit4;
		btnEditArray[++i] = btnEdit5;

		btnEditArray[++i] = btnEdit6;
		btnEditArray[++i] = btnEdit7;
		btnEditArray[++i] = btnEdit8;
		btnEditArray[++i] = btnEdit9;
		btnEditArray[++i] = btnEdit10;

		btnEditArray[++i] = btnEdit11;
		btnEditArray[++i] = btnEdit12;
		btnEditArray[++i] = btnEdit13;
		btnEditArray[++i] = btnEdit14;
		btnEditArray[++i] = btnEdit15;

		// add file path textbox to array
		i = 0;
		txbFilePathArray[i] = FilePath1;
		txbFilePathArray[++i] = FilePath2;
		txbFilePathArray[++i] = FilePath3;
		txbFilePathArray[++i] = FilePath4;
		txbFilePathArray[++i] = FilePath5;

		txbFilePathArray[++i] = FilePath6;
		txbFilePathArray[++i] = FilePath7;
		txbFilePathArray[++i] = FilePath8;
		txbFilePathArray[++i] = FilePath9;
		txbFilePathArray[++i] = FilePath10;

		txbFilePathArray[++i] = FilePath11;
		txbFilePathArray[++i] = FilePath12;
		txbFilePathArray[++i] = FilePath13;
		txbFilePathArray[++i] = FilePath14;
		txbFilePathArray[++i] = FilePath15;

		// add folder name textbox to array
		i = 0;
		txbFolderNameArray[i] = FolderName1;
		txbFolderNameArray[++i] = FolderName2;
		txbFolderNameArray[++i] = FolderName3;
		txbFolderNameArray[++i] = FolderName4;
		txbFolderNameArray[++i] = FolderName5;

		txbFolderNameArray[++i] = FolderName6;
		txbFolderNameArray[++i] = FolderName7;
		txbFolderNameArray[++i] = FolderName8;
		txbFolderNameArray[++i] = FolderName9;
		txbFolderNameArray[++i] = FolderName10;

		txbFolderNameArray[++i] = FolderName11;
		txbFolderNameArray[++i] = FolderName12;
		txbFolderNameArray[++i] = FolderName13;
		txbFolderNameArray[++i] = FolderName14;
		txbFolderNameArray[++i] = FolderName15;

		// add picturebox to array
		i = 0;
		pboxStatusArray[i] = pictureBox1;
		pboxStatusArray[++i] = pictureBox2;
		pboxStatusArray[++i] = pictureBox3;
		pboxStatusArray[++i] = pictureBox4;
		pboxStatusArray[++i] = pictureBox5;

		pboxStatusArray[++i] = pictureBox6;
		pboxStatusArray[++i] = pictureBox7;
		pboxStatusArray[++i] = pictureBox8;
		pboxStatusArray[++i] = pictureBox9;
		pboxStatusArray[++i] = pictureBox10;

		pboxStatusArray[++i] = pictureBox11;
		pboxStatusArray[++i] = pictureBox12;
		pboxStatusArray[++i] = pictureBox13;
		pboxStatusArray[++i] = pictureBox14;
		pboxStatusArray[++i] = pictureBox15;

		// load images
		picTrue = System::Drawing::Image::FromFile(IMAGEPATH_TRUEIMAGE);
		picFalse = System::Drawing::Image::FromFile(IMAGEPATH_FALSEIMAGE);
	}
	bool IsItemEmpty(unsigned int index)
	{
		// check empty
		if ("" == txbFilePathArray[index - 1]->Text)
		{
			// item empty
			return true;
		}
		return false;
	}
	bool CopyFile(unsigned int index)
	{
		String^ CurrentPath = System::Environment::CurrentDirectory;

		String^ message;
		
		// check empty
		if ("" == txbFilePathArray[index - 1]->Text)
		{
			// item empty
			OutputEmptyInfo(index);
			return false;
		}
		// check source
		if (!TFileAndDirs::AssertDirectory(txbFilePathArray[index - 1]->Text))
		{
			// source does not exist
			message = "Source does not exist...";
			OutputMessage(index, message);
			return false;
		}
		String^ SourcePath = txbFilePathArray[index - 1]->Text;
		// check dest
		String^ DesFolder = txbFolderNameArray[index - 1]->Text;
		if (0 == DesFolder->Length)
		{
			txbFolderNameArray[index - 1]->Text = "Folder" + Convert::ToString(index);
		}
		String^ DestPath = CurrentPath + "\\" + DestFolderName + "\\" + txbFolderNameArray[index - 1]->Text;
		if (!TFileAndDirs::AssertDirectory(DestPath))
		{
			// dest path does not exist
			if (!TFileAndDirs::MakeDirectory(DestPath, &message))
			{
				OutputMessage(index, message);
				return false;
			}
		}

		// copy
		int CopyCount[2] = { 0,0 };
		if (!CopyDirectory(SourcePath, DestPath, &message, CopyCount))
		{
			OutputMessage(index, message);
			return false;
		}

		// message
		OutputInfo(index, SourcePath, DestPath, CopyCount[0], CopyCount[1]);
		return true;
	}
	void OutputEmptyInfo(int item)
	{
		std::ostringstream ss;
		ss << "Item: ";
		ss << item;
		ss << "\r\nSkip...";
		ss << "\r\n";

		richTextBox1->AppendText(TString::ToDotNetString(ss.str()));
	}
	void OutputNewInfo(int item, String^ source, String^ dest)
	{
		std::ostringstream ss;
		ss << "New Item: ";
		ss << item;
		ss << "\r\nFrom: ";
		ss << TString::ToStdString(source);
		ss << "\r\nTo: ";
		ss << TString::ToStdString(dest);
		ss << "\r\n";

		richTextBox1->AppendText(TString::ToDotNetString(ss.str()));
	}
	void OutputInfo(int item, String^ source, String^ dest, int directories, int files)
	{
		std::ostringstream ss;
		ss << "Item: ";
		ss << item;
		ss << "\r\nFrom: ";
		ss << TString::ToStdString(source);
		ss << "\r\nTo: ";
		ss << TString::ToStdString(dest);
		ss << "\r\n\n" << directories << " directory(ies) and " << files << " file(s) are copied.";
		ss << "\r\n";

		richTextBox1->AppendText(TString::ToDotNetString(ss.str()));
	}
	void OutputMessage(int item, String^ str)
	{
		std::ostringstream ss;
		ss << "Item: ";
		ss << item;
		ss << "\r\n";
		ss << TString::ToStdString(str);
		ss << "\r\n";

		richTextBox1->AppendText(TString::ToDotNetString(ss.str()));
	}
	void OutputMessage(String^ str)
	{
		richTextBox1->AppendText(str);
	}
	void SetItemEnable(unsigned int i, bool b)
	{
		txbFilePathArray[i - 1]->Enabled = b;
		txbFolderNameArray[i - 1]->Enabled = b;
		if (b)
		{
			this->btnConformArray[i - 1]->Enabled = true;
			this->btnEditArray[i - 1]->Enabled = false;
		}
		else
		{
			this->btnConformArray[i - 1]->Enabled = false;
			this->btnEditArray[i - 1]->Enabled = true;
		}
	}

	// button click
	System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// clear text
		this->richTextBox1->Clear();

		for (unsigned int i = 1; i < NUM_ITEM + 1; i++)
		{
			if (!IsItemEmpty(i))
			{
				if (CopyFile(i))
				{
					pboxStatusArray[i - 1]->Image = picTrue;
				}
				else {
					pboxStatusArray[i - 1]->Image = picFalse;
				}
				OutputMessage("---------------------------------------------");
			}
		}
	}
	System::Void btnSaveConfig_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// clear file
		TFileAndDirs::WriteFile(FILEPATH_CONFIG, "");
		// write
		for (unsigned int i = 0; i < NUM_ITEM; i++)
		{
			String^ txb1 = txbFilePathArray[i]->Text;
			String^ txb2 = txbFolderNameArray[i]->Text;
			if ((txb1->Length != 0) && (txb2->Length != 0))
			{
				String^ str = txb1 + "<<" + txb2;
				TFileAndDirs::AddStringToFile(FILEPATH_CONFIG, str);
				
				OutputNewInfo(i + 1, txb1, txb2);
				OutputMessage("---------------------------------------------\r\n");
			}
		}
	}
	private: System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (unsigned int i = 0; i < NUM_ITEM; i++)
		{
			if (btnEditArray[i] == sender)
			{
				SetItemEnable(i + 1, true);
				break;
			}
		}
	}
	private: System::Void btnConform_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (unsigned int i = 0; i < NUM_ITEM; i++)
		{
			if (btnConformArray[i] == sender)
			{
				SetItemEnable(i + 1, false);
				break;
			}
		}
	}
};
}
