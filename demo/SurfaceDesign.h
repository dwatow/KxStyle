#pragma once

//#include "B-Spline.h"

using namespace Nurbs;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//MemoryStream 用到
using namespace System::IO;
//Metafile 用到
using namespace System::Drawing::Imaging;
using namespace DrawModule;




namespace PatternContruction {

	/// <summary>
	/// SurfaceDesign 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>

	
	public ref class SurfaceDesign : public System::Windows::Forms::Form
	{
		

	public:
		SurfaceDesign(float PlateWidth ,float PlateHeight )
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			this->PlateWidth = PlateWidth;
			this->PlateHeight = PlateHeight;
			Accept = false;
			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~SurfaceDesign()
		{
			if (components)
			{
				delete components;
			}
		}
	

	protected: 





	private: System::Windows::Forms::GroupBox^  groupBox1;































	protected: 



	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		//圖形畫在記憶體中
		MemoryStream^ MemoryStream_DesignDensity;
		Metafile^ Metafile_DesignDensity;
		Graphics^ SurfaceDensity;
		float PlateWidth;
		float PlateHeight;
		//圖形處理~~
		Metafile^ Metafile1;
		
		
		
		

	public:
		B_Spline_Surface^ Uni_Surface;
		bool Accept ;


	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::DataGridView^  dataGridView4;

















private: System::Windows::Forms::SplitContainer^  splitContainer1;
private: System::Windows::Forms::PictureBox^  pic_SurfaceDesign;
























private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripProgressBar^  ProgressBar;
private: System::Windows::Forms::ToolStripStatusLabel^  Statuslbl;
private: System::Windows::Forms::Button^  btn;
private: System::Windows::Forms::Button^  btnExit;
private: System::Windows::Forms::TabControl^  tabDensity_ControllPt;
private: System::Windows::Forms::TabPage^  tabControlPtDensity;
private: System::Windows::Forms::DataGridView^  dataGridView_ActualDesign_Density;
private: System::Windows::Forms::TabPage^  tab13Pt;
private: System::Windows::Forms::DataGridView^  dataGridView_Custom;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Custom_X;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Customed_Y;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Customed_Result;



























private: System::Windows::Forms::Button^  btnApply;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
private: System::Windows::Forms::SplitContainer^  splitContainer2;
private: System::Windows::Forms::SplitContainer^  splitContainer4;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::NumericUpDown^  num_VValue;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  txt_V_Resolution;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::NumericUpDown^  num_UValue;
private: System::Windows::Forms::TextBox^  txt_H_Resolution;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  txtV_Controll_Num;
private: System::Windows::Forms::TextBox^  txtH_Controll_Num;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::SplitContainer^  splitContainer3;
private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::DataGridView^  dataGridView1;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::DataGridView^  dataGridView_X_Location;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::DataGridView^  dataGridView_Y_Location;
private: System::Windows::Forms::TabPage^  tabWeight;
private: System::Windows::Forms::DataGridView^  dataGridView_Weight;
private: System::Windows::Forms::Button^  btn_Default_Pos;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::SplitContainer^  splitContainer5;
private: System::Windows::Forms::Label^  lbl_SelectedIndex;




















			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		void Build_DataGrid();
	//	void DrawSurface();
	//	void DrawSurface1214();
	
		void SetDensityColor(float &density ,float &R ,float &G ,float &B);
		void SetDataGridRow_Column(Point Number);
	
		///
		/// </summary>
		
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pic_SurfaceDesign = (gcnew System::Windows::Forms::PictureBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->num_VValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_V_Resolution = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->num_UValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->txt_H_Resolution = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtV_Controll_Num = (gcnew System::Windows::Forms::TextBox());
			this->txtH_Controll_Num = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_X_Location = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Y_Location = (gcnew System::Windows::Forms::DataGridView());
			this->tabWeight = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Weight = (gcnew System::Windows::Forms::DataGridView());
			this->btn_Default_Pos = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer5 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabDensity_ControllPt = (gcnew System::Windows::Forms::TabControl());
			this->tabControlPtDensity = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_ActualDesign_Density = (gcnew System::Windows::Forms::DataGridView());
			this->tab13Pt = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_Custom = (gcnew System::Windows::Forms::DataGridView());
			this->Custom_X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Customed_Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Customed_Result = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_SelectedIndex = (gcnew System::Windows::Forms::Label());
			this->btnApply = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->ProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->Statuslbl = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->btn = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_SurfaceDesign))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_VValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_UValue))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_X_Location))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Y_Location))->BeginInit();
			this->tabWeight->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Weight))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->splitContainer5->Panel1->SuspendLayout();
			this->splitContainer5->Panel2->SuspendLayout();
			this->splitContainer5->SuspendLayout();
			this->tabDensity_ControllPt->SuspendLayout();
			this->tabControlPtDensity->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ActualDesign_Density))->BeginInit();
			this->tab13Pt->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Custom))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->BeginInit();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->splitContainer1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(912, 507);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 18);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->pic_SurfaceDesign);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(906, 486);
			this->splitContainer1->SplitterDistance = 501;
			this->splitContainer1->TabIndex = 20;
			// 
			// pic_SurfaceDesign
			// 
			this->pic_SurfaceDesign->BackColor = System::Drawing::Color::Black;
			this->pic_SurfaceDesign->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pic_SurfaceDesign->Location = System::Drawing::Point(0, 0);
			this->pic_SurfaceDesign->Name = L"pic_SurfaceDesign";
			this->pic_SurfaceDesign->Size = System::Drawing::Size(501, 486);
			this->pic_SurfaceDesign->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pic_SurfaceDesign->TabIndex = 17;
			this->pic_SurfaceDesign->TabStop = false;
			this->pic_SurfaceDesign->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SurfaceDesign::pic_SurfaceDesign_Paint_1);
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer4);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->groupBox3);
			this->splitContainer2->Size = System::Drawing::Size(401, 486);
			this->splitContainer2->SplitterDistance = 240;
			this->splitContainer2->TabIndex = 22;
			// 
			// splitContainer4
			// 
			this->splitContainer4->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->Location = System::Drawing::Point(0, 0);
			this->splitContainer4->Name = L"splitContainer4";
			this->splitContainer4->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->panel1);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer4->Size = System::Drawing::Size(401, 240);
			this->splitContainer4->SplitterDistance = 91;
			this->splitContainer4->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->num_VValue);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txt_V_Resolution);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->num_UValue);
			this->panel1->Controls->Add(this->txt_H_Resolution);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtV_Controll_Num);
			this->panel1->Controls->Add(this->txtH_Controll_Num);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(401, 91);
			this->panel1->TabIndex = 17;
			// 
			// num_VValue
			// 
			this->num_VValue->Location = System::Drawing::Point(242, 73);
			this->num_VValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->num_VValue->Name = L"num_VValue";
			this->num_VValue->Size = System::Drawing::Size(58, 22);
			this->num_VValue->TabIndex = 27;
			this->num_VValue->TabStop = false;
			this->num_VValue->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(159, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 12);
			this->label6->TabIndex = 26;
			this->label6->Text = L"垂直平滑度";
			// 
			// txt_V_Resolution
			// 
			this->txt_V_Resolution->Location = System::Drawing::Point(241, 41);
			this->txt_V_Resolution->Name = L"txt_V_Resolution";
			this->txt_V_Resolution->Size = System::Drawing::Size(59, 22);
			this->txt_V_Resolution->TabIndex = 25;
			this->txt_V_Resolution->Text = L"100";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(159, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 12);
			this->label5->TabIndex = 24;
			this->label5->Text = L"顯示解析度(Y)";
			// 
			// num_UValue
			// 
			this->num_UValue->Location = System::Drawing::Point(94, 73);
			this->num_UValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->num_UValue->Name = L"num_UValue";
			this->num_UValue->Size = System::Drawing::Size(58, 22);
			this->num_UValue->TabIndex = 23;
			this->num_UValue->TabStop = false;
			this->num_UValue->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// txt_H_Resolution
			// 
			this->txt_H_Resolution->Location = System::Drawing::Point(94, 41);
			this->txt_H_Resolution->Name = L"txt_H_Resolution";
			this->txt_H_Resolution->Size = System::Drawing::Size(59, 22);
			this->txt_H_Resolution->TabIndex = 22;
			this->txt_H_Resolution->Text = L"100";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 12);
			this->label4->TabIndex = 21;
			this->label4->Text = L"顯示解析度(X)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 20;
			this->label3->Text = L"水平平滑度";
			// 
			// txtV_Controll_Num
			// 
			this->txtV_Controll_Num->Location = System::Drawing::Point(242, 11);
			this->txtV_Controll_Num->Name = L"txtV_Controll_Num";
			this->txtV_Controll_Num->Size = System::Drawing::Size(59, 22);
			this->txtV_Controll_Num->TabIndex = 19;
			this->txtV_Controll_Num->Text = L"5";
			this->txtV_Controll_Num->TextChanged += gcnew System::EventHandler(this, &SurfaceDesign::txtV_Controll_Num_TextChanged);
			// 
			// txtH_Controll_Num
			// 
			this->txtH_Controll_Num->Location = System::Drawing::Point(94, 11);
			this->txtH_Controll_Num->Name = L"txtH_Controll_Num";
			this->txtH_Controll_Num->Size = System::Drawing::Size(59, 22);
			this->txtH_Controll_Num->TabIndex = 18;
			this->txtH_Controll_Num->Text = L"5";
			this->txtH_Controll_Num->TextChanged += gcnew System::EventHandler(this, &SurfaceDesign::txtH_Controll_Num_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(159, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 12);
			this->label2->TabIndex = 17;
			this->label2->Text = L"垂直控制點數";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 12);
			this->label1->TabIndex = 16;
			this->label1->Text = L"水平控制點數";
			// 
			// splitContainer3
			// 
			this->splitContainer3->BackColor = System::Drawing::Color::Lime;
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->tabControl1);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->btn_Default_Pos);
			this->splitContainer3->Size = System::Drawing::Size(401, 145);
			this->splitContainer3->SplitterDistance = 116;
			this->splitContainer3->TabIndex = 16;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabWeight);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(401, 116);
			this->tabControl1->TabIndex = 11;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 21);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(393, 91);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"輸入參數";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Format = L"N2";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->Format = L"N2";
			dataGridViewCellStyle2->NullValue = nullptr;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(387, 85);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SurfaceDesign::dataGridView1_CellClick);
			this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SurfaceDesign::dataGridView1_KeyDown);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView_X_Location);
			this->tabPage2->Location = System::Drawing::Point(4, 21);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(396, 147);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"X座標";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView_X_Location
			// 
			this->dataGridView_X_Location->AllowUserToAddRows = false;
			this->dataGridView_X_Location->AllowUserToDeleteRows = false;
			this->dataGridView_X_Location->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView_X_Location->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_X_Location->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_X_Location->Location = System::Drawing::Point(3, 3);
			this->dataGridView_X_Location->Name = L"dataGridView_X_Location";
			this->dataGridView_X_Location->RowTemplate->Height = 24;
			this->dataGridView_X_Location->Size = System::Drawing::Size(390, 141);
			this->dataGridView_X_Location->TabIndex = 0;
			this->dataGridView_X_Location->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SurfaceDesign::dataGridView_X_Location_KeyDown);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView_Y_Location);
			this->tabPage3->Location = System::Drawing::Point(4, 21);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(396, 147);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Y座標";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Y_Location
			// 
			this->dataGridView_Y_Location->AllowUserToAddRows = false;
			this->dataGridView_Y_Location->AllowUserToDeleteRows = false;
			this->dataGridView_Y_Location->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Y_Location->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Y_Location->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Y_Location->Name = L"dataGridView_Y_Location";
			this->dataGridView_Y_Location->RowTemplate->Height = 24;
			this->dataGridView_Y_Location->Size = System::Drawing::Size(390, 141);
			this->dataGridView_Y_Location->TabIndex = 0;
			this->dataGridView_Y_Location->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SurfaceDesign::dataGridView_Y_Location_KeyDown);
			// 
			// tabWeight
			// 
			this->tabWeight->Controls->Add(this->dataGridView_Weight);
			this->tabWeight->Location = System::Drawing::Point(4, 21);
			this->tabWeight->Name = L"tabWeight";
			this->tabWeight->Padding = System::Windows::Forms::Padding(3);
			this->tabWeight->Size = System::Drawing::Size(396, 147);
			this->tabWeight->TabIndex = 3;
			this->tabWeight->Text = L"權重";
			this->tabWeight->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Weight
			// 
			this->dataGridView_Weight->AllowUserToAddRows = false;
			this->dataGridView_Weight->AllowUserToDeleteRows = false;
			dataGridViewCellStyle3->Format = L"N2";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->dataGridView_Weight->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView_Weight->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView_Weight->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->Format = L"N2";
			dataGridViewCellStyle4->NullValue = nullptr;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_Weight->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView_Weight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Weight->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->dataGridView_Weight->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Weight->Name = L"dataGridView_Weight";
			this->dataGridView_Weight->RowTemplate->Height = 24;
			this->dataGridView_Weight->Size = System::Drawing::Size(390, 141);
			this->dataGridView_Weight->TabIndex = 5;
			this->dataGridView_Weight->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SurfaceDesign::dataGridView_Weight_KeyDown);
			// 
			// btn_Default_Pos
			// 
			this->btn_Default_Pos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_Default_Pos->Location = System::Drawing::Point(0, 0);
			this->btn_Default_Pos->MinimumSize = System::Drawing::Size(10, 10);
			this->btn_Default_Pos->Name = L"btn_Default_Pos";
			this->btn_Default_Pos->Size = System::Drawing::Size(401, 25);
			this->btn_Default_Pos->TabIndex = 4;
			this->btn_Default_Pos->Text = L"預設位置";
			this->btn_Default_Pos->UseVisualStyleBackColor = true;
			this->btn_Default_Pos->Click += gcnew System::EventHandler(this, &SurfaceDesign::btn_Default_Pos_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->splitContainer5);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(0, 0);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(401, 242);
			this->groupBox3->TabIndex = 20;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"結果輸出";
			// 
			// splitContainer5
			// 
			this->splitContainer5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer5->Location = System::Drawing::Point(3, 18);
			this->splitContainer5->Name = L"splitContainer5";
			this->splitContainer5->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer5.Panel1
			// 
			this->splitContainer5->Panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->splitContainer5->Panel1->Controls->Add(this->tabDensity_ControllPt);
			// 
			// splitContainer5.Panel2
			// 
			this->splitContainer5->Panel2->Controls->Add(this->groupBox4);
			this->splitContainer5->Size = System::Drawing::Size(395, 221);
			this->splitContainer5->SplitterDistance = 118;
			this->splitContainer5->TabIndex = 0;
			// 
			// tabDensity_ControllPt
			// 
			this->tabDensity_ControllPt->Controls->Add(this->tabControlPtDensity);
			this->tabDensity_ControllPt->Controls->Add(this->tab13Pt);
			this->tabDensity_ControllPt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabDensity_ControllPt->Location = System::Drawing::Point(0, 0);
			this->tabDensity_ControllPt->Name = L"tabDensity_ControllPt";
			this->tabDensity_ControllPt->SelectedIndex = 0;
			this->tabDensity_ControllPt->Size = System::Drawing::Size(395, 118);
			this->tabDensity_ControllPt->TabIndex = 19;
			// 
			// tabControlPtDensity
			// 
			this->tabControlPtDensity->Controls->Add(this->dataGridView_ActualDesign_Density);
			this->tabControlPtDensity->Location = System::Drawing::Point(4, 21);
			this->tabControlPtDensity->Name = L"tabControlPtDensity";
			this->tabControlPtDensity->Padding = System::Windows::Forms::Padding(3);
			this->tabControlPtDensity->Size = System::Drawing::Size(387, 93);
			this->tabControlPtDensity->TabIndex = 0;
			this->tabControlPtDensity->Text = L"等分點密度";
			this->tabControlPtDensity->UseVisualStyleBackColor = true;
			// 
			// dataGridView_ActualDesign_Density
			// 
			this->dataGridView_ActualDesign_Density->AllowUserToAddRows = false;
			this->dataGridView_ActualDesign_Density->AllowUserToDeleteRows = false;
			this->dataGridView_ActualDesign_Density->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_ActualDesign_Density->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_ActualDesign_Density->Location = System::Drawing::Point(3, 3);
			this->dataGridView_ActualDesign_Density->Name = L"dataGridView_ActualDesign_Density";
			this->dataGridView_ActualDesign_Density->ReadOnly = true;
			this->dataGridView_ActualDesign_Density->RowHeadersWidth = 21;
			this->dataGridView_ActualDesign_Density->RowTemplate->Height = 24;
			this->dataGridView_ActualDesign_Density->Size = System::Drawing::Size(381, 87);
			this->dataGridView_ActualDesign_Density->TabIndex = 0;
			this->dataGridView_ActualDesign_Density->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SurfaceDesign::dataGridView_ActualDesign_Density_CellClick);
			// 
			// tab13Pt
			// 
			this->tab13Pt->Controls->Add(this->dataGridView_Custom);
			this->tab13Pt->Location = System::Drawing::Point(4, 21);
			this->tab13Pt->Name = L"tab13Pt";
			this->tab13Pt->Padding = System::Windows::Forms::Padding(3);
			this->tab13Pt->Size = System::Drawing::Size(390, 143);
			this->tab13Pt->TabIndex = 1;
			this->tab13Pt->Text = L"自行定義點密度";
			this->tab13Pt->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Custom
			// 
			this->dataGridView_Custom->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Custom->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Custom_X, 
				this->Customed_Y, this->Customed_Result});
			this->dataGridView_Custom->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Custom->Location = System::Drawing::Point(3, 3);
			this->dataGridView_Custom->Name = L"dataGridView_Custom";
			this->dataGridView_Custom->RowHeadersWidth = 21;
			this->dataGridView_Custom->RowTemplate->Height = 24;
			this->dataGridView_Custom->Size = System::Drawing::Size(384, 137);
			this->dataGridView_Custom->TabIndex = 1;
			this->dataGridView_Custom->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SurfaceDesign::dataGridView_Custom_CellContentClick);
			// 
			// Custom_X
			// 
			this->Custom_X->HeaderText = L"自訂X座標";
			this->Custom_X->Name = L"Custom_X";
			// 
			// Customed_Y
			// 
			this->Customed_Y->HeaderText = L"自訂Y座標";
			this->Customed_Y->Name = L"Customed_Y";
			// 
			// Customed_Result
			// 
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Customed_Result->DefaultCellStyle = dataGridViewCellStyle5;
			this->Customed_Result->HeaderText = L"產生密度結果";
			this->Customed_Result->Name = L"Customed_Result";
			this->Customed_Result->ReadOnly = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->lbl_SelectedIndex);
			this->groupBox4->Controls->Add(this->btnApply);
			this->groupBox4->Controls->Add(this->statusStrip1);
			this->groupBox4->Controls->Add(this->btn);
			this->groupBox4->Controls->Add(this->btnExit);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(0, 0);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(395, 99);
			this->groupBox4->TabIndex = 21;
			this->groupBox4->TabStop = false;
			this->groupBox4->Enter += gcnew System::EventHandler(this, &SurfaceDesign::groupBox4_Enter);
			// 
			// lbl_SelectedIndex
			// 
			this->lbl_SelectedIndex->AutoSize = true;
			this->lbl_SelectedIndex->Location = System::Drawing::Point(16, 18);
			this->lbl_SelectedIndex->Name = L"lbl_SelectedIndex";
			this->lbl_SelectedIndex->Size = System::Drawing::Size(107, 12);
			this->lbl_SelectedIndex->TabIndex = 22;
			this->lbl_SelectedIndex->Text = L"點選到的輸入位置 :";
			// 
			// btnApply
			// 
			this->btnApply->Location = System::Drawing::Point(96, 38);
			this->btnApply->Name = L"btnApply";
			this->btnApply->Size = System::Drawing::Size(72, 33);
			this->btnApply->TabIndex = 21;
			this->btnApply->Text = L"套用";
			this->btnApply->UseVisualStyleBackColor = true;
			this->btnApply->Click += gcnew System::EventHandler(this, &SurfaceDesign::btnApply_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->ProgressBar, this->Statuslbl});
			this->statusStrip1->Location = System::Drawing::Point(3, 74);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(389, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// ProgressBar
			// 
			this->ProgressBar->Name = L"ProgressBar";
			this->ProgressBar->Size = System::Drawing::Size(250, 16);
			// 
			// Statuslbl
			// 
			this->Statuslbl->Name = L"Statuslbl";
			this->Statuslbl->Size = System::Drawing::Size(29, 17);
			this->Statuslbl->Text = L"狀態";
			// 
			// btn
			// 
			this->btn->Location = System::Drawing::Point(18, 38);
			this->btn->Name = L"btn";
			this->btn->Size = System::Drawing::Size(72, 33);
			this->btn->TabIndex = 4;
			this->btn->Text = L"計算";
			this->btn->UseVisualStyleBackColor = true;
			this->btn->Click += gcnew System::EventHandler(this, &SurfaceDesign::button1_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(174, 38);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(72, 33);
			this->btnExit->TabIndex = 20;
			this->btnExit->Text = L"離開";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &SurfaceDesign::btnExit_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView2);
			this->tabPage4->Location = System::Drawing::Point(4, 21);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(325, 213);
			this->tabPage4->TabIndex = 0;
			this->tabPage4->Text = L"密度";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			dataGridViewCellStyle6->Format = L"N2";
			dataGridViewCellStyle6->NullValue = nullptr;
			this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle7->Format = L"N2";
			dataGridViewCellStyle7->NullValue = nullptr;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->dataGridView2->Location = System::Drawing::Point(18, 23);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(261, 184);
			this->dataGridView2->TabIndex = 4;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->dataGridView3);
			this->tabPage5->Location = System::Drawing::Point(4, 21);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(325, 213);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"X座標";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(18, 17);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(278, 168);
			this->dataGridView3->TabIndex = 0;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->dataGridView4);
			this->tabPage6->Location = System::Drawing::Point(4, 21);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(325, 213);
			this->tabPage6->TabIndex = 2;
			this->tabPage6->Text = L"Y座標";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(52, 22);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowTemplate->Height = 24;
			this->dataGridView4->Size = System::Drawing::Size(211, 150);
			this->dataGridView4->TabIndex = 0;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &SurfaceDesign::backgroundWorker1_DoWork);
			// 
			// SurfaceDesign
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(912, 507);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->Name = L"SurfaceDesign";
			this->Text = L"曲面調整均度";
			this->Load += gcnew System::EventHandler(this, &SurfaceDesign::SurfaceDesign_Load);
			this->Activated += gcnew System::EventHandler(this, &SurfaceDesign::SurfaceDesign_Activated);
			this->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &SurfaceDesign::SurfaceDesign_Validating);
			this->groupBox1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic_SurfaceDesign))->EndInit();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel1->PerformLayout();
			this->splitContainer4->Panel2->ResumeLayout(false);
			this->splitContainer4->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_VValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num_UValue))->EndInit();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_X_Location))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Y_Location))->EndInit();
			this->tabWeight->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Weight))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->splitContainer5->Panel1->ResumeLayout(false);
			this->splitContainer5->Panel2->ResumeLayout(false);
			this->splitContainer5->ResumeLayout(false);
			this->tabDensity_ControllPt->ResumeLayout(false);
			this->tabControlPtDensity->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_ActualDesign_Density))->EndInit();
			this->tab13Pt->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Custom))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView3))->EndInit();
			this->tabPage6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void SurfaceDesign_Load(System::Object^  sender, System::EventArgs^  e) {

			 
			/*	
				MemoryStream_DesignDensity = gcnew MemoryStream();			
				Graphics^ tmpG = this->pic_SurfaceDesign->CreateGraphics();		
				Metafile_DesignDensity =gcnew Metafile(MemoryStream_DesignDensity,tmpG->GetHdc());
				tmpG->ReleaseHdc();

				SurfaceDensity = this->pic_SurfaceDesign->CreateGraphics();
			*/

			 // B-Spline Surface 建立
		//	 this->temp_Surface = gcnew B_Spline_Surface();

			 //讀取Uni_Surface 上面的參數
			 if (this->Uni_Surface != nullptr){

				
				Point PtNumber = this->Uni_Surface->GetControllPtNumber();
				
				Point SurfaceResolution = this->Uni_Surface->SurfaceResolution::get();
			
				this->txtH_Controll_Num->Text = Convert::ToString(PtNumber.X);
				this->txtV_Controll_Num->Text = Convert::ToString(PtNumber.Y);
				int tmpu = 0 ,tmpv = 0;
				this->Uni_Surface->Get_uv_Value(tmpu,tmpv);
				this->num_UValue->Text = Convert::ToString(tmpu);
				this->num_VValue->Text = Convert::ToString(tmpv);
				this->txt_H_Resolution->Text = Convert::ToString(SurfaceResolution.X);
				this->txt_V_Resolution->Text = Convert::ToString(SurfaceResolution.Y);
				this->SetDataGridRow_Column(PtNumber);


				
				/*
				//建立DataGrid ------------------------------------------------------------------------------------
					this->dataGridView1->ColumnCount::set(PtNumber.X) ;
					this->dataGridView_X_Location->ColumnCount::set(PtNumber.X);
					this->dataGridView_Y_Location->ColumnCount::set(PtNumber.X);
					this->dataGridView_Weight->ColumnCount::set(PtNumber.X);
					this->dataGridView_ActualDesign_Density->ColumnCount::set(PtNumber.X);

					this->dataGridView1->RowCount::set(PtNumber.Y) ;
					this->dataGridView_X_Location->RowCount::set(PtNumber.Y);
					this->dataGridView_Y_Location->RowCount::set(PtNumber.Y);
					this->dataGridView_Weight->RowCount::set(PtNumber.Y);
					this->dataGridView_ActualDesign_Density->RowCount::set(PtNumber.Y);
				*/


				for(int ii= 0 ; ii< PtNumber.X ; ii++){	
					this->dataGridView1->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
					this->dataGridView_X_Location->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
					this->dataGridView_Y_Location->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
					this->dataGridView_ActualDesign_Density->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);	
					
					this->dataGridView1->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
					this->dataGridView_X_Location->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
					this->dataGridView_Y_Location->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
					this->dataGridView_ActualDesign_Density->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
				}


			
			
				//----------------------------------------------------------------------------------------------------




				//設計參數輸入 Surface 中

			//	array<float,2>^ tmp_Z = this->Uni_Surface->GetControllPt_Z();
				array<PointF,2>^ tmpPT = this->Uni_Surface->GetControllPt();



				//確認顯示方式 ~~
				int sortway = 0;

				if(tmpPT->Length >0){
					if(tmpPT[0,0].Y >= tmpPT[0,PtNumber.Y-1].Y ){
						sortway = 1 ;  //表是照[ii.jj]方式就ok了!!!
					}else{
						sortway = 2 ;  //表是照[ii.PtNumber.Y-1-jj]方式就ok了!!!
					}
				}

				
				

					
				for(int ii = 0 ; ii < PtNumber.X ; ii ++){
					for(int jj = 0 ;jj < PtNumber.Y ;jj ++){
						//PointF tmpLocation = (PointF)tmpPT->GetValue(ii,jj);
						PointF tmpControllPT ;
						float Z_Value;
						float Weight;
						this->Uni_Surface->GetControllPt_Data(tmpControllPT,Z_Value,Weight,Point(ii,jj));
						if(sortway == 2) {

							this->dataGridView1->default[ii,PtNumber.Y-1-jj]->Value = Z_Value ;							
							this->dataGridView_X_Location->default[ii,PtNumber.Y-1-jj]->Value = tmpControllPT.X;
							this->dataGridView_Y_Location->default[ii,PtNumber.Y-1-jj]->Value = tmpControllPT.Y;
							this->dataGridView_Weight->default[ii,PtNumber.Y-1-jj]->Value = Weight;
						}else if(sortway == 1) {
							this->dataGridView1->default[ii,jj]->Value = Z_Value ;							
							this->dataGridView_X_Location->default[ii,jj]->Value = tmpControllPT.X;
							this->dataGridView_Y_Location->default[ii,jj]->Value = tmpControllPT.Y;
							this->dataGridView_Weight->default[ii,jj]->Value = Weight;

						}
											 
					}
				}





			 }

				
			 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 
	//		 this->btn->Enabled = false;

			 this->backgroundWorker1->RunWorkerAsync(); 

		 
			 
			

			 /*


			 B_Spline_Surface^ calculate_surface ;
			calculate_surface = gcnew B_Spline_Surface();

			 //將參數輸入到calculate_surface 中
			 //資料格式為 --- -名字-,平滑度x,y ,解析度rx,ry,控制點(rowXcolumn) a,b ,控制點 (x,y,Z,W) ,... ......
			int Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
			int Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);

			array<String^>^ surfacedata = gcnew array<String^>(7+ 4*Num_H*Num_V);
			surfacedata->SetValue("GlobalSurface",0);
			surfacedata->SetValue(this->num_UValue->Text,1);
			surfacedata->SetValue(this->num_VValue->Text,2);
			surfacedata->SetValue(this->txt_H_Resolution->Text,3);
			surfacedata->SetValue(this->txt_V_Resolution->Text,4);
			surfacedata->SetValue(this->txtH_Controll_Num->Text,5);
			surfacedata->SetValue(this->txtV_Controll_Num->Text,6);


			int count = 7;
			for(int jj = 0 ;jj < Num_V ; jj++){
				for(int ii = 0 ;ii < Num_H ; ii++){
				
					surfacedata->SetValue(Convert::ToString(this->dataGridView_X_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Y_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView1->default[ii,Num_V-jj-1]->Value),count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Weight->default[ii,Num_V-jj-1]->Value),count);
					count ++;
									
				}
			}


	

			calculate_surface->SaveSurfaceData(surfacedata);

				
			
			this->Statuslbl->Text = "開始計算" ;

		
		    calculate_surface->ModifySurface_Resolution_Degree(); 

			

			for(int j = 0 ;j < Num_V ;j ++){
		   		for(int i = 0 ; i < Num_H ; i ++){	 		
					float Z = 0;
					float	tmpX = (float)i/(float)(Num_H-1)*this->PlateWidth;
					float	tmpY = (float)(Num_V-1-j)/(float)(Num_V-1)*this->PlateHeight;
					Z = calculate_surface->GetSurface_Z_Value(tmpX,tmpY);
					this->dataGridView_ActualDesign_Density->default[i,j]->Value = String::Format("{0:0.000}",Z);
				
									 
				}
				
				this->ProgressBar->Value =(int)(80*(float)j/(float)(Num_V-1)) ;
				this->statusStrip1->Update();
			}

			this->Statuslbl->Text = "產生圖形" ;
			this->ProgressBar->Value = 80 ;
			this->statusStrip1->Update();

	

			DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();
			Graphics^ test1 = this->pic_SurfaceDesign->CreateGraphics();					
			Draw1->PageRange =test1->VisibleClipBounds;
			Draw1->CreatePageSurface(calculate_surface ,true ,calculate_surface->SurfaceResolution::get());
			Metafile1 = Draw1->DrawPageSurface(PointF(100,0),test1,true,false,true,false);					
			delete test1;
			Graphics^ tmpPic;
			tmpPic = this->pic_SurfaceDesign->CreateGraphics();		
			tmpPic->DrawImage(Metafile1,5,5,this->pic_SurfaceDesign->Width-10,this->pic_SurfaceDesign->Height-10);				  
			this->Statuslbl->Text = "計算完成" ;
			this->ProgressBar->Value = 100 ;
			this->statusStrip1->Update();

			 this->btn->Enabled = true;


	 

	 */



			


			

	
				
				 
				 

			

			 }

