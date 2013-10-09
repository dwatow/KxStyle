#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "DataStructure.h"
using namespace Nurbs;
using namespace DensityClass;
using namespace DrawModule;
using namespace System::Drawing::Drawing2D;



namespace PatternContruction {

	/// <summary>
	/// HotSpot_Form 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class HotSpot_Form : public System::Windows::Forms::Form
	{
	public:
		HotSpot_Form(GridDensity^ surfacedensity,Pattern^ dot ,ArrayList^ HotSpotData ,RectangleF LGP)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			tmpdensity = surfacedensity;
			tmpDot = dot;
			MainFormHotSpotData = HotSpotData;
			tmpLGP = LGP;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~HotSpot_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView;
	protected: 

	protected: 







	private: System::Windows::Forms::ComboBox^  cboPitchDirection;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  lbl_Y;

	private: System::Windows::Forms::Label^  lbl_X;

	private: System::Windows::Forms::Label^  lbl_Angle;
	private: System::Windows::Forms::Label^  lbl_Coor;

	private: System::Windows::Forms::TextBox^  txtShortAxis;

	private: System::Windows::Forms::TextBox^  txtLongAxis;
	private: System::Windows::Forms::TextBox^  txtRotateAngle;
	private: System::Windows::Forms::TextBox^  txtNumber;
	private: System::Windows::Forms::TextBox^  txtPitch;




	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btn_Delete;
	private: System::Windows::Forms::Button^  btn_Accept;
	private: System::Windows::Forms::Button^  btn_Modify;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  txtCoord_Y;

	private: System::Windows::Forms::TextBox^  txtCoord_X;











	private:
		/// <summary>
		/// 設計工具所需的變數。
		GridDensity^ tmpdensity;
		Pattern^ tmpDot;
		Nurbs::B_Spline_Curve^ tmpCurve;
		ArrayList^ tmpHotSpotData;
		ArrayList^ MainFormHotSpotData;
		RectangleF tmpLGP ;
		array<PointF>^ OrigionalCpt ;
		int SelectedCptIndex ;




		 Matrix^ PicMatrix;





	private: System::Windows::Forms::TextBox^  txtGainValue;
	private: System::Windows::Forms::Label^  label8;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;





private: System::Windows::Forms::TextBox^  txtY1;



private: System::Windows::Forms::Label^  lblValue2;
private: System::Windows::Forms::TextBox^  txtY3;

private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  txtY2;

private: System::Windows::Forms::Label^  label5;

private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::NumericUpDown^  numSmoothDegree;


private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::NumericUpDown^  numX3;

private: System::Windows::Forms::NumericUpDown^  numX2;

private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::NumericUpDown^  numX1;

private: System::Windows::Forms::Label^  label11;




private: System::Windows::Forms::ComboBox^  cboShape;

private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::ComboBox^  cboSwapMode;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::PictureBox^  picLineCurve;
private: System::Windows::Forms::PictureBox^  pictureBoxShow;
private: System::Windows::Forms::GroupBox^  groupBox3;















			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cboPitchDirection = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxShow = (gcnew System::Windows::Forms::PictureBox());
			this->picLineCurve = (gcnew System::Windows::Forms::PictureBox());
			this->numSmoothDegree = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numX3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtGainValue = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->numX1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblValue2 = (gcnew System::Windows::Forms::Label());
			this->txtY1 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->numX2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtY2 = (gcnew System::Windows::Forms::TextBox());
			this->txtY3 = (gcnew System::Windows::Forms::TextBox());
			this->cboSwapMode = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_Accept = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->btn_Modify = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPitch = (gcnew System::Windows::Forms::TextBox());
			this->txtCoord_Y = (gcnew System::Windows::Forms::TextBox());
			this->txtCoord_X = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Coor = (gcnew System::Windows::Forms::Label());
			this->txtShortAxis = (gcnew System::Windows::Forms::TextBox());
			this->txtLongAxis = (gcnew System::Windows::Forms::TextBox());
			this->txtRotateAngle = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Y = (gcnew System::Windows::Forms::Label());
			this->lbl_X = (gcnew System::Windows::Forms::Label());
			this->lbl_Angle = (gcnew System::Windows::Forms::Label());
			this->txtNumber = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->cboShape = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxShow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLineCurve))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSmoothDegree))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowDrop = true;
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToOrderColumns = true;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column1, 
				this->dataGridViewTextBoxColumn1, this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4});
			this->dataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView->Location = System::Drawing::Point(6, 18);
			this->dataGridView->MultiSelect = false;
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersWidth = 15;
			this->dataGridView->RowTemplate->Height = 24;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(257, 315);
			this->dataGridView->TabIndex = 25;
			this->dataGridView->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &HotSpot_Form::dataGridView_CellMouseClick);
			// 
			// Column1
			// 
			this->Column1->FillWeight = 50;
			this->Column1->HeaderText = L"名稱";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column1->Width = 70;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->FillWeight = 80;
			this->dataGridViewTextBoxColumn1->HeaderText = L"座標(X)";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn1->Width = 45;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->FillWeight = 80;
			this->dataGridViewTextBoxColumn2->HeaderText = L"座標(Y)";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn2->Width = 45;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->FillWeight = 60;
			this->dataGridViewTextBoxColumn3->HeaderText = L"數目";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn3->Width = 40;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->FillWeight = 60;
			this->dataGridViewTextBoxColumn4->HeaderText = L"Pitch";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn4->Width = 40;
			// 
			// cboPitchDirection
			// 
			this->cboPitchDirection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPitchDirection->Enabled = false;
			this->cboPitchDirection->FormattingEnabled = true;
			this->cboPitchDirection->Location = System::Drawing::Point(101, 20);
			this->cboPitchDirection->Name = L"cboPitchDirection";
			this->cboPitchDirection->Size = System::Drawing::Size(58, 20);
			this->cboPitchDirection->TabIndex = 33;
			this->cboPitchDirection->SelectedIndexChanged += gcnew System::EventHandler(this, &HotSpot_Form::cboShape_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->cboSwapMode);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->btn_Accept);
			this->groupBox1->Controls->Add(this->btnExit);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->txtPitch);
			this->groupBox1->Controls->Add(this->txtCoord_Y);
			this->groupBox1->Controls->Add(this->cboPitchDirection);
			this->groupBox1->Controls->Add(this->txtCoord_X);
			this->groupBox1->Controls->Add(this->lbl_Coor);
			this->groupBox1->Controls->Add(this->txtShortAxis);
			this->groupBox1->Controls->Add(this->txtLongAxis);
			this->groupBox1->Controls->Add(this->txtRotateAngle);
			this->groupBox1->Controls->Add(this->lbl_Y);
			this->groupBox1->Controls->Add(this->lbl_X);
			this->groupBox1->Controls->Add(this->lbl_Angle);
			this->groupBox1->Location = System::Drawing::Point(16, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(611, 640);
			this->groupBox1->TabIndex = 34;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"輸入參數";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &HotSpot_Form::groupBox1_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pictureBoxShow);
			this->groupBox3->Controls->Add(this->picLineCurve);
			this->groupBox3->Controls->Add(this->numSmoothDegree);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->numX3);
			this->groupBox3->Controls->Add(this->txtGainValue);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->numX1);
			this->groupBox3->Controls->Add(this->lblValue2);
			this->groupBox3->Controls->Add(this->txtY1);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->numX2);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->txtY2);
			this->groupBox3->Controls->Add(this->txtY3);
			this->groupBox3->Location = System::Drawing::Point(6, 77);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(310, 557);
			this->groupBox3->TabIndex = 80;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"曲線型狀";
			// 
			// pictureBoxShow
			// 
			this->pictureBoxShow->BackColor = System::Drawing::Color::White;
			this->pictureBoxShow->Location = System::Drawing::Point(6, 18);
			this->pictureBoxShow->Name = L"pictureBoxShow";
			this->pictureBoxShow->Size = System::Drawing::Size(290, 201);
			this->pictureBoxShow->TabIndex = 79;
			this->pictureBoxShow->TabStop = false;
			this->pictureBoxShow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::pictureBoxShow_MouseMove);
			this->pictureBoxShow->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::pictureBoxShow_MouseClick);
			this->pictureBoxShow->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::pictureBoxShow_MouseDown);
			this->pictureBoxShow->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HotSpot_Form::pictureBoxShow_Paint);
			this->pictureBoxShow->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::pictureBoxShow_MouseUp);
			// 
			// picLineCurve
			// 
			this->picLineCurve->BackColor = System::Drawing::Color::White;
			this->picLineCurve->Location = System::Drawing::Point(6, 225);
			this->picLineCurve->Name = L"picLineCurve";
			this->picLineCurve->Size = System::Drawing::Size(290, 202);
			this->picLineCurve->TabIndex = 78;
			this->picLineCurve->TabStop = false;
			this->picLineCurve->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::picLineCurve_MouseMove);
			this->picLineCurve->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HotSpot_Form::picLineCurve_Paint);
			// 
			// numSmoothDegree
			// 
			this->numSmoothDegree->Location = System::Drawing::Point(206, 431);
			this->numSmoothDegree->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numSmoothDegree->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numSmoothDegree->Name = L"numSmoothDegree";
			this->numSmoothDegree->ReadOnly = true;
			this->numSmoothDegree->Size = System::Drawing::Size(46, 22);
			this->numSmoothDegree->TabIndex = 75;
			this->numSmoothDegree->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(9, 532);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(63, 12);
			this->label13->TabIndex = 74;
			this->label13->Text = L"座標3(X值)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(159, 434);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 12);
			this->label10->TabIndex = 67;
			this->label10->Text = L"平順度";
			// 
			// numX3
			// 
			this->numX3->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->numX3->Location = System::Drawing::Point(75, 526);
			this->numX3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numX3->Name = L"numX3";
			this->numX3->ReadOnly = true;
			this->numX3->Size = System::Drawing::Size(46, 22);
			this->numX3->TabIndex = 73;
			this->numX3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {75, 0, 0, 131072});
			this->numX3->ValueChanged += gcnew System::EventHandler(this, &HotSpot_Form::numX3_ValueChanged);
			this->numX3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::numX3_MouseDown);
			// 
			// txtGainValue
			// 
			this->txtGainValue->Location = System::Drawing::Point(101, 431);
			this->txtGainValue->Name = L"txtGainValue";
			this->txtGainValue->Size = System::Drawing::Size(46, 22);
			this->txtGainValue->TabIndex = 55;
			this->txtGainValue->TextChanged += gcnew System::EventHandler(this, &HotSpot_Form::txtGainValue_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 434);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(86, 12);
			this->label8->TabIndex = 54;
			this->label8->Text = L"軸心直徑參數 : ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 477);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 12);
			this->label11->TabIndex = 69;
			this->label11->Text = L"座標1(X值)";
			// 
			// numX1
			// 
			this->numX1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->numX1->Location = System::Drawing::Point(75, 470);
			this->numX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numX1->Name = L"numX1";
			this->numX1->ReadOnly = true;
			this->numX1->Size = System::Drawing::Size(46, 22);
			this->numX1->TabIndex = 70;
			this->numX1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {25, 0, 0, 131072});
			this->numX1->ValueChanged += gcnew System::EventHandler(this, &HotSpot_Form::numX1_ValueChanged);
			this->numX1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::numX1_MouseDown);
			// 
			// lblValue2
			// 
			this->lblValue2->AutoSize = true;
			this->lblValue2->Location = System::Drawing::Point(127, 473);
			this->lblValue2->Name = L"lblValue2";
			this->lblValue2->Size = System::Drawing::Size(63, 12);
			this->lblValue2->TabIndex = 62;
			this->lblValue2->Text = L"座標1(Y值)";
			// 
			// txtY1
			// 
			this->txtY1->Location = System::Drawing::Point(190, 469);
			this->txtY1->Name = L"txtY1";
			this->txtY1->Size = System::Drawing::Size(46, 22);
			this->txtY1->TabIndex = 61;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(9, 501);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(63, 12);
			this->label12->TabIndex = 71;
			this->label12->Text = L"座標2(X值)";
			// 
			// numX2
			// 
			this->numX2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->numX2->Location = System::Drawing::Point(75, 498);
			this->numX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numX2->Name = L"numX2";
			this->numX2->ReadOnly = true;
			this->numX2->Size = System::Drawing::Size(46, 22);
			this->numX2->TabIndex = 72;
			this->numX2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->numX2->ValueChanged += gcnew System::EventHandler(this, &HotSpot_Form::numX2_ValueChanged);
			this->numX2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &HotSpot_Form::numX2_MouseDown);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(127, 529);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 12);
			this->label6->TabIndex = 65;
			this->label6->Text = L"座標3(Y值)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(126, 501);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 12);
			this->label5->TabIndex = 63;
			this->label5->Text = L"座標2(Y值)";
			// 
			// txtY2
			// 
			this->txtY2->Location = System::Drawing::Point(190, 497);
			this->txtY2->Name = L"txtY2";
			this->txtY2->Size = System::Drawing::Size(46, 22);
			this->txtY2->TabIndex = 64;
			// 
			// txtY3
			// 
			this->txtY3->Location = System::Drawing::Point(190, 526);
			this->txtY3->Name = L"txtY3";
			this->txtY3->Size = System::Drawing::Size(46, 22);
			this->txtY3->TabIndex = 66;
			// 
			// cboSwapMode
			// 
			this->cboSwapMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSwapMode->FormattingEnabled = true;
			this->cboSwapMode->Location = System::Drawing::Point(518, 46);
			this->cboSwapMode->Name = L"cboSwapMode";
			this->cboSwapMode->Size = System::Drawing::Size(73, 20);
			this->cboSwapMode->TabIndex = 77;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(449, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 12);
			this->label2->TabIndex = 76;
			this->label2->Text = L"Swap 模式 :";
			// 
			// btn_Accept
			// 
			this->btn_Accept->Location = System::Drawing::Point(409, 490);
			this->btn_Accept->Name = L"btn_Accept";
			this->btn_Accept->Size = System::Drawing::Size(72, 33);
			this->btn_Accept->TabIndex = 41;
			this->btn_Accept->Text = L"套用";
			this->btn_Accept->UseVisualStyleBackColor = true;
			this->btn_Accept->Click += gcnew System::EventHandler(this, &HotSpot_Form::btn_Accept_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(487, 490);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(72, 33);
			this->btnExit->TabIndex = 39;
			this->btnExit->Text = L"離開";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &HotSpot_Form::btnExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 12);
			this->label1->TabIndex = 56;
			this->label1->Text = L"Pitch方向";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView);
			this->groupBox2->Controls->Add(this->btn_Delete);
			this->groupBox2->Controls->Add(this->btn_Modify);
			this->groupBox2->Controls->Add(this->btnAdd);
			this->groupBox2->Location = System::Drawing::Point(328, 77);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(268, 397);
			this->groupBox2->TabIndex = 44;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"內容";
			// 
			// btn_Delete
			// 
			this->btn_Delete->Location = System::Drawing::Point(159, 347);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(72, 33);
			this->btn_Delete->TabIndex = 43;
			this->btn_Delete->Text = L"刪除";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &HotSpot_Form::btn_Delete_Click);
			// 
			// btn_Modify
			// 
			this->btn_Modify->Location = System::Drawing::Point(81, 347);
			this->btn_Modify->Name = L"btn_Modify";
			this->btn_Modify->Size = System::Drawing::Size(72, 33);
			this->btn_Modify->TabIndex = 42;
			this->btn_Modify->Text = L"修改";
			this->btn_Modify->UseVisualStyleBackColor = true;
			this->btn_Modify->Click += gcnew System::EventHandler(this, &HotSpot_Form::btn_Modify_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(6, 347);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(72, 33);
			this->btnAdd->TabIndex = 40;
			this->btnAdd->Text = L"增加";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &HotSpot_Form::btnAdd_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(165, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 12);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Pitch值";
			// 
			// txtPitch
			// 
			this->txtPitch->Enabled = false;
			this->txtPitch->Location = System::Drawing::Point(240, 18);
			this->txtPitch->Name = L"txtPitch";
			this->txtPitch->Size = System::Drawing::Size(58, 22);
			this->txtPitch->TabIndex = 36;
			// 
			// txtCoord_Y
			// 
			this->txtCoord_Y->Location = System::Drawing::Point(518, 18);
			this->txtCoord_Y->Name = L"txtCoord_Y";
			this->txtCoord_Y->Size = System::Drawing::Size(58, 22);
			this->txtCoord_Y->TabIndex = 47;
			// 
			// txtCoord_X
			// 
			this->txtCoord_X->Location = System::Drawing::Point(442, 18);
			this->txtCoord_X->Name = L"txtCoord_X";
			this->txtCoord_X->Size = System::Drawing::Size(58, 22);
			this->txtCoord_X->TabIndex = 46;
			// 
			// lbl_Coor
			// 
			this->lbl_Coor->AutoSize = true;
			this->lbl_Coor->Location = System::Drawing::Point(326, 23);
			this->lbl_Coor->Name = L"lbl_Coor";
			this->lbl_Coor->Size = System::Drawing::Size(110, 12);
			this->lbl_Coor->TabIndex = 6;
			this->lbl_Coor->Text = L"軸心座標位置(X,Y) :";
			// 
			// txtShortAxis
			// 
			this->txtShortAxis->Location = System::Drawing::Point(240, 49);
			this->txtShortAxis->Name = L"txtShortAxis";
			this->txtShortAxis->Size = System::Drawing::Size(58, 22);
			this->txtShortAxis->TabIndex = 5;
			// 
			// txtLongAxis
			// 
			this->txtLongAxis->Location = System::Drawing::Point(101, 49);
			this->txtLongAxis->Name = L"txtLongAxis";
			this->txtLongAxis->Size = System::Drawing::Size(58, 22);
			this->txtLongAxis->TabIndex = 4;
			// 
			// txtRotateAngle
			// 
			this->txtRotateAngle->Location = System::Drawing::Point(385, 47);
			this->txtRotateAngle->Name = L"txtRotateAngle";
			this->txtRotateAngle->Size = System::Drawing::Size(58, 22);
			this->txtRotateAngle->TabIndex = 3;
			// 
			// lbl_Y
			// 
			this->lbl_Y->AutoSize = true;
			this->lbl_Y->Location = System::Drawing::Point(165, 52);
			this->lbl_Y->Name = L"lbl_Y";
			this->lbl_Y->Size = System::Drawing::Size(69, 12);
			this->lbl_Y->TabIndex = 2;
			this->lbl_Y->Text = L"短軸(Y方向)";
			// 
			// lbl_X
			// 
			this->lbl_X->AutoSize = true;
			this->lbl_X->Location = System::Drawing::Point(15, 52);
			this->lbl_X->Name = L"lbl_X";
			this->lbl_X->Size = System::Drawing::Size(69, 12);
			this->lbl_X->TabIndex = 1;
			this->lbl_X->Text = L"長軸(X方向)";
			// 
			// lbl_Angle
			// 
			this->lbl_Angle->AutoSize = true;
			this->lbl_Angle->Location = System::Drawing::Point(326, 52);
			this->lbl_Angle->Name = L"lbl_Angle";
			this->lbl_Angle->Size = System::Drawing::Size(53, 12);
			this->lbl_Angle->TabIndex = 0;
			this->lbl_Angle->Text = L"旋轉角度";
			// 
			// txtNumber
			// 
			this->txtNumber->Location = System::Drawing::Point(306, 6);
			this->txtNumber->Name = L"txtNumber";
			this->txtNumber->Size = System::Drawing::Size(40, 22);
			this->txtNumber->TabIndex = 35;
			this->txtNumber->Text = L"1";
			this->txtNumber->TextChanged += gcnew System::EventHandler(this, &HotSpot_Form::txtNumber_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(267, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 12);
			this->label3->TabIndex = 37;
			this->label3->Text = L"數目";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(20, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 12);
			this->label9->TabIndex = 56;
			this->label9->Text = L"名稱";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(67, 6);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(90, 22);
			this->txtName->TabIndex = 57;
			// 
			// cboShape
			// 
			this->cboShape->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboShape->FormattingEnabled = true;
			this->cboShape->Location = System::Drawing::Point(194, 6);
			this->cboShape->Name = L"cboShape";
			this->cboShape->Size = System::Drawing::Size(56, 20);
			this->cboShape->TabIndex = 58;
			this->cboShape->SelectedIndexChanged += gcnew System::EventHandler(this, &HotSpot_Form::cboShape_SelectedIndexChanged_1);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(163, 9);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(29, 12);
			this->label16->TabIndex = 59;
			this->label16->Text = L"形狀";
			// 
			// HotSpot_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 681);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->cboShape);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtNumber);
			this->Controls->Add(this->groupBox1);
			this->Name = L"HotSpot_Form";
			this->Text = L"HotSpot_Form";
			this->Load += gcnew System::EventHandler(this, &HotSpot_Form::HotSpot_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxShow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picLineCurve))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSmoothDegree))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numX2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void HotSpot_Form_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 this->cboPitchDirection->Items->Add("X方向 ");
				 this->cboPitchDirection->Items->Add("Y方向");


				 this->cboShape->Items->Add("橢圓形");
				 this->cboShape->Items->Add("菱形");
				 this->cboShape->SelectedIndex = 0;

				 this->cboSwapMode->Items->Add("橢圓(舊)");
				 this->cboSwapMode->Items->Add("同心橢圓");
				 this->cboSwapMode->SelectedIndex = 1;



				  //Curve
				 this->tmpCurve = gcnew B_Spline_Curve();

				 //HotSpot 初始數值 
				 this->numSmoothDegree->Value::set(4);
				 this->numX1->DecimalPlaces::set(2);
				 this->numX2->DecimalPlaces::set(2);
				 this->numX3->DecimalPlaces::set(2);
				 this->txtY1->Text = "1";
				 this->txtY2->Text = "1.5";
				 this->txtY3->Text = "2";
				 this->txtGainValue->Text = "2";


				 this->OrigionalCpt = gcnew array<PointF>(5);
				 this->SelectedCptIndex = -1;


				 //將座標轉換為中心點 為座標原點 ,並且為更改定義為往右和往上為正 ,並Scale ,使座標點為(1,1)的時候,是在圖形的右上角~
				 PicMatrix = gcnew Matrix(pictureBoxShow->Width/2.0f,0.0f,0.0f,-pictureBoxShow->Height/2.0f,pictureBoxShow->Width/2.0f,pictureBoxShow->Height/2.0f); 





				 this->tmpHotSpotData = gcnew ArrayList;

				 if(this->MainFormHotSpotData->Count > 0){
					 this->tmpHotSpotData->InsertRange(0,this->MainFormHotSpotData);
					  this->dataGridView->RowCount::set(this->tmpHotSpotData->Count);

					 for(int ii = 0 ; ii <this->tmpHotSpotData->Count ;ii++){
						//array<String^>^ inputData =(array<String^>^) this->tmpHotSpotData->default[ii];
						//this->dataGridView->default[0,ii]->Value = Convert::ToString(inputData[0]);
						//this->dataGridView->default[1,ii]->Value = Convert::ToString(inputData[4]);
						//this->dataGridView->default[2,ii]->Value = Convert::ToString(inputData[5]);
						//this->dataGridView->default[3,ii]->Value = Convert::ToString(inputData[1]);
						//this->dataGridView->default[4,ii]->Value = Convert::ToString(inputData[3]);

						HotSpot_Part^ inputData =  (HotSpot_Part^)this->tmpHotSpotData->default[ii];
						this->dataGridView->default[0,ii]->Value = inputData->Name;
						this->dataGridView->default[1,ii]->Value = Convert::ToString(inputData->CenterCoordinate.X);
						this->dataGridView->default[2,ii]->Value = Convert::ToString(inputData->CenterCoordinate.Y);
						this->dataGridView->default[3,ii]->Value = Convert::ToString(inputData->Number);
						this->dataGridView->default[4,ii]->Value = Convert::ToString(inputData->pitch);

					 }
				 }

					
			
				

				
			    

				 
			 }
