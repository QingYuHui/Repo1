#pragma once

#include "../../FileAndString/FileAndDirs.h"
#include "../../FileAndString/String.h"

namespace CADConvert {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->chbSourceOutput->Checked = true;

			sVersionCode = "V1.0.1704201";
			sToolName = "CAD Converter ";

			this->Text = sToolName + sVersionCode;
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^		sVersionCode;
	private: String^		sToolName;
	private: System::Windows::Forms::TextBox^  txbSourceFile;
	private: System::Windows::Forms::TextBox^  txbDestination;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnEditSource;
	private: System::Windows::Forms::Button^  btnEditDest;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Button^  btnFromSource;
	private: System::Windows::Forms::Button^  btnOpenSource;
	private: System::Windows::Forms::Button^  btnOpenDest;

	private: System::Windows::Forms::CheckBox^  chbSourceOutput;
	private: System::Windows::Forms::CheckBox^  chbBackup;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txbSourceFile = (gcnew System::Windows::Forms::TextBox());
			this->txbDestination = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnEditSource = (gcnew System::Windows::Forms::Button());
			this->btnEditDest = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->btnFromSource = (gcnew System::Windows::Forms::Button());
			this->btnOpenSource = (gcnew System::Windows::Forms::Button());
			this->btnOpenDest = (gcnew System::Windows::Forms::Button());
			this->chbSourceOutput = (gcnew System::Windows::Forms::CheckBox());
			this->chbBackup = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// txbSourceFile
			// 
			this->txbSourceFile->Location = System::Drawing::Point(95, 12);
			this->txbSourceFile->Name = L"txbSourceFile";
			this->txbSourceFile->Size = System::Drawing::Size(496, 21);
			this->txbSourceFile->TabIndex = 0;
			// 
			// txbDestination
			// 
			this->txbDestination->Location = System::Drawing::Point(95, 39);
			this->txbDestination->Name = L"txbDestination";
			this->txbDestination->Size = System::Drawing::Size(415, 21);
			this->txbDestination->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"源文件:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"输出文件夹:";
			// 
			// btnEditSource
			// 
			this->btnEditSource->Location = System::Drawing::Point(597, 10);
			this->btnEditSource->Name = L"btnEditSource";
			this->btnEditSource->Size = System::Drawing::Size(105, 23);
			this->btnEditSource->TabIndex = 4;
			this->btnEditSource->Text = L"选择...";
			this->btnEditSource->UseVisualStyleBackColor = true;
			this->btnEditSource->Click += gcnew System::EventHandler(this, &MyForm::btnEditSource_Click);
			// 
			// btnEditDest
			// 
			this->btnEditDest->Location = System::Drawing::Point(597, 37);
			this->btnEditDest->Name = L"btnEditDest";
			this->btnEditDest->Size = System::Drawing::Size(105, 23);
			this->btnEditDest->TabIndex = 5;
			this->btnEditDest->Text = L"选择...";
			this->btnEditDest->UseVisualStyleBackColor = true;
			this->btnEditDest->Click += gcnew System::EventHandler(this, &MyForm::btnEditDest_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(14, 66);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(577, 383);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(597, 426);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(105, 23);
			this->btnStart->TabIndex = 7;
			this->btnStart->Text = L"开始";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(597, 397);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(105, 23);
			this->btnClear->TabIndex = 8;
			this->btnClear->Text = L"清空日志";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"*.nc";
			this->openFileDialog1->Filter = L"all|*.*|cutter-files(*.iso;*.gbr;*.nc;*.cut)|*.iso;*.gbr;*.nc;*.cut|iso-files|*.iso|gbr-f"
				L"iles|*.gbr|nc-files|*.nc|cut-files|*.cut";
			// 
			// btnFromSource
			// 
			this->btnFromSource->Location = System::Drawing::Point(516, 37);
			this->btnFromSource->Name = L"btnFromSource";
			this->btnFromSource->Size = System::Drawing::Size(75, 23);
			this->btnFromSource->TabIndex = 9;
			this->btnFromSource->Text = L"自动目录";
			this->btnFromSource->UseVisualStyleBackColor = true;
			this->btnFromSource->Click += gcnew System::EventHandler(this, &MyForm::btnFromSource_Click);
			// 
			// btnOpenSource
			// 
			this->btnOpenSource->Location = System::Drawing::Point(597, 66);
			this->btnOpenSource->Name = L"btnOpenSource";
			this->btnOpenSource->Size = System::Drawing::Size(105, 23);
			this->btnOpenSource->TabIndex = 10;
			this->btnOpenSource->Text = L"打开源文件夹";
			this->btnOpenSource->UseVisualStyleBackColor = true;
			this->btnOpenSource->Click += gcnew System::EventHandler(this, &MyForm::btnOpenSource_Click);
			// 
			// btnOpenDest
			// 
			this->btnOpenDest->Location = System::Drawing::Point(597, 95);
			this->btnOpenDest->Name = L"btnOpenDest";
			this->btnOpenDest->Size = System::Drawing::Size(105, 23);
			this->btnOpenDest->TabIndex = 11;
			this->btnOpenDest->Text = L"打开目标文件夹";
			this->btnOpenDest->UseVisualStyleBackColor = true;
			this->btnOpenDest->Click += gcnew System::EventHandler(this, &MyForm::benOpenDest_Click);
			// 
			// chbSourceOutput
			// 
			this->chbSourceOutput->AutoSize = true;
			this->chbSourceOutput->Location = System::Drawing::Point(597, 353);
			this->chbSourceOutput->Name = L"chbSourceOutput";
			this->chbSourceOutput->Size = System::Drawing::Size(96, 16);
			this->chbSourceOutput->TabIndex = 12;
			this->chbSourceOutput->Text = L"输出至源文件";
			this->chbSourceOutput->UseVisualStyleBackColor = true;
			this->chbSourceOutput->CheckedChanged += gcnew System::EventHandler(this, &MyForm::chbSourceOutput_CheckedChanged);
			// 
			// chbBackup
			// 
			this->chbBackup->AutoSize = true;
			this->chbBackup->Location = System::Drawing::Point(597, 375);
			this->chbBackup->Name = L"chbBackup";
			this->chbBackup->Size = System::Drawing::Size(84, 16);
			this->chbBackup->TabIndex = 13;
			this->chbBackup->Text = L"备份源文件";
			this->chbBackup->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(710, 457);
			this->Controls->Add(this->chbBackup);
			this->Controls->Add(this->chbSourceOutput);
			this->Controls->Add(this->btnOpenDest);
			this->Controls->Add(this->btnOpenSource);
			this->Controls->Add(this->btnFromSource);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->btnEditDest);
			this->Controls->Add(this->btnEditSource);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txbDestination);
			this->Controls->Add(this->txbSourceFile);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEditSource_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if (Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog())
			{
				this->txbSourceFile->Text = openFileDialog1->FileName;
			}
		}
		catch (Exception^ e)
		{
			this->richTextBox1->AppendText(e->ToString());
			this->richTextBox1->AppendText("\r\n");
		}
	}
	private: System::Void btnFromSource_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ source = this->txbSourceFile->Text;
		if (0 == source->Length)
			return;
		int pos = source->LastIndexOf("\\");

		if (pos >= 0)
		{
			String^ dest = source->Substring(0, pos + 1);
			this->txbDestination->Text = dest;
		}
	}
	private: System::Void btnEditDest_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if (Windows::Forms::DialogResult::OK == folderBrowserDialog1->ShowDialog())
			{
				this->txbDestination->Text = folderBrowserDialog1->SelectedPath;
			}
		}
		catch (Exception^ e)
		{
			this->richTextBox1->AppendText(e->ToString());
			this->richTextBox1->AppendText("\r\n");
		}
	}
	private: System::Void btnOpenSource_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ source = this->txbSourceFile->Text;
		String^ message = "";

		// check empty
		if (0 == source->Length)
		{
			message = "源文件不存在...";
			OutputWarningMessage(message);
			return;
		}

		int pos = source->LastIndexOf("\\");
		source = source->Substring(0, pos);

		System::Diagnostics::Process::Start("Explorer.exe", source);
	}
	private: System::Void benOpenDest_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ dest = this->txbDestination->Text;
		String^ message = "";

		// check empty
		if (0 == dest->Length)
		{
			message = "输出文件夹不存在...";
			OutputWarningMessage(message);
			return;
		}
		System::Diagnostics::Process::Start("Explorer.exe", dest);
	}
	private: System::Void chbSourceOutput_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		bool bCheck = this->chbSourceOutput->Checked;

		this->txbDestination->Enabled = !bCheck;
		this->btnFromSource->Enabled = !bCheck;
		this->btnEditDest->Enabled = !bCheck;
		this->btnOpenDest->Enabled = !bCheck;
		this->chbBackup->Enabled = bCheck;
	}
	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->richTextBox1->Clear();
	}
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ source = this->txbSourceFile->Text;
		String^ dest = this->txbDestination->Text;
		String^ destfile = "";
		String^ message = "";
		bool bNoExtension = true;
		bool bUseSource = this->chbSourceOutput->Checked;
		bool bBackUp = this->chbBackup->Checked;

		// clear log
		this->richTextBox1->Clear();
		// check empty
		if (0 == source->Length)
		{
			message = "源文件不存在...";
			OutputWarningMessage(message);
			return;
		}
		if (!bUseSource && (0 == dest->Length))
		{
			message = "输出文件夹不存在...";
			OutputWarningMessage(message);
			return;
		}
		else {
			message = "输出至源文件...";
			OutputWarningMessage(message);
		}

		// use new folder to output
		if (!bUseSource)
		{
			// check destination path
			int pos = dest->LastIndexOf("\\");
			if (pos != dest->Length - 1)
			{
				dest += "\\";
			}
			// check destination folder
			if (!TFileAndDirs::AssertDirectory(dest))
			{
				String^ message;
				if (!TFileAndDirs::MakeDirectory(dest, &message))
				{
					OutputWarningMessage(message);
					return;
				}
				message = "输出文件夹不存在, 创建新文件夹:";
				message += dest;
				OutputWarningMessage(message);
			}
			try
			{
				// get file name
				pos = source->LastIndexOf("\\");
				if (pos >= 0)
				{
					destfile = source->Substring(pos + 1);

					pos = destfile->LastIndexOf(".");
					if (pos >= 0)
					{
						destfile = destfile->Substring(0, pos);
						bNoExtension = false;
					}
				}
				if (0 == destfile->Length)
				{
					destfile = "Default";
				}
				destfile += System::DateTime::Now.ToString("-yyMMddHHmmss");
				destfile += ".nc";

				dest += destfile;
				OutputMessage(source, dest);
			}
			catch (Exception^ e)
			{
				this->richTextBox1->AppendText(e->ToString());
				this->richTextBox1->AppendText("\r\n");
				return;
			}
			// copy
			if (!File::Exists(source))
			{
				message = "无法打开源文件...";
				OutputWarningMessage(message);
			}

			// create file
			TFileAndDirs::WriteFile(dest, "");

			StreamReader^ sr = gcnew StreamReader(source);
			StreamWriter^ sw = gcnew StreamWriter(dest, false, System::Text::Encoding::ASCII);
			try
			{
				String^ str = "";
				while ((str = sr->ReadLine()))
				{
					int pos = str->IndexOf("G");
					if (pos <= 0)
					{
						sw->WriteLine(str);
						continue;
					}
					str = str->Substring(0, pos);
					sw->WriteLine(str);
				}
			}
			finally
			{
				if (sr)
					delete (IDisposable^)sr;

				if (sw)
					delete (IDisposable^)sw;
			}
		}
		else { // use source file to out put
			try
			{
				// get file name
				int pos = source->LastIndexOf("\\");
				if (pos >= 0)
				{
					destfile = source->Substring(pos + 1);

					pos = destfile->LastIndexOf(".");
					if (pos >= 0)
					{
						destfile = destfile->Substring(0, pos);
						bNoExtension = false;
					}
				}
				destfile += "_bak.nc";

				pos = source->LastIndexOf("\\");
				dest = source->Substring(0, pos);
				dest += "\\";
				dest += destfile;
			}
			catch (Exception^ e)
			{
				this->richTextBox1->AppendText(e->ToString());
				this->richTextBox1->AppendText("\r\n");
				return;
			}

			if (bBackUp)
			{
				if (!TFileAndDirs::CopyFile(source, dest, &message))
				{
					message = "备份失败！\r\n";
					OutputWarningMessage(message);
					return;
				}
				message = "备份文件:";
				message += dest;
				OutputMessage(message);
			}

			String^ file;
			StreamReader^ sr = gcnew StreamReader(source);

			// set destination same with source
			dest = source;

			if (bNoExtension)
			{
				dest += ".nc";
			}
			OutputMessage(source, dest);
			try
			{
				String^ str = "";
				while ((str = sr->ReadLine()))
				{
					int pos = str->IndexOf("G");
					if (pos <= 0)
					{
						file = file + str + "\r\n";
						continue;
					}
					str = str->Substring(0, pos);
					file = file + str + "\r\n";
				}
			}
			catch (Exception^ e)
			{
				this->richTextBox1->AppendText(e->ToString());
				this->richTextBox1->AppendText("\r\n");
			}
			finally
			{
				if (sr)
					delete (IDisposable^)sr;
			}
			// write to file
			StreamWriter^ sw = gcnew StreamWriter(dest, false, System::Text::Encoding::ASCII);
			try
			{
				sw->Write(file);
			}
			catch (Exception^ e)
			{
				this->richTextBox1->AppendText(e->ToString());
				this->richTextBox1->AppendText("\r\n");
			}
			finally
			{
				if (sw)
					delete (IDisposable^)sw;
			}
		}
		// done
		message = "处理完成...";
		OutputMessage(message);
	}
	private:
		void OutputMessage(String^ str)
		{
			this->richTextBox1->SelectionColor = Color::Green;

			this->richTextBox1->AppendText(str);
			this->richTextBox1->AppendText("\r\n");

			this->richTextBox1->SelectionColor = Color::Black;
		}
		void OutputWarningMessage(String^ str)
		{
			this->richTextBox1->SelectionColor = Color::Red;

			this->richTextBox1->AppendText(str);
			this->richTextBox1->AppendText("\r\n");

			this->richTextBox1->SelectionColor = Color::Black;
		}
		void OutputMessage(String^ source, String^ dest)
		{
			String^ message = "来自: ";
			message += source;
			message += "\r\n保存至: ";
			message += dest;
			message += "\r\n开始处理...\r\n";

			richTextBox1->AppendText(message);
		}
};
}