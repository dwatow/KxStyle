#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::IO;
using namespace System::Drawing::Imaging;
//using namespace System::Collections::Generic;



#include "DataStructure.h"

//#include "B-Spline.h"

using namespace Nurbs;
int ComapreControllPt(PointF xtmpPt1,PointF xtmpPt2);

namespace PatternContruction {

	/// <summary>
	/// Summary for SmoothDensityEditForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SmoothDensityEditForm : public System::Windows::Forms::Form
	{
	public:
		SmoothDensityEditForm(B_Spline_Curve^ tmpHorizontal_Curve,B_Spline_Curve^ tmpVertical_Curve ,RectangleF LGP_Dimension)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			Horizontal_Window = Distribution_Horizontal->CreateGraphics();
			Vertical_Window = Distribution_Vertical->CreateGraphics();
			OK = false;
	
			CurrentControlPt_Index = -1;
			FrameSize_W = 551;
			FrameSize_H = 243;
			Active_Window = 0;

			this->tmpCurve_Vertical = tmpVertical_Curve;
			this->tmpCurve_Horizontal = tmpHorizontal_Curve;
			this->LGPInformation = LGP_Dimension;

			flagMoveControllPt = false;

	

			// Graphics Buffer
			context1 = gcnew BufferedGraphicsContext();
			context1->MaximumBuffer = System::Drawing::Size(FrameSize_W + 1, FrameSize_H + 1 );
			grafx1 = context1->Allocate(Vertical_Window, Rectangle(0,0,Distribution_Vertical->Width,Distribution_Vertical->Height)) ;
			// Graphics Buffer
			context2 = gcnew BufferedGraphicsContext();
			context2->MaximumBuffer = System::Drawing::Size( FrameSize_W + 1, FrameSize_H + 1 );
			grafx2 = context2->Allocate(Horizontal_Window, Rectangle(0,0,Distribution_Horizontal->Width,Distribution_Horizontal->Height)) ;


			TranslateFormula = gcnew TranslateModule();
			MouseSelectControllPt = -1;
			

	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~SmoothDensityEditForm()
		{
			if (components)
			{
				delete components;
			}
			delete Horizontal_Window;
			delete Vertical_Window;



		}

	private: System::Windows::Forms::PictureBox^  Distribution_Vertical;
	private: System::Windows::Forms::PictureBox^  Distribution_Horizontal;
	protected: 

    //�^�Ǫ����------------------------------------------
	public:
	//	DataInput *pinputdata ;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Label^  labelShow1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnOK;
	public: 

	public: 

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  btnsavecontrollpt;
	private: System::Windows::Forms::Button^  btnopencontrollpt;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;



	public: 
		bool OK;
		// Modify By Vinshen ...............................

		//�@................................................
	public: 






	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_ControlPtLocation;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_ControlPt_Den;























	public: 

	public: 


			 bool FlagMouseAction;
		//MeshGrid *ProduceDenSity(MeshGrid* Ori_mg);
		//void ProduceDenSity(MeshGrid* Ori_mg);
		//void ProduceDenSity_Array(MeshGridInfo ^ ori_mg_array);

	
	private:
		/// <summary>
		/// Required designer variable.
		
		
//		void AddControlPt(int X ,int Y,int DrawPic);    // 0���Up_Down(Vertical) ,1 ��� Left_Right(����)
//		void RemoveControlPt(int X ,int Y,int DrawPic); // 0���Up_Down ,1 ��� Left_Right
//		void MoveControlPt(int X ,int Y ,int DrawPic);  // 0���Up_Down ,1 ��� Left_Right
		//B-Spline-------------------------------------------------		
//		void GetKnotVector(array<float>^ &KnotVector,int n_value , int k_value);
//		void GetNikValue(array<float>^ &NikVector , array<float>^ KnotVector , int k_value ,float t,int n_value);
//		void Get_Point_In_BSplineCurve(float &Pt_X, float &Pt_Y,array<float>^ Bij_X ,array<float>^ Bij_Y , int k_value ,float t,int n_value );

		//GetDenSity
		
//		void GetDensityValue(float X ,float &Y,int DrawPic); // 0���Up_Down ,1 ��� Left_Right


		
		

		
		//UpDown �������I(������)
		
//		array<float>^ControlPt_X;
//		array<float>^ControlPt_Y;
//		array<float>^ Pt_X;
//		array<float>^ Pt_Y;
//		array<float>^ Den_X;
//		array<float>^ Den_Y;

		//��������ø�ϵ���
		Graphics^ Vertical_Window;

		// Reference ��B-Spline Curve�I
//		array<float>^ Pt_X_Ref;
//		array<float>^ Pt_Y_Ref;

		//LeftRight �������I

//		array<float>^ControlPt_X_L;
//		array<float>^ControlPt_Y_L;
//		array<float>^ Pt_X_L;
//		array<float>^ Pt_Y_L;
//		array<float>^ Den_X_L;
//		array<float>^ Den_Y_L;
				
		Graphics^ Horizontal_Window;
		
	
		// Reference ��B-Spline Curve�I
//		array<float>^ Pt_X_Ref_H;
//		array<float>^ Pt_Y_Ref_H;



//		float MaxDen;
//		float MinDen;
		//�����
//		int MeshNumber ;

		//�@�Τ��������I
		int CurrentControlPt_Index ;
		//�@�Τ�������
		int Active_Window;
		
		
		int FrameSize_W;
		int FrameSize_H;

		//�@�Τ�������
//		int Active_Window;


		//�����w�İ�,��֭��e�ɭԵe�����{��

		//�y�мȦs��---���|���sø��
	//	BufferedGraphicsContext^ Basecontext1;
	//	BufferedGraphics^ Basegrafx1;
	//	BufferedGraphicsContext^ Basecontext2;
	//	BufferedGraphics^ Basegrafx2;


		//�ϧμȦs��---�|���s�e��
	    BufferedGraphicsContext^ context1;
		BufferedGraphics^ grafx1;
		BufferedGraphicsContext^ context2;
		BufferedGraphics^ grafx2;



		//�ϧεe�b�O���餤
		MemoryStream^ Vertical_Pic_MemoryStream_Base;
		MemoryStream^ Vertical_Pic_MemoryStream_Curve;
		MemoryStream^ Horizontal_Pic_MemoryStream_Base;
		MemoryStream^ Horizontal_Pic_MemoryStream_Curve;

		Metafile^ Vertical_Pic_Metafile_Base;
		Metafile^ Vertical_Pic_Metafile_Curve;
		Metafile^ Horizontal_Pic_Metafile_Base;
		Metafile^ Horizontal_Pic_Metafile_Curve;


		//Screen �y�ЩM��ڮy���ഫ
		TranslateModule^  TranslateFormula;



		//�ƹ���쪺�����I
		int MouseSelectControllPt;

		//Flag
		bool flagMoveControllPt;


		// �e���u
//		void DrawB_Spline_Curve(Graphics^ CurrentDraw,array<float>^ CurrentPt_X,array<float>^ CurrentPt_Y ,array<float>^ CurrentControl_Pt_X ,array<float>^ CurrentControl_Pt_Y);

		//�e�����I�@�@��J���ܼƬ��@�Τ������I�bViewCoord���y��
		
//		void DrawB_Controll_Pt(Graphics^ CurrentDraw,array<float>^ Current_Control_Pt_X ,array<float>^ Current_Control_Pt_Y);

		//�Ʈy��
		void DrawCoordinate(float X_Coordinate_Range, float Y_Coordinate_Range , Graphics^ CurrentDraw ,int Grid_Number);  
		
		//�ɮת���
		String^ fileVersion;
		
		
	

		//�ഫ�����I��ƶǨ�Curve
		void TranslateDatatoCurve();


		//20080829 ----New B-Spline

		B_Spline_Curve^ tmpCurve_Vertical;
		B_Spline_Curve^ tmpCurve_Horizontal;

	
	public:
	
		B_Spline_Curve^ Curve_Vertical;
		B_Spline_Curve^ Curve_Horizontal;

	//	PointF LGPDimension;
		RectangleF LGPInformation;
	

		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SmoothDensityEditForm::typeid));
			this->Distribution_Vertical = (gcnew System::Windows::Forms::PictureBox());
			this->Distribution_Horizontal = (gcnew System::Windows::Forms::PictureBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->labelShow1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnsavecontrollpt = (gcnew System::Windows::Forms::Button());
			this->btnopencontrollpt = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_ControlPtLocation = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_ControlPt_Den = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Distribution_Vertical))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Distribution_Horizontal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_ControlPtLocation))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_ControlPt_Den))->BeginInit();
			this->SuspendLayout();
			// 
			// Distribution_Vertical
			// 
			this->Distribution_Vertical->BackColor = System::Drawing::Color::Gainsboro;
			this->Distribution_Vertical->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Distribution_Vertical->Location = System::Drawing::Point(31, 35);
			this->Distribution_Vertical->Name = L"Distribution_Vertical";
			this->Distribution_Vertical->Size = System::Drawing::Size(551, 243);
			this->Distribution_Vertical->TabIndex = 0;
			this->Distribution_Vertical->TabStop = false;
			this->Distribution_Vertical->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_MouseMove);
			this->Distribution_Vertical->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_MouseDoubleClick);
			this->Distribution_Vertical->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_MouseClick);
			this->Distribution_Vertical->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_MouseDown);
			this->Distribution_Vertical->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_Paint);
			this->Distribution_Vertical->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Vertical_MouseUp);
			// 
			// Distribution_Horizontal
			// 
			this->Distribution_Horizontal->BackColor = System::Drawing::Color::Gainsboro;
			this->Distribution_Horizontal->Location = System::Drawing::Point(31, 294);
			this->Distribution_Horizontal->Name = L"Distribution_Horizontal";
			this->Distribution_Horizontal->Size = System::Drawing::Size(551, 243);
			this->Distribution_Horizontal->TabIndex = 1;
			this->Distribution_Horizontal->TabStop = false;
			this->Distribution_Horizontal->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseMove);
			this->Distribution_Horizontal->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_Click);
			this->Distribution_Horizontal->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseDoubleClick);
			this->Distribution_Horizontal->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseClick);
			this->Distribution_Horizontal->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseDown);
			this->Distribution_Horizontal->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_Paint);
			this->Distribution_Horizontal->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseUp);
			this->Distribution_Horizontal->MouseEnter += gcnew System::EventHandler(this, &SmoothDensityEditForm::Distribution_Horizontal_MouseEnter);
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(700, 470);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(84, 30);
			this->btnOK->TabIndex = 3;
			this->btnOK->Text = L"�M��";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::btnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(699, 506);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(84, 31);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"���}";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::btnCancel_Click);
			// 
			// labelShow1
			// 
			this->labelShow1->AutoSize = true;
			this->labelShow1->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->labelShow1->Location = System::Drawing::Point(8, 49);
			this->labelShow1->Name = L"labelShow1";
			this->labelShow1->Size = System::Drawing::Size(17, 204);
			this->labelShow1->TabIndex = 5;
			this->labelShow1->Text = L"��\r\n\r\n��\r\n\r\n��\r\n\r\n�_\r\n\r\n��\r\n\r\n�K\r\n\r\n��\r\n\r\n��\r\n\r\n�G";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(8, 310);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 204);
			this->label1->TabIndex = 6;
			this->label1->Text = L"��\r\n\r\n��\r\n\r\n��\r\n\r\n�_\r\n\r\n��\r\n\r\n�K\r\n\r\n��\r\n\r\n��\r\n\r\n�G";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(599, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(215, 12);
			this->label2->TabIndex = 7;
			this->label2->Text = L"�K�ס@=�@�������K�ס@��@�������K��";
			// 
			// btnsavecontrollpt
			// 
			this->btnsavecontrollpt->Enabled = false;
			this->btnsavecontrollpt->Location = System::Drawing::Point(700, 433);
			this->btnsavecontrollpt->Name = L"btnsavecontrollpt";
			this->btnsavecontrollpt->Size = System::Drawing::Size(83, 31);
			this->btnsavecontrollpt->TabIndex = 9;
			this->btnsavecontrollpt->Text = L"�s��";
			this->btnsavecontrollpt->UseVisualStyleBackColor = true;
			this->btnsavecontrollpt->Visible = false;
			this->btnsavecontrollpt->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::btnsavecontrollpt_Click);
			// 
			// btnopencontrollpt
			// 
			this->btnopencontrollpt->Location = System::Drawing::Point(610, 506);
			this->btnopencontrollpt->Name = L"btnopencontrollpt";
			this->btnopencontrollpt->Size = System::Drawing::Size(83, 31);
			this->btnopencontrollpt->TabIndex = 10;
			this->btnopencontrollpt->Text = L"�}���°Ѽ�";
			this->btnopencontrollpt->UseVisualStyleBackColor = true;
			this->btnopencontrollpt->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::btnopencontrollpt_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &SmoothDensityEditForm::saveFileDialog1_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &SmoothDensityEditForm::openFileDialog1_FileOk);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(599, 155);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 12);
			this->label3->TabIndex = 15;
			this->label3->Text = L"�@�Τ������I��m :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(599, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 12);
			this->label4->TabIndex = 16;
			this->label4->Text = L"�@�Τ������I�K�� :";
			// 
			// numericUpDown_ControlPtLocation
			// 
			this->numericUpDown_ControlPtLocation->DecimalPlaces = 2;
			this->numericUpDown_ControlPtLocation->Location = System::Drawing::Point(712, 150);
			this->numericUpDown_ControlPtLocation->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->numericUpDown_ControlPtLocation->Name = L"numericUpDown_ControlPtLocation";
			this->numericUpDown_ControlPtLocation->Size = System::Drawing::Size(71, 22);
			this->numericUpDown_ControlPtLocation->TabIndex = 17;
			this->numericUpDown_ControlPtLocation->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::numericUpDown_ControlPtLocation_Click);
			this->numericUpDown_ControlPtLocation->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SmoothDensityEditForm::numericUpDown_ControlPtLocation_KeyDown);
			// 
			// numericUpDown_ControlPt_Den
			// 
			this->numericUpDown_ControlPt_Den->DecimalPlaces = 2;
			this->numericUpDown_ControlPt_Den->Location = System::Drawing::Point(712, 178);
			this->numericUpDown_ControlPt_Den->Name = L"numericUpDown_ControlPt_Den";
			this->numericUpDown_ControlPt_Den->Size = System::Drawing::Size(71, 22);
			this->numericUpDown_ControlPt_Den->TabIndex = 18;
			this->numericUpDown_ControlPt_Den->Click += gcnew System::EventHandler(this, &SmoothDensityEditForm::numericUpDown_ControlPt_Den_Click);
			this->numericUpDown_ControlPt_Den->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SmoothDensityEditForm::numericUpDown_ControlPt_Den_KeyDown);
			// 
			// SmoothDensityEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 571);
			this->Controls->Add(this->Distribution_Vertical);
			this->Controls->Add(this->numericUpDown_ControlPt_Den);
			this->Controls->Add(this->numericUpDown_ControlPtLocation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnopencontrollpt);
			this->Controls->Add(this->btnsavecontrollpt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelShow1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->Distribution_Horizontal);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"SmoothDensityEditForm";
			this->Text = L"SmoothDensityEditForm";
			this->Load += gcnew System::EventHandler(this, &SmoothDensityEditForm::SmoothDensityEditForm_Load);
			this->Shown += gcnew System::EventHandler(this, &SmoothDensityEditForm::SmoothDensityEditForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Distribution_Vertical))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Distribution_Horizontal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_ControlPtLocation))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_ControlPt_Den))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void SmoothDensityEditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 
