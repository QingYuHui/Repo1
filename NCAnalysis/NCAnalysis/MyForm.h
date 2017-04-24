#pragma once

#include "NCAnalysis.h"

namespace NCAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: NCAnalysis		*ncAnalysis;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  txbFilePath;
	private: System::Windows::Forms::Button^  btnSelectFile;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->txbFilePath = (gcnew System::Windows::Forms::TextBox());
			this->btnSelectFile = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(509, 537);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// txbFilePath
			// 
			this->txbFilePath->Location = System::Drawing::Point(527, 12);
			this->txbFilePath->Name = L"txbFilePath";
			this->txbFilePath->Size = System::Drawing::Size(245, 21);
			this->txbFilePath->TabIndex = 1;
			// 
			// btnSelectFile
			// 
			this->btnSelectFile->Location = System::Drawing::Point(697, 39);
			this->btnSelectFile->Name = L"btnSelectFile";
			this->btnSelectFile->Size = System::Drawing::Size(75, 23);
			this->btnSelectFile->TabIndex = 2;
			this->btnSelectFile->Text = L"Browser...";
			this->btnSelectFile->UseVisualStyleBackColor = true;
			this->btnSelectFile->Click += gcnew System::EventHandler(this, &MyForm::btnSelectFile_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(697, 68);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(75, 23);
			this->btnLoad->TabIndex = 3;
			this->btnLoad->Text = L"Load";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &MyForm::btnLoad_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"*.nc";
			this->openFileDialog1->Filter = L"NC-Files|*.nc";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->btnLoad);
			this->Controls->Add(this->btnSelectFile);
			this->Controls->Add(this->txbFilePath);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		ncAnalysis = new NCAnalysis();
	}
	private: System::Void btnSelectFile_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if (Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog())
			{
				this->txbFilePath->Text = openFileDialog1->FileName;
			}
		}
		catch (Exception^ e)
		{
			this->richTextBox1->AppendText(e->ToString());
			this->richTextBox1->AppendText("\r\n");
		}
	}
	private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ FilePath = this->txbFilePath->Text;
		String^ message = "Loading file " + FilePath;
		if (ncAnalysis->LoadFile(TString::ToStdString(FilePath)))
		{
			message += "\r\nSuccessful...";
		}
		else
		{
			message += "\r\nFailed...";
		}

		this->richTextBox1->AppendText(message);
	}
};
}
