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

		//網點形式  1 亂數 , 2 規則矩形排列 , 3 規則錯排
		int PatternMode;
		// 運算模式選擇 Ｖerlert = 1, Fast = 2, Normal = 3 
		int CalMode;  
		//上邊界距離　
		float Boundary_Up;
		//下邊界距離
		float Boundary_Down;
		//左邊界距離
		float Boundary_Left;
		//右邊界距離
		float Boundary_Right;
		//所有網點至少相距距離
		float Pattern_Space;
		//0表示圓形 ,1表示矩形 , 2 表示菱形
		int PatternShape; 
        //導光版寬度
		float PlateWidth;
        //導光版長度	
		float PlateHeight;
        //網格大小(N X N個網格) [0]為width [1]為height
		int MeshNumber[2];	  
		//選擇網點數目 (0表示根據密度設定 ,1表示自行設定)
		int PatternNumberSelection;
		//網點數目
		int PatternNumber;
		//終止分子動力模擬條件( 1 表示次數 , 4 表示達到適當距離 )
		int StopCriteria;
		//終止條件之次數
		int StopCriteriaIteriation; 
		// 亂數 --網點半徑（輸入為網點直徑或邊長) , 規則 --最大網點大小
		float PatternRadius;
		
		//----下面是內部參數設定----
		//模擬設定( 0表示為 橢圓形 ,1表示為矩形)
		int SimShape;
		//參數K設定
		float Parameter_K;
		//參數C設定
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

		//20120920 增加 -Swap Mode : 主要是橢圓Swap 時有分等比Swap 和非等比Swap .效果會不同
		int SwapModeIndex;
		

		Nurbs::B_Spline_Curve^ tmpCurve;

		void BuildCurve(int SamplingNumber); //建立Curve (必須建立完後才能夠判斷增益值)
		String^ Save();
		void Load(String^ data ,int version);

};

public ref class SettingData: public System::Object{
public:
	// 0為2D , 1為3D
	int  LTPattern_Style;
	//0為圓 ,1為矩形 ,2為菱型
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
		
		void BuildRegularPattern(int GridX,int GridY,int PatternArrangement); // 建立一個新的Pattern ,建立時 ,會初始話Modify Rate 為 1 .
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
	//	array<float>^ Origional_Dot_Diameter; //尚未修改網點的Pattern
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
		float GetDensity_Value_FromDotCood(PointF dotCoodrinate,RectangleF LGPInformation,Point GridNumber); // 座標定義為程式內定的座標(也就是Y方向朝下)		
		void GetDensity_Color(int &R ,int &G, int &B ,Point index);
		void xClearAll();
		void CreateGridDensity(Point GridNumber);
		float  maxDensity_Color;
		float  minDensity_Color;



};
//*/
public ref class MainFormData: public System::Object{
public :
	
	//LGP 尺寸
//	PointF LGPDimension;
	RectangleF LGPInformation;
	
	//網點形狀
	int Pattern_Shape;  //0表示圓形 ,1表示矩形 , 2 表示菱形

	//佈點型態
	int DotType;  //0表示規則佈點 , 1表示亂數佈點 ,2表示IJP佈點 ,3表示FM亂數佈點 
	//bool RandomDot; //不含IJP佈點時
	


	//規則佈點參數
	float MaxDot;
	float MinDot;
	float MinDotGap;	
	int Pattern_Arrangment;  // 0 : 矩形排列 , 1 : 45D錯排 , 2 : 60D錯排 ,3 :30D 錯排

	//20110812 新增參數
	int PitchDirection;
	float ActualPitchValue;

	//20110907 新增參數 (IJP每個區塊大小(X方向))
	int IJP_BlockX ;
	//20110907 新增參數 (IJP每個區塊大小(Y方向))
	int IJP_BlockY ;
	//20110907 新增參數 (IJP 網點大小)
	float IJP_DotSize ;

	//20120319 IJP 文字
	bool IJP_chkTextEdit ;
	int IJP_TextLocation;
	float IJP_TextLocation_X;
	float IJP_TextLocation_Y;
	float IJP_TextHeight;
	float IJP_TextLength;
	String^ IJP_Text;







	//亂數佈點參數
	
	float RandomDotSize;
	float RandomDotGap;
	//終止條件
	int RandomDotIteration;
	float RandomStopForce;
	bool chkStopNmber;
	bool chkStopForce;
	//----下面是進階參數設定----	
	int RandomDotSimRule;  //模擬設定( 0表示為 橢圓形 ,1表示為矩形)
	float Parameter_K;
	float Parameter_C;
	int RandomRebuildFrequency;

	//其他參數 (紀錄密度調整方式)
	int DensityDesignMethod ;  // 0為曲線調整 ,1為曲面調整

	//FM 亂數佈點參數
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

		//規則網點初始化參數

		this->MaxDot = 1.0f;
		this->MinDot = 0.5f;
		this->MinDotGap = 0.1f;
		this->Pattern_Shape = 0 ;
		this->Pattern_Arrangment = 2;

		//亂數網點初始化參數
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

		//密度設計方式
		this->DensityDesignMethod = -1;

		//20110812 新增參數 (PitchValue)
		this->PitchDirection = -1;    //-1 表示不啟用此功能
		this->ActualPitchValue = 0.0f;

		//20110907 新增參數 (IJP參數)
		this->IJP_BlockX = 17;
		this->IJP_BlockY = 17;
		this->IJP_DotSize = 50 ;

		//20120319 IJP文字
		this->IJP_chkTextEdit = false ;
		this->IJP_TextLocation = 0;
		this->IJP_TextLocation_X = 0;
		this->IJP_TextLocation_Y = 0;
		this->IJP_TextHeight = 1.0f;
		this->IJP_TextLength = 7.0f;
		this->IJP_Text = "";






		//20120319 FM 亂數佈點
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


		int ProductionStyle;   //出貨方式           0 : BLU  ,1 : LGP單體
		int LGP_Manufacture;   //製造地             0 : TW ,  1 : LC  ,2 :LMO
		int LGP_Material;      //材質               0 : PMMA, 1 : LNX865
		String^ LGP_PN_Number; //料號


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
	//必須要先初始化後才能設定數目
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

//定義物件 (多表單共用,且需一直存在或資料數目不大)


//參數設定相關資訊


static bool reconstruct_density;
static bool readingFile;


		
#endif

#pragma endregion