//			ControlPt_X = gcnew array<float>(0);
//			ControlPt_Y = gcnew array<float>(0);
//			ControlPt_X_L = gcnew array<float>(0);
//			ControlPt_Y_L = gcnew array<float>(0);

//			Pt_X = gcnew array<float>(0);
//			Pt_Y = gcnew array<float>(0);
//			Pt_X_L = gcnew array<float>(0);
//			Pt_Y_L = gcnew array<float>(0);


//			Pt_X_Ref = gcnew array<float>(0);
//			Pt_Y_Ref = gcnew array<float>(0);
//			Pt_X_Ref_H = gcnew array<float>(0);
//			Pt_Y_Ref_H = gcnew array<float>(0);


		

			

			Distribution_Horizontal->Size = System::Drawing::Size(FrameSize_W,FrameSize_H);
			Distribution_Vertical->Size = System::Drawing::Size(FrameSize_W,FrameSize_H);


			

		//	this->Curve_Vertical->Set_k_Value(3);
		//	this->Curve_Horizontal->Set_k_Value(3);
		
			this->Curve_Vertical = gcnew B_Spline_Curve();
			this->Curve_Horizontal = gcnew B_Spline_Curve();
			this->Curve_Vertical->ControllPt->InsertRange(0,this->tmpCurve_Vertical->ControllPt);
			this->Curve_Horizontal->ControllPt->InsertRange(0,this->tmpCurve_Horizontal->ControllPt);
			this->Curve_Vertical->Set_k_Value(this->tmpCurve_Vertical->Get_k_Value());
			this->Curve_Horizontal->Set_k_Value(this->tmpCurve_Horizontal->Get_k_Value());
		//	this->Curve_Horizontal->ReProduceCurve(100);
		//	this->Curve_Vertical->ReProduceCurve(100);
			
	


			FlagMouseAction = true;
			fileVersion = "1.1.0" ;

			
			






				
}