private: System::Void cboShape_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnCal_Click(System::Object^  sender, System::EventArgs^  e) {


		/*	 
			 try{


				 // -------------產生Curve

				 array<PointF>^ cPt = gcnew array<PointF>(5);

				 float gainVaule = Convert::ToSingle(this->txtGainValue->Text);

				cPt[0].Y = 1; //邊緣Gain 值永遠是1 
				cPt[0].X = 0;
				cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
				cPt[4].X = 1;

				cPt[1].Y =  Convert::ToSingle(this->txtY1->Text);
				cPt[1].X =  Convert::ToSingle(this->numX1->Value);
				cPt[2].Y =  Convert::ToSingle(this->txtY2->Text);
				cPt[2].X =  Convert::ToSingle(this->numX2->Value);
				cPt[3].Y =  Convert::ToSingle(this->txtY3->Text);
				cPt[3].X =  Convert::ToSingle(this->numX3->Value);


			

				this->tmpCurve->ControllPt->Clear();

				for(int ii = 0 ; ii < 5 ; ii ++){
					this->tmpCurve->ControllPt->Add(cPt[ii]);
				 }

				 this->tmpCurve->Set_k_Value(Convert::ToInt16(this->numSmoothDegree->Value));
				 this->tmpCurve->ReProduceCurve(51);


				 //--------------------------

				 float RotateAngle = Convert::ToSingle(this->txtRotateAngle->Text);
				 float LongAxis = Convert::ToSingle(this->txtLongAxis->Text)/2.0f;
				 float ShortAxis = Convert::ToSingle(this->txtShortAxis->Text)/2.0f;
				 PointF Coordinate(Convert::ToSingle(this->txtCoord_X->Text),Convert::ToSingle(this->txtCoord_Y->Text));





				 float max = Math::Max(2*LongAxis,2*ShortAxis);

				 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

				 float thda;
				 PointF pt ;
				 PointF tmp_pt;
				 float ratio = 1 ;
				
				 RectangleF MeshValue;

				 
				 //橢圓焦點
				 array<PointF>^ focusPt = gcnew array<PointF>(2) ;
			

				 float C ;
				 if( LongAxis > ShortAxis){
					C= (float)Math::Sqrt(LongAxis*LongAxis-ShortAxis*ShortAxis);
					 focusPt[0].X = Coordinate.X+C;
					 focusPt[1].X = Coordinate.X-C;
					 focusPt[0].Y = Coordinate.Y;
					 focusPt[1].Y = Coordinate.Y;
				 }else{
					C= (float)Math::Sqrt(-LongAxis*LongAxis+ShortAxis*ShortAxis);
					focusPt[0].X = Coordinate.X;
					focusPt[1].X = Coordinate.X;
					focusPt[0].Y = Coordinate.Y+C;
					focusPt[1].Y = Coordinate.Y-C;
				 }


				
				//圖形的90%作為限制
				float X_Ratio = (float)Math::Min(0.4f*this->picDraw->Width/LongAxis,0.4f*this->picDraw->Width/ShortAxis) ;
				float Y_Ratio = (float)Math::Min(0.4f*this->picDraw->Height/ShortAxis,0.4f*this->picDraw->Height/LongAxis);
			
				RectangleF meshSize = this->tmpdensity->GetMeshValue(Point(0,0));
				
				DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();

				Graphics^ tmp = this->picDraw->CreateGraphics();		
				tmp->Clear(Color::Black);							
				tmp->ResetTransform();

							
				//反轉Y座標
				 Matrix^ tmpMatrix = gcnew Matrix(Math::Min(X_Ratio,Y_Ratio),0.0f,0.0f,-Math::Min(X_Ratio,Y_Ratio),this->picDraw->Width/2.0f,this->picDraw->Height/2.0f);
				 tmp->Transform::set(tmpMatrix);
				
				float value;
				
				Pen^ skyBluePen = gcnew Pen(Brushes::DeepSkyBlue ) ;
				float minRange = Math::Min(Convert::ToSingle(this->txtRangeMin->Text),Convert::ToSingle(this->txtRangeMax->Text));
				float maxRange = Math::Max(Convert::ToSingle(this->txtRangeMin->Text),Convert::ToSingle(this->txtRangeMax->Text));

				


				
				for(int ii = 0 ; ii <this->tmpdensity->GetMeshNumber().X ; ii ++){
					 for(int jj = 0 ; jj < this->tmpdensity->GetMeshNumber().Y ; jj++){
						 MeshValue = this->tmpdensity->GetMeshValue(Point(ii,jj));
						 pt.X = MeshValue.X+MeshValue.Width/2;
						 pt.Y = MeshValue.Y+MeshValue.Height/2;
						 
						 //座標旋轉
						 tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
						 tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);

						 
						
						 

						 if(Block.Contains(tmp_pt) == true){
							//進行橢圓形判斷
							// value =  Math::Sqrt(Math::Pow(pt.X-tmp_focusPt[0].X,2) + Math::Pow(pt.Y-tmp_focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(pt.X-tmp_focusPt[1].X,2) + Math::Pow(pt.Y-tmp_focusPt[1].Y,2));
							 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
						 
							//表示在橢圓內
							 if (value < 2*Math::Max(LongAxis,ShortAxis)){
								thda = Math::Atan2(tmp_pt.Y - Coordinate.Y,tmp_pt.X-  Coordinate.X);
								float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
								float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));
								float tmpZ = this->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);

								skyBluePen = Draw1->ProduceColorPen((tmpZ-minRange)/(maxRange-minRange),PointF(0,1));											    							
								tmp->DrawRectangle(skyBluePen,pt.X-Coordinate.X-meshSize.Width/2,(pt.Y-Coordinate.Y-meshSize.Height/2),meshSize.Width,meshSize.Height);
								
														
							}

						 }
					 }
				 }


				

				skyBluePen->Color::set(Color::Green);
				tmp->DrawRectangle(skyBluePen,this->tmpLGP.X-Coordinate.X,this->tmpLGP.Y-Coordinate.Y,this->tmpLGP.Width,this->tmpLGP.Height);
				//tmp->DrawEllipse(skyBluePen,Block);
				

				
			
			
				delete tmp;

			}catch(...){
				MessageBox::Show("資料錯誤 !");
			}

		


			

		
*/
			 





		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	
			 

		 }
