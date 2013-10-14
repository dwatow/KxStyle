#ifndef FileIO_h
#define FileIO_h

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
//V2 ���᪺�Ƶ{�� (�M����)---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool SaveCLT_V3(StreamWriter ^ sr,int MFversion ,MainFormData^ formdata,int GSversion ,Nurbs::B_Spline_Surface^ Surface_Global_Design,int LSversion ,ArrayList^ Localsurfacedata,int GCHversion ,B_Spline_Curve^ Curve_H,B_Spline_Curve^ Curve_V ,int ProjVersion,Project_Information^ ProjInformation,int HotSpotVersion ,ArrayList^ HotSpotData);
//�}�ұM����---V2��
bool OpenCLT_V3(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,ArrayList^ Localsurfacedata,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve,Project_Information^ ProjInformation,ArrayList^ HotSpotData);


bool SaveLocalAreaPara(String^ version, StreamWriter ^ sr,ArrayList^ Localsurfacedata);
bool SaveGlobalAreaPara(String^ version,StreamWriter ^ sr,B_Spline_Surface^ Surface_Global_Design);
bool SaveGlobalLinePara(String^ version,StreamWriter ^ sr,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve);
bool SaveLGPPara(String^ version,StreamWriter ^ sr,array<String^>^ LGPPara);
bool SaveMainformPara(String^ version,StreamWriter ^ sr,MainFormData^ formdata);
bool SaveProjInformation(String^ version,StreamWriter ^ sr,Project_Information^ ProjInformation);
bool SaveHotSpotData(String^ version,StreamWriter ^ sr,ArrayList^ HotSpotData);

bool LoadLocalAreaPara(array<String^>^ FileData,ArrayList^ Localsurfacedata);
bool LoadGlobalAreaPara(String^ version,StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design);
bool LoadGlobalLinePara(String^ version,StreamReader ^ sr,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve);
bool LoadLGPPara(String^ version,StreamReader ^ sr,array<String^>^ LGPPara);
bool LoadMainformPara(String^ version,StreamReader ^ sr ,MainFormData^ formdata);
bool LoadProjInformation(String^ version,StreamReader ^ sr,Project_Information^ ProjInformation);
bool LoadHotSpotData(String^ version,StreamReader ^ sr,ArrayList^ HotSpotData);



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//AutoCaD �����ɮ�---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool SavePatternFile(StreamWriter ^ sr,MainFormData^ formdata,Pattern^ dot,Cosmetic_Data^ cosmetic_Data,Project_Information^ project);
bool SavePatternFile(StreamWriter ^ sr,array<RectangleF>^ OutLine,int patternShape,Pattern^ dot,Cosmetic_Data^ cosmetic_Data);
void xSaveAutoCad_Rectangle(StreamWriter ^ sr ,RectangleF^ recF);
void xSaveAutoCad_Circle(StreamWriter ^ sr ,PointF Coor,float dia,float increaseRatio);
bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot,PointF^ Pitch,RectangleF^ LGP);
bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot);
bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot,RectangleF^ LGP_Dimension);
bool xOpenAutoCad_Rectangle(StreamReader ^ sr ,RectangleF^ recF); //�ȶ}�ҳ̤j���x��
bool xOpenAutoCad_Rectangle_NonR12(StreamReader ^ sr ,RectangleF^ recF ,int readIndex); //�}�ҫD R12��Dxf�ɮ�
void xSaveAutoCad_Mtext(StreamWriter ^ sr ,String^ TextContent,PointF Location ,float TextSize ,bool reverseText);
bool xOpenAutoCad_PolyLine(StreamReader ^ sr ,List<PointF>^ PolyLinePt); //�}��PolyLine





//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//LT  �����ɮ�---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool SaveLTPatternFile(StreamWriter ^ sr,Pattern^ dot,MainFormData^ formdata,SettingData^ x_SetData);

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// IJP �����ɮ�---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Save_IJP_PatternFile(StreamWriter ^ sr,array<float,2>^ IJP_DotSize ,int &totalNumber,float IJP_DPI);


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//�S�� Renew  ���Ѽ� : int FileKind ,String^ Version ,String^ InputFileName ,MemoryStream^ MemoryStream_DesignGridDensity ,MemoryStream^ MemoryStream_CurrentPattern

//void FileNew(Pattern^ tmpdot,GridDensity^ tmpDensity,Point &tmpGirdNumber,MainFormData^ tmpMainData,B_Spline_Surface^ tmpSurface_Global_Design);

//�x�s Pattern Data


//�x�sLT File



//�x�s�M���� V1��
//bool SaveCLT_Characteristic_File_V1(StreamWriter ^ sr,MainFormData^ formdata,Nurbs::B_Spline_Surface^ Surface_Global_Design);
//�x�s�M���� V2�� (�t�����ק�Ѽ�)
//bool SaveCLT_Characteristic_File_V2(StreamWriter ^ sr,MainFormData^ formdata,Nurbs::B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data);
//bool SaveCLT_Characteristic_File_V3(StreamWriter ^ sr,MainFormData^ formdata,Nurbs::B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data,B_Spline_Curve^ Curve_H,B_Spline_Curve^ Curve_V);

//�����x�s�l�禡


//bool SaveControllpt(StreamWriter ^ sr,SmoothSurfaceInfo^ controllpt);
//bool SaveB_Spline_Surface(StreamWriter ^ sr,Nurbs::B_Spline_Surface^ Surface_Global_Design); //20090316 (�x�s���������)

//bool SaveB_Spline_Curve(StreamWriter ^ sr,Nurbs::B_Spline_Curve^ Curve);
//bool OpenB_Spline_Curve(StreamReader ^ sr,Nurbs::B_Spline_Curve^ Curve);


//�x�s�~���ק�Ѽ� (Local Area �M HotBar)
//bool SaveDetailModifyPara(StreamWriter ^ sr,Cosmetic_Data^ Cosmetic_Data);

//bool SaveFormParaFile(StreamWriter ^ sr,MainFormData^ formdata);
//���ݶ}�ɨ禡
//bool OpenParaFile_R1(StreamReader ^ sr,MainFormData^ formdata);


//�}��AutoCad Pattern �ɮ�
//Point3d* OpenPatternFile(StreamReader ^ sr,long &NR);


//�}�ұM����---Old Version
//void OpenCLT_Characteristic_File(GridDensity^ tmpDensity,StreamReader ^ sr,DataInput &inputdata,bool &filenew);

//�}�ұM����---090112
//bool OpenCLT_Characteristic_090112_File(StreamReader ^ sr,DataInput &inputdata,bool &filenew ,B_Spline_Surface^ Surface_Global_Design);

//�}�ұM����---R1��
//bool OpenCLT_R1(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve);







//�}�_�~���ק�Ѽ� (Local Area �M HotBar)
//bool OpenDetailModifyPara(StreamReader ^ sr,Cosmetic_Data^ Cosmetic_Data);
//�A�αM����---Old Version
//MeshGrid *OpenDensityWithDimFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
//bool OpenParaFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew);
//bool OpenControllPt(StreamReader ^ sr,SmoothSurfaceInfo^ controllpt,DataInput inputdata);

//�A�αM����---090112
//bool OpenB_Spline_Surface(StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design); //20090316 (�}�Ҧ��������)




#endif