private: System::Void SmoothDensityEditForm_Shown(System::Object^  sender, System::EventArgs^  e) {


		//	 ShowMeshGrid->Text = "�����  =  " + Convert::ToString(pinputdata->MeshNumber[0]) + "  X  " + Convert::ToString(pinputdata->MeshNumber[1]);
		//	 ShoePatternPlate->Text = "�G�I�ϰ�   =  " + Convert::ToString(pinputdata->PlateWidth) + "  X  " + Convert::ToString(pinputdata->PlateHeight);


	
			Vertical_Pic_MemoryStream_Base = gcnew MemoryStream();			
			Graphics^ tmpG = this->Distribution_Vertical->CreateGraphics();		
			Vertical_Pic_Metafile_Base =gcnew Metafile(Vertical_Pic_MemoryStream_Base,tmpG->GetHdc(),Rectangle(0,0,FrameSize_W,FrameSize_H),MetafileFrameUnit::Pixel);
			tmpG->ReleaseHdc();
			
			// --- 20080903--------ø��------
			Graphics^ g = g->FromImage(Vertical_Pic_Metafile_Base);
			g->PageScale = 1;
			g->PageUnit= GraphicsUnit::Pixel;
            //�y�мȦs��(������)
			g->Clip =gcnew System::Drawing::Region( Rectangle(0,0,FrameSize_W,FrameSize_H) );
			g->Clear(Color::Black);
			//�e�������_���y��
			DrawCoordinate(this->LGPInformation.Height,1,g,5);
			//�e���
			g->DrawRectangle(gcnew Pen( Color::Red,5),0,0,FrameSize_W,FrameSize_H);
			delete g;
			grafx1->Graphics->DrawImage(Vertical_Pic_Metafile_Base,0,0);




				
			Horizontal_Pic_MemoryStream_Base = gcnew MemoryStream();			
			Graphics^ tmpG2 = this->Distribution_Horizontal->CreateGraphics();		
			Horizontal_Pic_Metafile_Base =gcnew Metafile(Horizontal_Pic_MemoryStream_Base,tmpG2->GetHdc(),Rectangle(0,0,FrameSize_W,FrameSize_H),MetafileFrameUnit::Pixel);
			tmpG2->ReleaseHdc();
			
			// --- 20080903--------ø��------
			Graphics^ g2 = g2->FromImage(Horizontal_Pic_Metafile_Base);
			g2->PageScale = 1;
			g2->PageUnit= GraphicsUnit::Pixel;
            //�y�мȦs��(������)
			g2->Clip =gcnew System::Drawing::Region( Rectangle(0,0,FrameSize_W,FrameSize_H) );
			g2->Clear(Color::Black);
			//�e�������_���y��
			DrawCoordinate(this->LGPInformation.Width,1,g2,5);
			//�e���
			g2->DrawRectangle(gcnew Pen( Color::Red,5),0,0,FrameSize_W,FrameSize_H);
			delete g2;
			grafx2->Graphics->DrawImage(Horizontal_Pic_Metafile_Base,0,0);




			//�bGrafx1 �eCurve
			Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
			this->Curve_Vertical->ReProduceCurve(1000,tmpBoundary);
			//this->Curve_Vertical->ReProduceCurve(100);
			Pen^ redPen = gcnew Pen( Color::Red);
			grafx1->Graphics->DrawLines(redPen,Curve_Vertical->GetCurve());  
			//delete redPen;
		
			//�eControl Pt

			SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
			for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
				PointF tmppt = Curve_Vertical->ControllPt->default[i];	
				if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
				else  Brush->Color = Color::Purple;

				grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

			}

			grafx1->Render(Vertical_Window);


			//�bGrafx2 �eCurve
			//Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
			this->Curve_Horizontal->ReProduceCurve(1000,tmpBoundary);
			//this->Curve_Horizontal->ReProduceCurve(100);
			//Pen^ redPen = gcnew Pen( Color::Red);
			grafx2->Graphics->DrawLines(redPen,Curve_Horizontal->GetCurve());  
			//delete redPen;
		
			//�eControl Pt

			//SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
			for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
				PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
				if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
				else  Brush->Color = Color::Purple;

				grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

			}

			grafx2->Render(Horizontal_Window);





