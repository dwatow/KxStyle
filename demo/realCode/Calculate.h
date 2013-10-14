
#ifndef Setting_h
#define Setting_h

#include "DataStructure.h"
#include <iostream>
//#include <vector>
#include <deque>
#include <list>



using namespace std ;
using namespace System;


void TwoPointForce_Morse(Point3d &p1,Point3d p2,double properdistance);
void TwoPointForce(double K,double Radius,Point3d &p1,Point3d &p2,int shape,double properdistance ,bool Verlert);
void MoveDistance(double C ,double t,Point3d &pt);
void ProduceLDSPattern(MeshGrid *mesh,Point3d *pt,int MeshGrid,int PtNumber);
void RapidDynamicsMode(int TotalMeshNumber ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
					    float K , float C , int &overlapnumber , int &actualnumber,float PlateH ,
						float PlateW ,float BoundaryDist[4],float PatternSpace);
void NormalDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg,float PatternRadius , 
					   float K , float C , int &overlapnumber , int &actualnumber ,float PlateH 
					   , float PlateW ,float BoundaryDist[4],float PatternSpace);
//void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
//						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
//						 , bool ReConstrct ,vector<int> &vec1 ,vector<int> &vec2 ,vector<int> &sortvec
//						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace);
//void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
//						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
//						 , bool ReConstrct ,deque<int> &vec1 ,deque<int> &vec2 ,deque<int> &sortvec
//						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace);
void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
						 , bool ReConstrct ,deque<int> *relationPt
						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace);
void VerifyPtInMeshIndex(Point3d &pt,MeshGrid *mg,int MeshSize,float PatternRadius);
//----計算圓在矩形內的面積用
bool CirclePatternAreaInRectangle(RectangleF Rec1 ,PointF PatternCenter ,float PatternRadius);
void CA1(double XPxx, double XPyy,double Cr, int k);
void CA2(double XPxx,double XPyy,double Cr, int k);
//-------------------------

//void IsolateBoundaryCondition(Point3d &pt,MeshGrid *mg,int MeshSize,long NR ,float PlateW ,float PlateH,float PatternRadius);




void CalculatePtNumberInMash(MeshGrid *mg,Point3d *pt,DataInput inputdata,long NR,bool &flagReCalActDen);

void BulidMeshRelation(MeshGrid *mg,DataInput inputdata,float VerlertFactor,deque<int> *relationMeshGrid);
void BuildPointMeshRelation(MeshGrid *mg,DataInput inputdata,float VerlertFactor, list<int> *PtNumber);

bool CalculateGridMeshDensity(int CurveType ,float PenPara , float &density ,float distance ,float Boundarydistance );

//四則運算-----------------------------------------------------
double power_2(double x);
void Cross(float &x ,float &y ,float &z , float vecA_x,  float vecA_y, float vecA_z,  float vecB_x,  float vecB_y, float vecB_z);

//排序
void Sort(array<PointF>^ Data); 

//Verlert 運算 (New)
//void VelertMode(Pattern^ Dot ,GridDensity^ Density ,Point GirdNumber,MainFormData^ maindata,float factor);
//PointF PointForceFastMode(Pattern^ Dot,int index1 ,int index2 ,MainFormData^ maindata,float properdistance,array<PointF>^ D_T_Curve);
PointF PointForce(Pattern^ Dot,PointF pt1 ,PointF pt2 ,MainFormData^ maindata,float properdistance);
PointF PointForce(Pattern^ Dot,PointF pt1 ,PointF pt2,float distance ,MainFormData^ maindata,float properdistance);
void MovePoint(Pattern^ Dot,MainFormData^ maindata,float time ,int &UnSelectPt);
//----------------20091226暫時關-------------------------------
//void BuildRelation(Pattern^ Dot,GridDensity^ Density,MainFormData^ maindata ,Point GirdNumber);
//void BuildDensityArrayData(Pattern^ Dot,GridDensity^ Density,Point GirdNumber ,array<array<int>^,2>^ PtIndex);
//void VelerttMode(Pattern^ Dot ,GridDensity^ Density,Point GirdNumber,MainFormData^ maindata ,array<array<int>^,2>^ PtIndex,float* maxForcePow2 ,int* UnSelectedPt , int* SmallGapNumber);

						













#endif