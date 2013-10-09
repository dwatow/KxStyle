#pragma once





#include "DataStructure.h"

//���

#include "SmoothDensityEditForm.h"
#include "SettingForm.h"
#include "SurfaceDesign.h"

#include "Cosmetic_LocalArea_Form.h"

#include "PatternGrab_Form.h"
#include "Picanalysis.h"
#include "PatternFile_Information.h"
#include "ScreenMura.h"
#include "ProjectInformation.h"
#include "DataBaseForm.h"
#include "HotSpot_Form.h"
#include "IJP_Primer_Pattern.h"



//�p�⦡
//#include "B-Spline.h"
#include <stdio.h>
#include <math.h>
#include <complex>
//#include <vector>
#include <deque>
#include <list>
//#include "Security.h"
//#include "Calculate.h"
#include "FileIO.h"
#include "FileIO_OLD.h"
#include "resource.h"



using namespace DensityClass; 
using namespace DrawModule;
using namespace Nurbs;
using namespace std;
namespace PatternContruction {

	using namespace System::Net;
	
	//using namespace System::Data;	
	using namespace System::Data::OleDb;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Security::Cryptography;

	
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here

			MainData = gcnew MainFormData();
			Dot = gcnew Pattern();
			//Density = nullptr;
		//	PatternDensity->ClearAll();
			GirdNumber.Empty;
		//	LocalSurface = gcnew array<B_Spline_Surface>(0);
			this->CurrentDictionary = "";
			this->InputFileName = "";
			
			//Mouse
		//	PreImagePos.X = 0;
		//	PreImagePos.Y = 0;
		//	Delta.X = 0;
		//	Delta.Y = 0;

			
			

			
					
			
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			
		}


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FileNewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �}������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  OpenpatternToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �x�s�ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �x�sPattern�ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���}ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �˵�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ZoomPic;

	private: System::Windows::Forms::ToolStripMenuItem^  EditToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  SaveLTPatternFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  MovePic;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ToolStripMenuItem^  ShowLGP;


	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txt_LGPWidth;
	private: System::Windows::Forms::TextBox^  txt_LGPLength;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::RadioButton^  radioBtnRegular;
	private: System::Windows::Forms::RadioButton^  radioBtnRandom;
	private: System::Windows::Forms::ToolStripMenuItem^  �]�wToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���׽վ�\��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���u�վ㧡��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����վ㧡��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �ϰ�ק�\��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �}�ұM����0901112ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �M����090112ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Label^  lblInformation;
	private: System::Windows::Forms::Label^  lblavgDen;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TabControl^  tabControll;




	private: System::Windows::Forms::TabPage^  tab_Regular;
	private: System::Windows::Forms::Label^  lbl_AllowMaxDen;
	private: System::Windows::Forms::Label^  lbl_AllowMinDen;
	private: System::Windows::Forms::Label^  lbl_DotPitch;
	private: System::Windows::Forms::ComboBox^  cboPatternArragementStyle;
	private: System::Windows::Forms::ComboBox^  comboBoxPatternShape;
	private: System::Windows::Forms::TextBox^  txt_MinDotGap;
	private: System::Windows::Forms::TextBox^  txt_MinDot;
	private: System::Windows::Forms::TextBox^  txt_maxDot;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TabPage^  tab_Random;
	private: System::Windows::Forms::Label^  lblpatdis;
	private: System::Windows::Forms::TextBox^  txt_RandomDotGap;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btn_ProducePattern;
	private: System::Windows::Forms::Button^  btn_Apply_ReqularDot_Set;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_Total_Num;
	private: System::Windows::Forms::Label^  lbl_RandomIteration;
	private: System::Windows::Forms::Label^  lbl_Current_File;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txt_RandomParaC;
	private: System::Windows::Forms::TextBox^  txt_RandomParaK;
	private: System::Windows::Forms::ComboBox^  cbo_RandomDotSimRule;
	private: System::Windows::Forms::TextBox^  txt_RandomDotSize;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Button^  btn_Accept_RandomPattern;
	private: System::Windows::Forms::Label^  lbl_RandomTotalNum;
	private: System::Windows::Forms::Label^  lbl_RandomGirdNumber;
private: System::Windows::Forms::Label^  lblVersion;

	private: System::Windows::Forms::Button^  btn_modifyDot;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ק�ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  HotBar�ק�ToolStripMenuItem;

	private: System::Windows::Forms::Button^  btnResetModifyRate;
	private: System::Windows::Forms::Label^  lbl_MaxPattern;
	private: System::Windows::Forms::Label^  lbl_MinPattern;
	private: System::Windows::Forms::Label^  lbl_AverageForce;
	private: System::Windows::Forms::Label^  lbl_AllowanceRandomDensity;
	private: System::Windows::Forms::TextBox^  txt_RandomRebuildFrequency;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  txt_RandomDotIteration;
	private: System::Windows::Forms::TextBox^  txt_RandomCuttingForce;
	private: System::Windows::Forms::CheckBox^  chkRamdomStopForce;
	private: System::Windows::Forms::CheckBox^  chkRandomStopNumber;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  lbl_SmallGapNumber;
	private: System::Windows::Forms::ToolStripMenuItem^  �u��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���I�K�פ��RToolStripMenuItem;
private: System::Windows::Forms::TabPage^  tabPageIJP;
private: System::Windows::Forms::TextBox^  IJP_txt_DotSize;
private: System::Windows::Forms::TextBox^  IJP_txt_BlockX;






	private: System::Windows::Forms::Label^  label8;


	private: System::Windows::Forms::ToolStripMenuItem^  �Ӥ���Ƨ��ToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  �������RToolStripMenuItem;
private: System::Windows::Forms::Button^  btnShowMura;
private: System::Windows::Forms::ToolStripMenuItem^  �M�׸�TToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ���׹w��ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ��ƮwToolStripMenuItem;
private: System::Windows::Forms::Label^  lbl_Pattern_File;
private: System::Windows::Forms::Label^  lblMinGap;
private: System::Windows::Forms::TextBox^  txt_DesirePitch;

private: System::Windows::Forms::ComboBox^  cboPitchDirection;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::GroupBox^  groupBox5;



private: System::Windows::Forms::CheckBox^  chkPitchSetting;
private: System::Windows::Forms::Label^  lblActualDensityRange;
private: System::Windows::Forms::Label^  lblAllowPitchRange;
private: System::Windows::Forms::Label^  lblMessage;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::RadioButton^  radioIJPBtn;


private: System::Windows::Forms::Button^  btn_IJP;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  IJP_txt_BlockY;



private: System::Windows::Forms::ToolStripMenuItem^  Save_IJP_File;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

private: System::Windows::Forms::Label^  lblTotalNumber;

private: System::Windows::Forms::Button^  btn_CuttingShape;
private: System::Windows::Forms::ToolStripMenuItem^  �~������Dxf��ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  Save_IJP_PrimerPattern;
private: System::Windows::Forms::TextBox^  IJP_txt_TextLocaY;

private: System::Windows::Forms::TextBox^  IJP_txt_TextLocaX;


private: System::Windows::Forms::TextBox^  IJP_txt_TextHeight;
private: System::Windows::Forms::TextBox^  IJP_txt_TextLength;







private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  lbl_LGP_Text;






private: System::Windows::Forms::Button^  btnY_Axis;


private: System::Windows::Forms::Button^  btnNormal;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::TextBox^  IJP_txt_TEXT;

private: System::Windows::Forms::Button^  btnX_Axis;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Button^  btnImportText;
private: System::Windows::Forms::ComboBox^  IJP_cbo_TextLocation;


private: System::Windows::Forms::ToolStripMenuItem^  �����d��ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  �ﶵToolStripMenuItem;
private: System::Windows::Forms::Label^  lblShowDen;

private: System::Windows::Forms::Label^  lblLGPLocation;
private: System::Windows::Forms::GroupBox^  group_Text;
private: System::Windows::Forms::CheckBox^  IJP_chk_TextEdit;


private: System::Windows::Forms::RadioButton^  radio_FMPattern;
private: System::Windows::Forms::TabPage^  tab_FM_Pattern;

private: System::Windows::Forms::Label^  lbl_FMMaxDen;


private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::TextBox^  txtFMPattern;

private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::TextBox^  txtFMPatternGap;

private: System::Windows::Forms::Button^  btnFMPattern;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::ComboBox^  cboIJPDPI;
private: System::Windows::Forms::Label^  label16;

private: System::ComponentModel::IContainer^  components;
private:
		/// <summary>
		/// Required designer variable.
		
		/// </summary>