/*

			//�y�мȦs��(������)
			Basegrafx2->Graphics->Clear(Color::Black);
			//�e�y��
			DrawCoordinate(pinputdata->PlateWidth,1,Basegrafx2->Graphics,5);
			//DrawCoordinate(pinputdata->PlateWidth,pinputdata->PlateHeight,MaxDen,MinDen,Basegrafx2->Graphics);
			//�e���
			Basegrafx2->Graphics->DrawRectangle(gcnew Pen( Color::Red,5),0,0,FrameSize_W,FrameSize_H);

			Basegrafx2->Render(grafx2->Graphics);


			*/


			
			

			
			
			
			
			
			


		 }
//�������ϧγB�z

private: System::Void Distribution_Vertical_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			
			//�����ܼ� ,��Array ����
			
	//		 if(Active_Window != 1){
		
	//			Active_Window = 1;				
			 SmoothDensityEditForm::numericUpDown_ControlPtLocation->Maximum = Convert::ToDecimal(this->LGPInformation.Height+20);
			 SmoothDensityEditForm::numericUpDown_ControlPt_Den->Maximum = Convert::ToDecimal(120);
				//�e���
			 this->labelShow1->BackColor= Color::Red;
			 this->label1->BackColor= Color::Transparent;
	//		 }
		 }
private: System::Void Distribution_Vertical_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {


			 //�b�}�Ҫ�� ,�}���ɮ� ,�����ɮ׮ɷ|���s�e�� 
			
			grafx1->Render(e->Graphics);
			
	
			
		 }

private: System::Void Distribution_Vertical_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 

			 if(CurrentControlPt_Index != -1 && Active_Window == 1) {

					Rectangle tmpRec(e->X-5,e->Y-5,10,10);
					Point tmpPt;
					tmpPt.X = int(Curve_Vertical->ControllPt->default[CurrentControlPt_Index].X);
					tmpPt.Y = int(Curve_Vertical->ControllPt->default[CurrentControlPt_Index].Y);

					if(tmpRec.Contains(tmpPt) == true){
						flagMoveControllPt = true;
						this->Cursor = System::Windows::Forms::Cursors::Hand;					
					}
			 }

};			
private: System::Void Distribution_Vertical_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


		 //���ʷƹ�
			 if(e->Button == ::MouseButtons::Left && flagMoveControllPt == true){
				Point tmpPt;
				tmpPt.X = int(Curve_Vertical->ControllPt->default[CurrentControlPt_Index].X);
				tmpPt.Y = int(Curve_Vertical->ControllPt->default[CurrentControlPt_Index].Y);

			

					grafx1->Graphics->DrawImage(Vertical_Pic_Metafile_Base,0,0);	

					//�]�w�@�Τ������I����m
					Curve_Vertical->ControllPt->default[CurrentControlPt_Index] = Point(e->X,e->Y);

					//�P�_���b���ʤ��������I�O�_���V�L�t�@�����I ,�����ܫh�i��Index�ܴ����ʧ@
					PointF tmpLeftPt(0.0f,0.0f) ,tmpRightPt((float)FrameSize_W,0.0f);
					if(CurrentControlPt_Index > 0) 
						tmpLeftPt = Curve_Vertical->ControllPt->default[CurrentControlPt_Index-1];
					else
						tmpLeftPt.X = Curve_Vertical->ControllPt->default[CurrentControlPt_Index].X -0.01f;

					if(CurrentControlPt_Index < Curve_Vertical->ControllPt->Count-1)
						tmpRightPt = Curve_Vertical->ControllPt->default[CurrentControlPt_Index + 1];
					else
						tmpRightPt.X = Curve_Vertical->ControllPt->default[CurrentControlPt_Index ].X + 0.01f;


					//��ܦV���V�L�Y�@�����I
					if(e->X < tmpLeftPt.X) {
						Curve_Vertical->ControllPt->Reverse(CurrentControlPt_Index-1,2);
						CurrentControlPt_Index = CurrentControlPt_Index -1;
					}
					//��ܦV�k�V�L�Y�@�����I
					if(e->X > tmpRightPt.X) {
						Curve_Vertical->ControllPt->Reverse(CurrentControlPt_Index,2);
						CurrentControlPt_Index = CurrentControlPt_Index +1;
					}


				
					

					//��ܱ����I����m�M�K��
					PointF CurvePt(0.0f,0.0f);
					SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);
					CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(Curve_Vertical->ControllPt->default[CurrentControlPt_Index],frameSize,30,30,this->LGPInformation.Height,100);
					this->numericUpDown_ControlPt_Den->Text = Convert::ToString(CurvePt.Y);
					this->numericUpDown_ControlPtLocation->Text = Convert::ToString(CurvePt.X);
						
					

					//�bGrafx1 �eCurve
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Vertical->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Vertical->ReProduceCurve(100);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx1->Graphics->DrawLines(redPen,Curve_Vertical->GetCurve());  
					delete redPen;
				
					//�eControl Pt

					SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
					for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
						PointF tmppt = Curve_Vertical->ControllPt->default[i];	
						if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
						else  Brush->Color = Color::Purple;

						grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

					}

					grafx1->Render(Vertical_Window);
			
			}

}


private: System::Void Distribution_Vertical_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


			 flagMoveControllPt = false;
			 this->Cursor = System::Windows::Forms::Cursors::Default;


}		 
private: System::Void Distribution_Vertical_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			

			 //Double Click : �@�άO�]�w�@�Τ��������I
			 //�Y�����ʧ@�h��O�n�]�w�������I���@�Τ��������I

			
			 if (MouseSelectControllPt != -1) {

				//��ܥثe��쪺�����I�OVecterical Window
				Active_Window = 1;

				CurrentControlPt_Index = MouseSelectControllPt;

				

				PointF ScreenPt = Curve_Vertical->ControllPt->default[CurrentControlPt_Index];
				SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);

				PointF CurvePt(0,0);
				CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(ScreenPt,frameSize,30,30,this->LGPInformation.Height,100);
				this->numericUpDown_ControlPt_Den->Enabled = true;
				this->numericUpDown_ControlPtLocation->Enabled = true;
				this->numericUpDown_ControlPt_Den->Text = Convert::ToString(CurvePt.Y);
				this->numericUpDown_ControlPtLocation->Text = Convert::ToString(CurvePt.X);


				//�eControl Pt
				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Vertical->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
				
				grafx1->Render(Vertical_Window);

			 }
			

		 }

