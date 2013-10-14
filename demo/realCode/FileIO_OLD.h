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

//附屬開檔函式
bool OpenParaFile_R1(StreamReader ^ sr,MainFormData^ formdata);




//開啟專案檔---Old Version
void OpenCLT_Characteristic_File(GridDensity^ tmpDensity,StreamReader ^ sr,DataInput &inputdata,bool &filenew);

//開啟專案檔---090112
bool OpenCLT_Characteristic_090112_File(StreamReader ^ sr,DataInput &inputdata,bool &filenew ,B_Spline_Surface^ Surface_Global_Design);

//開啟專案檔---R1版
bool OpenCLT_R1(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,ArrayList^ Localsurfacedata,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve);

//開起品味修改參數 (Local Area 和 HotBar)
bool OpenDetailModifyPara(StreamReader ^ sr,Cosmetic_Data^ Cosmetic_Data);
bool OpenDetailModifyPara(StreamReader ^ sr,ArrayList^ Localsurfacedata);
//適用專案檔---Old Version
MeshGrid *OpenDensityWithDimFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
bool OpenParaFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
bool OpenControllPt(StreamReader ^ sr,SmoothSurfaceInfo^ controllpt,DataInput inputdata);

//適用專案檔---090112
bool OpenB_Spline_Surface(StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design); //20090316 (開啟曲面表單資料)




#endif