#pragma region Windows Form Designer generated code

		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.

        // add by vinshen
		
		bool Produce_RegularPattern(Pattern^ Dot,Point GridNumber , RectangleF LGPSize ,int PatternArrangeMent ,GridDensity^ Density);    //���ͳW�h���I
		bool Produce_RandomPattern();    //���Ͷüƺ��I


		bool ProduceGridDensity_ByTwoCurve();  //���ͮ��I�K�� �Q�Φ��u����
		bool ProduceGridDensity();   //���ͮ��I�K��  
		bool ProduceHotSpotDensity(GridDensity^ density ,ArrayList^ hotSpotData); //����HotSpot�K��Data.
		bool ProduceHotSpotDensity(Pattern^ tmpDot ,ArrayList^ hotSpotData); //����HotSpot ���I�ܤ�.
		bool ProduceHotSpotDensity(array<float,2>^ tmpFM_DotSize ,ArrayList^ hotSpotData); //����HotSpot FM���I
		 
	//	bool ProduceGridDensity_FromDot(Point GridNumber ,GridDensity^ density ,Pattern^ dot); //���ͮ��I�K��,�Ѻ��I�p��o��,����Ƥ��i�H�Ӧh,�_�h�~�t�|�ܤj
		void CheckOverlap(int &OverlapNumber,float Pattern_Space,bool Verlert,deque<int> *relationPt);  //�ü��ˬd���I	
		void CheckInsidePlate(Point3d &pt); //�ü��ˬd���I
		void ModifyDot();  //�����ק�
		void ModifyDotRate(ArrayList^ LocalAreaPara,Pattern^ Dot);  //�����ק�-�o����I�Y���� 
		void ModifyDotRate(ArrayList^ LocalAreaPara,array<float,2>^ tmpFM_DotSize);  //�����ק�-�o����I�Y���� 

	
		void ResetAll();
		//�NMainData����ƶǨ���W�� ...
		void UpdateMainFormData(); 
		void DrawCurrentPattern();
	//	void DrawDesignGridDensity(bool DrawDensity,GridDensity^ density ,B_Spline_Surface^ surface);
		void DrawDesignGridDensity(GridDensity^ density);
		void DrawDesignGridDensity(B_Spline_Surface^ surface);
	

		void CheckItem();
		void UpdateMessage();

	//	void DrawImage(Graphics^ g);
		void DrawPic(Graphics^ g,Point ScaleCenter,float scale ,Point ScreenPt);
		void DrawLocalSurfaceData(Graphics^ g,ArrayList^ localsurfacedata);
		void DrawHotSpotData(Graphics^ g,ArrayList^ hotspotdata);



		
		//�ϧά���
		MemoryStream^ MemoryStream_DesignGridDensity;
		MemoryStream^ MemoryStream_CurrentPattern;
		Metafile^ Metafile_DesignGridDensity;
		Metafile^ Metafile_CurrentPattern;
		void SetDensityColor(float &density ,float &R ,float &G ,float &B);
		
	
		//���I����
		Pattern^ Dot;
		
		DensityClass::GridDensity^ SurfacePatternDensity;   //�w�q���Ѧ����M���u���ͪ��K�� ,���]�t�����ק諸���G
		DensityClass::GridDensity^ PatternDensity;          //�w�q�����I�̲ת��K�� ,�t���I�Y�񪺵��G

		GridDensity^ CalRegularPatternDensity(Pattern^ tmpDot ,Point tmpGridNumber , RectangleF tmpLGPSize ,int ShowingStyle);	 //�Ѻ���K�שM���I�Y���� ,�o��̲ױK�� .	ShowingStyle : 0 ��� 0~1���ƭ� , 1 ���0~100
		GridDensity^ CalFMPatternDensity(array<float,2>^ tmpFM_DotSize ,Point tmpGridNumber , RectangleF tmpLGPSize ,Point BlockSize ,float maxDen);	 //��FM���I�ƥ� ,�o��̲ױK�� .	
		
		GridDensity^ CalNearlyRegularDotDensity(Pattern^ tmpDot,PointF^ Size,RectangleF^ LGP);	//��Ū�J�����I,�o�������K�� .	

		DensityClass::GridDensity^ ScreenMuraData;          //�w�q���������R���᪺��� 
		

		Point GirdNumber;

		// LGP ���䪺�~��
		List<PointF>^ LGPPolyLinePt ;
		bool IsPtInside(PointF targetPt,List<PointF>^ LGP_PolyLine);  //�P�_�I�O���O�b�h��Τ�
	
		

		TranslateModule^  TranslateFormula;// 20091216	
	
		


		int FileKind ;    // 1��Pattern , 2 ���@Density ,3 ����J�Ѽ� ,4��LT�����ɮ� ,5 ��DensityWithDim(ģ�����) ,6��DensityWithDim(Actual)





		//�����ק�Ѽ�
		//array<B_Spline_Surface>^ LocalSurface ;// = gcnew List<B_Spline_Surface>(0);


		//�����W��
		String^ Version;
		//�M���ɦW��
		String^ InputFileName;
		//DXF �ɮצW��
		String^ PatternName;
		//�ثe���|
		String^ CurrentDictionary;





		//���Ѽƿ�J
		MainFormData^ MainData;

		//�M�׸�T
		Project_Information^ project;




		//�]�w�Ѽƿ�J
		SettingData^ Set_Data;

		//�ϰ�ק�Ѽ�
		Cosmetic_Data^ Cosmetic_LocalAreaData;

		//���u�վ㧡��
		
		Nurbs::B_Spline_Curve^ Curve_Vertical;
		Nurbs::B_Spline_Curve^ Curve_Horizontal;

		//�����վ㧡��
		Nurbs::B_Spline_Surface^ Surface_Global_Design;

	

		
		SettingForm ^ Set_Data_Form;

		//�̤j�K�׼ƭ�
		float maxDen;

		//Surface ����� (���骺)

		//Surface �����(�����ק諸)	
		ArrayList^ localsurfacedata ;

		//HotSpot �����ק���
	    ArrayList^ HotSpotData ;



		//�ۭqPitch�ɭp�⪺���\Pitch�d��
		float MaxPitch ;
		float MinPitch ;


		//IJP Dot �Ѽ�

		array<float,2>^ IJP_DotSize;
		Point IJP_Grid;
		RectangleF IJP_TextRange;
		//String^ IJP_Text;
		Bitmap^ IJP_TextBitmap;
		int IJPText_Index;
		float     IJP_DPI ;


		//�ϧΤƥ\��

		Matrix^ MainPicMatrix;
		//Matrix^ InvPicMatrix;
		array<PointF>^ ObjectCoordinate;   //index 0�O��ڪ���W�����y�� , index 1 �O�ϭ�Mouse ���I�y��
		float PicSacleVaule;
		//float ZoomScale;  // �i��RoomIn,RoomOut �ɼȦs��Data .


		Bitmap^ Density_Bitmap;

		//


		


		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�}������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenpatternToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�}�ұM����0901112ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�~������Dxf��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�s�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�sPattern�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Save_IJP_File = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Save_IJP_PrimerPattern = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveLTPatternFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�M����090112ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���}ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���׽վ�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���u�վ㧡��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����վ㧡��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ϰ�ק�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ק�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HotBar�ק�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˵�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ZoomPic = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MovePic = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ShowLGP = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����d��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ﶵToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�M�׸�TToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ƮwToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�]�wToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�u��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���I�K�פ��RToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�Ӥ���Ƨ��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������RToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���׹w��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->lblShowDen = (gcnew System::Windows::Forms::Label());
			this->lblLGPLocation = (gcnew System::Windows::Forms::Label());
			this->lblMinGap = (gcnew System::Windows::Forms::Label());
			this->lbl_Pattern_File = (gcnew System::Windows::Forms::Label());
			this->lbl_MaxPattern = (gcnew System::Windows::Forms::Label());
			this->lbl_MinPattern = (gcnew System::Windows::Forms::Label());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->lbl_Current_File = (gcnew System::Windows::Forms::Label());
			this->lblInformation = (gcnew System::Windows::Forms::Label());
			this->lblavgDen = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_CuttingShape = (gcnew System::Windows::Forms::Button());
			this->btnShowMura = (gcnew System::Windows::Forms::Button());
			this->btn_ProducePattern = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_LGPWidth = (gcnew System::Windows::Forms::TextBox());
			this->txt_LGPLength = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->radio_FMPattern = (gcnew System::Windows::Forms::RadioButton());
			this->radioIJPBtn = (gcnew System::Windows::Forms::RadioButton());
			this->radioBtnRegular = (gcnew System::Windows::Forms::RadioButton());
			this->radioBtnRandom = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tabControll = (gcnew System::Windows::Forms::TabControl());
			this->tab_Regular = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->lblAllowPitchRange = (gcnew System::Windows::Forms::Label());
			this->cboPitchDirection = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->txt_DesirePitch = (gcnew System::Windows::Forms::TextBox());
			this->btn_modifyDot = (gcnew System::Windows::Forms::Button());
			this->btnResetModifyRate = (gcnew System::Windows::Forms::Button());
			this->lblActualDensityRange = (gcnew System::Windows::Forms::Label());
			this->chkPitchSetting = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_Total_Num = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_Apply_ReqularDot_Set = (gcnew System::Windows::Forms::Button());
			this->lbl_AllowMaxDen = (gcnew System::Windows::Forms::Label());
			this->lbl_AllowMinDen = (gcnew System::Windows::Forms::Label());
			this->lbl_DotPitch = (gcnew System::Windows::Forms::Label());
			this->cboPatternArragementStyle = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxPatternShape = (gcnew System::Windows::Forms::ComboBox());
			this->txt_MinDotGap = (gcnew System::Windows::Forms::TextBox());
			this->txt_MinDot = (gcnew System::Windows::Forms::TextBox());
			this->txt_maxDot = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tab_Random = (gcnew System::Windows::Forms::TabPage());
			this->lbl_SmallGapNumber = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txt_RandomParaK = (gcnew System::Windows::Forms::TextBox());
			this->txt_RandomRebuildFrequency = (gcnew System::Windows::Forms::TextBox());
			this->txt_RandomParaC = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->cbo_RandomDotSimRule = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txt_RandomDotIteration = (gcnew System::Windows::Forms::TextBox());
			this->txt_RandomCuttingForce = (gcnew System::Windows::Forms::TextBox());
			this->chkRamdomStopForce = (gcnew System::Windows::Forms::CheckBox());
			this->chkRandomStopNumber = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_AllowanceRandomDensity = (gcnew System::Windows::Forms::Label());
			this->lbl_AverageForce = (gcnew System::Windows::Forms::Label());
			this->lbl_RandomTotalNum = (gcnew System::Windows::Forms::Label());
			this->lbl_RandomGirdNumber = (gcnew System::Windows::Forms::Label());
			this->btn_Accept_RandomPattern = (gcnew System::Windows::Forms::Button());
			this->txt_RandomDotSize = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->lbl_RandomIteration = (gcnew System::Windows::Forms::Label());
			this->lblpatdis = (gcnew System::Windows::Forms::Label());
			this->txt_RandomDotGap = (gcnew System::Windows::Forms::TextBox());
			this->tabPageIJP = (gcnew System::Windows::Forms::TabPage());
			this->cboIJPDPI = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->IJP_chk_TextEdit = (gcnew System::Windows::Forms::CheckBox());
			this->group_Text = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->btnX_Axis = (gcnew System::Windows::Forms::Button());
			this->btnY_Axis = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnNormal = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->IJP_cbo_TextLocation = (gcnew System::Windows::Forms::ComboBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->btnImportText = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->IJP_txt_TextLength = (gcnew System::Windows::Forms::TextBox());
			this->IJP_txt_TEXT = (gcnew System::Windows::Forms::TextBox());
			this->IJP_txt_TextHeight = (gcnew System::Windows::Forms::TextBox());
			this->IJP_txt_TextLocaX = (gcnew System::Windows::Forms::TextBox());
			this->lbl_LGP_Text = (gcnew System::Windows::Forms::Label());
			this->IJP_txt_TextLocaY = (gcnew System::Windows::Forms::TextBox());
			this->lblTotalNumber = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->IJP_txt_BlockY = (gcnew System::Windows::Forms::TextBox());
			this->btn_IJP = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->IJP_txt_DotSize = (gcnew System::Windows::Forms::TextBox());
			this->IJP_txt_BlockX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tab_FM_Pattern = (gcnew System::Windows::Forms::TabPage());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->lbl_FMMaxDen = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->txtFMPattern = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->txtFMPatternGap = (gcnew System::Windows::Forms::TextBox());
			this->btnFMPattern = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabControll->SuspendLayout();
			this->tab_Regular->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tab_Random->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabPageIJP->SuspendLayout();
			this->group_Text->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->tab_FM_Pattern->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->�ɮ�ToolStripMenuItem, 
				this->EditToolStripMenuItem, this->�˵�ToolStripMenuItem, this->����ToolStripMenuItem, this->�]�wToolStripMenuItem, this->�u��ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1282, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ɮ�ToolStripMenuItem
			// 
			this->�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->FileNewToolStripMenuItem, 
				this->�}������ToolStripMenuItem, this->�x�s�ɮ�ToolStripMenuItem, this->���}ToolStripMenuItem});
			this->�ɮ�ToolStripMenuItem->Name = L"�ɮ�ToolStripMenuItem";
			this->�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->�ɮ�ToolStripMenuItem->Text = L"�ɮ�";
			// 
			// FileNewToolStripMenuItem
			// 
			this->FileNewToolStripMenuItem->Name = L"FileNewToolStripMenuItem";
			this->FileNewToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->FileNewToolStripMenuItem->Text = L"�}�s�ɮ�";
			this->FileNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::FileNewToolStripMenuItem_Click);
			// 
			// �}������ToolStripMenuItem
			// 
			this->�}������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->OpenpatternToolStripMenuItem, 
				this->�}�ұM����0901112ToolStripMenuItem, this->�~������Dxf��ToolStripMenuItem});
			this->�}������ToolStripMenuItem->Name = L"�}������ToolStripMenuItem";
			this->�}������ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->�}������ToolStripMenuItem->Text = L"�}������";
			this->�}������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�}������ToolStripMenuItem_Click);
			// 
			// OpenpatternToolStripMenuItem
			// 
			this->OpenpatternToolStripMenuItem->Name = L"OpenpatternToolStripMenuItem";
			this->OpenpatternToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->OpenpatternToolStripMenuItem->Text = L"���Pattern�ɮ�";
			this->OpenpatternToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenpatternToolStripMenuItem_Click);
			// 
			// �}�ұM����0901112ToolStripMenuItem
			// 
			this->�}�ұM����0901112ToolStripMenuItem->Name = L"�}�ұM����0901112ToolStripMenuItem";
			this->�}�ұM����0901112ToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->�}�ұM����0901112ToolStripMenuItem->Text = L"�}�ұM����-v2.0";
			this->�}�ұM����0901112ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�}�ұM����0901112ToolStripMenuItem_Click);
			// 
			// �~������Dxf��ToolStripMenuItem
			// 
			this->�~������Dxf��ToolStripMenuItem->Name = L"�~������Dxf��ToolStripMenuItem";
			this->�~������Dxf��ToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->�~������Dxf��ToolStripMenuItem->Text = L"�~������Dxf��";
			this->�~������Dxf��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�~������Dxf��ToolStripMenuItem_Click);
			// 
			// �x�s�ɮ�ToolStripMenuItem
			// 
			this->�x�s�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->�x�sPattern�ɮ�ToolStripMenuItem, 
				this->Save_IJP_File, this->Save_IJP_PrimerPattern, this->SaveLTPatternFileToolStripMenuItem, this->�M����090112ToolStripMenuItem});
			this->�x�s�ɮ�ToolStripMenuItem->Name = L"�x�s�ɮ�ToolStripMenuItem";
			this->�x�s�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->�x�s�ɮ�ToolStripMenuItem->Text = L"�x�s�ɮ�";
			// 
			// �x�sPattern�ɮ�ToolStripMenuItem
			// 
			this->�x�sPattern�ɮ�ToolStripMenuItem->Name = L"�x�sPattern�ɮ�ToolStripMenuItem";
			this->�x�sPattern�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->�x�sPattern�ɮ�ToolStripMenuItem->Text = L"Pattern�ɮ�";
			this->�x�sPattern�ɮ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�x�sPattern�ɮ�ToolStripMenuItem_Click);
			// 
			// Save_IJP_File
			// 
			this->Save_IJP_File->Name = L"Save_IJP_File";
			this->Save_IJP_File->Size = System::Drawing::Size(212, 22);
			this->Save_IJP_File->Text = L"IJP�ɮ�";
			this->Save_IJP_File->Click += gcnew System::EventHandler(this, &Form1::Save_IJP_File_Click);
			// 
			// Save_IJP_PrimerPattern
			// 
			this->Save_IJP_PrimerPattern->Name = L"Save_IJP_PrimerPattern";
			this->Save_IJP_PrimerPattern->Size = System::Drawing::Size(212, 22);
			this->Save_IJP_PrimerPattern->Text = L"IJP Primer Pattern";
			this->Save_IJP_PrimerPattern->Click += gcnew System::EventHandler(this, &Form1::Save_IJP_PrimerPattern_Click);
			// 
			// SaveLTPatternFileToolStripMenuItem
			// 
			this->SaveLTPatternFileToolStripMenuItem->Name = L"SaveLTPatternFileToolStripMenuItem";
			this->SaveLTPatternFileToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->SaveLTPatternFileToolStripMenuItem->Text = L"�x�sLT���I�ɮ�(�ѳy�]�w)";
			this->SaveLTPatternFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::SaveLTPatternFileToolStripMenuItem_Click);
			// 
			// �M����090112ToolStripMenuItem
			// 
			this->�M����090112ToolStripMenuItem->Name = L"�M����090112ToolStripMenuItem";
			this->�M����090112ToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->�M����090112ToolStripMenuItem->Text = L"�M����-v2.0";
			this->�M����090112ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�M����090112ToolStripMenuItem_Click);
			// 
			// ���}ToolStripMenuItem
			// 
			this->���}ToolStripMenuItem->Name = L"���}ToolStripMenuItem";
			this->���}ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->���}ToolStripMenuItem->Text = L"���}";
			this->���}ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���}ToolStripMenuItem_Click);
			// 
			// EditToolStripMenuItem
			// 
			this->EditToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->���׽վ�\��ToolStripMenuItem, 
				this->�ϰ�ק�\��ToolStripMenuItem});
			this->EditToolStripMenuItem->Name = L"EditToolStripMenuItem";
			this->EditToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->EditToolStripMenuItem->Text = L"�s��";
			this->EditToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::EditToolStripMenuItem_DropDownOpening);
			// 
			// ���׽վ�\��ToolStripMenuItem
			// 
			this->���׽վ�\��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->���u�վ㧡��ToolStripMenuItem, 
				this->�����վ㧡��ToolStripMenuItem});
			this->���׽վ�\��ToolStripMenuItem->Name = L"���׽վ�\��ToolStripMenuItem";
			this->���׽վ�\��ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->���׽վ�\��ToolStripMenuItem->Text = L"�K�׽վ�\��";
			this->���׽վ�\��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���׽վ�\��ToolStripMenuItem_Click);
			// 
			// ���u�վ㧡��ToolStripMenuItem
			// 
			this->���u�վ㧡��ToolStripMenuItem->CheckOnClick = true;
			this->���u�վ㧡��ToolStripMenuItem->Enabled = false;
			this->���u�վ㧡��ToolStripMenuItem->Name = L"���u�վ㧡��ToolStripMenuItem";
			this->���u�վ㧡��ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->���u�վ㧡��ToolStripMenuItem->Text = L"���u�վ㧡��";
			this->���u�վ㧡��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���u�վ㧡��ToolStripMenuItem_Click);
			// 
			// �����վ㧡��ToolStripMenuItem
			// 
			this->�����վ㧡��ToolStripMenuItem->CheckOnClick = true;
			this->�����վ㧡��ToolStripMenuItem->Name = L"�����վ㧡��ToolStripMenuItem";
			this->�����վ㧡��ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->�����վ㧡��ToolStripMenuItem->Text = L"�����վ㧡��";
			this->�����վ㧡��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����վ㧡��ToolStripMenuItem_Click);
			// 
			// �ϰ�ק�\��ToolStripMenuItem
			// 
			this->�ϰ�ק�\��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�����ק�ToolStripMenuItem, 
				this->HotBar�ק�ToolStripMenuItem});
			this->�ϰ�ק�\��ToolStripMenuItem->Name = L"�ϰ�ק�\��ToolStripMenuItem";
			this->�ϰ�ק�\��ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->�ϰ�ק�\��ToolStripMenuItem->Text = L"�ӳ��ק�\��";
			this->�ϰ�ק�\��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�ϰ�ק�\��ToolStripMenuItem_Click);
			// 
			// �����ק�ToolStripMenuItem
			// 
			this->�����ק�ToolStripMenuItem->Name = L"�����ק�ToolStripMenuItem";
			this->�����ק�ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�����ק�ToolStripMenuItem->Text = L"�����ק�";
			this->�����ק�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ק�ToolStripMenuItem_Click);
			// 
			// HotBar�ק�ToolStripMenuItem
			// 
			this->HotBar�ק�ToolStripMenuItem->Name = L"HotBar�ק�ToolStripMenuItem";
			this->HotBar�ק�ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->HotBar�ק�ToolStripMenuItem->Text = L"�S��Ϊ������ק�";
			this->HotBar�ק�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lEDHotBar�ק�ToolStripMenuItem_Click);
			// 
			// �˵�ToolStripMenuItem
			// 
			this->�˵�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->ZoomPic, 
				this->MovePic, this->ShowLGP, this->�����d��ToolStripMenuItem, this->�ﶵToolStripMenuItem});
			this->�˵�ToolStripMenuItem->Name = L"�˵�ToolStripMenuItem";
			this->�˵�ToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->�˵�ToolStripMenuItem->Text = L"�˵�";
			this->�˵�ToolStripMenuItem->DropDownOpened += gcnew System::EventHandler(this, &Form1::�˵�ToolStripMenuItem_DropDownOpened);
			// 
			// ZoomPic
			// 
			this->ZoomPic->Name = L"ZoomPic";
			this->ZoomPic->Size = System::Drawing::Size(139, 22);
			this->ZoomPic->Text = L"�Y���Y��";
			this->ZoomPic->Click += gcnew System::EventHandler(this, &Form1::ShowDesignDensityToolStripMenuItem_Click);
			// 
			// MovePic
			// 
			this->MovePic->Name = L"MovePic";
			this->MovePic->Size = System::Drawing::Size(139, 22);
			this->MovePic->Text = L"�Y�ɥ���";
			this->MovePic->Click += gcnew System::EventHandler(this, &Form1::ShowActualResultDensityToolStripMenuItem_Click);
			// 
			// ShowLGP
			// 
			this->ShowLGP->Name = L"ShowLGP";
			this->ShowLGP->Size = System::Drawing::Size(139, 22);
			this->ShowLGP->Text = L"LGP�̾A�j�p";
			this->ShowLGP->Click += gcnew System::EventHandler(this, &Form1::ShowCurrentPatternToolStripMenuItem_Click);
			// 
			// �����d��ToolStripMenuItem
			// 
			this->�����d��ToolStripMenuItem->Enabled = false;
			this->�����d��ToolStripMenuItem->Name = L"�����d��ToolStripMenuItem";
			this->�����d��ToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->�����d��ToolStripMenuItem->Text = L"�����d��";
			this->�����d��ToolStripMenuItem->Visible = false;
			// 
			// �ﶵToolStripMenuItem
			// 
			this->�ﶵToolStripMenuItem->Enabled = false;
			this->�ﶵToolStripMenuItem->Name = L"�ﶵToolStripMenuItem";
			this->�ﶵToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->�ﶵToolStripMenuItem->Text = L"�ﶵ";
			this->�ﶵToolStripMenuItem->Visible = false;
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�M�׸�TToolStripMenuItem, 
				this->��ƮwToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->����ToolStripMenuItem->Text = L"��T";
			// 
			// �M�׸�TToolStripMenuItem
			// 
			this->�M�׸�TToolStripMenuItem->Name = L"�M�׸�TToolStripMenuItem";
			this->�M�׸�TToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->�M�׸�TToolStripMenuItem->Text = L"�M�׸�T";
			this->�M�׸�TToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�M�׸�TToolStripMenuItem_Click);
			// 
			// ��ƮwToolStripMenuItem
			// 
			this->��ƮwToolStripMenuItem->Name = L"��ƮwToolStripMenuItem";
			this->��ƮwToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->��ƮwToolStripMenuItem->Text = L"��Ʈw";
			this->��ƮwToolStripMenuItem->Visible = false;
			this->��ƮwToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��ƮwToolStripMenuItem_Click);
			// 
			// �]�wToolStripMenuItem
			// 
			this->�]�wToolStripMenuItem->Name = L"�]�wToolStripMenuItem";
			this->�]�wToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->�]�wToolStripMenuItem->Text = L"�]�w";
			this->�]�wToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�]�wToolStripMenuItem_Click);
			// 
			// �u��ToolStripMenuItem
			// 
			this->�u��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->���I�K�פ��RToolStripMenuItem, 
				this->�Ӥ���Ƨ��ToolStripMenuItem, this->�������RToolStripMenuItem, this->���׹w��ToolStripMenuItem});
			this->�u��ToolStripMenuItem->Name = L"�u��ToolStripMenuItem";
			this->�u��ToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->�u��ToolStripMenuItem->Text = L"�u��";
			// 
			// ���I�K�פ��RToolStripMenuItem
			// 
			this->���I�K�פ��RToolStripMenuItem->Name = L"���I�K�פ��RToolStripMenuItem";
			this->���I�K�פ��RToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->���I�K�פ��RToolStripMenuItem->Text = L"���I�K�פ��R";
			this->���I�K�פ��RToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���I�K�פ��RToolStripMenuItem_Click);
			// 
			// �Ӥ���Ƨ��ToolStripMenuItem
			// 
			this->�Ӥ���Ƨ��ToolStripMenuItem->Name = L"�Ӥ���Ƨ��ToolStripMenuItem";
			this->�Ӥ���Ƨ��ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�Ӥ���Ƨ��ToolStripMenuItem->Text = L"�Ӥ���Ƨ��";
			this->�Ӥ���Ƨ��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�Ӥ���Ƨ��ToolStripMenuItem_Click);
			// 
			// �������RToolStripMenuItem
			// 
			this->�������RToolStripMenuItem->Name = L"�������RToolStripMenuItem";
			this->�������RToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�������RToolStripMenuItem->Text = L"�������R";
			this->�������RToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������RToolStripMenuItem_Click);
			// 
			// ���׹w��ToolStripMenuItem
			// 
			this->���׹w��ToolStripMenuItem->Enabled = false;
			this->���׹w��ToolStripMenuItem->Name = L"���׹w��ToolStripMenuItem";
			this->���׹w��ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->���׹w��ToolStripMenuItem->Text = L"�@�����׹w���\��";
			this->���׹w��ToolStripMenuItem->Visible = false;
			this->���׹w��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���׹w��ToolStripMenuItem_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"saveFileDialog";
			this->saveFileDialog1->SupportMultiDottedExtensions = true;
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->AutoScroll = true;
			this->splitContainer1->Panel2->AutoScrollMargin = System::Drawing::Size(10, 10);
			this->splitContainer1->Panel2->AutoScrollMinSize = System::Drawing::Size(2, 2);
			this->splitContainer1->Panel2->Controls->Add(this->tableLayoutPanel1);
			this->splitContainer1->Size = System::Drawing::Size(1282, 758);
			this->splitContainer1->SplitterDistance = 918;
			this->splitContainer1->TabIndex = 45;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(918, 758);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseWheel);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->groupBox7, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->groupBox6, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox8, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox4, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 496)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 243)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(326, 932);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->lblShowDen);
			this->groupBox7->Controls->Add(this->lblLGPLocation);
			this->groupBox7->Controls->Add(this->lblMinGap);
			this->groupBox7->Controls->Add(this->lbl_Pattern_File);
			this->groupBox7->Controls->Add(this->lbl_MaxPattern);
			this->groupBox7->Controls->Add(this->lbl_MinPattern);
			this->groupBox7->Controls->Add(this->lblVersion);
			this->groupBox7->Controls->Add(this->lbl_Current_File);
			this->groupBox7->Controls->Add(this->lblInformation);
			this->groupBox7->Controls->Add(this->lblavgDen);
			this->groupBox7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox7->Location = System::Drawing::Point(3, 692);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(339, 237);
			this->groupBox7->TabIndex = 48;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"�T��";
			this->groupBox7->Enter += gcnew System::EventHandler(this, &Form1::groupBox7_Enter);
			// 
			// lblShowDen
			// 
			this->lblShowDen->AutoSize = true;
			this->lblShowDen->Location = System::Drawing::Point(9, 174);
			this->lblShowDen->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblShowDen->Name = L"lblShowDen";
			this->lblShowDen->Size = System::Drawing::Size(83, 12);
			this->lblShowDen->TabIndex = 60;
			this->lblShowDen->Text = L"�ƹ������K�� :";
			// 
			// lblLGPLocation
			// 
			this->lblLGPLocation->AutoSize = true;
			this->lblLGPLocation->Location = System::Drawing::Point(9, 153);
			this->lblLGPLocation->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLGPLocation->Name = L"lblLGPLocation";
			this->lblLGPLocation->Size = System::Drawing::Size(83, 12);
			this->lblLGPLocation->TabIndex = 59;
			this->lblLGPLocation->Text = L"�ƹ������y�� :";
			// 
			// lblMinGap
			// 
			this->lblMinGap->AutoSize = true;
			this->lblMinGap->Location = System::Drawing::Point(9, 132);
			this->lblMinGap->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblMinGap->Name = L"lblMinGap";
			this->lblMinGap->Size = System::Drawing::Size(54, 12);
			this->lblMinGap->TabIndex = 58;
			this->lblMinGap->Text = L"�̤pGap :";
			// 
			// lbl_Pattern_File
			// 
			this->lbl_Pattern_File->AutoSize = true;
			this->lbl_Pattern_File->Location = System::Drawing::Point(9, 42);
			this->lbl_Pattern_File->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_Pattern_File->Name = L"lbl_Pattern_File";
			this->lbl_Pattern_File->Size = System::Drawing::Size(91, 12);
			this->lbl_Pattern_File->TabIndex = 57;
			this->lbl_Pattern_File->Text = L"Pattern�ɮצW�� :";
			// 
			// lbl_MaxPattern
			// 
			this->lbl_MaxPattern->AutoSize = true;
			this->lbl_MaxPattern->Location = System::Drawing::Point(9, 109);
			this->lbl_MaxPattern->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_MaxPattern->Name = L"lbl_MaxPattern";
			this->lbl_MaxPattern->Size = System::Drawing::Size(59, 12);
			this->lbl_MaxPattern->TabIndex = 55;
			this->lbl_MaxPattern->Text = L"�̤j���I :";
			// 
			// lbl_MinPattern
			// 
			this->lbl_MinPattern->AutoSize = true;
			this->lbl_MinPattern->Location = System::Drawing::Point(9, 86);
			this->lbl_MinPattern->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_MinPattern->Name = L"lbl_MinPattern";
			this->lbl_MinPattern->Size = System::Drawing::Size(59, 12);
			this->lbl_MinPattern->TabIndex = 54;
			this->lbl_MinPattern->Text = L"�̤p���I :";
			// 
			// lblVersion
			// 
			this->lblVersion->AutoSize = true;
			this->lblVersion->Font = (gcnew System::Drawing::Font(L"�s�ө���", 14.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lblVersion->ForeColor = System::Drawing::Color::Red;
			this->lblVersion->Location = System::Drawing::Point(10, 196);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(237, 19);
			this->lblVersion->TabIndex = 53;
			this->lblVersion->Text = L"Software Version: 3.7(���ժ�)";
			// 
			// lbl_Current_File
			// 
			this->lbl_Current_File->AutoSize = true;
			this->lbl_Current_File->Location = System::Drawing::Point(9, 18);
			this->lbl_Current_File->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_Current_File->Name = L"lbl_Current_File";
			this->lbl_Current_File->Size = System::Drawing::Size(71, 12);
			this->lbl_Current_File->TabIndex = 52;
			this->lbl_Current_File->Text = L"�M���ɦW�� :";
			// 
			// lblInformation
			// 
			this->lblInformation->AutoSize = true;
			this->lblInformation->ForeColor = System::Drawing::Color::Red;
			this->lblInformation->Location = System::Drawing::Point(12, 153);
			this->lblInformation->Name = L"lblInformation";
			this->lblInformation->Size = System::Drawing::Size(0, 12);
			this->lblInformation->TabIndex = 51;
			// 
			// lblavgDen
			// 
			this->lblavgDen->AutoSize = true;
			this->lblavgDen->Location = System::Drawing::Point(9, 65);
			this->lblavgDen->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblavgDen->Name = L"lblavgDen";
			this->lblavgDen->Size = System::Drawing::Size(68, 12);
			this->lblavgDen->TabIndex = 49;
			this->lblavgDen->Text = L"�����л\�v:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btn_CuttingShape);
			this->groupBox1->Controls->Add(this->btnShowMura);
			this->groupBox1->Controls->Add(this->btn_ProducePattern);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 628);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 58);
			this->groupBox1->TabIndex = 47;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"����";
			// 
			// btn_CuttingShape
			// 
			this->btn_CuttingShape->Location = System::Drawing::Point(205, 14);
			this->btn_CuttingShape->Margin = System::Windows::Forms::Padding(4);
			this->btn_CuttingShape->Name = L"btn_CuttingShape";
			this->btn_CuttingShape->Size = System::Drawing::Size(87, 36);
			this->btn_CuttingShape->TabIndex = 27;
			this->btn_CuttingShape->Text = L"�~���׾�";
			this->btn_CuttingShape->UseVisualStyleBackColor = true;
			this->btn_CuttingShape->Click += gcnew System::EventHandler(this, &Form1::btn_CuttingShape_Click);
			// 
			// btnShowMura
			// 
			this->btnShowMura->Location = System::Drawing::Point(109, 15);
			this->btnShowMura->Margin = System::Windows::Forms::Padding(4);
			this->btnShowMura->Name = L"btnShowMura";
			this->btnShowMura->Size = System::Drawing::Size(87, 35);
			this->btnShowMura->TabIndex = 26;
			this->btnShowMura->Text = L"��ܺ���";
			this->btnShowMura->UseVisualStyleBackColor = true;
			this->btnShowMura->Click += gcnew System::EventHandler(this, &Form1::btnDotDisturbe_Click);
			// 
			// btn_ProducePattern
			// 
			this->btn_ProducePattern->Enabled = false;
			this->btn_ProducePattern->Location = System::Drawing::Point(14, 15);
			this->btn_ProducePattern->Margin = System::Windows::Forms::Padding(4);
			this->btn_ProducePattern->Name = L"btn_ProducePattern";
			this->btn_ProducePattern->Size = System::Drawing::Size(87, 35);
			this->btn_ProducePattern->TabIndex = 23;
			this->btn_ProducePattern->Text = L"�K�׽վ���I";
			this->btn_ProducePattern->UseVisualStyleBackColor = true;
			this->btn_ProducePattern->Click += gcnew System::EventHandler(this, &Form1::btn_click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label4);
			this->groupBox6->Controls->Add(this->label3);
			this->groupBox6->Controls->Add(this->txt_LGPWidth);
			this->groupBox6->Controls->Add(this->txt_LGPLength);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(4, 87);
			this->groupBox6->Margin = System::Windows::Forms::Padding(4);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(4);
			this->groupBox6->Size = System::Drawing::Size(337, 38);
			this->groupBox6->TabIndex = 41;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"LGP �ؤo";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(148, 20);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 12);
			this->label4->TabIndex = 7;
			this->label4->Text = L"�e��(W)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 20);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 12);
			this->label3->TabIndex = 6;
			this->label3->Text = L"����(L)";
			// 
			// txt_LGPWidth
			// 
			this->txt_LGPWidth->Location = System::Drawing::Point(204, 14);
			this->txt_LGPWidth->Margin = System::Windows::Forms::Padding(4);
			this->txt_LGPWidth->Name = L"txt_LGPWidth";
			this->txt_LGPWidth->Size = System::Drawing::Size(73, 22);
			this->txt_LGPWidth->TabIndex = 1;
			this->txt_LGPWidth->TextChanged += gcnew System::EventHandler(this, &Form1::txtBoxPlateH_TextChanged);
			this->txt_LGPWidth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtBoxPlateH_KeyPress);
			// 
			// txt_LGPLength
			// 
			this->txt_LGPLength->Location = System::Drawing::Point(66, 14);
			this->txt_LGPLength->Margin = System::Windows::Forms::Padding(4);
			this->txt_LGPLength->Name = L"txt_LGPLength";
			this->txt_LGPLength->Size = System::Drawing::Size(73, 22);
			this->txt_LGPLength->TabIndex = 0;
			this->txt_LGPLength->TextChanged += gcnew System::EventHandler(this, &Form1::txtBoxPlateW_TextChanged);
			this->txt_LGPLength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtBoxPlateW_KeyPress);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->radio_FMPattern);
			this->groupBox8->Controls->Add(this->radioIJPBtn);
			this->groupBox8->Controls->Add(this->radioBtnRegular);
			this->groupBox8->Controls->Add(this->radioBtnRandom);
			this->groupBox8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox8->Location = System::Drawing::Point(3, 3);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(339, 77);
			this->groupBox8->TabIndex = 49;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"�G�I�覡";
			// 
			// radio_FMPattern
			// 
			this->radio_FMPattern->AutoSize = true;
			this->radio_FMPattern->Location = System::Drawing::Point(18, 15);
			this->radio_FMPattern->Name = L"radio_FMPattern";
			this->radio_FMPattern->Size = System::Drawing::Size(87, 16);
			this->radio_FMPattern->TabIndex = 3;
			this->radio_FMPattern->Text = L"FM�üƧG�I";
			this->radio_FMPattern->UseVisualStyleBackColor = true;
			this->radio_FMPattern->CheckedChanged += gcnew System::EventHandler(this, &Form1::radio_FMPattern_CheckedChanged);
			// 
			// radioIJPBtn
			// 
			this->radioIJPBtn->AutoSize = true;
			this->radioIJPBtn->Location = System::Drawing::Point(19, 59);
			this->radioIJPBtn->Name = L"radioIJPBtn";
			this->radioIJPBtn->Size = System::Drawing::Size(61, 16);
			this->radioIJPBtn->TabIndex = 2;
			this->radioIJPBtn->Text = L"IJP�G�I";
			this->radioIJPBtn->UseVisualStyleBackColor = true;
			this->radioIJPBtn->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged_1);
			// 
			// radioBtnRegular
			// 
			this->radioBtnRegular->AutoSize = true;
			this->radioBtnRegular->Checked = true;
			this->radioBtnRegular->Location = System::Drawing::Point(18, 37);
			this->radioBtnRegular->Name = L"radioBtnRegular";
			this->radioBtnRegular->Size = System::Drawing::Size(162, 16);
			this->radioBtnRegular->TabIndex = 1;
			this->radioBtnRegular->TabStop = true;
			this->radioBtnRegular->Text = L"�W�h�G�I(��Pitch�����j�p)";
			this->radioBtnRegular->UseVisualStyleBackColor = true;
			this->radioBtnRegular->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioBtnRandom
			// 
			this->radioBtnRandom->AutoSize = true;
			this->radioBtnRandom->Enabled = false;
			this->radioBtnRandom->Location = System::Drawing::Point(161, 15);
			this->radioBtnRandom->Name = L"radioBtnRandom";
			this->radioBtnRandom->Size = System::Drawing::Size(162, 16);
			this->radioBtnRandom->TabIndex = 0;
			this->radioBtnRandom->Text = L"�üƧG�I(���j�p����Pitch)";
			this->radioBtnRandom->UseVisualStyleBackColor = true;
			this->radioBtnRandom->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tabControll);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 132);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(339, 490);
			this->groupBox4->TabIndex = 50;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"�ѼƳ]�w";
			// 
			// tabControll
			// 
			this->tabControll->Controls->Add(this->tab_Regular);
			this->tabControll->Controls->Add(this->tab_Random);
			this->tabControll->Controls->Add(this->tabPageIJP);
			this->tabControll->Controls->Add(this->tab_FM_Pattern);
			this->tabControll->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControll->Location = System::Drawing::Point(3, 18);
			this->tabControll->Name = L"tabControll";
			this->tabControll->SelectedIndex = 0;
			this->tabControll->Size = System::Drawing::Size(333, 469);
			this->tabControll->TabIndex = 0;
			this->tabControll->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tabControll_SelectedIndexChanged);
			// 
			// tab_Regular
			// 
			this->tab_Regular->Controls->Add(this->groupBox5);
			this->tab_Regular->Controls->Add(this->btn_modifyDot);
			this->tab_Regular->Controls->Add(this->btnResetModifyRate);
			this->tab_Regular->Controls->Add(this->lblActualDensityRange);
			this->tab_Regular->Controls->Add(this->chkPitchSetting);
			this->tab_Regular->Controls->Add(this->lbl_Total_Num);
			this->tab_Regular->Controls->Add(this->label6);
			this->tab_Regular->Controls->Add(this->label5);
			this->tab_Regular->Controls->Add(this->label2);
			this->tab_Regular->Controls->Add(this->label1);
			this->tab_Regular->Controls->Add(this->btn_Apply_ReqularDot_Set);
			this->tab_Regular->Controls->Add(this->lbl_AllowMaxDen);
			this->tab_Regular->Controls->Add(this->lbl_AllowMinDen);
			this->tab_Regular->Controls->Add(this->lbl_DotPitch);
			this->tab_Regular->Controls->Add(this->cboPatternArragementStyle);
			this->tab_Regular->Controls->Add(this->comboBoxPatternShape);
			this->tab_Regular->Controls->Add(this->txt_MinDotGap);
			this->tab_Regular->Controls->Add(this->txt_MinDot);
			this->tab_Regular->Controls->Add(this->txt_maxDot);
			this->tab_Regular->Controls->Add(this->label13);
			this->tab_Regular->Controls->Add(this->label12);
			this->tab_Regular->Controls->Add(this->label11);
			this->tab_Regular->Controls->Add(this->label7);
			this->tab_Regular->Location = System::Drawing::Point(4, 21);
			this->tab_Regular->Name = L"tab_Regular";
			this->tab_Regular->Padding = System::Windows::Forms::Padding(3);
			this->tab_Regular->Size = System::Drawing::Size(325, 444);
			this->tab_Regular->TabIndex = 0;
			this->tab_Regular->Text = L"�W�h���I�]�w";
			this->tab_Regular->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->lblMessage);
			this->groupBox5->Controls->Add(this->lblAllowPitchRange);
			this->groupBox5->Controls->Add(this->cboPitchDirection);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Controls->Add(this->txt_DesirePitch);
			this->groupBox5->Location = System::Drawing::Point(11, 190);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(261, 103);
			this->groupBox5->TabIndex = 34;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Pitch�վ�";
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->ForeColor = System::Drawing::Color::Red;
			this->lblMessage->Location = System::Drawing::Point(7, 72);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(29, 12);
			this->lblMessage->TabIndex = 37;
			this->lblMessage->Text = L"ĵ�i";
			this->lblMessage->Visible = false;
			// 
			// lblAllowPitchRange
			// 
			this->lblAllowPitchRange->AutoSize = true;
			this->lblAllowPitchRange->Location = System::Drawing::Point(7, 18);
			this->lblAllowPitchRange->Name = L"lblAllowPitchRange";
			this->lblAllowPitchRange->Size = System::Drawing::Size(85, 12);
			this->lblAllowPitchRange->TabIndex = 36;
			this->lblAllowPitchRange->Text = L"���\Pitch �d�� :";
			// 
			// cboPitchDirection
			// 
			this->cboPitchDirection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPitchDirection->FormattingEnabled = true;
			this->cboPitchDirection->Location = System::Drawing::Point(75, 43);
			this->cboPitchDirection->Margin = System::Windows::Forms::Padding(4);
			this->cboPitchDirection->Name = L"cboPitchDirection";
			this->cboPitchDirection->Size = System::Drawing::Size(62, 20);
			this->cboPitchDirection->TabIndex = 31;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(7, 46);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(61, 12);
			this->label20->TabIndex = 30;
			this->label20->Text = L"Pitch �]�w :";
			// 
			// txt_DesirePitch
			// 
			this->txt_DesirePitch->Location = System::Drawing::Point(145, 43);
			this->txt_DesirePitch->Margin = System::Windows::Forms::Padding(4);
			this->txt_DesirePitch->Name = L"txt_DesirePitch";
			this->txt_DesirePitch->Size = System::Drawing::Size(73, 22);
			this->txt_DesirePitch->TabIndex = 32;
			this->txt_DesirePitch->TextChanged += gcnew System::EventHandler(this, &Form1::txt_DesirePitch_TextChanged);
			this->txt_DesirePitch->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::txt_DesirePitch_MouseDown);
			// 
			// btn_modifyDot
			// 
			this->btn_modifyDot->Enabled = false;
			this->btn_modifyDot->Location = System::Drawing::Point(198, 400);
			this->btn_modifyDot->Margin = System::Windows::Forms::Padding(4);
			this->btn_modifyDot->Name = L"btn_modifyDot";
			this->btn_modifyDot->Size = System::Drawing::Size(87, 36);
			this->btn_modifyDot->TabIndex = 24;
			this->btn_modifyDot->Text = L"�ӳ��ק���I";
			this->btn_modifyDot->UseVisualStyleBackColor = true;
			this->btn_modifyDot->Visible = false;
			this->btn_modifyDot->Click += gcnew System::EventHandler(this, &Form1::btn_modifyDot_Click);
			// 
			// btnResetModifyRate
			// 
			this->btnResetModifyRate->Enabled = false;
			this->btnResetModifyRate->Location = System::Drawing::Point(198, 401);
			this->btnResetModifyRate->Margin = System::Windows::Forms::Padding(4);
			this->btnResetModifyRate->Name = L"btnResetModifyRate";
			this->btnResetModifyRate->Size = System::Drawing::Size(87, 35);
			this->btnResetModifyRate->TabIndex = 25;
			this->btnResetModifyRate->Text = L"���]�ӳ����I";
			this->btnResetModifyRate->UseVisualStyleBackColor = true;
			this->btnResetModifyRate->Visible = false;
			this->btnResetModifyRate->Click += gcnew System::EventHandler(this, &Form1::btnResetModifyRate_Click);
			// 
			// lblActualDensityRange
			// 
			this->lblActualDensityRange->AutoSize = true;
			this->lblActualDensityRange->Location = System::Drawing::Point(12, 326);
			this->lblActualDensityRange->Name = L"lblActualDensityRange";
			this->lblActualDensityRange->Size = System::Drawing::Size(83, 12);
			this->lblActualDensityRange->TabIndex = 35;
			this->lblActualDensityRange->Text = L"���\�K�׽d�� :";
			// 
			// chkPitchSetting
			// 
			this->chkPitchSetting->AutoSize = true;
			this->chkPitchSetting->Location = System::Drawing::Point(14, 168);
			this->chkPitchSetting->Name = L"chkPitchSetting";
			this->chkPitchSetting->Size = System::Drawing::Size(249, 16);
			this->chkPitchSetting->TabIndex = 33;
			this->chkPitchSetting->Text = L"�ҥ�Pitch�վ�(���ҥή�,�{���۰ʭp��Pitch)";
			this->chkPitchSetting->UseVisualStyleBackColor = true;
			this->chkPitchSetting->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkPitchSetting_CheckedChanged);
			// 
			// lbl_Total_Num
			// 
			this->lbl_Total_Num->AutoSize = true;
			this->lbl_Total_Num->Location = System::Drawing::Point(12, 349);
			this->lbl_Total_Num->Name = L"lbl_Total_Num";
			this->lbl_Total_Num->Size = System::Drawing::Size(74, 12);
			this->lbl_Total_Num->TabIndex = 29;
			this->lbl_Total_Num->Text = L"�`���I�ƥ�  :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(198, 68);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(25, 12);
			this->label6->TabIndex = 28;
			this->label6->Text = L"(�P)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(198, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(25, 12);
			this->label5->TabIndex = 27;
			this->label5->Text = L"(�P)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(198, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 12);
			this->label2->TabIndex = 26;
			this->label2->Text = L"(�P)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 12);
			this->label1->TabIndex = 25;
			this->label1->Text = L"�ƦC�覡 :";
			// 
			// btn_Apply_ReqularDot_Set
			// 
			this->btn_Apply_ReqularDot_Set->Location = System::Drawing::Point(198, 362);
			this->btn_Apply_ReqularDot_Set->Name = L"btn_Apply_ReqularDot_Set";
			this->btn_Apply_ReqularDot_Set->Size = System::Drawing::Size(83, 32);
			this->btn_Apply_ReqularDot_Set->TabIndex = 24;
			this->btn_Apply_ReqularDot_Set->Text = L"�M��";
			this->btn_Apply_ReqularDot_Set->UseVisualStyleBackColor = true;
			this->btn_Apply_ReqularDot_Set->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// lbl_AllowMaxDen
			// 
			this->lbl_AllowMaxDen->AutoSize = true;
			this->lbl_AllowMaxDen->Location = System::Drawing::Point(11, 412);
			this->lbl_AllowMaxDen->Name = L"lbl_AllowMaxDen";
			this->lbl_AllowMaxDen->Size = System::Drawing::Size(83, 12);
			this->lbl_AllowMaxDen->TabIndex = 23;
			this->lbl_AllowMaxDen->Text = L"���\�̤j�K�� :";
			this->lbl_AllowMaxDen->Visible = false;
			// 
			// lbl_AllowMinDen
			// 
			this->lbl_AllowMinDen->AutoSize = true;
			this->lbl_AllowMinDen->Location = System::Drawing::Point(90, 412);
			this->lbl_AllowMinDen->Name = L"lbl_AllowMinDen";
			this->lbl_AllowMinDen->Size = System::Drawing::Size(83, 12);
			this->lbl_AllowMinDen->TabIndex = 22;
			this->lbl_AllowMinDen->Text = L"���\�̤p�K�� :";
			this->lbl_AllowMinDen->Visible = false;
			// 
			// lbl_DotPitch
			// 
			this->lbl_DotPitch->AutoSize = true;
			this->lbl_DotPitch->Location = System::Drawing::Point(12, 372);
			this->lbl_DotPitch->Name = L"lbl_DotPitch";
			this->lbl_DotPitch->Size = System::Drawing::Size(61, 12);
			this->lbl_DotPitch->TabIndex = 21;
			this->lbl_DotPitch->Text = L"���I Pitch :";
			// 
			// cboPatternArragementStyle
			// 
			this->cboPatternArragementStyle->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboPatternArragementStyle->FormattingEnabled = true;
			this->cboPatternArragementStyle->Location = System::Drawing::Point(118, 116);
			this->cboPatternArragementStyle->Margin = System::Windows::Forms::Padding(4);
			this->cboPatternArragementStyle->Name = L"cboPatternArragementStyle";
			this->cboPatternArragementStyle->Size = System::Drawing::Size(78, 20);
			this->cboPatternArragementStyle->TabIndex = 20;
			this->cboPatternArragementStyle->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxRegularStyle_SelectedIndexChanged);
			// 
			// comboBoxPatternShape
			// 
			this->comboBoxPatternShape->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxPatternShape->FormattingEnabled = true;
			this->comboBoxPatternShape->Location = System::Drawing::Point(118, 88);
			this->comboBoxPatternShape->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxPatternShape->Name = L"comboBoxPatternShape";
			this->comboBoxPatternShape->Size = System::Drawing::Size(78, 20);
			this->comboBoxPatternShape->TabIndex = 19;
			this->comboBoxPatternShape->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxPatternShape_SelectedIndexChanged);
			// 
			// txt_MinDotGap
			// 
			this->txt_MinDotGap->Location = System::Drawing::Point(118, 58);
			this->txt_MinDotGap->Margin = System::Windows::Forms::Padding(4);
			this->txt_MinDotGap->Name = L"txt_MinDotGap";
			this->txt_MinDotGap->Size = System::Drawing::Size(73, 22);
			this->txt_MinDotGap->TabIndex = 18;
			// 
			// txt_MinDot
			// 
			this->txt_MinDot->Location = System::Drawing::Point(118, 34);
			this->txt_MinDot->Margin = System::Windows::Forms::Padding(4);
			this->txt_MinDot->Name = L"txt_MinDot";
			this->txt_MinDot->Size = System::Drawing::Size(73, 22);
			this->txt_MinDot->TabIndex = 17;
			// 
			// txt_maxDot
			// 
			this->txt_maxDot->Location = System::Drawing::Point(118, 7);
			this->txt_maxDot->Margin = System::Windows::Forms::Padding(4);
			this->txt_maxDot->Name = L"txt_maxDot";
			this->txt_maxDot->Size = System::Drawing::Size(73, 22);
			this->txt_maxDot->TabIndex = 16;
			this->txt_maxDot->TextChanged += gcnew System::EventHandler(this, &Form1::txt_maxDot_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(8, 96);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(59, 12);
			this->label13->TabIndex = 3;
			this->label13->Text = L"���I�Ϊ� :";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 61);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(97, 12);
			this->label12->TabIndex = 2;
			this->label12->Text = L"���\�̤p���j(d) :";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(5, 37);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(103, 12);
			this->label11->TabIndex = 1;
			this->label11->Text = L"���\�̤p���I(�r) :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 17);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 12);
			this->label7->TabIndex = 0;
			this->label7->Text = L"���\�̤j���I(�r) :";
			// 
			// tab_Random
			// 
			this->tab_Random->Controls->Add(this->lbl_SmallGapNumber);
			this->tab_Random->Controls->Add(this->groupBox3);
			this->tab_Random->Controls->Add(this->groupBox2);
			this->tab_Random->Controls->Add(this->lbl_AllowanceRandomDensity);
			this->tab_Random->Controls->Add(this->lbl_AverageForce);
			this->tab_Random->Controls->Add(this->lbl_RandomTotalNum);
			this->tab_Random->Controls->Add(this->lbl_RandomGirdNumber);
			this->tab_Random->Controls->Add(this->btn_Accept_RandomPattern);
			this->tab_Random->Controls->Add(this->txt_RandomDotSize);
			this->tab_Random->Controls->Add(this->label15);
			this->tab_Random->Controls->Add(this->lbl_RandomIteration);
			this->tab_Random->Controls->Add(this->lblpatdis);
			this->tab_Random->Controls->Add(this->txt_RandomDotGap);
			this->tab_Random->Location = System::Drawing::Point(4, 21);
			this->tab_Random->Name = L"tab_Random";
			this->tab_Random->Padding = System::Windows::Forms::Padding(3);
			this->tab_Random->Size = System::Drawing::Size(325, 444);
			this->tab_Random->TabIndex = 1;
			this->tab_Random->Text = L"�üƺ��I�]�w";
			this->tab_Random->UseVisualStyleBackColor = true;
			// 
			// lbl_SmallGapNumber
			// 
			this->lbl_SmallGapNumber->AutoSize = true;
			this->lbl_SmallGapNumber->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lbl_SmallGapNumber->Location = System::Drawing::Point(15, 410);
			this->lbl_SmallGapNumber->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_SmallGapNumber->Name = L"lbl_SmallGapNumber";
			this->lbl_SmallGapNumber->Size = System::Drawing::Size(84, 12);
			this->lbl_SmallGapNumber->TabIndex = 71;
			this->lbl_SmallGapNumber->Text = L"�p��Gap���I��";
			this->lbl_SmallGapNumber->Visible = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->txt_RandomParaK);
			this->groupBox3->Controls->Add(this->txt_RandomRebuildFrequency);
			this->groupBox3->Controls->Add(this->txt_RandomParaC);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->cbo_RandomDotSimRule);
			this->groupBox3->Location = System::Drawing::Point(4, 154);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(236, 142);
			this->groupBox3->TabIndex = 70;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"�i���]�w";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &Form1::groupBox3_Enter);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(33, 18);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 12);
			this->label10->TabIndex = 50;
			this->label10->Text = L"K Para :";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(33, 82);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 12);
			this->label9->TabIndex = 49;
			this->label9->Text = L"�B��k�h";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(33, 48);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 12);
			this->label14->TabIndex = 51;
			this->label14->Text = L"C Para :";
			// 
			// txt_RandomParaK
			// 
			this->txt_RandomParaK->Location = System::Drawing::Point(136, 15);
			this->txt_RandomParaK->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomParaK->Name = L"txt_RandomParaK";
			this->txt_RandomParaK->Size = System::Drawing::Size(73, 22);
			this->txt_RandomParaK->TabIndex = 53;
			// 
			// txt_RandomRebuildFrequency
			// 
			this->txt_RandomRebuildFrequency->Location = System::Drawing::Point(138, 110);
			this->txt_RandomRebuildFrequency->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomRebuildFrequency->Name = L"txt_RandomRebuildFrequency";
			this->txt_RandomRebuildFrequency->Size = System::Drawing::Size(73, 22);
			this->txt_RandomRebuildFrequency->TabIndex = 65;
			// 
			// txt_RandomParaC
			// 
			this->txt_RandomParaC->Location = System::Drawing::Point(136, 45);
			this->txt_RandomParaC->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomParaC->Name = L"txt_RandomParaC";
			this->txt_RandomParaC->Size = System::Drawing::Size(73, 22);
			this->txt_RandomParaC->TabIndex = 54;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(34, 113);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(101, 12);
			this->label17->TabIndex = 64;
			this->label17->Text = L"�C�j�X�����غ���";
			// 
			// cbo_RandomDotSimRule
			// 
			this->cbo_RandomDotSimRule->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbo_RandomDotSimRule->FormattingEnabled = true;
			this->cbo_RandomDotSimRule->Location = System::Drawing::Point(136, 79);
			this->cbo_RandomDotSimRule->Margin = System::Windows::Forms::Padding(4);
			this->cbo_RandomDotSimRule->Name = L"cbo_RandomDotSimRule";
			this->cbo_RandomDotSimRule->Size = System::Drawing::Size(78, 20);
			this->cbo_RandomDotSimRule->TabIndex = 55;
			this->cbo_RandomDotSimRule->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbo_RandomDotSimRule_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txt_RandomDotIteration);
			this->groupBox2->Controls->Add(this->txt_RandomCuttingForce);
			this->groupBox2->Controls->Add(this->chkRamdomStopForce);
			this->groupBox2->Controls->Add(this->chkRandomStopNumber);
			this->groupBox2->Location = System::Drawing::Point(3, 70);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(237, 78);
			this->groupBox2->TabIndex = 67;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"�פ����(�p������)";
			// 
			// txt_RandomDotIteration
			// 
			this->txt_RandomDotIteration->Location = System::Drawing::Point(121, 13);
			this->txt_RandomDotIteration->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomDotIteration->Name = L"txt_RandomDotIteration";
			this->txt_RandomDotIteration->Size = System::Drawing::Size(73, 22);
			this->txt_RandomDotIteration->TabIndex = 69;
			// 
			// txt_RandomCuttingForce
			// 
			this->txt_RandomCuttingForce->Location = System::Drawing::Point(121, 43);
			this->txt_RandomCuttingForce->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomCuttingForce->Name = L"txt_RandomCuttingForce";
			this->txt_RandomCuttingForce->Size = System::Drawing::Size(73, 22);
			this->txt_RandomCuttingForce->TabIndex = 68;
			// 
			// chkRamdomStopForce
			// 
			this->chkRamdomStopForce->AutoSize = true;
			this->chkRamdomStopForce->Location = System::Drawing::Point(6, 43);
			this->chkRamdomStopForce->Name = L"chkRamdomStopForce";
			this->chkRamdomStopForce->Size = System::Drawing::Size(108, 16);
			this->chkRamdomStopForce->TabIndex = 67;
			this->chkRamdomStopForce->Text = L"�����@�ΤO�p��";
			this->chkRamdomStopForce->UseVisualStyleBackColor = true;
			// 
			// chkRandomStopNumber
			// 
			this->chkRandomStopNumber->AutoSize = true;
			this->chkRandomStopNumber->Location = System::Drawing::Point(6, 21);
			this->chkRandomStopNumber->Name = L"chkRandomStopNumber";
			this->chkRandomStopNumber->Size = System::Drawing::Size(96, 16);
			this->chkRandomStopNumber->TabIndex = 66;
			this->chkRandomStopNumber->Text = L"�B�⦸�ƹF��";
			this->chkRandomStopNumber->UseVisualStyleBackColor = true;
			// 
			// lbl_AllowanceRandomDensity
			// 
			this->lbl_AllowanceRandomDensity->AutoSize = true;
			this->lbl_AllowanceRandomDensity->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lbl_AllowanceRandomDensity->Location = System::Drawing::Point(10, 390);
			this->lbl_AllowanceRandomDensity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_AllowanceRandomDensity->Name = L"lbl_AllowanceRandomDensity";
			this->lbl_AllowanceRandomDensity->Size = System::Drawing::Size(77, 12);
			this->lbl_AllowanceRandomDensity->TabIndex = 63;
			this->lbl_AllowanceRandomDensity->Text = L"���\�̤j�K��";
			// 
			// lbl_AverageForce
			// 
			this->lbl_AverageForce->AutoSize = true;
			this->lbl_AverageForce->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lbl_AverageForce->Location = System::Drawing::Point(9, 366);
			this->lbl_AverageForce->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_AverageForce->Name = L"lbl_AverageForce";
			this->lbl_AverageForce->Size = System::Drawing::Size(65, 12);
			this->lbl_AverageForce->TabIndex = 61;
			this->lbl_AverageForce->Text = L"�����@�ΤO";
			// 
			// lbl_RandomTotalNum
			// 
			this->lbl_RandomTotalNum->AutoSize = true;
			this->lbl_RandomTotalNum->Location = System::Drawing::Point(10, 345);
			this->lbl_RandomTotalNum->Name = L"lbl_RandomTotalNum";
			this->lbl_RandomTotalNum->Size = System::Drawing::Size(74, 12);
			this->lbl_RandomTotalNum->TabIndex = 60;
			this->lbl_RandomTotalNum->Text = L"�`���I�ƥ�  :";
			this->lbl_RandomTotalNum->Click += gcnew System::EventHandler(this, &Form1::lbl_TotalNum_Random_Click);
			// 
			// lbl_RandomGirdNumber
			// 
			this->lbl_RandomGirdNumber->AutoSize = true;
			this->lbl_RandomGirdNumber->Location = System::Drawing::Point(9, 303);
			this->lbl_RandomGirdNumber->Name = L"lbl_RandomGirdNumber";
			this->lbl_RandomGirdNumber->Size = System::Drawing::Size(47, 12);
			this->lbl_RandomGirdNumber->TabIndex = 59;
			this->lbl_RandomGirdNumber->Text = L"����� :";
			// 
			// btn_Accept_RandomPattern
			// 
			this->btn_Accept_RandomPattern->Location = System::Drawing::Point(188, 400);
			this->btn_Accept_RandomPattern->Name = L"btn_Accept_RandomPattern";
			this->btn_Accept_RandomPattern->Size = System::Drawing::Size(83, 32);
			this->btn_Accept_RandomPattern->TabIndex = 58;
			this->btn_Accept_RandomPattern->Text = L"�M��";
			this->btn_Accept_RandomPattern->UseVisualStyleBackColor = true;
			this->btn_Accept_RandomPattern->Click += gcnew System::EventHandler(this, &Form1::btn_Accept_Click);
			// 
			// txt_RandomDotSize
			// 
			this->txt_RandomDotSize->Location = System::Drawing::Point(112, 10);
			this->txt_RandomDotSize->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomDotSize->Name = L"txt_RandomDotSize";
			this->txt_RandomDotSize->Size = System::Drawing::Size(73, 22);
			this->txt_RandomDotSize->TabIndex = 57;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(9, 13);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(73, 12);
			this->label15->TabIndex = 56;
			this->label15->Text = L"���I�j�p(�r)";
			// 
			// lbl_RandomIteration
			// 
			this->lbl_RandomIteration->AutoSize = true;
			this->lbl_RandomIteration->Font = (gcnew System::Drawing::Font(L"�s�ө���", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lbl_RandomIteration->Location = System::Drawing::Point(9, 324);
			this->lbl_RandomIteration->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_RandomIteration->Name = L"lbl_RandomIteration";
			this->lbl_RandomIteration->Size = System::Drawing::Size(104, 12);
			this->lbl_RandomIteration->TabIndex = 47;
			this->lbl_RandomIteration->Text = L"�|�N����             �@";
			// 
			// lblpatdis
			// 
			this->lblpatdis->AutoSize = true;
			this->lblpatdis->Location = System::Drawing::Point(9, 44);
			this->lblpatdis->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblpatdis->Name = L"lblpatdis";
			this->lblpatdis->Size = System::Drawing::Size(84, 12);
			this->lblpatdis->TabIndex = 20;
			this->lblpatdis->Text = L"���I��Gap�j�p";
			// 
			// txt_RandomDotGap
			// 
			this->txt_RandomDotGap->Location = System::Drawing::Point(112, 41);
			this->txt_RandomDotGap->Margin = System::Windows::Forms::Padding(4);
			this->txt_RandomDotGap->Name = L"txt_RandomDotGap";
			this->txt_RandomDotGap->Size = System::Drawing::Size(73, 22);
			this->txt_RandomDotGap->TabIndex = 18;
			// 
			// tabPageIJP
			// 
			this->tabPageIJP->Controls->Add(this->cboIJPDPI);
			this->tabPageIJP->Controls->Add(this->label16);
			this->tabPageIJP->Controls->Add(this->IJP_chk_TextEdit);
			this->tabPageIJP->Controls->Add(this->group_Text);
			this->tabPageIJP->Controls->Add(this->lblTotalNumber);
			this->tabPageIJP->Controls->Add(this->label18);
			this->tabPageIJP->Controls->Add(this->IJP_txt_BlockY);
			this->tabPageIJP->Controls->Add(this->btn_IJP);
			this->tabPageIJP->Controls->Add(this->label19);
			this->tabPageIJP->Controls->Add(this->IJP_txt_DotSize);
			this->tabPageIJP->Controls->Add(this->IJP_txt_BlockX);
			this->tabPageIJP->Controls->Add(this->label8);
			this->tabPageIJP->Location = System::Drawing::Point(4, 21);
			this->tabPageIJP->Name = L"tabPageIJP";
			this->tabPageIJP->Padding = System::Windows::Forms::Padding(3);
			this->tabPageIJP->Size = System::Drawing::Size(325, 444);
			this->tabPageIJP->TabIndex = 2;
			this->tabPageIJP->Text = L"IJP �Q�L�]�w";
			this->tabPageIJP->UseVisualStyleBackColor = true;
			this->tabPageIJP->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// cboIJPDPI
			// 
			this->cboIJPDPI->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboIJPDPI->FormattingEnabled = true;
			this->cboIJPDPI->Location = System::Drawing::Point(78, 67);
			this->cboIJPDPI->Margin = System::Windows::Forms::Padding(4);
			this->cboIJPDPI->Name = L"cboIJPDPI";
			this->cboIJPDPI->Size = System::Drawing::Size(68, 20);
			this->cboIJPDPI->TabIndex = 94;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(9, 70);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(67, 12);
			this->label16->TabIndex = 93;
			this->label16->Text = L"�ѪR��(DPI)";
			// 
			// IJP_chk_TextEdit
			// 
			this->IJP_chk_TextEdit->AutoSize = true;
			this->IJP_chk_TextEdit->Location = System::Drawing::Point(7, 102);
			this->IJP_chk_TextEdit->Name = L"IJP_chk_TextEdit";
			this->IJP_chk_TextEdit->Size = System::Drawing::Size(96, 16);
			this->IJP_chk_TextEdit->TabIndex = 92;
			this->IJP_chk_TextEdit->Text = L"�ҥΤ�r�s��";
			this->IJP_chk_TextEdit->UseVisualStyleBackColor = true;
			this->IJP_chk_TextEdit->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkTextEdit_CheckedChanged);
			// 
			// group_Text
			// 
			this->group_Text->Controls->Add(this->groupBox9);
			this->group_Text->Controls->Add(this->IJP_cbo_TextLocation);
			this->group_Text->Controls->Add(this->label21);
			this->group_Text->Controls->Add(this->btnImportText);
			this->group_Text->Controls->Add(this->label22);
			this->group_Text->Controls->Add(this->label24);
			this->group_Text->Controls->Add(this->IJP_txt_TextLength);
			this->group_Text->Controls->Add(this->IJP_txt_TEXT);
			this->group_Text->Controls->Add(this->IJP_txt_TextHeight);
			this->group_Text->Controls->Add(this->IJP_txt_TextLocaX);
			this->group_Text->Controls->Add(this->lbl_LGP_Text);
			this->group_Text->Controls->Add(this->IJP_txt_TextLocaY);
			this->group_Text->Enabled = false;
			this->group_Text->Location = System::Drawing::Point(7, 124);
			this->group_Text->Name = L"group_Text";
			this->group_Text->Size = System::Drawing::Size(296, 268);
			this->group_Text->TabIndex = 91;
			this->group_Text->TabStop = false;
			this->group_Text->Text = L"��r�s��";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->btnX_Axis);
			this->groupBox9->Controls->Add(this->btnY_Axis);
			this->groupBox9->Controls->Add(this->button3);
			this->groupBox9->Controls->Add(this->btnNormal);
			this->groupBox9->Controls->Add(this->button2);
			this->groupBox9->Controls->Add(this->button1);
			this->groupBox9->Location = System::Drawing::Point(12, 159);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(243, 102);
			this->groupBox9->TabIndex = 88;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"����P��g";
			// 
			// btnX_Axis
			// 
			this->btnX_Axis->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnX_Axis.Image")));
			this->btnX_Axis->Location = System::Drawing::Point(145, 13);
			this->btnX_Axis->Name = L"btnX_Axis";
			this->btnX_Axis->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->btnX_Axis->Size = System::Drawing::Size(45, 35);
			this->btnX_Axis->TabIndex = 82;
			this->btnX_Axis->UseVisualStyleBackColor = true;
			this->btnX_Axis->Click += gcnew System::EventHandler(this, &Form1::btnX_Axis_Click);
			// 
			// btnY_Axis
			// 
			this->btnY_Axis->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnY_Axis.Image")));
			this->btnY_Axis->Location = System::Drawing::Point(92, 13);
			this->btnY_Axis->Name = L"btnY_Axis";
			this->btnY_Axis->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->btnY_Axis->Size = System::Drawing::Size(45, 35);
			this->btnY_Axis->TabIndex = 77;
			this->btnY_Axis->UseVisualStyleBackColor = true;
			this->btnY_Axis->Click += gcnew System::EventHandler(this, &Form1::btnY_Axis_Click);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(145, 57);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(46, 40);
			this->button3->TabIndex = 86;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// btnNormal
			// 
			this->btnNormal->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnNormal.Image")));
			this->btnNormal->Location = System::Drawing::Point(35, 13);
			this->btnNormal->Name = L"btnNormal";
			this->btnNormal->Size = System::Drawing::Size(46, 35);
			this->btnNormal->TabIndex = 76;
			this->btnNormal->UseVisualStyleBackColor = true;
			this->btnNormal->Click += gcnew System::EventHandler(this, &Form1::btnNormal_Click);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(91, 57);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 40);
			this->button2->TabIndex = 85;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(35, 57);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 40);
			this->button1->TabIndex = 84;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// IJP_cbo_TextLocation
			// 
			this->IJP_cbo_TextLocation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->IJP_cbo_TextLocation->FormattingEnabled = true;
			this->IJP_cbo_TextLocation->Location = System::Drawing::Point(77, 33);
			this->IJP_cbo_TextLocation->Margin = System::Windows::Forms::Padding(4);
			this->IJP_cbo_TextLocation->Name = L"IJP_cbo_TextLocation";
			this->IJP_cbo_TextLocation->Size = System::Drawing::Size(79, 20);
			this->IJP_cbo_TextLocation->TabIndex = 90;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(11, 36);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(59, 12);
			this->label21->TabIndex = 66;
			this->label21->Text = L"��r�y�� :";
			// 
			// btnImportText
			// 
			this->btnImportText->Location = System::Drawing::Point(234, 119);
			this->btnImportText->Name = L"btnImportText";
			this->btnImportText->Size = System::Drawing::Size(38, 24);
			this->btnImportText->TabIndex = 89;
			this->btnImportText->Text = L"�פJ";
			this->btnImportText->UseVisualStyleBackColor = true;
			this->btnImportText->Click += gcnew System::EventHandler(this, &Form1::btnImportText_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(11, 66);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(103, 12);
			this->label22->TabIndex = 67;
			this->label22->Text = L"��r�Q�L����(mm)";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(12, 93);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(127, 12);
			this->label24->TabIndex = 87;
			this->label24->Text = L"��r�Q�L�̤j����(mm)";
			// 
			// IJP_txt_TextLength
			// 
			this->IJP_txt_TextLength->Location = System::Drawing::Point(158, 90);
			this->IJP_txt_TextLength->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_TextLength->Name = L"IJP_txt_TextLength";
			this->IJP_txt_TextLength->Size = System::Drawing::Size(45, 22);
			this->IJP_txt_TextLength->TabIndex = 69;
			// 
			// IJP_txt_TEXT
			// 
			this->IJP_txt_TEXT->Location = System::Drawing::Point(116, 120);
			this->IJP_txt_TEXT->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_TEXT->Name = L"IJP_txt_TEXT";
			this->IJP_txt_TEXT->Size = System::Drawing::Size(111, 22);
			this->IJP_txt_TEXT->TabIndex = 83;
			// 
			// IJP_txt_TextHeight
			// 
			this->IJP_txt_TextHeight->Location = System::Drawing::Point(158, 60);
			this->IJP_txt_TextHeight->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_TextHeight->Name = L"IJP_txt_TextHeight";
			this->IJP_txt_TextHeight->Size = System::Drawing::Size(45, 22);
			this->IJP_txt_TextHeight->TabIndex = 70;
			// 
			// IJP_txt_TextLocaX
			// 
			this->IJP_txt_TextLocaX->Location = System::Drawing::Point(159, 33);
			this->IJP_txt_TextLocaX->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_TextLocaX->Name = L"IJP_txt_TextLocaX";
			this->IJP_txt_TextLocaX->Size = System::Drawing::Size(44, 22);
			this->IJP_txt_TextLocaX->TabIndex = 71;
			// 
			// lbl_LGP_Text
			// 
			this->lbl_LGP_Text->AutoSize = true;
			this->lbl_LGP_Text->Location = System::Drawing::Point(12, 125);
			this->lbl_LGP_Text->Name = L"lbl_LGP_Text";
			this->lbl_LGP_Text->Size = System::Drawing::Size(97, 12);
			this->lbl_LGP_Text->TabIndex = 73;
			this->lbl_LGP_Text->Text = L"IJP�Q�L��r���e :";
			// 
			// IJP_txt_TextLocaY
			// 
			this->IJP_txt_TextLocaY->Location = System::Drawing::Point(211, 33);
			this->IJP_txt_TextLocaY->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_TextLocaY->Name = L"IJP_txt_TextLocaY";
			this->IJP_txt_TextLocaY->Size = System::Drawing::Size(44, 22);
			this->IJP_txt_TextLocaY->TabIndex = 72;
			// 
			// lblTotalNumber
			// 
			this->lblTotalNumber->AutoSize = true;
			this->lblTotalNumber->Location = System::Drawing::Point(12, 418);
			this->lblTotalNumber->Name = L"lblTotalNumber";
			this->lblTotalNumber->Size = System::Drawing::Size(59, 12);
			this->lblTotalNumber->TabIndex = 65;
			this->lblTotalNumber->Text = L"�`���I�� :";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(131, 17);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(61, 12);
			this->label18->TabIndex = 61;
			this->label18->Text = L"�϶��j�pY";
			// 
			// IJP_txt_BlockY
			// 
			this->IJP_txt_BlockY->Location = System::Drawing::Point(209, 14);
			this->IJP_txt_BlockY->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_BlockY->Name = L"IJP_txt_BlockY";
			this->IJP_txt_BlockY->Size = System::Drawing::Size(45, 22);
			this->IJP_txt_BlockY->TabIndex = 60;
			this->IJP_txt_BlockY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtBlockY_KeyPress);
			// 
			// btn_IJP
			// 
			this->btn_IJP->Location = System::Drawing::Point(198, 398);
			this->btn_IJP->Name = L"btn_IJP";
			this->btn_IJP->Size = System::Drawing::Size(83, 32);
			this->btn_IJP->TabIndex = 59;
			this->btn_IJP->Text = L"�M��";
			this->btn_IJP->UseVisualStyleBackColor = true;
			this->btn_IJP->Click += gcnew System::EventHandler(this, &Form1::btn_IJP_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(10, 17);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(61, 12);
			this->label19->TabIndex = 25;
			this->label19->Text = L"�϶��j�pX";
			// 
			// IJP_txt_DotSize
			// 
			this->IJP_txt_DotSize->Location = System::Drawing::Point(133, 41);
			this->IJP_txt_DotSize->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_DotSize->Name = L"IJP_txt_DotSize";
			this->IJP_txt_DotSize->Size = System::Drawing::Size(73, 22);
			this->IJP_txt_DotSize->TabIndex = 23;
			this->IJP_txt_DotSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txt_IJPDotSize_KeyPress);
			// 
			// IJP_txt_BlockX
			// 
			this->IJP_txt_BlockX->Location = System::Drawing::Point(78, 14);
			this->IJP_txt_BlockX->Margin = System::Windows::Forms::Padding(4);
			this->IJP_txt_BlockX->Name = L"IJP_txt_BlockX";
			this->IJP_txt_BlockX->Size = System::Drawing::Size(45, 22);
			this->IJP_txt_BlockX->TabIndex = 22;
			this->IJP_txt_BlockX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtBlockX_KeyPress);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 44);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(103, 12);
			this->label8->TabIndex = 21;
			this->label8->Text = L"�Q��DotSize(50~55)";
			// 
			// tab_FM_Pattern
			// 
			this->tab_FM_Pattern->Controls->Add(this->label26);
			this->tab_FM_Pattern->Controls->Add(this->label28);
			this->tab_FM_Pattern->Controls->Add(this->lbl_FMMaxDen);
			this->tab_FM_Pattern->Controls->Add(this->label27);
			this->tab_FM_Pattern->Controls->Add(this->txtFMPattern);
			this->tab_FM_Pattern->Controls->Add(this->label23);
			this->tab_FM_Pattern->Controls->Add(this->label25);
			this->tab_FM_Pattern->Controls->Add(this->txtFMPatternGap);
			this->tab_FM_Pattern->Controls->Add(this->btnFMPattern);
			this->tab_FM_Pattern->Location = System::Drawing::Point(4, 21);
			this->tab_FM_Pattern->Name = L"tab_FM_Pattern";
			this->tab_FM_Pattern->Padding = System::Windows::Forms::Padding(3);
			this->tab_FM_Pattern->Size = System::Drawing::Size(325, 444);
			this->tab_FM_Pattern->TabIndex = 3;
			this->tab_FM_Pattern->Text = L"FM �üƺ��I";
			this->tab_FM_Pattern->UseVisualStyleBackColor = true;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(200, 45);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(25, 12);
			this->label26->TabIndex = 65;
			this->label26->Text = L"(�P)";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(200, 18);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(25, 12);
			this->label28->TabIndex = 64;
			this->label28->Text = L"(�P)";
			// 
			// lbl_FMMaxDen
			// 
			this->lbl_FMMaxDen->AutoSize = true;
			this->lbl_FMMaxDen->Location = System::Drawing::Point(12, 318);
			this->lbl_FMMaxDen->Name = L"lbl_FMMaxDen";
			this->lbl_FMMaxDen->Size = System::Drawing::Size(83, 12);
			this->lbl_FMMaxDen->TabIndex = 63;
			this->lbl_FMMaxDen->Text = L"���\�̤j�K�� :";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(12, 341);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(74, 12);
			this->label27->TabIndex = 62;
			this->label27->Text = L"�`���I�ƥ�  :";
			// 
			// txtFMPattern
			// 
			this->txtFMPattern->Location = System::Drawing::Point(115, 15);
			this->txtFMPattern->Margin = System::Windows::Forms::Padding(4);
			this->txtFMPattern->Name = L"txtFMPattern";
			this->txtFMPattern->Size = System::Drawing::Size(73, 22);
			this->txtFMPattern->TabIndex = 61;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(12, 18);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(73, 12);
			this->label23->TabIndex = 60;
			this->label23->Text = L"���I�j�p(�r)";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(12, 49);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(55, 12);
			this->label25->TabIndex = 59;
			this->label25->Text = L"Mini Gap :";
			// 
			// txtFMPatternGap
			// 
			this->txtFMPatternGap->Location = System::Drawing::Point(115, 46);
			this->txtFMPatternGap->Margin = System::Windows::Forms::Padding(4);
			this->txtFMPatternGap->Name = L"txtFMPatternGap";
			this->txtFMPatternGap->Size = System::Drawing::Size(73, 22);
			this->txtFMPatternGap->TabIndex = 58;
			// 
			// btnFMPattern
			// 
			this->btnFMPattern->Location = System::Drawing::Point(202, 380);
			this->btnFMPattern->Name = L"btnFMPattern";
			this->btnFMPattern->Size = System::Drawing::Size(83, 32);
			this->btnFMPattern->TabIndex = 25;
			this->btnFMPattern->Text = L"�M��";
			this->btnFMPattern->UseVisualStyleBackColor = true;
			this->btnFMPattern->Click += gcnew System::EventHandler(this, &Form1::btnFMPattern_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripProgressBar1});
			this->statusStrip1->Location = System::Drawing::Point(0, 756);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 18, 0);
			this->statusStrip1->Size = System::Drawing::Size(1282, 26);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->Stretch = false;
			this->statusStrip1->TabIndex = 52;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->AutoToolTip = true;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(41, 21);
			this->toolStripStatusLabel1->Text = L"���A�@";
			this->toolStripStatusLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolStripStatusLabel1->ToolTipText = L"���A1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(750, 20);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker2_DoWork);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker3_DoWork);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoScrollMargin = System::Drawing::Size(10, 10);
			this->AutoScrollMinSize = System::Drawing::Size(2, 2);
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(1282, 782);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->tabControll->ResumeLayout(false);
			this->tab_Regular->ResumeLayout(false);
			this->tab_Regular->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tab_Random->ResumeLayout(false);
			this->tab_Random->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPageIJP->ResumeLayout(false);
			this->tabPageIJP->PerformLayout();
			this->group_Text->ResumeLayout(false);
			this->group_Text->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->tab_FM_Pattern->ResumeLayout(false);
			this->tab_FM_Pattern->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
