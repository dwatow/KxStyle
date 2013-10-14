#pragma once
#ifndef DataStructure_h
#define DataStructure_h
#include <math.h>
//#include <map>
#include <iostream>
//#include "B-Spline.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::IO;


using namespace Nurbs;
	
class DataInput{		
	public:

		//���I�Φ�  1 �ü� , 2 �W�h�x�αƦC , 3 �W�h����
		int PatternMode;
		// �B��Ҧ���� ��erlert = 1, Fast = 2, Normal = 3 
		int CalMode;  
		//�W��ɶZ���@
		float Boundary_Up;
		//�U��ɶZ��
		float Boundary_Down;
		//����ɶZ��
		float Boundary_Left;
		//�k��ɶZ��
		float Boundary_Right;
		//�Ҧ����I�ܤ֬۶Z�Z��
		float Pattern_Space;
		//0��ܶ�� ,1��ܯx�� , 2 ��ܵ٧�
		int PatternShape; 
        //�ɥ����e��
		float PlateWidth;
        //�ɥ�������	
		float PlateHeight;
        //����j�p(N X N�Ӻ���) [0]��width [1]��height
		int MeshNumber[2];	  
		//��ܺ��I�ƥ� (0��ܮھڱK�׳]�w ,1��ܦۦ�]�w)
		int PatternNumberSelection;
		//���I�ƥ�
		int PatternNumber;
		//�פ���l�ʤO��������( 1 ��ܦ��� , 4 ��ܹF��A��Z�� )
		int StopCriteria;
		//�פ���󤧦���
		int StopCriteriaIteriation; 
		// �ü� --���I�b�|�]��J�����I���|�����) , �W�h --�̤j���I�j�p
		float PatternRadius;
		
		//----�U���O�����ѼƳ]�w----
		//�����]�w( 0��ܬ� ���� ,1��ܬ��x��)
		int SimShape;
		//�Ѽ�K�]�w
		float Parameter_K;
		//�Ѽ�C�]�w
		float Parameter_C;

		void Initial();


};
public ref class HotSpot_Part: public System::Object{

	public:

		HotSpot_Part(){
			Number = 1;
			CenterGainValue = 2.0f;
			SmoothingDegree = 4;
			ConrollPt = gcnew array<PointF>(3);
			ConrollPt[0].X = 0.25f;
			ConrollPt[0].Y = 1.0f;
			ConrollPt[1].X = 0.5f;
			ConrollPt[1].Y = 1.5f;
			ConrollPt[2].X = 0.75f;
			ConrollPt[2].Y = 2.0f;

		};
		~HotSpot_Part(){
		};

		String^ Name;
		String^ Shape;
		int ShapeIndex;
		int Number;
		String^ PitchDirection;
		int PitchDirectionIndex;
		float pitch;
		float Length_X;
		float Length_Y;
		PointF CenterCoordinate;
		float rotateAngle;
		float CenterGainValue;
		int SmoothingDegree;
		array<PointF>^ ConrollPt;

		//20120920 �W�[ -Swap Mode : �D�n�O���Swap �ɦ�������Swap �M�D����Swap .�ĪG�|���P
		int SwapModeIndex;
		

		Nurbs::B_Spline_Curve^ tmpCurve;

		void BuildCurve(int SamplingNumber); //�إ�Curve (�����إߧ���~����P�_�W�q��)
		String^ Save();
		void Load(String^ data ,int version);

};

public ref class SettingData: public System::Object{
public:
	// 0��2D , 1��3D
	int  LTPattern_Style;
	//0���� ,1���x�� ,2���٫�
	int  LTPattern_Shape;
	float  X_direction_Shift;
	float Y_direction_Shift;
	float PatternDeep;

	float Color_MaxDenValue;
	float Color_MinDenValue;
	bool LimitDotSize;




	SettingData(){
		LTPattern_Style = 0;
		LTPattern_Shape = 0;
		X_direction_Shift = 0;
	    Y_direction_Shift = 0;
	    PatternDeep = 0;
		Color_MaxDenValue = 100;
		Color_MinDenValue = 0;
		LimitDotSize = false;


		
	};

	~SettingData(){		
	};


public:
	void Initialize_LT_Setting();

};