private: System::Void btnShowCurve_Click(System::Object^  sender, System::EventArgs^  e) {
		

//*
			 array<PointF>^ cPt = gcnew array<PointF>(5);

			 float gainVaule = Convert::ToSingle(this->txtGainValue->Text);

			cPt[0].Y = 1; //邊緣Gain 值永遠是1 
			cPt[0].X = 0;
			cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
			cPt[4].X = 1;

			cPt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			cPt[1].X =  Convert::ToSingle(this->numX1->Value);
			cPt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			cPt[2].X =  Convert::ToSingle(this->numX2->Value);
			cPt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			cPt[3].X =  Convert::ToSingle(this->numX3->Value);


		

			this->tmpCurve->ControllPt->Clear();

			for(int ii = 0 ; ii < 5 ; ii ++){
				this->tmpCurve->ControllPt->Add(cPt[ii]);
			 }

			 this->tmpCurve->Set_k_Value(Convert::ToInt16(this->numSmoothDegree->Value));
			 this->tmpCurve->ReProduceCurve(101);


	
		
			array<PointF,1>^ tmpCurve = this->tmpCurve->GetCurve();
			float max = -10000;
			float min = 10000;
			for(int ii = 0 ; ii <tmpCurve->Length ; ii++){
				if(tmpCurve[ii].Y > max ) max = tmpCurve[ii].Y;
				if(tmpCurve[ii].Y < min ) min = tmpCurve[ii].Y;
			}


			 //繪圖
			 
			 //RectangleF^ range;

			 Graphics^ tmp = this->picLineCurve->CreateGraphics();
			
			 Point Size(this->picLineCurve->Width,this->picLineCurve->Height);
			 Pen^ tmpPen = gcnew Pen(Brushes::Blue);

			

			
			 tmp->Clear(Color::Black);

			 tmpPen->Width::set(0.02);			

			// RectangleF Range = this->tmpCurve->Curve_Boundary::get();
			 
			 

			 //反轉Y座標
			// Matrix^ tmpMatrix;

			

		
			 Matrix^ tmpMatrix = gcnew Matrix(1,0,0,-1,0,Size.Y);
			 Matrix^ tmpMatrix2 = gcnew Matrix(1,0,0,1,0,0);
			 Matrix^ tmpMatrix3 = gcnew Matrix(0.9f*Size.X,0.0f,0.0f,0.9f*Size.Y/(max-min),0.0f,0.0f);
			 Matrix^ tmpMatrix4 = gcnew Matrix(1,0,0,1,0.05,0.05*(max-min));
			
		
			 tmpMatrix3->Multiply(tmpMatrix4);
			 tmpMatrix2->Multiply(tmpMatrix3);
			 tmpMatrix->Multiply(tmpMatrix2);




			 //Scale 並反轉Y座標
			 tmp->Transform::set(tmpMatrix);
			 tmp->TranslateTransform(0,-min,MatrixOrder::Prepend); 
			
			 
			 


			
						
		
		
						
			 tmp->DrawLines(tmpPen,this->tmpCurve->GetCurve());  //畫Cruve
			 tmpPen->Brush::set(Brushes::Red);
			 
		//*	 
			 for(int ii = 0 ; ii<this->tmpCurve->ControllPt->Count ; ii ++){
			//	 RectangleF tmpRec(this->tmpCurve->ControllPt->default[ii].X-0.02 ,this->tmpCurve->ControllPt->default[ii].Y-0.02 ,0.04 ,0.04);
			//	 tmp->FillEllipse(tmpPen,tmpRec);

			 }
		 //*/

			/*
			 for(int jj = 0 ; jj<this->tmpCurve->GetCurve()->Length ; jj ++){
				 float R;
				 float G;
				 float B;
				 
				 float density;
				 density = this->tmpCurve->GetCurve_Z_Value((float)jj/(this->tmpCurve->GetCurve()->Length-1));
				 SetDensityColor(density,R,G,B);

				 tmp->DrawEllipse(tmpPen->Brush::set(Color::FromArgb(R,G,B)),RectangleF());

			 }
			 */

			 Graphics^ tmpShow = this->pictureBoxShow->CreateGraphics();
			 tmpShow->Clear(Color::Black);
			
			 
		
			

		
			// 座標轉換
			tmpShow->Transform::set(PicMatrix);
			
			

			 


//*			
			 for(int jj = this->tmpCurve->GetCurve()->Length-1 ; jj>=0 ; jj --){
				   	float R;
					float G;
					float B;
				 
				 float density;
				 float ratio = (float)jj/(this->tmpCurve->GetCurve()->Length-1);
				 density = this->tmpCurve->GetCurve_Z_Value(1.0f-ratio,0);
				 
				
				 // 定義Gain =0 時den = 0  ,Gain =5 時 den = 1 
				 density = (density-1.0f)/5.0f + 1.0f/5.0f ;

				 SetDensityColor(density,R,G,B);
				 tmpPen->Color::set(Color::FromArgb(R,G,B));
				 //tmpPen->Color::set(Color::Red);
				 
				 tmpShow->FillEllipse(tmpPen->Brush,RectangleF(-ratio,-ratio,2*ratio,2*ratio));

				 
				 
			   }


			//畫控制點座標 :
			 for(int jj = 0  ; jj <this->tmpCurve->ControllPt->Count  ; jj ++){

				 tmpPen->Color::set(Color::YellowGreen);				 
				 tmpShow->FillEllipse(tmpPen->Brush,RectangleF(this->tmpCurve->ControllPt->default[jj].X-0.05 ,-0.05 ,0.1,0.1));

			 }


//*/
			


		//	 tmp->DrawLine(tmpPen,0,1,1,1);  //Gain為1的線
		//	 tmpPen->Brush::set(Brushes::Yellow);
		//	 tmp->DrawLine(tmpPen,0.0f,gainVaule,1.0f,gainVaule);  //Gain設定值的線
			 
			 


		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numX2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 try{
			//	this->numX2->Maximum::set(this->numX3->Value);
			//	this->numX2->Minimum::set(this->numX1->Value);
			 }catch(...){
				 //點History 時 ,會有順序上的問題 ,所以要按順序跑 (1->2->3)
			//	this->numX2->Minimum::set(this->numX1->Value); 
			//	this->numX1->Maximum::set(this->numX2->Value);
			//	this->numX3->Minimum::set(this->numX2->Value);
			//	this->numX2->Maximum::set(this->numX3->Value);
			 }

		 }
