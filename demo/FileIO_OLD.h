#ifndef FileIO_OLD_h
#define FileIO_OLD_h

#include "DataStructure.h"
#include "Calculate.h"


using namespace Nurbs;
using namespace DensityClass;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Collections;






//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



bool OpenB_Spline_Curve(StreamReader ^ sr,Nurbs::B_Spline_Curve^ Curve);

//���ݶ}�ɨ禡
bool OpenParaFile_R1(StreamReader ^ sr,MainFormData^ formdata);




//�}�ұM����---Old Version
void OpenCLT_Characteristic_File(GridDensity^ tmpDensity,StreamReader ^ sr,DataInput &inputdata,bool &filenew);

//�}�ұM����---090112
bool OpenCLT_Characteristic_090112_File(StreamReader ^ sr,DataInput &inputdata,bool &filenew ,B_Spline_Surface^ Surface_Global_Design);

//�}�ұM����---R1��
bool OpenCLT_R1(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,ArrayList^ Localsurfacedata,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve);

//�}�_�~���ק�Ѽ� (Local Area �M HotBar)
bool OpenDetailModifyPara(StreamReader ^ sr,Cosmetic_Data^ Cosmetic_Data);
bool OpenDetailModifyPara(StreamReader ^ sr,ArrayList^ Localsurfacedata);
//�A�αM����---Old Version
MeshGrid *OpenDensityWithDimFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
bool OpenParaFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
bool OpenControllPt(StreamReader ^ sr,SmoothSurfaceInfo^ controllpt,DataInput inputdata);

//�A�αM����---090112
bool OpenB_Spline_Surface(StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design); //20090316 (�}�Ҧ��������)




#endif