//-------------------------------------------------------------------------------------------------------
// ���s���� --------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
private: System::Void btn_click(System::Object^  sender, System::EventArgs^  e) {


//	1) Nurbs Dll :
//			a, B-Spline Surface ���� GridDensity.

//  2) DensityClass .DLL :
//          a. ��Density  ���� Pattern 
//  3) �����ק� :
//          a ,��X���I�X�i���
//  4) ���͹ϧ� :
//			case 1 : ��Density �M���I�X�i��ұo��̫�ϧ�
//	        case 2 : �S�����I�� ,�ȥ�Density ���͹ϧ�	
//
//   SurfacePatternDensity �w�q��0~100
//   PatternDensity �w�q�� 0~1 (�]����ܼƭȪ��d��O0~1)


		if(this->radioBtnRegular->Checked == true)
			this->backgroundWorker1->RunWorkerAsync();
		if(this->radioIJPBtn->Checked == true)
			this->backgroundWorker2->RunWorkerAsync();
		if(this->radio_FMPattern->Checked == true){
			this->backgroundWorker3->RunWorkerAsync();
		}


/*

				this->btn_ProducePattern->Enabled = false;

		bool success = false;
		//Point Resolution(2*this->GirdNumber.X+1,2*this->GirdNumber.Y+1); //Surface�n + 1
		Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface�n + 1
		this->Surface_Global_Design->SurfaceResolution::set(Resolution);	
	
		if( (this->Surface_Global_Design->IsInputDataChanged == true ||this->Surface_Global_Design->IsSurfaceEmpty == true)){

			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͦ���";
			this->statusStrip1->Update();
			if(this->�����վ㧡��ToolStripMenuItem->Checked == true) {
			//	success = this->ProduceGridDensity();
				this->SurfacePatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);	
				this->toolStripStatusLabel1->Text = "�p��K��";
				this->Surface_Global_Design->ProduceGridDensity(this->SurfacePatternDensity);

			}else if(this->���u�վ㧡��ToolStripMenuItem->Checked == true){
			//	success = this->ProduceGridDensity_ByTwoCurve();
			}else{
				MessageBox::Show("�п�ܧ��׽վ�覡");
				this->toolStripStatusLabel1->Text = "���A";
				this->statusStrip1->Update();
				return;
			}


			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͺ��I";
			this->statusStrip1->Update();

			//if(this->MainData->RandomDot == true){		
			if(this->MainData->DotType == 1){	
				this->Produce_RandomPattern();
			}else{
				Produce_RegularPattern(this->Dot,this->GirdNumber,this->MainData->LGPInformation,this->MainData->Pattern_Arrangment,this->SurfacePatternDensity); 
			}

		}

		this->toolStripProgressBar1->Value = 0;
		this->toolStripStatusLabel1->Text = "�����ק�";
		this->statusStrip1->Update();

		
		ModifyDotRate(this->localsurfacedata,this->Dot);

		//HotSpot �ק�
		if(this->HotSpotData != nullptr && this->HotSpotData->Count > 0){
			this->ProduceHotSpotDensity(this->Dot,this->HotSpotData);
		}

		//�Ѻ��I�Y���ҩM���I�K�׺�X�̲ת����I�K�� .
		
		this->PatternDensity = this->CalRegularPatternDensity(this->Dot ,this->GirdNumber,this->MainData->LGPInformation,0);			 



		






		if(this->Surface_Global_Design->IsSurfaceEmpty == false) {

			this->toolStripStatusLabel1->Text = "���͹ϧ�";
			
			this->toolStripProgressBar1->Value = 0;
			this->statusStrip1->Update();

			this->DrawDesignGridDensity(this->PatternDensity);
		}

		this->toolStripProgressBar1->Value = 100;
		this->toolStripStatusLabel1->Text = "�B�⧹��";
		this->statusStrip1->Update();

			
		this->UpdateMessage();
		this->CheckItem();
		
		this->btn_ProducePattern->Enabled = true;



//*/










	    










			 







	}

	