private: System::Void numX1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

			 try{
			//	this->numX1->Maximum::set(this->numX2->Value);
			 }catch(...){
				//點History 時 ,會有順序上的問題 ,所以要按順序跑 (1->2->3)
			//	this->numX2->Minimum::set(this->numX1->Value); 
			//	this->numX1->Maximum::set(this->numX2->Value);
			//	this->numX3->Minimum::set(this->numX2->Value);
			//	this->numX2->Maximum::set(this->numX3->Value);
			 }

		 }
private: System::Void numX3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 try{
		//		this->numX3->Minimum::set(this->numX2->Value);
			 }catch(...){
				//點History 時 ,會有順序上的問題 ,所以要按順序跑 (1->2->3)
			//	this->numX2->Minimum::set(this->numX1->Value); 
			//	this->numX1->Maximum::set(this->numX2->Value);
			//	this->numX3->Minimum::set(this->numX2->Value);
			//	this->numX2->Maximum::set(this->numX3->Value);
			 }
		 }
private: System::Void btn_Accept_Click(System::Object^  sender, System::EventArgs^  e) {



			this->MainFormHotSpotData->RemoveRange(0,this->MainFormHotSpotData->Count);
			this->MainFormHotSpotData->InsertRange(0,this->tmpHotSpotData);

	


		 }
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {

			//  array<String^>^ inputData = gcnew array<String^>(17);
			  HotSpot_Part^ tmpPart = gcnew HotSpot_Part();

			 try{
				
				 tmpPart->Name = this->txtName->Text;
				 tmpPart->Number = Convert::ToInt32(this->txtNumber->Text);
				 
				 tmpPart->Shape = this->cboShape->Text;
				 tmpPart->ShapeIndex = this->cboShape->SelectedIndex;

				 tmpPart->PitchDirection = this->cboPitchDirection->Text;
				 tmpPart->PitchDirectionIndex = this->cboPitchDirection->SelectedIndex;


				 if(tmpPart->Number > 1)
					tmpPart->pitch = Convert::ToSingle(this->txtPitch->Text);
				 else 
					 tmpPart->pitch = 0;
				 tmpPart->CenterCoordinate = PointF(Convert::ToSingle(this->txtCoord_X->Text) , Convert::ToSingle(this->txtCoord_Y->Text));
				 tmpPart->Length_X = Convert::ToSingle(this->txtLongAxis->Text);
				 tmpPart->Length_Y = Convert::ToSingle(this->txtShortAxis->Text);
				 tmpPart->rotateAngle = Convert::ToSingle(this->txtRotateAngle->Text);
				 tmpPart->CenterGainValue = Convert::ToSingle(this->txtGainValue->Text);
				 tmpPart->SmoothingDegree = Convert::ToInt16(this->numSmoothDegree->Value);
				 tmpPart->ConrollPt[0].X = Convert::ToSingle(this->numX1->Value);
				 tmpPart->ConrollPt[0].Y = Convert::ToSingle(this->txtY1->Text);
				 tmpPart->ConrollPt[1].X = Convert::ToSingle(this->numX2->Value);
				 tmpPart->ConrollPt[1].Y = Convert::ToSingle(this->txtY2->Text);
				 tmpPart->ConrollPt[2].X = Convert::ToSingle(this->numX3->Value);
				 tmpPart->ConrollPt[2].Y = Convert::ToSingle(this->txtY3->Text);



				 //20120920增加
				 tmpPart->SwapModeIndex = this->cboSwapMode->SelectedIndex;





				 //inputData[0] = 
				 //inputData[1] = 
				 //inputData[2] = Convert::ToString(this->cboPitchDirection->SelectedIndex );
				 //inputData[3] = ;
				 //inputData[4] = ;
				 //inputData[5] = ;
				 //inputData[6] = ;
				 //inputData[7] = ;
				// inputData[8] = this->txtRotateAngle->Text;
				// inputData[9] = this->txtGainValue->Text;
				// inputData[10] = Convert::ToString();
				// inputData[11] = Convert::ToString(this->numX1->Value);
				// inputData[12] = this->txtY1->Text;
				// inputData[13] = Convert::ToString(this->numX2->Value);
				// inputData[14] = this->txtY2->Text;
				// inputData[15] = Convert::ToString(this->numX3->Value);
				// inputData[16] = this->txtY3->Text;

			 }catch(...){
				 MessageBox::Show("資料輸入錯誤");
				 return;
			 }

		

			 this->tmpHotSpotData->Add(tmpPart);

			 int length =  this->tmpHotSpotData->Count;
			 
			 this->dataGridView->RowCount::set(length);

			// this->dataGridView->default[0,length-1]->Value = Convert::ToString(inputData[0]);
			// this->dataGridView->default[1,length-1]->Value = Convert::ToString(inputData[4]);
			// this->dataGridView->default[2,length-1]->Value = Convert::ToString(inputData[5]);
			// this->dataGridView->default[3,length-1]->Value = Convert::ToString(inputData[1]);
			// this->dataGridView->default[4,length-1]->Value = Convert::ToString(inputData[3]);


			 this->dataGridView->default[0,length-1]->Value = tmpPart->Name;
			 this->dataGridView->default[1,length-1]->Value = Convert::ToString(tmpPart->CenterCoordinate.X);
			 this->dataGridView->default[2,length-1]->Value = Convert::ToString(tmpPart->CenterCoordinate.Y);
			 this->dataGridView->default[3,length-1]->Value = Convert::ToString(tmpPart->Number);
			 this->dataGridView->default[4,length-1]->Value = Convert::ToString(tmpPart->pitch);

			 
			 




			 


		 }