private: System::Void Distribution_Vertical_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


			  //�P�O�Y���@�Τ��������I ,�O���O��ø�ϰϪ������I ,�Y���O ,�h�N�@�Τ��������I�ܦ��D�@�Τ�
			 if (CurrentControlPt_Index != -1 && Active_Window != 1)  CurrentControlPt_Index = -1;

			grafx1->Graphics->DrawImage(Vertical_Pic_Metafile_Base,0,0);


			 //�P�O�O�_�ƹ������챱�m�I 
			 	Rectangle tmpRec(e->X-5,e->Y-5,10,10);
				PointF ScreenPt((float)e->X,(float)e->Y);		

				MouseSelectControllPt = -1;

				for(int i=0;i<Curve_Vertical->ControllPt->Count;i++){
					Point tmpPt;
					tmpPt.X = int(Curve_Vertical->ControllPt->default[i].X);
					tmpPt.Y = int(Curve_Vertical->ControllPt->default[i].Y);

					if(tmpRec.Contains(tmpPt) == true) {
						MouseSelectControllPt = i;					
						break;
					}

				};


				


				 if(e->Button == ::MouseButtons::Right && CurrentControlPt_Index != -1){ 
					 
					 String^ message = "�O�_�R���������I ?";
					 String^ caption = "�����I";
					 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
					 System::Windows::Forms::DialogResult result;

					// Displays the MessageBox.
					 result = MessageBox::Show( message, caption, buttons );
					 if ( result == ::DialogResult::Yes && Curve_Vertical->ControllPt->Count >2 )
					 {
						Curve_Vertical->ControllPt->RemoveAt(CurrentControlPt_Index);
						CurrentControlPt_Index = -1;						
					 }else if(result == ::DialogResult::Yes){
						 MessageBox::Show("�����I�ƥؤ��o�p�� 2 !!!");
					 }

				 }


				//�b�D�����I���a����U�ƹ�����ɦ���ذʧ@ ...

				//�Y�ƹ��O�b�S���I�챱���I,�B�S���]�w�@�Τ��������I ,�h��ܼW�[�����I~~

				 if(e->Button == ::MouseButtons::Left && MouseSelectControllPt == -1 && CurrentControlPt_Index ==-1){
						
					 //��ܼW�[�����I
						 //20080829
							PointF tmpPt((float)e->X,(float)e->Y);
							Curve_Vertical->ControllPt->Add(tmpPt);	
							Curve_Vertical->ControllPt->Sort(gcnew Comparison<PointF>(ComapreControllPt));
							
				 }else if(e->Button == ::MouseButtons::Left && MouseSelectControllPt == -1 && CurrentControlPt_Index !=-1 && Active_Window == 1) {
					//�Y�Y�ƹ��S���I�챱���I,�B���]�w�@�Τ��������I(�åB�O�b�@�Τ������W) ,�h��ܧ�@�Τ��������I�ܦ��S���@�Τ�
						CurrentControlPt_Index = MouseSelectControllPt ;
						this->numericUpDown_ControlPt_Den->Enabled = false;
						this->numericUpDown_ControlPtLocation->Enabled = false;
				 }
              
			   //�N�y�и�T��JGrafx1��

			   //�bGrafx1
			   this->Curve_Vertical->Set_k_Value(Curve_Vertical->ControllPt->Count);
			 			
			
				//�eControl Pt

				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Vertical->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
			    


				//�eCurve
				//�]�w�eCurve����ɭ� ,�W�L�ܳ]�����u
				if(Curve_Vertical->ControllPt->Count >= 2) {
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Vertical->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Vertical->ReProduceCurve(1000);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx1->Graphics->DrawLines(redPen,Curve_Vertical->GetCurve());  
					delete redPen;
				}

			   grafx1->Render(Vertical_Window);
			   
			 


		 }	


//�������ϧγB�z

private: System::Void Distribution_Horizontal_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			
/*
			 if (Active_Window != 2) {
				CurrentControlPt_Index = -1;
				Active_Window = 2;
				SmoothDensityEditForm::numericUpDown_ControlPtLocation->Maximum = Convert::ToDecimal(pinputdata->PlateWidth+20);
				SmoothDensityEditForm::numericUpDown_ControlPt_Den->Maximum = Convert::ToDecimal(120);
				

				this->label1->BackColor= Color::Red;
				this->labelShow1->BackColor= Color::Transparent;
				//�e���

			//	grafx1->Graphics->DrawRectangle(gcnew Pen( Color::Black,5),0,0,FrameSize_W,FrameSize_H);
			//	grafx1->Render(Vertical_Window);
			//	grafx2->Graphics->DrawRectangle(gcnew Pen( Color::Red,5),0,0,FrameSize_W,FrameSize_H);
			//	grafx2->Render(Horizontal_Window);
			}
*/
		 }
private: System::Void Distribution_Horizontal_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		
			 //�b�}�Ҫ�� ,�}���ɮ� ,�����ɮ׮ɷ|���s�e�� 
			
			 grafx2->Render(e->Graphics);

		 }






private: System::Void Distribution_Horizontal_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if(CurrentControlPt_Index != -1 && Active_Window == 2 ) {

					Rectangle tmpRec(e->X-5,e->Y-5,10,10);
					Point tmpPt;
					tmpPt.X = int(Curve_Horizontal->ControllPt->default[CurrentControlPt_Index].X);
					tmpPt.Y = int(Curve_Horizontal->ControllPt->default[CurrentControlPt_Index].Y);

					if(tmpRec.Contains(tmpPt) == true){
						flagMoveControllPt = true;
						this->Cursor = System::Windows::Forms::Cursors::Hand;					
					}
			 }


		 }
