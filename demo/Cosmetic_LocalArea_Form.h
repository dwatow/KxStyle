#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace DrawModule;
//using namespace System::IO;


using namespace System::Drawing::Imaging;
#include "DataStructure.h"


using namespace DensityClass;

namespace PatternContruction {

	/// <summary>
	/// Cosmetic_LocalArea_Form 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public  ref class Cosmetic_LocalArea_Form : public System::Windows::Forms::Form
	
	{
	public:
		Cosmetic_LocalArea_Form(Point GridNumber,GridDensity^ density,Pattern^ dot,Cosmetic_Data^ localData,RectangleF LGP,ArrayList^ localsurfacedata)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			tmpLocalData = localData;
			tmpDot = dot;
			tmpLGP = LGP;
			tmpDen = density;
			tmpGridNumber = GridNumber;
		//	tmplocalsurfacedata = localsurfacedata;
			Tolocalsurfacedata = localsurfacedata;
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Cosmetic_LocalArea_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox3;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox1;





	private: System::Windows::Forms::DataGridView^  dataGridView_History;


	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btn_Delete;
	private: System::Windows::Forms::Button^  btn_Modify;
	private: System::Windows::Forms::Button^  btnAdd;
	private:
		/// <summary>
		/// 設計工具所需的變數。
	
		Pattern^ tmpDot;
		GridDensity^ tmpDen;
		Cosmetic_Data^ tmpLocalData;
		Point tmpGridNumber;

		ArrayList^ tmplocalsurfacedata;
		ArrayList^ Tolocalsurfacedata;

		array<String^,1>^ InputData;

		

	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::DataGridView^  dataGridView_Ratio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn45;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn46;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn47;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn48;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn49;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: System::Windows::Forms::DataGridView^  dataGridView_Density;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn50;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn51;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn52;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn53;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn54;
	private: System::Windows::Forms::Button^  btnCal;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::ComboBox^  cboCalRatioMethod;






	private: System::Windows::Forms::Label^  lbl_V_Value;
	private: System::Windows::Forms::Label^  lbl_U_Value;
	private: System::Windows::Forms::ComboBox^  cboRadiusVariation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnCoorLocation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;








			 RectangleF tmpLGP;
//	bool Input();
	bool DatatoArray(int checkedItem);    //將局部修改表單中的參數存為array ,...
	void ArraytoData(ArrayList^ SurfaceArrayList , int index);
	void ShowData(array<String^,1>^ inputdata,int currentRow);
	//array<float,1>^ ToSurfaceInputData(array<String^,1>^ forminputdata);
	array<String^>^ ToSurfaceInputData(array<String^,1>^ forminputdata);

	
		
	












	private: System::Windows::Forms::HScrollBar^  hScrollBar_V_Value;
	private: System::Windows::Forms::HScrollBar^  hScrollBar_U_Value;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::ComboBox^  cboArratDirection;
	private: System::Windows::Forms::TextBox^  txtArrayDistance;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txtArrayNumber;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TabControl^  tabDensity_ControllPt;
private: System::Windows::Forms::TabPage^  tabControlPtDensity;

private: System::Windows::Forms::DataGridView^  dataGridView_ModifyPara;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
private: System::Windows::Forms::TabPage^  Pt_Weight;
private: System::Windows::Forms::DataGridView^  dataGridControllPtWeight;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn16;

private: System::Windows::Forms::TabPage^  tabControllPtX;
private: System::Windows::Forms::TabPage^  tabControllPtY;
private: System::Windows::Forms::DataGridView^  dataGrid_Cpt_X;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn17;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn18;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn19;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn20;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn21;
private: System::Windows::Forms::DataGridView^  dataGrid_Cpt_Y;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn22;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn23;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn24;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn25;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn26;





private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::TextBox^  txtNumY;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;

private: System::Windows::Forms::TextBox^  txtNumX;

private: System::Windows::Forms::TextBox^  txtSurfaceName;
private: System::Windows::Forms::Label^  label15;

	private: System::Windows::Forms::Button^  btn_Accept;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txt_Y_Value;

	private: System::Windows::Forms::TextBox^  txt_X_Value;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cboPointLocation;
	private: System::Windows::Forms::TextBox^  txt_Area_Width;
	private: System::Windows::Forms::TextBox^  txt_Area_Length;
	private: System::Windows::Forms::GroupBox^  groupBox2;




			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btn_Modify = (gcnew System::Windows::Forms::Button());
			this->dataGridView_History = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnCoorLocation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_V_Value = (gcnew System::Windows::Forms::Label());
			this->lbl_U_Value = (gcnew System::Windows::Forms::Label());
			this->txtSurfaceName = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar_V_Value = (gcnew System::Windows::Forms::HScrollBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtNumY = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar_U_Value = (gcnew System::Windows::Forms::HScrollBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtNumX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->txtArrayDistance = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtArrayNumber = (gcnew System::Windows::Forms::TextBox());
			this->cboArratDirection = (gcnew System::Windows::Forms::ComboBox());
			this->tabDensity_ControllPt = (gcnew System::Windows::Forms::TabControl());
			this->tabControlPtDensity = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_ModifyPara = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pt_Weight = (gcnew System::Windows::Forms::TabPage());
			this->dataGridControllPtWeight = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControllPtX = (gcnew System::Windows::Forms::TabPage());
			this->dataGrid_Cpt_X = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControllPtY = (gcnew System::Windows::Forms::TabPage());
			this->dataGrid_Cpt_Y = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txt_Area_Width = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboPointLocation = (gcnew System::Windows::Forms::ComboBox());
			this->txt_Area_Length = (gcnew System::Windows::Forms::TextBox());
			this->txt_Y_Value = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_X_Value = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btn_Accept = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->cboCalRatioMethod = (gcnew System::Windows::Forms::ComboBox());
			this->btnCal = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Ratio = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn45 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn46 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn47 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn48 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn49 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Density = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn50 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn51 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn52 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn53 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn54 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cboRadiusVariation = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_History))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabDensity_ControllPt->SuspendLayout();
			this->tabControlPtDensity->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ModifyPara))->BeginInit();
			this->Pt_Weight->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridControllPtWeight))->BeginInit();
			this->tabControllPtX->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid_Cpt_X))->BeginInit();
			this->tabControllPtY->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid_Cpt_Y))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Ratio))->BeginInit();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Density))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->btn_Delete);
			this->groupBox3->Controls->Add(this->btnAdd);
			this->groupBox3->Controls->Add(this->btn_Modify);
			this->groupBox3->Controls->Add(this->dataGridView_History);
			this->groupBox3->Location = System::Drawing::Point(356, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(298, 426);
			this->groupBox3->TabIndex = 20;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"歷史紀錄";
			// 
			// btn_Delete
			// 
			this->btn_Delete->Enabled = false;
			this->btn_Delete->Location = System::Drawing::Point(201, 367);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(72, 33);
			this->btn_Delete->TabIndex = 27;
			this->btn_Delete->Text = L"刪除";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btn_Delete_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(16, 367);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(72, 33);
			this->btnAdd->TabIndex = 25;
			this->btnAdd->Text = L"增加";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btnAdd_Click);
			// 
			// btn_Modify
			// 
			this->btn_Modify->Enabled = false;
			this->btn_Modify->Location = System::Drawing::Point(107, 367);
			this->btn_Modify->Name = L"btn_Modify";
			this->btn_Modify->Size = System::Drawing::Size(72, 33);
			this->btn_Modify->TabIndex = 26;
			this->btn_Modify->Text = L"修改";
			this->btn_Modify->UseVisualStyleBackColor = true;
			this->btn_Modify->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btn_Modify_Click);
			// 
			// dataGridView_History
			// 
			this->dataGridView_History->AllowDrop = true;
			this->dataGridView_History->AllowUserToAddRows = false;
			this->dataGridView_History->AllowUserToDeleteRows = false;
			this->dataGridView_History->AllowUserToOrderColumns = true;
			this->dataGridView_History->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_History->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Column1, 
				this->columnCoorLocation, this->dataGridViewTextBoxColumn1, this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, 
				this->dataGridViewTextBoxColumn4});
			this->dataGridView_History->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView_History->Location = System::Drawing::Point(16, 21);
			this->dataGridView_History->MultiSelect = false;
			this->dataGridView_History->Name = L"dataGridView_History";
			this->dataGridView_History->ReadOnly = true;
			this->dataGridView_History->RowHeadersWidth = 15;
			this->dataGridView_History->RowTemplate->Height = 24;
			this->dataGridView_History->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_History->Size = System::Drawing::Size(257, 314);
			this->dataGridView_History->TabIndex = 24;
			this->dataGridView_History->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Cosmetic_LocalArea_Form::dataGridView_History_CellMouseClick);
			this->dataGridView_History->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &Cosmetic_LocalArea_Form::dataGridView_History_RowsAdded);
			this->dataGridView_History->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &Cosmetic_LocalArea_Form::dataGridView_History_RowsRemoved);
			this->dataGridView_History->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Cosmetic_LocalArea_Form::dataGridView_History_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->FillWeight = 50;
			this->Column1->HeaderText = L"名稱";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column1->Width = 40;
			// 
			// columnCoorLocation
			// 
			this->columnCoorLocation->FillWeight = 60;
			this->columnCoorLocation->HeaderText = L"起始點";
			this->columnCoorLocation->Name = L"columnCoorLocation";
			this->columnCoorLocation->ReadOnly = true;
			this->columnCoorLocation->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->columnCoorLocation->Width = 40;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->FillWeight = 60;
			this->dataGridViewTextBoxColumn1->HeaderText = L"座標(X)";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn1->Width = 40;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->FillWeight = 60;
			this->dataGridViewTextBoxColumn2->HeaderText = L"座標(Y)";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn2->Width = 40;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->FillWeight = 60;
			this->dataGridViewTextBoxColumn3->HeaderText = L"長度";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn3->Width = 40;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->FillWeight = 60;
			this->dataGridViewTextBoxColumn4->HeaderText = L"寬度";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->dataGridViewTextBoxColumn4->Width = 40;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->tabDensity_ControllPt);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(2, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 473);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"參數輸入";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->lbl_V_Value);
			this->groupBox5->Controls->Add(this->lbl_U_Value);
			this->groupBox5->Controls->Add(this->txtSurfaceName);
			this->groupBox5->Controls->Add(this->hScrollBar_V_Value);
			this->groupBox5->Controls->Add(this->label15);
			this->groupBox5->Controls->Add(this->txtNumY);
			this->groupBox5->Controls->Add(this->hScrollBar_U_Value);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->label14);
			this->groupBox5->Controls->Add(this->txtNumX);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Location = System::Drawing::Point(0, 94);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(335, 92);
			this->groupBox5->TabIndex = 41;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"控制點數目和名稱";
			// 
			// lbl_V_Value
			// 
			this->lbl_V_Value->AutoSize = true;
			this->lbl_V_Value->Location = System::Drawing::Point(220, 66);
			this->lbl_V_Value->Name = L"lbl_V_Value";
			this->lbl_V_Value->Size = System::Drawing::Size(33, 12);
			this->lbl_V_Value->TabIndex = 64;
			this->lbl_V_Value->Text = L"label8";
			// 
			// lbl_U_Value
			// 
			this->lbl_U_Value->AutoSize = true;
			this->lbl_U_Value->Location = System::Drawing::Point(220, 44);
			this->lbl_U_Value->Name = L"lbl_U_Value";
			this->lbl_U_Value->Size = System::Drawing::Size(33, 12);
			this->lbl_U_Value->TabIndex = 63;
			this->lbl_U_Value->Text = L"label7";
			// 
			// txtSurfaceName
			// 
			this->txtSurfaceName->Location = System::Drawing::Point(40, 18);
			this->txtSurfaceName->Name = L"txtSurfaceName";
			this->txtSurfaceName->Size = System::Drawing::Size(67, 22);
			this->txtSurfaceName->TabIndex = 8;
			this->txtSurfaceName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Cosmetic_LocalArea_Form::txtSurfaceName_KeyPress);
			// 
			// hScrollBar_V_Value
			// 
			this->hScrollBar_V_Value->LargeChange = 1;
			this->hScrollBar_V_Value->Location = System::Drawing::Point(82, 66);
			this->hScrollBar_V_Value->Maximum = 1000;
			this->hScrollBar_V_Value->Minimum = 2;
			this->hScrollBar_V_Value->Name = L"hScrollBar_V_Value";
			this->hScrollBar_V_Value->Size = System::Drawing::Size(126, 12);
			this->hScrollBar_V_Value->TabIndex = 62;
			this->hScrollBar_V_Value->Value = 2;
			this->hScrollBar_V_Value->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Cosmetic_LocalArea_Form::hScrollBar_V_Value_Scroll);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 21);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(29, 12);
			this->label15->TabIndex = 7;
			this->label15->Text = L"名稱";
			// 
			// txtNumY
			// 
			this->txtNumY->Location = System::Drawing::Point(286, 16);
			this->txtNumY->Name = L"txtNumY";
			this->txtNumY->Size = System::Drawing::Size(44, 22);
			this->txtNumY->TabIndex = 6;
			this->txtNumY->TextChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::txtNumY_TextChanged);
			// 
			// hScrollBar_U_Value
			// 
			this->hScrollBar_U_Value->LargeChange = 1;
			this->hScrollBar_U_Value->Location = System::Drawing::Point(82, 43);
			this->hScrollBar_U_Value->Maximum = 1000;
			this->hScrollBar_U_Value->Minimum = 2;
			this->hScrollBar_U_Value->Name = L"hScrollBar_U_Value";
			this->hScrollBar_U_Value->Size = System::Drawing::Size(126, 13);
			this->hScrollBar_U_Value->TabIndex = 61;
			this->hScrollBar_U_Value->Value = 2;
			this->hScrollBar_U_Value->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Cosmetic_LocalArea_Form::hScrollBar_U_Value_Scroll);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(225, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 12);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Y方向數目";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(113, 21);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(64, 12);
			this->label14->TabIndex = 4;
			this->label14->Text = L"X方向 數目";
			this->label14->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::label14_Click);
			// 
			// txtNumX
			// 
			this->txtNumX->Location = System::Drawing::Point(179, 16);
			this->txtNumX->Name = L"txtNumX";
			this->txtNumX->Size = System::Drawing::Size(45, 22);
			this->txtNumX->TabIndex = 1;
			this->txtNumX->TextChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::txtNumX_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 12);
			this->label4->TabIndex = 29;
			this->label4->Text = L"平滑度X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 66);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 12);
			this->label6->TabIndex = 31;
			this->label6->Text = L"平滑度Y";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->txtArrayDistance);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->txtArrayNumber);
			this->groupBox4->Controls->Add(this->cboArratDirection);
			this->groupBox4->Location = System::Drawing::Point(1, 188);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(335, 43);
			this->groupBox4->TabIndex = 40;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"陣列";
			// 
			// txtArrayDistance
			// 
			this->txtArrayDistance->Location = System::Drawing::Point(269, 18);
			this->txtArrayDistance->Name = L"txtArrayDistance";
			this->txtArrayDistance->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->txtArrayDistance->Size = System::Drawing::Size(45, 22);
			this->txtArrayDistance->TabIndex = 6;
			this->txtArrayDistance->TextChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::txtArrayDistance_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(210, 21);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 12);
			this->label11->TabIndex = 5;
			this->label11->Text = L"陣列間距";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(112, 21);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 12);
			this->label10->TabIndex = 4;
			this->label10->Text = L"陣列數";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 21);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 12);
			this->label9->TabIndex = 3;
			this->label9->Text = L"陣列方向";
			// 
			// txtArrayNumber
			// 
			this->txtArrayNumber->Location = System::Drawing::Point(159, 18);
			this->txtArrayNumber->Name = L"txtArrayNumber";
			this->txtArrayNumber->Size = System::Drawing::Size(48, 22);
			this->txtArrayNumber->TabIndex = 1;
			// 
			// cboArratDirection
			// 
			this->cboArratDirection->FormattingEnabled = true;
			this->cboArratDirection->Location = System::Drawing::Point(60, 18);
			this->cboArratDirection->Name = L"cboArratDirection";
			this->cboArratDirection->Size = System::Drawing::Size(46, 20);
			this->cboArratDirection->TabIndex = 0;
			this->cboArratDirection->SelectedIndexChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::cboArratDirection_SelectedIndexChanged);
			// 
			// tabDensity_ControllPt
			// 
			this->tabDensity_ControllPt->Controls->Add(this->tabControlPtDensity);
			this->tabDensity_ControllPt->Controls->Add(this->Pt_Weight);
			this->tabDensity_ControllPt->Controls->Add(this->tabControllPtX);
			this->tabDensity_ControllPt->Controls->Add(this->tabControllPtY);
			this->tabDensity_ControllPt->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tabDensity_ControllPt->Location = System::Drawing::Point(3, 237);
			this->tabDensity_ControllPt->Name = L"tabDensity_ControllPt";
			this->tabDensity_ControllPt->SelectedIndex = 0;
			this->tabDensity_ControllPt->Size = System::Drawing::Size(333, 233);
			this->tabDensity_ControllPt->TabIndex = 22;
			// 
			// tabControlPtDensity
			// 
			this->tabControlPtDensity->Controls->Add(this->dataGridView_ModifyPara);
			this->tabControlPtDensity->Location = System::Drawing::Point(4, 21);
			this->tabControlPtDensity->Name = L"tabControlPtDensity";
			this->tabControlPtDensity->Padding = System::Windows::Forms::Padding(3);
			this->tabControlPtDensity->Size = System::Drawing::Size(325, 208);
			this->tabControlPtDensity->TabIndex = 0;
			this->tabControlPtDensity->Text = L"縮放參數";
			this->tabControlPtDensity->UseVisualStyleBackColor = true;
			// 
			// dataGridView_ModifyPara
			// 
			this->dataGridView_ModifyPara->AllowUserToAddRows = false;
			this->dataGridView_ModifyPara->AllowUserToDeleteRows = false;
			this->dataGridView_ModifyPara->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_ModifyPara->ColumnHeadersVisible = false;
			this->dataGridView_ModifyPara->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->Column2, 
				this->Column3, this->Column4, this->Column5, this->Column6});
			this->dataGridView_ModifyPara->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_ModifyPara->Location = System::Drawing::Point(3, 3);
			this->dataGridView_ModifyPara->Name = L"dataGridView_ModifyPara";
			this->dataGridView_ModifyPara->RowHeadersVisible = false;
			this->dataGridView_ModifyPara->RowHeadersWidth = 8;
			this->dataGridView_ModifyPara->RowTemplate->Height = 24;
			this->dataGridView_ModifyPara->Size = System::Drawing::Size(319, 202);
			this->dataGridView_ModifyPara->TabIndex = 0;
			this->dataGridView_ModifyPara->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Cosmetic_LocalArea_Form::dataGridView_ModifyPara_KeyDown);
			// 
			// Column2
			// 
			this->Column2->FillWeight = 65;
			this->Column2->HeaderText = L"Column 1";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 65;
			// 
			// Column3
			// 
			this->Column3->FillWeight = 65;
			this->Column3->HeaderText = L"Column 2";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 65;
			// 
			// Column4
			// 
			this->Column4->FillWeight = 65;
			this->Column4->HeaderText = L"Column 3";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 65;
			// 
			// Column5
			// 
			this->Column5->FillWeight = 65;
			this->Column5->HeaderText = L"Column 4";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 65;
			// 
			// Column6
			// 
			this->Column6->FillWeight = 65;
			this->Column6->HeaderText = L"Column 5";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 65;
			// 
			// Pt_Weight
			// 
			this->Pt_Weight->Controls->Add(this->dataGridControllPtWeight);
			this->Pt_Weight->Location = System::Drawing::Point(4, 21);
			this->Pt_Weight->Name = L"Pt_Weight";
			this->Pt_Weight->Padding = System::Windows::Forms::Padding(3);
			this->Pt_Weight->Size = System::Drawing::Size(325, 208);
			this->Pt_Weight->TabIndex = 3;
			this->Pt_Weight->Text = L"控制點權重";
			this->Pt_Weight->UseVisualStyleBackColor = true;
			// 
			// dataGridControllPtWeight
			// 
			this->dataGridControllPtWeight->AllowUserToAddRows = false;
			this->dataGridControllPtWeight->AllowUserToDeleteRows = false;
			this->dataGridControllPtWeight->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridControllPtWeight->ColumnHeadersVisible = false;
			this->dataGridControllPtWeight->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn12, 
				this->dataGridViewTextBoxColumn13, this->dataGridViewTextBoxColumn14, this->dataGridViewTextBoxColumn15, this->dataGridViewTextBoxColumn16});
			this->dataGridControllPtWeight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridControllPtWeight->Location = System::Drawing::Point(3, 3);
			this->dataGridControllPtWeight->Name = L"dataGridControllPtWeight";
			this->dataGridControllPtWeight->RowHeadersVisible = false;
			this->dataGridControllPtWeight->RowHeadersWidth = 8;
			this->dataGridControllPtWeight->RowTemplate->Height = 24;
			this->dataGridControllPtWeight->Size = System::Drawing::Size(319, 202);
			this->dataGridControllPtWeight->TabIndex = 1;
			this->dataGridControllPtWeight->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Cosmetic_LocalArea_Form::dataGridControllPtWeight_KeyDown);
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->FillWeight = 65;
			this->dataGridViewTextBoxColumn12->HeaderText = L"Column 1";
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			this->dataGridViewTextBoxColumn12->Width = 65;
			// 
			// dataGridViewTextBoxColumn13
			// 
			this->dataGridViewTextBoxColumn13->FillWeight = 65;
			this->dataGridViewTextBoxColumn13->HeaderText = L"Column 2";
			this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
			this->dataGridViewTextBoxColumn13->Width = 65;
			// 
			// dataGridViewTextBoxColumn14
			// 
			this->dataGridViewTextBoxColumn14->FillWeight = 65;
			this->dataGridViewTextBoxColumn14->HeaderText = L"Column 3";
			this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
			this->dataGridViewTextBoxColumn14->Width = 65;
			// 
			// dataGridViewTextBoxColumn15
			// 
			this->dataGridViewTextBoxColumn15->FillWeight = 65;
			this->dataGridViewTextBoxColumn15->HeaderText = L"Column 4";
			this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
			this->dataGridViewTextBoxColumn15->Width = 65;
			// 
			// dataGridViewTextBoxColumn16
			// 
			this->dataGridViewTextBoxColumn16->FillWeight = 65;
			this->dataGridViewTextBoxColumn16->HeaderText = L"Column 5";
			this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
			this->dataGridViewTextBoxColumn16->Width = 65;
			// 
			// tabControllPtX
			// 
			this->tabControllPtX->Controls->Add(this->dataGrid_Cpt_X);
			this->tabControllPtX->Location = System::Drawing::Point(4, 21);
			this->tabControllPtX->Name = L"tabControllPtX";
			this->tabControllPtX->Padding = System::Windows::Forms::Padding(3);
			this->tabControllPtX->Size = System::Drawing::Size(325, 208);
			this->tabControllPtX->TabIndex = 4;
			this->tabControllPtX->Text = L"控制點位置 (X)";
			this->tabControllPtX->UseVisualStyleBackColor = true;
			this->tabControllPtX->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::tabControllPtX_Click);
			// 
			// dataGrid_Cpt_X
			// 
			this->dataGrid_Cpt_X->AllowUserToAddRows = false;
			this->dataGrid_Cpt_X->AllowUserToDeleteRows = false;
			this->dataGrid_Cpt_X->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_Cpt_X->ColumnHeadersVisible = false;
			this->dataGrid_Cpt_X->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn17, 
				this->dataGridViewTextBoxColumn18, this->dataGridViewTextBoxColumn19, this->dataGridViewTextBoxColumn20, this->dataGridViewTextBoxColumn21});
			this->dataGrid_Cpt_X->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid_Cpt_X->Location = System::Drawing::Point(3, 3);
			this->dataGrid_Cpt_X->Name = L"dataGrid_Cpt_X";
			this->dataGrid_Cpt_X->RowHeadersVisible = false;
			this->dataGrid_Cpt_X->RowHeadersWidth = 8;
			this->dataGrid_Cpt_X->RowTemplate->Height = 24;
			this->dataGrid_Cpt_X->Size = System::Drawing::Size(319, 202);
			this->dataGrid_Cpt_X->TabIndex = 2;
			this->dataGrid_Cpt_X->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Cosmetic_LocalArea_Form::dataGrid_Cpt_X_KeyDown);
			// 
			// dataGridViewTextBoxColumn17
			// 
			this->dataGridViewTextBoxColumn17->FillWeight = 65;
			this->dataGridViewTextBoxColumn17->HeaderText = L"Column 1";
			this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
			this->dataGridViewTextBoxColumn17->Width = 65;
			// 
			// dataGridViewTextBoxColumn18
			// 
			this->dataGridViewTextBoxColumn18->FillWeight = 65;
			this->dataGridViewTextBoxColumn18->HeaderText = L"Column 2";
			this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
			this->dataGridViewTextBoxColumn18->Width = 65;
			// 
			// dataGridViewTextBoxColumn19
			// 
			this->dataGridViewTextBoxColumn19->FillWeight = 65;
			this->dataGridViewTextBoxColumn19->HeaderText = L"Column 3";
			this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
			this->dataGridViewTextBoxColumn19->Width = 65;
			// 
			// dataGridViewTextBoxColumn20
			// 
			this->dataGridViewTextBoxColumn20->FillWeight = 65;
			this->dataGridViewTextBoxColumn20->HeaderText = L"Column 4";
			this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
			this->dataGridViewTextBoxColumn20->Width = 65;
			// 
			// dataGridViewTextBoxColumn21
			// 
			this->dataGridViewTextBoxColumn21->FillWeight = 65;
			this->dataGridViewTextBoxColumn21->HeaderText = L"Column 5";
			this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
			this->dataGridViewTextBoxColumn21->Width = 65;
			// 
			// tabControllPtY
			// 
			this->tabControllPtY->Controls->Add(this->dataGrid_Cpt_Y);
			this->tabControllPtY->Location = System::Drawing::Point(4, 21);
			this->tabControllPtY->Name = L"tabControllPtY";
			this->tabControllPtY->Padding = System::Windows::Forms::Padding(3);
			this->tabControllPtY->Size = System::Drawing::Size(325, 208);
			this->tabControllPtY->TabIndex = 5;
			this->tabControllPtY->Text = L"控制點位置(Y)";
			this->tabControllPtY->UseVisualStyleBackColor = true;
			// 
			// dataGrid_Cpt_Y
			// 
			this->dataGrid_Cpt_Y->AllowUserToAddRows = false;
			this->dataGrid_Cpt_Y->AllowUserToDeleteRows = false;
			this->dataGrid_Cpt_Y->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_Cpt_Y->ColumnHeadersVisible = false;
			this->dataGrid_Cpt_Y->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn22, 
				this->dataGridViewTextBoxColumn23, this->dataGridViewTextBoxColumn24, this->dataGridViewTextBoxColumn25, this->dataGridViewTextBoxColumn26});
			this->dataGrid_Cpt_Y->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid_Cpt_Y->Location = System::Drawing::Point(3, 3);
			this->dataGrid_Cpt_Y->Name = L"dataGrid_Cpt_Y";
			this->dataGrid_Cpt_Y->RowHeadersVisible = false;
			this->dataGrid_Cpt_Y->RowHeadersWidth = 8;
			this->dataGrid_Cpt_Y->RowTemplate->Height = 24;
			this->dataGrid_Cpt_Y->Size = System::Drawing::Size(319, 202);
			this->dataGrid_Cpt_Y->TabIndex = 2;
			this->dataGrid_Cpt_Y->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Cosmetic_LocalArea_Form::dataGrid_Cpt_Y_KeyDown);
			// 
			// dataGridViewTextBoxColumn22
			// 
			this->dataGridViewTextBoxColumn22->FillWeight = 65;
			this->dataGridViewTextBoxColumn22->HeaderText = L"Column 1";
			this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
			this->dataGridViewTextBoxColumn22->Width = 65;
			// 
			// dataGridViewTextBoxColumn23
			// 
			this->dataGridViewTextBoxColumn23->FillWeight = 65;
			this->dataGridViewTextBoxColumn23->HeaderText = L"Column 2";
			this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
			this->dataGridViewTextBoxColumn23->Width = 65;
			// 
			// dataGridViewTextBoxColumn24
			// 
			this->dataGridViewTextBoxColumn24->FillWeight = 65;
			this->dataGridViewTextBoxColumn24->HeaderText = L"Column 3";
			this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
			this->dataGridViewTextBoxColumn24->Width = 65;
			// 
			// dataGridViewTextBoxColumn25
			// 
			this->dataGridViewTextBoxColumn25->FillWeight = 65;
			this->dataGridViewTextBoxColumn25->HeaderText = L"Column 4";
			this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
			this->dataGridViewTextBoxColumn25->Width = 65;
			// 
			// dataGridViewTextBoxColumn26
			// 
			this->dataGridViewTextBoxColumn26->FillWeight = 65;
			this->dataGridViewTextBoxColumn26->HeaderText = L"Column 5";
			this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
			this->dataGridViewTextBoxColumn26->Width = 65;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txt_Area_Width);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->cboPointLocation);
			this->groupBox2->Controls->Add(this->txt_Area_Length);
			this->groupBox2->Controls->Add(this->txt_Y_Value);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->txt_X_Value);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(0, 11);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(335, 77);
			this->groupBox2->TabIndex = 39;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"區域範圍輸入方式";
			// 
			// txt_Area_Width
			// 
			this->txt_Area_Width->Location = System::Drawing::Point(147, 46);
			this->txt_Area_Width->Name = L"txt_Area_Width";
			this->txt_Area_Width->Size = System::Drawing::Size(58, 22);
			this->txt_Area_Width->TabIndex = 36;
			this->txt_Area_Width->TextChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::txt_Area_Width_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(234, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 12);
			this->label5->TabIndex = 34;
			this->label5->Text = L"Y :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(145, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 12);
			this->label1->TabIndex = 33;
			this->label1->Text = L"X :";
			// 
			// cboPointLocation
			// 
			this->cboPointLocation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPointLocation->FormattingEnabled = true;
			this->cboPointLocation->Location = System::Drawing::Point(29, 21);
			this->cboPointLocation->Name = L"cboPointLocation";
			this->cboPointLocation->Size = System::Drawing::Size(110, 20);
			this->cboPointLocation->TabIndex = 32;
			this->cboPointLocation->SelectedIndexChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::cboPointLocation_SelectedIndexChanged);
			// 
			// txt_Area_Length
			// 
			this->txt_Area_Length->Location = System::Drawing::Point(40, 46);
			this->txt_Area_Length->Name = L"txt_Area_Length";
			this->txt_Area_Length->Size = System::Drawing::Size(58, 22);
			this->txt_Area_Length->TabIndex = 35;
			this->txt_Area_Length->TextChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::txt_Area_Length_TextChanged);
			// 
			// txt_Y_Value
			// 
			this->txt_Y_Value->Location = System::Drawing::Point(257, 21);
			this->txt_Y_Value->Name = L"txt_Y_Value";
			this->txt_Y_Value->Size = System::Drawing::Size(58, 22);
			this->txt_Y_Value->TabIndex = 27;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(113, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 12);
			this->label3->TabIndex = 28;
			this->label3->Text = L"寬(Y)";
			// 
			// txt_X_Value
			// 
			this->txt_X_Value->Location = System::Drawing::Point(170, 21);
			this->txt_X_Value->Name = L"txt_X_Value";
			this->txt_X_Value->Size = System::Drawing::Size(58, 22);
			this->txt_X_Value->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 12);
			this->label2->TabIndex = 25;
			this->label2->Text = L"長(X)";
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(557, 445);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(72, 33);
			this->btnExit->TabIndex = 24;
			this->btnExit->Text = L"離開";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btnExit_Click);
			// 
			// btn_Accept
			// 
			this->btn_Accept->Location = System::Drawing::Point(463, 445);
			this->btn_Accept->Name = L"btn_Accept";
			this->btn_Accept->Size = System::Drawing::Size(72, 33);
			this->btn_Accept->TabIndex = 25;
			this->btn_Accept->Text = L"套用";
			this->btn_Accept->UseVisualStyleBackColor = true;
			this->btn_Accept->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btn_Accept_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(664, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(332, 171);
			this->pictureBox1->TabIndex = 26;
			this->pictureBox1->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(665, 9);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(101, 12);
			this->label12->TabIndex = 28;
			this->label12->Text = L"顯示半徑變化圖形";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label16);
			this->groupBox6->Controls->Add(this->cboCalRatioMethod);
			this->groupBox6->Controls->Add(this->btnCal);
			this->groupBox6->Controls->Add(this->tabControl1);
			this->groupBox6->Location = System::Drawing::Point(667, 204);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(332, 281);
			this->groupBox6->TabIndex = 29;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"結果";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(106, 251);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(101, 12);
			this->label16->TabIndex = 27;
			this->label16->Text = L"檢測縮放比例方式";
			// 
			// cboCalRatioMethod
			// 
			this->cboCalRatioMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboCalRatioMethod->FormattingEnabled = true;
			this->cboCalRatioMethod->Location = System::Drawing::Point(213, 248);
			this->cboCalRatioMethod->Name = L"cboCalRatioMethod";
			this->cboCalRatioMethod->Size = System::Drawing::Size(86, 20);
			this->cboCalRatioMethod->TabIndex = 26;
			// 
			// btnCal
			// 
			this->btnCal->Location = System::Drawing::Point(10, 241);
			this->btnCal->Name = L"btnCal";
			this->btnCal->Size = System::Drawing::Size(72, 33);
			this->btnCal->TabIndex = 25;
			this->btnCal->Text = L"計算";
			this->btnCal->UseVisualStyleBackColor = true;
			this->btnCal->Click += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::btnCal_Click_1);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tabControl1->Location = System::Drawing::Point(3, 18);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(326, 216);
			this->tabControl1->TabIndex = 23;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->dataGridView_Ratio);
			this->tabPage7->Location = System::Drawing::Point(4, 21);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(318, 191);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"實際縮放比例(直徑)";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Ratio
			// 
			this->dataGridView_Ratio->AllowUserToAddRows = false;
			this->dataGridView_Ratio->AllowUserToDeleteRows = false;
			this->dataGridView_Ratio->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Ratio->ColumnHeadersVisible = false;
			this->dataGridView_Ratio->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn45, 
				this->dataGridViewTextBoxColumn46, this->dataGridViewTextBoxColumn47, this->dataGridViewTextBoxColumn48, this->dataGridViewTextBoxColumn49});
			this->dataGridView_Ratio->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Ratio->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Ratio->Name = L"dataGridView_Ratio";
			this->dataGridView_Ratio->ReadOnly = true;
			this->dataGridView_Ratio->RowHeadersVisible = false;
			this->dataGridView_Ratio->RowHeadersWidth = 21;
			this->dataGridView_Ratio->RowTemplate->Height = 24;
			this->dataGridView_Ratio->Size = System::Drawing::Size(312, 185);
			this->dataGridView_Ratio->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn45
			// 
			this->dataGridViewTextBoxColumn45->FillWeight = 65;
			this->dataGridViewTextBoxColumn45->HeaderText = L"Column 1";
			this->dataGridViewTextBoxColumn45->Name = L"dataGridViewTextBoxColumn45";
			this->dataGridViewTextBoxColumn45->ReadOnly = true;
			this->dataGridViewTextBoxColumn45->Width = 65;
			// 
			// dataGridViewTextBoxColumn46
			// 
			this->dataGridViewTextBoxColumn46->FillWeight = 65;
			this->dataGridViewTextBoxColumn46->HeaderText = L"Column 2";
			this->dataGridViewTextBoxColumn46->Name = L"dataGridViewTextBoxColumn46";
			this->dataGridViewTextBoxColumn46->ReadOnly = true;
			this->dataGridViewTextBoxColumn46->Width = 65;
			// 
			// dataGridViewTextBoxColumn47
			// 
			this->dataGridViewTextBoxColumn47->FillWeight = 65;
			this->dataGridViewTextBoxColumn47->HeaderText = L"Column 3";
			this->dataGridViewTextBoxColumn47->Name = L"dataGridViewTextBoxColumn47";
			this->dataGridViewTextBoxColumn47->ReadOnly = true;
			this->dataGridViewTextBoxColumn47->Width = 65;
			// 
			// dataGridViewTextBoxColumn48
			// 
			this->dataGridViewTextBoxColumn48->FillWeight = 65;
			this->dataGridViewTextBoxColumn48->HeaderText = L"Column 4";
			this->dataGridViewTextBoxColumn48->Name = L"dataGridViewTextBoxColumn48";
			this->dataGridViewTextBoxColumn48->ReadOnly = true;
			this->dataGridViewTextBoxColumn48->Width = 65;
			// 
			// dataGridViewTextBoxColumn49
			// 
			this->dataGridViewTextBoxColumn49->FillWeight = 65;
			this->dataGridViewTextBoxColumn49->HeaderText = L"Column 5";
			this->dataGridViewTextBoxColumn49->Name = L"dataGridViewTextBoxColumn49";
			this->dataGridViewTextBoxColumn49->ReadOnly = true;
			this->dataGridViewTextBoxColumn49->Width = 65;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->dataGridView_Density);
			this->tabPage8->Location = System::Drawing::Point(4, 21);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(318, 191);
			this->tabPage8->TabIndex = 2;
			this->tabPage8->Text = L"網點覆蓋率";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Density
			// 
			this->dataGridView_Density->AllowUserToAddRows = false;
			this->dataGridView_Density->AllowUserToDeleteRows = false;
			this->dataGridView_Density->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Density->ColumnHeadersVisible = false;
			this->dataGridView_Density->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn50, 
				this->dataGridViewTextBoxColumn51, this->dataGridViewTextBoxColumn52, this->dataGridViewTextBoxColumn53, this->dataGridViewTextBoxColumn54});
			this->dataGridView_Density->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Density->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Density->Name = L"dataGridView_Density";
			this->dataGridView_Density->ReadOnly = true;
			this->dataGridView_Density->RowHeadersVisible = false;
			this->dataGridView_Density->RowHeadersWidth = 21;
			this->dataGridView_Density->RowTemplate->Height = 24;
			this->dataGridView_Density->Size = System::Drawing::Size(312, 185);
			this->dataGridView_Density->TabIndex = 2;
			// 
			// dataGridViewTextBoxColumn50
			// 
			this->dataGridViewTextBoxColumn50->FillWeight = 65;
			this->dataGridViewTextBoxColumn50->HeaderText = L"Column 1";
			this->dataGridViewTextBoxColumn50->Name = L"dataGridViewTextBoxColumn50";
			this->dataGridViewTextBoxColumn50->ReadOnly = true;
			this->dataGridViewTextBoxColumn50->Width = 65;
			// 
			// dataGridViewTextBoxColumn51
			// 
			this->dataGridViewTextBoxColumn51->FillWeight = 65;
			this->dataGridViewTextBoxColumn51->HeaderText = L"Column 2";
			this->dataGridViewTextBoxColumn51->Name = L"dataGridViewTextBoxColumn51";
			this->dataGridViewTextBoxColumn51->ReadOnly = true;
			this->dataGridViewTextBoxColumn51->Width = 65;
			// 
			// dataGridViewTextBoxColumn52
			// 
			this->dataGridViewTextBoxColumn52->FillWeight = 65;
			this->dataGridViewTextBoxColumn52->HeaderText = L"Column 3";
			this->dataGridViewTextBoxColumn52->Name = L"dataGridViewTextBoxColumn52";
			this->dataGridViewTextBoxColumn52->ReadOnly = true;
			this->dataGridViewTextBoxColumn52->Width = 65;
			// 
			// dataGridViewTextBoxColumn53
			// 
			this->dataGridViewTextBoxColumn53->FillWeight = 65;
			this->dataGridViewTextBoxColumn53->HeaderText = L"Column 4";
			this->dataGridViewTextBoxColumn53->Name = L"dataGridViewTextBoxColumn53";
			this->dataGridViewTextBoxColumn53->ReadOnly = true;
			this->dataGridViewTextBoxColumn53->Width = 65;
			// 
			// dataGridViewTextBoxColumn54
			// 
			this->dataGridViewTextBoxColumn54->FillWeight = 65;
			this->dataGridViewTextBoxColumn54->HeaderText = L"Column 5";
			this->dataGridViewTextBoxColumn54->Name = L"dataGridViewTextBoxColumn54";
			this->dataGridViewTextBoxColumn54->ReadOnly = true;
			this->dataGridViewTextBoxColumn54->Width = 65;
			// 
			// cboRadiusVariation
			// 
			this->cboRadiusVariation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRadiusVariation->FormattingEnabled = true;
			this->cboRadiusVariation->Location = System::Drawing::Point(772, 6);
			this->cboRadiusVariation->Name = L"cboRadiusVariation";
			this->cboRadiusVariation->Size = System::Drawing::Size(121, 20);
			this->cboRadiusVariation->TabIndex = 30;
			this->cboRadiusVariation->SelectedIndexChanged += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::cboRadiusVariation_SelectedIndexChanged);
			// 
			// Cosmetic_LocalArea_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1038, 490);
			this->Controls->Add(this->cboRadiusVariation);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_Accept);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Name = L"Cosmetic_LocalArea_Form";
			this->Text = L"Cosmetic_LocalArea_Form";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Cosmetic_LocalArea_Form::Cosmetic_LocalArea_Form_Load);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_History))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabDensity_ControllPt->ResumeLayout(false);
			this->tabControlPtDensity->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ModifyPara))->EndInit();
			this->Pt_Weight->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridControllPtWeight))->EndInit();
			this->tabControllPtX->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid_Cpt_X))->EndInit();
			this->tabControllPtY->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid_Cpt_Y))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Ratio))->EndInit();
			this->tabPage8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Density))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Cosmetic_LocalArea_Form_Load(System::Object^  sender, System::EventArgs^  e) {
			 


			 this->cboPointLocation->Items->Add("左下點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("左上點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("右上點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("右下點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("中心點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("左中點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("右中點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("上中點座標(X,Y) :");
			 this->cboPointLocation->Items->Add("下中點座標(X,Y) :");
			 this->cboPointLocation->SelectedIndex = 0;


			 //陣列功能
			 this->cboArratDirection->Items->Add("+X");
			 this->cboArratDirection->Items->Add("-X");
			 this->cboArratDirection->Items->Add("+Y");
			 this->cboArratDirection->Items->Add("-Y");
			 this->cboArratDirection->SelectedIndex = 0;

			 //平滑度
			  this->lbl_U_Value->Text = "平滑度X :" ;
			  this->lbl_V_Value->Text = "平滑度Y :" ;
			 this->hScrollBar_U_Value->Enabled = false;
			 this->hScrollBar_V_Value->Enabled = false;



			 //將陣列的數目顯示在表單上面
		

			 //顯示計算比例的方式 :
			 this->cboCalRatioMethod->Items->Add("等分點");
			 this->cboCalRatioMethod->Items->Add("實際座標點");
			 this->cboCalRatioMethod->SelectedIndex = 0;


			 //畫圖設定 :
			 this->cboRadiusVariation->Items->Add("顯示放大區域");
			 this->cboRadiusVariation->Items->Add("顯示縮小區域");
			 this->cboRadiusVariation->SelectedIndex = 0;


			

			
			 this->dataGridView_ModifyPara->RowCount::set(1);
			 this->dataGridView_ModifyPara->ColumnCount::set(1);
			 this->dataGridControllPtWeight->RowCount::set(1);
			 this->dataGridControllPtWeight->ColumnCount::set(1);
			 this->dataGrid_Cpt_X->RowCount::set(1);
			 this->dataGrid_Cpt_X->ColumnCount::set(1);
			 this->dataGrid_Cpt_Y->RowCount::set(1);
			 this->dataGrid_Cpt_Y->ColumnCount::set(1);


			 


			
			 
			 



			//此為ArrayList容器 ,在局部修改的Form中建立一個容器 .
			//然後將主表單中容器中儲存的資料轉到局部修改中的暫存容器
			
			tmplocalsurfacedata = gcnew ArrayList;

			if(this->Tolocalsurfacedata->Count != 0) {
				tmplocalsurfacedata->AddRange(this->Tolocalsurfacedata); 
			}

			//設定DataGrid_View History 
			this->dataGridView_History->RowCount::set(tmplocalsurfacedata->Count);

			for(int ii = 0 ; ii <tmplocalsurfacedata->Count ; ii++){

				//設定為不可Sort
				//this->dataGridView_History->Rows->default[ii]->SortMode::set(DataGridViewColumnSortMode::NotSortable);

				array<String^>^ tmp =(array<String^>^) tmplocalsurfacedata->default[ii];
				//顯示資料
				this->ShowData(tmp, ii);
			}




		 }
private: System::Void btnCal_Click(System::Object^  sender, System::EventArgs^  e) {

			


		 }
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {


			 bool ISDataOK = false;			

			

			 //將表單中KeyIn 的輸入參數轉到Array中
			  ISDataOK = this->DatatoArray(1);

			 if (ISDataOK == true){
				 //增加GridView RowCount (增加一列 ..)
				this->dataGridView_History->RowCount::set(this->dataGridView_History->RowCount + 1);
				 //顯示資料
				 this->ShowData(this->InputData, this->dataGridView_History->RowCount-1);
				 //將Array加到ArrayList
				 this->tmplocalsurfacedata->Add(this->InputData);
			 }
				
		

			


		 }

private: System::Void btn_Accept_Click(System::Object^  sender, System::EventArgs^  e) {




		
		

			Tolocalsurfacedata->RemoveRange(0,Tolocalsurfacedata->Count);
			Tolocalsurfacedata->AddRange(this->tmplocalsurfacedata );
/*
			 this->btn_Accept->Enabled = false;
			 B_Spline_Surface^ tmpLocalSurface;
			


			 //數值回覆到預設值
			  for(int i = 0 ;i <this->tmpDot->GetDotNumber() ; i++){				 
				 this->tmpDot->ModifyRate_LocalArea->SetValue(1.0f,i);
			 };



			 RectangleF LocalArea(0,0,0,0);

			 for(int kk =0 ; kk < this->dataGridView_History->RowCount ; kk ++){				 







					float LU_X   = this->tmpLGP.X + (float)this->dataGridView_History->default[1,kk]->Value;
					float LU_Y   = this->tmpLGP.Y + (float)this->dataGridView_History->default[2,kk]->Value;  
					float Length = (float)this->dataGridView_History->default[3,kk]->Value;
					float Width  = (float)this->dataGridView_History->default[4,kk]->Value;
					int U_Value  = Convert::ToInt16(this->dataGridView_History->default[5,kk]->Value);
					int V_Value  = Convert::ToInt16(this->dataGridView_History->default[6,kk]->Value);

					tmpLocalSurface = gcnew B_Spline_Surface();

	
	

					if(this->chkBoundarySmooth->Checked != true) {

						//(輸入參數為 控制點數目(>=3) ,平滑度(>=2),和解析度);
						 Point Cpt(5,5); Point Degree(U_Value,V_Value);Point Resolution(100,100);
						 tmpLocalSurface->CreateZeroSurface(Cpt,Degree,Resolution);

					//	tmpLocalSurface->ControllPt = gcnew array<PointF,2>(5,5);
					//	tmpLocalSurface->ControllPt_Z = gcnew array<float,2>(5,5);
					//	tmpLocalSurface->Weight = gcnew array<float,2>(5,5);

						 for(int ii = 0 ;ii< 5 ;ii++){

							 for(int jj = 0 ;jj < 5 ;jj++){
								 //Z 值輸入
								 float tmpV = (float)this->dataGridView_History->default[7+ii*5+jj,kk]->Value;
								 tmpLocalSurface->ControllPt_Z->SetValue(tmpV,ii,4-jj);//座標轉換!!! (4-jj)

							//	 PointF tmpPt(LU_X + Length*ii/4,LU_Y -Width*jj/4); //座標轉換!!! (-Width)
							//	 tmpLocalSurface->ControllPt->SetValue(tmpPt,ii,jj);
								   PointF tmpPt;
								 // 控制點輸入 
 
					
								  tmpPt.X = LU_X + (float)this->dataGridView_History->default[60+ii*5+jj,kk]->Value;
								  tmpPt.Y = LU_Y+(float)this->dataGridView_History->default[85+ii*5+jj,kk]->Value;
								 
								 tmpLocalSurface->ControllPt->SetValue(tmpPt,ii,4-jj);
								 //權重輸入
								 float tmpW = (float)this->dataGridView_History->default[35+ii*5+jj,kk]->Value;
								 tmpLocalSurface->Weight->SetValue(tmpW,ii,4-jj);//座標轉換!!! (4-jj)

							 }
						 }


					}else{

						/*(輸入參數為 控制點數目(>=3) ,平滑度(>=2),和解析度);*/
/*
						 Point Cpt(7,7); Point Degree(U_Value,V_Value);Point Resolution(100,100);
						 tmpLocalSurface->CreateZeroSurface(Cpt,Degree,Resolution);

					//	tmpLocalSurface->ControllPt = gcnew array<PointF,2>(7,7);
					//	tmpLocalSurface->ControllPt_Z = gcnew array<float,2>(7,7);
					//	tmpLocalSurface->Weight = gcnew array<float,2>(7,7);

						 for(int ii = 0 ;ii< 7 ;ii++){
							PointF tmpPt ;
							if(ii == 0) {
								 //平滑用的控制點
								tmpPt.X = LU_X-0.1;									 
							}else if(ii == 6){
								  //平滑用的控制點
								tmpPt.X = LU_X + Length + 0.1;																 
							}else{
								//我們輸入的控制點
								 tmpPt.X = LU_X + Length*(ii-1)/4;
							}

							 for(int jj = 0 ;jj < 7 ;jj++){

									 if(jj == 0){
										tmpPt.Y = LU_Y + 0.1;
										
									 }else if (jj == 6){
										tmpPt.Y = LU_Y -Width - 0.1;
										
									 }else{
										tmpPt.Y = LU_Y -Width*(jj-1)/4;
										
									 }

									 if(ii ==0 || ii ==6 || jj == 0 || jj == 6){
										tmpLocalSurface->ControllPt_Z->SetValue(0,ii,6-jj);//座標轉換!!! (6-jj)
										tmpLocalSurface->Weight->SetValue(100,ii,6-jj);//座標轉換!!! (6-jj)
									 }else{
										 float tmpV = (float)this->dataGridView_History->default[7+(ii-1)*5+(jj-1),kk]->Value;
										tmpLocalSurface->ControllPt_Z->SetValue(tmpV,ii,6-jj);//座標轉換!!! (6-jj)
										float tmpW = (float)this->dataGridView_History->default[35+(ii-1)*5+(jj-1),kk]->Value;
										tmpLocalSurface->Weight->SetValue(tmpW,ii,6-jj);//座標轉換!!! (6-jj)

									 }

									 tmpLocalSurface->ControllPt->SetValue(tmpPt,ii,jj);

											
								

							 }
						 }
						

*/
/*
					}



					tmpLocalSurface->ModifySurface_Resolution_Degree();

				//	tmpLocalSurface->Set_uv_Value( U_Value,V_Value);
				//	tmpLocalSurface->ProduceSurface(100,100);

					

					 //將計算結果加入
					 int arraynumber = Convert::ToInt16(this->dataGridView_History->default[33,kk]->Value);
					 int arrayDirection = Convert::ToInt16(this->dataGridView_History->default[32,kk]->Value);
					 float arrayDistance = Convert::ToSingle(this->dataGridView_History->default[34,kk]->Value);
									
				

					 for(int ll= 0 ;ll <this->tmpDot->GetDotNumber() ; ll++){
						 
						  PointF tmpCoor(0,0) ;
						  float tmpDia = 0;
						  this->tmpDot->GetDotValue(tmpCoor,tmpDia,ll) ;
						 
						 for(int mm = 0 ;mm < arraynumber  ; mm++){
							// RectangleF SurfaceBoundary(LU_X,LU_Y,Length,Width);
							 RectangleF SurfaceBoundary=tmpLocalSurface->SurfaceBoundary;

							
							 switch(arrayDirection){  //陣列方向
								 case 0: // +X
									 SurfaceBoundary.X = SurfaceBoundary.X + mm*arrayDistance ;
									 break;
								 case 1: // -X 
									  SurfaceBoundary.X = SurfaceBoundary.X -mm*arrayDistance ;
									 break;
								 case 2: // +Y
									  SurfaceBoundary.Y = SurfaceBoundary.Y -mm*arrayDistance ;
									 break;
								 case 3: // -Y
									  SurfaceBoundary.Y = SurfaceBoundary.Y +mm*arrayDistance ;
									 break;
							 }


							 if(tmpCoor.X >= SurfaceBoundary.X  && tmpCoor.X <= SurfaceBoundary.X+SurfaceBoundary.Width  && tmpCoor.Y >= SurfaceBoundary.Y  && tmpCoor.Y <=  SurfaceBoundary.Y+ SurfaceBoundary.Height ){
								  switch(arrayDirection){  //陣列方向
									  case 0:
										  tmpCoor.X = tmpCoor.X- mm*arrayDistance;
										  break;
									  case 1:
										  tmpCoor.X = tmpCoor.X+ mm*arrayDistance;
										  break;
									  case 2:
										  tmpCoor.Y = tmpCoor.Y+ mm*arrayDistance;  //Y座標有上下顛倒
										  break;
									  case 3:
										  tmpCoor.Y = tmpCoor.Y- mm*arrayDistance; //Y座標有上下顛倒
										  break;
								  }
								  float test = tmpLocalSurface->GetSurface_Z_Value(tmpCoor.X,tmpCoor.Y);
								  float Z_Value = 100+(float)tmpLocalSurface->GetSurface_Z_Value(tmpCoor.X,tmpCoor.Y);  
								  float predata = (float)this->tmpDot->ModifyRate_LocalArea->GetValue(ll);
								  if(Z_Value <0)  Z_Value = 0;							 
								 // this->tmpDotRatio->SetValue(predata*Z_Value/100,ll);
								  this->tmpDot->ModifyRate_LocalArea->SetValue(predata*Z_Value/100,ll);
							 }
						 }
					 }






				 
			 }

			 
			 
			 
			 
			 


			 //紀錄區域修改的輸入參數
			 
			 this->tmpLocalData->LocalArea_History_Data = gcnew array<float,2>(this->dataGridView_History->RowCount,this->dataGridView_History->ColumnCount);
			 for(int j = 0 ; j< this->dataGridView_History->ColumnCount ; j++){
				 for(int k = 0 ; k<this->dataGridView_History->RowCount ; k++){
					 float tmpV = (float)this->dataGridView_History->default[j,k]->Value;
					 this->tmpLocalData->LocalArea_History_Data->SetValue(tmpV,k,j);
				 }
			 }


			
				

			 this->btn_Accept->Enabled = true;
			
*/

		 }
private: System::Void btn_Delete_Click(System::Object^  sender, System::EventArgs^  e) {
			

			//取得目前作用中的Index 
		    int tmpindex =this->dataGridView_History->CurrentRow->Index;
			  


			if(tmpindex>=0){

				//移除歷史記錄中的資料
				 DataGridViewRowCollection^ rows2 = this->dataGridView_History->Rows;			 
				 rows2->RemoveAt(tmpindex);

				//移除ArrayList 中的資料
				 this->tmplocalsurfacedata->RemoveAt(tmpindex);
			}

			 




		 }

private: System::Void btn_Modify_Click(System::Object^  sender, System::EventArgs^  e) {

				bool ISDataOK = false;


				 //取得目前作用中的Index 
				int tmpindex =this->dataGridView_History->CurrentRow->Index;

				//做用中的資料,已經借由Mouse Click 傳到表單上面 .



				//將表單中KeyIn 的輸入參數轉到Array中 (修改後的)
				
				//將啟用或不啟用的數值輸入 
				
			//	MessageBox::Show(Convert::ToString(this->dataGridView_History->default[1,tmpindex]->Value))
				ISDataOK =  DatatoArray(0);
				
				if (ISDataOK == true){

					//取得目前作用中資料指標
					array<String^,1>^ tmpData =(array<String^,1>^) this->tmplocalsurfacedata->default[tmpindex];

					if ( tmpData->Length != this->InputData->Length){
						//Resize 後 ,會產生一個新的Array ,所以沒有和 tmplocalsurfacedata link 在一起
						Array::Resize(tmpData ,this->InputData->Length);					
						this->tmplocalsurfacedata->RemoveAt(tmpindex);
						this->tmplocalsurfacedata->Insert(tmpindex,this->InputData);
					}else{
						
						this->InputData->CopyTo(tmpData,0);

					}

					 //顯示資料
					//for(int ii = 0 ;ii < this->dataGridView_History->RowCount ; ii ++){
						this->ShowData(this->InputData, tmpindex);
					//}
				 }


		 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 this->Hide();
			 this->Close();

		 }
private: System::Void dataGridView_History_RowsRemoved(System::Object^  sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^  e) {
			 if(this->dataGridView_History->RowCount == 0) {
				 this->btn_Delete->Enabled = false;
				 this->btn_Modify->Enabled = false;
			 }
		 }
private: System::Void dataGridView_History_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) {
			if(this->dataGridView_History->RowCount > 0) {
				 this->btn_Delete->Enabled = true;
				 this->btn_Modify->Enabled = true;
			 }
		 }
private: System::Void dataGridView_History_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

//滑鼠點選 歷史資料的時候 ,將this->dataGridView_History(右邊介面) 的數值傳到修改介面上(左邊的介面)







			 DataGridViewRow^ rows =this->dataGridView_History->CurrentRow;
				int tmpindex = rows->Index;
				this->ArraytoData(this->tmplocalsurfacedata,tmpindex);



				//有啟用或非啟用Icon 
				/*

			DataGridViewCell^ cell = this->dataGridView_History->CurrentCell;
			
			if(cell->ColumnIndex == 1){
				
				if(	Convert::ToInt32(cell->Value) == 1){
					this->dataGridView_History->default[1,tmpindex]->Value = 0 ;							
				}
				else{
					this->dataGridView_History->default[1,tmpindex]->Value = 1;									
				}
				

			}
			*/



		 }

private: System::Void dataGridView_History_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			
		 }
private: System::Void btn_Werght_OK_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void dataGridView_ModifyPara_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->Control == true && e->KeyCode == Keys::V ){
				
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView_ModifyPara->ColumnCount;
				  MaxIndex.Y = this->dataGridView_ModifyPara->RowCount;


				  DataGridViewCell^ currentCell = this->dataGridView_ModifyPara->CurrentCell;
				  if (currentCell->Selected == true){
					  Index_Cell.X = currentCell->ColumnIndex;
					  Index_Cell.Y = currentCell->RowIndex;						
				  }
				  				

				  if (test2 == true){
					
					  String^ sss = Clipboard::GetText();
					  array<String^,1>^ Separate1 = sss->Split('\n');
					  //Separate1 是Row
					  for(int ii = 0 ; ii < Separate1->Length ; ii++){
						  String^ tmpSep = Convert::ToString(Separate1->GetValue(ii));
						  array<String^,1>^ Separate2  =  tmpSep->Split('	');
						  for(int jj =0 ;jj < Separate2->Length ;jj++){
							   String^ tmpSep2 = Convert::ToString(Separate2->GetValue(jj));
							   if( Index_Cell.X+jj <MaxIndex.X && Index_Cell.Y+ii < MaxIndex.Y)
								this->dataGridView_ModifyPara->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }
		 }
private: System::Void dataGridControllPtWeight_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if(e->Control == true && e->KeyCode == Keys::V ){
				// MessageBox::Show("貼上") ;
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView_ModifyPara->ColumnCount;
				  MaxIndex.Y = this->dataGridView_ModifyPara->RowCount;


				  DataGridViewCell^ currentCell = this->dataGridControllPtWeight->CurrentCell;
				  if (currentCell->Selected == true){
					  Index_Cell.X = currentCell->ColumnIndex;
					  Index_Cell.Y = currentCell->RowIndex;						
				  }
				  				

				  if (test2 == true){
					
					  String^ sss = Clipboard::GetText();
					  array<String^,1>^ Separate1 = sss->Split('\n');
					  //Separate1 是Row
					  for(int ii = 0 ; ii < Separate1->Length ; ii++){
						  String^ tmpSep = Convert::ToString(Separate1->GetValue(ii));
						  array<String^,1>^ Separate2  =  tmpSep->Split('	');
						  for(int jj =0 ;jj < Separate2->Length ;jj++){
							   String^ tmpSep2 = Convert::ToString(Separate2->GetValue(jj));
							   if( Index_Cell.X+jj <MaxIndex.X && Index_Cell.Y+ii < MaxIndex.Y)
								this->dataGridControllPtWeight->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }
		 }


		 
private: System::Void chkBoundarySmooth_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabControllPtX_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnCpt_X_Click(System::Object^  sender, System::EventArgs^  e) {

			 /*

		 if(this->txt_Area_Length->Text != ""){
			 for(int ii= 0 ; ii< ; ii++){	
				 float X = Convert::ToSingle(this->txt_Area_Length->Text) * ii/(4);
				  for(int jj= 0 ; jj<5 ; jj++){						
					  this->dataGrid_Cpt_X->default[ii,jj]->Value = X;
				  }
			}
		 }

			*/



			 

			 
		 }
private: System::Void btn_Cpt_Y_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(this->txt_Area_Width->Text != ""){
				for(int ii= 0 ; ii<5 ; ii++){					
					  for(int jj= 0 ; jj<5 ; jj++){	
						//  float Y = Convert::ToSingle(this->txt_Area_Width->Text)  * (jj)/(4); 
						  float Y = Convert::ToSingle(this->txt_Area_Width->Text)  * (4 - jj)/(4); 
						  this->dataGrid_Cpt_Y->default[ii,jj]->Value = Y;
					  }
				}
			 }
		 }
private: System::Void dataGrid_Cpt_X_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			  if(e->Control == true && e->KeyCode == Keys::V ){
				// MessageBox::Show("貼上") ;
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGrid_Cpt_X->ColumnCount;
				  MaxIndex.Y = this->dataGrid_Cpt_X->RowCount;


				  DataGridViewCell^ currentCell = this->dataGrid_Cpt_X->CurrentCell;
				  if (currentCell->Selected == true){
					  Index_Cell.X = currentCell->ColumnIndex;
					  Index_Cell.Y = currentCell->RowIndex;						
				  }
				  				

				  if (test2 == true){
					
					  String^ sss = Clipboard::GetText();
					  array<String^,1>^ Separate1 = sss->Split('\n');
					  //Separate1 是Row
					  for(int ii = 0 ; ii < Separate1->Length ; ii++){
						  String^ tmpSep = Convert::ToString(Separate1->GetValue(ii));
						  array<String^,1>^ Separate2  =  tmpSep->Split('	');
						  for(int jj =0 ;jj < Separate2->Length ;jj++){
							   String^ tmpSep2 = Convert::ToString(Separate2->GetValue(jj));
							   if( Index_Cell.X+jj <MaxIndex.X && Index_Cell.Y+ii < MaxIndex.Y)
								this->dataGrid_Cpt_X->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }


		 }
private: System::Void dataGrid_Cpt_Y_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			  if(e->Control == true && e->KeyCode == Keys::V ){
				// MessageBox::Show("貼上") ;
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGrid_Cpt_Y->ColumnCount;
				  MaxIndex.Y = this->dataGrid_Cpt_Y->RowCount;


				  DataGridViewCell^ currentCell = this->dataGrid_Cpt_Y->CurrentCell;
				  if (currentCell->Selected == true){
					  Index_Cell.X = currentCell->ColumnIndex;
					  Index_Cell.Y = currentCell->RowIndex;						
				  }
				  				

				  if (test2 == true){
					
					  String^ sss = Clipboard::GetText();
					  array<String^,1>^ Separate1 = sss->Split('\n');
					  //Separate1 是Row
					  for(int ii = 0 ; ii < Separate1->Length ; ii++){
						  String^ tmpSep = Convert::ToString(Separate1->GetValue(ii));
						  array<String^,1>^ Separate2  =  tmpSep->Split('	');
						  for(int jj =0 ;jj < Separate2->Length ;jj++){
							   String^ tmpSep2 = Convert::ToString(Separate2->GetValue(jj));
							   if( Index_Cell.X+jj <MaxIndex.X && Index_Cell.Y+ii < MaxIndex.Y)
								this->dataGrid_Cpt_Y->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }




		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			for(int ii= 0 ; ii<5 ; ii++){					
				  for(int jj= 0 ; jj<5 ; jj++){	
					//  float Y = Convert::ToSingle(this->txt_Area_Width->Text)  * (jj)/(4); 					
					  this->dataGridControllPtWeight->default[ii,jj]->Value = 1.0f;
				  }
			}
		 }
private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cboPointLocation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtNumX_TextChanged(System::Object^  sender, System::EventArgs^  e) {




			 int Num_X = 0; int Num_Y = 0;
			 if(txtNumX->Text != "") Num_X = Convert::ToInt16(txtNumX->Text);
			 if(txtNumY->Text != "") Num_Y = Convert::ToInt16(txtNumY->Text);

		
			 this->dataGridView_ModifyPara->ColumnCount::set(Num_X);			
			 this->dataGridControllPtWeight->ColumnCount::set(Num_X);			
			 this->dataGrid_Cpt_X->ColumnCount::set(Num_X);			
			 this->dataGrid_Cpt_Y->ColumnCount::set(Num_X);
			 this->hScrollBar_U_Value->Maximum = Num_X;

			 


			 if(Num_X >= 2 && Num_Y >= 2){
				 PointF coordinate;
				 float X = Convert::ToSingle(this->txt_Area_Length->Text);
				 float Y = Convert::ToSingle(this->txt_Area_Width->Text);
				 

				 for(int ii = 0 ; ii < Num_X ; ii++){
					
					 coordinate.X = ii*X/(Num_X-1);

					 for(int jj = 0 ; jj < Num_Y ; jj ++){
						 coordinate.Y = (Num_Y-jj-1)*Y/(Num_Y-1);
						
						  this->dataGrid_Cpt_X->default[ii,jj]->Value = coordinate.X;
						  this->dataGrid_Cpt_Y->default[ii,jj]->Value = coordinate.Y;
						  if(this->dataGridControllPtWeight->default[ii,jj]->Value == nullptr)
							this->dataGridControllPtWeight->default[ii,jj]->Value = 1.0f;
						  if(this->dataGridView_ModifyPara->default[ii,jj]->Value == nullptr)
							this->dataGridView_ModifyPara->default[ii,jj]->Value = 0.0f;

					 }
				 }

				 this->hScrollBar_U_Value->Enabled = true;	
				 this->hScrollBar_V_Value->Enabled = true;	

			 }else{
				 this->hScrollBar_U_Value->Enabled = false;	
				 this->hScrollBar_V_Value->Enabled = false;	
			 }








		 }
private: System::Void txtNumY_TextChanged(System::Object^  sender, System::EventArgs^  e) {



			 int Num_X = 0; int Num_Y = 0;
			 if(txtNumX->Text != "") Num_X = Convert::ToInt16(txtNumX->Text);
			 if(txtNumY->Text != "") Num_Y = Convert::ToInt16(txtNumY->Text);


			this->dataGridView_ModifyPara->RowCount::set(Num_Y);		
			 this->dataGridControllPtWeight->RowCount::set(Num_Y);			
			 this->dataGrid_Cpt_X->RowCount::set(Num_Y);			
			 this->dataGrid_Cpt_Y->RowCount::set(Num_Y);
			 this->hScrollBar_V_Value->Maximum = Num_Y;
			

			 if(Num_X >= 2 && Num_Y >= 2){
				 PointF coordinate;
				  float X = Convert::ToSingle(this->txt_Area_Length->Text);
				 float Y = Convert::ToSingle(this->txt_Area_Width->Text);
				 

				 for(int ii = 0 ; ii < Num_X ; ii++){
					
					 coordinate.X = ii*X/(Num_X-1);

					 for(int jj = 0 ; jj < Num_Y ; jj ++){
						 coordinate.Y = (Num_Y-jj-1)*Y/(Num_Y-1);
						
						  this->dataGrid_Cpt_X->default[ii,jj]->Value = coordinate.X;
						  this->dataGrid_Cpt_Y->default[ii,jj]->Value = coordinate.Y;
						  if(this->dataGridControllPtWeight->default[ii,jj]->Value == nullptr)
							this->dataGridControllPtWeight->default[ii,jj]->Value = 1.0f;
						  if(this->dataGridView_ModifyPara->default[ii,jj]->Value == nullptr)
							this->dataGridView_ModifyPara->default[ii,jj]->Value = 0.0f;

					 }
				 }

				 this->hScrollBar_V_Value->Enabled = true;
				 this->hScrollBar_U_Value->Enabled = true;
				 
			 }else{
				this->hScrollBar_V_Value->Enabled = false;
				this->hScrollBar_U_Value->Enabled = false;
			 }


		


		 }
private: System::Void cboArratDirection_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnCal_Click_1(System::Object^  sender, System::EventArgs^  e) {

			 
			//
			
			
			if(this->dataGridView_History->RowCount <= 0) return; 



						
			B_Spline_Surface^ tmpLocalSurface;
			tmpLocalSurface = gcnew B_Spline_Surface();


		

			DataGridViewRow^ rows =this->dataGridView_History->CurrentRow;
			int tmpindex = rows->Index;

			array<String^,1>^ tmpData = (array<String^,1>^)this->tmplocalsurfacedata->default[tmpindex];
			array<String^>^ tmpsurfaceData = this->ToSurfaceInputData(tmpData);
			PointF Area(Convert::ToSingle(tmpData[4]),Convert::ToSingle(tmpData[5])) ;   //局部修改區域的長和寬
				
				 
			//	Point Cpt(5,5); Point Degree(2,2);Point Resolution(100,100);
			
				tmpLocalSurface->SaveSurfaceData(tmpsurfaceData);
				tmpLocalSurface->ModifySurface_Resolution_Degree();

				//設定DataGirdViewDensity 和 直徑比例  的Row Count 和 Column Count:
				this->dataGridView_Density->RowCount::set(Convert::ToInt16(tmpData[13]));
				this->dataGridView_Density->ColumnCount::set(Convert::ToInt16(tmpData[12]));

				this->dataGridView_Ratio->RowCount::set(Convert::ToInt16(tmpData[13]));
				this->dataGridView_Ratio->ColumnCount::set(Convert::ToInt16(tmpData[12]));


				//轉換到絕對座標

				float shiftX = 0  ;
				float shiftY = 0  ;

				switch  (Convert::ToInt16(tmpData[1])){
					case 0: //"左下點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2]) ;
						shiftY = Convert::ToSingle(tmpData[3]) ;
											
						break;
					case 1: //"左上點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  ;
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5]);
						
						break;
					case 2: //"右上點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4]);
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5]);
						
						break;
					case 3: //"右下點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4]);
						shiftY = Convert::ToSingle(tmpData[3])  ;

						break;
					case 4: //"中心點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4])/2;
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5])/2;

						break;
					case 5: //"左中點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  ;
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5])/2;

						break;
					case 6: //"右中點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4]);
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5])/2;

						break;
					case 7: //"上中點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4])/2;
						shiftY = Convert::ToSingle(tmpData[3])  - Convert::ToSingle(tmpData[5]);

						break;
					case 8: //"下中點座標(X,Y) :"
						shiftX = Convert::ToSingle(tmpData[2])  - Convert::ToSingle(tmpData[4])/2;
						shiftY = Convert::ToSingle(tmpData[3])  ;

						break;
				}









				//計算縮放比例和密度
				for(int ii =0 ;ii <tmpLocalSurface->GetControllPtNumber().X ;ii ++){
					for(int jj = 0 ; jj <tmpLocalSurface->GetControllPtNumber().Y ; jj++){
						PointF coordinate ;
						float InputZ_Value;
						float tmpWeight;
						float Z_Value;
						float Den;
						
						tmpLocalSurface->GetControllPt_Data(coordinate,InputZ_Value,tmpWeight,Point(ii,jj));

						//等分點 ~~
						if (this->cboCalRatioMethod->SelectedIndex == 0){
								coordinate.X =ii* Area.X/(tmpLocalSurface->GetControllPtNumber().X-1);
								coordinate.Y =jj* Area.Y/(tmpLocalSurface->GetControllPtNumber().Y-1);
						}

						Z_Value = tmpLocalSurface->GetSurface_Z_Value(coordinate.X,coordinate.Y);

						//轉換到LGP 上真實的座標 ,並且由座標抓取密度數值 .
						PointF tmp_coordinate ;
						tmp_coordinate.X = shiftX + coordinate.X ;
						tmp_coordinate.Y = shiftY + coordinate.Y ;
					
						if(this->tmpDen != nullptr) {
							this->dataGridView_Density->Enabled = true;
							Den = this->tmpDen->GetDensityValue(tmp_coordinate);
							if(Den <0 ) Den = 0;
							this->dataGridView_Density->default[ii,tmpLocalSurface->GetControllPtNumber().Y-1-jj]->Value = Den*(1+Z_Value/100)*(1+Z_Value/100);
						}else{
							this->dataGridView_Density->Enabled = false;
						}
						
						this->dataGridView_Ratio->default[ii,tmpLocalSurface->GetControllPtNumber().Y-1-jj]->Value = 1+Z_Value/100;
						
						
					}
				}

				 
					



				//顯示顏色
				DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();
				Graphics^ test1 = this->pictureBox1->CreateGraphics();
				Metafile^ Metafile1;

				Draw1->PageRange = test1->VisibleClipBounds;
				Draw1->CreatePageSurface(tmpLocalSurface ,true ,Point(100,100));
				if(this->cboRadiusVariation->SelectedIndex == 0) {
					Metafile1 = Draw1->DrawPageSurface(PointF(100,0),test1,true,false,true,false);
				}else {
					Metafile1 = Draw1->DrawPageSurface(PointF(100,0),test1,true,false,true,true);
				}
				delete test1;

				float ratioX = this->pictureBox1->Width/Convert::ToSingle(tmpData[4]);
				float ratioY = this->pictureBox1->Height/Convert::ToSingle(tmpData[5]);


				Graphics^ temp = this->pictureBox1->CreateGraphics();
				temp->Clear(Color::Black);
				if (ratioX >= ratioY ){
					temp->DrawImage(Metafile1,((float)this->pictureBox1->Width-Convert::ToSingle(tmpData[4])*ratioY)/2,0.0f,Convert::ToSingle(tmpData[4])*ratioY,(float)this->pictureBox1->Height);
				}else{
					temp->DrawImage(Metafile1,0.0f,((float)this->pictureBox1->Height-Convert::ToSingle(tmpData[5])*ratioX)/2,(float)this->pictureBox1->Width,Convert::ToSingle(tmpData[5])*ratioX);
				}
		
		
		

			


			//	 }catch(...){
			//		 MessageBox::Show("計算錯誤");
			//	 }

			//   }else{
			//	    MessageBox::Show("資料輸入錯誤");

			//	 }

			





		 }