private: System::Void chk_Default_Resolution_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 /*
			 if (chk_Default_Resolution->Checked == true) {
				 txt_H_Resolution->Enabled = false; 
				 txt_V_Resolution->Enabled = false;
			 }else {
				 txt_H_Resolution->Enabled = true; 
				 txt_V_Resolution->Enabled = true;
			 }

			 */
			 



		 }
private: System::Void txtH_Controll_Num_TextChanged(System::Object^  sender, System::EventArgs^  e) {





				int Num_H;
				int Num_V;




		//	 try{
					
					if(txtH_Controll_Num->Text != "")
						this->num_UValue->Maximum::set(Convert::ToUInt16(txtH_Controll_Num->Text));
					if(this->txtH_Controll_Num->Text != "")
						Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
					else
						Num_H = 2;

					if(this->txtV_Controll_Num->Text != "")
						Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);
					else
						Num_V = 2;



					//設計參數網格數
				//	this->dataGridView1->ColumnCount::set(Num_H) ;
				//	this->dataGridView_X_Location->ColumnCount::set(Num_H);
				//	this->dataGridView_Y_Location->ColumnCount::set(Num_H);
				//	this->dataGridView_Weight->ColumnCount::set(Num_H);
					
					//結果輸出網格數
				//	this->dataGridView_ActualDesign_Density->ColumnCount::set(Num_H);
					this->SetDataGridRow_Column(Point(Num_H,Num_V));


					for(int ii= 0 ; ii<Num_H ; ii++){
						this->dataGridView1->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
						this->dataGridView_X_Location->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
						this->dataGridView_Y_Location->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
						this->dataGridView_ActualDesign_Density->Columns->default[ii]->SortMode = DataGridViewColumnSortMode::NotSortable;
						this->dataGridView1->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
						this->dataGridView_X_Location->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
						this->dataGridView_Y_Location->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
						this->dataGridView_ActualDesign_Density->Columns->default[ii]->Name = L"橫向點: " + Convert::ToString(ii+1);
					}

					//自動計算產生座標和權重

					if(Num_H >= 2 && Num_V >= 2){
						 PointF coordinate;
						 float X = Convert::ToSingle(this->PlateWidth);
						 float Y = Convert::ToSingle(this->PlateHeight);
						 

						 for(int ii = 0 ; ii < Num_H ; ii++){
							
							 coordinate.X = ii*X/(Num_H-1);

							 for(int jj = 0 ; jj < Num_V ; jj ++){
								 coordinate.Y = (Num_V-jj-1)*Y/(Num_V-1);
								
								  this->dataGridView_X_Location->default[ii,jj]->Value = coordinate.X;
								  this->dataGridView_Y_Location->default[ii,jj]->Value = coordinate.Y;
								  this->dataGridView_Weight->default[ii,jj]->Value = 1.0f;
								  this->dataGridView1->default[ii,jj]->Value = 0.0f;

							 }
						 }

						 //產生UV Value

						 int U,V;
						 this->Uni_Surface->Get_uv_Value(U,V);
						 if(U <2 ) U = 2;
						 if(V <2 ) V = 2;

						 this->num_UValue->Text = Convert::ToString(U);
						 this->num_VValue->Text = Convert::ToString(V);
						 this->num_UValue->Enabled = true;
						 this->num_VValue->Enabled = true;
						 
					}else{
						 this->num_UValue->Enabled = false;
						 this->num_VValue->Enabled = false;

					}








		//	 }
		//	 catch(...){
				// this->txtH_Controll_Num->Text = " ";	
			//	 MessageBox::Show("Error!!");
			// }
		 }
