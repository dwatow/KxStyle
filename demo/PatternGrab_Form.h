#pragma once
#include "DataStructure.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace DensityClass; 


namespace PatternContruction {

	/// <summary>
	/// PatternGrab_Form 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class PatternGrab_Form : public System::Windows::Forms::Form
	{
	public:
		PatternGrab_Form(Pattern^ Dot ,RectangleF^ LGP ,DensityClass::GridDensity^ Density)
		{
			InitializeComponent();
			if(Dot != nullptr) tmpDot = Dot;
			if(LGP->IsEmpty == false) tmpLGP = LGP;
			if(Density != nullptr) tmpDensity=Density;
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~PatternGrab_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 













	private: System::Windows::Forms::DataGridView^  dataGridView_ActualDesign_Density;
	private: System::Windows::Forms::Button^  btnCal;
	private: System::Windows::Forms::Button^  btnExit;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TextBox^  txtLGP_Y;
	private: System::Windows::Forms::TextBox^  txtLGP_X;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtMeshNumber_W;
	private: System::Windows::Forms::TextBox^  txtMeshNum_L;
	private: System::Windows::Forms::TextBox^  txtMeshSize_W;
	private: System::Windows::Forms::TextBox^  txtMeshSize_L;
	private: System::Windows::Forms::TextBox^  txt_LGPWidth;
	private: System::Windows::Forms::TextBox^  txt_LGPLength;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TextBox^  txtMeshY;

	private: System::Windows::Forms::TextBox^  txtMeshX;

	private: System::Windows::Forms::Label^  label5;




		Pattern^ tmpDot;
		RectangleF^ tmpLGP;




	private: System::Windows::Forms::ComboBox^  cboratioY;

	private: System::Windows::Forms::ComboBox^  cboratioX;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtShiftY;

	private: System::Windows::Forms::TextBox^  txtShiftX;

	private: System::Windows::Forms::TextBox^  txtRatioY;

	private: System::Windows::Forms::TextBox^  txtRatioX;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  cboCrossSection;


	private: System::Windows::Forms::TextBox^  txtTargetValue;
	private: System::Windows::Forms::Label^  lblCoordinate;



			 DensityClass::GridDensity^ tmpDensity;

		float GetPatternAreaInRec(RectangleF Rec,PointF DotCoor,float DotDia);
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView_ActualDesign_Density = (gcnew System::Windows::Forms::DataGridView());
			this->btnCal = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->txtLGP_Y = (gcnew System::Windows::Forms::TextBox());
			this->txtLGP_X = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtMeshNumber_W = (gcnew System::Windows::Forms::TextBox());
			this->txtMeshNum_L = (gcnew System::Windows::Forms::TextBox());
			this->txtMeshSize_W = (gcnew System::Windows::Forms::TextBox());
			this->txtMeshSize_L = (gcnew System::Windows::Forms::TextBox());
			this->txt_LGPWidth = (gcnew System::Windows::Forms::TextBox());
			this->txt_LGPLength = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->txtShiftY = (gcnew System::Windows::Forms::TextBox());
			this->txtShiftX = (gcnew System::Windows::Forms::TextBox());
			this->txtRatioY = (gcnew System::Windows::Forms::TextBox());
			this->txtRatioX = (gcnew System::Windows::Forms::TextBox());
			this->cboratioY = (gcnew System::Windows::Forms::ComboBox());
			this->cboratioX = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtMeshY = (gcnew System::Windows::Forms::TextBox());
			this->txtMeshX = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->txtTargetValue = (gcnew System::Windows::Forms::TextBox());
			this->lblCoordinate = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->cboCrossSection = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ActualDesign_Density))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView_ActualDesign_Density
			// 
			this->dataGridView_ActualDesign_Density->AllowUserToAddRows = false;
			this->dataGridView_ActualDesign_Density->AllowUserToDeleteRows = false;
			this->dataGridView_ActualDesign_Density->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_ActualDesign_Density->Location = System::Drawing::Point(12, 175);
			this->dataGridView_ActualDesign_Density->Name = L"dataGridView_ActualDesign_Density";
			this->dataGridView_ActualDesign_Density->ReadOnly = true;
			this->dataGridView_ActualDesign_Density->RowHeadersWidth = 21;
			this->dataGridView_ActualDesign_Density->RowTemplate->Height = 24;
			this->dataGridView_ActualDesign_Density->RowTemplate->ReadOnly = true;
			this->dataGridView_ActualDesign_Density->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView_ActualDesign_Density->Size = System::Drawing::Size(369, 212);
			this->dataGridView_ActualDesign_Density->TabIndex = 9;
			// 
			// btnCal
			// 
			this->btnCal->Location = System::Drawing::Point(387, 304);
			this->btnCal->Name = L"btnCal";
			this->btnCal->Size = System::Drawing::Size(83, 31);
			this->btnCal->TabIndex = 10;
			this->btnCal->Text = L"計算";
			this->btnCal->UseVisualStyleBackColor = true;
			this->btnCal->Click += gcnew System::EventHandler(this, &PatternGrab_Form::btnCal_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(387, 341);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(83, 31);
			this->btnExit->TabIndex = 11;
			this->btnExit->Text = L"離開";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &PatternGrab_Form::btnExit_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(369, 170);
			this->tabControl1->TabIndex = 15;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->txtLGP_Y);
			this->tabPage1->Controls->Add(this->txtLGP_X);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->txtMeshNumber_W);
			this->tabPage1->Controls->Add(this->txtMeshNum_L);
			this->tabPage1->Controls->Add(this->txtMeshSize_W);
			this->tabPage1->Controls->Add(this->txtMeshSize_L);
			this->tabPage1->Controls->Add(this->txt_LGPWidth);
			this->tabPage1->Controls->Add(this->txt_LGPLength);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 21);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(361, 145);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Pattern概估密度";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// txtLGP_Y
			// 
			this->txtLGP_Y->Location = System::Drawing::Point(214, 11);
			this->txtLGP_Y->Margin = System::Windows::Forms::Padding(4);
			this->txtLGP_Y->Name = L"txtLGP_Y";
			this->txtLGP_Y->Size = System::Drawing::Size(73, 22);
			this->txtLGP_Y->TabIndex = 26;
			// 
			// txtLGP_X
			// 
			this->txtLGP_X->Location = System::Drawing::Point(133, 11);
			this->txtLGP_X->Margin = System::Windows::Forms::Padding(4);
			this->txtLGP_X->Name = L"txtLGP_X";
			this->txtLGP_X->Size = System::Drawing::Size(73, 22);
			this->txtLGP_X->TabIndex = 25;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 12);
			this->label4->TabIndex = 24;
			this->label4->Text = L"LGP左下角座標";
			// 
			// txtMeshNumber_W
			// 
			this->txtMeshNumber_W->Location = System::Drawing::Point(214, 101);
			this->txtMeshNumber_W->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshNumber_W->Name = L"txtMeshNumber_W";
			this->txtMeshNumber_W->Size = System::Drawing::Size(73, 22);
			this->txtMeshNumber_W->TabIndex = 23;
			this->txtMeshNumber_W->Text = L"5";
			// 
			// txtMeshNum_L
			// 
			this->txtMeshNum_L->Location = System::Drawing::Point(133, 101);
			this->txtMeshNum_L->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshNum_L->Name = L"txtMeshNum_L";
			this->txtMeshNum_L->Size = System::Drawing::Size(73, 22);
			this->txtMeshNum_L->TabIndex = 22;
			this->txtMeshNum_L->Text = L"5";
			// 
			// txtMeshSize_W
			// 
			this->txtMeshSize_W->Location = System::Drawing::Point(214, 71);
			this->txtMeshSize_W->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshSize_W->Name = L"txtMeshSize_W";
			this->txtMeshSize_W->Size = System::Drawing::Size(73, 22);
			this->txtMeshSize_W->TabIndex = 21;
			this->txtMeshSize_W->Text = L"10";
			// 
			// txtMeshSize_L
			// 
			this->txtMeshSize_L->Location = System::Drawing::Point(133, 71);
			this->txtMeshSize_L->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshSize_L->Name = L"txtMeshSize_L";
			this->txtMeshSize_L->Size = System::Drawing::Size(73, 22);
			this->txtMeshSize_L->TabIndex = 20;
			this->txtMeshSize_L->Text = L"10";
			// 
			// txt_LGPWidth
			// 
			this->txt_LGPWidth->Location = System::Drawing::Point(214, 41);
			this->txt_LGPWidth->Margin = System::Windows::Forms::Padding(4);
			this->txt_LGPWidth->Name = L"txt_LGPWidth";
			this->txt_LGPWidth->Size = System::Drawing::Size(73, 22);
			this->txt_LGPWidth->TabIndex = 19;
			// 
			// txt_LGPLength
			// 
			this->txt_LGPLength->Location = System::Drawing::Point(133, 41);
			this->txt_LGPLength->Margin = System::Windows::Forms::Padding(4);
			this->txt_LGPLength->Name = L"txt_LGPLength";
			this->txt_LGPLength->Size = System::Drawing::Size(73, 22);
			this->txt_LGPLength->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 17;
			this->label3->Text = L"抓取網格數";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 12);
			this->label2->TabIndex = 16;
			this->label2->Text = L"抓取密度網格大小";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 15;
			this->label1->Text = L"LGP 尺寸";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->txtShiftY);
			this->tabPage2->Controls->Add(this->txtShiftX);
			this->tabPage2->Controls->Add(this->txtRatioY);
			this->tabPage2->Controls->Add(this->txtRatioX);
			this->tabPage2->Controls->Add(this->cboratioY);
			this->tabPage2->Controls->Add(this->cboratioX);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->txtMeshY);
			this->tabPage2->Controls->Add(this->txtMeshX);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Location = System::Drawing::Point(4, 21);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(361, 145);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"軟體設計密度";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// txtShiftY
			// 
			this->txtShiftY->Location = System::Drawing::Point(133, 113);
			this->txtShiftY->Margin = System::Windows::Forms::Padding(4);
			this->txtShiftY->Name = L"txtShiftY";
			this->txtShiftY->Size = System::Drawing::Size(56, 22);
			this->txtShiftY->TabIndex = 41;
			this->txtShiftY->Text = L"0";
			// 
			// txtShiftX
			// 
			this->txtShiftX->Location = System::Drawing::Point(133, 89);
			this->txtShiftX->Margin = System::Windows::Forms::Padding(4);
			this->txtShiftX->Name = L"txtShiftX";
			this->txtShiftX->Size = System::Drawing::Size(56, 22);
			this->txtShiftX->TabIndex = 40;
			this->txtShiftX->Text = L"0";
			// 
			// txtRatioY
			// 
			this->txtRatioY->Location = System::Drawing::Point(133, 64);
			this->txtRatioY->Margin = System::Windows::Forms::Padding(4);
			this->txtRatioY->Name = L"txtRatioY";
			this->txtRatioY->Size = System::Drawing::Size(56, 22);
			this->txtRatioY->TabIndex = 39;
			this->txtRatioY->Text = L"0";
			// 
			// txtRatioX
			// 
			this->txtRatioX->Location = System::Drawing::Point(133, 38);
			this->txtRatioX->Margin = System::Windows::Forms::Padding(4);
			this->txtRatioX->Name = L"txtRatioX";
			this->txtRatioX->Size = System::Drawing::Size(56, 22);
			this->txtRatioX->TabIndex = 38;
			this->txtRatioX->Text = L"0";
			// 
			// cboratioY
			// 
			this->cboratioY->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboratioY->FormattingEnabled = true;
			this->cboratioY->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"mm", L"%"});
			this->cboratioY->Location = System::Drawing::Point(193, 64);
			this->cboratioY->Name = L"cboratioY";
			this->cboratioY->Size = System::Drawing::Size(50, 20);
			this->cboratioY->TabIndex = 35;
			// 
			// cboratioX
			// 
			this->cboratioX->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboratioX->FormattingEnabled = true;
			this->cboratioX->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"mm", L"%"});
			this->cboratioX->Location = System::Drawing::Point(193, 38);
			this->cboratioX->Name = L"cboratioX";
			this->cboratioX->Size = System::Drawing::Size(50, 20);
			this->cboratioX->TabIndex = 34;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(25, 116);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 12);
			this->label9->TabIndex = 33;
			this->label9->Text = L"Y方向偏移";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(25, 95);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(61, 12);
			this->label8->TabIndex = 32;
			this->label8->Text = L"X方向偏移";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(25, 72);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 12);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Y方向內縮";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 12);
			this->label6->TabIndex = 30;
			this->label6->Text = L"X方向內縮";
			// 
			// txtMeshY
			// 
			this->txtMeshY->Location = System::Drawing::Point(214, 12);
			this->txtMeshY->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshY->Name = L"txtMeshY";
			this->txtMeshY->Size = System::Drawing::Size(73, 22);
			this->txtMeshY->TabIndex = 29;
			this->txtMeshY->Text = L"5";
			// 
			// txtMeshX
			// 
			this->txtMeshX->Location = System::Drawing::Point(133, 12);
			this->txtMeshX->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshX->Name = L"txtMeshX";
			this->txtMeshX->Size = System::Drawing::Size(73, 22);
			this->txtMeshX->TabIndex = 28;
			this->txtMeshX->Text = L"5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 12);
			this->label5->TabIndex = 27;
			this->label5->Text = L"網格數";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->txtTargetValue);
			this->tabPage3->Controls->Add(this->lblCoordinate);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->cboCrossSection);
			this->tabPage3->Location = System::Drawing::Point(4, 21);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(361, 145);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"網點直徑";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// txtTargetValue
			// 
			this->txtTargetValue->Location = System::Drawing::Point(88, 51);
			this->txtTargetValue->Margin = System::Windows::Forms::Padding(4);
			this->txtTargetValue->Name = L"txtTargetValue";
			this->txtTargetValue->Size = System::Drawing::Size(107, 22);
			this->txtTargetValue->TabIndex = 42;
			this->txtTargetValue->Text = L"0";
			// 
			// lblCoordinate
			// 
			this->lblCoordinate->AutoSize = true;
			this->lblCoordinate->Location = System::Drawing::Point(17, 54);
			this->lblCoordinate->Name = L"lblCoordinate";
			this->lblCoordinate->Size = System::Drawing::Size(53, 12);
			this->lblCoordinate->TabIndex = 37;
			this->lblCoordinate->Text = L"座標位置";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(17, 24);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 12);
			this->label10->TabIndex = 36;
			this->label10->Text = L"Profile方向";
			// 
			// cboCrossSection
			// 
			this->cboCrossSection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboCrossSection->FormattingEnabled = true;
			this->cboCrossSection->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"X 方向Profile", L"Y 方向Profile"});
			this->cboCrossSection->Location = System::Drawing::Point(88, 21);
			this->cboCrossSection->Name = L"cboCrossSection";
			this->cboCrossSection->Size = System::Drawing::Size(107, 20);
			this->cboCrossSection->TabIndex = 35;
			this->cboCrossSection->SelectedIndexChanged += gcnew System::EventHandler(this, &PatternGrab_Form::cboCrossSection_SelectedIndexChanged);
			// 
			// PatternGrab_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 399);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnCal);
			this->Controls->Add(this->dataGridView_ActualDesign_Density);
			this->Name = L"PatternGrab_Form";
			this->Text = L"網點密度分析";
			this->Load += gcnew System::EventHandler(this, &PatternGrab_Form::PatternGrab_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ActualDesign_Density))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PatternGrab_Form_Load(System::Object^  sender, System::EventArgs^  e) {

				this->txtLGP_X->Text = String::Format("{0:0.00}",this->tmpLGP->X);
				this->txtLGP_Y->Text = String::Format("{0:0.00}",this->tmpLGP->Y);
				this->txt_LGPLength->Text = String::Format("{0:0.00}",this->tmpLGP->Width);
				this->txt_LGPWidth->Text = String::Format("{0:0.00}",this->tmpLGP->Height);
				this->cboratioX->SelectedIndex = 0;
				this->cboratioY->SelectedIndex = 0;
				if(this->tmpDot->GetDotNumber() == 0 ){ 
					this->tabPage1->Enabled = false;
					this->tabPage3->Enabled = false;
				}
				if(this->tmpDensity == nullptr) this->tabPage2->Enabled = false;


				if(this->tmpDot->GetDotNumber() == 0) {
					this->tabPage1->Enabled = false;
					this->tabPage3->Enabled = false;
				}else{
					this->tabPage1->Enabled = true;
					this->tabPage3->Enabled = true;
				}

				if(this->tmpDensity->IsDensityEmpty == true){
					this->tabPage2->Enabled = false;
				}else{
					this->tabPage2->Enabled = true;
				}






			 }