private: System::Void hScrollBar_U_Value_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			 this->lbl_U_Value->Text = "平滑度X :" + Convert::ToString(this->hScrollBar_U_Value->Value);

		 }
private: System::Void hScrollBar_V_Value_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {

			  this->lbl_V_Value->Text = "平滑度Y :" + Convert::ToString(this->hScrollBar_V_Value->Value);
		 }
private: System::Void txtArrayDistance_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txt_Area_Length_TextChanged(System::Object^  sender, System::EventArgs^  e) {



			 int Num_X = 0; int Num_Y = 0;
			 if(txtNumX->Text != "") Num_X = Convert::ToInt16(txtNumX->Text);
			 if(txtNumY->Text != "") Num_Y = Convert::ToInt16(txtNumY->Text);

		
			 this->dataGridView_ModifyPara->ColumnCount::set(Num_X);			
			 this->dataGridControllPtWeight->ColumnCount::set(Num_X);			
			 this->dataGrid_Cpt_X->ColumnCount::set(Num_X);			
			 this->dataGrid_Cpt_Y->ColumnCount::set(Num_X);
			// this->hScrollBar_U_Value->Maximum = Num_X;

			 


			 if(Num_X >= 2 && Num_Y >= 2){
				 PointF coordinate;
				 float X = Convert::ToSingle(this->txt_Area_Length->Text);
				// float Y = Convert::ToSingle(this->txt_Area_Width->Text);
				 

				 for(int ii = 0 ; ii < Num_X ; ii++){
					
					 coordinate.X = ii*X/(Num_X-1);

					 for(int jj = 0 ; jj < Num_Y ; jj ++){
					//	 coordinate.Y = (Num_Y-jj-1)*Y/(Num_Y-1);
						
						  this->dataGrid_Cpt_X->default[ii,jj]->Value = coordinate.X;
						//  this->dataGrid_Cpt_Y->default[ii,jj]->Value = coordinate.Y;
						//  this->dataGridControllPtWeight->default[ii,jj]->Value = 1.0f;
						//  this->dataGridView_ModifyPara->default[ii,jj]->Value = 0.0f;

					 }
				 }

				
				 

			//	 this->hScrollBar_U_Value->Enabled = true;	
			//	 this->hScrollBar_V_Value->Enabled = true;	

				 this->tabDensity_ControllPt->SelectedIndex::set(2);
				 this->txt_Area_Length->Focus();

			 }else{
			//	 this->hScrollBar_U_Value->Enabled = false;	
			//	 this->hScrollBar_V_Value->Enabled = false;	
			 }





		 }