private: System::Void btn_Delete_Click(System::Object^  sender, System::EventArgs^  e) {


			 if(this->dataGridView->RowCount > 0){

				DataGridViewRow^ rows =this->dataGridView->CurrentRow;
				int tmpindex = rows->Index;			
				this->tmpHotSpotData->RemoveAt(tmpindex);					
				//移除歷史記錄中的資料
				 DataGridViewRowCollection^ rows2 = this->dataGridView->Rows;			 
				 rows2->RemoveAt(tmpindex);

			 }
				
				



		 }
private: System::Void btn_Modify_Click(System::Object^  sender, System::EventArgs^  e) {

			 	DataGridViewRow^ rows =this->dataGridView->CurrentRow;
			
				int tmpindex = rows->Index;
				//array<String^>^ inputData =(array<String^>^) this->tmpHotSpotData->default[tmpindex];
				HotSpot_Part^ tmpPart = (HotSpot_Part^)this->tmpHotSpotData->default[tmpindex];

				try{



					 tmpPart->Name = this->txtName->Text;
					 tmpPart->Number = Convert::ToInt32(this->txtNumber->Text);

					 tmpPart->Shape = this->cboShape->Text;
					 tmpPart->ShapeIndex = this->cboShape->SelectedIndex;

					 tmpPart->PitchDirection = this->cboPitchDirection->Text;
					 tmpPart->PitchDirectionIndex = this->cboPitchDirection->SelectedIndex;

					 //tmpPart->pitch = Convert::ToSingle(this->txtPitch->Text);

					 if(tmpPart->Number > 1)
						tmpPart->pitch = Convert::ToSingle(this->txtPitch->Text);
					 else 
						tmpPart->pitch = 0;



					 tmpPart->CenterCoordinate = PointF(Convert::ToSingle(this->txtCoord_X->Text) , Convert::ToSingle(this->txtCoord_Y->Text));
					 tmpPart->Length_X = Convert::ToSingle(this->txtLongAxis->Text);
					 tmpPart->Length_Y = Convert::ToSingle(this->txtShortAxis->Text);
					 tmpPart->rotateAngle = Convert::ToSingle(this->txtRotateAngle->Text);
					 tmpPart->CenterGainValue = Convert::ToSingle(this->txtGainValue->Text);
					 tmpPart->SmoothingDegree = Convert::ToInt16(this->numSmoothDegree->Value);
					 tmpPart->ConrollPt[0].X = Convert::ToSingle(this->numX1->Value);
					 tmpPart->ConrollPt[0].Y = Convert::ToSingle(this->txtY1->Text);
					 tmpPart->ConrollPt[1].X = Convert::ToSingle(this->numX2->Value);
					 tmpPart->ConrollPt[1].Y = Convert::ToSingle(this->txtY2->Text);
					 tmpPart->ConrollPt[2].X = Convert::ToSingle(this->numX3->Value);
					 tmpPart->ConrollPt[2].Y = Convert::ToSingle(this->txtY3->Text);


					  //20120920增加
					 tmpPart->SwapModeIndex = this->cboSwapMode->SelectedIndex;


				/*
					 inputData[0] = this->txtName->Text;
					 inputData[1] = this->txtNumber->Text;
					 inputData[2] = Convert::ToString(this->cboPitchDirection->SelectedIndex );
					 inputData[3] = this->txtPitch->Text;
					 inputData[4] = this->txtCoord_X->Text;
					 inputData[5] = this->txtCoord_Y->Text;
					 inputData[6] = this->txtLongAxis->Text;
					 inputData[7] = this->txtShortAxis->Text;
					 inputData[8] = this->txtRotateAngle->Text;
					 inputData[9] = this->txtGainValue->Text;
					 inputData[10] = Convert::ToString(this->numSmoothDegree->Value);
					 inputData[11] = Convert::ToString(this->numX1->Value);
					 inputData[12] = this->txtY1->Text;
					 inputData[13] = Convert::ToString(this->numX2->Value);
					 inputData[14] = this->txtY2->Text;
					 inputData[15] = Convert::ToString(this->numX3->Value);
					 inputData[16] = this->txtY3->Text;
				 */

				 }catch(...){
					 MessageBox::Show("資料輸入錯誤");
					 return;
				 }


			//	 this->dataGridView->default[0,tmpindex]->Value = Convert::ToString(inputData[0]);
			//	 this->dataGridView->default[1,tmpindex]->Value = Convert::ToString(inputData[4]);
			//	 this->dataGridView->default[2,tmpindex]->Value = Convert::ToString(inputData[5]);
			//	 this->dataGridView->default[3,tmpindex]->Value = Convert::ToString(inputData[1]);
			//	 this->dataGridView->default[4,tmpindex]->Value = Convert::ToString(inputData[3]);



          
				this->dataGridView->default[0,tmpindex]->Value = tmpPart->Name;
				this->dataGridView->default[1,tmpindex]->Value = Convert::ToString(tmpPart->CenterCoordinate.X);
				this->dataGridView->default[2,tmpindex]->Value = Convert::ToString(tmpPart->CenterCoordinate.Y);
				this->dataGridView->default[3,tmpindex]->Value = Convert::ToString(tmpPart->Number);
				this->dataGridView->default[4,tmpindex]->Value = Convert::ToString(tmpPart->pitch);
		




		 }
