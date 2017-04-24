#pragma once

#include "../../Paint/ViewWindow.h"
#include "PuzzleOperate.h"

// change blocks may make the grid out of picturebox
#define	BLOCKS	3

namespace Puzzle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace HGUI;

	enum EPicSelect
	{
		Pic1 = 0,
		Pic2 = 1,
		Pic3 = 2,
		Pic4 = 3
	};

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			viewWindow = new ViewWindow();

			puzzleOperate = gcnew PuzzleOperate();
			
			SetViewWindow();

			uiTimer->Enabled = true;

			// this follow button is use for debug
			// i will keep it on the form but commit it
			this->btnShuffleAng->Enabled = false;
			this->btnShuffleOrd->Enabled = false;
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
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnLoadPic;
	private: System::Windows::Forms::Button^  btnShuffleOrd;
	private: System::Windows::Forms::Button^  btnShuffleAng;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labStep;
	private: System::Windows::Forms::Label^  labTime;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  uiTimer;			// timer for ui update
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  rbPic4;
	private: System::Windows::Forms::RadioButton^  rbPic3;
	private: System::Windows::Forms::RadioButton^  rbPic2;
	private: System::Windows::Forms::RadioButton^  rbPic1;
	protected:
	private:
		ViewWindow							*viewWindow;		// a class for GDI assistant
		PuzzleOperate						^puzzleOperate;		// a class for puzzle operate
		Bitmap^								ViewImage;			// bitmap for mainly picture box
		System::Drawing::Graphics^			ViewGraphics;
		Bitmap^								SmallViewImage;		// bitmap for navigator
		EPicSelect							PicSelect;			// which picture are selected ?

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->PBoxView = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->labStep = (gcnew System::Windows::Forms::Label());
			this->labTime = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->rbPic4 = (gcnew System::Windows::Forms::RadioButton());
			this->rbPic3 = (gcnew System::Windows::Forms::RadioButton());
			this->rbPic2 = (gcnew System::Windows::Forms::RadioButton());
			this->rbPic1 = (gcnew System::Windows::Forms::RadioButton());
			this->btnShuffleAng = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnShuffleOrd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLoadPic = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->StatLblXCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->StatLblYCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->uiTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
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
			this->panel1->Size = System::Drawing::Size(803, 804);
			this->panel1->TabIndex = 0;
			// 
			// PBoxView
			// 
			this->PBoxView->Location = System::Drawing::Point(0, 3);
			this->PBoxView->Name = L"PBoxView";
			this->PBoxView->Size = System::Drawing::Size(800, 800);
			this->PBoxView->TabIndex = 0;
			this->PBoxView->TabStop = false;
			this->PBoxView->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::PBoxView_Paint);
			this->PBoxView->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PBoxView_MouseDown);
			this->PBoxView->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PBoxView_MouseMove);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Location = System::Drawing::Point(821, 28);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(243, 804);
			this->panel2->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnReset);
			this->groupBox1->Controls->Add(this->labStep);
			this->groupBox1->Controls->Add(this->labTime);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(3, 242);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(228, 363);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"游戏信息";
			// 
			// labStep
			// 
			this->labStep->AutoSize = true;
			this->labStep->Location = System::Drawing::Point(145, 271);
			this->labStep->Name = L"labStep";
			this->labStep->Size = System::Drawing::Size(11, 12);
			this->labStep->TabIndex = 6;
			this->labStep->Text = L"-";
			// 
			// labTime
			// 
			this->labTime->AutoSize = true;
			this->labTime->Location = System::Drawing::Point(145, 242);
			this->labTime->Name = L"labTime";
			this->labTime->Size = System::Drawing::Size(11, 12);
			this->labTime->TabIndex = 5;
			this->labTime->Text = L"-";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(14, 20);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 271);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 12);
			this->label5->TabIndex = 1;
			this->label5->Text = L"游戏步数:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"游戏时间:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->rbPic4);
			this->groupBox2->Controls->Add(this->rbPic3);
			this->groupBox2->Controls->Add(this->rbPic2);
			this->groupBox2->Controls->Add(this->rbPic1);
			this->groupBox2->Controls->Add(this->btnShuffleAng);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->btnShuffleOrd);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->btnLoadPic);
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(228, 233);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"设置";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 51);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 12);
			this->label6->TabIndex = 13;
			this->label6->Text = L"选择图片:";
			// 
			// rbPic4
			// 
			this->rbPic4->AutoSize = true;
			this->rbPic4->Location = System::Drawing::Point(147, 115);
			this->rbPic4->Name = L"rbPic4";
			this->rbPic4->Size = System::Drawing::Size(53, 16);
			this->rbPic4->TabIndex = 12;
			this->rbPic4->TabStop = true;
			this->rbPic4->Text = L"图片4";
			this->rbPic4->UseVisualStyleBackColor = true;
			this->rbPic4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// rbPic3
			// 
			this->rbPic3->AutoSize = true;
			this->rbPic3->Location = System::Drawing::Point(147, 93);
			this->rbPic3->Name = L"rbPic3";
			this->rbPic3->Size = System::Drawing::Size(53, 16);
			this->rbPic3->TabIndex = 11;
			this->rbPic3->TabStop = true;
			this->rbPic3->Text = L"图片3";
			this->rbPic3->UseVisualStyleBackColor = true;
			this->rbPic3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// rbPic2
			// 
			this->rbPic2->AutoSize = true;
			this->rbPic2->Location = System::Drawing::Point(147, 71);
			this->rbPic2->Name = L"rbPic2";
			this->rbPic2->Size = System::Drawing::Size(53, 16);
			this->rbPic2->TabIndex = 10;
			this->rbPic2->TabStop = true;
			this->rbPic2->Text = L"图片2";
			this->rbPic2->UseVisualStyleBackColor = true;
			this->rbPic2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// rbPic1
			// 
			this->rbPic1->AutoSize = true;
			this->rbPic1->Location = System::Drawing::Point(147, 49);
			this->rbPic1->Name = L"rbPic1";
			this->rbPic1->Size = System::Drawing::Size(53, 16);
			this->rbPic1->TabIndex = 9;
			this->rbPic1->TabStop = true;
			this->rbPic1->Text = L"图片1";
			this->rbPic1->UseVisualStyleBackColor = true;
			this->rbPic1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// btnShuffleAng
			// 
			this->btnShuffleAng->Location = System::Drawing::Point(147, 184);
			this->btnShuffleAng->Name = L"btnShuffleAng";
			this->btnShuffleAng->Size = System::Drawing::Size(75, 23);
			this->btnShuffleAng->TabIndex = 8;
			this->btnShuffleAng->Text = L"执行";
			this->btnShuffleAng->UseVisualStyleBackColor = true;
			this->btnShuffleAng->Click += gcnew System::EventHandler(this, &MainForm::btnShuffleAng_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 12);
			this->label3->TabIndex = 7;
			this->label3->Text = L"打乱角度:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"打乱顺序:";
			// 
			// btnShuffleOrd
			// 
			this->btnShuffleOrd->Location = System::Drawing::Point(147, 155);
			this->btnShuffleOrd->Name = L"btnShuffleOrd";
			this->btnShuffleOrd->Size = System::Drawing::Size(75, 23);
			this->btnShuffleOrd->TabIndex = 5;
			this->btnShuffleOrd->Text = L"执行";
			this->btnShuffleOrd->UseVisualStyleBackColor = true;
			this->btnShuffleOrd->Click += gcnew System::EventHandler(this, &MainForm::btnShuffleOrd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"新的游戏:";
			// 
			// btnLoadPic
			// 
			this->btnLoadPic->Location = System::Drawing::Point(147, 20);
			this->btnLoadPic->Name = L"btnLoadPic";
			this->btnLoadPic->Size = System::Drawing::Size(75, 23);
			this->btnLoadPic->TabIndex = 0;
			this->btnLoadPic->Text = L"开始";
			this->btnLoadPic->UseVisualStyleBackColor = true;
			this->btnLoadPic->Click += gcnew System::EventHandler(this, &MainForm::btnLoadPic_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->StatLblXCor, this->StatLblYCor });
			this->statusStrip1->Location = System::Drawing::Point(0, 835);
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
			// uiTimer
			// 
			this->uiTimer->Interval = 1000;
			this->uiTimer->Tick += gcnew System::EventHandler(this, &MainForm::uiTimer_Tick);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(147, 302);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 7;
			this->btnReset->Text = L"重新开始";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 857);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"拼图";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->EndInit();
			this->panel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void uiTimer_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			UpdateInformation();
		}
		// update game information for ui
		void UpdateInformation()
		{
			// update information
			unsigned int uiTotalCount = puzzleOperate->GetTotalClick();
			unsigned int uiTotalTime = puzzleOperate->GetTotalTime();

			try
			{
				TimeSpan tWorkDisply(0, 0, uiTotalTime);
				this->labTime->Text = tWorkDisply.Hours + "小时" + tWorkDisply.Minutes + "分" + tWorkDisply.Seconds + "秒";

				this->labStep->Text = Convert::ToString(uiTotalCount);
			}
			catch (Exception^ e)
			{
				e->ToString();
				return;
			}
		}
		String^ getPictureSelect()
		{
			String^ sPath;

			switch (PicSelect)
			{
			case EPicSelect::Pic1:
				sPath = ".\\source\\PuzzlePic1.jpg";
				break;
			case EPicSelect::Pic2:
				sPath = ".\\source\\PuzzlePic2.jpg";
				break;
			case EPicSelect::Pic3:
				sPath = ".\\source\\PuzzlePic3.jpg";
				break;
			case EPicSelect::Pic4:
				sPath = ".\\source\\PuzzlePic4.jpg";
				break;
			default:
				break;
			}

			return sPath;
		}
		System::Void PBoxView_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{ 
			// just for debug
			// is useless for puzzle
			Geo::TPoint CurPoint(viewWindow->ConvertToWorldCoords(Geo::TPoint(e->X, e->Y)));
			StatLblXCor->Text = "X:" + CurPoint.X().ToString("####.00");
			StatLblYCor->Text = "Y:" + CurPoint.Y().ToString("####.00");
		}
		System::Void PBoxView_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			Geo::TPoint CurPoint(e->X, e->Y);

			bool bWin = false;
			switch (e->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				bWin = puzzleOperate->MoveBlock(ViewGraphics, CurPoint);
				break;
			case System::Windows::Forms::MouseButtons::Right:
				bWin = puzzleOperate->RotateBlock(ViewGraphics, CurPoint);
				break;
			default:
				break;
			}

			DrawBorder();

			PBoxView->Invalidate();

			UpdateInformation();

			if (bWin)
			{
				MessageBox::Show("游戏完成...", "成功");
			}
		}
		
		System::Void PBoxView_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			e->Graphics->DrawImage(ViewImage, 0, 0);
		}
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
		{
			// new bitmap and graphics
			ViewImage = gcnew Bitmap(this->PBoxView->ClientRectangle.Width, this->PBoxView->ClientRectangle.Height);
			ViewGraphics = System::Drawing::Graphics::FromImage(ViewImage);

			SmallViewImage = gcnew Bitmap(this->pictureBox1->ClientRectangle.Width, this->pictureBox1->ClientRectangle.Height);

			DrawBackground();
			DrawBorder();

			// set default option
			PicSelect = EPicSelect::Pic1;
			this->rbPic1->Checked = true;
		}
		void SetViewWindow()
		{
			viewWindow->SetCoordinateSystem(this->PBoxView->ClientRectangle);
		}
		void DrawBorder()
		{
			// draw border and block
			int iWidth = (this->PBoxView->ClientRectangle.Width - 2) / BLOCKS;
			int iHeight = (this->PBoxView->ClientRectangle.Height - 2) / BLOCKS;
			for (int i = 0; i <= BLOCKS; i++)
			{
				Geo::TPoint pt1(i*iWidth, 0);
				Geo::TPoint pt2(i*iWidth, this->PBoxView->ClientRectangle.Height);
				Geo::TPoint pt3(0, i*iHeight + 1);
				Geo::TPoint pt4(this->PBoxView->ClientRectangle.Width, i*iHeight + 1);
				viewWindow->PaintLine(ViewGraphics, pt1, pt2, 3.0);
				viewWindow->PaintLine(ViewGraphics, pt3, pt4, 3.0);
			}
			
			PBoxView->Invalidate();
		}
		void DrawBackground()
		{
			ViewGraphics->Clear(System::Drawing::Color::White);
		}
		// load picture and draw it to the picturebox
		System::Void btnLoadPic_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// if it is already initialize
			// then start new one
			if (puzzleOperate->GetEnable())
			{
				System::Windows::Forms::DialogResult Res = MessageBox::Show("放弃当前游戏并重新开始 ?", "提示", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

				if (Res == System::Windows::Forms::DialogResult::Yes)
					puzzleOperate->ReInitialize(ViewGraphics, getPictureSelect());
				else
					return;
			}
			else 
			{
				String^ sPath = getPictureSelect();

				//Get work area of PBoxView
				System::Drawing::Rectangle NetRect = PBoxView->ClientRectangle;

				try
				{
					// i think give a Graphics is better than get a block memory
					if (!puzzleOperate->Initialize(sPath, ViewGraphics, BLOCKS, NetRect.Width - 1, NetRect.Height - 1))
					{
						MessageBox::Show("读取图片失败.", "错误");
						return;
					}
				}
				catch (Exception^ e)
				{
					e->ToString();
					MessageBox::Show("读取图片失败.", "错误");
					return;
				}

				System::Drawing::Graphics^ SmallViewGraphics = System::Drawing::Graphics::FromImage(SmallViewImage);
				SmallViewGraphics->DrawImage(ViewImage, 0, 0, 200, 200);

				this->pictureBox1->Image = SmallViewImage;
			}

			// new angle
			puzzleOperate->ShuffleBitmapAng(ViewGraphics);
			// new order
			puzzleOperate->ShuffleBitmapOrd(ViewGraphics);

			// refresh ui is necessary
			DrawBorder();
			
			PBoxView->Invalidate();
		}
		System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// if it is already initialize
			// then start new one
			if (puzzleOperate->GetEnable())
			{
				System::Windows::Forms::DialogResult Res = MessageBox::Show("放弃当前游戏并重新开始 ?", "提示", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

				if (Res == System::Windows::Forms::DialogResult::Yes)
					puzzleOperate->ReInitialize(ViewGraphics);			// read picture from hard disk again will be easier
				else
					return;
			}

			// new angle
			puzzleOperate->ShuffleBitmapAng(ViewGraphics);
			// new order
			puzzleOperate->ShuffleBitmapOrd(ViewGraphics);
			// refresh ui is necessary
			DrawBorder();
			PBoxView->Invalidate();
		}
		// update picturebox by radio button
		System::Void radioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
			if (true == this->rbPic1->Checked)
				PicSelect = EPicSelect::Pic1;
			else if (true == this->rbPic2->Checked)
				PicSelect = EPicSelect::Pic2;
			else if (true == this->rbPic3->Checked)
				PicSelect = EPicSelect::Pic3;
			else if (true == this->rbPic4->Checked)
				PicSelect = EPicSelect::Pic4;

			// get picture file path
			String^ sFilePath = getPictureSelect();

			Bitmap^ picBitmap = gcnew Bitmap(Image::FromFile(sFilePath));

			System::Drawing::Graphics^ SmallViewGraphics = System::Drawing::Graphics::FromImage(SmallViewImage);
			SmallViewGraphics->DrawImage(picBitmap, 0, 0, 200, 200);

			//this->pictureBox1->Image->Dispose();

			this->pictureBox1->Image = SmallViewImage;

			// refresh ui is necessary
			DrawBorder();

			PBoxView->Invalidate();

			// must delete the useless memory
			GC::Collect();
		}
		System::Void btnShuffleOrd_Click(System::Object^  sender, System::EventArgs^  e)
		{
			puzzleOperate->ShuffleBitmapOrd(ViewGraphics);

			DrawBorder();

			PBoxView->Invalidate();
		}
		System::Void btnShuffleAng_Click(System::Object^  sender, System::EventArgs^  e)
		{
			puzzleOperate->ShuffleBitmapAng(ViewGraphics);

			DrawBorder();

			PBoxView->Invalidate();
		}

		// load game
		// for test, not finish.
		Void LoadGame()
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

			openFileDialog->InitialDirectory = "D:\\";
			openFileDialog->Filter = "Data files(*.dat)|*.dat";
			openFileDialog->FilterIndex = 1;  //
			openFileDialog->RestoreDirectory = true;

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (puzzleOperate->ReadFrom(openFileDialog->FileName, ViewGraphics))
				{
					MessageBox::Show("读取成功.", "提示");
				}
				else {
					MessageBox::Show("读取失败.", "提示");
				}
			}

			DrawBorder();

			PBoxView->Invalidate();
		}

		// save game
		// for test, not finish
		Void SaveGame()
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

			saveFileDialog->InitialDirectory = "D:\\";
			saveFileDialog->FileName = "NewGame";
			saveFileDialog->Filter = "Data files(*.dat)|*.dat";
			saveFileDialog->FilterIndex = 1;  //
			saveFileDialog->RestoreDirectory = true;

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (puzzleOperate->WriteTo(saveFileDialog->FileName))
				{
					MessageBox::Show("保存成功.", "提示");
				}
				else {
					MessageBox::Show("保存失败.", "提示");
				}
			}
		}
};
}