private: System::Void txtV_Controll_Num_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		

			 int Num_H;
			 int Num_V;

			 
			 //	try{
					if(this->txtV_Controll_Num->Text != "")		
						this->num_VValue->Maximum::set(Convert::ToInt16(this->txtV_Controll_Num->Text));

					if (this->txtH_Controll_Num->Text != "")
						Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
					else
						Num_H = 2;

					if(this->txtV_Controll_Num->Text != "")
						Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);
					else
						Num_V = 2;



				//	this->dataGridView1->RowCount::set(Num_V) ;
				//	this->dataGridView_X_Location->RowCount::set(Num_V);
				//	this->dataGridView_Y_Location->RowCount::set(Num_V);
				//	this->dataGridView_Weight->RowCount::set(Num_V);

					//結果輸出網格數
				//	this->dataGridView_ActualDesign_Density->RowCount::set(Num_V);
					

					this->SetDataGridRow_Column(Point(Num_H,Num_V));
			
					//自動計算產生座標和權重

					if(Num_H >= 2 && Num_V >= 2){
						 PointF coordinate;
						 float X = Convert::ToSingle(this->PlateWidth);
						 float Y = Convert::ToSingle(this->PlateHeight);
						 

						 for(int ii = 0 ; ii < Num_H ; ii++){
							
							 coordinate.X = ii*X/(Num_H-1);

							 for(int jj = 0 ; jj < Num_V ; jj ++){
								 coordinate.Y = (Num_V-jj-1)*Y/(Num_V-1);
								
								  this->dataGridView_X_Location->default[ii,jj]->Value = coordinate.X;
								  this->dataGridView_Y_Location->default[ii,jj]->Value = coordinate.Y;
								  this->dataGridView_Weight->default[ii,jj]->Value = 1.0f;
								  this->dataGridView1->default[ii,jj]->Value = 0.0f;

							 }
						 }

						//產生UV Value

						 int U,V;
						 this->Uni_Surface->Get_uv_Value(U,V);
						 if(U <2 ) U = 2;
						 if(V <2 ) V = 2;

						 this->num_UValue->Text = Convert::ToString(U);
						 this->num_VValue->Text = Convert::ToString(V);
						 this->num_UValue->Enabled = true;
						 this->num_VValue->Enabled = true;
						 
					}else{
						 this->num_UValue->Enabled = false;
						 this->num_VValue->Enabled = false;


					}





		//	 }
		//	 catch(...){
				// this->txtV_Controll_Num->Text = " ";	
		//		  MessageBox::Show("Error!!");
		//	 }
		 }