private: System::Void Distribution_Horizontal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	

			  //���ʷƹ�
			 if(e->Button == ::MouseButtons::Left && flagMoveControllPt == true){
				Point tmpPt;
				tmpPt.X = int(Curve_Horizontal->ControllPt->default[CurrentControlPt_Index].X);
				tmpPt.Y = int(Curve_Horizontal->ControllPt->default[CurrentControlPt_Index].Y);

			

					grafx2->Graphics->DrawImage(Horizontal_Pic_Metafile_Base,0,0);	

					//�]�w�@�Τ������I����m
					Curve_Horizontal->ControllPt->default[CurrentControlPt_Index] = PointF((float)e->X,(float)e->Y);

					//�P�_���b���ʤ��������I�O�_���V�L�t�@�����I ,�����ܫh�i��Index�ܴ����ʧ@
					PointF tmpLeftPt(0,0) ,tmpRightPt((float)FrameSize_W,0);
					if(CurrentControlPt_Index > 0) 
						tmpLeftPt = Curve_Horizontal->ControllPt->default[CurrentControlPt_Index-1];
					else
						tmpLeftPt.X = Curve_Horizontal->ControllPt->default[CurrentControlPt_Index].X -0.01f;

					if(CurrentControlPt_Index < Curve_Horizontal->ControllPt->Count-1)
						tmpRightPt = Curve_Horizontal->ControllPt->default[CurrentControlPt_Index + 1];
					else
						tmpRightPt.X = Curve_Horizontal->ControllPt->default[CurrentControlPt_Index ].X + 0.01f;


					//��ܦV���V�L�Y�@�����I
					if(e->X < tmpLeftPt.X) {
						Curve_Horizontal->ControllPt->Reverse(CurrentControlPt_Index-1,2);
						CurrentControlPt_Index = CurrentControlPt_Index -1;
					}
					//��ܦV�k�V�L�Y�@�����I
					if(e->X > tmpRightPt.X) {
						Curve_Horizontal->ControllPt->Reverse(CurrentControlPt_Index,2);
						CurrentControlPt_Index = CurrentControlPt_Index +1;
					}


				
					

					//��ܱ����I����m�M�K��
					PointF CurvePt(0,0);
					SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);
					CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(Curve_Horizontal->ControllPt->default[CurrentControlPt_Index],frameSize,30,30,this->LGPInformation.Width,100);
					this->numericUpDown_ControlPt_Den->Text = Convert::ToString(CurvePt.Y);
					this->numericUpDown_ControlPtLocation->Text = Convert::ToString(CurvePt.X);


					//�bGrafx1 �eCurve
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Horizontal->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Horizontal->ReProduceCurve(100);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx2->Graphics->DrawLines(redPen,Curve_Horizontal->GetCurve());  
					delete redPen;
				
					//�eControl Pt

					SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
					for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
						PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
						if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
						else  Brush->Color = Color::Purple;

						grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

					}

					grafx2->Render(Horizontal_Window);
			
			}

/*
			//�e Ref Curve
			if (chkShowRefCurve->Checked == true && Pt_X_Ref_H->Length>0 && Pt_Y_Ref_H->Length>0){
				Pen^ PurplePen = gcnew Pen( Color::Purple);
				for(int i = 0 ; i<Pt_X_Ref_H->Length-1 ; i++){				 
					 grafx2->Graphics->DrawLine(PurplePen,(float)Pt_X_Ref_H->GetValue(i),(float)Pt_Y_Ref_H->GetValue(i)
						 ,(float)Pt_X_Ref_H->GetValue(i+1),(float)Pt_Y_Ref_H->GetValue(i+1));
				};
				delete PurplePen;
			}
			DrawB_Controll_Pt(grafx2->Graphics,ControlPt_X_L,ControlPt_Y_L);

	

			//�e�w������
			GetPredictLuminance_Line();


	

			grafx2->Render(Horizontal_Window);
*/


		}
	
private: System::Void Distribution_Horizontal_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


		flagMoveControllPt = false;
		this->Cursor = System::Windows::Forms::Cursors::Default;

	}

private: System::Void Distribution_Horizontal_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			//Double Click : �@�άO�]�w�@�Τ��������I
			 //�Y�����ʧ@�h��O�n�]�w�������I���@�Τ��������I

			
			 if (MouseSelectControllPt != -1) {


				this->numericUpDown_ControlPt_Den->Enabled = true;
				this->numericUpDown_ControlPtLocation->Enabled = true;

				//��ܥثe��쪺�����I�OHorizontal Window
				Active_Window = 2;

				CurrentControlPt_Index = MouseSelectControllPt;

								
				PointF ScreenPt = Curve_Horizontal->ControllPt->default[CurrentControlPt_Index];
				SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);

				PointF CurvePt(0,0);
				CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(ScreenPt,frameSize,30,30,this->LGPInformation.Width,100);
				this->numericUpDown_ControlPt_Den->Text = Convert::ToString(CurvePt.Y);
				this->numericUpDown_ControlPtLocation->Text = Convert::ToString(CurvePt.X);


				//�eControl Pt
				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
				
				grafx2->Render(Horizontal_Window);

			 }


		 }
private: System::Void Distribution_Horizontal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
			 //�P�O�Y���@�Τ��������I ,�O���O��ø�ϰϪ������I ,�Y���O ,�h�N�@�Τ��������I�ܦ��D�@�Τ�
			 if (CurrentControlPt_Index != -1 && Active_Window != 2) CurrentControlPt_Index = -1;
			 //(Note : ��Mouse Dowm��A Mouse Click)
			 
			 
			 grafx2->Graphics->DrawImage(Horizontal_Pic_Metafile_Base,0,0);


			 //�P�O�O�_�ƹ������챱�m�I 
			 	Rectangle tmpRec(e->X-5,e->Y-5,10,10);
				PointF ScreenPt((float)e->X,(float)e->Y);		

				MouseSelectControllPt = -1;

				for(int i=0;i<Curve_Horizontal->ControllPt->Count;i++){
					Point tmpPt;
					tmpPt.X = int(Curve_Horizontal->ControllPt->default[i].X);
					tmpPt.Y = int(Curve_Horizontal->ControllPt->default[i].Y);

					if(tmpRec.Contains(tmpPt) == true) {
						MouseSelectControllPt = i;					
						break;
					}

				};


				


				 if(e->Button == ::MouseButtons::Right && CurrentControlPt_Index != -1){ 
					 
					 String^ message = "�O�_�R���������I ?";
					 String^ caption = "�����I";
					 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
					 
					 System::Windows::Forms::DialogResult result;

					// Displays the MessageBox.
					
					 result = MessageBox::Show( message, caption, buttons );
					 if ( result == ::DialogResult::Yes && Curve_Horizontal->ControllPt->Count > 2 )
					 {
						Curve_Horizontal->ControllPt->RemoveAt(CurrentControlPt_Index);
						CurrentControlPt_Index = -1;						
					 }else if(result == ::DialogResult::Yes){
						 MessageBox::Show("�����I�ƥؤ��o�p�� 2 !!!");
					 }

				 }


				//�b�D�����I���a����U�ƹ�����ɦ���ذʧ@ ...

				//�Y�ƹ��O�b�S���I�챱���I,�B�S���]�w�@�Τ��������I ,�h��ܼW�[�����I~~

				 if(e->Button == ::MouseButtons::Left && MouseSelectControllPt == -1 && CurrentControlPt_Index ==-1){
						
					 //��ܼW�[�����I
						 //20080829
							PointF tmpPt((float)e->X,(float)e->Y);
							Curve_Horizontal->ControllPt->Add(tmpPt);	
							Curve_Horizontal->ControllPt->Sort(gcnew Comparison<PointF>(ComapreControllPt));
							
				 }else if(e->Button == ::MouseButtons::Left && MouseSelectControllPt == -1 && CurrentControlPt_Index !=-1 &&  Active_Window == 2) {
					//�Y�Y�ƹ��O�b�S���I�챱���I,�B���]�w�@�Τ��������I(�b�ثe�@�Ϊ�������) ,�h��ܧ�@�Τ��������I�ܦ��S���@�Τ�
						CurrentControlPt_Index = MouseSelectControllPt ;
						this->numericUpDown_ControlPt_Den->Enabled = false;
						this->numericUpDown_ControlPtLocation->Enabled = false;
				 }
              
			   //�N�y�и�T��JGrafx1��

			   //�bGrafx1
			   this->Curve_Horizontal->Set_k_Value(Curve_Horizontal->ControllPt->Count);
			 			
			
				//�eControl Pt

				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
			    


				//�eCurve
				//�]�w�eCurve����ɭ� ,�W�L�ܳ]�����u
				if (Curve_Horizontal->ControllPt->Count >=2) {
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Horizontal->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Horizontal->ReProduceCurve(1000);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx2->Graphics->DrawLines(redPen,Curve_Horizontal->GetCurve());  
					delete redPen;
				}

			   grafx2->Render(Horizontal_Window);
			   
			 
		 }