//---------------------------------------------------------------------------------------------------------
//  ���MenuBar ��k--------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------


private: System::Void ���}ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 Form1::Close();	
		 }
		
//----------------------------------------------------------------------------------------------------------		 
// �˵��\��-------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//��ܳ]�w---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------


private: System::Void ShowCurrentPatternToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



			this->PicSacleVaule = Math::Min(this->pictureBox1->Width/this->MainData->LGPInformation.Width*0.8f,this->pictureBox1->Height/this->MainData->LGPInformation.Height*0.8f);
			//��l�Ƽƭ�

			ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
			ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
			ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
			ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;


			 this->pictureBox1->Invalidate();



          //20090304   ��ܺ��I
/*
			ShowCurrentPatternToolStripMenuItem->Checked =! ShowCurrentPatternToolStripMenuItem->Checked;
			if(ShowCurrentPatternToolStripMenuItem->Checked == true){
				this->DrawCurrentPattern();
			}
*/

			
		 }
private: System::Void ShowDesignDensityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// 20090304 ��ܳ]�p�K��

			 /*

			 ShowDesignDensityToolStripMenuItem->Checked =!  ShowDesignDensityToolStripMenuItem->Checked;
			 ShowActualResultDensityToolStripMenuItem->Checked = false;	
			 if(ShowDesignDensityToolStripMenuItem->Checked == true){
				Graphics^ temp = this->pictureBox1->CreateGraphics();
				int picwidth = this->pictureBox1->Width;
				int picheight = this->pictureBox1->Height;	
				float scale = 0;
				//if(this->MainData->LGPDimension.Y  >= this->MainData->LGPDimension.X ){
				if(this->MainData->LGPInformation.Height  >= this->MainData->LGPInformation.Width ){
					scale = picheight/this->MainData->LGPInformation.Height *0.8f;
					//temp->DrawImage(this->Metafile_DesignGridDensity,(int)(picwidth-scale*this->MainData->LGPDimension.X )/2,(int)picheight/10,(int)(scale*this->MainData->LGPDimension.X ),(int)(scale*this->MainData->LGPDimension.Y ));
					temp->DrawImage(this->Metafile_DesignGridDensity,(int)(picwidth-scale*this->MainData->LGPInformation.Width )/2,(int)picheight/10,(int)(scale*this->MainData->LGPInformation.Width ),(int)(scale*this->MainData->LGPInformation.Height ));
				}
				else{
					scale = picwidth/this->MainData->LGPInformation.Width *0.8f;
					temp->DrawImage(this->Metafile_DesignGridDensity,(int)picwidth/10,(int)(picheight-scale*this->MainData->LGPInformation.Height )/2,(int)(scale*this->MainData->LGPInformation.Width),(int)(scale*this->MainData->LGPInformation.Height ));
				}		
				delete temp;

				
			 }
			 */

			 this->ZoomPic->Checked =!this->ZoomPic->Checked;


			 
			 if(this->ZoomPic->Checked == true){
				 this->pictureBox1->Focus();
			 }else{
				 //�Ѱ��J�I
				 this->pictureBox1->Enabled::set(false);
				 this->pictureBox1->Enabled::set(true);
			 }






			
		 }

private: System::Void ShowActualResultDensityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		  // 20090304  ��ܹ�ڱK��	

			 /*
			 ShowActualResultDensityToolStripMenuItem->Checked =! ShowActualResultDensityToolStripMenuItem->Checked;			
			 ShowDesignDensityToolStripMenuItem->Checked = false;
			 */

			 this->MovePic->Checked =!this->MovePic->Checked;


				 				
								


			
			 

			 
			
	
		 }


//------------------------------------------------------------------------------------------------------
//�s��]�w ---------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
//-------���ƥ�B�z------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		
		
			
			 
			

			 
//*		
			
			
			char *tmp = nullptr;

			// �o��IP��}
				
			String^	IPAddress =Dns::GetHostAddresses(Dns::GetHostName())[0]->ToString();
			
			//�ץ�IPAddress �bCLT ��������IP���ʮɭn���sLicense �����D
			int dot1 ,dot2;
			

			dot1 =IPAddress->IndexOf(".");
			dot2 =IPAddress->IndexOf(".",dot1+1);
			if(dot2 >=0) {
				IPAddress = IPAddress->Substring(0,dot2);
			}else {
			//	MessageBox::Show("�гs������!!!");
			//	Form1::Close();
			}


			//--------------------------------------------------------

			//�o����d��}
			array<Net::NetworkInformation::NetworkInterface^>^ mac = Net::NetworkInformation::NetworkInterface::GetAllNetworkInterfaces();
			String^	MacAddress = mac[0]->GetPhysicalAddress()->ToString();
						
		

			try{

			
				//�ӤH��

			//	String^ Information = IPAddress+MacAddress+Environment::UserDomainName+Environment::UserName+Environment::MachineName;

				//�j����
			//	String^ Information = IPAddress+MacAddress+Environment::UserDomainName+Environment::MachineName;

			
				
				



				ASCIIEncoding^ textConverter = gcnew ASCIIEncoding;
				RijndaelManaged^ myRijndael = gcnew RijndaelManaged;
				array<Byte>^fromEncrypt;
				array<Byte>^encrypted;
			//	array<Byte>^toEncrypt;
				array<Byte>^key;
				array<Byte>^IV;
			//	FILE *stream;

			//	if((stream =fopen("Licence.dat","rb+")) == nullptr){
					

	/*			

				//�N����o���q����ƥ[�K 				   
				//Create a new key and initialization vector.
					myRijndael->GenerateKey();
					myRijndael->GenerateIV();
				//Get the key and IV.
					key = myRijndael->Key;
					IV = myRijndael->IV;	   
				//Get an encryptor.
				   ICryptoTransform^ encryptor = myRijndael->CreateEncryptor( key, IV );				   
				//Encrypt the data.
				   MemoryStream^ msEncrypt = gcnew MemoryStream;
				   CryptoStream^ csEncrypt = gcnew CryptoStream( msEncrypt,encryptor,CryptoStreamMode::Write );				   
				//Convert the data to a Byte array.
				   toEncrypt = textConverter->GetBytes(Information);				   
				//Write all data to the crypto stream and flush it.
				   csEncrypt->Write( toEncrypt, 0, toEncrypt->Length );
				   csEncrypt->FlushFinalBlock();				 
				   encrypted = msEncrypt->ToArray();
							   
				   //*
				   System::IO::StreamWriter ^ sr = gcnew System::IO::StreamWriter(Environment::CurrentDirectory +"\\Licence.dat");
				  
				   for(int i = 0 ;i<key->Length ; i++){
					   sr->Write(key[i]);
				   }
				   for(int i = 0 ;i<IV->Length ; i++){
					   sr->Write(IV[i]);
				   }
			
				   for(int i = 0 ; i<encrypted->Length ; i++){
					sr->Write(encrypted[i]);			   						
				   }

				   sr->Close();
					MessageBox::Show("Licence Error !");
					Form1::Close();
				 
		*/		

				 


			//	}
			//	else{
	        
			//	fclose(stream);


				// �ѱK


//*


				System::IO::StreamReader ^ sr2 = gcnew System::IO::StreamReader(Environment::CurrentDirectory +"\\Licence.dat");


				
			
				//encrypted->Clear(nullptr,0,encrypted->Length);
				Byte tmpByte; 
				int count = 0;
				key = gcnew array<Byte>(0);
				IV = gcnew array<Byte>(0);
				encrypted = gcnew array<Byte>(0);
				while(sr2->EndOfStream == false){
					
					if(count < 31){			
						 Array::Resize(key, key->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						key->SetValue(tmpByte,key->Length-1);					
						count ++;

					}
					else if(count >= 31 && count <46 ){					
						Array::Resize(IV, IV->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						IV->SetValue(tmpByte,IV->Length-1);					
						count ++;

					}else if (count == 46){
						Array::Resize(key, key->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						key->SetValue(tmpByte,key->Length-1);	
						count ++;

					}else if (count == 47){
						Array::Resize(IV, IV->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						IV->SetValue(tmpByte,IV->Length-1);		
						count ++;

					}else{				
						Array::Resize(encrypted, encrypted->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						encrypted->SetValue(tmpByte,encrypted->Length-1);					
						count ++;
					}

				}
				sr2->Close();

				if ( key->Length != 32 || IV->Length != 16){
					MessageBox::Show("Licence Error !");
					Form1::Close();
				}
			
				//Get encrypted array of bytes.
				//encrypted = msEncrypt->ToArray();
			   
			   //This is where the message would be transmitted to a recipient
			   // who already knows your secret key. Optionally, you can
			   // also encrypt your secret key using a public key algorithm
			   // and pass it to the mesage recipient along with the RijnDael
			   // encrypted message.            
			   //Get a decryptor that uses the same key and IV as the encryptor.
			   ICryptoTransform^ decryptor = myRijndael->CreateDecryptor( key, IV );
			   
			   //Now decrypt the previously encrypted message using the decryptor
			   // obtained in the above step.
			  
			   MemoryStream^ msDecrypt = gcnew MemoryStream( encrypted );
			   CryptoStream^ csDecrypt = gcnew CryptoStream( msDecrypt,decryptor,CryptoStreamMode::Read );
			   fromEncrypt = gcnew array<Byte>(encrypted->Length);
			   
			   //Read the data out of the crypto stream.
			   csDecrypt->Read( fromEncrypt, 0, fromEncrypt->Length );
			   

			   String^ roundtrip;
			   //Convert the Byte array back into a String*.
			   roundtrip = textConverter->GetString( fromEncrypt );

			   array<String^>^ seproundtrip =roundtrip->Split(',');

			   int totalday ;
			   DateTime d1 = System::DateTime::Now::get();				
			   totalday = 365*d1.Year+12*d1.Month + d1.Day; 

			   if(seproundtrip[0]->default[0] == '0' ) {//�ϥΤ@�Ӥ�	  
				   if(Convert::ToInt64(seproundtrip[1]) - totalday <0){
					    MessageBox::Show("�W�L�ϥδ��� !!!");
						Form1::Close();
				   }
			   }

			   if(seproundtrip[0]->default[1] == '0' ){ //�ӤH��
				   if(String::Compare(seproundtrip[2],Environment::UserName) != 0){
					   MessageBox::Show("Licence Error !");
						Form1::Close();
				   }

			   }

			   	if(seproundtrip[0]->default[2] == '0' ){ //���q����
				   if((String::Compare(seproundtrip[3],IPAddress) || String::Compare(seproundtrip[4],Environment::UserDomainName))!= 0){
					   MessageBox::Show("Licence Error !");
						Form1::Close();
				   }

			   }

				
				

				// �@�w�n�T�{�� ~~!!!)

				if(String::Compare(seproundtrip[5],Environment::MachineName) != 0){
					   MessageBox::Show("Licence Error !");
						Form1::Close();
				}

				if(String::Compare(seproundtrip[6],MacAddress) != 0){
					   MessageBox::Show("Licence Error !");
						Form1::Close();
				}




			



				   





	
		//	}

		 
//*/
		  

		}   


   		   catch(...){
			    MessageBox::Show("Licence Error !");
				Form1::Close();

		   }


//*/


//----------------------------------------------20091217----------------------------------------------------------------------------------------
/*
			 
		





			

		
		
			
			

			try{

				String^ Information =Environment::UserDomainName+Environment::UserName+Environment::MachineName;


				ASCIIEncoding^ textConverter = gcnew ASCIIEncoding;
				RijndaelManaged^ myRijndael = gcnew RijndaelManaged;
				array<Byte>^fromEncrypt;
				array<Byte>^encrypted;
				array<Byte>^toEncrypt;
				array<Byte>^key;
				array<Byte>^IV;
				FILE *stream;

				if((stream =fopen("Licence.dat","rb+")) == nullptr){
					

				

				//�N����o���q����ƥ[�K 				   
				//Create a new key and initialization vector.
					myRijndael->GenerateKey();
					myRijndael->GenerateIV();
				//Get the key and IV.
					key = myRijndael->Key;
					IV = myRijndael->IV;	   
				//Get an encryptor.
				   ICryptoTransform^ encryptor = myRijndael->CreateEncryptor( key, IV );				   
				//Encrypt the data.
				   MemoryStream^ msEncrypt = gcnew MemoryStream;
				   CryptoStream^ csEncrypt = gcnew CryptoStream( msEncrypt,encryptor,CryptoStreamMode::Write );				   
				//Convert the data to a Byte array.
				   toEncrypt = textConverter->GetBytes(Information);				   
				//Write all data to the crypto stream and flush it.
				   csEncrypt->Write( toEncrypt, 0, toEncrypt->Length );
				   csEncrypt->FlushFinalBlock();				 
				   encrypted = msEncrypt->ToArray();
							   
				   //*
				   System::IO::StreamWriter ^ sr = gcnew System::IO::StreamWriter(Environment::CurrentDirectory +"\\Licence.dat");
				  
				   for(int i = 0 ;i<key->Length ; i++){
					   sr->Write(key[i]);
				   }
				   for(int i = 0 ;i<IV->Length ; i++){
					   sr->Write(IV[i]);
				   }
			
				   for(int i = 0 ; i<encrypted->Length ; i++){
					sr->Write(encrypted[i]);			   						
				   }

				   sr->Close();
					MessageBox::Show("Licence Error !");
					Form1::Close();
				 
				

				 


				}
				else{
	        
				fclose(stream);

				// �ѱK




				System::IO::StreamReader ^ sr2 = gcnew System::IO::StreamReader(Environment::CurrentDirectory +"\\Licence.dat");
			
				//encrypted->Clear(nullptr,0,encrypted->Length);
				Byte tmpByte; 
				int count = 0;
				key = gcnew array<Byte>(0);
				IV = gcnew array<Byte>(0);
				encrypted = gcnew array<Byte>(0);
				while(sr2->EndOfStream == false){
					
					if(count < 31){			
						 Array::Resize(key, key->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						key->SetValue(tmpByte,key->Length-1);					
						count ++;

					}
					else if(count >= 31 && count <46 ){					
						Array::Resize(IV, IV->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						IV->SetValue(tmpByte,IV->Length-1);					
						count ++;

					}else if (count == 46){
						Array::Resize(key, key->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						key->SetValue(tmpByte,key->Length-1);	
						count ++;

					}else if (count == 47){
						Array::Resize(IV, IV->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						IV->SetValue(tmpByte,IV->Length-1);		
						count ++;

					}else{				
						Array::Resize(encrypted, encrypted->Length + 1);
						tmpByte =Convert::ToByte(sr2->Read());
						encrypted->SetValue(tmpByte,encrypted->Length-1);					
						count ++;
					}

				}
				sr2->Close();

				if ( key->Length != 32 || IV->Length != 16){
					MessageBox::Show("Licence Error !");
					Form1::Close();
				}
			
				//Get encrypted array of bytes.
				//encrypted = msEncrypt->ToArray();
			   
			   //This is where the message would be transmitted to a recipient
			   // who already knows your secret key. Optionally, you can
			   // also encrypt your secret key using a public key algorithm
			   // and pass it to the mesage recipient along with the RijnDael
			   // encrypted message.            
			   //Get a decryptor that uses the same key and IV as the encryptor.
			   ICryptoTransform^ decryptor = myRijndael->CreateDecryptor( key, IV );
			   
			   //Now decrypt the previously encrypted message using the decryptor
			   // obtained in the above step.
			  
			   MemoryStream^ msDecrypt = gcnew MemoryStream( encrypted );
			   CryptoStream^ csDecrypt = gcnew CryptoStream( msDecrypt,decryptor,CryptoStreamMode::Read );
			   fromEncrypt = gcnew array<Byte>(encrypted->Length);
			   
			   //Read the data out of the crypto stream.
			   csDecrypt->Read( fromEncrypt, 0, fromEncrypt->Length );
			   

			   String^ roundtrip;
			   //Convert the Byte array back into a String*.
			   roundtrip = textConverter->GetString( fromEncrypt );

		   			if(String::Compare(roundtrip,Information) != 0){
					   MessageBox::Show("Licence Error !");
						Form1::Close();
					}
				
			}

		 

		  

		}   


   		   catch(...){
			    MessageBox::Show("Licence Error !");
				Form1::Close();

		   }
//*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------



 


		   

			


			




		

		   //��l�ưѼ�


		   	Version =gcnew String("Version 3.8 ");

			

		
			this->cboPatternArragementStyle->Text = "�ƦC�覡";
			this->cboPatternArragementStyle->Items->Add("�x�αƦC");
			this->cboPatternArragementStyle->Items->Add("45��-���ƱƦC");
			this->cboPatternArragementStyle->Items->Add("60��-���ƱƦC");
			this->cboPatternArragementStyle->Items->Add("30��-���ƱƦC");
			this->cboPatternArragementStyle->SelectedIndex = 2;

			this->comboBoxPatternShape->Text = "�Ϊ�";
			this->comboBoxPatternShape->Items->Add("���");
			this->comboBoxPatternShape->Items->Add("�x��");
			//this->comboBoxPatternShape->Items->Add("�٧�");
			this->comboBoxPatternShape->SelectedIndex = 0;

			this->cbo_RandomDotSimRule->Text = "�B��k�h";
			this->cbo_RandomDotSimRule->Items->Add("����");
			this->cbo_RandomDotSimRule->Items->Add("�x��");
			//this->cbo_RandomDotSimRule->Items->Add("���");
			this->cbo_RandomDotSimRule->SelectedIndex = 0;

			
			this->cboPitchDirection->Items->Add("X��V");
			this->cboPitchDirection->Items->Add("Y��V");
			this->cboPitchDirection->SelectedIndex = 0;


		
			this->IJP_cbo_TextLocation->Items->Add("���U�y��");
			this->IJP_cbo_TextLocation->Items->Add("���W�y��");
			this->IJP_cbo_TextLocation->Items->Add("�k�U�y��");
			this->IJP_cbo_TextLocation->Items->Add("�k�W�y��");
			this->IJP_cbo_TextLocation->SelectedIndex = 0;



			this->cboIJPDPI->Items->Add("400");
			this->cboIJPDPI->Items->Add("300");
			this->cboIJPDPI->SelectedIndex = 0;



			//�վ�Pitch
			this->groupBox5->Enabled = false;

			
		//	FileNew( NR);
			//mg = nullptr;
			//pt = nullptr;
		
			//relationPt = nullptr;
			
		//	NR = 0;
			
			Set_Data = gcnew SettingData();
			Cosmetic_LocalAreaData = gcnew Cosmetic_Data();
	
			 this->tab_Random->Enabled = false;	


			//ShowData();
			this->UpdateMainFormData();
			
	

			//Setting Form
			//Set_Data_Form = gcnew SettingForm();


			// B-Spline Surface �إ�
			this->Surface_Global_Design = gcnew Nurbs::B_Spline_Surface();


			//B-Spline Curve �إ�
			this->Curve_Horizontal = gcnew Nurbs::B_Spline_Curve();
			this->Curve_Vertical = gcnew Nurbs::B_Spline_Curve();

			this->Curve_Horizontal->xInitialize(PointF(0,120),PointF(543,120));
			this->Curve_Vertical->xInitialize(PointF(0,120),PointF(543,120));


		    this->localsurfacedata = gcnew ArrayList;
			this->HotSpotData = gcnew ArrayList;
			


		
			


			// �ϧΤưѼ� ------------------------------------------------------------------------------------------


			MainPicMatrix = gcnew Matrix(1.0f,0.0f,0.0f,-1.0f,0.0f,this->pictureBox1->Height); //�N�y���ഫ�����U�����y�Э��I
			
			
			


			this->ObjectCoordinate = gcnew array<PointF>(2); 


			 this->PicSacleVaule = Math::Min(this->pictureBox1->Width/this->MainData->LGPInformation.Width*0.8f,this->pictureBox1->Height/this->MainData->LGPInformation.Height*0.8f);


			//��l�Ƽƭ�

			ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
			ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
			ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
			ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;

			//----------------------------------------------------------------------------------------------------------


			//Version
			this->lblVersion->Text = "Software " + this->Version;


			this->CheckItem();

}






// ----------------------------------------------------------------------------------------------------------------
// �ƹ��\��]�w --------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------
//  �U�C����J�ѼƤ�Box �]�w�P�O�@-----------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

private: System::Void txtBoxCalNum_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 //20090304 ---�|�N����

			try{
				int pn;
				//String^ str = txtBoxCalNum->Text;
				String^ str = this->txt_RandomDotIteration->Text;
				//String^ str = this->txt_Random_Iteration->Text;
				if (str != "")	pn= Convert::ToInt32(str);			
				//inputdata.StopCriteriaIteriation = pn;
				this->MainData->RandomDotIteration = pn;


			}
			catch(...){
				this->btn_ProducePattern->Enabled = false;
				

			}

			

		 }





private: System::Void txtBoxPlateH_TextChanged(System::Object^  sender, System::EventArgs^  e) {


			 //20090304 --lgp �ؤo �e��

			 	
			 try{

				float ph;
				
				String^ str = this->txt_LGPWidth->Text;
				if (str != "") ph = Convert::ToSingle(str);
			
				if(ph > 0){
					//this->MainData->LGPDimension.Y = ph;
					this->MainData->LGPInformation.Height = ph;

				}
				else{
					MessageBox::Show("�ɥ����ؤo��J���~ !!");
					this->txt_LGPWidth->Text = String::Format("{0:0.00}",this->MainData->LGPInformation.Height);
					this->CheckItem();
					return;
				}


			}
			catch(...){
				MessageBox::Show("�ɥ����ؤo��J���~ !!");
				

			}

			this->CheckItem();

			

		 }
private: System::Void txtBoxPlateW_TextChanged(System::Object^  sender, System::EventArgs^  e) {

     //20090304 ��Jlgp �ؤo --��

			 try{

					float pw;
					
					String^ str = this->txt_LGPLength->Text;
					if (str != "") pw = Convert::ToSingle(str);
					
					if(pw>0){
					//	this->MainData->LGPDimension.X = pw;
						this->MainData->LGPInformation.Width = pw;
					}else{
						MessageBox::Show("�ɥ����ؤo��J���~ !!");
					//	this->txt_LGPLength->Text = String::Format("{0:0.00}",this->MainData->LGPDimension.X);
						this->txt_LGPLength->Text = String::Format("{0:0.00}",this->MainData->LGPInformation.Width);
						this->CheckItem();
						return;

					}

					
					



			


				


				}
			catch(...){
				
				MessageBox::Show("�ɥ����ؤo��J���~ !!");

			}
			this->CheckItem();

			
		 }

private: System::Void txtPatternSpace_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			//20090304 ---���I����Z��

			try{

				float patternSpace;
				String^ str = this->txt_RandomDotGap->Text;
				//String^ str = txtPatternSpace->Text;
				if (str != "")	patternSpace = Convert::ToSingle(str);
				//inputdata.Pattern_Space = patternSpace;
				this->MainData->RandomDotGap = patternSpace;
				
			//	ResetPointData();
			
			}
			catch(...){
				this->btn_ProducePattern->Enabled = false;
				

			}

		 }

private: System::Void FileNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->InputFileName = "";
			 this->CurrentDictionary = "";
			 this->PatternName = "";
			 this->ResetAll();
			 this->CheckItem();
	
		 }
private: System::Void txtBoxPlateW_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;			 
		 }

private: System::Void txtBoxPlateH_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtPatRadius_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxMeshW_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxMeshH_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxUp_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxDown_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxLeft_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxRight_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtPatNbr_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtPatternSpace_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }
private: System::Void txtBoxCalNum_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			  if ((e->KeyChar>='0' && e->KeyChar<='9') ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;
		 }



//------------------------------------------------------------------------------------------------------------------
// ----�U�C���x�s�ɮת�Sub------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			//�x�s�ɮ�
	//	try{
				bool success = false;
				String^ path = saveFileDialog1->FileName;
				
				//System::IO::StreamWriter ^ sr = gcnew
				//System::IO::StreamWriter(saveFileDialog1->FileName);

				System::IO::StreamWriter ^ sr = nullptr;
				//System::IO::StreamWriter ^ sr2 = nullptr;   //�x�s��@�ΰѼ��ɪ����|
				
				//int  tmpquotient  = NR/2000000; 	
				//int  tmpquotient  = 0; 	

				// Create a UTF7 encoding   
				//(�]�w�s�ɪ��s�X�覡 ,�ت��O���n������rŪ�JAutoCad���ýX])
				// �w�]�O �t�Τ���ANSI

				Encoding^ utf ;//= Encoding::Default;
				





				if (FileKind == 1){


					//AutoCad �x�s�ɥ�ANSI
					utf = Encoding::Default;

					this->toolStripStatusLabel1->Text = "Pattern��X";
					this->toolStripProgressBar1->Value = 0;
					this->statusStrip1->Update();

					
					

					sr =  gcnew	System::IO::StreamWriter(path,false,utf);
					success = SavePatternFile(sr,this->MainData,this->Dot,this->Cosmetic_LocalAreaData,this->project);

				


					//success =SavePatternFile(sr,this->MainData,pt,NR,2000000*tmpquotient,NR);					
					delete sr;
				}
				else{

					if (FileKind == 4) {
						
						
						utf = Encoding::Unicode;

						this->toolStripStatusLabel1->Text = "LT��X";
						this->toolStripProgressBar1->Value = 0;
						this->statusStrip1->Update();
						sr =  gcnew	System::IO::StreamWriter(path,false,utf);
						success = SaveLTPatternFile(sr,this->Dot,this->MainData,Set_Data);
						//success =SaveLTPatternFile(sr,pt,NR,this->MainData,Set_Data);
						sr->Close();

					}

					if(FileKind == 5){

						
						utf = Encoding::Default;

						this->toolStripStatusLabel1->Text = "IJP�ɮ׿�X";
						this->toolStripProgressBar1->Value = 0;
						this->statusStrip1->Update();
						sr =  gcnew	System::IO::StreamWriter(path,false,utf);
						int totalNumber = 0;
						success = Save_IJP_PatternFile(sr,IJP_DotSize,totalNumber,this->IJP_DPI);
						MessageBox::Show("�`���I�� =" +  Convert::ToString(totalNumber));
						sr->Close();

						// Header��
						//�M���ɮצW��
						FileInfo^ tmpParaInfo = gcnew System::IO::FileInfo(path);
						
						utf = Encoding::Default;
						this->toolStripStatusLabel1->Text = "IJP Header ��";
						this->toolStripProgressBar1->Value = 0;
						sr =  gcnew	System::IO::StreamWriter(tmpParaInfo->FullName+"_header.txt",false,utf);
						String^ str;						
						str=String::Format("X Resolution=" + "{0:#0.0#}"+ ";",this->IJP_DPI);
						sr->WriteLine(str);
						str=String::Format("Y Resolution=" + "{0:#0.0#}"+ ";",this->IJP_DPI);
						sr->WriteLine(str);
						str = "X Copy=1;";
						sr->WriteLine(str);
						str = "Y Copy=1;";
						sr->WriteLine(str);
						str = String::Format("X Material Size=" + "{0:#0.000#}" +";",this->MainData->LGPInformation.Width);
						sr->WriteLine(str);
						str = String::Format("Y Material Size=" + "{0:#0.000#}" +";",this->MainData->LGPInformation.Height);
						sr->WriteLine(str);
						str = "X Space=0.000000;";
						sr->WriteLine(str);
						str = "Y Space=0.000000;";
						sr->WriteLine(str);
						str = String::Format("File Size=" + "{0:#0#}"+ ";",totalNumber);
						sr->WriteLine(str);
						str = "Drop=1;";
						sr->WriteLine(str);
						str = String::Format("1 Drop=" + "{0:#0.0000#}" +";",this->MainData->IJP_DotSize/1000.0f) ;
						sr->WriteLine(str);
						str = String::Format("Pattern File Name=" + "{0:#0.0#}"+";",tmpParaInfo->Name); 
						sr->WriteLine(str);
																					
						sr->Close();

						//���ե� -------------------------------------------------------------------

						/*

						this->Dot->Initialize_me();
						this->Dot->BuildPattern(totalNumber);
						this->Dot->ModifyRate_HotSpot = gcnew array<float>(this->Dot->GetDotNumber());
						this->Dot->ModifyRate_LocalArea = gcnew array<float>(this->Dot->GetDotNumber());
						for(int ii = 0 ; ii <this->Dot->GetDotNumber() ; ii++){							
							this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
						}

						long count = 0;

						for(int ii = 0 ; ii <IJP_DotSize->GetLength(0) ; ii ++){
							for(int jj = 3*IJP_DotSize->GetLength(1)/6 ; jj <4*IJP_DotSize->GetLength(1)/6 ; jj++){

								float dia = Convert::ToSingle(IJP_DotSize->GetValue(ii,jj));
								if( dia> 0){
									this->Dot->SetDotValue(PointF(ii*0.0635,jj*0.0635),dia/1000.0f,count);
									count ++;
								}
							}
						}

						//*/

						
							

						//--------------------------------------------------------------------------
						
						

					}
					if (FileKind == 6){
						//IJP Primer Pattern ....
						

						//AutoCad �x�s�ɥ�ANSI
						utf = Encoding::Default;

						this->toolStripStatusLabel1->Text = "IJP_Primer Pattern��X";
						this->toolStripProgressBar1->Value = 0;
						this->statusStrip1->Update();


						Cosmetic_Data^ tmpCosmetic = gcnew Cosmetic_Data();
										
						//�N���I�Ϊ��]��Circle ,�åB�������e��Shape .
						//int pre_shape  = this->MainData->Pattern_Shape;
						//this->MainData->Pattern_Shape = 0;



//���Primer ��� ,���ϥΪ�KeyIn �Ѽ� -------------------------------------------------------------------------

						bool Cutting =false;
						float dotSize = 0.15f;
						float dotGap = 0.05f;
						int FileNumber = 1 ;
						Point ArrayNumber(1,1);
						PointF ArrayPitch(0.0f,0.0f);
						if(this->LGPPolyLinePt != nullptr && this->LGPPolyLinePt->Count > 3) {
							Cutting = true;
						}


						IJP_Primer_Pattern^ PrimerForm = gcnew  IJP_Primer_Pattern(&Cutting,&dotSize,&dotGap,&FileNumber,this->MainData->LGPInformation,&ArrayNumber,&ArrayPitch);
						PrimerForm->ShowDialog();
//-------------------------------------------------------------------------------------------------------------
//�]�w���� �j�p -----------------------------------------------------------------------------------------------

						
						float size[2];
						size[0] = dotSize + dotGap ;
						size[1] = size[0]*Math::Sqrt(3);
						Point tmpGridNumber((int)Math::Round(this->MainData->LGPInformation.Width/size[0]),(int)Math::Round(this->MainData->LGPInformation.Height/size[1]));


//-------------------------------------------------------------------------------------------------------------
//�إߤ���Section

						array<int>^ section = gcnew array<int>(FileNumber+1);
						for(int ii = 0 ; ii < FileNumber+1 ; ii ++){
							int Y = Math::Round(ii*tmpGridNumber.Y/(FileNumber));
							section->SetValue(Y,ii);
						}

						
//----------------------------------------------------------------------------------------------------------------

					
					
						String^ tmpCode ;

						for(int kk = 0 ; kk < FileNumber ; kk ++){

							tmpCode = "_" + Convert::ToString(kk) ;
							if(FileNumber >1)
								path = path->Insert(path->Length-4,tmpCode );

						
							
							sr =  gcnew	System::IO::StreamWriter(path,false,utf);

							

							//���ͺ��I
							Pattern^ tmpDot;
							tmpDot = gcnew Pattern();

							long NR ;
							if( FileNumber > 1) {
								if( kk != 0) NR = ArrayNumber.X*ArrayNumber.Y*(2*tmpGridNumber.X-1)*(section[kk+1] -section[kk]);
								else NR = ArrayNumber.X*ArrayNumber.Y*(tmpGridNumber.X*(section[kk+1] -section[kk]) +(tmpGridNumber.X-1)*(section[kk+1] -section[kk]-1)) ;
							}else{
								NR = ArrayNumber.X*ArrayNumber.Y*(tmpGridNumber.X*(section[kk+1] -section[kk]) +(tmpGridNumber.X-1)*(section[kk+1] -section[kk]-1)) ;
							}

							tmpDot->BuildPattern(NR);

							

							int tmpIndex = 0;
							//����W�����I�y��
							for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
								for(int jj = section[kk] ;jj < section[kk+1] ; jj++){
									//Array ���I
									for(int ll = 0 ; ll < ArrayNumber.X ; ll++){
										for(int mm= 0 ;mm < ArrayNumber.Y ;mm++){
											Point index(ii,jj);							
											PointF dot_coor((ii+0.5f)*size[0]+ll*ArrayPitch.X,(jj+0.5f)*size[1]+mm*ArrayPitch.Y);								
											tmpDot->SetDotValue(dot_coor,dotSize,tmpIndex);
											tmpIndex ++ ;
										}
									}
								}								
							}
						
							//���涡������y��
							int startIndex;
							if( FileNumber > 1) {
								if( kk != 0) startIndex = section[kk]-1;
								else startIndex = section[kk];
							}else{
								startIndex = section[kk];
							}

							for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
								for(int jj = startIndex ;jj < section[kk+1]-1 ; jj++){
									for(int ll = 0 ; ll < ArrayNumber.X ; ll++){
										for(int mm= 0 ;mm < ArrayNumber.Y ;mm++){
											Point index(ii,jj);																		
											PointF dot_coor((ii+1)*size[0]+ll*ArrayPitch.X,(jj+1)*size[1]+mm*ArrayPitch.Y);
											tmpDot->SetDotValue(dot_coor,dotSize,tmpIndex);
											tmpIndex ++ ;
										}
									}
								}								
							}

							//�P�B����-----------------------------------------------------------------------------------------------
							if(Cutting == true) {														
								 for(int ii = 0 ;ii < tmpDot->GetDotNumber() ; ii ++){
									PointF coord;
									float dotsize;
									tmpDot->GetDotValue(coord,dotsize,ii);
									 if(this->IsPtInside(coord,this->LGPPolyLinePt) == false){
										 tmpDot->SetDotValue(coord,0.0f,ii);
									 }
								}															  							
						
							}

							

							//�s��
							this->toolStripStatusLabel1->Text = "�i��s��";
							
							array<RectangleF,1>^ OutLine = gcnew array<RectangleF>(ArrayNumber.X*ArrayNumber.Y) ;
							int count = 0;
							for(int ii = 0 ; ii < ArrayNumber.X ; ii++){
								for(int jj = 0 ; jj <ArrayNumber.Y ;jj++){
									RectangleF tmp(this->MainData->LGPInformation.X + ii*ArrayPitch.X,this->MainData->LGPInformation.Y +jj*ArrayPitch.Y,this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);
									OutLine->SetValue(tmp,count);
									count ++;
								}
							}

							success = SavePatternFile(sr,OutLine,0,tmpDot,tmpCosmetic); //0����� ,1���x��
							delete[] tmpDot;
							delete[] OutLine;
							

							if(FileNumber > 1)
								path = path->Remove(path->Length-4-tmpCode->Length,tmpCode->Length);

				
						}


						//�^�s���e��Shape .
						//this->MainData->Pattern_Shape = pre_shape;

		
					
						delete[] tmpCosmetic;
					

					}

					if (FileKind == 8){

						utf = Encoding::Unicode;

						this->toolStripStatusLabel1->Text = "�M���ɿ�X";
						this->toolStripProgressBar1->Value = 0;
						this->statusStrip1->Update();
						sr = gcnew	System::IO::StreamWriter(saveFileDialog1->FileName,false,utf);

						//��sMainFormData.
						//3.5.1�����e��
						//success = SaveCLT_V3( sr,3 ,this->MainData,1 ,Surface_Global_Design,1 ,this->localsurfacedata,1 ,this->Curve_Horizontal,this->Curve_Vertical,1,project,1,this->HotSpotData);
						//3.6�����e��
						success = SaveCLT_V3( sr,3 ,this->MainData,1 ,Surface_Global_Design,1 ,this->localsurfacedata,1 ,this->Curve_Horizontal,this->Curve_Vertical,1,project,2,this->HotSpotData);


						


						sr->Close();

						//�x�s���
						//String^ Dic = saveFileDialog1->FileName;
						
						//sr2 = gcnew	System::IO::StreamWriter("X:\\CCC.clt2");
						//success = SaveCLT_V3( sr2,1 ,this->MainData,1 ,Surface_Global_Design,1 ,this->localsurfacedata,1 ,this->Curve_Horizontal,this->Curve_Vertical,1,project);
						//sr2->Close();

						
					}

					
				}
				if (success == true) {
					this->toolStripStatusLabel1->Text = "�s�ɦ��\";
					this->toolStripProgressBar1->Value = 100;

					//�]�w���|��-------------------------------------------------------
					//array<String^>^ tmpStr = saveFileDialog1->FileName->Split('\\');
					//String^ Str = "" ;
					//for(int ii = 0 ; ii < tmpStr->Length-1 ; ii ++){
					//	Str = Str + tmpStr[ii] + "\\" ;
					//}
					//Directory::SetCurrentDirectory(Str) ;
					//-----------------------------------------------------------------

					//�M���ɦW��
					if (FileKind == 8){
						//�M���ɮצW��
						FileInfo^ ParaInfo = gcnew System::IO::FileInfo(path);
						this->InputFileName = ParaInfo->Name ;
						this->CurrentDictionary = ParaInfo->DirectoryName;
					}
					if (FileKind == 1) {
						//DXF �ɮצW��
						FileInfo^ PatternInfo = gcnew System::IO::FileInfo(path);
						this->PatternName = PatternInfo->Name;
					}
				
					this->UpdateMainFormData();
					
					
				}
				else {
					toolStripStatusLabel1->Text = "�s�ɿ��~";
					this->toolStripProgressBar1->Value = 0;
				}
				this->statusStrip1->Update();
//		}catch(System::FieldAccessException^ e){
//			MessageBox::Show(e->ToString());
	//	}catch(...){
			
	//		MessageBox::Show("�s�ɿ��~");
	//	};

		

		 }