private: System::Void pic_SurfaceDesign_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			int picwidth = this->pic_SurfaceDesign->Width;
			int picheight = this->pic_SurfaceDesign->Height;


			if ( this->Metafile_DesignDensity != nullptr) {
				float scale = 0;
				if(this->PlateHeight >= this->PlateWidth){
					scale = picheight/this->PlateHeight*0.8f;
					e->Graphics->DrawImage(this->Metafile_DesignDensity,(int)(picwidth-scale*this->PlateWidth)/2,(int)picheight/10,(int)(scale*this->PlateWidth),(int)(scale*this->PlateHeight));
					//使用下列的方法,圖形就會很嚴重的閃爍
					//this->SurfaceDensity->DrawImage(this->Metafile_DesignDensity,(int)(picwidth-scale*this->PlateWidth)/2,(int)picheight/10,(int)(scale*this->PlateWidth),(int)(scale*this->PlateHeight));
				}
				else{
					scale = picwidth/this->PlateWidth*0.8f;
					e->Graphics->DrawImage(this->Metafile_DesignDensity,(int)picwidth/10,(int)(picheight-scale*this->PlateHeight)/2,(int)(scale*this->PlateWidth),(int)(scale*this->PlateHeight));
					//使用下列的方法,圖形就會很嚴重的閃爍
					//this->SurfaceDensity->DrawImage(this->Metafile_DesignDensity,(int)picwidth/10,(int)(picheight-scale*this->PlateHeight)/2,(int)(scale*this->PlateWidth),(int)(scale*this->PlateHeight));
				}
			}

				
			 
		 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();

			 
		 }