private: System::Void txt_Area_Width_TextChanged(System::Object^  sender, System::EventArgs^  e) {


			 int Num_X = 0; int Num_Y = 0;
			 if(txtNumX->Text != "") Num_X = Convert::ToInt16(txtNumX->Text);
			 if(txtNumY->Text != "") Num_Y = Convert::ToInt16(txtNumY->Text);


			this->dataGridView_ModifyPara->RowCount::set(Num_Y);		
			 this->dataGridControllPtWeight->RowCount::set(Num_Y);			
			 this->dataGrid_Cpt_X->RowCount::set(Num_Y);			
			 this->dataGrid_Cpt_Y->RowCount::set(Num_Y);
			// this->hScrollBar_V_Value->Maximum = Num_Y;
			

			 if(Num_X >= 2 && Num_Y >= 2){
				 PointF coordinate;
				  float X = Convert::ToSingle(this->txt_Area_Length->Text);
				 float Y = Convert::ToSingle(this->txt_Area_Width->Text);
				 

				 for(int ii = 0 ; ii < Num_X ; ii++){
					
					 coordinate.X = ii*X/(Num_X-1);

					 for(int jj = 0 ; jj < Num_Y ; jj ++){
						 coordinate.Y = (Num_Y-jj-1)*Y/(Num_Y-1);
						
						//  this->dataGrid_Cpt_X->default[ii,jj]->Value = coordinate.X;
						  this->dataGrid_Cpt_Y->default[ii,jj]->Value = coordinate.Y;
						 // this->dataGridControllPtWeight->default[ii,jj]->Value = 1.0f;
						 // this->dataGridView_ModifyPara->default[ii,jj]->Value = 0.0f;

					 }
				 }

				// this->hScrollBar_V_Value->Enabled = true;
				// this->hScrollBar_U_Value->Enabled = true;
				this->tabDensity_ControllPt->SelectedIndex::set(3);
				this->txt_Area_Width->Focus();
				
				 
			 }else{
				//this->hScrollBar_V_Value->Enabled = false;
				//this->hScrollBar_U_Value->Enabled = false;
			 }





		 }
private: System::Void cboRadiusVariation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {






		 }
private: System::Void txtSurfaceName_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


			 //限制下面的字元 ,不得使用在名字輸入上
			if( e->KeyChar == '_' || e->KeyChar == '$' ||e->KeyChar == ','|| e->KeyChar == '}' || e->KeyChar == '{' ){
				e->Handled = true;				
			 }
			 			
		 }

};
}