private: System::Void �x�sPattern�ɮ�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			FileKind = 1;
			if(this->project->projectName !="" && this->project->PatternVersion !="")
				saveFileDialog1->FileName = "Dxf-" + this->project->projectName + "-" + this->project->PatternVersion;
			else	saveFileDialog1->FileName = "DxfPattern";

			saveFileDialog1->Filter = "DxfFormat (*.dxf)|*.dxf";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".dxf";
			//saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();

		//	if(InputFileName == nullptr)
		//		saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();

			if(this->CurrentDictionary == "") saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			else  saveFileDialog1->InitialDirectory = this->CurrentDictionary;



			saveFileDialog1->ShowDialog();
			this->CheckItem();
			
		 }
private: System::Void SaveLTPatternFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		//	#ifdef _DEBUG
		//		bool success = false;
		//		MessageBox::Show("Debug");
		//		System::IO::StreamWriter ^ sr = nullptr;
		//		sr =  gcnew	System::IO::StreamWriter("D://test.txt");	
		//		success =SaveLTPatternFile(sr,pt,NR,inputdata,Set_Data);
		//		sr->Close();


		//	#else
			 	FileKind =4;
				saveFileDialog1->FileName = "LTPattern";
				saveFileDialog1->Filter = "�ڢ���I�ɮ� (*.txt)|*.txt";
				saveFileDialog1->FilterIndex = 1;
				saveFileDialog1->RestoreDirectory = true;
				saveFileDialog1->DefaultExt = ".txt";
				
			//	if(InputFileName == nullptr)	InputFileName = Directory::GetCurrentDirectory();
			//	saveFileDialog1->InitialDirectory = InputFileName;

				if(this->CurrentDictionary == "")	saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
				else saveFileDialog1->InitialDirectory = CurrentDictionary;

				saveFileDialog1->ShowDialog();

		//	#endif


		 }

private: System::Void �M����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			FileKind = 7;
			saveFileDialog1->FileName = "CLT_1";
			saveFileDialog1->Filter = "�M���� (*.txt)|*.txt";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".txt";
			
			//if(InputFileName == nullptr)	InputFileName = Directory::GetCurrentDirectory();
			//saveFileDialog1->InitialDirectory = InputFileName;		

			if(this->CurrentDictionary == "")	saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			else saveFileDialog1->InitialDirectory = CurrentDictionary;

			
			saveFileDialog1->ShowDialog();

		 }
private: System::Void �M����090112ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			FileKind = 8;
			if(this->project->projectName !="" && this->project->PatternVersion !="")
				saveFileDialog1->FileName = this->project->projectName + "_" + this->project->PatternVersion;
			else	saveFileDialog1->FileName = "CLT_V3";
			saveFileDialog1->Filter = "�M���� (*.clt2)|*.clt2";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".clt2";
			//if(InputFileName == nullptr)	InputFileName = Directory::GetCurrentDirectory();
			//saveFileDialog1->InitialDirectory = InputFileName;

			if(this->CurrentDictionary == "")	saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			else saveFileDialog1->InitialDirectory = CurrentDictionary;

				
			saveFileDialog1->ShowDialog();
			
		 }
//=============================================================================================================================
//   �U�C���}���ɮת�Sub
//=============================================================================================================================

private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 //Ū�J�ɮ�
			
		//	try{








				
				DataInput inputdata;
				bool success = false;
				bool filenew = false;
				String^ path = openFileDialog->FileName;
				System::IO::StreamReader ^ sr;



				//��o��󪺼g�J���				
				DateTime establishTime;
				establishTime =  System::IO::File::GetLastWriteTime(openFileDialog->FileName);


				//�ɮ׭ק�ɶ� (�H�����e���s�X�覡���@��)
				DateTime ModifyTime =  DateTime(2011,8,4);

				
				
				
				
	
				


				//���P���إߤ���s�X�覡���@�� 
				
				if(DateTime::Compare(establishTime,ModifyTime)<=0 || openFileDialog->FilterIndex != 0){
					//��ܥ��ª����ɮ�
					sr = gcnew System::IO::StreamReader(openFileDialog->FileName);
				}else {
					//��ܥηs�����s�X�覡�x�s
					
					// Create a UTF7 encoding   
					//(�]�w�s�ɪ��s�X�覡 ,�ت��O���n������rŪ�JAutoCad���ýX])
					// �w�]�O �t�Τ���ANSI
					
					//Encoding^ utf = Encoding::Default;
					Encoding^ utf = Encoding::Unicode;

				    sr = gcnew System::IO::StreamReader(openFileDialog->FileName,utf);
				}

				

				

			

			

				if(FileKind == 1){

				
					RectangleF^ LGP = gcnew RectangleF() ;
					PointF^ Pitch = gcnew PointF(); 
					
				

					
				//	success = OpenPatternFile(sr,this->Dot);
				//	success = OpenPatternFile(sr,this->Dot,tmpLGP);
					success = OpenPatternFile(sr,this->Dot,Pitch,LGP);
					
				
					this->PatternDensity = this->CalNearlyRegularDotDensity(this->Dot,Pitch,LGP);
					this->DrawDesignGridDensity(this->PatternDensity);


					
					
					//�إ� ScreenMura ����
					Point tmpGrid;
					RectangleF tmpLGP(LGP->X,LGP->Y,LGP->Width,LGP->Height);

					tmpGrid.X = PatternDensity->GetMeshNumber().X*2;
					tmpGrid.Y = PatternDensity->GetMeshNumber().Y*2;


					this->ScreenMuraData = gcnew GridDensity(tmpGrid,tmpLGP);
					for(int ii = 0 ; ii <tmpGrid.X ;ii++){
						for(int jj = 0 ; jj <tmpGrid.Y ;jj++){
							this->ScreenMuraData->SetDensityValue(0.0f,Point(ii,jj));
						}
					}
			


				
					bool booldot  ;
					if(this->Dot->GetDotNumber() == 0) booldot = false;
					else booldot = true;

					if(success == false){
						MessageBox::Show("Ū�����I����!!");
					}else if(booldot == false){
						MessageBox::Show("Ū�����κ��I!!");
					}else{

						
						this->MainData->LGPInformation.X = LGP->X;
						this->MainData->LGPInformation.Y = LGP->Y;
						this->MainData->LGPInformation.Width = LGP->Width;
						this->MainData->LGPInformation.Height = LGP->Height;
						this->UpdateMainFormData();
					//	this->Dot->ModifyRate_HotSpot = gcnew array<float>(this->Dot->GetDotNumber());
						this->Dot->ModifyRate_LocalArea = gcnew array<float>(this->Dot->GetDotNumber());
						for(int ii = 0 ; ii <this->Dot->GetDotNumber() ; ii++){							
							this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
						}
						
					}

				}else if (FileKind == 2){
					//Ū�J���䪺�~�� LGPPolyLinePt
					while(sr->EndOfStream != true){						
						String^ str ;									
						str = sr->ReadLine();
						if (str->CompareTo("POLYLINE") == 0){
							if(LGPPolyLinePt == nullptr) LGPPolyLinePt = gcnew List<PointF>(0);	
							else LGPPolyLinePt->Clear();							
							success = xOpenAutoCad_PolyLine(sr ,LGPPolyLinePt); //�}��PolyLine
						}
					}												
				}else if (FileKind == 8){

					//*
					//�M�Ÿ��
					if(this->project != nullptr) this->project->ClearAll();
					if(this->SurfacePatternDensity != nullptr) this->SurfacePatternDensity->ClearAll();
					if(this->localsurfacedata->Count >=0) this->localsurfacedata->Clear();
					if(this->Surface_Global_Design->IsSurfaceEmpty == false) delete  this->Surface_Global_Design;
					this->MainData->Initialize();

					



						//openFileDialog->Filter = "�M���� R1 (*.clt)|*.clt|�M����CLT_090112 (*.txt)|*.txt|�M����OldVersion (*.txt)|*.txt";
						if(openFileDialog->FilterIndex == 2){
							success = OpenCLT_R1(sr,this->MainData,this->Surface_Global_Design,this->localsurfacedata,this->Curve_Horizontal,this->Curve_Vertical);
							this->Curve_Horizontal->Set_k_Value(this->Curve_Horizontal->ControllPt->Count);
							this->Curve_Vertical->Set_k_Value(this->Curve_Vertical->ControllPt->Count);

						}else if (openFileDialog->FilterIndex == 3){
							success = OpenCLT_Characteristic_090112_File(sr,inputdata,filenew , Surface_Global_Design);	
							this->MainData->GetInputData(inputdata);
						}else if (openFileDialog->FilterIndex == 4){
							//OpenCLT_Characteristic_File(this->Density,sr,inputdata,filenew);
							OpenCLT_Characteristic_File(this->PatternDensity,sr,inputdata,filenew);
							this->MainData->GetInputData(inputdata);
						}else if (openFileDialog->FilterIndex == 1){
							success = OpenCLT_V3( sr,this->MainData,this->Surface_Global_Design, this->localsurfacedata,this->Curve_Horizontal,this->Curve_Vertical,this->project,this->HotSpotData);
						}


				}





				if (success == true) {
					this->toolStripStatusLabel1->Text = "�}�ɦ��\";
					this->toolStripProgressBar1->Value = 100;
					//�]�w���|��-------------------------------------------------------
					//array<String^>^ tmpStr = openFileDialog->FileName->Split('\\');
					//String^ Str = "" ;
					//for(int ii = 0 ; ii < tmpStr->Length-1 ; ii ++){
					//	Str = Str + tmpStr[ii] + "\\" ;
					//}
					//Directory::SetCurrentDirectory(Str) ;
					//-----------------------------------------------------------------

					if(FileKind == 8) {					
						//�M���ɮצW��
						FileInfo^ ParaInfo = gcnew System::IO::FileInfo(path);
						this->InputFileName = ParaInfo->Name ;
						this->CurrentDictionary = ParaInfo->DirectoryName;
						this->UpdateMessage();
					}
					if (FileKind == 1) {
						//DXF �ɮצW��
						FileInfo^ PatternInfo = gcnew System::IO::FileInfo(path);
						this->PatternName = PatternInfo->Name;
						this->UpdateMessage();
					}


					this->UpdateMainFormData();
				//	this->UpdateMessage();
					
				}
				else {
					toolStripStatusLabel1->Text = "�}�ɿ��~";
					this->toolStripProgressBar1->Value = 0;
				}
				this->statusStrip1->Update();
		//	}
		//	catch(...){
		//		MessageBox::Show("�}�ɿ��~");
		//		toolStripStatusLabel1->Text = "�}�ɿ��~";
		//	}


}



private: System::Void OpenpatternToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



			 MessageBox::Show("�ϥ� Beta2 M3 �H�e�������ͪ�Dxf ,�Х���AutoCad�t�s�� Dxf �ɮ׫�A�i��Ū�� !!! ");



			 if(this->Dot != nullptr){
				 if(this->Dot->GetDotNumber() > 0){
					System::Windows::Forms::DialogResult result;
					result= MessageBox::Show("�{�����w��Pattern ,�O�_���J ?" ,"ĵ�i",MessageBoxButtons::YesNo);
					if( result == ::DialogResult::Yes){
						this->Dot->Initialize_me();
						this->CheckItem();
					}else{
						return;
					}

				 }else{

					this->Dot->Initialize_me();
					this->CheckItem();
					
				 }
			 }
		






			


			//�}��Pattern�ɮ�
		//	#ifdef _DEBUG
			//	MessageBox::Show("Debug");
			//	bool success = false;
			//	FileKind = 1;			 
			//	String^ path = "D:/data/Dxf_Test.dxf";
			//	System::IO::StreamReader ^ sr = gcnew
			//	System::IO::StreamReader(path);
			//	long tmpNR;
			//	if (pt != nullptr) delete[] pt;
			//	this->pt = OpenPatternFile(sr,tmpNR);
			//	this->NR = tmpNR;
			//	ShowData();
			//	CheckInputError();	
			//	Viewoperation(3) ;
		//	#else
			 
				FileKind =1;
				openFileDialog->FileName = "PatternFile";
				openFileDialog->Filter = "Pattern�ɮ� (*.dxf)|*.dxf";
				openFileDialog->FilterIndex = 1;
				openFileDialog->RestoreDirectory = true;
				openFileDialog->DefaultExt=".dxf";
				if(InputFileName == nullptr){
					openFileDialog->InitialDirectory = Directory::GetCurrentDirectory();	
				}
				else{
					openFileDialog->InitialDirectory = InputFileName;
				}
				
				openFileDialog->ShowDialog();
			
				this->CheckItem();
		//	#endif
		 }


private: System::Void �M����ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			readingFile = true;

//			#ifdef _DEBUG
/*
		 		MessageBox::Show("Debug");
				bool filenew = false;
				FileKind = 2;
				String^ path = "D:/DebugData/CLT_1.txt";
				System::IO::StreamReader ^ sr = gcnew
				System::IO::StreamReader(path);
			
				mg = OpenCLT_Characteristic_File(sr,inputdata,surfacecontrollPt,localsurfacecontrollPt,filenew);	

				ShowData();
				CheckInputError();	
				Viewoperation(3) ;
*/
//			#else
			//�}�ұM���ɮ�
				FileKind =7;
				openFileDialog->FileName = "CLT_1";
				openFileDialog->Filter = "�M���ɮ� (*.txt)|*.txt";
				openFileDialog->FilterIndex = 1;
				openFileDialog->RestoreDirectory = true;
				openFileDialog->DefaultExt=".txt";
				
				if(InputFileName == nullptr){
					openFileDialog->InitialDirectory = Directory::GetCurrentDirectory();	
				}
				else{
					openFileDialog->InitialDirectory = InputFileName;
				}
				openFileDialog->ShowDialog();

				//�����ɮצW��
				InputFileName = openFileDialog->FileName;

            //	ShowData();
			
			//	Viewoperation(3) ;


//			#endif
			

			
		



			readingFile = false;
		 }



//--------------------------------------------------------------------------------------------------------------------
//�e��\��]�w--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//�h�����--------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------


private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		
	
			 
		this->btn_ProducePattern->Enabled = false;

		bool success = false;
		//Point Resolution(2*this->GirdNumber.X+1,2*this->GirdNumber.Y+1); //Surface�n + 1
		Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface�n + 1
		this->Surface_Global_Design->SurfaceResolution::set(Resolution);	
	
		if( (this->Surface_Global_Design->IsInputDataChanged == true ||this->Surface_Global_Design->IsSurfaceEmpty == true)){

			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͦ���";
			this->statusStrip1->Update();
			if(this->�����վ㧡��ToolStripMenuItem->Checked == true) {
			//	success = this->ProduceGridDensity();
				this->SurfacePatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);	
				this->toolStripStatusLabel1->Text = "�p��K��";
				this->Surface_Global_Design->ProduceGridDensity(this->SurfacePatternDensity);

			}else if(this->���u�վ㧡��ToolStripMenuItem->Checked == true){
			//	success = this->ProduceGridDensity_ByTwoCurve();
			}else{
				MessageBox::Show("�п�ܧ��׽վ�覡");
				this->toolStripStatusLabel1->Text = "���A";
				this->statusStrip1->Update();
				return;
			}


			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͺ��I";
			this->statusStrip1->Update();

			//if(this->MainData->RandomDot == true){		
			if(this->MainData->DotType == 1){	
				this->Produce_RandomPattern();
			}else{
				Produce_RegularPattern(this->Dot,this->GirdNumber,this->MainData->LGPInformation,this->MainData->Pattern_Arrangment,this->SurfacePatternDensity); 
			}

		}

		this->toolStripProgressBar1->Value = 0;
		this->toolStripStatusLabel1->Text = "�����ק�";
		this->statusStrip1->Update();

		
		ModifyDotRate(this->localsurfacedata,this->Dot);

		//HotSpot �ק�
		if(this->HotSpotData != nullptr && this->HotSpotData->Count > 0){
			this->ProduceHotSpotDensity(this->Dot,this->HotSpotData);
		}

		//�Ѻ��I�Y���ҩM���I�K�׺�X�̲ת����I�K�� .
		
		this->PatternDensity = this->CalRegularPatternDensity(this->Dot ,this->GirdNumber,this->MainData->LGPInformation,0);			 



		/*

			//�إ� ScreenMura ����
			Point tmpGrid;

			tmpGrid.X = this->GirdNumber.X*2;
			tmpGrid.Y = this->GirdNumber.Y*2;

			this->ScreenMuraData = gcnew GridDensity(tmpGrid,this->MainData->LGPInformation);
			for(int ii = 0 ; ii <tmpGrid.X ;ii++){
				for(int jj = 0 ; jj <tmpGrid.Y ;jj++){
					this->ScreenMuraData->SetDensityValue(0.0f,Point(ii,jj));
				}
			}
		
		*/
		






		if(this->Surface_Global_Design->IsSurfaceEmpty == false) {

			this->toolStripStatusLabel1->Text = "���͹ϧ�";
			
			this->toolStripProgressBar1->Value = 0;
			this->statusStrip1->Update();

			this->DrawDesignGridDensity(this->PatternDensity);
		}

		this->toolStripProgressBar1->Value = 100;
		this->toolStripStatusLabel1->Text = "�B�⧹��";
		this->statusStrip1->Update();

			
		this->UpdateMessage();
		this->CheckItem();
		
		this->btn_ProducePattern->Enabled = true;


			
		 }

private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			
			 this->btn_ProducePattern->Enabled = true;

		 }


private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {



			 if ( this->Density_Bitmap != nullptr) {
				this->DrawPic(e->Graphics,Point(this->ObjectCoordinate[0].X,this->ObjectCoordinate[0].Y),this->PicSacleVaule,Point(this->ObjectCoordinate[1].X,this->pictureBox1->Height-this->ObjectCoordinate[1].Y));
				if ( this->localsurfacedata != nullptr)  this->DrawLocalSurfaceData(e->Graphics,this->localsurfacedata); //�n��bDrawPic�᭱
				if(this->HotSpotData != nullptr) this->DrawHotSpotData(e->Graphics,this->HotSpotData); //�n��bDrawPic�᭱
			 }else{
				 e->Graphics->Clear(Color::Black);
			 }
			 






		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//		About^ dlgabout;
	//		dlgabout = gcnew About;			
	//		dlgabout->ShowDialog();
	//		delete[] dlgabout;
		 }


private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

				 if(this->radioBtnRandom->Checked == true){
					 //IBM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = true;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;					 
					 this->tabControll->SelectedIndex = 1;					
					  this->MainData->DotType = 1;

				 }else if(this->radioBtnRegular->Checked == true){
					 //�W�h�G�I
					 this->tab_Regular->Enabled = true;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 0;
					
					   this->MainData->DotType = 0;

				 }else if(this->radioIJPBtn->Checked == true){
					//IJP�G�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = true;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 2;
					  this->MainData->DotType = 2;

				 }else{ 
					 //FM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = true;
					 this->tabControll->SelectedIndex = 3;
					 this->MainData->DotType = 3;
				 }


		

		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

				 if(this->radioBtnRandom->Checked == true){
					 //IBM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = true;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;					 
					 this->tabControll->SelectedIndex = 1;					
					  this->MainData->DotType = 1;

				 }else if(this->radioBtnRegular->Checked == true){
					 //�W�h�G�I
					 this->tab_Regular->Enabled = true;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 0;
					
					   this->MainData->DotType = 0;

				 }else if(this->radioIJPBtn->Checked == true){
					//IJP�G�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = true;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 2;
					  this->MainData->DotType = 2;

				 }else{ 
					 //FM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = true;
					 this->tabControll->SelectedIndex = 3;
					 this->MainData->DotType = 3;
				 }
		 }


private: System::Void radioButton1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {

				 if(this->radioBtnRandom->Checked == true){
					 //IBM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = true;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;					 
					 this->tabControll->SelectedIndex = 1;					
					  this->MainData->DotType = 1;

				 }else if(this->radioBtnRegular->Checked == true){
					 //�W�h�G�I
					 this->tab_Regular->Enabled = true;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 0;
					
					   this->MainData->DotType = 0;

				 }else if(this->radioIJPBtn->Checked == true){
					//IJP�G�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = true;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 2;
					  this->MainData->DotType = 2;

				 }else{ 
					 //FM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = true;
					 this->tabControll->SelectedIndex = 3;
					 this->MainData->DotType = 3;
				 }





		 }
private: System::Void �]�wToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 // 20090304 �]�w�����
			 //Setting Form
			 Set_Data_Form = gcnew SettingForm(this->Set_Data);
			
			 //Set_Data_Form->Show();
			 Set_Data_Form->ShowDialog();
			 
			



				

		 }



private: System::Void ���u�վ㧡��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
// 20090304 ---�Q�Φ��u�վ���駡��

//*
			SmoothDensityEditForm^ smoothset;
			PointF tmpLGP(this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);
			smoothset = gcnew SmoothDensityEditForm(this->Curve_Horizontal,this->Curve_Vertical,this->MainData->LGPInformation);
		//	smoothset = gcnew SmoothDensityEditForm(this->Curve_Horizontal,this->Curve_Vertical,tmpLGP);
		//	smoothset = gcnew SmoothDensityEditForm(this->Curve_Horizontal,this->Curve_Vertical,this->MainData->LGPDimension);
						
			this->���u�վ㧡��ToolStripMenuItem->Checked = true;
			this->�����վ㧡��ToolStripMenuItem->Checked = false;
			this->MainData->DensityDesignMethod = 0;

			
			smoothset->ShowDialog();
	


		 }
private: System::Void �����վ㧡��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

        //20090304 ---�Q�Φ����վ㧡��

			SurfaceDesign^ Surface1;
			//this->Surface_Global_Design = gcnew B_Spline_Surface();
			
		//	Surface1 = gcnew SurfaceDesign(inputdata.PlateWidth,inputdata.PlateHeight);
		//	Surface1 = gcnew SurfaceDesign(this->MainData->LGPDimension.X,this->MainData->LGPDimension.Y);
			Surface1 = gcnew SurfaceDesign(this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);
			
			Surface1->Uni_Surface = this->Surface_Global_Design;
			

			//Surface1->Show();
			Surface1->ShowDialog();	

			this->���u�վ㧡��ToolStripMenuItem->Checked = false;
			this->�����վ㧡��ToolStripMenuItem->Checked = true;
			this->MainData->DensityDesignMethod = 1;


			this->CheckItem();
			
			 
		 }

private: System::Void �}�ұM����0901112ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



			
			 if(this->InputFileName == nullptr || this->InputFileName == "" ){
				 
				 //��ܩ|�����J�M�� , �����n�M�Ÿ̭�����T
				// this->ResetAll();
				// this->CheckItem();
			
			 }else{

				System::Windows::Forms::DialogResult result;
				result= MessageBox::Show("�{�����w���M�װѼ�,�O�_���J ?" ,"ĵ�i",MessageBoxButtons::YesNo);
				if( result == ::DialogResult::No){
					return;
				}else{
					this->ResetAll();
					
				}
	
			 }


	 		//�}�ұM���ɮ�
			FileKind =8;
			openFileDialog->FileName = "CLT_v3.0";
			openFileDialog->Filter = "�M���� V3.0 (*.clt2)|*.clt2|�M���� V2.0 (*.clt)|*.clt|�M����CLT_090112 (*.txt)|*.txt|�M����OldVersion (*.txt)|*.txt";
			openFileDialog->FilterIndex = 1;
			openFileDialog->RestoreDirectory = true;
			openFileDialog->DefaultExt=".c20";
			
		//	if(InputFileName == nullptr){
		//		openFileDialog->InitialDirectory = Directory::GetCurrentDirectory();	
		//	}
		//	else{
		//		openFileDialog->InitialDirectory = InputFileName;
		//	}

			if(this->CurrentDictionary == "")	this->CurrentDictionary = Directory::GetCurrentDirectory();	
			openFileDialog->InitialDirectory = this->CurrentDictionary;
			

			openFileDialog->ShowDialog();


			//ShowData();
			this->UpdateMainFormData();
			this->CheckItem();
		



			 
			


		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


			 //  20090304 ---�W�h���I���M�Ϋ��s
			 try{
				
			
				 this->MainData->LGPInformation = RectangleF(0,0,Convert::ToSingle(this->txt_LGPLength->Text),Convert::ToSingle(this->txt_LGPWidth->Text));
				 this->MainData->MaxDot = Convert::ToSingle(this->txt_maxDot->Text);
				 this->MainData->MinDot = Convert::ToSingle(this->txt_MinDot->Text);
				 this->MainData->MinDotGap = Convert::ToSingle(this->txt_MinDotGap->Text);
				 this->MainData->Pattern_Shape = this->comboBoxPatternShape->SelectedIndex;
				 this->MainData->Pattern_Arrangment = this->cboPatternArragementStyle->SelectedIndex;
				 if(this->chkPitchSetting->Checked == true){
					 this->MainData->PitchDirection = this->cboPitchDirection->SelectedIndex; 
					 this->MainData->ActualPitchValue = Convert::ToSingle(this->txt_DesirePitch->Text);
				 }
				 else{
					 this->MainData->ActualPitchValue = 0;
					 this->MainData->PitchDirection = -1;
				 }

			 }catch(...){
				 MessageBox::Show("�Ѽƿ�J���~!");
				 return;

			 }


			 try{

					float RecArea = 0;
					float maxDenArea = 0;
					float minDenArea = 0;
					float actualmaxDenArea= 0;
					float actualminDenArea= 0;
					float actualBlockArea= 0;
					float allowMaxDot = 0;
		
					int total_num = 0;

					

					float minDis = this->MainData->MaxDot + this->MainData->MinDotGap;
					


					switch (this->MainData->Pattern_Arrangment){
						case 0: //�D����						


							if(this->chkPitchSetting->Checked == true){
								if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue);
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue);
									
								}
								else if(this->cboPitchDirection->SelectedIndex == 1){ //Y��V
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue);
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue);
								}
								
								allowMaxDot = this->MainData->ActualPitchValue-  this->MainData->MinDotGap;
								actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue*2;
							

							}else{
								this->GirdNumber.X = (int)Math::Round(this->MainData->LGPInformation.Width/minDis);
								this->GirdNumber.Y = (int)Math::Round(this->MainData->LGPInformation.Height/minDis);
							}


							RecArea =(float) Math::Pow(minDis,2); //�D����
							total_num = this->GirdNumber.X*this->GirdNumber.Y;
							break;
						case 1://45��-����
							//if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //��ΩM�٧�

								

								if(this->chkPitchSetting->Checked == true){

									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue);
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue);
									allowMaxDot = (1.414*this->MainData->ActualPitchValue-  2*this->MainData->MinDotGap)/2;
									actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue;

								}else{
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/minDis/1.414);							
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/minDis/1.414);  //45D	

								}



								RecArea = 2*(float)Math::Pow(minDis,2)/2; //45D
								total_num = this->GirdNumber.X*this->GirdNumber.Y + (this->GirdNumber.X-1)*(this->GirdNumber.Y-1);

							//}
							/*
							else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // �x��
								MessageBox::Show("�ثe�x�εL45�׿���,�N�ΫD���ƨ��N");							
								this->GirdNumber.X = (int)Math::Round(this->MainData->LGPInformation.Width/minDis);							
								this->GirdNumber.Y = (int)Math::Round(this->MainData->LGPInformation.Height/minDis);
								RecArea = (float)Math::Pow(minDis,2); //�D����
								total_num = this->GirdNumber.X*this->GirdNumber.Y;

							}
							*/
							break;
						case 2://60��-����
							//if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //��ΩM�٧�							

							if(this->chkPitchSetting->Checked == true){
								if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue);
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue/Math::Sqrt(3));
									allowMaxDot = this->MainData->ActualPitchValue- this->MainData->MinDotGap;
									actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue*1.732;
								}
								else if(this->cboPitchDirection->SelectedIndex == 1){ //Y��V
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue);
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue*Math::Sqrt(3));
									allowMaxDot = this->MainData->ActualPitchValue/Math::Sqrt(3)- this->MainData->MinDotGap;
									actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue/1.732;
								}
								

							}else{

								this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/minDis);												
								this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/minDis/1.732);  //60D

							}
								RecArea = 1.732f*(float)Math::Pow(minDis,2)/2.0f; //60D
								total_num = this->GirdNumber.X*this->GirdNumber.Y + (this->GirdNumber.X-1)*(this->GirdNumber.Y-1);
							//}
							/*
							else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // �x��
								MessageBox::Show("�ثe�x�εL60�׿���,�N�ΫD���ƨ��N");							
								this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/minDis);							
								this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/minDis);
								RecArea = (float)Math::Pow(minDis,2); //�D����
								total_num = this->GirdNumber.X*this->GirdNumber.Y;
							}
							*/
							break;
					
						 case 3://30��-����
						
							if(this->chkPitchSetting->Checked == true){
								if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue);
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue*Math::Sqrt(3));
									allowMaxDot = this->MainData->ActualPitchValue/Math::Sqrt(3)- this->MainData->MinDotGap;
									actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue/1.732;
								}
								else if(this->cboPitchDirection->SelectedIndex == 1){ //Y��V
									this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/this->MainData->ActualPitchValue);
									this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/this->MainData->ActualPitchValue/Math::Sqrt(3));
									allowMaxDot = this->MainData->ActualPitchValue- this->MainData->MinDotGap;
									actualBlockArea = this->MainData->ActualPitchValue*this->MainData->ActualPitchValue*1.732;
								}
							

							}else{

								this->GirdNumber.X =(int) Math::Round(this->MainData->LGPInformation.Width/minDis/1.732);												
								this->GirdNumber.Y =(int) Math::Round(this->MainData->LGPInformation.Height/minDis);  //30D

							}



							RecArea = 1.732f*(float)Math::Pow(minDis,2)/2.0f; //60D
							total_num = this->GirdNumber.X*this->GirdNumber.Y + (this->GirdNumber.X-1)*(this->GirdNumber.Y-1);


							break;

					}

				


					if(Form1::comboBoxPatternShape->SelectedIndex == 0){   //���
						maxDenArea =(float) Math::PI*(float)Math::Pow(Convert::ToSingle(this->txt_maxDot->Text),2)/4;
						minDenArea =(float) Math::PI*(float)Math::Pow(Convert::ToSingle(this->txt_MinDot->Text),2)/4;
						actualmaxDenArea =	(float) Math::PI*(float)Math::Pow(allowMaxDot,2)/4*2;
						actualminDenArea = minDenArea*2;
					}
					else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // �x��
						maxDenArea =(float) Math::Pow(Convert::ToSingle(this->txt_maxDot->Text),2);
						minDenArea =(float) Math::Pow(Convert::ToSingle(this->txt_MinDot->Text),2);
						actualmaxDenArea =	(float) Math::PI*(float)Math::Pow(allowMaxDot,2);
						actualminDenArea = minDenArea;
		
					}else if(Form1::comboBoxPatternShape->SelectedIndex == 2){ //�٫�

					}
					
					
					
						
		
					lbl_DotPitch->Text = String::Format("���I Pitch (X,Y) = "+" 	"+"{0:#0.000}"+" , "+"{1:#0.000}",this->MainData->LGPInformation.Width/this->GirdNumber.X,this->MainData->LGPInformation.Height/this->GirdNumber.Y);	

				//	lbl_AllowMaxDen->Text =String::Format("���\�̤j�K��  = " + "{0:#0.00}"+" % ",maxDenArea/RecArea*100);
					maxDen = maxDenArea/RecArea*100;
				//	lbl_AllowMinDen->Text = String::Format("���\�̤p�K��  = " + "{0:#0.00}"+" % ",minDenArea/RecArea*100);
					if(this->chkPitchSetting->Checked == true && actualminDenArea <= actualmaxDenArea  ) 
						this->lblActualDensityRange->Text = String::Format("���\�K�׽d��  = " + "{0:#0.00}"+" % ~ " + "{1:#0.00}" + " %",actualminDenArea/actualBlockArea*100,actualmaxDenArea/actualBlockArea*100);
					else if(this->chkPitchSetting->Checked == true && actualminDenArea > actualmaxDenArea  ) 
						this->lblActualDensityRange->Text = String::Format("���\�K�׽d��  = None");
             		else this->lblActualDensityRange->Text = String::Format("���\�K�׽d��  = " + "{0:#0.00}"+" % ~ " + "{1:#0.00}" + " %",minDenArea/RecArea*100,maxDenArea/RecArea*100);

					this->lbl_Total_Num->Text =  String::Format("�`���I�ƥ�  = " + "{0:#0}",total_num);					
					this->CheckItem();

					//�NResolution �ǤJ��Surface�� 
					Point tmpRes(this->GirdNumber.X+1 ,this->GirdNumber.Y + 1);
					this->Surface_Global_Design->SurfaceResolution::set(tmpRes);


					if(this->chkPitchSetting->Checked == true){

						switch (this->cboPatternArragementStyle->SelectedIndex){
						 
							case 0: //�x�αƦC
								MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
								MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
								 break;
							 case 1://45�ױƦC	
								MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))/Math::Sqrt(2)*2;
								MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))/Math::Sqrt(2)*2;					
								 break;
							 case 2://60�ױƦC
								if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
									MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
									MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);				
								 }else{
									MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);
									MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);				
								 }
								
								 break;
							 case 3:
								 if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
									MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);
									MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);				
									 
								 }else{
									MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
									MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);					
								 }
								
								 break;
						}

						this->lblAllowPitchRange->Text = String::Format("���\Pitch�d�� = " + "{0:0.0000}" + "~" + "{1:0.0000}",MinPitch,MaxPitch);

						if(Convert::ToSingle(this->txt_DesirePitch->Text) > MaxPitch || Convert::ToSingle(this->txt_DesirePitch->Text) < MinPitch ) {
							this->lblMessage->Visible = true;
							this->lblMessage->Text = "ĵ�i!!Pitch �W�X���\�d��";
						} else this->lblMessage->Visible = false;

					}

				//�ϧΤƪ���l�]�w

				this->PicSacleVaule = Math::Min(this->pictureBox1->Width/this->MainData->LGPInformation.Width*0.8f,this->pictureBox1->Height/this->MainData->LGPInformation.Height*0.8f);
				//��l�Ƽƭ�

				ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
				ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
				ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
				ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;



				
				
			 }catch(...){
				 MessageBox::Show("�p����~!");
				 this->btn_ProducePattern->Enabled = false;
			 }




				
					
}
		 





private: System::Void EditToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
		//	 if(inputdata.PlateHeight <= 0 || inputdata.PlateWidth <= 0)
		//		 this->���׽վ�\��ToolStripMenuItem->Enabled = false;
		//	 else
		//		  this->���׽վ�\��ToolStripMenuItem->Enabled = true;
		 }
private: System::Void �˵�ToolStripMenuItem_DropDownOpened(System::Object^  sender, System::EventArgs^  e) {

		/*
			 if(this->Metafile_DesignGridDensity != nullptr){
				 ShowDesignDensityToolStripMenuItem->Enabled = true ;
			 }else {
				 ShowDesignDensityToolStripMenuItem->Enabled = false ;
			 }

			 if(Metafile_CurrentPattern != nullptr){
				 ShowCurrentPatternToolStripMenuItem->Enabled = true;
			 }else{
				 ShowCurrentPatternToolStripMenuItem->Enabled = false;
			 }

		 */

			 
		 }

private: System::Void comboBoxRegularStyle_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->MainData->Pattern_Arrangment = this->cboPatternArragementStyle->SelectedIndex;
		 }

private: System::Void comboBoxPatternShape_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
			 if(this->comboBoxPatternShape->SelectedIndex == 1){ //Pattern ���x��
				 this->cboPatternArragementStyle->SelectedIndex = 0 ;  //�D����
				 this->cboPatternArragementStyle->Enabled = false;
			 }else{
				 this->cboPatternArragementStyle->Enabled = true;
			 }
			  this->MainData->Pattern_Shape = this->comboBoxPatternShape->SelectedIndex;
		 }
private: System::Void cbo_RandomDotSimRule_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->MainData->RandomDotSimRule = this->cbo_RandomDotSimRule->SelectedIndex;
		 }

private: System::Void �G�u�ק�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	//		 Solution_Cosmetic_Line_Form^ Cosmetic_Line;
	//		 Cosmetic_Line = gcnew Solution_Cosmetic_Line_Form(this->Dot,this->MainData,this->GirdNumber,this->Cosmetic_LocalAreaData);
	//		 Cosmetic_Line->ShowDialog();
	//		 this->CheckItem();


		 }
private: System::Void btn_modifyDot_Click(System::Object^  sender, System::EventArgs^  e) {

/*
				int a  ;
				int b  ;
			 this->btn_modifyDot->Enabled = false;
			 array<float,2>^ ratio = gcnew array<float,2>(this->GirdNumber.X,this->GirdNumber.Y);
		
			 PointF GridSize(this->MainData->LGPInformation.Width/this->GirdNumber.X,this->MainData->LGPInformation.Height/this->GirdNumber.Y);
			
			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("���I�|����̤pGap�� : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
			}
				 

			 for(int ii = 0 ;ii <this->Dot->GetDotNumber();ii++){
				 float ModifyRate_HotSpot = 1.0f;
				 if(this->Dot->ModifyRate_HotSpot->Length >0){
					ModifyRate_HotSpot = (float)this->Dot->ModifyRate_HotSpot->GetValue(ii);
					}
	
				 float ModifyRate_LocalArea = 1.0f;
				 if(this->Dot->ModifyRate_LocalArea->Length >0){
					ModifyRate_LocalArea = (float)this->Dot->ModifyRate_LocalArea->GetValue(ii);
				 }

				
				float newDia = ModifyRate_HotSpot*ModifyRate_LocalArea*(float)this->Dot->Origional_Dot_Diameter->GetValue(ii);

				if(this->Set_Data->LimitDotSize == true){
					if(newDia >=this->MainData->MaxDot) newDia = this->MainData->MaxDot;
				}
				this->Dot->Dot_Diameter->SetValue(newDia,ii);

				if(this->GirdNumber.X != 0 && this->GirdNumber.Y != 0){
					if(this->MainData->RandomDot == false){
					//�p���ܰʫ᪺�K��(�A�Φb���O��DXF Ū�X���I�����p) ---------------------------------------------					
					float Den = 0;
					for(int jj = 0 ;jj< 4 ; jj++){
						Point tmpDenIndex(0,0);
						tmpDenIndex = (Point)this->Dot->DotDensity_Index->GetValue(jj,ii);
						float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  + 3.1415926*newDia*newDia/16.0f/GridSize.X/GridSize.Y;
						ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);						
					}

					//-----------------------------------------------------------
					}else {
						PointF coodrinate;
						float dia;
						this->Dot->GetDotValue(coodrinate,dia,ii);
						
						a =Math::Round(coodrinate.X/this->MainData->LGPInformation.Width*this->GirdNumber.X);						
						b =Math::Round(coodrinate.Y/this->MainData->LGPInformation.Height*this->GirdNumber.Y);
						if(a>=0 && a < this->GirdNumber.X && b>=0 && b < this->GirdNumber.Y){
							Point tmpDenIndex(a,b);						
							float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  + Math::PI*dia*dia/4/GridSize.X/GridSize.Y;
							ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);
						}

					}
				}

			 }






	
					











			 if(this->GirdNumber.X != 0 && this->GirdNumber.Y != 0){

				 for(int ii= 0 ;ii < this->GirdNumber.X ; ii++){
					  for(int jj= 0 ;jj < this->GirdNumber.Y ; jj++){
						 float tmpDen =  (float)ratio->GetValue(ii,jj);
						 if(this->Set_Data->LimitDotSize == true){
							if(tmpDen >=this->maxDen/100) tmpDen = this->maxDen/100;
						 }
						 //this->Density->SetDensity(tmpDen,ii,jj); 20091226�H�e
						 Point index(ii,jj);
						// this->Density->SetDensityValue(tmpDen,index);
						 this->PatternDensity->SetDensityValue(tmpDen,index);
					  }
				 }

			
				 this->DrawDesignGridDensity(this->PatternDensity);
			 }else{
				 MessageBox::Show("�qDxf�ɮ�Ū�������I����ܱK�� !!");
			 }


			this->UpdateMessage();
			this->CheckItem();
			this->btnResetModifyRate->Enabled = true;

	*/		
			 
			 
		 }
private: System::Void �����ק�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 PointF LGP(this->MainData->LGPDimension.X,this->MainData->LGPDimension.Y);
		//	 PointF LGP(this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);
			 
		//	 Cosmetic_LocalArea_Form^ cosmeticLocalArea;
			// cosmeticLocalArea = gcnew Cosmetic_LocalArea_Form(this->GirdNumber,this->Density,this->Dot,this->Cosmetic_LocalAreaData,this->MainData->LGPInformation,this->btn_modifyDot);




		//	 if(cosmeticLocalArea == nullptr) {
	 	//		for(int ii = 0 ; ii <this->Dot->GetDotNumber() ; ii++){
		//			this->Dot->ModifyRate_HotSpot->SetValue(1.0f,ii);
		//			this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
		//		}
			 //--------------------
			 Cosmetic_LocalArea_Form^ cosmeticLocalArea = gcnew Cosmetic_LocalArea_Form(this->GirdNumber,this->SurfacePatternDensity,this->Dot,this->Cosmetic_LocalAreaData,this->MainData->LGPInformation,this->localsurfacedata);

		//	}

			 cosmeticLocalArea->Show();
			 
		
			 
			 

			 this->CheckItem();


		 }
private: System::Void �}������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lEDHotBar�ק�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 HotSpot_Form^ hotSpot = gcnew  HotSpot_Form(this->SurfacePatternDensity,this->Dot,this->HotSpotData,this->MainData->LGPInformation);
			 hotSpot->Show();
			 this->CheckItem();



			
		 }
private: System::Void btnResetModifyRate_Click(System::Object^  sender, System::EventArgs^  e) {

/*
			int a  ;
			int b  ;

			 this->btnResetModifyRate->Enabled = false;


			 	 array<float,2>^ ratio = gcnew array<float,2>(this->GirdNumber.X,this->GirdNumber.Y);
		//	 PointF GridSize(this->MainData->LGPDimension.X/this->GirdNumber.X,this->MainData->LGPDimension.Y/this->GirdNumber.Y);
				 PointF GridSize(this->MainData->LGPInformation.Width/this->GirdNumber.X,this->MainData->LGPInformation.Height/this->GirdNumber.Y);
			

			 Array::Copy(this->Dot->Origional_Dot_Diameter,this->Dot->Dot_Diameter,this->Dot->Origional_Dot_Diameter->Length);
			
				for(int ii = 0 ;ii <this->Dot->GetDotNumber(); ii++){

					if(this->Dot->ModifyRate_HotSpot->Length == this->Dot->GetDotNumber())	this->Dot->ModifyRate_HotSpot->SetValue(1.0f,ii);
				
					if(this->Dot->ModifyRate_LocalArea->Length == this->Dot->GetDotNumber())  this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
					
					float newDia = (float)this->Dot->Origional_Dot_Diameter->GetValue(ii);
						
						//�p���ܰʫ᪺�K�� ---------------------------------------------
						//�W�h�G�I�ɨϥ�

						float Den = 0;
						if(this->MainData->RandomDot == false){
							for(int jj = 0 ;jj< 4 ; jj++){
								Point tmpDenIndex(0,0);
								tmpDenIndex = (Point)this->Dot->DotDensity_Index->GetValue(jj,ii);
								float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  + 3.1415926*newDia*newDia/16.0f/GridSize.X/GridSize.Y;
								ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);
					
					
								
								
							}

						//-----------------------------------------------------------

						//�üƧG�I�θ��J���I�ɨϥ�
						}else {
							PointF coodrinate;
							float dia;
							this->Dot->GetDotValue(coodrinate,dia,ii);
							
							a =Math::Round(coodrinate.X/this->MainData->LGPInformation.Width*this->GirdNumber.X);						
							b =Math::Round(coodrinate.Y/this->MainData->LGPInformation.Height*this->GirdNumber.Y);
							if(a>=0 && a < this->GirdNumber.X && b>=0 && b < this->GirdNumber.Y){
								Point tmpDenIndex(a,b);						
								float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  + Math::PI*dia*dia/4/GridSize.X/GridSize.Y;
								ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);
							}
						}

					










						//---------------------------------------------------------------





				}


				for(int ii= 0 ;ii < this->GirdNumber.X ; ii++){
					  for(int jj= 0 ;jj < this->GirdNumber.Y ; jj++){
						 float tmpDen =  (float)ratio->GetValue(ii,jj);
						 //this->Density->SetDensity(tmpDen,ii,jj);  //20091226 �H�e
						  Point index(ii,jj);
						// this->Density->SetDensityValue(tmpDen,index);
						 this->PatternDensity->SetDensityValue(tmpDen,index);


					  }
				 }

				
				this->DrawDesignGridDensity(this->PatternDensity);
				this->UpdateMessage();
	*/		
		 }
private: System::Void ���׽վ�\��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	

		 }
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btn_Accept_Click(System::Object^  sender, System::EventArgs^  e) {

			 try{
			//	 this->MainData->LGPDimension = PointF(Convert::ToSingle(this->txt_LGPLength->Text),Convert::ToSingle(this->txt_LGPWidth->Text));
				 this->MainData->LGPInformation = RectangleF(0,0,Convert::ToSingle(this->txt_LGPLength->Text),Convert::ToSingle(this->txt_LGPWidth->Text));

				 this->MainData->RandomDotIteration = Convert::ToInt16(this->txt_RandomDotIteration->Text);
				 this->MainData->RandomDotSize = Convert::ToSingle(this->txt_RandomDotSize->Text);
				 this->MainData->RandomDotGap = Convert::ToSingle(this->txt_RandomDotGap->Text);
				 this->MainData->Parameter_K = Convert::ToSingle(this->txt_RandomParaK->Text);
				 this->MainData->Parameter_C = Convert::ToSingle(this->txt_RandomParaC->Text);
				 this->MainData->RandomDotSimRule = cbo_RandomDotSimRule->SelectedIndex;
				 //�s�W�Ѽ� (File �����OV04�~��)
				 this->MainData->RandomRebuildFrequency = Convert::ToInt16(this->txt_RandomRebuildFrequency->Text);
				 this->MainData->RandomStopForce = Convert::ToSingle(this->txt_RandomCuttingForce->Text);
				 this->MainData->chkStopForce = this->chkRamdomStopForce->Checked;
				 this->MainData->chkStopNmber = this->chkRandomStopNumber->Checked;

			 }catch(...){

				 MessageBox::Show("��J���~ !!");
			 }

			 //���ƭȬO�ھڨC�Ӻ���i�H��J16�Ӻ��I���� ,���g���
			 this->GirdNumber.X = (int )Math::Round(this->MainData->LGPInformation.Width/this->MainData->RandomDotSize/4);
			 this->GirdNumber.Y = (int )Math::Round(this->MainData->LGPInformation.Height/this->MainData->RandomDotSize/4);

			
			 this->lbl_RandomGirdNumber->Text = String::Format("{0:#0.00##}"+"	"+"{1:#0}"+" X " + "{2:#0} ","�����  :",this->GirdNumber.X,this->GirdNumber.Y);
			 float ratio = (float)Math::Pow(this->MainData->RandomDotSize/2,2)/(float)Math::Pow((this->MainData->RandomDotGap/2+this->MainData->RandomDotSize/2),2);
			 this->lbl_AllowanceRandomDensity->Text = String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}" ,"���\�̤j�K�� :",0.8*ratio);  //�z�׭ȬO0.9 (�̱K��n ) ,���L��ڪ��p�U ,�����F��o�˪��ƦC�覡 ,�G�]�p�g��� 0.8
			 
			 

			this->CheckItem();
			this->btn_ProducePattern->Enabled = true;
	

		 }
private: System::Void lbl_TotalNum_Random_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ���I�K�פ��RToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 	PatternGrab_Form^ patternGrab ;
						
				patternGrab = gcnew PatternGrab_Form(this->Dot,this->MainData->LGPInformation ,this->PatternDensity);
				patternGrab->ShowDialog();

				this->CheckItem();
				//this->UpdateMessage();
				 
		 }




private: System::Void �Ӥ���Ƨ��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 	PicAnalysis^ pictureGrab ;
				pictureGrab = gcnew PicAnalysis();
				pictureGrab->ShowDialog();



		 }
private: System::Void tttToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->�����ק�ToolStripMenuItem->Enabled = true;
		 }

private: System::Void �������RToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



			//�إ� ScreenMura ����
			Point tmpGrid;

			tmpGrid.X = this->GirdNumber.X*2;
			tmpGrid.Y = this->GirdNumber.Y*2;

			this->ScreenMuraData = gcnew GridDensity(tmpGrid,this->MainData->LGPInformation);
			for(int ii = 0 ; ii <tmpGrid.X ;ii++){
				for(int jj = 0 ; jj <tmpGrid.Y ;jj++){
					this->ScreenMuraData->SetDensityValue(0.0f,Point(ii,jj));
				}
			}





			ScreenMura^ muraAnalysis;
		
			muraAnalysis = gcnew ScreenMura( this->Dot ,this->ScreenMuraData ,this->MainData->LGPInformation ,this->GirdNumber ,this->MainData->Pattern_Arrangment );
				
			muraAnalysis->ShowDialog();
			 
			 
			this->CheckItem();
			 
			 



		 }
private: System::Void btnDotDisturbe_Click(System::Object^  sender, System::EventArgs^  e) {


			 if (this->ScreenMuraData != nullptr) {
				 //���C�ѪR��

				 Point test= this->ScreenMuraData->GetMeshNumber();
				 test.X = test.X/2;
				 test.Y = test.Y/2;

				 GridDensity^ tmpGrid = gcnew GridDensity(test,this->MainData->LGPInformation);

					float avgValue = 0;
					int count = 0;
		
					for(int ii = 0 ; ii <test.X ;ii++){
						for(int jj = 0 ; jj <test.Y ;jj++){

							float value = 0;

							value = (this->ScreenMuraData->GetDensityValue(Point(2*ii,2*jj)) +this->ScreenMuraData->GetDensityValue(Point(2*ii+1,2*jj)) + this->ScreenMuraData->GetDensityValue(Point(2*ii+1,2*jj+1)) + this->ScreenMuraData->GetDensityValue(Point(2*ii,2*jj+1)))/4;

							if(value != 0){
								avgValue = avgValue + value;
								count++;
							}

							tmpGrid->SetDensityValue(value,Point(ii,jj));
						}
					}

					avgValue = avgValue/count;


				//���s�t���C��
					//*
					for(int ii = 0 ; ii <test.X ;ii++){
						for(int jj = 0 ; jj <test.Y ;jj++){
							float temp = tmpGrid->GetDensityValue(Point(ii,jj));
							temp = 5*(temp-avgValue) + 0.1f;
							
							
							tmpGrid->SetDensityValue(temp,Point(ii,jj));

						}
					}
					//*/




				 if (this->Dot->MuraValue != nullptr) {			
					//this->DrawDesignGridDensity(this->ScreenMuraData);	
					 this->DrawDesignGridDensity(tmpGrid);
				 }

			 }
			


		 }
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {

		   project = gcnew Project_Information();
		   project->Designer = Environment::UserName;
		   project->DesignDate = Convert::ToString(System::DateTime::Now::get());
		   ProjectInformation^ InformationForm = gcnew ProjectInformation(project);
		   InformationForm->ShowDialog();

		 }
private: System::Void �M�׸�TToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			ProjectInformation^ InformationForm = gcnew ProjectInformation(project);
			InformationForm->ShowDialog();
		 }
private: System::Void ��ƮwToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			DataBaseForm^ DataBase = gcnew DataBaseForm();
			
			DataBase->ShowDialog();
		 }