private: System::Void dataGridView1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			if(e->Control == true && e->KeyCode == Keys::V ){
				
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView1->ColumnCount;
				  MaxIndex.Y = this->dataGridView1->RowCount;


				  DataGridViewCell^ currentCell = this->dataGridView1->CurrentCell;
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
								this->dataGridView1->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }




		 }

private: System::Void dataGridView_Y_Location_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->Control == true && e->KeyCode == Keys::V ){
				
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView_Y_Location->ColumnCount;
				  MaxIndex.Y = this->dataGridView_Y_Location->RowCount;


				  DataGridViewCell^ currentCell = this->dataGridView_Y_Location->CurrentCell;
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
								this->dataGridView_Y_Location->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }

		 }
private: System::Void dataGridView_X_Location_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if(e->Control == true && e->KeyCode == Keys::V ){
				
								
				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView_X_Location->ColumnCount;
				  MaxIndex.Y = this->dataGridView_X_Location->RowCount;


				  DataGridViewCell^ currentCell = this->dataGridView_X_Location->CurrentCell;
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
								this->dataGridView_X_Location->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }



		 }

private: System::Void btn_Default_Pos_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 
			 int Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
			 int Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);


			 if(this->tabControl1->SelectedIndex == 1){

				 for(int ii= 0 ; ii<Num_H ; ii++){	
					 float X = this->PlateWidth *ii/(Num_H-1);
					  for(int jj= 0 ; jj<Num_V ; jj++){						
						  this->dataGridView_X_Location->default[ii,jj]->Value = X;
					  }
				 }

			 }else if(this->tabControl1->SelectedIndex == 2){
		
				for(int ii= 0 ; ii<Num_H ; ii++){	
					
					  for(int jj= 0 ; jj<Num_V ; jj++){	
						  float Y = this->PlateHeight * (Num_V-jj-1)/(Num_V-1); //20091217 (暫時先關掉)
						//  float Y = this->PlateHeight * jj/(Num_V-1); //20091217 (暫時先關掉)
						  this->dataGridView_Y_Location->default[ii,jj]->Value = Y;
					  }
				 }

			 }else if(this->tabControl1->SelectedIndex == 3){
				for(int ii= 0 ; ii<Num_H ; ii++){						
					  for(int jj= 0 ; jj<Num_V ; jj++){						
						  this->dataGridView_Weight->default[ii,jj]->Value = 1.0f;
					  }
				 }

			 }

		 }
	
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pic_SurfaceDesign_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if(Metafile1 != nullptr)
				 e->Graphics->DrawImage(Metafile1,5,5,this->pic_SurfaceDesign->Width-10,this->pic_SurfaceDesign->Height-10);

		 }