public ref class Pattern: public System::Object{
	private:
	
	//	array<int,2>^ Outside_Dot_Index;
	//	array<int,2>^ Inside_Dot_Index;
	public:	
		Pattern(){

			this->Initialize_me();


		};
		~Pattern(){
			this->ClearAll();
			GC::Collect();
			
		};
		
				
	public:
		
		void BuildRegularPattern(int GridX,int GridY,int PatternArrangement); // �إߤ@�ӷs��Pattern ,�إ߮� ,�|��l��Modify Rate �� 1 .
		void BuildPattern(long DotNumber);
		void SetDotValue(PointF dot_coor ,float dot_dia,long Dot_Index);
	//	void SetDotModifyRateValue(float modifyrate, int row , int column,bool cross_arrangement);
	//	void SetDotModifyRateValue(float modifyrate, int selectedNumber ,bool cross_arrangement ,bool row);
		//void SetDotModifyRateValue(float modifyrate, int column,bool cross_arrangement);
	//	void SetDotLocation(int Dot_Index,Point Correspond_dot_Location ,bool OutsideDot);
		void GetDotValue(PointF &dot_coor,float &dot_dia ,int Index);
	//	void GetDotValue(PointF &dot_coor,float &dot_dia ,Point dot_Index ,bool OutsideDot);
		void ClearAll();
		void Initialize_me();
	//	bool BuildOri_DotDia();
		long GetDotNumber();
		


		


	//	array<float>^ Dot_ModifyRate;
	//	array<float>^ ModifyRate_Line;
		array<PointF>^ Dot_Coordinate;
	//	array<float>^ ModifyRate_HotSpot;
		array<float>^ ModifyRate_LocalArea;

		array<float>^ Dot_Diameter;	
	//	array<float>^ Origional_Dot_Diameter; //�|���ק���I��Pattern
		array<Point,2>^ DotDensity_Index;
		array<PointF>^ Dot_Force;

		array<float>^ MuraValue;




		
		

		
		

		
		

		

	


};
public ref class Cosmetic_Data : public System::Object{

public :
	array<float>^ Current_InputData;
	array<float,2>^ LocalArea_History_Data;
	array<float,2>^ Line_History_Data;
	array<String^,2>^ HotBar_History_Data;
//	B_Spline_Surface^ LocalSurface;

	void Initialize();
	

public :
	Cosmetic_Data(){
		Initialize();
	
	};
	~Cosmetic_Data(){

	};

	


};
/*
public ref class GridDensity: public System::Object{
	private:
		array<int,2>^ DensityColor_R;
		array<int,2>^ DensityColor_G;
		array<int,2>^ DensityColor_B;
		array<float,2>^ DensityValue;
	
		
		void SetDensityColor(float density,float &R ,float &G ,float &B);
	

		

	public:
		array<List<int>^,2>^ DotIndex;
		GridDensity(int GridNumberX,int GridNumberY,float maxColorDen ,float minColorDen,ButtonBase^ btnProducePattern){
			DensityValue = gcnew array<float,2>(GridNumberX,GridNumberY);
			DensityColor_R = gcnew array<int,2>(GridNumberX,GridNumberY);
			DensityColor_G = gcnew array<int,2>(GridNumberX,GridNumberY);
			DensityColor_B = gcnew array<int,2>(GridNumberX,GridNumberY);
			maxDensity_Color = maxColorDen;
		    minDensity_Color = minColorDen;
			
			
			

		};

		~GridDensity(){
		};


	public :
		void SetDensity(float den,Point index);
		void SetDensity(float den,int indexX, int indexY);
		void GetDensity_Value(float &den ,Point index);
		void GetDensity_Value(float &den ,int indexX, int indexY);	
		float GetDensity_Value_FromDotCood(PointF dotCoodrinate,RectangleF LGPInformation,Point GridNumber); // �y�Щw�q���{�����w���y��(�]�N�OY��V�¤U)		
		void GetDensity_Color(int &R ,int &G, int &B ,Point index);
		void xClearAll();
		void CreateGridDensity(Point GridNumber);
		float  maxDensity_Color;
		float  minDensity_Color;



};
//*/
public ref class MainFormData: public System::Object{
public :
	
	//LGP �ؤo
//	PointF LGPDimension;
	RectangleF LGPInformation;
	
	//���I�Ϊ�
	int Pattern_Shape;  //0��ܶ�� ,1��ܯx�� , 2 ��ܵ٧�

	//�G�I���A
	int DotType;  //0��ܳW�h�G�I , 1��ܶüƧG�I ,2���IJP�G�I ,3���FM�üƧG�I 
	//bool RandomDot; //���tIJP�G�I��
	


	//�W�h�G�I�Ѽ�
	float MaxDot;
	float MinDot;
	float MinDotGap;	
	int Pattern_Arrangment;  // 0 : �x�αƦC , 1 : 45D���� , 2 : 60D���� ,3 :30D ����

	//20110812 �s�W�Ѽ�
	int PitchDirection;
	float ActualPitchValue;

	//20110907 �s�W�Ѽ� (IJP�C�Ӱ϶��j�p(X��V))
	int IJP_BlockX ;
	//20110907 �s�W�Ѽ� (IJP�C�Ӱ϶��j�p(Y��V))
	int IJP_BlockY ;
	//20110907 �s�W�Ѽ� (IJP ���I�j�p)
	float IJP_DotSize ;

	//20120319 IJP ��r
	bool IJP_chkTextEdit ;
	int IJP_TextLocation;
	float IJP_TextLocation_X;
	float IJP_TextLocation_Y;
	float IJP_TextHeight;
	float IJP_TextLength;
	String^ IJP_Text;







	//�üƧG�I�Ѽ�
	
	float RandomDotSize;
	float RandomDotGap;
	//�פ����
	int RandomDotIteration;
	float RandomStopForce;
	bool chkStopNmber;
	bool chkStopForce;
	//----�U���O�i���ѼƳ]�w----	
	int RandomDotSimRule;  //�����]�w( 0��ܬ� ���� ,1��ܬ��x��)
	float Parameter_K;
	float Parameter_C;
	int RandomRebuildFrequency;

	//��L�Ѽ� (�����K�׽վ�覡)
	int DensityDesignMethod ;  // 0�����u�վ� ,1�������վ�

	//FM �üƧG�I�Ѽ�
	float FM_DotSize;
	float FM_MiniDotGap;





	
public :
	void GetInputData(DataInput oldform);
//private:
	//void Initialize();

	MainFormData(){
		this->Initialize();

	};
	~MainFormData(){
	};
	void Initialize(){
	//	this->LGPDimension = PointF(420,297);				
		this->LGPInformation = RectangleF(0,0,420,297);
		this->Pattern_Shape = 0;
		//this->RandomDot = false;
		this->DotType = 0;

		//�W�h���I��l�ưѼ�

		this->MaxDot = 1.0f;
		this->MinDot = 0.5f;
		this->MinDotGap = 0.1f;
		this->Pattern_Shape = 0 ;
		this->Pattern_Arrangment = 2;

		//�üƺ��I��l�ưѼ�
		this->RandomDotSize = 0.3f;
		this->RandomDotGap = 0.015f;
		this->RandomDotIteration = 50;
		this->RandomDotSimRule = 0;
		this->Parameter_K = 1.0f;
		this->Parameter_C = 0.5f;
		this->RandomStopForce = 0.5f;
		this->RandomRebuildFrequency = 2;
		this->chkStopNmber = true;
		this->chkStopForce = true;

		//�K�׳]�p�覡
		this->DensityDesignMethod = -1;

		//20110812 �s�W�Ѽ� (PitchValue)
		this->PitchDirection = -1;    //-1 ��ܤ��ҥΦ��\��
		this->ActualPitchValue = 0.0f;

		//20110907 �s�W�Ѽ� (IJP�Ѽ�)
		this->IJP_BlockX = 17;
		this->IJP_BlockY = 17;
		this->IJP_DotSize = 50 ;

		//20120319 IJP��r
		this->IJP_chkTextEdit = false ;
		this->IJP_TextLocation = 0;
		this->IJP_TextLocation_X = 0;
		this->IJP_TextLocation_Y = 0;
		this->IJP_TextHeight = 1.0f;
		this->IJP_TextLength = 7.0f;
		this->IJP_Text = "";






		//20120319 FM �üƧG�I
		this->FM_DotSize = 0.3f;
		this->FM_MiniDotGap = 0.15f;



}



};