private: System::Void dataGridView_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {


			 	DataGridViewRow^ rows =this->dataGridView->CurrentRow;
				int tmpindex = rows->Index;
				//array<String^>^ inputData = (array<String^>^)this->tmpHotSpotData->default[tmpindex];
				HotSpot_Part^ tmpPart = (HotSpot_Part^)this->tmpHotSpotData->default[tmpindex];


				
				// this->txtName->Text = inputData[0];
				// this->txtNumber->Text =inputData[1];
				// this->cboPitchDirection->SelectedIndex  = Convert::ToInt16(inputData[2]);
				// this->txtPitch->Text = inputData[3];
				// this->txtCoord_X->Text = inputData[4];
				// this->txtCoord_Y->Text = inputData[5];
				// this->txtLongAxis->Text = inputData[6];
				// this->txtShortAxis->Text = inputData[7];
				// this->txtRotateAngle->Text = inputData[8];
				// this->txtGainValue->Text = inputData[9];
				// this->numSmoothDegree->Value = Convert::ToInt16(inputData[10]);
				// this->numX1->Value = Convert::ToDecimal(inputData[11]);
				// this->txtY1->Text = inputData[12];
				// this->numX2->Value =Convert::ToDecimal( inputData[13]);
				// this->txtY2->Text = inputData[14];
				// this->numX3->Value = Convert::ToDecimal(inputData[15]);
				// this->txtY3->Text = inputData[16];

				 this->txtName->Text = tmpPart->Name;
				 this->txtNumber->Text =Convert::ToString(tmpPart->Number);

				 this->cboShape->SelectedIndex = tmpPart->ShapeIndex;
				
				 this->cboPitchDirection->SelectedIndex = tmpPart->PitchDirectionIndex;				 
				 this->txtPitch->Text = Convert::ToString(tmpPart->pitch);

				 this->txtCoord_X->Text = Convert::ToString(tmpPart->CenterCoordinate.X);
				 this->txtCoord_Y->Text = Convert::ToString(tmpPart->CenterCoordinate.Y);


				 this->txtLongAxis->Text = Convert::ToString(tmpPart->Length_X);
				 this->txtShortAxis->Text = Convert::ToString(tmpPart->Length_Y);

				 this->txtRotateAngle->Text = Convert::ToString(tmpPart->rotateAngle);
				 this->txtGainValue->Text = Convert::ToString(tmpPart->CenterGainValue);
				 this->numSmoothDegree->Value =tmpPart->SmoothingDegree;

				 this->numX1->Value = Convert::ToDecimal(tmpPart->ConrollPt[0].X);
				 this->txtY1->Text = Convert::ToString(tmpPart->ConrollPt[0].Y);
				 this->numX2->Value = Convert::ToDecimal(tmpPart->ConrollPt[1].X);
				 this->txtY2->Text = Convert::ToString(tmpPart->ConrollPt[1].Y);
				 this->numX3->Value =  Convert::ToDecimal(tmpPart->ConrollPt[2].X);
				 this->txtY3->Text = Convert::ToString(tmpPart->ConrollPt[2].Y);


				 //20120920增加
				 this->cboSwapMode->SelectedIndex = tmpPart->SwapModeIndex  ;
				 
				
				 
				
				 //圖面更新
				this->pictureBoxShow->Invalidate();
				this->picLineCurve->Invalidate();

				






		 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->Close();

			 
		 }


private: System::Void txtGainValue_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			
			 
		 }
private: System::Void txtNumber_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 try{
				 if(Convert::ToInt16(this->txtNumber->Text)>1){
					 this->txtPitch->Enabled = true;
					 this->cboPitchDirection->Enabled = true;
				 }else{
					 this->txtPitch->Enabled = false;
					 this->cboPitchDirection->Enabled = false;
				 }
			 }catch(...){
				 MessageBox::Show("輸入錯誤 !");
			 }

		 }



private: System::Void numX2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		//	 this->numX2->Maximum::set(this->numX3->Value);
		//	 this->numX2->Minimum::set(this->numX1->Value);
		 }
private: System::Void numX3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		//	 this->numX3->Minimum::set(this->numX2->Value);
		 }
private: System::Void numX1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		//	this->numX1->Maximum::set(this->numX2->Value);
		 }
private: System::Void cboShape_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
			 if(this->cboShape->SelectedIndex == 0){
				 // 橢圓形
				 this->lbl_X->Text = "長軸(X方向)" ;
				 this->lbl_Y->Text = "短軸(Y方向)" ;
				 this->lbl_Coor->Text = "軸心座標位置(X,Y) :";
				 this->cboSwapMode->Enabled = true;


			 }else{
				 //菱形
				 this->lbl_X->Text = "對角線(X方向)" ;
				 this->lbl_Y->Text = "對角線(Y方向)" ;
				 this->lbl_Coor->Text = "中心座標位置(X,Y) :";
				 this->cboSwapMode->Enabled = false;

			 }


		 }


private: System::Void pictureBoxShow_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {



			 	

			 if(this->SelectedCptIndex != -1 && e->Button == ::MouseButtons::Left){	
				 array<PointF>^ tmp = gcnew array<PointF>(1);
				 float tmpY ;
				 tmp[0].X = this->OrigionalCpt[this->SelectedCptIndex].X-1;
				 tmp[0].Y = 0;
				 tmpY = this->OrigionalCpt[this->SelectedCptIndex].Y;
				 this->PicMatrix->TransformPoints(tmp);

				 float deltaX = 0 ;
				 float deltaY = 0 ;

				 deltaX = e->X - tmp[0].X;							
			     deltaY = e->Y - tmp[0].Y;


				 if(e->X <= 0 || e->Y <= 0 || e->X > this->pictureBoxShow->Size.Width || e->Y > this->pictureBoxShow->Size.Height) return ;
				

				switch (this->SelectedCptIndex){

					case 1:  
						if (Math::Abs(deltaX) <= Math::Abs(deltaY)) this->txtY1->Text =   Convert::ToString (this->OrigionalCpt[this->SelectedCptIndex].Y - deltaY/100.0f);
						if (Math::Abs(deltaX) > Math::Abs(deltaY)) this->numX1->Value =  Convert::ToDecimal(this->OrigionalCpt[this->SelectedCptIndex].X + deltaX/this->PicMatrix->Elements[0]);
						break;
					case 2: 			
						if (Math::Abs(deltaX) <= Math::Abs(deltaY)) this->txtY2->Text =   Convert::ToString (this->OrigionalCpt[this->SelectedCptIndex].Y - deltaY/100.0f);
						if (Math::Abs(deltaX) > Math::Abs(deltaY)) this->numX2->Value =  Convert::ToDecimal(this->OrigionalCpt[this->SelectedCptIndex].X + deltaX/this->PicMatrix->Elements[0]);
						break;
					case 3: 			
						if (Math::Abs(deltaX) <= Math::Abs(deltaY)) this->txtY3->Text =   Convert::ToString (this->OrigionalCpt[this->SelectedCptIndex].Y - deltaY/100.0f);
						if (Math::Abs(deltaX) > Math::Abs(deltaY)) this->numX3->Value =  Convert::ToDecimal(this->OrigionalCpt[this->SelectedCptIndex].X + deltaX/this->PicMatrix->Elements[0]);

						break;
					case 4: 			
						if (Math::Abs(deltaX) <= Math::Abs(deltaY)) this->txtGainValue->Text = Convert::ToString(this->OrigionalCpt[this->SelectedCptIndex].Y - deltaY/100.0f);
						break;

				}

				




				this->pictureBoxShow->Invalidate();
				this->picLineCurve->Invalidate();



			 }
				
				

					



			 




		 }