private: System::Void dataGridView_Custom_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
private: System::Void btnApply_Click(System::Object^  sender, System::EventArgs^  e) {
			 //將參數輸入到Global_Surface 中
			 //資料格式為 --- -名字-,平滑度x,y ,解析度rx,ry,控制點(rowXcolumn) a,b ,控制點 (x,y,Z,W) ,... ......
			int Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
			int Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);

			array<String^>^ surfacedata = gcnew array<String^>(7+ 4*Num_H*Num_V);
			surfacedata->SetValue("GlobalSurface",0);
			surfacedata->SetValue(this->num_UValue->Text,1);
			surfacedata->SetValue(this->num_VValue->Text,2);
			surfacedata->SetValue(this->txt_H_Resolution->Text,3);
			surfacedata->SetValue(this->txt_V_Resolution->Text,4);
			surfacedata->SetValue(this->txtH_Controll_Num->Text,5);
			surfacedata->SetValue(this->txtV_Controll_Num->Text,6);


			int count = 7;
			for(int jj = 0 ;jj < Num_V ; jj++){
				for(int ii = 0 ;ii < Num_H ; ii++){
				
					surfacedata->SetValue(Convert::ToString(this->dataGridView_X_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Y_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView1->default[ii,Num_V-jj-1]->Value),count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Weight->default[ii,Num_V-jj-1]->Value),count);
					count ++;
									
				}
			}


	

			this->Uni_Surface->SaveSurfaceData(surfacedata);




		









		 }