public ref class Project_Information: public System::Object{
	
	

	public:	
		Project_Information(){

		};

		~Project_Information(){

		};

		String^ projectName;
		String^ PatternVersion;
		
		int RegularInkProperty;
		String^ SpecialInk;

		int ScreenSize;
		int MeshSize;
		float Thick;
		float ScreenAngle;
		String^ Designer;
		String^ DesignDate;


		int ProductionStyle;   //�X�f�覡           0 : BLU  ,1 : LGP����
		int LGP_Manufacture;   //�s�y�a             0 : TW ,  1 : LC  ,2 :LMO
		int LGP_Material;      //����               0 : PMMA, 1 : LNX865
		String^ LGP_PN_Number; //�Ƹ�


	void ClearAll();







};



public ref class SmoothSurfaceInfo: public System::Object{

public:
	int Controll_Row_number;
	int Controll_Collum_number;
	array<float,2>^ controllPt_X;
	array<float,2>^ controllPt_Y;
	array<float,2>^ controllPt_Z;
	
	
	int SelectIndex_X;
	int SelectIndex_Y;
	float IniValue_Z;

public:
	SmoothSurfaceInfo(){
		Empty = true;
	}

	~SmoothSurfaceInfo(){
	};

	void Initialize(float PlateWidth,float PlateHeight,float IniValue_Z);
	//�����n����l�ƫ�~��]�w�ƥ�
	void SetControllPt_Number_IniValue(int X_Number,int Y_Number,float Ini_Z);

	

public :
	bool Empty;

public:
	float PlateW;
	float PlateH;



};
/*
public ref class MeshGridInfo: public System::Object{
	public:
		array<float,2>^ Density;
		array<float,2>^ ChangedDensity;

		array<array<int>^,2>^ PtInDensityGrid;
		
		
	
		bool Empty;
	public:
		MeshGridInfo(){
			Empty = true;
		};

		~MeshGridInfo(){
		};
	public :
		void Initailize(int Number_X ,int Number_Y ,float IniDensity);
		void ClearAll();
	private:
		int Number_X;
		int Number_Y;
		float IniDensity;
		

};
*/