private: System::Void pictureBoxShow_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

			 //*
			 
			 
			  array<PointF>^ Pre_cPt = gcnew array<PointF>(5);
			  array<PointF>^ Pre_Curve ;
			 
			 array<PointF>^ cPt = gcnew array<PointF>(5);


			 float gainVaule = Convert::ToSingle(this->txtGainValue->Text);

			cPt[0].Y = 1; //邊緣Gain 值永遠是1 
			cPt[0].X = 0;
			cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
			cPt[4].X = 1;

			cPt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			cPt[1].X =  Convert::ToSingle(this->numX1->Value);
			cPt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			cPt[2].X =  Convert::ToSingle(this->numX2->Value);
			cPt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			cPt[3].X =  Convert::ToSingle(this->numX3->Value);


			//儲存舊的CPt; 
			this->tmpCurve->ControllPt->CopyTo(Pre_cPt);
			

			this->tmpCurve->ControllPt->Clear();
			for(int ii = 0 ; ii < 5 ; ii ++){
				this->tmpCurve->ControllPt->Add(cPt[ii]);
			 }

			 this->tmpCurve->Set_k_Value(Convert::ToInt16(this->numSmoothDegree->Value));
			 this->tmpCurve->ReProduceCurve(101);


	
		
			array<PointF,1>^ tmpCurve = this->tmpCurve->GetCurve();
			float max = -10000;
			float min = 10000;
			for(int ii = 0 ; ii <tmpCurve->Length ; ii++){
				if(tmpCurve[ii].Y > max ) max = tmpCurve[ii].Y;
				if(tmpCurve[ii].Y < min ) min = tmpCurve[ii].Y;

				//確認Curve 是否有倒包的情況發生

				if (ii != tmpCurve->Length-1){
					
					//PS : 此判別方法僅限於目前設定(座標位置變化後 ,結果就會不一樣 ) 					
					if((tmpCurve[ii+1].X  -tmpCurve[ii].X) <= 0){

						//回復舊的資料 

						this->txtY1->Text =   Convert::ToString (Pre_cPt[1].Y);
						this->numX1->Value =  Convert::ToDecimal(Pre_cPt[1].X);
						this->txtY2->Text =   Convert::ToString (Pre_cPt[2].Y);
						this->numX2->Value =  Convert::ToDecimal(Pre_cPt[2].X);
						this->txtY3->Text =   Convert::ToString (Pre_cPt[3].Y);
						this->numX3->Value =  Convert::ToDecimal(Pre_cPt[3].X);
						this->txtGainValue->Text = Convert::ToString(Pre_cPt[4].Y);

						this->tmpCurve->ControllPt->Clear();
						for(int ii = 0 ; ii < 5 ; ii ++){
							this->tmpCurve->ControllPt->Add(Pre_cPt[ii]);
						}
						this->tmpCurve->ReProduceCurve(101);					
						return;
					}
				}
				

			}


			 Pen^ tmpPen = gcnew Pen(Brushes::Blue);
			 tmpPen->Width::set(0.02);		

			 //繪圖
			 

			 


		
			 e->Graphics->Clear(Color::Black);
			
			 Matrix^ PicMatrix;
			 
		
			//將座標轉換為中心點 為座標原點 ,並且為更改定義為往右和往上為正 ,並Scale ,使座標點為(1,1)的時候,是在圖形的右上角~
			 PicMatrix = gcnew Matrix(pictureBoxShow->Width/2.0f,0.0f,0.0f,-pictureBoxShow->Height/2.0f,pictureBoxShow->Width/2.0f,pictureBoxShow->Height/2.0f); 


		
			// 座標轉換
			//tmpShow->Transform::set(PicMatrix);
			e->Graphics->Transform::set(PicMatrix);
			

			 


			array<PointF>^ tmpPolygon = gcnew array<PointF>(4);





			if(this->cboShape->SelectedIndex == 0 && this->cboSwapMode->SelectedIndex == 1){

				for(int jj = this->tmpCurve->GetCurve()->Length-1 ; jj>=0 ; jj --){
			   		float R;
					float G;
					float B;
					 
					 float density;
					 float ratio = (float)jj/(this->tmpCurve->GetCurve()->Length-1);
					 density = this->tmpCurve->GetCurve_Z_Value(1.0f-ratio,0);

					 if(density<0 ) density = 0;

					 // 定義Gain =0 時den = 0  ,Gain =5 時 den = 1 
					 density = (density-1.0f)/5.0f + 1.0f/5.0f ;
					 SetDensityColor(density,R,G,B);
					 tmpPen->Color::set(Color::FromArgb(R,G,B));
					 e->Graphics->FillEllipse(tmpPen->Brush,RectangleF(-ratio,-ratio,2*ratio,2*ratio));
							 							 
				}
					
				
					
					 
			}else if (this->cboShape->SelectedIndex == 1){

				for(int jj = this->tmpCurve->GetCurve()->Length-1 ; jj>=0 ; jj --){
			   		float R;
					float G;
					float B;
					 
					 float density;
					 float ratio = (float)jj/(this->tmpCurve->GetCurve()->Length-1);
					 density = this->tmpCurve->GetCurve_Z_Value(1.0f-ratio,0);

					  if(density<0 ) density = 0;

					 // 定義Gain =0 時den = 0  ,Gain =5 時 den = 1 
					 density = (density-1.0f)/5.0f + 1.0f/5.0f ;
					 SetDensityColor(density,R,G,B);
					 tmpPen->Color::set(Color::FromArgb(R,G,B));

					tmpPolygon[0] = PointF(0,-ratio);
					tmpPolygon[1] = PointF(-ratio,0);
					tmpPolygon[2] = PointF(0,ratio);
					tmpPolygon[3] = PointF(ratio,0);

					e->Graphics->FillPolygon(tmpPen->Brush,tmpPolygon);
					
							 							 
				}



			}else if (this->cboShape->SelectedIndex == 0 && this->cboSwapMode->SelectedIndex == 0){

				
				if (this->txtLongAxis->Text == "" || this->txtShortAxis->Text == "") {
					MessageBox::Show("請輸入長軸與短軸尺寸!!!");
					return;
				}

							
					float thda;
					float R;
					float G;
					float B;
					
					float LongAxis = Convert::ToSingle(this->txtLongAxis->Text);
					float ShortAxis = Convert::ToSingle(this->txtShortAxis->Text);

					//橢圓焦點
					 array<PointF>^ focusPt = gcnew array<PointF>(2) ;
					 float C ;
					 if(LongAxis >ShortAxis){
						C = Math::Sqrt(LongAxis*LongAxis-ShortAxis*ShortAxis);
						focusPt[0].X = C;
						focusPt[1].X = -C;
						focusPt[0].Y = 0;
						focusPt[1].Y = 0;

					
					 }else{ 
						C = Math::Sqrt(-LongAxis*LongAxis+ShortAxis*ShortAxis);
						focusPt[0].X = 0;
						focusPt[1].X = 0;
						focusPt[0].Y = C;
						focusPt[1].Y = -C;
					 }


					 for(int kk = 0 ; kk <31 ; kk++){
						 for(int jj = 0 ; jj<31 ; jj++){





							
							
							PointF tmp_pt = PointF(kk/30.0f*LongAxis,jj/30.0f*ShortAxis);



							float  value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));


							 if (value < 2*Math::Max(LongAxis,ShortAxis)){

								thda = Math::Atan2(tmp_pt.Y,tmp_pt.X);
								

								float tmpZ = 0;
								float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
								float R2 = Math::Sqrt(Math::Pow(tmp_pt.X,2) + Math::Pow(tmp_pt.Y,2));	
								
									tmpZ = this->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);

									 if(tmpZ<0 ) tmpZ = 0;

									tmpZ = (tmpZ-1.0f)/5.0f + 1.0f/5.0f ;
									SetDensityColor(tmpZ,R,G,B);
									tmpPen->Color::set(Color::FromArgb(R,G,B));

									e->Graphics->FillRectangle(tmpPen->Brush,tmp_pt.X/LongAxis-0.05f,tmp_pt.Y/ShortAxis-0.05f,0.1f,0.1f);
									e->Graphics->FillRectangle(tmpPen->Brush,-tmp_pt.X/LongAxis-0.05f,tmp_pt.Y/ShortAxis-0.05f,0.1f,0.1f);
									e->Graphics->FillRectangle(tmpPen->Brush,-tmp_pt.X/LongAxis-0.05f,-tmp_pt.Y/ShortAxis-0.05f,0.1f,0.1f);
									e->Graphics->FillRectangle(tmpPen->Brush,tmp_pt.X/LongAxis-0.05f,-tmp_pt.Y/ShortAxis-0.05f,0.1f,0.1f);
								

							 }
							
						 }

					 }
				

			}


		
























			 //畫控制點座標 :
			 for(int jj = 1  ; jj <this->tmpCurve->ControllPt->Count  ; jj ++){



				 if( jj == this->SelectedCptIndex) {
					 tmpPen->Color::set(Color::Red);
					 e->Graphics->FillEllipse(tmpPen->Brush,RectangleF((this->tmpCurve->ControllPt->default[jj].X-0.05)-1 ,-0.05 ,0.1,0.1));
				 }else {
					 tmpPen->Color::set(Color::YellowGreen);				 
		
					 e->Graphics->FillEllipse(tmpPen->Brush,RectangleF((this->tmpCurve->ControllPt->default[jj].X-0.05)-1 ,-0.05 ,0.1,0.1));


				 }

			 }

			
			
			




				


		 }
private: System::Void pictureBoxShow_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			
		 }