private: System::Void SurfaceDesign_Activated(System::Object^  sender, System::EventArgs^  e) {

			


				

		 }
private: System::Void SurfaceDesign_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			
		 }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {



			 this->btn->Enabled = false;
			
			B_Spline_Surface^ calculate_surface ;
			calculate_surface = gcnew B_Spline_Surface();

			 //將參數輸入到calculate_surface 中
			 //資料格式為 --- -名字-,平滑度x,y ,解析度rx,ry,控制點(rowXcolumn) a,b ,控制點 (x,y,Z,W) ,... ......
			int Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text);
			int Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);

			array<String^>^ surfacedata = gcnew array<String^>(7+ 4*Num_H*Num_V);
			surfacedata->SetValue("GlobalSurface",0);
			surfacedata->SetValue(this->num_UValue->Text,1);
			surfacedata->SetValue(this->num_VValue->Text,2);
			surfacedata->SetValue(this->txt_H_Resolution->Text,3);
			surfacedata->SetValue(this->txt_V_Resolution->Text,4);
			surfacedata->SetValue(this->txtH_Controll_Num->Text,5);
			surfacedata->SetValue(this->txtV_Controll_Num->Text,6);


			int count = 7;
			for(int jj = 0 ;jj < Num_V ; jj++){
				for(int ii = 0 ;ii < Num_H ; ii++){
				
					surfacedata->SetValue(Convert::ToString(this->dataGridView_X_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Y_Location->default[ii,Num_V-jj-1]->Value) ,count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView1->default[ii,Num_V-jj-1]->Value),count);
					count ++;
					surfacedata->SetValue(Convert::ToString(this->dataGridView_Weight->default[ii,Num_V-jj-1]->Value),count);
					count ++;
									
				}
			}


	

			calculate_surface->SaveSurfaceData(surfacedata);

				
			
			this->Statuslbl->Text = "開始計算" ;

		
		    calculate_surface->ModifySurface_Resolution_Degree(); 

			

			for(int j = 0 ;j < Num_V ;j ++){
		   		for(int i = 0 ; i < Num_H ; i ++){	 		
					float Z = 0;
					float	tmpX = (float)i/(float)(Num_H-1)*this->PlateWidth;
					float	tmpY = (float)(Num_V-1-j)/(float)(Num_V-1)*this->PlateHeight;
					Z = calculate_surface->GetSurface_Z_Value(tmpX,tmpY);
					this->dataGridView_ActualDesign_Density->default[i,j]->Value = String::Format("{0:0.000}",Z);
				
									 
				}
				
				this->ProgressBar->Value =(int)(80*(float)j/(float)(Num_V-1)) ;
				this->statusStrip1->Update();
			}

			this->Statuslbl->Text = "產生圖形" ;
			this->ProgressBar->Value = 80 ;
			this->statusStrip1->Update();

			

			DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();
			Graphics^ test1 = this->pic_SurfaceDesign->CreateGraphics();					
			Draw1->PageRange =test1->VisibleClipBounds;
			Draw1->CreatePageSurface(calculate_surface ,true ,calculate_surface->SurfaceResolution::get());
			Metafile1 = Draw1->DrawPageSurface(PointF(100,0),test1,true,false,true,false);					
			delete test1;
			Graphics^ tmpPic;
			tmpPic = this->pic_SurfaceDesign->CreateGraphics();		
			tmpPic->DrawImage(Metafile1,5,5,this->pic_SurfaceDesign->Width-10,this->pic_SurfaceDesign->Height-10);				  
			this->Statuslbl->Text = "計算完成" ;
			this->ProgressBar->Value = 100 ;
			this->statusStrip1->Update();

			 this->btn->Enabled = true;


	 







			// do {
			//	 this->ProgressBar->Value = this->Uni_Surface->ProcessBarValue::get();				 
			// }while (this->ProgressBar->Value < 100);
		 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {


			 

			





		 }