private: System::Void btnCal_Click(System::Object^  sender, System::EventArgs^  e) {

		
			 
			 if(this->tmpDot != nullptr && this->tabControl1->SelectedIndex == 0 && this->tabPage1->Enabled == true){


				 int NumL = Convert::ToUInt16(this->txtMeshNum_L->Text);
				 int NumW = Convert::ToInt16(this->txtMeshNumber_W->Text);
				 PointF MeshSize(Convert::ToSingle(this->txtMeshSize_L->Text),Convert::ToSingle(this->txtMeshSize_W->Text));

				 this->tmpLGP->Width = Convert::ToSingle(this->txt_LGPLength->Text);
				 this->tmpLGP->Height = Convert::ToSingle(this->txt_LGPWidth->Text);
				 this->tmpLGP->X = Convert::ToSingle(this->txtLGP_X->Text);
				 this->tmpLGP->Y = Convert::ToSingle(this->txtLGP_Y->Text);

				 
				 array<float ,2>^ Density = gcnew array<float,2>(NumL,NumW);
				 
				
				 for(int ii =0 ;ii <this->tmpDot->GetDotNumber() ;ii++){
					 int indexX = -1;
					 int indexY = -1;
					 PointF dotCoordinate;
					 float dotDia;
					 this->tmpDot->GetDotValue(dotCoordinate,dotDia,ii);
					

					 float pitchX = ( this->tmpLGP->Width-MeshSize.X)/(NumL-1);
					 float pitchY = (this->tmpLGP->Height-MeshSize.Y)/(NumW-1);


					 for(int jj = 0 ;jj < NumL ; jj++){
						 if(dotCoordinate.X>=(jj*pitchX + this->tmpLGP->X) && dotCoordinate.X<=(jj*pitchX+MeshSize.X + this->tmpLGP->X)){
								indexX = jj;
								break;
						 }

					 }

					 for(int kk = 0 ;kk < NumW ;kk++){
						if(dotCoordinate.Y>=(kk*pitchY + this->tmpLGP->Y) && dotCoordinate.Y<=(kk*pitchY+MeshSize.Y + this->tmpLGP->Y)){
								indexY = kk;
								break;
						 }
					 }


					 //計算網格的面積<粗略值>
					 if(indexX != -1 && indexY != -1){
						 float tmpArea = (float)Density->GetValue(indexX,indexY) + (float)Math::PI*dotDia*dotDia/4;
						 Density->SetValue(tmpArea,indexX,indexY);
					 }

				 }


				 //將Density面積值轉換為比例值 
				 for(int ii = 0 ;ii < NumL ;ii ++){
					 for(int jj = 0 ;jj< NumW; jj++){
						  float tmpDensity = (float)Density->GetValue(ii,jj);
						//  tmpDensity = 100*tmpDensity/(MeshSize.X*MeshSize.Y);
						   tmpDensity = tmpDensity/(MeshSize.X*MeshSize.Y);
						  Density->SetValue(tmpDensity,ii,jj);
					 }

				 }
		
				this->dataGridView_ActualDesign_Density->ColumnCount::set(NumL);
				this->dataGridView_ActualDesign_Density->RowCount::set(NumW);
				
				
				for(int ii = 0 ; ii < NumL ; ii ++){
						for(int jj = 0 ;jj < NumW ;jj ++){
						
							float Z = 0;
							Z = (float)Density->GetValue(ii,jj);
							this->dataGridView_ActualDesign_Density->default[ii,NumW-jj-1]->Value = String::Format("{0:0.000}",Z);
																	 
						 }
				}
			 }else if(this->tmpDensity != nullptr && this->tabControl1->SelectedIndex == 1 && this->tabPage2->Enabled == true){
				 //Density 密度
				 Point Mesh = this->tmpDensity->GetMeshNumber();



				 int NumX = Convert::ToUInt16(this->txtMeshX->Text);
				 int NumY = Convert::ToInt16(this->txtMeshY->Text);
				 int RatioX ;int RatioY;
				 int ShiftX; int ShiftY;

				 if(this->cboratioX->SelectedIndex == 0)	RatioX = (int)(Convert::ToSingle(this->txtRatioX->Text)/(this->tmpLGP->Width)*Mesh.X);
				 else	RatioX =(int)(Convert::ToSingle(this->txtRatioX->Text)*Mesh.X/100);

				 if(this->cboratioY->SelectedIndex == 0)	RatioY = (int)(Convert::ToSingle(this->txtRatioY->Text)/(this->tmpLGP->Height)*Mesh.Y);
				 else	RatioY =(int)(Convert::ToSingle(this->txtRatioY->Text)*Mesh.Y/100);

				 ShiftX =(int)( Convert::ToSingle(this->txtShiftX->Text)/(this->tmpLGP->Width)*Mesh.X);
				 ShiftY =(int)( Convert::ToSingle(this->txtShiftY->Text)/(this->tmpLGP->Height)*Mesh.Y);
				

				 



				 if(NumX <2 || NumY <2){
					 MessageBox::Show("數值不能夠小於2!!");					 
				 }else {
					this->dataGridView_ActualDesign_Density->ColumnCount::set(NumX);
					this->dataGridView_ActualDesign_Density->RowCount::set(NumY);
					
					for(int ii = 0 ; ii < NumX ; ii ++){
						for(int jj = 0 ;jj < NumY ;jj ++){
							
							int a =(int) Math::Round(RatioX + (float)(Mesh.X-1-2*RatioX)/(float)(NumX-1)*(float)ii); // 一定要用float ,不然整數除以整數數值會有問題
							int b =(int) Math::Round(RatioY + (float)(Mesh.Y-1-2*RatioY)/(float)(NumY-1)*(float)jj); // 一定要用float ,不然整數除以整數數值會有問題							
							float Z = 0;								
							Point Index(a+ShiftX ,b+ShiftY);

							if(Index.X < 0) Index.X = 0;
							if(Index.Y < 0) Index.Y = 0;
							if(Index.X > Mesh.X-1) Index.X = Mesh.X-1;
							if(Index.Y > Mesh.Y-1) Index.Y = Mesh.Y-1;

							Z = this->tmpDensity->GetDensityValue(Index);
							this->dataGridView_ActualDesign_Density->default[ii,NumY-1-jj]->Value = String::Format("{0:0.000}",100*Z);																	 
						 }

					}
				 }

			 }else if(this->tmpDot != nullptr && this->tabPage3->Enabled == true){
				 //抓網點直徑

			
				 array<float>^ dia = gcnew array<float>(0) ;
				 array<float>^ locationX = gcnew array<float>(0) ;
				 array<float>^ locationY = gcnew array<float>(0) ;
				  int count = 0;
				  float selectRange = 0;
				  Point MeshNumber = this->tmpDensity->GetMeshNumber();					
				  float targetValue = Convert::ToSingle(this->txtTargetValue->Text);

				  if (MeshNumber.X * MeshNumber.Y *1.5 >= this->tmpDot->GetDotNumber()){
					  //表示90度排列
					  selectRange = 0.5f;
				  }else{
					  selectRange = 0.25f;
				  }




				 if(this->cboCrossSection->SelectedIndex == 0 ){  

					
					
					  
					
											

					 //  X 方向Profile (橫截面 Profile)
					

					 for(int ii = 0 ; ii <this->tmpDot->GetDotNumber() ; ii ++){
						 PointF coordinate ;
						 float Diameter ;
						 this->tmpDot->GetDotValue(coordinate,Diameter,ii);
						 float ratio = Convert::ToSingle(this->tmpDot->ModifyRate_LocalArea->GetValue(ii));
						 
						

						 if(Math::Abs(coordinate.Y-targetValue) <= (selectRange*this->tmpLGP->Height/MeshNumber.Y)){							 
							 count ++ ;
							 Array::Resize(dia,count);
							 Array::Resize(locationX,count);
							 Array::Resize(locationY,count);

							 dia->SetValue(Diameter*ratio,count-1);
							 locationX->SetValue(coordinate.X,count-1);
							 locationY->SetValue(coordinate.Y,count-1);

						 }
						 
					 }

				
					 
					 array<float>^ tmparray =gcnew array<float>(count);
					 locationX->CopyTo(tmparray,0);
					 Array::Sort(tmparray,dia);
					 locationX->CopyTo(tmparray,0);
					  Array::Sort(tmparray,locationY);


					 this->dataGridView_ActualDesign_Density->ColumnCount::set(3);
					 this->dataGridView_ActualDesign_Density->RowCount::set(count);




				 }else{

					// Y 方向Profile ( Profile)
					

					

					 for(int ii = 0 ; ii <this->tmpDot->GetDotNumber() ; ii ++){
						 PointF coordinate ;
						 float Diameter ;
						 this->tmpDot->GetDotValue(coordinate,Diameter,ii);
						 float ratio = Convert::ToSingle(this->tmpDot->ModifyRate_LocalArea->GetValue(ii));
						 
						

						 if(Math::Abs(coordinate.X-targetValue) <= (selectRange*this->tmpLGP->Width/MeshNumber.X)){							 
							 count ++ ;
							 Array::Resize(dia,count);
							 Array::Resize(locationX,count);
							 Array::Resize(locationY,count);

							 dia->SetValue(Diameter*ratio,count-1);
							 locationX->SetValue(coordinate.X,count-1);
							 locationY->SetValue(coordinate.Y,count-1);

						 }
						 
					 }

				
					 
					 array<float>^ tmparray =gcnew array<float>(count);
					 locationY->CopyTo(tmparray,0);
					 Array::Sort(tmparray,dia);
					 locationY->CopyTo(tmparray,0);
					  Array::Sort(tmparray,locationX);


					 this->dataGridView_ActualDesign_Density->ColumnCount::set(3);
					 this->dataGridView_ActualDesign_Density->RowCount::set(count);






				 }



				 this->dataGridView_ActualDesign_Density->Columns->default[0]->Name = L"X座標 ";
				 this->dataGridView_ActualDesign_Density->Columns->default[1]->Name = L"Y座標 ";
				 this->dataGridView_ActualDesign_Density->Columns->default[2]->Name = L" 直徑 ";
				
			
				 for(int ii = 0 ; ii < count ; ii ++){
					 this->dataGridView_ActualDesign_Density->default[0,ii]->Value = locationX[ii];
					 this->dataGridView_ActualDesign_Density->default[1,ii]->Value = locationY[ii];
					 this->dataGridView_ActualDesign_Density->default[2,ii]->Value = dia[ii];
				}




			 };
			 
			 
		}
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void cboCrossSection_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->cboCrossSection->SelectedIndex == 0){
				 this->lblCoordinate->Text = "Y 座標位置 :";
			 }else{
				 this->lblCoordinate->Text = "X 座標位置 :";
			 }

		 }
};
}
