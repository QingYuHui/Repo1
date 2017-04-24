#pragma once

#include "../../Paint/ViewWindow.h"
#include "SortOperate.h"
#include "../../FileAndString/String.h"
#include "Animation.h"

namespace Sort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace HGUI;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			// viewWindow is a class for draw elements
			viewWindow = new ViewWindow();
			// sortOperate is a class for sort
			sortOperate = new SortOperate();
			// a class for analyse demo data
			dataQueue = new TDataQueue();
			// initialize pen and brush
			pen = gcnew System::Drawing::Pen(System::Drawing::Color::Color::Black, 1);
			brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::Black);

			SetViewWindow();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::PictureBox^  PBoxView;
	private: System::Windows::Forms::ToolStripStatusLabel^  StatLblXCor;
	private: System::Windows::Forms::ToolStripStatusLabel^  StatLblYCor;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  cbDataAmount;
	private: System::Windows::Forms::ComboBox^  cbDataType;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  cbSortType;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Button^  btnGenerate;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  btnStartDemo;
	private: System::Windows::Forms::ComboBox^  cbSortTypeDemo;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btnNext;
	private: System::Windows::Forms::Button^  btnPre;
	protected:
	private:
		System::Drawing::Pen^  pen;									// for draw element
		System::Drawing::Brush^  brush;								// for draw element
		ViewWindow							*viewWindow;
		TDataQueue							*dataQueue;
		Bitmap^								ViewImage;
		System::Drawing::Graphics^			ViewGraphics;
		SortOperate							*sortOperate;
		int									iTotalData;				// how many value in vectore ?
		unsigned int						SingleStepFlag;

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->PBoxView = (gcnew System::Windows::Forms::PictureBox());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->btnStartDemo = (gcnew System::Windows::Forms::Button());
				 this->cbSortTypeDemo = (gcnew System::Windows::Forms::ComboBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->cbDataType = (gcnew System::Windows::Forms::ComboBox());
				 this->cbDataAmount = (gcnew System::Windows::Forms::ComboBox());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->btnClear = (gcnew System::Windows::Forms::Button());
				 this->btnStart = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->cbSortType = (gcnew System::Windows::Forms::ComboBox());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->btnGenerate = (gcnew System::Windows::Forms::Button());
				 this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
				 this->StatLblXCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
				 this->StatLblYCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->btnPre = (gcnew System::Windows::Forms::Button());
				 this->btnNext = (gcnew System::Windows::Forms::Button());
				 this->panel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->BeginInit();
				 this->panel2->SuspendLayout();
				 this->groupBox3->SuspendLayout();
				 this->groupBox1->SuspendLayout();
				 this->statusStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left));
				 this->panel1->Controls->Add(this->PBoxView);
				 this->panel1->Location = System::Drawing::Point(12, 28);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(759, 628);
				 this->panel1->TabIndex = 0;
				 // 
				 // PBoxView
				 // 
				 this->PBoxView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->PBoxView->Location = System::Drawing::Point(3, 3);
				 this->PBoxView->Name = L"PBoxView";
				 this->PBoxView->Size = System::Drawing::Size(753, 622);
				 this->PBoxView->TabIndex = 0;
				 this->PBoxView->TabStop = false;
				 this->PBoxView->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::PBoxView_Paint);
				 this->PBoxView->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PBoxView_MouseMove);
				 // 
				 // panel2
				 // 
				 this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->panel2->Controls->Add(this->groupBox3);
				 this->panel2->Controls->Add(this->groupBox1);
				 this->panel2->Location = System::Drawing::Point(777, 28);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(275, 628);
				 this->panel2->TabIndex = 1;
				 // 
				 // groupBox3
				 // 
				 this->groupBox3->Controls->Add(this->btnNext);
				 this->groupBox3->Controls->Add(this->btnPre);
				 this->groupBox3->Controls->Add(this->label7);
				 this->groupBox3->Controls->Add(this->btnStartDemo);
				 this->groupBox3->Controls->Add(this->cbSortTypeDemo);
				 this->groupBox3->Controls->Add(this->label8);
				 this->groupBox3->Location = System::Drawing::Point(3, 259);
				 this->groupBox3->Name = L"groupBox3";
				 this->groupBox3->Size = System::Drawing::Size(269, 227);
				 this->groupBox3->TabIndex = 3;
				 this->groupBox3->TabStop = false;
				 this->groupBox3->Text = L"算法演示";
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(6, 56);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(59, 12);
				 this->label7->TabIndex = 7;
				 this->label7->Text = L"开始排序:";
				 // 
				 // btnStartDemo
				 // 
				 this->btnStartDemo->Location = System::Drawing::Point(188, 51);
				 this->btnStartDemo->Name = L"btnStartDemo";
				 this->btnStartDemo->Size = System::Drawing::Size(75, 23);
				 this->btnStartDemo->TabIndex = 6;
				 this->btnStartDemo->Text = L"开始";
				 this->btnStartDemo->UseVisualStyleBackColor = true;
				 this->btnStartDemo->Click += gcnew System::EventHandler(this, &MainForm::btnStartDemo_Click);
				 // 
				 // cbSortTypeDemo
				 // 
				 this->cbSortTypeDemo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->cbSortTypeDemo->FormattingEnabled = true;
				 this->cbSortTypeDemo->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Select", L"Insertion", L"Shell", L"Merge" });
				 this->cbSortTypeDemo->Location = System::Drawing::Point(107, 20);
				 this->cbSortTypeDemo->Name = L"cbSortTypeDemo";
				 this->cbSortTypeDemo->Size = System::Drawing::Size(156, 20);
				 this->cbSortTypeDemo->TabIndex = 5;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(6, 23);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(59, 12);
				 this->label8->TabIndex = 4;
				 this->label8->Text = L"排序算法:";
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->label3);
				 this->groupBox1->Controls->Add(this->cbDataType);
				 this->groupBox1->Controls->Add(this->cbDataAmount);
				 this->groupBox1->Controls->Add(this->label5);
				 this->groupBox1->Controls->Add(this->btnClear);
				 this->groupBox1->Controls->Add(this->btnStart);
				 this->groupBox1->Controls->Add(this->label2);
				 this->groupBox1->Controls->Add(this->cbSortType);
				 this->groupBox1->Controls->Add(this->label4);
				 this->groupBox1->Controls->Add(this->label1);
				 this->groupBox1->Controls->Add(this->btnGenerate);
				 this->groupBox1->Location = System::Drawing::Point(3, 3);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(269, 250);
				 this->groupBox1->TabIndex = 1;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"排序";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(6, 59);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(71, 12);
				 this->label3->TabIndex = 9;
				 this->label3->Text = L"生成随机数:";
				 // 
				 // cbDataType
				 // 
				 this->cbDataType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->cbDataType->FormattingEnabled = true;
				 this->cbDataType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"bars", L"points" });
				 this->cbDataType->Location = System::Drawing::Point(188, 26);
				 this->cbDataType->Name = L"cbDataType";
				 this->cbDataType->Size = System::Drawing::Size(75, 20);
				 this->cbDataType->TabIndex = 8;
				 // 
				 // cbDataAmount
				 // 
				 this->cbDataAmount->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->cbDataAmount->FormattingEnabled = true;
				 this->cbDataAmount->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"25", L"50", L"100", L"200" });
				 this->cbDataAmount->Location = System::Drawing::Point(107, 26);
				 this->cbDataAmount->Name = L"cbDataAmount";
				 this->cbDataAmount->Size = System::Drawing::Size(75, 20);
				 this->cbDataAmount->TabIndex = 5;
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(6, 161);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(59, 12);
				 this->label5->TabIndex = 3;
				 this->label5->Text = L"开始排序:";
				 // 
				 // btnClear
				 // 
				 this->btnClear->Location = System::Drawing::Point(188, 83);
				 this->btnClear->Name = L"btnClear";
				 this->btnClear->Size = System::Drawing::Size(75, 23);
				 this->btnClear->TabIndex = 4;
				 this->btnClear->Text = L"清空";
				 this->btnClear->UseVisualStyleBackColor = true;
				 this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
				 // 
				 // btnStart
				 // 
				 this->btnStart->Location = System::Drawing::Point(188, 156);
				 this->btnStart->Name = L"btnStart";
				 this->btnStart->Size = System::Drawing::Size(75, 23);
				 this->btnStart->TabIndex = 2;
				 this->btnStart->Text = L"开始";
				 this->btnStart->UseVisualStyleBackColor = true;
				 this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(6, 88);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(59, 12);
				 this->label2->TabIndex = 3;
				 this->label2->Text = L"清空画布:";
				 // 
				 // cbSortType
				 // 
				 this->cbSortType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->cbSortType->FormattingEnabled = true;
				 this->cbSortType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Select", L"Insertion", L"Shell", L"Merge" });
				 this->cbSortType->Location = System::Drawing::Point(107, 125);
				 this->cbSortType->Name = L"cbSortType";
				 this->cbSortType->Size = System::Drawing::Size(156, 20);
				 this->cbSortType->TabIndex = 1;
				 this->cbSortType->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::OnSelectedIndexChanged);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(6, 128);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(59, 12);
				 this->label4->TabIndex = 0;
				 this->label4->Text = L"排序算法:";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(6, 30);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(95, 12);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"数据个数和形状:";
				 // 
				 // btnGenerate
				 // 
				 this->btnGenerate->Location = System::Drawing::Point(188, 54);
				 this->btnGenerate->Name = L"btnGenerate";
				 this->btnGenerate->Size = System::Drawing::Size(75, 23);
				 this->btnGenerate->TabIndex = 0;
				 this->btnGenerate->Text = L"生成";
				 this->btnGenerate->UseVisualStyleBackColor = true;
				 this->btnGenerate->Click += gcnew System::EventHandler(this, &MainForm::btnGenerate_Click);
				 // 
				 // statusStrip1
				 // 
				 this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->StatLblXCor, this->StatLblYCor });
				 this->statusStrip1->Location = System::Drawing::Point(0, 659);
				 this->statusStrip1->Name = L"statusStrip1";
				 this->statusStrip1->Size = System::Drawing::Size(1064, 22);
				 this->statusStrip1->TabIndex = 2;
				 this->statusStrip1->Text = L"statusStrip1";
				 // 
				 // StatLblXCor
				 // 
				 this->StatLblXCor->Name = L"StatLblXCor";
				 this->StatLblXCor->Size = System::Drawing::Size(25, 17);
				 this->StatLblXCor->Text = L"0.0";
				 // 
				 // StatLblYCor
				 // 
				 this->StatLblYCor->Name = L"StatLblYCor";
				 this->StatLblYCor->Size = System::Drawing::Size(25, 17);
				 this->StatLblYCor->Text = L"0.0";
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(1064, 24);
				 this->menuStrip1->TabIndex = 3;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // timer1
				 // 
				 this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
				 // 
				 // btnPre
				 // 
				 this->btnPre->Location = System::Drawing::Point(107, 87);
				 this->btnPre->Name = L"btnPre";
				 this->btnPre->Size = System::Drawing::Size(75, 23);
				 this->btnPre->TabIndex = 8;
				 this->btnPre->Text = L"<";
				 this->btnPre->UseVisualStyleBackColor = true;
				 this->btnPre->Click += gcnew System::EventHandler(this, &MainForm::btnPre_Click);
				 // 
				 // btnNext
				 // 
				 this->btnNext->Location = System::Drawing::Point(188, 87);
				 this->btnNext->Name = L"btnNext";
				 this->btnNext->Size = System::Drawing::Size(75, 23);
				 this->btnNext->TabIndex = 9;
				 this->btnNext->Text = L">";
				 this->btnNext->UseVisualStyleBackColor = true;
				 this->btnNext->Click += gcnew System::EventHandler(this, &MainForm::btnNext_Click);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1064, 681);
				 this->Controls->Add(this->statusStrip1);
				 this->Controls->Add(this->menuStrip1);
				 this->Controls->Add(this->panel2);
				 this->Controls->Add(this->panel1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				 this->MaximizeBox = false;
				 this->Name = L"MainForm";
				 this->ShowIcon = false;
				 this->Text = L"Sort";
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
				 this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				 this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::PBoxView_SizeChanged);
				 this->panel1->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->EndInit();
				 this->panel2->ResumeLayout(false);
				 this->groupBox3->ResumeLayout(false);
				 this->groupBox3->PerformLayout();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->statusStrip1->ResumeLayout(false);
				 this->statusStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private:
		System::Void PBoxView_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			Geo::TPoint CurPoint(viewWindow->ConvertToWorldCoords(Geo::TPoint(e->X, e->Y)));
			StatLblXCor->Text = "X:" + CurPoint.X().ToString("####.00");
			StatLblYCor->Text = "Y:" + CurPoint.Y().ToString("####.00");
		}
		System::Void PBoxView_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			e->Graphics->DrawImage(ViewImage, 0, 0);
		}
		System::Void PBoxView_SizeChanged(System::Object^  sender, System::EventArgs^  e)
		{
		}
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
		{
			// new bitmap and graphics
			ViewImage = gcnew Bitmap(this->PBoxView->ClientRectangle.Width, this->PBoxView->ClientRectangle.Height);
			ViewGraphics = System::Drawing::Graphics::FromImage(ViewImage);
			//PBoxView->Image = ViewImage;

			DrawBackground();
			DrawBorder();

			// set default value
			iTotalData = -1;
			this->cbDataAmount->SelectedIndex = 2;
			this->cbDataType->SelectedIndex = 0;
			this->cbSortType->SelectedIndex = 0;
			this->cbSortTypeDemo->SelectedIndex = 0;

			timer1->Enabled = false;
		}
		System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
		}
		void Sort::MainForm::OnSelectedIndexChanged(System::Object ^sender, System::EventArgs ^e)
		{
			if (sortOperate && (-1 != iTotalData))
			{
				// then shuffle data
				sortOperate->ShuffleSortData();
				// display
				DrawElement(iTotalData);
			}
		}
		// set current window's size for view window
		// it need window size for CTM
		void SetViewWindow()
		{
			viewWindow->SetCoordinateSystem(this->PBoxView->ClientRectangle);
		}
		// draw the border
		void DrawBorder()
		{
			// draw border
			System::Drawing::Rectangle NetRect = PBoxView->ClientRectangle;//Get work area of PBoxView
			Geo::TRectangle Rect(1, 1, NetRect.Width - 1, NetRect.Height - 1);
			viewWindow->PaintRectangle(ViewGraphics, pen, Rect);

			PBoxView->Invalidate();
		}
		// clear the back ground
		void DrawBackground()
		{
			ViewGraphics->Clear(System::Drawing::Color::White);
		}
		// draw point or bar
		void DrawElement(int iAmount)
		{
			double dClientWidth = static_cast<double>(this->PBoxView->ClientRectangle.Width);
			double dClientHeight = static_cast<double>(this->PBoxView->ClientRectangle.Height);

			dClientWidth -= 5;
			dClientHeight -= 5;

			double dBarWidth = dClientWidth / iAmount * 2.0 / 3.0;
			double dGroupWidth = dClientWidth / iAmount;
			double dBarHeighFac = dClientHeight / (500 + 5);

			// clear canvas
			DrawBackground();
			DrawBorder();

			// display

			String^ sDataType = this->cbDataType->Text;

			// get unlock with 1ms waitting
			DWORD PStatus = WaitForSingleObject(sortOperate->PMutex, 1);

			// can't handle the sort data
			if (PStatus == WAIT_TIMEOUT)
				return;

			const int *p = sortOperate->GetSortData();
			 
			if ("points" == sDataType)
			{
				for (int i = 0; i < iAmount; i++)
				{
					Geo::TPoint pt(5 + i * dGroupWidth, 5 + dBarHeighFac * p[i]);
					viewWindow->PaintPoint(ViewGraphics, brush, pt);
				}
			}
			else  // bar
			{
				for (int i = 0; i < iAmount; i++)
				{
					Geo::TRectangle Rect(5 + i * dGroupWidth, 5, 5 + i * dGroupWidth + dBarWidth, 5 + dBarHeighFac * p[i]);
					viewWindow->FillRectangle(ViewGraphics, brush, Rect);
				}
			}

			PBoxView->Invalidate();

			// unlock data
			ReleaseMutex(sortOperate->PMutex);
		}
		// generate ramdom points
		System::Void btnGenerate_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int iAmount;
			try
			{
				if (this->cbDataAmount->Text == "")
					return;
				iAmount = Convert::ToInt32(this->cbDataAmount->Text);
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->ToString());
				return;
			}

			// generate sort data
			sortOperate->FillSortData(iAmount);
			// then shuffle data
			sortOperate->ShuffleSortData();
			// display
			DrawElement(iAmount);

			iTotalData = iAmount;

			this->cbDataAmount->Enabled = false;
			this->cbDataType->Enabled = false;
		}
		System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e)
		{
			DrawBackground();
			DrawBorder();
			PBoxView->Invalidate();

			this->cbDataAmount->Enabled = true;
			this->cbDataType->Enabled = true;
			iTotalData = -1;

			// if the timer is running, stop it
			if (true == timer1->Enabled)
			{
				timer1->Enabled = false;
			}
		}
		// make widget available or not
		void AvailableSet(bool enable)
		{
			this->groupBox1->Enabled = enable;
			this->groupBox3->Enabled = enable;
		}
		System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (-1 == iTotalData)
				return;

			// show dynamic
			if (false == timer1->Enabled)		// if the sort did not start
			{
				sortOperate->DoSortInChildThraed(this->cbSortType->SelectedIndex);
				timer1->Enabled = true;
				AvailableSet(false);			// set widget enable
			}
		}
		System::Void btnStartDemo_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int q[10] = { 8,3,2,5,6,7,9,4,0,1 };
			
			// write animation
			std::string file = ".\\operate.dat";
			if (File::Exists(TString::ToDotNetString(file)))
			{
				remove(file.c_str());
			}
			// sortOperate->InsertionMethodForOutput(q, file);
			sortOperate->SelectMethodForOutput(q, file);

			// load animation
			dataQueue->LoadAnimation(file);

			SingleStepFlag = 0;
		}
		Void DrawSingleStep()
		{
			DrawBackground();
			DrawBorder();

			int q[10] = { 8,3,2,5,6,7,9,4,0,1 };

			System::Drawing::Brush^  brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Color::White);

			Geo::TPoint PtOrigin(30, 570);
			int gap = 30;

			viewWindow->PaintText(ViewGraphics, "q[]", PtOrigin + Geo::TPoint(120, 30), System::Drawing::Color::Black);

			for (int i = 0; i < 10; i++)
			{
				viewWindow->PaintText(ViewGraphics, Convert::ToString(i), PtOrigin + Geo::TPoint(gap*i, 0), System::Drawing::Color::Black);
			}

			if ("" != dataQueue->paraA)
				viewWindow->PaintText(ViewGraphics, TString::ToDotNetString(dataQueue->paraA), PtOrigin + Geo::TPoint(gap * 11, 0), System::Drawing::Color::Black);
			if ("" != dataQueue->paraB)
				viewWindow->PaintText(ViewGraphics, TString::ToDotNetString(dataQueue->paraB), PtOrigin + Geo::TPoint(gap * 12, 0), System::Drawing::Color::Black);
			if ("" != dataQueue->paraC)
				viewWindow->PaintText(ViewGraphics, TString::ToDotNetString(dataQueue->paraC), PtOrigin + Geo::TPoint(gap * 13, 0), System::Drawing::Color::Black);
			if ("" != dataQueue->paraD)
				viewWindow->PaintText(ViewGraphics, TString::ToDotNetString(dataQueue->paraD), PtOrigin + Geo::TPoint(gap * 14, 0), System::Drawing::Color::Black);

			int line = 1;
			for (int i = 0; i < 10; i++)
			{
				viewWindow->PaintText(ViewGraphics, Convert::ToString(dataQueue->data[i]), PtOrigin + Geo::TPoint(gap*i, - line * 30), System::Drawing::Color::Black);
			}
			int a = 0;
			int b = 0;
			int c = 0;
			int d = 0;
			// std::vector<TDataQueue::TItem>::iterator Iter = dataQueue->Queue->begin();
			for (size_t i = 0; i < dataQueue->Queue.size(); i++)
			{
				if (SingleStepFlag < dataQueue->Queue[i].Step)
					break;
				if (dataQueue->Queue[i].act == TDataQueue::TAction::NUL)
				{
					a = dataQueue->Queue[i].A;
					b = dataQueue->Queue[i].B;
					c = dataQueue->Queue[i].C;
					d = dataQueue->Queue[i].D;

					// clear old parameter
					viewWindow->FillRectangle(ViewGraphics, brush, Geo::TRectangle(PtOrigin + Geo::TPoint(gap * 11, -line * 50), PtOrigin + Geo::TPoint(gap * 16, -line * 30)));
					// draw new parameter
					if ("" != dataQueue->paraA)
						viewWindow->PaintText(ViewGraphics, Convert::ToString(a), PtOrigin + Geo::TPoint(gap * 11, -line * 30), System::Drawing::Color::Black);
					if ("" != dataQueue->paraB)
						viewWindow->PaintText(ViewGraphics, Convert::ToString(b), PtOrigin + Geo::TPoint(gap * 12, -line * 30), System::Drawing::Color::Black);
					if ("" != dataQueue->paraC)
						viewWindow->PaintText(ViewGraphics, Convert::ToString(c), PtOrigin + Geo::TPoint(gap * 13, -line * 30), System::Drawing::Color::Black);
					if ("" != dataQueue->paraD)
						viewWindow->PaintText(ViewGraphics, Convert::ToString(d), PtOrigin + Geo::TPoint(gap * 14, -line * 30), System::Drawing::Color::Black);

				}
				else if (dataQueue->Queue[i].act == TDataQueue::TAction::LOH)
				{
					int act1 = dataQueue->Queue[i].actpar1;
					int act2 = dataQueue->Queue[i].actpar2;
					// clear old square
					viewWindow->FillRectangle(ViewGraphics, brush, Geo::TRectangle(PtOrigin + Geo::TPoint(0, -line * 30 - gap / 2 - 3), PtOrigin + Geo::TPoint(gap * 10, -line * 30 - gap / 2)));
					// draw new square
					viewWindow->PaintRectangle(ViewGraphics, Geo::TRectangle(PtOrigin + Geo::TPoint(gap * act1, -line * 30 - gap / 2 - 2), PtOrigin + Geo::TPoint(gap * act1 + gap / 2, -line * 30 - gap / 2)));
					viewWindow->PaintRectangle(ViewGraphics, Geo::TRectangle(PtOrigin + Geo::TPoint(gap * act2, -line * 30 - gap / 2 - 2), PtOrigin + Geo::TPoint(gap * act2 + gap / 2, -line * 30 - gap / 2)));

					// clear old explain
					viewWindow->FillRectangle(ViewGraphics, brush, Geo::TRectangle(PtOrigin + Geo::TPoint(gap * 16, -line * 50), PtOrigin + Geo::TPoint(gap * 22, -line * 30)));
					// draw explain of compare
					String^ str = "if ( q[" + act1 + "] < q[" + act2 + "] )";
					viewWindow->PaintText(ViewGraphics, str, PtOrigin + Geo::TPoint(gap * 16, -line * 30), System::Drawing::Color::Black);
				}
				else if (dataQueue->Queue[i].act == TDataQueue::TAction::SWP)
				{
					int act1 = dataQueue->Queue[i].actpar1;
					int act2 = dataQueue->Queue[i].actpar2;
					std::swap(q[act1], q[act2]);
					
					// clear old swap
					viewWindow->FillRectangle(ViewGraphics, brush, Geo::TRectangle(PtOrigin + Geo::TPoint(gap * 16, -line * 50), PtOrigin + Geo::TPoint(gap * 22, -line * 30)));
					// draw explain of swap
					String^ str = "swap ( q[" + act1 + "] < q[" + act2 + "] )";
					viewWindow->PaintText(ViewGraphics, str, PtOrigin + Geo::TPoint(gap * 16, -line * 30), System::Drawing::Color::Black);

					// clear old array
					viewWindow->FillRectangle(ViewGraphics, brush, Geo::TRectangle(PtOrigin + Geo::TPoint(0, -line * 50), PtOrigin + Geo::TPoint(gap * 10, -line * 30)));
					// draw new array
					for (int i = 0; i < 10; i++)
					{
						viewWindow->PaintText(ViewGraphics, Convert::ToString(q[i]), PtOrigin + Geo::TPoint(gap*i, -line * 30), System::Drawing::Color::Black);
					}
				}
				else if (dataQueue->Queue[i].act == TDataQueue::TAction::ENDL)
				{
					line++;	// must less than 19
				}
			}
			PBoxView->Invalidate();
		}
		System::Void btnNext_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (SingleStepFlag < dataQueue->TotalStep)
				SingleStepFlag++;
			DrawSingleStep();
		}
		System::Void btnPre_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (0 < SingleStepFlag)
				SingleStepFlag--;
			DrawSingleStep();
		}
		// single step
		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			// display
			DrawElement(iTotalData);

			// if thread is stop, then the sort is done
			if (sortOperate->GetThreadStatus())
			{
				AvailableSet(true);
				timer1->Enabled = false;
			}	
		}
};
}