private: System::Void dataGridView_Weight_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


			 

			 if(e->Control == true && e->KeyCode == Keys::V ){
				
				  DataGridViewCell^ currentCell = this->dataGridView_Weight->CurrentCell;

				  bool test2 =  Clipboard::ContainsText();
				  Point Index_Cell;
				  Point MaxIndex;
				  MaxIndex.X = this->dataGridView_Weight->ColumnCount;
				  MaxIndex.Y = this->dataGridView_Weight->RowCount;


				 
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
								this->dataGridView_Weight->default[Index_Cell.X+jj,Index_Cell.Y+ii]->Value = tmpSep2;
								
						  }

					  }					 
					  
				  }
				 
			 }




			 



		 }
private: System::Void groupBox4_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

			DataGridViewCell^ currentCell = this->dataGridView1->CurrentCell;
			
			
		
		
			if(currentCell->Selected == true ){
				 this->lbl_SelectedIndex->Text =  String::Format("點選到的控制點座標  =  橫向位置 :" + "{0:#0}"+" , 縱向位置 : " + "{1:#0}" ,currentCell->ColumnIndex + 1,currentCell->RowIndex + 1);
			 }else{

				 	 this->lbl_SelectedIndex->Text =  "點選到的控制點座標  = Null";

			 }




		 }
private: System::Void dataGridView1_CellMouseDown(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {




		 }
private: System::Void dataGridView_ActualDesign_Density_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

			DataGridViewCell^ currentCell = this->dataGridView_ActualDesign_Density->CurrentCell;
					
		
			if(currentCell->Selected == true ){
				 this->lbl_SelectedIndex->Text =  String::Format("點選到的輸出密度座標  =  橫向位置 :" + "{0:#0}"+" , 縱向位置 : " + "{1:#0}" ,currentCell->ColumnIndex + 1,currentCell->RowIndex + 1);
			 }else{

				 	 this->lbl_SelectedIndex->Text =  "點選到的輸出密度座標  = Null";

			 }


		 }
};
}
