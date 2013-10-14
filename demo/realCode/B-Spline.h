
#ifndef B_Spline_h
#define B_Spline_h

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;


typedef  void (*CALLBACK) (int);

public ref class B_Spline_Curve: public System::Object{

public:
	B_Spline_Curve(){
		KnotVector = gcnew array<float>(0);
		//NikVector = gcnew array<float>(0);
		NikVectorGroup = gcnew array<array<float>^>(0);
		//tmpNikVector =  gcnew array<float>(0);
		ControllPt =  gcnew List<PointF>(0);
		Curve = gcnew array<PointF>(0);		
		k_value = 0 ;
		rebuildKnotVector = true;
		rebuildNikVector = true;
	};

	~B_Spline_Curve(){
		ControllPt->Clear();
		Array::Clear(Curve,0,Curve->Length);
		Array::Clear(KnotVector,0,KnotVector->Length);
		
	};


	//控制點
	List<PointF>^ ControllPt;
	//Curve
	array<PointF>^ GetCurve();



	void ReProduceCurve(int resolution);
	//在繪製Curve時 ,設定產生Curve允許的範圍
	void ReProduceCurve(int resolution,Rectangle Coordinate_Boundary);

	void Set_k_Value(int k_value);
	int Get_k_Value();
	int ComapreControllPt(PointF xtmpPt1,PointF xtmpPt2);


	
	float GetCurve_Z_Value(float X,int StartSearchIndex);
	void xInitialize(PointF startPt,PointF endPt);
	

private:
	
	
	array<PointF>^ Curve;		
	array<float>^ KnotVector;

	array<array<float>^>^ NikVectorGroup;

	int k_value;  //階數
	int pre_ControllPt_Number;
	void SetNikVector(float t,array<float>^ &xNikVector);
	void SetNikVectorGroup(int resolution);
	void SetKnotVector();

	bool rebuildKnotVector;
	bool rebuildNikVector;

	
	

};

//Surface 
public ref class B_Spline_Surface:public System::Object{

public:
	B_Spline_Surface(){

		this->xInitialize();


	
	};

	~B_Spline_Surface(){
			
	};

	//控制點
	array<PointF,2>^ ControllPt;
	array<float,2>^ ControllPt_Z;
	array<PointF,2>^  Surface;
	array<float,2>^ Surface_Z;
	RectangleF SurfaceBoundary;

	void ProduceSurface(int resolution_u ,int resolution_v );
//	void ProduceSurface(int resolution_u ,int resolution_v ,CALLBACK fcallback);
	float GetSurface_Z_Value(float X_Location,float Y_Location);
	float GetSurface_Z_Value(float X_Location,float Y_Location,int IniIndexX,int IniIndexY);
	void Set_uv_Value(int u_value,int v_value);
	void Get_uv_Value(int &u_value,int &v_value);
	bool BuildBlendingVector_Nik;
	bool BuildBlendingVector_Mjl;

	//權重
	array<float,2>^ Weight;

private:



public:	
//private:
	array<float>^   KnotVector_u;
	array<float>^   KnotVector_v;
	array<array<float>^>^ NikVectorGroup;
	array<array<float>^>^ MjlVectorGroup;	
	array<float>^ SetKnotVector(char KnotVector_Type);

	void SetBlendingVectorGroup(int resolution ,char BlendVector_Type );
	void SetBlendingVector(float t,array<float>^ &xBlendingVector,char direction);
	void CopyFrom(B_Spline_Surface^ SourceObj);

	int u_value ;
	int v_value ;
	bool BuildKnotVector_u;
	bool BuildKnotVector_v;
	void xInitialize();


	//Define  "u_value , ControllPt->(Dimension 0) ,NikVectorGroup ,KnotVector_u " are Group 1




};



public ref class TranslateModule: public System::Object{
	public:
		TranslateModule(){
		};
		~TranslateModule(){
		};

		PointF Translate_Pt_From_Screen_To_BSplineCoordinate(PointF^ ScreenPt,SizeF^ DrawingFrameSize,int Y_Direction_Boundary,int X_Direction_Boundary,float X_Coordinate_Range,float Y_Coordinate_Range);
		PointF Translate_Pt_From_BSplineCoordinate_To_Screen(PointF^ B_SplinePt,SizeF^ DrawingFrameSize,int Y_Direction_Boundary,int X_Direction_Boundary,float X_Coordinate_Range,float Y_Coordinate_Range);
		
};






void GetKnotVector(array<float>^ &KnotVector,int n_value , int k_value);
void GetNikValue(array<float>^ &NikVector , array<float>^ KnotVector , int k_value ,float t,int n_value);
//B-Spline 曲面公式
void Get_BSplineSurface_Point(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,float para_u,float para_v, int k_value );
void Get_BSplineSurface_Point_New071101(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,float para_u,float para_v, int k_value
										,int i,int j,float plateW,float plateH,float *size,float *pos);
void Get_BSplineSurface_Point_New080311(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,float para_u,float para_v, int k_value,array<float>^ KnotVector_u,array<float>^ KnotVector_v );













#endif