private: System::Void pictureBoxShow_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {




			this->OrigionalCpt[0].Y = 1; //邊緣Gain 值永遠是1 
			this->OrigionalCpt[0].X = 0;
			this->OrigionalCpt[4].Y = Convert::ToSingle(this->txtGainValue->Text); //中心Gain 值是使用者輸入
			this->OrigionalCpt[4].X = 1;

			this->OrigionalCpt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			this->OrigionalCpt[1].X =  Convert::ToSingle(this->numX1->Value);
			this->OrigionalCpt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			this->OrigionalCpt[2].X =  Convert::ToSingle(this->numX2->Value);
			this->OrigionalCpt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			this->OrigionalCpt[3].X =  Convert::ToSingle(this->numX3->Value);


			this->SelectedCptIndex = -1;

			for(int ii = 1 ; ii < this->OrigionalCpt->Length ; ii++){
				array<PointF>^ tmp = gcnew array<PointF>(1) ;
				tmp[0].X= this->OrigionalCpt[ii].X-1;
				tmp[0].Y = 0;
				this->PicMatrix->TransformPoints(tmp);
				RectangleF block(tmp[0].X-5,tmp[0].Y-5,10,10);
				if(block.Contains(Point(e->X ,e->Y) )){
					this->SelectedCptIndex = ii;
					break;
				}

			}


			this->pictureBoxShow->Invalidate();
			this->picLineCurve->Invalidate();


/*

			 this->SelectedCpt = gcnew array<PointF>(5);


			array<PointF>^ cPt = gcnew array<PointF>(5);

			 float gainVaule = Convert::ToSingle(this->txtGainValue->Text);

			cPt[0].Y = 1; //邊緣Gain 值永遠是1 
			cPt[0].X = 0;
			cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
			cPt[4].X = 1;

			cPt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			cPt[1].X =  Convert::ToSingle(this->numX1->Value);
			cPt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			cPt[2].X =  Convert::ToSingle(this->numX2->Value);
			cPt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			cPt[3].X =  Convert::ToSingle(this->numX3->Value);



		
			 
				
				

					tmp[0].X = e->X;
					tmp[0].Y = e->Y;	





				//顯示滑鼠對應座標
					if(this->PicMatrix != nullptr && this->PicMatrix->IsInvertible == true ) {

					Matrix^ InvMa = gcnew Matrix(this->PicMatrix->Elements[0],this->PicMatrix->Elements[1],this->PicMatrix->Elements[2],this->PicMatrix->Elements[3],this->PicMatrix->Elements[4],this->PicMatrix->Elements[5]) ;				
					InvMa->Invert();	
					InvMa->TransformPoints(tmp);
					delete InvMa;	




					bool tmpSelected = false; 
					int symbol ;
					
					if(e->Button == ::MouseButtons::Left)  symbol = 1; 
					if(e->Button == ::MouseButtons::Right)  symbol = -1; 


					for(int ii = 0 ; ii <cPt->Length ; ii ++){
						RectangleF block(cPt[ii].X-0.05-1.0f,-0.05,0.1,0.1);
						if(block.Contains(tmp[0]) && SelectedCpt[ii] == PointF(0,0)){

							SelectedCpt[ii].X = e->X;
							SelectedCpt[ii].Y = e->Y;


							
							tmpSelected = true;

							break;
						}

					}

					if(tmpSelected == false ) {
						  delete[] this->SelectedCpt;
						  this->SelectedCpt = nullptr;
					}


					this->pictureBoxShow->Invalidate();
					
				}
				
*/


		 }
private: System::Void pictureBoxShow_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {



			this->SelectedCptIndex = -1;
			 		

			

			this->OrigionalCpt[0].Y = 1; //邊緣Gain 值永遠是1 
			this->OrigionalCpt[0].X = 0;
			this->OrigionalCpt[4].Y = Convert::ToSingle(this->txtGainValue->Text); //中心Gain 值是使用者輸入
			this->OrigionalCpt[4].X = 1;

			this->OrigionalCpt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			this->OrigionalCpt[1].X =  Convert::ToSingle(this->numX1->Value);
			this->OrigionalCpt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			this->OrigionalCpt[2].X =  Convert::ToSingle(this->numX2->Value);
			this->OrigionalCpt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			this->OrigionalCpt[3].X =  Convert::ToSingle(this->numX3->Value);


			this->pictureBoxShow->Invalidate();
			this->picLineCurve->Invalidate();

		 }

private: System::Void picLineCurve_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 		
			 	array<PointF>^ tmp = gcnew array<PointF>(1);

				tmp[0].X = e->X;
				tmp[0].Y = e->Y;	





				//顯示滑鼠對應座標
				if(this->PicMatrix != nullptr && this->PicMatrix->IsInvertible == true ) {

				Matrix^ InvMa = gcnew Matrix(this->PicMatrix->Elements[0],this->PicMatrix->Elements[1],this->PicMatrix->Elements[2],this->PicMatrix->Elements[3],this->PicMatrix->Elements[4],this->PicMatrix->Elements[5]) ;				
				InvMa->Invert();	
				InvMa->TransformPoints(tmp);
				delete InvMa;	

				}


		 }
private: System::Void picLineCurve_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {


	/*		 			 
			 array<PointF>^ cPt = gcnew array<PointF>(5);

			

			cPt[0].Y = 1; //邊緣Gain 值永遠是1 
			cPt[0].X = 0;
			cPt[4].Y = Convert::ToSingle(this->txtGainValue->Text); //中心Gain 值是使用者輸入
			cPt[4].X = 1;

			cPt[1].Y =  Convert::ToSingle(this->txtY1->Text);
			cPt[1].X =  Convert::ToSingle(this->numX1->Value);
			cPt[2].Y =  Convert::ToSingle(this->txtY2->Text);
			cPt[2].X =  Convert::ToSingle(this->numX2->Value);
			cPt[3].Y =  Convert::ToSingle(this->txtY3->Text);
			cPt[3].X =  Convert::ToSingle(this->numX3->Value);


		

			this->tmpCurve->ControllPt->Clear();

  			for(int ii = 0 ; ii < 5 ; ii ++){
				this->tmpCurve->ControllPt->Add(cPt[ii]);
			}

			 this->tmpCurve->Set_k_Value(Convert::ToInt16(this->numSmoothDegree->Value));
			 this->tmpCurve->ReProduceCurve(101);

*/
	
/*		
			array<PointF,1>^ tmpCurve = this->tmpCurve->GetCurve();
			float max = -10000;
			float min = 10000;

			
			for(int ii = 0 ; ii <tmpCurve->Length ; ii++){
				if(tmpCurve[ii].Y > max ) max = tmpCurve[ii].Y;
				if(tmpCurve[ii].Y < min ) min = tmpCurve[ii].Y;

				if (min < 0 ) min = 0 ;

			}
*/

			float max = this->tmpCurve->Curve_Boundary.Y + this->tmpCurve->Curve_Boundary.Height ;
			float min = this->tmpCurve->Curve_Boundary.Y;

			if(min < 0 ) min = 0;




			 //繪圖
			 
			 Graphics^ tmp = e->Graphics;
			
			 Point Size(this->picLineCurve->Width,this->picLineCurve->Height);
			 Pen^ tmpPen = gcnew Pen(Brushes::Blue);


			 tmp->Clear(Color::Black);


			 tmpPen->Width::set(0.01);			
		





			//畫顆度線
			  System::Drawing::Font^ tmpFont = gcnew System::Drawing::Font(L"新細明體",10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136));
			tmpPen->Color::set(Color::White);
			 for(int ii = 0 ; ii < 9 ; ii ++){
				 float temp = (max-min)/8.0f*ii + min;
				 String^ s = String::Format("{0:0.00}",temp);
				 tmp->DrawLine(tmpPen,0.0f,0.8f*Size.Y*(8-ii)/8.0f+0.1f*Size.Y,7.0f,0.8f*Size.Y*(8-ii)/8.0f+0.1f*Size.Y);
				 tmp->DrawString(s,tmpFont,tmpPen->Brush,10.0f,0.8f*Size.Y*(8-ii)/8.0f-5+0.1f*Size.Y);	 
			 }  





			 //Scale 

			
			
			 tmp->TranslateTransform(0,max*0.8f*Size.Y/(max- min)+0.1f*Size.Y ); 
			 tmp->ScaleTransform(Size.X,-0.8f*Size.Y/(max- min));
			
			 
			



			 //畫Cruve-----------------------------------------------

			 tmpPen->Color::set(Color::Blue);	

			 array<PointF>^ X_AxisCurve = gcnew array<PointF>(201);

			 for(int ii = 0 ; ii < 101 ; ii ++){
				 X_AxisCurve[ii].X = this->tmpCurve->GetCurve()[ii].X/2.0f;
				 X_AxisCurve[ii].Y = this->tmpCurve->GetCurve()[ii].Y;

				 if(X_AxisCurve[ii].Y < 0) X_AxisCurve[ii].Y = 0;

			 }
			 for(int ii = 101 ; ii < 201 ; ii ++){
				 X_AxisCurve[ii].X = 1.0f-this->tmpCurve->GetCurve()[200-ii].X/2.0f;
				 X_AxisCurve[ii].Y = this->tmpCurve->GetCurve()[200-ii].Y;

				 if(X_AxisCurve[ii].Y < 0) X_AxisCurve[ii].Y = 0;
				 
			 }



			 tmp->DrawLines(tmpPen,X_AxisCurve);  



			 








		 }
};
}