private: System::Void ���׹w��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 /*
			 OpticalProfile^ Form = gcnew OpticalProfile();
			 Form->ShowDialog();
			 */
		 }

private: System::Void chkPitchSetting_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->chkPitchSetting->Checked == true){
				this->groupBox5->Enabled = true;
			 }else{
				this->groupBox5->Enabled = false;
			 }
		 }

private: System::Void txt_DesirePitch_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 



			 	switch (this->cboPatternArragementStyle->SelectedIndex){
					 
					case 0: //�x�αƦC
						MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
						MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
						 break;
					 case 1://45�ױƦC	
						MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))/Math::Sqrt(2)*2;
						MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))/Math::Sqrt(2)*2;					
						 break;
					 case 2://60�ױƦC
						if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
							MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
							MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);				
						 }else{
							MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);
							MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);				
						 }
						
						 break;
					 case 3:
						 if(this->cboPitchDirection->SelectedIndex == 0){ //X��V
							MaxPitch = (Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);
							MinPitch = (Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text))*Math::Sqrt(3);				
							 
						 }else{
							MaxPitch = Convert::ToSingle(this->txt_maxDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);
							MinPitch = Convert::ToSingle(this->txt_MinDot->Text) + Convert::ToSingle(this->txt_MinDotGap->Text);					
						 }
						
						 break;
				 }

				this->lblAllowPitchRange->Text = String::Format("���\Pitch�d�� = " + "{0:0.0000}" + "~" + "{1:0.0000}",MinPitch,MaxPitch);

				

			



		 }
private: System::Void txt_DesirePitch_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txt_maxDot_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btn_IJP_Click(System::Object^  sender, System::EventArgs^  e) {

			 //��ƿ�J
			 try{
				this->MainData->LGPInformation = RectangleF(0,0,Convert::ToSingle(this->txt_LGPLength->Text),Convert::ToSingle(this->txt_LGPWidth->Text));
				this->MainData->IJP_BlockX = Convert::ToInt16(this->IJP_txt_BlockX->Text);
				this->MainData->IJP_BlockY = Convert::ToInt16(this->IJP_txt_BlockY->Text);
				this->MainData->IJP_DotSize =  Convert::ToSingle(this->IJP_txt_DotSize->Text);
				this->MainData->DotType = 2;
				this->MainData->IJP_chkTextEdit = this->IJP_chk_TextEdit->Checked;
				this->MainData->IJP_TextLocation = this->IJP_cbo_TextLocation->SelectedIndex;
				this->MainData->IJP_TextLocation_X = Convert::ToSingle(this->IJP_txt_TextLocaX->Text);
				this->MainData->IJP_TextLocation_Y = Convert::ToSingle(this->IJP_txt_TextLocaY->Text);
				this->MainData->IJP_TextHeight = Convert::ToSingle(this->IJP_txt_TextHeight->Text);
				this->MainData->IJP_TextLength = Convert::ToSingle(this->IJP_txt_TextLength->Text);
				this->MainData->IJP_Text = this->IJP_txt_TEXT->Text;
				

				//�å��x�s��MainData��
				this->IJP_DPI = Convert::ToSingle(this->cboIJPDPI->Text);


			}catch(...){
				 MessageBox::Show("��J���~");
				 this->btn_ProducePattern->Enabled = false;
				 return;
			
			}

			

			 float max ;
			 float min ;
			 float dia ;

			 

			  
			 dia = this->MainData->IJP_DotSize;

			

			 max = dia*dia*Math::PI/4.0f/63.5/63.5;
			 min = max/this->MainData->IJP_BlockX/this->MainData->IJP_BlockY;
					

			 this->IJP_Grid.X = this->MainData->LGPInformation.Width/(25.4/this->IJP_DPI);
			 this->IJP_Grid.Y = this->MainData->LGPInformation.Height/(25.4/this->IJP_DPI);
			
			 if(this->IJP_Grid.X*(25.4/this->IJP_DPI) > this->MainData->LGPInformation.Width)  this->IJP_Grid.X = this->IJP_Grid.X - 1;
			 if(this->IJP_Grid.Y*(25.4/this->IJP_DPI) > this->MainData->LGPInformation.Height) this->IJP_Grid.Y = this->IJP_Grid.Y - 1;

			 int tmpresult ;
			 int tmpresult1 ;

			 this->GirdNumber.X = Math::DivRem(this->IJP_Grid.X,this->MainData->IJP_BlockX,tmpresult) ;
			 this->GirdNumber.Y = Math::DivRem(this->IJP_Grid.Y,this->MainData->IJP_BlockY,tmpresult1) ;

			 if(tmpresult != 0) this->GirdNumber.X = this->GirdNumber.X + 1;
			 if(tmpresult1 != 0) this->GirdNumber.Y = this->GirdNumber.Y + 1;




			 // IJP ��r�s��-----------------------------------------------------------------------------------------------

		
			 if(this->MainData->IJP_chkTextEdit == true){
		
				 //IJP�Q�L��r 

				 this->IJP_TextRange.Width = this->MainData->IJP_TextLength ;
				 this->IJP_TextRange.Height = this->MainData->IJP_TextHeight ;



				 switch (this->MainData->IJP_TextLocation){
						case 0:   //���U
							this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X ; 
							this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y ; 
							
							break;
						case 1:  // ���W
							if (this->IJPText_Index <=2 ) {  //�������r
								
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y - this->IJP_TextRange.Height;
							
							}else{   //�������r
							
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y - this->IJP_TextRange.Width;

							}
							
							break;
						case 2: //�k�U	
							if (this->IJPText_Index <=2 ) {  //�������r
							
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X - this->IJP_TextRange.Width;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y;
								
							}else{
								
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X - this->IJP_TextRange.Height;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y;
							}
							
							break;
						case 3: //�k�W	
							if(this->IJPText_Index <=2 ) {  //�������r
								
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X -this->IJP_TextRange.Width ;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y -this->IJP_TextRange.Height ;
								
							}else{
								this->IJP_TextRange.X = this->MainData->IJP_TextLocation_X -this->IJP_TextRange.Height ;
								this->IJP_TextRange.Y = this->MainData->IJP_TextLocation_Y -this->IJP_TextRange.Width ;

							}
							
							break;
				
					} 
				
			
				//��r��� 

				IJP_TextBitmap = gcnew Bitmap(this->IJP_TextRange.Width/(25.4/this->IJP_DPI),this->IJP_TextRange.Height/(25.4/this->IJP_DPI));
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial Black",Math::Truncate(this->IJP_TextRange.Height/(25.4/this->IJP_DPI))-2,GraphicsUnit::Pixel );
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );


				//		
				
				//this->IJP_Text = this->IJP_txt_TEXT->Text;
				
				Graphics^ test2 ;	
				test2 = Graphics::FromImage(IJP_TextBitmap);
				test2->Clear(Color::White);
				test2->DrawString(this->MainData->IJP_Text,drawFont,drawBrush,0.0f,0.0f);

				
				

				switch (this->IJPText_Index){
					case 0:   //TW
						IJP_TextBitmap->RotateFlip(RotateFlipType ::RotateNoneFlipNone);
						break;
					case 1:  // LC			
						IJP_TextBitmap->RotateFlip(RotateFlipType ::RotateNoneFlipX);
						break;
					case 2: 			
						IJP_TextBitmap->RotateFlip(RotateFlipType ::RotateNoneFlipY);
						break;
					case 3: 			
						IJP_TextBitmap->RotateFlip(RotateFlipType ::Rotate90FlipNone);
						break;
					case 4: //LMO			
						IJP_TextBitmap->RotateFlip(RotateFlipType ::Rotate90FlipX);
						break;
					case 5: //LMO			
						IJP_TextBitmap->RotateFlip(RotateFlipType ::Rotate90FlipY);
						break;
				} 

			
				

//				Graphics^ testPic = this->IJP_Text_Pic->CreateGraphics();
//				testPic->DrawImage(IJP_TextBitmap,0,0,this->IJP_Text_Pic->Size.Width,this->IJP_Text_Pic->Size.Height);


				//�]���y�����Y (����Y�y�� ,�ҥH���FilpY)
				IJP_TextBitmap->RotateFlip(RotateFlipType ::RotateNoneFlipY);


			}

			//----------------------------------------------------------------------------------------------------------------

			//�NResolution �ǤJ��Surface�� 
			Point tmpRes(this->GirdNumber.X+1 ,this->GirdNumber.Y + 1);
			this->Surface_Global_Design->SurfaceResolution::set(tmpRes);



			//�ϧΤƪ���l�]�w

			this->PicSacleVaule = Math::Min(this->pictureBox1->Width/this->MainData->LGPInformation.Width*0.8f,this->pictureBox1->Height/this->MainData->LGPInformation.Height*0.8f);
			//��l�Ƽƭ�

			ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
			ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
			ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
			ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;



			this->CheckItem();
		





			 
		 }
private: System::Void Save_IJP_File_Click(System::Object^  sender, System::EventArgs^  e) {

			FileKind = 5;
			if(this->project->projectName !="" && this->project->PatternVersion !="")
				saveFileDialog1->FileName = "IJP-" + this->project->projectName + "-" + this->project->PatternVersion;
			else	saveFileDialog1->FileName = "IJP_Pattern";

			saveFileDialog1->Filter = "IJP_Format (*.txt)|*.txt";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".txt";

			if(this->CurrentDictionary == "") saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			else  saveFileDialog1->InitialDirectory = this->CurrentDictionary;

			saveFileDialog1->ShowDialog();
			this->CheckItem();
		 }

private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {



		//------------------------------------------------------------------------------------------------


			 //IJP���� (FM)

		
		//-----------------------------------------------------------------------------------------------------
	    //---�ѱ����I��J�Ѽ� ����Surface��Density 


		this->btn_ProducePattern->Enabled = false;

		bool success = false;
	
		Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface�n + 1
		this->Surface_Global_Design->SurfaceResolution::set(Resolution);	
	
		if( (this->Surface_Global_Design->IsInputDataChanged == true ||this->Surface_Global_Design->IsSurfaceEmpty == true)){

			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͦ���";
			this->statusStrip1->Update();
			if(this->�����վ㧡��ToolStripMenuItem->Checked == true) {
		
				this->SurfacePatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);	
				this->toolStripStatusLabel1->Text = "�p��K��";
				this->Surface_Global_Design->ProduceGridDensity(this->SurfacePatternDensity);

			}else{
				MessageBox::Show("�п�ܧ��׽վ�覡");
				this->toolStripStatusLabel1->Text = "���A";
				this->statusStrip1->Update();
				return;
			}	

		}







		//-------------------------------------------------------------------------------------------------------------------------------------
		//Step1 : �ѷs���K�ײ��͹��������I 
	    


		PointF BlockSize ;
		//BlockSize.X = (float)this->IJP_Grid.X/(float)this->PatternDensity->GetMeshNumber().X ;
		//BlockSize.Y = (float)this->IJP_Grid.Y/(float)this->PatternDensity->GetMeshNumber().Y ;
		BlockSize.X = (float)this->IJP_Grid.X/(float)this->SurfacePatternDensity->GetMeshNumber().X ;
		BlockSize.Y = (float)this->IJP_Grid.Y/(float)this->SurfacePatternDensity->GetMeshNumber().Y ;
		array<float>^ randomData;
		Random^ autoRand = gcnew Random(0);


		long totalNumber = 0;

		bool exceedMaxDen = false;


		
		this->toolStripStatusLabel1->Text = "�t�m�K��";
		this->statusStrip1->Update();

		//�M��IJP �̭������ (V3.2���ץ�)	

		//Array::Clear(this->IJP_DotSize,0,this->IJP_DotSize->LongLength);
			
		if(this->IJP_DotSize != nullptr) delete[] this->IJP_DotSize;

		this->IJP_DotSize = gcnew array<float,2>(this->IJP_Grid.X,this->IJP_Grid.Y);
		array<bool,2>^ IJPDot = gcnew array<bool,2>(this->IJP_Grid.X,this->IJP_Grid.Y);	
		

		

		///�w�q48.69%�ɬO�����Q�L @0.05f ,400DPI �����G
		float maxDen = this->MainData->IJP_DotSize*this->MainData->IJP_DotSize*Math::PI/(25.4f/this->IJP_DPI)/(25.4f/this->IJP_DPI)/4.0f/10000.0f;

		
		for(int ii = 0 ; ii < this->IJP_DotSize->GetLength(0) ; ii ++){
			for(int jj = 0 ; jj < this->IJP_DotSize->GetLength(1) ; jj ++){
				Point grid;
				grid.X = Math::Round(ii*(this->SurfacePatternDensity->GetMeshNumber().X-1)/(this->IJP_DotSize->GetLength(0)-1));
				grid.Y = Math::Round(jj*(this->SurfacePatternDensity->GetMeshNumber().Y-1)/(this->IJP_DotSize->GetLength(1)-1));
				float tmp = this->SurfacePatternDensity->GetDensityValue(grid);

				//�w�q48.69%�ɬO�����Q�L				
				if(tmp > maxDen) tmp = maxDen;
				this->IJP_DotSize->SetValue(tmp/maxDen,ii ,jj);


			}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(ii)/Convert::ToSingle(this->IJP_DotSize->GetLength(0));
			this->statusStrip1->Update();
		}

		//HotSpot �ק�
		this->toolStripProgressBar1->Value = 0;
		this->toolStripStatusLabel1->Text = "�����ק�";
		this->statusStrip1->Update();

		

		if(this->HotSpotData != nullptr && this->HotSpotData->Count > 0){
			this->ProduceHotSpotDensity(this->IJP_DotSize,this->HotSpotData);
		}

		


		if(this->localsurfacedata != nullptr && this->localsurfacedata->Count > 0){
			this->ModifyDotRate(this->localsurfacedata,this->IJP_DotSize);
		}


		this->toolStripProgressBar1->Value = 100;
		this->statusStrip1->Update();

		//�Ѻ��I�Y���ҩM���I�K�׺�X�̲ת����I�K�� .
				
		this->PatternDensity = this->CalFMPatternDensity(this->IJP_DotSize ,this->GirdNumber,this->MainData->LGPInformation,Point(this->MainData->IJP_BlockX,this->MainData->IJP_BlockY),maxDen);


		this->toolStripStatusLabel1->Text = "���ͺ��I";
		this->statusStrip1->Update();

		
		int selectedPT = 0 ;
	



		//��Floyd  Error Diffusing �覡 ,�ﵽ�~�� 
		int a = 0 ;
		float errorden = 0.0f;
		float tmp = 0.0f;
		int mod = 0;
		float den = 0;
		for( int jj = 0 ; jj < this->IJP_DotSize->GetLength(1) ; jj++){
			
			a= Math::DivRem(jj,2,mod);

			if(mod == 0 ){
			//---------------------------------------------------------------------------------------
				for(int ii = 0 ; ii < this->IJP_DotSize->GetLength(0) ; ii++){			
								den = Convert::ToSingle(this->IJP_DotSize->GetValue(ii,jj));
								selectedPT = autoRand->Next(-10,10);	
								//Threshold �� 0.5
								if(den < 0.5+selectedPT/100.0f ) {
									errorden = den;
							

								}else{
								
									IJPDot->SetValue(true,ii,jj);
									//this->IJP_DotSize->SetValue(this->MainData->IJP_DotSize, ii,jj);
									totalNumber ++;
									errorden = den-1.0f;
								}
								//Diffusing ��F�񪺺��I

								if(ii+2 <this->IJP_DotSize->GetLength(0)){
									this->IJP_DotSize[ii+2,jj] = this->IJP_DotSize[ii+2,jj] + 5.0f/48.0f*errorden;
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+2,jj+1] = this->IJP_DotSize[ii+2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+2,jj+2] = this->IJP_DotSize[ii+2,jj+2] + 1.0f/48.0f*errorden;
								}

								if(ii+1 <this->IJP_DotSize->GetLength(0)){
									this->IJP_DotSize[ii+1,jj] = this->IJP_DotSize[ii+1,jj] + 7.0f/48.0f*errorden;
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+1,jj+1] = this->IJP_DotSize[ii+1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+1,jj+2] = this->IJP_DotSize[ii+1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii,jj+1] = this->IJP_DotSize[ii,jj+1] + 7.0f/48.0f*errorden;
								if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii,jj+2] = this->IJP_DotSize[ii,jj+2] + 5.0f/48.0f*errorden;

								if(ii-1 >= 0){
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-1,jj+1] = this->IJP_DotSize[ii-1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-1,jj+2] = this->IJP_DotSize[ii-1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(ii-2 >= 0){
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-2,jj+1] = this->IJP_DotSize[ii-2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-2,jj+2] = this->IJP_DotSize[ii-2,jj+2] + 1.0f/48.0f*errorden;
								}




								/*
								if( ii+1 <this->IJP_DotSize->GetLength(0)) {
									tmp = this->IJP_DotSize[ii+1,jj];
									this->IJP_DotSize->SetValue(tmp + 7.0f/16.0f*errorden ,ii+1,jj);
								}
								if(ii+1 <this->IJP_DotSize->GetLength(0) && jj+1 <this->IJP_DotSize->GetLength(1)) {
									tmp = this->IJP_DotSize[ii+1,jj+1];
									this->IJP_DotSize->SetValue(tmp + 1.0f/16.0f*errorden ,ii+1,jj+1);
								}
								if(jj+1 <this->IJP_DotSize->GetLength(1)) {
									tmp = this->IJP_DotSize[ii,jj+1];
									this->IJP_DotSize->SetValue( tmp +5.0f/16.0f*errorden ,ii,jj+1);
								}
								if(ii-1 > 0 && jj+1 <this->IJP_DotSize->GetLength(1)) {
									tmp = this->IJP_DotSize[ii-1,jj+1];
									this->IJP_DotSize->SetValue(tmp +3.0f/16.0f*errorden ,ii-1,jj+1);
								}
								*/
																							
					}
			//-------------------------------------------------------------------------------------------
			}else{
				//---------------------------------------------------------------------------------------
				for(int ii = this->IJP_DotSize->GetLength(0)-1 ; ii >=0 ; ii--){			
								den = Convert::ToSingle(this->IJP_DotSize->GetValue(ii,jj));
								errorden = 0.0f;
								//Threshold �� 0.5
								selectedPT = autoRand->Next(-10,10);	
								if(den < 0.5+selectedPT/100.0f ) {
									errorden = den;
								
								}else{
								
									IJPDot->SetValue(true,ii,jj);								
									totalNumber ++;
									errorden = den-1.0f;
								}





								if(ii+2 <this->IJP_DotSize->GetLength(0)){
									
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+2,jj+1] = this->IJP_DotSize[ii+2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+2,jj+2] = this->IJP_DotSize[ii+2,jj+2] + 1.0f/48.0f*errorden;
								}

								if(ii+1 <this->IJP_DotSize->GetLength(0)){
									
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+1,jj+1] = this->IJP_DotSize[ii+1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii+1,jj+2] = this->IJP_DotSize[ii+1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii,jj+1] = this->IJP_DotSize[ii,jj+1] + 7.0f/48.0f*errorden;
								if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii,jj+2] = this->IJP_DotSize[ii,jj+2] + 5.0f/48.0f*errorden;

								if(ii-1 >= 0){
									this->IJP_DotSize[ii-1,jj] = this->IJP_DotSize[ii-1,jj] + 7.0f/48.0f*errorden;
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-1,jj+1] = this->IJP_DotSize[ii-1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-1,jj+2] = this->IJP_DotSize[ii-1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(ii-2 >= 0){
									this->IJP_DotSize[ii-2,jj] = this->IJP_DotSize[ii-2,jj] + 5.0f/48.0f*errorden;
									if(jj+1 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-2,jj+1] = this->IJP_DotSize[ii-2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <this->IJP_DotSize->GetLength(1)) this->IJP_DotSize[ii-2,jj+2] = this->IJP_DotSize[ii-2,jj+2] + 1.0f/48.0f*errorden;
								}



								/*
									//Diffusing ��F�񪺺��I
									
									if( ii-1 >=0) {
										tmp = this->IJP_DotSize[ii-1,jj];
										this->IJP_DotSize->SetValue(tmp + 7.0f/16.0f*errorden ,ii-1,jj);
									}
									if(ii-1 >=0 && jj+1 <this->IJP_DotSize->GetLength(1)) {
										tmp = this->IJP_DotSize[ii-1,jj+1];
										this->IJP_DotSize->SetValue(tmp + 1.0f/16.0f*errorden ,ii-1,jj+1);
									}
									if(jj+1 <this->IJP_DotSize->GetLength(1)) {
										tmp = this->IJP_DotSize[ii,jj+1];
										this->IJP_DotSize->SetValue( tmp +5.0f/16.0f*errorden ,ii,jj+1);
									}
									if(ii+1 < this->IJP_DotSize->GetLength(0) && jj+1 <this->IJP_DotSize->GetLength(1)) {
										tmp = this->IJP_DotSize[ii+1,jj+1];
										this->IJP_DotSize->SetValue(tmp +3.0f/16.0f*errorden ,ii+1,jj+1);
									}
								*/
	
								
					}
			//-----------------------------------------------------------------------


			}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(jj)/Convert::ToSingle(this->IJP_DotSize->GetLength(1));
				this->statusStrip1->Update();
		 }


		
		

		this->toolStripStatusLabel1->Text = "�t�m���I";
		this->statusStrip1->Update();

		for(int ii = 0 ; ii < this->IJP_DotSize->GetLength(0) ; ii ++){
			for(int jj = 0 ; jj < this->IJP_DotSize->GetLength(1) ; jj ++){
				if(Convert::ToBoolean(IJPDot->GetValue(ii,jj)) == true){
					this->IJP_DotSize->SetValue(this->MainData->IJP_DotSize, ii,jj);
				}else{
					this->IJP_DotSize->SetValue(-1.0f, ii,jj);
				}

			}

			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(ii)/Convert::ToSingle(this->IJP_DotSize->GetLength(0));
			this->statusStrip1->Update();

		}

		this->toolStripStatusLabel1->Text = "��r���I";
		this->statusStrip1->Update();


		 //��r���I����
	
		Point StartIndex;
		Point EndIndex ;

		if(this->IJPText_Index == 0 ||this->IJPText_Index == 1 || this->IJPText_Index == 2){
			StartIndex.X = Math::Round(this->IJP_DotSize->GetLength(0)*this->IJP_TextRange.X/this->MainData->LGPInformation.Width);
			StartIndex.Y = Math::Round(this->IJP_DotSize->GetLength(1)*this->IJP_TextRange.Y/this->MainData->LGPInformation.Height);
			EndIndex.X = Math::Round(this->IJP_DotSize->GetLength(0)*(this->IJP_TextRange.X+this->IJP_TextRange.Width)/this->MainData->LGPInformation.Width);
			EndIndex.Y = Math::Round(this->IJP_DotSize->GetLength(1)*(this->IJP_TextRange.Y+this->IJP_TextRange.Height)/this->MainData->LGPInformation.Height);
		}else{
			StartIndex.X = Math::Round(this->IJP_DotSize->GetLength(0)*this->IJP_TextRange.X/this->MainData->LGPInformation.Width);
			StartIndex.Y = Math::Round(this->IJP_DotSize->GetLength(1)*this->IJP_TextRange.Y/this->MainData->LGPInformation.Height);
			EndIndex.X = Math::Round(this->IJP_DotSize->GetLength(0)*(this->IJP_TextRange.X+this->IJP_TextRange.Height)/this->MainData->LGPInformation.Width);
			EndIndex.Y = Math::Round(this->IJP_DotSize->GetLength(1)*(this->IJP_TextRange.Y+this->IJP_TextRange.Width)/this->MainData->LGPInformation.Height);
		}


		
		//----------------------------------------------------------------------
		

		for(int ii = StartIndex.X ; ii <EndIndex.X ; ii++){
			for(int jj = StartIndex.Y ; jj < EndIndex.Y ; jj++){
				Point index ;
				index.X = Math::Round((float)(ii-StartIndex.X)/(float)(EndIndex.X-1-StartIndex.X)*(IJP_TextBitmap->Width-1))	;
				index.Y = Math::Round((float)(jj-StartIndex.Y)/(float)(EndIndex.Y-1-StartIndex.Y)*(IJP_TextBitmap->Height-1))	;


				if(index.X >= 0 && index.X <= IJP_TextBitmap->Width-1 && index.Y >= 0 && index.Y <= IJP_TextBitmap->Height-1){

						Color test  =  IJP_TextBitmap->GetPixel(index.X,index.Y);
						if(ii >=0 && ii < this->IJP_DotSize->GetLength(0) && jj >=0 && jj < this->IJP_DotSize->GetLength(1)){

							if( test.R == 0 && test.G == 0 && test.B == 0 ){
								if(Convert::ToSingle(this->IJP_DotSize->GetValue(ii,jj)) == -1.0f) totalNumber++;
								this->IJP_DotSize->SetValue(this->MainData->IJP_DotSize, ii,jj);
							}else{
								if(Convert::ToSingle(this->IJP_DotSize->GetValue(ii,jj)) != -1.0f) totalNumber--;
								this->IJP_DotSize->SetValue(-1.0f, ii,jj);
							}

						}
				}

			}
		}
		
	

		delete[] IJPDot;

			this->toolStripStatusLabel1->Text = "�p�⧹��";
			this->statusStrip1->Update();

			this->btn_ProducePattern->Enabled = true;

			this->lblTotalNumber->Text = "�`���I�� = " + Convert::ToString(totalNumber);

		if(this->Surface_Global_Design->IsSurfaceEmpty == false) {

			this->toolStripStatusLabel1->Text = "���͹ϧ�";
			
			this->toolStripProgressBar1->Value = 0;
			this->statusStrip1->Update();

			for(int ii = 0 ; ii < this->PatternDensity->GetMeshNumber().X ; ii++){
				for(int jj = 0 ; jj < this->PatternDensity->GetMeshNumber().Y ; jj++){
					float den = this->PatternDensity->GetDensityValue(Point(ii,jj))/100.0f;
					if (den > 0.4869f) den = 0.4869f ;  //����̤j�K�׬�48%
					this->PatternDensity->SetDensityValue(den,Point(ii,jj));
				}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(ii)/Convert::ToSingle(this->PatternDensity->GetMeshNumber().X);
			this->statusStrip1->Update();
			}

			this->DrawDesignGridDensity(this->PatternDensity);

		}
		
		//�eIJP��r

		this->toolStripProgressBar1->Value = 100;
		this->toolStripStatusLabel1->Text = "�B�⧹��";
		this->statusStrip1->Update();			
		this->UpdateMessage();
		this->CheckItem();		
		
		//---------------------------
		this->lblavgDen->Text = String::Format("�����л\�v : " + "{0:#0.00}"+" % ",Math::PI*totalNumber*this->MainData->IJP_DotSize*this->MainData->IJP_DotSize/4.0f/1000.0f/1000.0f/(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height)*100);
		this->lbl_MinPattern->Text = String::Format("�̤p���I(���|) : " + "{0:#0.0000}"+" mm",this->MainData->IJP_DotSize/1000.0f);
		this->lbl_MaxPattern->Text = String::Format("�̤j���I(���|) : " + "{0:#0.0000}"+" mm ",this->MainData->IJP_DotSize/1000.0f);
		//----------------------------

		if( exceedMaxDen == true) MessageBox::Show("�]�p�ȶW�L�̤j���\�K��,�N�H 48%�������]�p");



		//*/
















	    






		 }
private: System::Void txtBlockX_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 	
			 if ((e->KeyChar>='0' && e->KeyChar<='9') ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;	

		 }
private: System::Void txtBlockY_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

			 if ((e->KeyChar>='0' && e->KeyChar<='9') ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;	


		 }
private: System::Void txt_IJPDotSize_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

			if ((e->KeyChar>='0' && e->KeyChar<='9') || e->KeyChar == '.' ||e->KeyChar == (char)8)	e->Handled = false;
				else e->Handled = true;	
		 }
private: System::Void btn_CuttingShape_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioIJPBtn->Checked == true && this->LGPPolyLinePt->Count > 3 && this->IJP_DotSize->GetLength(0) > 0  && this->IJP_DotSize->GetLength(1) > 0){
				 //IJP ���I����
				 this->toolStripStatusLabel1->Text = "�}�l����";
				 this->btn_CuttingShape->Enabled = false;

				 long count = 0;

			

				 for(int ii = 0 ; ii < this->IJP_DotSize->GetLength(0) ; ii++){
					for(int jj = 0 ; jj < this->IJP_DotSize->GetLength(1) ; jj ++){
						if(Convert::ToSingle(this->IJP_DotSize->GetValue(ii,jj)) > 0){

							if(this->IsPtInside(PointF(ii*(25.4/this->IJP_DPI),jj*(25.4/this->IJP_DPI)),this->LGPPolyLinePt) == false){
								//��ܺ��I�b�~��
								this->IJP_DotSize->SetValue(0.0f,ii,jj);
								int indexX = Math::Truncate((float)ii/(float)this->MainData->IJP_BlockX);
								int indexY = Math::Truncate((float)jj/(float)this->MainData->IJP_BlockY);
								float den = this->PatternDensity->GetDensityValue(Point(indexX,indexY));
								den = den - Math::PI*this->MainData->IJP_DotSize/((25.4/this->IJP_DPI)*this->MainData->IJP_BlockX)/((25.4/this->IJP_DPI)*this->MainData->IJP_BlockY);
								this->PatternDensity->SetDensityValue(den,Point(indexX,indexY));

								
							}else{
								count ++ ;
							}
						}
					}
				 }

				this->toolStripStatusLabel1->Text = "���͹ϧ�";
				this->toolStripProgressBar1->Value = 0;
				this->statusStrip1->Update();
				this->DrawDesignGridDensity(this->PatternDensity);

				this->lblTotalNumber->Text = "�`���I�� = " + Convert::ToString(count);

				 this->toolStripStatusLabel1->Text = "���䧹��";
				  this->btn_CuttingShape->Enabled = true;


				 MessageBox::Show("IJP ���I���䧹��") ;
			 }else if(this->radioBtnRegular->Checked == true  && this->LGPPolyLinePt->Count > 3 && this->Dot->GetDotNumber() > 0 ){
				 //�@����I����

				  this->toolStripStatusLabel1->Text = "�}�l����";
				   this->btn_CuttingShape->Enabled = false;

				 for(int ii = 0 ;ii < this->Dot->GetDotNumber() ; ii ++){
					 PointF coord;
					 float dotsize;

					 this->Dot->GetDotValue(coord,dotsize,ii);
					 if(this->IsPtInside(coord,this->LGPPolyLinePt) == false){
						 this->Dot->SetDotValue(coord,-0.1f,ii);
					 }
				 }

				
				this->PatternDensity =  this->CalRegularPatternDensity(this->Dot,this->GirdNumber,this->MainData->LGPInformation,0);
				this->toolStripStatusLabel1->Text = "���͹ϧ�";
				this->toolStripProgressBar1->Value = 0;
				this->statusStrip1->Update();
				this->DrawDesignGridDensity(this->PatternDensity);

				 this->toolStripStatusLabel1->Text = "���䧹��";
				  this->btn_CuttingShape->Enabled = true;
				  MessageBox::Show("�W�h ���I���䧹��") ;
				 				 
			 }else if(this->radio_FMPattern->Checked == true  && this->LGPPolyLinePt->Count > 3 && this->Dot->GetDotNumber() > 0 ){
				 //FM�üƧG�I����
					this->toolStripStatusLabel1->Text = "�}�l����";
				   this->btn_CuttingShape->Enabled = false;

					for(int ii = 0 ;ii < this->Dot->GetDotNumber() ; ii ++){
						 PointF coord;
						 float dotsize;

						 this->Dot->GetDotValue(coord,dotsize,ii);
						 if(this->IsPtInside(coord,this->LGPPolyLinePt) == false){
							 this->Dot->SetDotValue(coord,-0.1f,ii);
						 }
					 }


					//���s�p��K��
					for(int ii = 0 ; ii <this->PatternDensity->GetMeshNumber().X ; ii++){
						for(int jj = 0 ; jj<this->PatternDensity->GetMeshNumber().Y ;jj++){
							PointF coord;
							coord.X = this->MainData->LGPInformation.Width * ii / (this->PatternDensity->GetMeshNumber().X-1) ;
							coord.Y = this->MainData->LGPInformation.Height * jj / (this->PatternDensity->GetMeshNumber().Y-1) ;
							if(this->IsPtInside(coord,this->LGPPolyLinePt) == false){
								this->PatternDensity->SetDensityValue(0,Point(ii,jj));
							}
						}
					}

				
					
					this->toolStripStatusLabel1->Text = "���͹ϧ�";
					this->toolStripProgressBar1->Value = 0;
					this->statusStrip1->Update();
					this->DrawDesignGridDensity(this->PatternDensity);

					this->toolStripStatusLabel1->Text = "���䧹��";
					this->btn_CuttingShape->Enabled = true;
					MessageBox::Show("FM�üƺ��I���䧹��") ;

			 }
		 }