/*
struct DlgSmoothSurfaceData {
public:
	float CurrentControllPt_X;
	float CurrentControllPt_Y;
	float CurrentControllPt_Z;
	int Controll_Row_number;
	int Controll_Collum_number;
	float IniValue_Z;
	int MouseFunctionSelected;
};
*/

class Force{
public :
	float Fx;
	float Fy;
	float Fz;
};
/*
struct MeshInfo {
public :
	int WGrid;
	int HGrid;
	bool NonDimInfo ;
};
*/
/*
struct PenBlushInfo {
public:
	float PenPara ;
	float PenSize ;		
	int SelectType;
	int CurveStyle;
	
};
*/


class MeshGrid{
private :
	float MeshSize[2];  //W X H
	float MeshPosition[2]; //X,Y
	float PatternDensityinMesh ;	
	

public :
	long PtNumbers;
	int Color_R;
	int Color_G;
	int Color_B;
	float SqrtDensity ;
	float DividSqrtDensity;
	int relationMeshGird[8];
	void SetMeshSize(float size[2]);
	float* GetMeshSize();
	void SetMeshPosition(float pos[2]);
	float *GetMeshPosition();
	void SetPatternDensityinMesh(float density);
	float GetPatternDensityinMesh();


	
};


class Point3d{


public:
		float X;
		float Y;
		float Z;
		int MeshIndex;
		int RelationPtNumber;
		Force totalforce;
		bool Overlap;
		bool InsidePlateArea;
		float Radius;	
//public:
	
		 void GetPointPosition(double &x,double &y,double &z);
		 void SetPointPosition(double x ,double y,double z);
		 int GetMeshIndex();
		 void SetMeshIndex(int mindex);
		 void AddForce(Force f);
		 void IniForce();
		 void GetForce(Force &force);
		 void IniPt();

};
/*
class DrawInfo{
public:
	bool RedrawPattern;
	bool RedrawOriPattern;
	bool RedrawUnSuitablePattern;
	bool RedrawDesignDensity;
	bool RedrawActualDensity;
	bool RedrawMesh;
	void Initial(); 

};
*/






void SetDensityColor(float &density,float &R ,float &G ,float &B);

//�w�q���� (�h���@��,�B�ݤ@���s�b�θ�Ƽƥؤ��j)


//�ѼƳ]�w������T


static bool reconstruct_density;
static bool readingFile;


		
#endif

#pragma endregion