#pragma once

#include <queue>
#include <ctime>
#include "../../Paint/ViewWindow.h"
#include "Akima.h"
#include "SpeedControl.h"

namespace SpeedControl {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace HGUI;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			viewWindow = new ViewWindow();

			speedControl = new TSpeedControl();

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
	private: System::Windows::Forms::ToolStripMenuItem^  fileFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  PBoxView;
	private: System::Windows::Forms::ToolStripStatusLabel^  StatLblXCor;
	private: System::Windows::Forms::ToolStripStatusLabel^  StatLblYCor;
	private: System::Windows::Forms::Button^  btnGenerate;
	private: System::Windows::Forms::Button^  btnAkima;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txbPoint6;
	private: System::Windows::Forms::TextBox^  txbPoint5;
	private: System::Windows::Forms::TextBox^  txbPoint4;
	private: System::Windows::Forms::TextBox^  txbPoint3;
	private: System::Windows::Forms::TextBox^  txbPoint2;
	private: System::Windows::Forms::TextBox^  txbPoint1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  btnAkimaOpt;
	private: System::Windows::Forms::ComboBox^  cbAkimaStrategy;
	private: System::Windows::Forms::Label^  label10;
	protected:

	private:
		System::ComponentModel::Container	^components;
		ViewWindow							*viewWindow;
		Bitmap^								ViewImage;
		System::Drawing::Graphics^			ViewGraphics;
		TSpeedControl						*speedControl;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->PBoxView = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cbAkimaStrategy = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->btnAkimaOpt = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbPoint6 = (gcnew System::Windows::Forms::TextBox());
			this->txbPoint5 = (gcnew System::Windows::Forms::TextBox());
			this->txbPoint4 = (gcnew System::Windows::Forms::TextBox());
			this->txbPoint3 = (gcnew System::Windows::Forms::TextBox());
			this->txbPoint2 = (gcnew System::Windows::Forms::TextBox());
			this->txbPoint1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAkima = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->StatLblXCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->StatLblYCor = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
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
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Location = System::Drawing::Point(777, 28);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(275, 628);
			this->panel2->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cbAkimaStrategy);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->btnAkimaOpt);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->btnClear);
			this->groupBox2->Controls->Add(this->btnGenerate);
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(269, 263);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Generate path";
			// 
			// cbAkimaStrategy
			// 
			this->cbAkimaStrategy->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbAkimaStrategy->FormattingEnabled = true;
			this->cbAkimaStrategy->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Normal", L"Ti = (M(i-1) + M(i)) / 2", L"Ti = Mi" });
			this->cbAkimaStrategy->Location = System::Drawing::Point(113, 112);
			this->cbAkimaStrategy->Name = L"cbAkimaStrategy";
			this->cbAkimaStrategy->Size = System::Drawing::Size(150, 20);
			this->cbAkimaStrategy->TabIndex = 9;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 115);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(95, 12);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Akima strategy:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 54);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(101, 12);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Draw with akima:";
			// 
			// btnAkimaOpt
			// 
			this->btnAkimaOpt->Location = System::Drawing::Point(188, 49);
			this->btnAkimaOpt->Name = L"btnAkimaOpt";
			this->btnAkimaOpt->Size = System::Drawing::Size(75, 23);
			this->btnAkimaOpt->TabIndex = 6;
			this->btnAkimaOpt->Text = L"Start";
			this->btnAkimaOpt->UseVisualStyleBackColor = true;
			this->btnAkimaOpt->Click += gcnew System::EventHandler(this, &MainForm::btnAkimaOpt_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 83);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 12);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Clear:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 12);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Generate path:";
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(188, 83);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 3;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
			// 
			// btnGenerate
			// 
			this->btnGenerate->Location = System::Drawing::Point(188, 20);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(75, 23);
			this->btnGenerate->TabIndex = 0;
			this->btnGenerate->Text = L"Start";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &MainForm::btnGenerate_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txbPoint6);
			this->groupBox1->Controls->Add(this->txbPoint5);
			this->groupBox1->Controls->Add(this->txbPoint4);
			this->groupBox1->Controls->Add(this->txbPoint3);
			this->groupBox1->Controls->Add(this->txbPoint2);
			this->groupBox1->Controls->Add(this->txbPoint1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->btnAkima);
			this->groupBox1->Location = System::Drawing::Point(3, 272);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(269, 335);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Akima optimize";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 158);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 12);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Point6:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 12);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Point5:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 12);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Point4:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 12);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Point3:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 12);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Point2:";
			// 
			// txbPoint6
			// 
			this->txbPoint6->Location = System::Drawing::Point(116, 155);
			this->txbPoint6->Name = L"txbPoint6";
			this->txbPoint6->Size = System::Drawing::Size(100, 21);
			this->txbPoint6->TabIndex = 8;
			// 
			// txbPoint5
			// 
			this->txbPoint5->Location = System::Drawing::Point(116, 128);
			this->txbPoint5->Name = L"txbPoint5";
			this->txbPoint5->Size = System::Drawing::Size(100, 21);
			this->txbPoint5->TabIndex = 7;
			// 
			// txbPoint4
			// 
			this->txbPoint4->Location = System::Drawing::Point(116, 101);
			this->txbPoint4->Name = L"txbPoint4";
			this->txbPoint4->Size = System::Drawing::Size(100, 21);
			this->txbPoint4->TabIndex = 6;
			// 
			// txbPoint3
			// 
			this->txbPoint3->Location = System::Drawing::Point(116, 74);
			this->txbPoint3->Name = L"txbPoint3";
			this->txbPoint3->Size = System::Drawing::Size(100, 21);
			this->txbPoint3->TabIndex = 5;
			// 
			// txbPoint2
			// 
			this->txbPoint2->Location = System::Drawing::Point(116, 47);
			this->txbPoint2->Name = L"txbPoint2";
			this->txbPoint2->Size = System::Drawing::Size(100, 21);
			this->txbPoint2->TabIndex = 4;
			// 
			// txbPoint1
			// 
			this->txbPoint1->Location = System::Drawing::Point(116, 20);
			this->txbPoint1->Name = L"txbPoint1";
			this->txbPoint1->Size = System::Drawing::Size(100, 21);
			this->txbPoint1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 12);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Point1:";
			// 
			// btnAkima
			// 
			this->btnAkima->Location = System::Drawing::Point(188, 206);
			this->btnAkima->Name = L"btnAkima";
			this->btnAkima->Size = System::Drawing::Size(75, 23);
			this->btnAkima->TabIndex = 1;
			this->btnAkima->Text = L"Start";
			this->btnAkima->UseVisualStyleBackColor = true;
			this->btnAkima->Click += gcnew System::EventHandler(this, &MainForm::btnAkima_Click);
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileFToolStripMenuItem,
					this->optionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1064, 25);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileFToolStripMenuItem
			// 
			this->fileFToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileFToolStripMenuItem->Name = L"fileFToolStripMenuItem";
			this->fileFToolStripMenuItem->Size = System::Drawing::Size(39, 21);
			this->fileFToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(96, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// optionToolStripMenuItem
			// 
			this->optionToolStripMenuItem->Name = L"optionToolStripMenuItem";
			this->optionToolStripMenuItem->Size = System::Drawing::Size(60, 21);
			this->optionToolStripMenuItem->Text = L"Option";
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
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"SpeedControl";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBoxView))->EndInit();
			this->panel2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	System::Void PBoxView_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		Geo::TPoint CurPoint( viewWindow->ConvertToWorldCoords(Geo::TPoint(e->X, e->Y)) );
		StatLblXCor->Text = "X:" + CurPoint.X().ToString("####.00");
		StatLblYCor->Text = "Y:" + CurPoint.Y().ToString("####.00");
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

		DrawBackground();
		DrawBorder();

		/*this->txbPoint1->Text = "30.0, 20.0";
		this->txbPoint2->Text = "150.0, 50.0";
		this->txbPoint3->Text = "280.0, 150.0";
		this->txbPoint4->Text = "450.0, 450.0";
		this->txbPoint5->Text = "600.0, 520.0";
		this->txbPoint6->Text = "700.0, 530.0";*/

		this->txbPoint1->Text = "200, 100";
		this->txbPoint2->Text = "100, 300";
		this->txbPoint3->Text = "200, 500";
		this->txbPoint4->Text = "400, 500";
		this->txbPoint5->Text = "500, 300";
		this->txbPoint6->Text = "400, 100";

		cbAkimaStrategy->SelectedIndex = 0;
	}
	void SetViewWindow()
	{
		viewWindow->SetCoordinateSystem(this->PBoxView->ClientRectangle);
	}
	void DrawBorder()
	{
		// draw border
		System::Drawing::Rectangle NetRect = PBoxView->ClientRectangle;//Get work area of PBoxView
		Geo::TRectangle Rect(1, 1, NetRect.Width - 1, NetRect.Height - 1);
		viewWindow->PaintRectangle(ViewGraphics, Rect);

		PBoxView->Invalidate();
	}
	void DrawBackground()
	{
		ViewGraphics->Clear(System::Drawing::Color::White);
	}
	System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DrawBackground();
		DrawBorder();
	}
	System::Void btnGenerate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		speedControl->GeneratePath();

		std::vector<Geo::TPoint> VecPt = speedControl->GetPathVec();
		// clear old
		DrawBackground();
		DrawBorder();
		// draw point
		for (size_t i = 0; i < VecPt.size() - 1; i++)
		{
			viewWindow->PaintPoint(ViewGraphics, VecPt[i], 5.0);
			viewWindow->PaintLine(ViewGraphics, VecPt[i], VecPt[i+1]);
		}
		viewWindow->PaintPoint(ViewGraphics, VecPt[VecPt.size() - 1], 5.0);

		PBoxView->Invalidate();
	}
	System::Void btnAkimaOpt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DrawAkima(speedControl->GetPathVec());
	}
	System::Void btnAkima_Click(System::Object^  sender, System::EventArgs^  e)
	{
		std::vector<Geo::TPoint> VecPt;

		// first point
		try
		{
			String^ sInput = this->txbPoint1->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint1->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX - 20, dPosY));
			VecPt.push_back(Geo::TPoint(dPosX - 10, dPosY));
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint1->ForeColor = System::Drawing::Color::Red;
			return;
		}

		// second point
		try
		{
			String^ sInput = this->txbPoint2->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint2->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint2->ForeColor = System::Drawing::Color::Red;
			return;
		}

		// third point
		try
		{
			String^ sInput = this->txbPoint3->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint3->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint3->ForeColor = System::Drawing::Color::Red;
			return;
		}

		// fourth point
		try
		{
			String^ sInput = this->txbPoint4->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint4->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint4->ForeColor = System::Drawing::Color::Red;
			return;
		}

		// fivth point
		try
		{
			String^ sInput = this->txbPoint5->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint5->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint5->ForeColor = System::Drawing::Color::Red;
			return;
		}

		// sixth point
		try
		{
			String^ sInput = this->txbPoint6->Text;
			if ("" == sInput)
				return;

			int iPos = sInput->IndexOf(",");
			String^ sPosX = sInput->Substring(0, iPos);
			String^ sPosY = sInput->Substring(iPos + 1, sInput->Length - iPos - 1);
			double dPosX = Convert::ToDouble(sPosX);
			double dPosY = Convert::ToDouble(sPosY);

			this->txbPoint6->ForeColor = System::Drawing::Color::Black;

			// insert to vector
			VecPt.push_back(Geo::TPoint(dPosX, dPosY));
			VecPt.push_back(Geo::TPoint(dPosX + 10, dPosY));
			VecPt.push_back(Geo::TPoint(dPosX + 20, dPosY));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
			this->txbPoint6->ForeColor = System::Drawing::Color::Red;
			return;
		}

		if (VecPt.size() != 10)
			return;

		DrawAkima(VecPt);
		
	}

	void DrawAkima(const std::vector<Geo::TPoint> &VecPt)
	{
		std::vector<Geo::TPoint> NewPt;
		std::vector<Geo::TPoint> AkimaPt;

		int iAkimaStrategy = this->cbAkimaStrategy->SelectedIndex;

		for (unsigned int i = 0; i < VecPt.size(); i++)
		{
			AkimaPt.push_back(Geo::TPoint(VecPt[i].X(), VecPt[i].Y()));

			if (AkimaPt.size() > 5)
			{
				TAkima	akima;
				akima.AkimaInit(AkimaPt, iAkimaStrategy);

				double dLow = AkimaPt[2].X();
				double dHeigh = AkimaPt[3].X();
				if (dLow > dHeigh)
					std::swap(dLow, dHeigh);
				for (double d = dLow; d <= dHeigh; )
				{
					NewPt.push_back(Geo::TPoint(d, akima.GetAkimaCoordY(d)));
					if ((dHeigh - dLow) < 20)
					{
						d++;
					}
					else {
						d += 10;
					}
				}

				i -= 5;
				AkimaPt.clear();
			}
		}

		// draw point
		for (size_t i = 2; i < VecPt.size() - 2; i++)
		{
			viewWindow->PaintPoint(ViewGraphics, VecPt[i], 5.0);
		}

		for (size_t i = 0; i < NewPt.size(); i++)
		{
			viewWindow->PaintPoint(ViewGraphics, NewPt[i], 3.0);
		}

		PBoxView->Invalidate();
	}

};
}