private: System::Void iJPCAD�ɮ�ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void �~������Dxf��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 	FileKind =2;
				openFileDialog->FileName = "PolyLineFile";
				openFileDialog->Filter = "����Dxf�ɮ� (*.dxf)|*.dxf";
				openFileDialog->FilterIndex = 1;
				openFileDialog->RestoreDirectory = true;
				openFileDialog->DefaultExt=".dxf";
				if(InputFileName == nullptr){
					openFileDialog->InitialDirectory = Directory::GetCurrentDirectory();	
				}
				else{
					openFileDialog->InitialDirectory = InputFileName;
				}
				
				openFileDialog->ShowDialog();
				
			
				this->CheckItem();
		 }
private: System::Void tabControll_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->tabControll->SelectedIndex == 0 ){
				 this->radioBtnRegular->Checked = true;				 
			 }else if(this->tabControll->SelectedIndex == 2){
				 this->radioIJPBtn->Checked = true;
			 }else if(this->tabControll->SelectedIndex == 3){
				 this->radio_FMPattern->Checked = true;
			 }
		 }
private: System::Void Save_IJP_PrimerPattern_Click(System::Object^  sender, System::EventArgs^  e) {

			 //IJP_Primer Pattern 
			 FileKind = 6;
			if(this->project->projectName !="" && this->project->PatternVersion !="")
				saveFileDialog1->FileName = "IJP_Primer-" + this->project->projectName + "-" + this->project->PatternVersion;
			else	saveFileDialog1->FileName = "IJP_PrimerPattern";

			saveFileDialog1->Filter = "DxfFormat (*.dxf)|*.dxf";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			saveFileDialog1->DefaultExt = ".dxf";
			//saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();

		//	if(InputFileName == nullptr)
		//		saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();

			if(this->CurrentDictionary == "") saveFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();
			else  saveFileDialog1->InitialDirectory = this->CurrentDictionary;



			saveFileDialog1->ShowDialog();
			this->CheckItem();


		 }
private: System::Void groupBox7_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


			

			 
		

			this->ObjectCoordinate[0].X = e->X;
			this->ObjectCoordinate[0].Y = e->Y;
	

			Matrix^ InvMa = gcnew Matrix(this->MainPicMatrix->Elements[0],this->MainPicMatrix->Elements[1],this->MainPicMatrix->Elements[2],this->MainPicMatrix->Elements[3],this->MainPicMatrix->Elements[4],this->MainPicMatrix->Elements[5]) ;				
			if(InvMa->IsInvertible == true){
				InvMa->Invert();	
				InvMa->TransformPoints(this->ObjectCoordinate);
			}
			delete InvMa;
		
	
			 this->ObjectCoordinate[1].X = e->X;
			 this->ObjectCoordinate[1].Y = e->Y;


		//	 this->lblLGPLocation->Text = "�ƹ������y�� : " + Convert::ToString(this->ObjectCoordinate[0].X)  + " , " + Convert::ToString(this->ObjectCoordinate[0].Y);

			 //*

			//*/

		


				

			 
		 }

//�ۤv�[�J��MouseWheel�ƥ� 
private: System::Void pictureBox1_MouseWheel( Object^ sender, System::Windows::Forms::MouseEventArgs^ e ){


		 float scaleValue;
		scaleValue = this->MainPicMatrix->Elements[0];
		this->ObjectCoordinate[0].X = e->X;
		this->ObjectCoordinate[0].Y = e->Y;

		Matrix^ InvMa = gcnew Matrix(this->MainPicMatrix->Elements[0],this->MainPicMatrix->Elements[1],this->MainPicMatrix->Elements[2],this->MainPicMatrix->Elements[3],this->MainPicMatrix->Elements[4],this->MainPicMatrix->Elements[5]) ;
		
		
		 InvMa->Invert();	
		 InvMa->TransformPoints(this->ObjectCoordinate);
		 delete InvMa;


		this->ObjectCoordinate[1].X = e->X;
		this->ObjectCoordinate[1].Y = e->Y;
		 

	 


	

		scaleValue = scaleValue + e->Delta/240.0f;
		if(scaleValue < 0.5) scaleValue = 0.5f;

		this->PicSacleVaule = scaleValue;
		
		pictureBox1->Invalidate();
 }



private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 

			 
			if(e->Button == ::MouseButtons::Left && this->MovePic->Checked == true){

				this->ObjectCoordinate[1].X = e->X;
				this->ObjectCoordinate[1].Y = e->Y;
				this->pictureBox1->Invalidate();									
			}else{


				array<PointF>^ tmp = gcnew array<PointF>(1);   

				tmp[0].X = e->X;
				tmp[0].Y = e->Y;	
				

				//��ܷƹ������y��
				if(this->MainPicMatrix != nullptr && this->MainPicMatrix->IsInvertible == true){

				

					Matrix^ InvMa = gcnew Matrix(this->MainPicMatrix->Elements[0],this->MainPicMatrix->Elements[1],this->MainPicMatrix->Elements[2],this->MainPicMatrix->Elements[3],this->MainPicMatrix->Elements[4],this->MainPicMatrix->Elements[5]) ;				
					InvMa->Invert();	
					InvMa->TransformPoints(tmp);
					delete InvMa;										
					this->lblLGPLocation->Text = String::Format("�ƹ������y�� : " + "{0:#0.00}"+" , " +"{1:#0.00}" ,tmp[0].X,tmp[0].Y); 
				}


				//��ܷƹ������K��


				if(this->MainPicMatrix != nullptr && this->Density_Bitmap != nullptr && this->PatternDensity != nullptr && this->PatternDensity->IsDensityEmpty == false && this->MainData->LGPInformation.Contains(tmp[0]) == true  ){				
						int	indexX = Math::Round(tmp[0].X/this->MainData->LGPInformation.Width*(this->PatternDensity->GetMeshNumber().X-1));
						int	indexY = Math::Round(tmp[0].Y/this->MainData->LGPInformation.Height*(this->PatternDensity->GetMeshNumber().Y-1));										
				    	float den = this->PatternDensity->GetDensityValue(Point(indexX ,indexY))*100.0f;	
						this->lblShowDen->Text = String::Format("�ƹ������K�� :" + "{0:#0.00}",den); 
				}else{
						this->lblShowDen->Text = String::Format("�ƹ������K�� :" + "{0:#0.00}",0.0f); 

					
				}

				delete tmp;
				
			



			}

			//��ܧ����ק諸�W��

				

			
		
			

		 }
private: System::Void btnImportText_Click(System::Object^  sender, System::EventArgs^  e) {


			 
		String^ CLO_M;
		String^ CLO_P; 

	



		switch (project->LGP_Manufacture){
			case 0:   //TW
				CLO_M = "L";
				break;
			case 1:  // LC			
				CLO_M = "C";
				break;
			case 2: //LMO			
				CLO_M = "M";
				break;
		}


		//�Ȥ�n�D���s�X

		if(project->ProductionStyle == 0) {//BLU�X�f
			CLO_P = "B";
		}else  {//LGP ����
			CLO_P = "L";	
		}






		//CLO�ۤv���s�X 
		DateTime establishTime;
		establishTime = DateTime::Now::get();
		int year = establishTime.Year;
		int month = establishTime.Month;
		int day = establishTime.Day;

		

		//*
		array<wchar_t>^ spchar = {'/',' '};  
		array<String^>^ date = Convert::ToString(DateTime::Now::get())->Split(spchar);
		
		array<wchar_t>^ DateCode = gcnew array<wchar_t>(3);
	
		//DateCode[0] = date[0]->default[3];
		DateCode[0] = Convert::ToString(establishTime.Year)->default[3];

		//int month ;
		//month = Convert::ToInt64(date[1]);
	
		if( month <=9 ){			
			DateCode[1] = Convert::ToChar(Convert::ToString(month));
		}else{
			DateCode[1] = Convert::ToChar(month+55);
		}

		//int day ;
		//day = Convert::ToInt64(date[2]);

		if( day <=9 ){			
			DateCode[2] = Convert::ToChar(Convert::ToString(day));
		}else if(day >9 && day <= 17){
			DateCode[2] = Convert::ToChar(day+55);
		}else if(day >17 && day <= 22){
			DateCode[2] = Convert::ToChar(day+56);
		}else{
			DateCode[2] = Convert::ToChar(day+57);
		}

		//*/


		this->IJP_txt_TEXT->Text = this->project->projectName  + "-" +  project->PatternVersion + "-" + CLO_P + "-" +Convert::ToString(DateCode[0])+Convert::ToString(DateCode[1])+Convert::ToString(DateCode[2]) + "-" + CLO_M ;

		//this->IJP_txt_TEXT->Text = this->IJP_Text;








		 }
private: System::Void btnNormal_Click(System::Object^  sender, System::EventArgs^  e) {
			 IJPText_Index = 0;

		 }
private: System::Void btnY_Axis_Click(System::Object^  sender, System::EventArgs^  e) {
			  IJPText_Index = 1;
		 }
private: System::Void btnX_Axis_Click(System::Object^  sender, System::EventArgs^  e) {
			  IJPText_Index = 2;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  IJPText_Index = 3;
		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			  IJPText_Index = 4;
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  IJPText_Index = 5;
		 }


private: System::Void chkTextEdit_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			

			 if (this->IJP_chk_TextEdit->Checked == true){
				 this->group_Text->Enabled = true;
			 }else{
				 this->group_Text->Enabled = false;
			 }

			
		 }
private: System::Void backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {


			 				//------------------------------------------------------------------------------------------------


			 // FM -�üƧG�I

			

		this->btn_ProducePattern->Enabled = false;

		bool success = false;
	
		Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface�n + 1
		this->Surface_Global_Design->SurfaceResolution::set(Resolution);	
	
		if( (this->Surface_Global_Design->IsInputDataChanged == true ||this->Surface_Global_Design->IsSurfaceEmpty == true)){

			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͦ���";
			this->statusStrip1->Update();
			if(this->�����վ㧡��ToolStripMenuItem->Checked == true) {
		
				this->SurfacePatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);	
				this->toolStripStatusLabel1->Text = "�p��K��";
				this->Surface_Global_Design->ProduceGridDensity(this->SurfacePatternDensity);

			}else{
				MessageBox::Show("�п�ܧ��׽վ�覡");
				this->toolStripStatusLabel1->Text = "���A";
				this->statusStrip1->Update();
				return;
			}	

		}


		//For �����ק��-----------------------------------------------------------------------------------

//*

		Pattern^ tmpDot;  

		tmpDot = gcnew Pattern();

		tmpDot->BuildPattern(this->GirdNumber.X*this->GirdNumber.Y);
		this->Produce_RegularPattern(tmpDot ,this->GirdNumber ,this->MainData->LGPInformation,0,this->SurfacePatternDensity);
		
	
	
	

		tmpDot->ModifyRate_LocalArea = gcnew array<float>(tmpDot->GetDotNumber());
		for(int ii = 0 ; ii <tmpDot->GetDotNumber() ; ii++){							
			tmpDot->ModifyRate_LocalArea->SetValue(1.0f,ii);
		}

		this->toolStripProgressBar1->Value = 0;
		this->toolStripStatusLabel1->Text = "�����ק�";
		this->statusStrip1->Update();

		
		ModifyDotRate(this->localsurfacedata,tmpDot);
		//HotSpot �ק�
		if(this->HotSpotData != nullptr && this->HotSpotData->Count > 0){
			this->ProduceHotSpotDensity(tmpDot,this->HotSpotData);
		}

		//�Ѻ��I�Y���ҩM���I�K�׺�X�̲ת����I�K�� .

		
		
		this->PatternDensity = this->CalRegularPatternDensity(tmpDot ,this->GirdNumber,this->MainData->LGPInformation,1);

		
		
		
		delete tmpDot; 

//*/
		//--------------------------------------------------------------------------------------------------------------------------------------


	    


		PointF BlockSize ;
		BlockSize.X = (float)this->IJP_Grid.X/(float)this->PatternDensity->GetMeshNumber().X ;
		BlockSize.Y = (float)this->IJP_Grid.Y/(float)this->PatternDensity->GetMeshNumber().Y ;
	//	BlockSize.X = (float)this->IJP_Grid.X/(float)this->SurfacePatternDensity->GetMeshNumber().X ;
	//	BlockSize.Y = (float)this->IJP_Grid.Y/(float)this->SurfacePatternDensity->GetMeshNumber().Y ;
		array<float>^ randomData;
		Random^ autoRand = gcnew Random(0);


		long totalNumber = 0;

		bool exceedMaxDen = false;


		
		this->toolStripStatusLabel1->Text = "�t�m�K��";
		this->statusStrip1->Update();

	

		
			
		
		float size = this->MainData->FM_DotSize + this->MainData->FM_MiniDotGap;
	
	


		array<float,2>^ tmpDotDen = gcnew array<float,2>((int)(this->MainData->LGPInformation.Width/size),(int)(this->MainData->LGPInformation.Height/size));	
		array<bool,2>^ Bool_tmpDotDen = gcnew array<bool,2>((int)(this->MainData->LGPInformation.Width/size),(int)(this->MainData->LGPInformation.Height/size));	
		

		float maxDen = this->MainData->FM_DotSize*this->MainData->FM_DotSize*Math::PI/4/size/size;


		


		//*
		for(int ii = 0 ; ii < tmpDotDen->GetLength(0) ; ii ++){
			for(int jj = 0 ; jj < tmpDotDen->GetLength(1) ; jj ++){
				Point grid;
			//	grid.X = Math::Truncate(ii*(this->SurfacePatternDensity->GetMeshNumber().X-1)/(tmpDotDen->GetLength(0)-1));
			//	grid.Y = Math::Truncate(jj*(this->SurfacePatternDensity->GetMeshNumber().Y-1)/(tmpDotDen->GetLength(1)-1));
			//	float tmp = this->SurfacePatternDensity->GetDensityValue(grid);

				grid.X = Math::Truncate(ii*(this->PatternDensity->GetMeshNumber().X-1)/(tmpDotDen->GetLength(0)-1));
				grid.Y = Math::Truncate(jj*(this->PatternDensity->GetMeshNumber().Y-1)/(tmpDotDen->GetLength(1)-1));
				float tmp = this->PatternDensity->GetDensityValue(grid);
				
				
				//�w�q maxDen �ɬO�����Q�L
				//?????????????????????????????????????????????????????????????
				if(tmp > 100.0f* maxDen) tmp =100.0f*maxDen ;  //����̤j�K��
				tmpDotDen->SetValue(tmp/maxDen/100.0f,ii ,jj);
				//?????????????????????????????????????????????????????????????


			}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(ii)/Convert::ToSingle(tmpDotDen->GetLength(0));
			this->statusStrip1->Update();
		}







		this->toolStripStatusLabel1->Text = "���ͺ��I";
		this->statusStrip1->Update();

		
		int selectedPT = 0 ;

		/*
		//Halton Sequence 
		array<float,2>^ gate = gcnew array<float,2>(tmpDotDen->GetLength(0),tmpDotDen->GetLength(1));
		for(int ii = 0 ; ii < gate->GetLength(0) ;ii++){
			for(int jj = 0 ; jj < gate->GetLength(1) ;jj++){

					int temppp ;
					float H = 0 ;
					float half = 1/2.0f ;
					int tmpI = ii+1 ;
					int digit;
					while (tmpI != 0.0f ){
						Math::DivRem ( tmpI, 2 ,digit ) ;
						H = H + (float)digit * half ;
						tmpI = ( tmpI - digit )/2.0f ;
						half = half/2.0f ;
					}

					float HY = 0 ;
					half = 1.0f/3.0f ;
					tmpI = jj+1 ;
					digit= 0 ;
					while (tmpI != 0.0f ){
						Math::DivRem ( tmpI, 3 ,digit ) ;
						HY = HY + (float)digit * half ;
						tmpI = (tmpI - digit )/3.0f ;
						half = half/3.0f ;
					}

					





			}
		}
		*/
	



		//��Floyd  Error Diffusing �覡 ,�ﵽ�~�� 
		int a = 0 ;
		float errorden = 0.0f;
		float tmp = 0.0f;
		int mod = 0;
		float den = 0;
		for( int jj = 0 ; jj < tmpDotDen->GetLength(1) ; jj++){
			
			a= Math::DivRem(jj,2,mod);

			if(mod == 0 ){
			//---------------------------------------------------------------------------------------
				for(int ii = 0 ; ii < tmpDotDen->GetLength(0) ; ii++){			
								den = Convert::ToSingle(tmpDotDen->GetValue(ii,jj));


								selectedPT = autoRand->Next(-10,10);	




								//Threshold �� 0.5
								if(den < 0.5+(float)selectedPT/100.0f ) {
							

									errorden = den;
							

								}else{
								
									Bool_tmpDotDen->SetValue(true,ii,jj);
									//this->IJP_DotSize->SetValue(this->MainData->IJP_DotSize, ii,jj);
									totalNumber ++;
									errorden = den-1.0f;
								}
								//Diffusing ��F�񪺺��I (Floyd-Steinberg)
								/*
								if( ii+1 <tmpDotDen->GetLength(0)) {
									tmp = tmpDotDen[ii+1,jj];
									tmpDotDen->SetValue(tmp + 7.0f/16.0f*errorden ,ii+1,jj);
								}
								if(ii+1 <tmpDotDen->GetLength(0) && jj+1 <tmpDotDen->GetLength(1)) {
									tmp = tmpDotDen[ii+1,jj+1];
									tmpDotDen->SetValue(tmp + 1.0f/16.0f*errorden ,ii+1,jj+1);
								}
								if(jj+1 <tmpDotDen->GetLength(1)) {
									tmp = tmpDotDen[ii,jj+1];
									tmpDotDen->SetValue( tmp +5.0f/16.0f*errorden ,ii,jj+1);
								}
								if(ii-1 > 0 && jj+1 <tmpDotDen->GetLength(1)) {
									tmp = tmpDotDen[ii-1,jj+1];
									tmpDotDen->SetValue(tmp +3.0f/16.0f*errorden ,ii-1,jj+1);
								}
								//*/
								//Diffusing ��F�񪺺��I (Mini average error filter)

								if(ii+2 <tmpDotDen->GetLength(0)){
									tmpDotDen[ii+2,jj] = tmpDotDen[ii+2,jj] + 5.0f/48.0f*errorden;
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii+2,jj+1] = tmpDotDen[ii+2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii+2,jj+2] = tmpDotDen[ii+2,jj+2] + 1.0f/48.0f*errorden;
								}

								if(ii+1 <tmpDotDen->GetLength(0)){
									tmpDotDen[ii+1,jj] = tmpDotDen[ii+1,jj] + 7.0f/48.0f*errorden;
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii+1,jj+1] = tmpDotDen[ii+1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii+1,jj+2] = tmpDotDen[ii+1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii,jj+1] = tmpDotDen[ii,jj+1] + 7.0f/48.0f*errorden;
								if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii,jj+2] = tmpDotDen[ii,jj+2] + 5.0f/48.0f*errorden;

								if(ii-1 >= 0){
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii-1,jj+1] = tmpDotDen[ii-1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii-1,jj+2] = tmpDotDen[ii-1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(ii-2 >= 0){
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii-2,jj+1] = tmpDotDen[ii-2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii-2,jj+2] = tmpDotDen[ii-2,jj+2] + 1.0f/48.0f*errorden;
								}





																							
					}
			//-----------------------------------------------------------------------
			}else{
				//---------------------------------------------------------------------------------------
				for(int ii = tmpDotDen->GetLength(0)-1 ; ii >=0 ; ii--){			
								den = Convert::ToSingle(tmpDotDen->GetValue(ii,jj));
								errorden = 0.0f;
								//Threshold �� 0.5

								selectedPT = autoRand->Next(-10,10);	
								if(den < 0.5+(float)selectedPT/100.0f ) {
								
									errorden = den;
								
								}else{
								
									Bool_tmpDotDen->SetValue(true,ii,jj);
								
									totalNumber ++;
									errorden = den-1.0f;
								}
									//Diffusing ��F�񪺺��I
									/*
									if( ii-1 >=0) {
										tmp = tmpDotDen[ii-1,jj];
										tmpDotDen->SetValue(tmp + 7.0f/16.0f*errorden ,ii-1,jj);
									}
									if(ii-1 >=0 && jj+1 <tmpDotDen->GetLength(1)) {
										tmp = tmpDotDen[ii-1,jj+1];
										tmpDotDen->SetValue(tmp + 1.0f/16.0f*errorden ,ii-1,jj+1);
									}
									if(jj+1 <tmpDotDen->GetLength(1)) {
										tmp = tmpDotDen[ii,jj+1];
										tmpDotDen->SetValue( tmp +5.0f/16.0f*errorden ,ii,jj+1);
									}
									if(ii+1 < tmpDotDen->GetLength(0) && jj+1 <tmpDotDen->GetLength(1)) {
										tmp = tmpDotDen[ii+1,jj+1];
										tmpDotDen->SetValue(tmp +3.0f/16.0f*errorden ,ii+1,jj+1);
									}
									*/

								if(ii+2 <tmpDotDen->GetLength(0)){
									
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii+2,jj+1] = tmpDotDen[ii+2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii+2,jj+2] = tmpDotDen[ii+2,jj+2] + 1.0f/48.0f*errorden;
								}

								if(ii+1 <tmpDotDen->GetLength(0)){
									
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii+1,jj+1] = tmpDotDen[ii+1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii+1,jj+2] = tmpDotDen[ii+1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii,jj+1] = tmpDotDen[ii,jj+1] + 7.0f/48.0f*errorden;
								if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii,jj+2] = tmpDotDen[ii,jj+2] + 5.0f/48.0f*errorden;

								if(ii-1 >= 0){
									tmpDotDen[ii-1,jj] = tmpDotDen[ii-1,jj] + 7.0f/48.0f*errorden;
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii-1,jj+1] = tmpDotDen[ii-1,jj+1] + 5.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii-1,jj+2] = tmpDotDen[ii-1,jj+2] + 3.0f/48.0f*errorden;
								}

								if(ii-2 >= 0){
									tmpDotDen[ii-2,jj] = tmpDotDen[ii-2,jj] + 5.0f/48.0f*errorden;
									if(jj+1 <tmpDotDen->GetLength(1)) tmpDotDen[ii-2,jj+1] = tmpDotDen[ii-2,jj+1] + 3.0f/48.0f*errorden;
									if(jj+2 <tmpDotDen->GetLength(1)) tmpDotDen[ii-2,jj+2] = tmpDotDen[ii-2,jj+2] + 1.0f/48.0f*errorden;
								}
	
								
					}
			//-----------------------------------------------------------------------


			}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(jj)/Convert::ToSingle(tmpDotDen->GetLength(1));
				this->statusStrip1->Update();
		 }

		//*/

		this->toolStripStatusLabel1->Text = "�t�m���I";
		this->statusStrip1->Update();


		this->Dot->BuildPattern(totalNumber);

		//float deltaX = ;

		float deltaX = (this->MainData->LGPInformation.Width - Bool_tmpDotDen->GetLength(0)*size)/2;
		float deltaY = (this->MainData->LGPInformation.Height - Bool_tmpDotDen->GetLength(1)*size)/2;


	
		


		int count = 0;
		for(int ii = 0 ; ii < Bool_tmpDotDen->GetLength(0); ii ++){
			for(int jj = 0 ; jj <Bool_tmpDotDen->GetLength(1); jj ++){
				if(Convert::ToBoolean(Bool_tmpDotDen->GetValue(ii,jj)) == true){
					PointF coor(deltaX + (ii+0.5)*size, deltaY + (jj+0.5)*size);
					this->Dot->SetDotValue(coor,this->MainData->FM_DotSize,count);	
					count ++ ;
				}
			}
		}

	
			this->toolStripStatusLabel1->Text = "�p�⧹��";
			this->statusStrip1->Update();

			this->btn_ProducePattern->Enabled = true;

			this->lblTotalNumber->Text = "�`���I�� = " + Convert::ToString(totalNumber);

		if(this->Surface_Global_Design->IsSurfaceEmpty == false) {

			this->toolStripStatusLabel1->Text = "���͹ϧ�";
			
			this->toolStripProgressBar1->Value = 0;
			this->statusStrip1->Update();

			for(int ii = 0 ; ii < this->PatternDensity->GetMeshNumber().X ; ii++){
				for(int jj = 0 ; jj < this->PatternDensity->GetMeshNumber().Y ; jj++){
					float den = this->PatternDensity->GetDensityValue(Point(ii,jj))/100.0f;
					
					//if (den > 0.4869) den = 0.4869 ;  //����̤j�K�׬�48%
					if (den > maxDen) den = maxDen ;  //����̤j�K��
					this->PatternDensity->SetDensityValue(den,Point(ii,jj));
				}
			this->toolStripProgressBar1->Value = 100.0f*Convert::ToSingle(ii)/Convert::ToSingle(this->PatternDensity->GetMeshNumber().X);
			this->statusStrip1->Update();
			}

			this->DrawDesignGridDensity(this->PatternDensity);

		}
		
	
		

		delete[]  tmpDotDen;	
		delete[]  Bool_tmpDotDen;
		GC::Collect();
			




		this->toolStripProgressBar1->Value = 100;
		this->toolStripStatusLabel1->Text = "�B�⧹��";
		this->statusStrip1->Update();			
		this->UpdateMessage();
		this->CheckItem();		
		
		//---------------------------
		this->lblavgDen->Text = String::Format("�����л\�v : " + "{0:#0.00}"+" % ",Math::PI*totalNumber*this->MainData->FM_DotSize*this->MainData->FM_DotSize/4.0f/(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height)*100);
		this->lbl_MinPattern->Text = String::Format("�̤p���I(���|) : " + "{0:#0.0000}"+" mm",this->MainData->FM_DotSize);
		this->lbl_MaxPattern->Text = String::Format("�̤j���I(���|) : " + "{0:#0.0000}"+" mm ",this->MainData->FM_DotSize);
		//----------------------------

		









		 }
private: System::Void btnFMPattern_Click(System::Object^  sender, System::EventArgs^  e) {

			 try{

					this->MainData->LGPInformation = RectangleF(0,0,Convert::ToSingle(this->txt_LGPLength->Text),Convert::ToSingle(this->txt_LGPWidth->Text));
					this->MainData->FM_DotSize = Convert::ToSingle(this->txtFMPattern->Text);				 
					this->MainData->FM_MiniDotGap = Convert::ToSingle(this->txtFMPatternGap->Text);
				}catch(...){
					MessageBox::Show("��ƿ�J���~ !!");
					return;
				}




				 float den = 100.0f * this->MainData->FM_DotSize*this->MainData->FM_DotSize*Math::PI/4/(this->MainData->FM_DotSize+this->MainData->FM_MiniDotGap)/(this->MainData->FM_DotSize+this->MainData->FM_MiniDotGap);
				 this->lbl_FMMaxDen->Text = String::Format("���\�̤j�K�� : " + "{0:#0.00}" + "%",den);


				 //�w�q 1mm �@�Ӻ���
				 this->GirdNumber.X = (int)this->MainData->LGPInformation.Width ;
				 this->GirdNumber.Y = (int)this->MainData->LGPInformation.Height;



				//�NResolution �ǤJ��Surface�� 
				Point tmpRes(this->GirdNumber.X+1 ,this->GirdNumber.Y + 1);
				this->Surface_Global_Design->SurfaceResolution::set(tmpRes);



				//�ϧΤƪ���l�]�w

				this->PicSacleVaule = Math::Min(this->pictureBox1->Width/this->MainData->LGPInformation.Width*0.8f,this->pictureBox1->Height/this->MainData->LGPInformation.Height*0.8f);
				//��l�Ƽƭ�

				ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
				ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
				ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
				ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;

				this->CheckItem();





		 }
private: System::Void radio_FMPattern_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 	if(this->radioBtnRandom->Checked == true){
					 //IBM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = true;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;					 
					 this->tabControll->SelectedIndex = 1;					
					  this->MainData->DotType = 1;

				 }else if(this->radioBtnRegular->Checked == true){
					 //�W�h�G�I
					 this->tab_Regular->Enabled = true;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 0;
					
					   this->MainData->DotType = 0;

				 }else if(this->radioIJPBtn->Checked == true){
					//IJP�G�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = true;
					 this->tab_FM_Pattern->Enabled = false;
					 this->tabControll->SelectedIndex = 2;
					  this->MainData->DotType = 2;

				 }else{ 
					 //FM�üƧG�I
					 this->tab_Regular->Enabled = false;
					 this->tab_Random->Enabled = false;
					 this->tabPageIJP->Enabled = false;
					 this->tab_FM_Pattern->Enabled = true;
					 this->tabControll->SelectedIndex = 3;
					 this->MainData->DotType = 3;
				 }



		 }
private: System::Void �ϰ�ק�\��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};



}