//�ɮ׳B�z����
private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {


		this->tmpCurve_Vertical->ControllPt->Clear();
		this->tmpCurve_Horizontal->ControllPt->Clear();
		this->tmpCurve_Vertical->ControllPt->InsertRange(0,this->Curve_Vertical->ControllPt);
		this->tmpCurve_Horizontal->ControllPt->InsertRange(0,this->Curve_Horizontal->ControllPt);
		this->tmpCurve_Vertical->Set_k_Value(this->Curve_Vertical->Get_k_Value());
		this->tmpCurve_Horizontal->Set_k_Value(this->Curve_Horizontal->Get_k_Value());

		 }
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {

				
				
			  SmoothDensityEditForm::Close();


		 }
private: System::Void btnsavecontrollpt_Click(System::Object^  sender, System::EventArgs^  e) {

/*
			FlagMouseAction = false;
			saveFileDialog1->FileName = "ControlPt";
			saveFileDialog1->Filter = "ControlPt(�tTab���j�r��) (*.txt)|*.txt";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".txt";
			saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			saveFileDialog1->ShowDialog();
			FlagMouseAction = true;
*/

		 }
private: System::Void btnopencontrollpt_Click(System::Object^  sender, System::EventArgs^  e) {

//*
			FlagMouseAction = false;
			openFileDialog1->FileName = "ControlPt";
			openFileDialog1->Filter = "ControlPt(�tTab���j�r��) (*.txt)|*.txt";
			openFileDialog1->FilterIndex = 1;
			openFileDialog1->RestoreDirectory = true;
			openFileDialog1->DefaultExt=".txt";
			openFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			openFileDialog1->ShowDialog();
			FlagMouseAction = true;

//*/
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

/*
				String^ path = saveFileDialog1->FileName;
				System::IO::StreamWriter ^ sr = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);

				try{
					
					String^ str = "# ControlPt" + "	" + fileVersion;
					sr->WriteLine(str);
					str = "# ControlPt Location/Parameter Export file";
					sr->WriteLine(str);
					str = Convert::ToString(ControlPt_X->Length);
					sr->WriteLine(str);
					str = "Location_V" + "	"+"Density_V ";					
					sr->WriteLine(str);

					for(int i=0 ; i<ControlPt_X->Length ;i++){
						//�ഫ���ڮy��
						float Den = (MaxDen-MinDen)*((float)FrameSize_H-30-(float)ControlPt_Y->GetValue(i))/((float)FrameSize_H-60)*100;
						float ControlPtLocation	= (float)pinputdata->PlateHeight*((float)ControlPt_X->GetValue(i)-30)/((float)FrameSize_W-60);							
						str=String::Format("{0:F}"+"	"+"{1:F}",ControlPtLocation,Den);						
						sr->WriteLine(str);
					}
					str = Convert::ToString(ControlPt_X_L->Length);
					sr->WriteLine(str);
					str = "Locaion_H" + "	" + "Density_H";
					sr->WriteLine(str);
					for(int i=0 ; i<ControlPt_X_L->Length ;i++){
						//�ഫ���ڮy��
						float Den = (MaxDen-MinDen)*((float)FrameSize_H-30-(float)ControlPt_Y_L->GetValue(i))/((float)FrameSize_H-60)*100;
						float ControlPtLocation = (float)pinputdata->PlateWidth*((float)ControlPt_X_L->GetValue(i)-30)/((float)FrameSize_W-60);
						str=String::Format("{0:F}"+"	"+"{1:F}",ControlPtLocation,Den);	
						sr->WriteLine(str);

					}
					
					sr->Close();
					//return true;

				}catch(...){
					sr->Close();
					MessageBox::Show("ControlPt�s�ɿ��~");
					//return false;

				}
				FlagMouseAction = true;
*/
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			

//*
				bool success = false;
			 	String^ path = openFileDialog1->FileName;
				System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);

				try{

					String^ str ;
					String^ buffer;
					int verPtNumber = 0;
					int horPtNumber = 0;


				
					str = sr->ReadLine();

					//Ū���ɮת����榡
					int found = 0; 
					int compare = -1;
					found = str->IndexOf( "	" );
					buffer =str->Substring(found)->Trim();
					compare = String::Compare(buffer,fileVersion);
					if (compare != 0 ) {
						sr->Close();
						MessageBox::Show("Ū�����ɮת����P���n�餣�ۮe ,���n�餹�\������ : " + fileVersion);
						return ;
					}


					str = sr->ReadLine();

					// Up_Down Data

					str = sr->ReadLine();
					verPtNumber = Convert::ToInt32(str);
					str = sr->ReadLine();


					//�M�ű����I���,�R�������I
			//		Array::Clear(ControlPt_X,0,ControlPt_X->Length);
			//		Array::Clear(ControlPt_Y,0,ControlPt_Y->Length);
			//		Array::Resize(ControlPt_X,0) ;
			//		Array::Resize(ControlPt_Y,0) ;
			//		Array::Clear(ControlPt_X_L,0,ControlPt_X_L->Length);
			//		Array::Clear(ControlPt_Y_L,0,ControlPt_Y_L->Length);
			//		Array::Resize(ControlPt_X_L,0) ;
			//		Array::Resize(ControlPt_Y_L,0) ;

					this->Curve_Horizontal->ControllPt->Clear();
					this->Curve_Vertical->ControllPt->Clear();
		


					
					for(int i =0 ; i<verPtNumber ; i++){
						 found = 0;
						 str = sr->ReadLine();
					//	 float Xpos,Ypos;		
						 PointF Con_Pt;
						 found = str->IndexOf( "	" );
						 buffer =str->Substring(0,found);
					//	 Xpos = Convert::ToSingle(buffer);	
						 Con_Pt.X = Convert::ToSingle(buffer);	
						 buffer =str->Substring(found)->Trim();
					//	 Ypos = Convert::ToSingle(buffer);	
						 Con_Pt.Y = Convert::ToSingle(buffer);	

						 //�ഫ�ܹϭ��y��
					//	Ypos = (float)FrameSize_H-30 - Ypos* ((float)FrameSize_H-60)/100/(MaxDen-MinDen);
					//	Xpos = 30 + Xpos*((float)FrameSize_W-60)/(float)pinputdata->PlateHeight ;
						SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);
						Con_Pt= this->TranslateFormula->Translate_Pt_From_BSplineCoordinate_To_Screen(Con_Pt,frameSize,30,30,this->LGPInformation.Height,100);
						//Con_Pt.Y = (float)FrameSize_H-30 - Con_Pt.Y* ((float)FrameSize_H-60)/100/(MaxDen-MinDen);
						//Con_Pt.X = 30 + Con_Pt.X*((float)FrameSize_W-60)/(float)this->LGPDimension.Y ;

						 this->Curve_Vertical->ControllPt->Add(Con_Pt);
						// AddControlPt((int)Xpos ,(int)Ypos,0);
					}

					// Left_Right Data

					
					str = sr->ReadLine();
					horPtNumber = Convert::ToInt32(str);
					str = sr->ReadLine();
					for(int i =0 ; i<horPtNumber ; i++){
						 found = 0;
						 str = sr->ReadLine();
					//	 float Xpos,Ypos;
						 PointF Con_Pt;
						 found = str->IndexOf( "	" );
						 buffer =str->Substring(0,found);
						// Xpos = Convert::ToSingle(buffer);
						 Con_Pt.X = Convert::ToSingle(buffer);
						 buffer =str->Substring(found)->Trim();
						// Ypos = Convert::ToSingle(buffer);
						 Con_Pt.Y = Convert::ToSingle(buffer);

						 //�ഫ�ܹϭ��y��
						// Ypos = (float)FrameSize_H-30 - Ypos* ((float)FrameSize_H-60)/100/(MaxDen-MinDen);
						// Xpos = 30 + Xpos*((float)FrameSize_W-60)/(float)pinputdata->PlateWidth ;
						
						 	SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);
							Con_Pt= this->TranslateFormula->Translate_Pt_From_BSplineCoordinate_To_Screen(Con_Pt,frameSize,30,30,this->LGPInformation.Width,100);
						 // Con_Pt.Y  = (float)FrameSize_H-30 -  Con_Pt.Y * ((float)FrameSize_H-60)/100/(MaxDen-MinDen);
						 // Con_Pt.X = 30 + Con_Pt.X*((float)FrameSize_W-60)/(float)this->LGPDimension.X ;

						  this->Curve_Horizontal->ControllPt->Add(Con_Pt);
						// AddControlPt((int)Xpos ,(int)Ypos,1);
					}
					

					sr->Close();
					success = true;
						 







					
				}
				catch(...){
					sr->Close();
					this->Curve_Horizontal->xInitialize(PointF(0,120),PointF(543,120));
					this->Curve_Vertical->xInitialize(PointF(0,120),PointF(543,120));
					MessageBox::Show("ControlPtŪ�ɿ��~");
					
					//return false;
				}
				FlagMouseAction = true;



				//�e�� --------------------------------------------

				//Grafx2---------------------------------------------------------

				 grafx2->Graphics->DrawImage(Horizontal_Pic_Metafile_Base,0,0);              
				//�N�y�и�T��JGrafx1��
				//�bGrafx1
				this->Curve_Horizontal->Set_k_Value(Curve_Horizontal->ControllPt->Count);
			 						
				//�eControl Pt

				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
			    
				//�eCurve
				//�]�w�eCurve����ɭ� ,�W�L�ܳ]�����u
				if (Curve_Horizontal->ControllPt->Count >=2) {
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Horizontal->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Horizontal->ReProduceCurve(1000);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx2->Graphics->DrawLines(redPen,Curve_Horizontal->GetCurve());  
					delete redPen;
				}

			   grafx2->Render(Horizontal_Window);



				//Grafx1---------------------------------------------------------------

				grafx1->Graphics->DrawImage(Vertical_Pic_Metafile_Base,0,0);
            
			   //�N�y�и�T��JGrafx1��

			   //�bGrafx1
			   this->Curve_Vertical->Set_k_Value(Curve_Vertical->ControllPt->Count);
			 			
			
				//�eControl Pt

			//	SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Vertical->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}
			    


				//�eCurve
				//�]�w�eCurve����ɭ� ,�W�L�ܳ]�����u
				if(Curve_Vertical->ControllPt->Count >= 2) {
					Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
					this->Curve_Vertical->ReProduceCurve(1000,tmpBoundary);
					//this->Curve_Vertical->ReProduceCurve(1000);
					Pen^ redPen = gcnew Pen( Color::Red);
					grafx1->Graphics->DrawLines(redPen,Curve_Vertical->GetCurve());  
					delete redPen;
				}

			   grafx1->Render(Vertical_Window);


				// --- 20080725--------ø��------

				//----------------------------------������----------------------------------------------------------------------

				//�y�й��ɸ�T---
			//	Basegrafx1->Render(grafx1->Graphics);

	//			if (success == true) {
	//				//�e�����I
	//				DrawB_Controll_Pt(grafx1->Graphics,ControlPt_X,ControlPt_Y);
	//				//�e���u
	//				Array::Resize(Pt_X,(int) (1)/0.001+1);
	//				Array::Resize(Pt_Y,(int) (1)/0.001+1);
	//				DrawB_Spline_Curve(grafx1->Graphics,Pt_X,Pt_Y,ControlPt_X,ControlPt_Y);
	//			}
				
				//�e���
	//			grafx1->Graphics->DrawRectangle(gcnew Pen( Color::Red,5),0,0,FrameSize_W,FrameSize_H);
	//			grafx1->Render(Vertical_Window);
				

				//----------------------------------������----------------------------------------------------------------------

				//�y�й��ɸ�T---
	//			Basegrafx2->Render(grafx2->Graphics);

	//			if (success == true) {
	//				//�e�����I
	//				DrawB_Controll_Pt(grafx2->Graphics,ControlPt_X_L,ControlPt_Y_L);
	//				//�e���u
	//				Array::Resize(Pt_X_L,(int) (1)/0.001+1);
	//				Array::Resize(Pt_Y_L,(int) (1)/0.001+1);
	//				DrawB_Spline_Curve(grafx2->Graphics,Pt_X_L,Pt_Y_L,ControlPt_X_L,ControlPt_Y_L);
	//			}
				
				//�e���
	//			grafx2->Graphics->DrawRectangle(gcnew Pen( Color::Black,5),0,0,FrameSize_W,FrameSize_H);
	//			grafx2->Render(Horizontal_Window);
				








//*/				
				
		 }


		 		 

private: System::Void btnPredictSystem_Click(System::Object^  sender, System::EventArgs^  e) {
			 


		 }	


private: System::Void numericUpDown_ControlPtLocation_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if (e->KeyCode == Keys::Enter)		this->TranslateDatatoCurve();
			 
		 }
private: System::Void numericUpDown_ControlPt_Den_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			  if (e->KeyCode == Keys::Enter)		this->TranslateDatatoCurve();
		 }


private: System::Void numericUpDown_ControlPtLocation_Click(System::Object^  sender, System::EventArgs^  e) {
			  this->TranslateDatatoCurve();
		 }
private: System::Void numericUpDown_ControlPt_Den_Click(System::Object^  sender, System::EventArgs^  e) {
			  this->TranslateDatatoCurve();
		 }

private: System::Void Distribution_Horizontal_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};

}



