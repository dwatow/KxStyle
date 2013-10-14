// PatternContruction.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "..\OtherSource\BaseDefinitions.h"
//#include "..\OtherSource\matrix.h"
#include "..\OtherSource\SimSeqs.h"
#include "DataStructure.h"
#include <deque>
#include <new>
#include <io.h>
#include <vector>

using namespace std;
using namespace PatternContruction;
using namespace System::Globalization;
using namespace System::Drawing::Drawing2D;


//Reg 用~~
using namespace Microsoft::Win32;



[STAThreadAttribute]
//[STAThreadAttribute]

//----------------------------------------------------------------------------------------------------
//Find功能 ,找出在網格內的B-SplineSurface點-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------









//-----------------------------------------------------------------------------------------------------
//計算Regular佈點Overlap 的數目------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
/*
void Form1::CalculateRegularPatternOverlapNumber(){

	//執行產生網點後檢查

	float size[2];
	int index = Form1::comboBoxRegularStyle->SelectedIndex;
	Mesh = inputdata.MeshNumber;		
	size[0] = inputdata.PlateWidth/(float)Mesh[0]; //單位寬度
	size[1] = inputdata.PlateHeight/(float)Mesh[1]; //單位長度
	float tmpminvalue =  min(size[0],size[1]); //網格大小,不是半徑
	int tmpOverlapCount = 0;
	for(int i = 0 ;i<NR ;i++){

		pt[i].Overlap = false; //初始網點狀態

		switch(index){
			case 0: //非錯排(矩形排列)
				if(pt[i].Radius > tmpminvalue/2  )	{					
					tmpOverlapCount++;					
					pt[i].Overlap = true;
				}
				break;
			case 1: //錯排
				if(inputdata.PatternShape == 0 && pt[i].Radius > tmpminvalue/1.414/2 ){ //圓形
					tmpOverlapCount++;	
					pt[i].Overlap = true;
				}else if(inputdata.PatternShape == 1 && pt[i].Radius > tmpminvalue/2) {  //矩形
					tmpOverlapCount++;
					pt[i].Overlap = true;
				}else if(inputdata.PatternShape == 2 && pt[i].Radius > tmpminvalue/2){  //菱形
					tmpOverlapCount++;
					pt[i].Overlap = true;
				}

				break;
		}
	}
	

	ShowOverlap->Text = "重疊網點數目 : " + Convert::ToString(tmpOverlapCount);


}
*/

//-------------------------------------------------------------------------------------------------------
//計算允許最大設計密度和最小設計密度---------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
/*
void Form1::CalculateMax_Min_AllowanceDensity(){
	float size[2];
	int index = Form1::comboBoxRegularStyle->SelectedIndex;
	Mesh = inputdata.MeshNumber;		
	size[0] = inputdata.PlateWidth/(float)Mesh[0]; //單位寬度
	size[1] = inputdata.PlateHeight/(float)Mesh[1]; //單位長度
	float tmpminvalue =  min(size[0],size[1]); //網格大小,不是半徑
	float maxden = 0,minden=0;

	switch(index){
		case 0: //非錯排(矩形排列)
			
			if(inputdata.PatternShape == 0){ //圓形				
				maxden = 3.1415926535*tmpminvalue*tmpminvalue /(4*size[0]*size[1]);
				minden = 3.1415926535* 0.025 *0.025/(size[0] *size[1]);
			}else if(inputdata.PatternShape == 1) {  //矩形
				maxden = tmpminvalue*tmpminvalue /(size[0]*size[1]);
				minden = 0.05*0.05/(size[0] *size[1]);
			}else{  //菱形
				maxden = tmpminvalue*tmpminvalue /(2*size[0]*size[1]);
				minden = 2* 0.025 *0.025/(size[0] *size[1]);
			}

			break;
		case 1: //錯牌			
			
			if(inputdata.PatternShape == 0){ //圓形
				maxden = 3.1415926535*tmpminvalue*tmpminvalue /(4*size[0]*size[1]);
				minden = 2*3.1415926535* 0.025 *0.025/(size[0] *size[1]);
			}else if(inputdata.PatternShape == 1) {  //矩形
				maxden = 2*tmpminvalue*tmpminvalue /(size[0]*size[1]);
				minden = 2*0.05*0.05/(size[0] *size[1]);
			}else{  //菱形
				maxden = 2*tmpminvalue*tmpminvalue /(2*size[0]*size[1]);;
				minden = 2*2* 0.025 *0.025/(size[0] *size[1]);
			}

			break;
	}

	


		
	
		lblInformation ->Text = "" ;

}
*/
//-------------------------------------------------------------------------------------------------------
//計算網格數目的功能(只有規則佈點有用)-------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
/*
void Form1::CalculateRegularMeshNumber(){


	

	//規則佈點之Grid數目設定
	if (radioBtnRegular->Checked == true) {
		int index = Form1::comboBoxRegularStyle->SelectedIndex;
		int pre_Mesh0 = inputdata.MeshNumber[0];
		int pre_Mesh1 = inputdata.MeshNumber[1];

		switch (index){
			case 0: //非錯排
				inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
				inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2;							
				break;
			case 1://45度-錯排
				if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //圓形和菱形
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2/1.414;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/1.414;  //45D					
				}
				else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // 矩形
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/2;
				}
				break;
			case 2://60度-錯排
				if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //圓形和菱形
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2/1.414;												
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/1.414/1.732;  //60D
				}
				else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // 矩形
					MessageBox::Show("目前矩形無60度錯排,將用45度錯排取代");
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/2;
				}
				break;

		}
		//防呆 (防止輸入為 0的情況後.計算密度會有問題發生)
		if (inputdata.PatternRadius == 0 || inputdata.PlateWidth == 0 || inputdata.PlateHeight == 0 ) {
			inputdata.MeshNumber[0] = 1;
			inputdata.MeshNumber[1] = 1;
		}


		//若網格數目改變 ,密度資料必須清除 ,故Reset ,且網點資料也要清除ResetPointData()
		if (pre_Mesh0 != inputdata.MeshNumber[0] || pre_Mesh1 != inputdata.MeshNumber[1])	{
			ResetMeshDate();
			ResetPointData();
		}
			
	}


}
*/

// -----------------------------------------------------------------------------------------------------
// 顯示與檢查功能 --------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

void Form1::ResetAll(){

	//沒有 Renew  的參數 : String^ Version ,String^ InputFileName 
// SettingForm ^ Set_Data_Form ,B_Spline_Curve^ Curve_Horizontal ,B_Spline_Curve^ Curve_Vertical 

			//網點相關
			
			// 規則佈點
			if(this->Dot != nullptr){
				delete this->Dot;
				this->Dot = nullptr;
				this->Dot = gcnew Pattern();
				//this->Dot->Initialize_me();		
			}

			// IJP佈點

			if(this->IJP_DotSize != nullptr){
				delete[] this->IJP_DotSize;

			}




			
			if(this->PatternDensity != nullptr)
				this->PatternDensity->ClearAll();


			//專案資訊
			if(this->project != nullptr){
				this->project->ClearAll();
			}
			
			
			this->GirdNumber = this->GirdNumber.Empty;
			//Main表單 參數
			if(this->MainData != nullptr){
				this->MainData->Initialize();
				this->UpdateMainFormData();
			}
			//Surface 參數
			if(this->Surface_Global_Design != nullptr) {
				
				delete this->Surface_Global_Design;
				this->Surface_Global_Design = nullptr;
				this->Surface_Global_Design = gcnew Nurbs::B_Spline_Surface();
				
				
			}
			

			//Curve 參數
			if(this->Curve_Horizontal != nullptr) {
				this->Curve_Horizontal = gcnew B_Spline_Curve();
				this->Curve_Horizontal->xInitialize(PointF(0,120),PointF(543,120));
			}
			if(this->Curve_Vertical != nullptr){
				this->Curve_Vertical = gcnew B_Spline_Curve();
				this->Curve_Vertical->xInitialize(PointF(0,120),PointF(543,120));
			}

			//LocalArea 參數,HotSpot 參數
			this->Cosmetic_LocalAreaData->Initialize();

			//局部修改參數
			if(this->localsurfacedata != nullptr)
				this->localsurfacedata->Clear();

			//HotSpot 參數修改
			if(this->HotSpotData != nullptr){
				this->HotSpotData->Clear();
			}


			//LGP修邊參數
			if( this->LGPPolyLinePt != nullptr)
				this->LGPPolyLinePt->Clear();



			//LT參數 
			this->Set_Data->Initialize_LT_Setting();

			
			//SurfaceDensity參數
			if (this->SurfacePatternDensity != nullptr)
				this->SurfacePatternDensity->ClearAll();

			//PatternDensity參數
			if (this->PatternDensity != nullptr)
				this->PatternDensity->ClearAll();
			
			delete this->Metafile_DesignGridDensity;
			this->Metafile_DesignGridDensity = nullptr;
			
			if(this->MemoryStream_DesignGridDensity != nullptr) this->MemoryStream_DesignGridDensity->Close();
				
			FileKind = -1;
			pictureBox1->Refresh();
			maxDen = 1000;

			
			//圖形化功能參數Reset 

			if(this->MainPicMatrix != nullptr) this->MainPicMatrix->Reset() ;
			//if (this->ObjectCoordinate != nullptr)  ;  -->還要找原因~~
			PicSacleVaule = 1.0f;
			if( this->Density_Bitmap != nullptr) {
				delete Density_Bitmap;
				Density_Bitmap = nullptr;
			}
			
			
			
	

		
			
			
			//訊息Reset

			this->lbl_DotPitch->Text = String::Format("網點 Pitch (X,Y) = ");	
			this->lbl_AllowMaxDen->Text =String::Format("允許最大密度  = " );
			this->lbl_AllowMinDen->Text = String::Format("允許最小密度  = " );		
			this->lblActualDensityRange->Text = String::Format("密度範圍  = " );
			this->lbl_Total_Num->Text =  String::Format("總網點數目  = " );		
			this->lbl_Current_File->Text = "專案檔名稱 : " ;
			this->lbl_Pattern_File->Text = "Pattern檔案名稱 :";
			Form1::Text ="CLT佈點程式 " + Version + " 目前路徑 : " ;
			this->lblavgDen->Text = "平均覆蓋率 : " ;
			this->lbl_MinPattern->Text = "最小網點(直徑) : ";
			this->lbl_MaxPattern->Text = "最大網點(直徑) : ";
			this->lblMinGap->Text = String::Format("(非擾動)規則佈點最小Gap : ");

		
			GC::Collect();
		
		
		   

}
void Form1::UpdateMainFormData(){

	this->txt_LGPLength->Text =  Convert::ToString(this->MainData->LGPInformation.Width) ;
	this->txt_LGPWidth->Text  =  Convert::ToString(this->MainData->LGPInformation.Height);
	this->txt_maxDot->Text    =  Convert::ToString(this->MainData->MaxDot);
	this->txt_MinDot->Text	  =  Convert::ToString(this->MainData->MinDot);
	this->txt_MinDotGap->Text =  Convert::ToString(this->MainData->MinDotGap);
	this->txt_RandomParaC->Text = Convert::ToString(this->MainData->Parameter_C);
	this->txt_RandomParaK->Text = Convert::ToString(this->MainData->Parameter_K);
	
	
	this->cboPatternArragementStyle->SelectedIndex = Convert::ToInt16(this->MainData->Pattern_Arrangment);
	this->comboBoxPatternShape->SelectedIndex = this->MainData->Pattern_Shape;

	if(this->MainData->DotType == 1) this->radioBtnRandom->Checked = true;
	else if(this->MainData->DotType == 0) this->radioBtnRegular->Checked = true;
	else if(this->MainData->DotType == 2)this->radioIJPBtn->Checked = true;
	else this->radio_FMPattern->Checked = true;

	this->txt_RandomDotSize->Text = Convert::ToString(this->MainData->RandomDotSize);
	this->txt_RandomDotGap->Text = Convert::ToString(this->MainData->RandomDotGap);
	this->txt_RandomDotIteration->Text = Convert::ToString(this->MainData->RandomDotIteration);
	this->cbo_RandomDotSimRule->SelectedIndex = this->MainData->RandomDotSimRule;

	//亂數新增參數
	this->txt_RandomCuttingForce->Text =  Convert::ToString(this->MainData->RandomStopForce);
	this->txt_RandomRebuildFrequency->Text =  Convert::ToString(this->MainData->RandomRebuildFrequency);
	this->chkRamdomStopForce->Checked =  (this->MainData->chkStopForce);
	this->chkRandomStopNumber->Checked = (this->MainData->chkStopNmber);

	//密度設計方式 (曲線或曲面)
	switch(this->MainData->DensityDesignMethod) {
		case 0:
			this->曲線調整均度ToolStripMenuItem->Checked = true;
			this->曲面調整均度ToolStripMenuItem->Checked = false;
			break;
		case 1:
			this->曲線調整均度ToolStripMenuItem->Checked = false;
			this->曲面調整均度ToolStripMenuItem->Checked = true;
			break;

	}

	//
	if(this->MainData->PitchDirection == -1){
		this->chkPitchSetting->Checked = false;
	}else{
		this->chkPitchSetting->Checked = true;
		this->cboPitchDirection->SelectedIndex = this->MainData->PitchDirection;
		this->txt_DesirePitch->Text = Convert::ToString(this->MainData->ActualPitchValue);
		
	}

	//20110907 IJP增加功能

	this->IJP_txt_DotSize->Text = Convert::ToString(this->MainData->IJP_DotSize);
	this->IJP_txt_BlockX->Text = Convert::ToString(this->MainData->IJP_BlockX);
	this->IJP_txt_BlockY->Text = Convert::ToString(this->MainData->IJP_BlockY);

	
	
						
	//20120319 UJP文字
	this->IJP_chk_TextEdit->Checked = this->MainData->IJP_chkTextEdit;
	this->IJP_cbo_TextLocation->SelectedIndex = this->MainData->IJP_TextLocation;
	this->IJP_txt_TextLocaX->Text = Convert::ToString(this->MainData->IJP_TextLocation_X);
	this->IJP_txt_TextLocaY->Text = Convert::ToString(this->MainData->IJP_TextLocation_Y);
	this->IJP_txt_TextHeight->Text = Convert::ToString(this->MainData->IJP_TextHeight);
	this->IJP_txt_TextLength->Text = Convert::ToString(this->MainData->IJP_TextLength);	
	this->IJP_txt_TEXT->Text = this->MainData->IJP_Text;





	//20120319 FM 亂數佈點
	this->txtFMPattern->Text = Convert::ToString(this->MainData->FM_DotSize);
	this->txtFMPatternGap->Text  = Convert::ToString(this->MainData->FM_MiniDotGap);
					
	if(this->CurrentDictionary != "")	Directory::SetCurrentDirectory(this->CurrentDictionary) ;

	//顯示目前作用中的檔案 :
	if(this->InputFileName == "")		
		this->lbl_Current_File->Text = "專案檔名稱 : " ;
	else
		this->lbl_Current_File->Text = "專案檔名稱 : " + this->InputFileName;
		

	//DXF檔案名稱  :
	this->lbl_Pattern_File->Text = "Pattern檔案名稱 :" + this->PatternName;

	//顯示Title :
	Form1::Text ="CLT佈點程式 " + Version + " 目前路徑 : "  + this->CurrentDictionary;







}



void Form1::CheckInsidePlate(Point3d &pt){
/*
	if(pt.X >= inputdata.Boundary_Left && pt.X <= (this->MainData->LGPDimension.X -inputdata.Boundary_Right-2*inputdata.PatternRadius) 
		&& pt.Y >=inputdata.Boundary_Up && pt.Y <= (this->MainData->LGPDimension.Y -inputdata.Boundary_Down-2*inputdata.PatternRadius)){
			pt.InsidePlateArea = true;
	}
	else{
		pt.InsidePlateArea = false;
	}
*/	

};

void Form1::CheckOverlap(int &OverlapNumber,float Pattern_Space,bool Verlert,deque<int> *relationPt){

/*
	OverlapNumber=0;
	float PatternRadius = inputdata.PatternRadius;
	if (Verlert == false){
		for(int i=0;i<NR;i++){		
			double px1,py1,pz1;
			pt[i].GetPointPosition(px1,py1,pz1);
			CheckInsidePlate(pt[i]);
			int pt1index = pt[i].GetMeshIndex();
			pt[i].Overlap = false;
			if (pt1index != -1){
				for(int j= 0;j<NR ;j++){
					if ( pt[j].GetMeshIndex() != -1){
						double px2,py2,pz2;				
						pt[j].GetPointPosition(px2,py2,pz2);
						double dx ,dy;
						dx =fabs(px1-px2);//*Width ;
						dy =fabs(py1-py2);//*Height ;						
						int pt2index = pt[j].GetMeshIndex();					
						if((i!=j) && (power_2(dx)+power_2(dy) < power_2(2*PatternRadius+Pattern_Space)) && pt1index != -1 && pt2index != -1 && !(dx==0 && dy ==0)){
							pt[i].Overlap = true;
							pt[j].Overlap = true;
							OverlapNumber ++;
							break;
						}

					}
			
				}
			}

		}
	}
	else{
		
		
		for(int i= 0; i<NR;i++){
			pt[i].Overlap = false;
		}
		for(int i= 0; i<NR;i++){
			CheckInsidePlate(pt[i]);
			for(int j =0 ;j< pt[i].RelationPtNumber ;j++){		
			//for(int j =0 ;j< relationPt[i].size() ;j++){									
				int index = relationPt[i].at(j);
				double dx,dy;
				dx = fabs(pt[i].X-pt[index].X);
				dy = fabs(pt[i].Y-pt[index].Y);
				
				if((i!=index) && (power_2(dx)+power_2(dy) < power_2(2*PatternRadius+Pattern_Space)) && !(dx==0 && dy ==0)){
					if (pt[i].Overlap == true &&  pt[index].Overlap == false ) OverlapNumber ++;
					else if(pt[i].Overlap == false &&  pt[index].Overlap == false ) OverlapNumber = OverlapNumber+2;
					else if(pt[i].Overlap == false &&  pt[index].Overlap == true ) OverlapNumber = OverlapNumber+1;
					pt[i].Overlap = true;
					pt[index].Overlap = true;
					
					
				}		
				
		
			};
			
		};
	}
*/
	

};

bool Form1::ProduceGridDensity_ByTwoCurve(){
// 20090304產生網格密度 _利用曲線產生網格密度

	
		//曲線調整均度
		B_Spline_Curve^ tmpCurve_Vertical = gcnew B_Spline_Curve() ;
		B_Spline_Curve^ tmpCurve_Horizontal = gcnew B_Spline_Curve();



		try{	

			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("網點會限制最小Gap為 : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
			}
			

			//this->Density = gcnew GridDensity(this->GirdNumber.X,this->GirdNumber.Y,this->Set_Data->Color_MaxDenValue,this->Set_Data->Color_MinDenValue,this->btn_ProducePattern);  20091226以前
			//this->Density = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);
			this->PatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);
			
			
			//Curve Vertical---------------------------------------------------------------------------
			PointF CurvePt(0.0f,0.0f);
			SizeF frameSize = SizeF(551,243);
			int tmpCount = this->Curve_Vertical->ControllPt->Count;

			tmpCurve_Vertical->Set_k_Value(tmpCount);

			for(int ii = 0 ; ii < tmpCount ; ii++){
				CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(this->Curve_Vertical->ControllPt->default[ii],frameSize,30,30,this->MainData->LGPInformation.Height,100);
				tmpCurve_Vertical->ControllPt->Add(CurvePt);
		
			}		
			Rectangle tmpBoundary(0,0,(int)this->MainData->LGPInformation.Height,100);


			float Dif_V = fabs(tmpCurve_Vertical->ControllPt->default[0].X -tmpCurve_Vertical->ControllPt->default[tmpCount-1].X );
			int resolution_V = (int)Math::Round(this->GirdNumber.Y*Dif_V/this->MainData->LGPInformation.Height);

			tmpCurve_Vertical->ReProduceCurve(resolution_V,tmpBoundary);

		
			//Curve Horizontal ------------------------------------------------------------------------
		//	PointF CurvePt(0.0f,0.0f);
		//	SizeF frameSize = SizeF(551,243);
			tmpCount = this->Curve_Horizontal->ControllPt->Count;

			tmpCurve_Horizontal->Set_k_Value(tmpCount);

			for(int ii = 0 ; ii < tmpCount ; ii++){
				CurvePt = TranslateFormula->Translate_Pt_From_Screen_To_BSplineCoordinate(this->Curve_Horizontal->ControllPt->default[ii],frameSize,30,30,this->MainData->LGPInformation.Width,100);
			
				tmpCurve_Horizontal->ControllPt->Add(CurvePt);
				
			}		
		
		//	tmpBoundary.X = 0 ;
		//	tmpBoundary.Y = 0 ;
			tmpBoundary.Width = (int)this->MainData->LGPInformation.Width;
		//	tmpBoundary.Height = 100;

			float Dif_H = fabs(tmpCurve_Horizontal->ControllPt->default[0].X -tmpCurve_Horizontal->ControllPt->default[tmpCount-1].X );
			int resolution_H =(int) Math::Round(this->GirdNumber.X*Dif_H/this->MainData->LGPInformation.Width);

	
			tmpCurve_Horizontal->ReProduceCurve(resolution_H,tmpBoundary);

			//--------------------------------------------------------------------------------------------------
			
			
		
			this->toolStripStatusLabel1->Text = "產生密度";
			this->statusStrip1->Update();

			array<float>^ Z_V = gcnew array<float>(this->GirdNumber.Y);
			for(int jj = 0 ; jj<this->GirdNumber.Y; jj++){		
					float tmpZ_V = tmpCurve_Vertical->GetCurve_Z_Value((jj+0.5f)*this->MainData->LGPInformation.Height/this->GirdNumber.Y,jj);												
					Z_V[jj] = tmpZ_V/100;
				}



			for(int ii = 0 ; ii < this->GirdNumber.X ; ii++) {
				
				float Z_H = tmpCurve_Horizontal->GetCurve_Z_Value((ii+0.5f)*this->MainData->LGPInformation.Width/this->GirdNumber.X,ii);
				float tmpDen ;


				for(int jj = 0 ; jj<this->GirdNumber.Y; jj++){
					
					tmpDen = Z_H*Z_V[jj];

					if(this->Set_Data->LimitDotSize == true){
						if(tmpDen >=this->maxDen) tmpDen = this->maxDen;
					}
						
					
				//	this->Density->SetDensity(tmpDen/100,ii,jj);  //20091226以前
					Point index(ii,jj);
				//	this->Density->SetDensityValue(tmpDen,index);
					this->PatternDensity->SetDensityValue(tmpDen/100,index);
												
				}
				this->toolStripProgressBar1->Value = 100*ii/(this->GirdNumber.X-1);
				this->statusStrip1->Update();
			}


			delete tmpCurve_Horizontal;
			delete tmpCurve_Vertical;

			

		}catch(...){
			MessageBox::Show("產生密度錯誤!!");
			return false;
		}

		return true;
			
			
					
			
				


		








}
/*
bool Form1::ProduceGridDensity_FromDot(Point GridNumber ,GridDensity^ density ,Pattern^ dot){
	//產生格點密度,由網點計算得知,網格數不可以太多,否則誤差會很大
//	density->xClearAll();  //20091226以前
	density->ClearAll();
	
	density->CreateGridDensity(GridNumber);
	//BuildRelation(dot,density,this->MainData ,GridNumber);







	return false ;


};
*/
 
bool Form1::ProduceGridDensity(){
// 20090304產生網格密度

	

		try{		
			

			
			this->PatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);
			

			

			float size[2];
			float pos[2];

			size[0] = this->MainData->LGPInformation.Width  /this->GirdNumber.X;
			size[1] = this->MainData->LGPInformation.Height  / this->GirdNumber.Y;

			int tmpX ,tmpY;
			
			float tmpZ_pre;


		
			Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface要 + 1
		//	Point Resolution(this->GirdNumber.X,this->GirdNumber.Y);

			this->Surface_Global_Design->ModifySurface_Resolution_Degree(Resolution);
			//this->Surface_Global_Design->ProduceSurface(this->GirdNumber.X+1,this->GirdNumber.Y+1);
			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "產生密度";
			this->statusStrip1->Update();

			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("網點會限制最小Gap為 : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
			}

			Point SurfaceResolution = this->Surface_Global_Design->GetSurfaceResolution();

			for(int ii = 0 ; ii < this->GirdNumber.X ; ii++) {
				for(int jj = 0 ; jj<this->GirdNumber.Y ; jj++){
					int tmpIndex;
					pos[0] = (ii)*size[0];
					pos[1] = (jj)*size[1];
					tmpIndex = ii*this->GirdNumber.Y+jj;
						//找出欲尋求點的邊界
						float targetX,targetY;

						targetX = (ii +0.5f)*size[0];
						targetY = (jj +0.5f)*size[1];
					

						
						tmpX = (int)((ii/(float)this->GirdNumber.X)*(SurfaceResolution.X-1)) ;
						tmpY = (int)((jj/(float)this->GirdNumber.Y)*(SurfaceResolution.Y-1)) ;
						tmpZ_pre = this->Surface_Global_Design->GetSurface_Z_Value(targetX,targetY,tmpX,tmpY);
					
						if(this->Set_Data->LimitDotSize == true){
							if(tmpZ_pre >=this->maxDen) tmpZ_pre = this->maxDen;
						}
					//	this->Density->SetDensity(tmpZ_pre/100,ii,jj);  //20091226以前

						  Point index(ii,jj);
					//	 this->Density->SetDensityValue(tmpZ_pre/100,index);
						 this->PatternDensity->SetDensityValue(tmpZ_pre/100,index);
					
				}
				this->toolStripProgressBar1->Value = 100*ii/(this->GirdNumber.X-1);
				this->statusStrip1->Update();
			}

			

		}catch(...){
			return false;
		}

		return true;
			
			
					
			
				


		








}

bool Form1::Produce_RandomPattern()
{

			
/*


		
		long DotNum = 0 ;
		float ratio = 0 ;

		for(int ii= 0 ;ii <this->GirdNumber.X ; ii++){
			for(int jj = 0 ;jj<this->GirdNumber.Y ;jj++){
				float den = 0;
			//	this->Density->GetDensity_Value(den,ii,jj);  //20091226以前
				Point index(ii,jj);
				den = this->Density->GetDensityValue(index);
				ratio = ratio + den;
			}
		}
		//平均覆蓋率
		ratio = ratio/(this->GirdNumber.X*this->GirdNumber.Y);

		DotNum = Math::Round(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height*ratio/(Math::PI*this->MainData->RandomDotSize*this->MainData->RandomDotSize/4));

		this->lbl_RandomTotalNum->Text = "總網點數 : " + Convert::ToString(DotNum) ;

		this->Dot->BuildPattern(DotNum);

		this->Dot->ModifyRate_HotSpot = gcnew array<float>(this->Dot->GetDotNumber());
		this->Dot->ModifyRate_LocalArea = gcnew array<float>(this->Dot->GetDotNumber());
		for(int ii = 0 ; ii <this->Dot->GetDotNumber() ; ii++){
			this->Dot->ModifyRate_HotSpot->SetValue(1.0f,ii);
			this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
		}

		this->Dot->Dot_Force = gcnew array<PointF>(this->Dot->GetDotNumber());

		
		
		toolStripStatusLabel1->Text = "亂數-讀取LDS";

		double buffer[3] ={0,0,0};
		long bases[3];
		long ReadPrime;
		ReadPrime = ReadPrimes(&bases[0], 3);
		if (ReadPrime == 0){
			MessageBox::Show("讀Prime檔案錯誤");
			return false;
		}
		LDSqBase*Numbers;
		Numbers=(LDSqBase*)new LDSqHalton(&bases[0], 3, DotNum, BGENAU, GENAU);


		//抓取LDS資料
		toolStripStatusLabel1->Text = "亂數-分佈LDS";

		//儲存LDS Z Value ,作為日後密度細分時使用
	//	List<PointF>^ ZValue = gcnew List<PointF>(0);
		array<PointF>^ ZValue = gcnew array<PointF>(DotNum);

		for (long i=0; i<DotNum; i++) {
			Numbers->NextElement(&buffer[0], 3);		
		//	pt[i-1].SetPointPosition(buffer[0],buffer[1],buffer[2]);
			PointF ptCood(buffer[0],buffer[1]);
		//	this->Dot->SetDotValue(ptCood,this->MainData->RandomDotSize,i);	
			this->Dot->Dot_Coordinate[i] = ptCood;
			this->Dot->Dot_Diameter[i] = this->MainData->RandomDotSize;

			PointF Z_index(buffer[2],i);
		//	ZValue->Add(Z_index);
			ZValue[i] = Z_index;
			
		}
		
	
		
	
		
		free(Numbers);

		//計算所有密度數值
		float tmp = 0;
		double totalDen = 0;
		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){				
			//	this->Density->GetDensity_Value(tmp,ii,jj);  20091226以前

				Point index(ii,jj);
				tmp = this->Density->GetDensityValue(index);
				totalDen = totalDen + tmp;				
			}
		}

		
		//產生密度區間
		array<PointF,2>^ RatioRange = gcnew array<PointF,2>(this->GirdNumber.X,this->GirdNumber.Y);

		 tmp = 0;
		float tmpDen = 0;
		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){
				
				//this->Density->GetDensity_Value(tmp,ii,jj);  20091226以前
				Point index(ii,jj);
				tmp = this->Density->GetDensityValue(index);

				PointF range(tmpDen/totalDen,0);
				tmpDen = tmpDen + tmp;
				range.Y = tmpDen/totalDen;
				
				if(ii == this->GirdNumber.X-1 && jj == this->GirdNumber.Y-1 ){
					range.Y = 1;
				}
				//RatioRange->SetValue(range,ii,jj);
				RatioRange[ii,jj] = range;
							
			}
		}


		toolStripStatusLabel1->Text = "亂數-對應資料";

		//建立對應資料
		this->Density->DotIndex = gcnew array<List<int>^,2>(this->GirdNumber.X,this->GirdNumber.Y);


		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){
				List<int>^ tempList = gcnew List<int>(0);
			//	this->Density->DotIndex->SetValue(tempList,ii,jj);
				this->Density->DotIndex[ii,jj] = tempList;

			}
		}

					
	
		int tmpIndexX =0  ,tmpIndexY = 0;	

		for(int ii = 0 ; ii <this->Dot->GetDotNumber(); ii++){

					
			PointF Range(0,0);
			PointF RangeR(0,0);
			PointF RangeL(0,0);
			int RangeIndex[2] ;
			RangeIndex[0] = 0;
			RangeIndex[1] = this->GirdNumber.X*this->GirdNumber.Y-1;
			int b = 0;
			int a = 0;
			// a = Math::DivRem(10,3,b); b是餘數
			//tmpIndexX = Math::DivRem(int(RangeIndex[0]+RangeIndex[1])/2,this->GirdNumber.Y,tmpIndexY);
			tmpIndexX = Math::DivRem(int(ZValue[ii].X*this->GirdNumber.X*this->GirdNumber.Y),this->GirdNumber.Y,tmpIndexY);

			do{
				Range = RatioRange[tmpIndexX,tmpIndexY];


				

				if(tmpIndexX+1 <= this->GirdNumber.X-1) {
					RangeR = RatioRange[tmpIndexX+1,tmpIndexY];
					if(ZValue[ii].X > RangeR.Y){
						tmpIndexX ++;
						Range = RatioRange[tmpIndexX,tmpIndexY];
					}
				}
				if(tmpIndexX-1 >= 0) {
					RangeL = RatioRange[tmpIndexX-1,tmpIndexY];
					if(ZValue[ii].X < RangeL.X){
						tmpIndexX --;	
						Range = RatioRange[tmpIndexX,tmpIndexY];
					}
				}

				
				

				if ( ZValue[ii].X < Range.X) {

					tmpIndexY -- ;
					if(tmpIndexY < 0){
						tmpIndexY = this->GirdNumber.Y-1;
						tmpIndexX --;
					}

					
				}else if( ZValue[ii].X  > Range.Y){

					tmpIndexY ++ ;
					if(tmpIndexY  > this->GirdNumber.Y-1){
						tmpIndexY = 0;
						tmpIndexX ++;
					}
					
				}
			
				
				



			}while (ZValue[ii].X <Range.X || ZValue[ii].X  > Range.Y);

			List<int>^	tempList = this->Density->DotIndex[tmpIndexX,tmpIndexY];
			tempList->Add(ZValue[ii].Y);


			this->toolStripProgressBar1->Value = 100*ii/(this->Dot->GetDotNumber() -1);
			this->statusStrip1->Update();
		
			

		}



					
		toolStripStatusLabel1->Text = "亂數-初始網點";

		
		//產生初使網點
		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){
				List<int>^ tempList; 
				tempList = this->Density->DotIndex[ii,jj];
				for(int kk = 0 ; kk<tempList->Count ;kk++){
					PointF cood ;
					float dia;
					this->Dot->GetDotValue(cood,dia,tempList->default[kk]);
			
					cood.X = ii*this->MainData->LGPInformation.Width/this->GirdNumber.X + cood.X*this->MainData->LGPInformation.Width/this->GirdNumber.X;
					cood.Y = jj*this->MainData->LGPInformation.Height/this->GirdNumber.Y + cood.Y*this->MainData->LGPInformation.Height/this->GirdNumber.Y;

					//this->Dot->SetDotValue(cood,dia,tempList->default[kk]);
					this->Dot->Dot_Coordinate[tempList->default[kk]] = cood;
			
				}
			}
			this->toolStripProgressBar1->Value = 100*ii/(this->GirdNumber.X -1);
			this->statusStrip1->Update();
		}

		

		//Verlet 計算
		
	
		array<array<int>^,2>^ PtIndex = gcnew array<array<int>^,2>(GirdNumber.X,GirdNumber.Y);

		//將List 轉換到Array
		BuildDensityArrayData(this->Dot,this->Density,this->GirdNumber , PtIndex);

		toolStripStatusLabel1->Text = "亂數-Verlet計算";

		float maxForcePow2 = 100.0f;
		int countNumber = 0;
		



//		for(int ii = 0 ;ii < this->MainData->RandomDotIteration ; ii ++){
		float v,iniforce = 0;
		while(this->MainData->chkStopForce == true || this->MainData->chkStopNmber == true ){

			if(countNumber >= this->MainData->RandomDotIteration && this->MainData->chkStopNmber == true) break;
			if(maxForcePow2 <= this->MainData->RandomStopForce && this->MainData->chkStopForce == true ) break;
			
			int UnselectPt = 0,SmallGapNumber = 0;	

			VelerttMode( this->Dot ,this->Density,this->GirdNumber,this->MainData, PtIndex,&maxForcePow2,&UnselectPt,&SmallGapNumber);

			int a ,b = 0;
			b = Math::DivRem(countNumber,this->MainData->RandomRebuildFrequency,a);
			if (a == 0 && b != 0){
				BuildRelation(this->Dot,this->Density,this->MainData ,this->GirdNumber);
				BuildDensityArrayData(this->Dot,this->Density,GirdNumber , PtIndex);
				
			}
			countNumber ++ ;
			this->lbl_RandomIteration->Text = "疊代次數 : " + Convert::ToString(countNumber);
			this->lbl_AverageForce->Text = "平均作用力 : " + Convert::ToString(maxForcePow2);
			this->lbl_RandomTotalNum->Text = "總網點數 : " + Convert::ToString(DotNum-UnselectPt );
			this->lbl_SmallGapNumber->Text = "小於Gap網點對 :" + Convert::ToString(SmallGapNumber );


			
			if(countNumber == 1) iniforce = maxForcePow2;
			float tmpvalue = 100 *fabs(iniforce -maxForcePow2 )/fabs(iniforce- this->MainData->RandomStopForce);

	//		if( this->MainData->chkStopForce == true && this->MainData->chkStopNmber == true){
	//			v = Math::Max((float)100*countNumber/(this->MainData->RandomDotIteration),tmpvalue);
	//		}else if(this->MainData->chkStopForce == true){
	//			v = tmpvalue;
	//		}else if (this->MainData->chkStopNmber == true){
	//			v =  100*countNumber/(this->MainData->RandomDotIteration);
	//		}

			v =  100*countNumber/(this->MainData->RandomDotIteration);

			this->toolStripProgressBar1->Value = (int)v;

			this->statusStrip1->Update();
		
			

		


		}

		bool success = false;
		success = this->Dot->BuildOri_DotDia();



		
		return true;
		

*/
	return true;
	

}

void Form1::SetDensityColor(float &density ,float &R ,float &G ,float &B){

	
	if (density > 1) density = 1;
	if (density < 0) density = 0;
	
	float tempvalue = density*400+380;
	//float R,G,B;
	float Gamma =  0.8f;
    float IntensityMax = 255;
	float factor;
	
	if (tempvalue >= 380 && tempvalue < 440){
		R = -(tempvalue - 440) / (440 - 380);
        G = 0.0;
        B = 1.0;
	
	}else if(tempvalue >= 440 && tempvalue < 490){
		R = 0.0;
        G = (tempvalue - 440) / (490 - 440);
        B = 1.0;
	
	}else if(tempvalue >= 490 && tempvalue < 510){
		R = 0.0;
        G = 1.0;
        B = -(tempvalue - 510) / (510 - 490);
	}else if(tempvalue >= 510 && tempvalue < 580){
		R = (tempvalue - 510) / (580 - 510);
        G = 1.0;
        B = 0.0;
	}else if(tempvalue >= 580 && tempvalue < 645){
		R = 1.0;
        G = -(tempvalue - 645) / (645 - 580);
        B = 0.0;

	}else if(tempvalue >= 645 && tempvalue <= 780){

		R = 1.0;
        G = (tempvalue - 645) / (780 - 645);
        B = (tempvalue - 645) / (780 - 645);
		Gamma = 1;

	}else{
		R = 1.0;
        G = 1.0;
        B = 1.0;
	};

	if (tempvalue >= 380 && tempvalue <= 420){
		factor = 0.3f + 0.7f*(tempvalue - 380) / (420 - 380);
	}else if(tempvalue >= 420 && tempvalue <= 700){
		factor = 1.0;
	}else{
		factor = 1.0;
		 //factor = 0.3 + 0.7*(780 - tempvalue) / (780 - 700);
	};


	
	R = (IntensityMax * (float)Math::Pow(R * factor, Gamma));
	G = (IntensityMax * (float)Math::Pow(G * factor, Gamma));
	B = (IntensityMax * (float)Math::Pow(B * factor, Gamma));

}

bool Form1::Produce_RegularPattern(Pattern^ tmpDot,Point tmpGridNumber , RectangleF tmpLGPSize ,int tmpPatternArrangeMent ,GridDensity^ tmpDensity)
{
	
	float size[2];

	//輸入參數 : 
	// GirdNumber,LGPInformation     --> 主要是要得到座標
	// Pattern_Arrangment , SurfacePatternDensity--> 排列方式和密度產生對應的直徑

	//產出數值
	//  array<PointF>^ Dot_Coordinate --> OK
	//	array<float>^ Dot_Diameter --> OK;	
	//	array<Point,2>^ DotDensity_Index -->OK;
	

	//未產出的數值
	//	array<float>^ ModifyRate_HotSpot --> NA;
	//	array<float>^ ModifyRate_LocalArea --> NA;
	//	array<PointF>^ Dot_Force --> NA;
	//	array<float>^ MuraValue --> NA;

	


	
	
	
	
//	if (radioBtnRegular->Checked == true) {
		


		
		
		size[0] = tmpLGPSize.Width /tmpGridNumber.X; //單位寬度
		size[1] = tmpLGPSize.Height /tmpGridNumber.Y; //單位長度
		//float tmpminvalue =  min(size[0],size[1]);
		float den = 0 ,maxden = 0 ,minden = 0;

		int tmpcount = 0;
		
		tmpDot->BuildRegularPattern(tmpGridNumber.X,tmpGridNumber.Y,tmpPatternArrangeMent);


	
	
		
		tmpDot->DotDensity_Index = gcnew array<Point,2>(4,tmpDot->GetDotNumber());
		
		


		switch(tmpPatternArrangeMent){

			

			case 0: //非錯排(矩形排列)
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						
						float dot_dia = 0;


						//設定半徑
						float tempDen = 0 ;
					
						Point index(ii,jj);
				
						//tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;


						int tmpIndex = ii*tmpGridNumber.Y +jj ;
						if(this->MainData->Pattern_Shape == 0){ //圓形						
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形							
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 4.0f);
						}

						//設定位置
						PointF dot_coor((ii+0.5f)*size[0],(jj+0.5f)*size[1]);
						Point dot_Location(ii,jj);
						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);
						Point tmpDenIndex(ii,jj);
						for(int kk = 0 ;kk<4 ;kk ++){
							tmpDot->DotDensity_Index->SetValue(tmpDenIndex,kk,tmpIndex);
						}

					}

					this->toolStripProgressBar1->Value = 100*ii/(tmpGridNumber.X-1);
					this->statusStrip1->Update();
				}

			

				break;
				case 1  : // 45,60度錯牌
				//網格上的網點大小
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//設定半徑
						float dot_dia = 0;
						float tempDen = 0 ;
						

						

						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;


						int tmpIndex = ii*this->GirdNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形							
							float dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//設定位置
						
						PointF dot_coor((ii+0.5f)*size[0],(jj+0.5f)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);
					
						
						

						Point tmpDenIndex(ii,jj);
						for(int kk = 0 ;kk<4 ;kk ++){
							tmpDot->DotDensity_Index->SetValue(tmpDenIndex,kk,tmpIndex);
						}


					}
					this->toolStripProgressBar1->Value = 50*ii/(tmpGridNumber.X-1);
					this->statusStrip1->Update();
				}
				
				//網格間的網格大小

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//設定半徑
						
						
						float tempDen = 0;
						float tmp1 ,tmp2 ,tmp3 ,tmp4;
					
						Point index(ii,jj);
					
					//	tmp1 = this->PatternDensity->GetDensityValue(index);
						tmp1 = tmpDensity->GetDensityValue(index)/100;
						index.X = ii+1;											
					//	tmp2 = this->PatternDensity->GetDensityValue(index);
						tmp2 = tmpDensity->GetDensityValue(index)/100;
						index.Y = jj+1;						
					//	tmp3 = this->PatternDensity->GetDensityValue(index);
						tmp3 = tmpDensity->GetDensityValue(index)/100;
						index.X = ii;						
					//	tmp4 = this->PatternDensity->GetDensityValue(index);
						tmp4 = tmpDensity->GetDensityValue(index)/100;
						tempDen = (tmp1+tmp2+tmp3+tmp4)/4;
						
						



						float dot_dia = 0;


						int tmpIndex = tmpGridNumber.X*tmpGridNumber.Y + ii*(tmpGridNumber.Y-1) +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形							
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形							
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}



						PointF dot_coor((ii+1)*size[0],(jj+1)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);
						Point tmpDenIndex1(ii,jj),tmpDenIndex2(ii+1,jj),tmpDenIndex3(ii+1,jj+1),tmpDenIndex4(ii,jj+1);
										
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex1,0,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex2,1,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex3,2,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex4,3,tmpIndex);
						


					}
					this->toolStripProgressBar1->Value = 50+ 50*ii/(tmpGridNumber.X-2);
					this->statusStrip1->Update();
				}


			

				break;
			case 2 : // 45,60度錯牌



				//網格上的網點大小
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//設定半徑
						float dot_dia = 0;
						float tempDen = 0 ;
						
						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;



						int tmpIndex = ii*this->GirdNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形
							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形
							
							float dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}


						PointF dot_coor((ii+0.5f)*size[0],(jj+0.5f)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);


						Point tmpDenIndex(ii,jj);
						for(int kk = 0 ;kk<4 ;kk ++){
							tmpDot->DotDensity_Index->SetValue(tmpDenIndex,kk,tmpIndex);
						}


					}
					this->toolStripProgressBar1->Value = 50*ii/(tmpGridNumber.X-1);
					this->statusStrip1->Update();
				}
				
				//網格間的網格大小

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//設定半徑
						
							
						
						
						float tempDen = 0;
						float tmp1 ,tmp2 ,tmp3 ,tmp4;
				
						Point index(ii,jj);
					
					//	tmp1 = this->PatternDensity->GetDensityValue(index);
						tmp1 = tmpDensity->GetDensityValue(index)/100;




				
						index.X = ii+1;						
					
					//	tmp2 = this->PatternDensity->GetDensityValue(index);
						tmp2 = tmpDensity->GetDensityValue(index)/100;

					
						index.Y = jj+1;	
					
					//	tmp3 = this->PatternDensity->GetDensityValue(index);
						tmp3 = tmpDensity->GetDensityValue(index)/100;

				
						index.X = ii;	
					
					//	tmp4 = this->PatternDensity->GetDensityValue(index);
						tmp4 = tmpDensity->GetDensityValue(index)/100;

						
						tempDen = (tmp1+tmp2+tmp3+tmp4)/4;
						




/*
						float tempDen = 0;
						float tmp1 ,tmp2 ,tmp3 ,tmp4;
						this->Density->GetDensity_Value(tmp1,ii,jj);
						this->Density->GetDensity_Value(tmp2,ii+1,jj);
						this->Density->GetDensity_Value(tmp3,ii+1,jj+1);
						this->Density->GetDensity_Value(tmp4,ii,jj+1);

						
						tempDen = (tmp1+tmp2+tmp3+tmp4)/4;

*/

						float dot_dia = 0;


						int tmpIndex = tmpGridNumber.X*tmpGridNumber.Y + ii*(tmpGridNumber.Y-1) +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 8.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//設定位置
						//PointF tmpPos((ii+1)*size[0],(jj+1)*size[1]);
						//pt[tmpIndex].SetPointPosition(tmpPos.X,tmpPos.Y,0);

						PointF dot_coor((ii+1)*size[0],(jj+1)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);
				//		tmpDot->SetDotLocation(tmpIndex,dot_Location,false);


						Point tmpDenIndex1(ii,jj),tmpDenIndex2(ii+1,jj),tmpDenIndex3(ii+1,jj+1),tmpDenIndex4(ii,jj+1);
										
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex1,0,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex2,1,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex3,2,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex4,3,tmpIndex);


					}
					this->toolStripProgressBar1->Value = 50+ 50*ii/(tmpGridNumber.X-2);
					this->statusStrip1->Update();
				}
				break;
				case 3: //30 度錯牌

					//網格上的網點大小
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//設定半徑
						float dot_dia = 0;
						float tempDen = 0 ;
						
						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;

						int tmpIndex = ii*tmpGridNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形
							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形
							
							float dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}


						PointF dot_coor((ii+0.5f)*size[0],(jj+0.5f)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);


						Point tmpDenIndex(ii,jj);
						for(int kk = 0 ;kk<4 ;kk ++){
							tmpDot->DotDensity_Index->SetValue(tmpDenIndex,kk,tmpIndex);
						}


					}
					this->toolStripProgressBar1->Value = 50*ii/(tmpGridNumber.X-1);
					this->statusStrip1->Update();
				}
				
				//網格間的網格大小

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//設定半徑
						
							
						
						
						float tempDen = 0;
						float tmp1 ,tmp2 ,tmp3 ,tmp4;
				
						Point index(ii,jj);
					
						//tmp1 = this->PatternDensity->GetDensityValue(index);
						tmp1 = tmpDensity->GetDensityValue(index)/100;


				
						index.X = ii+1;						
					
						//tmp2 = this->PatternDensity->GetDensityValue(index);
						tmp2 = tmpDensity->GetDensityValue(index)/100;

					
						index.Y = jj+1;	
					
						//tmp3 = this->PatternDensity->GetDensityValue(index);
						tmp3 = tmpDensity->GetDensityValue(index)/100;

				
						index.X = ii;	
					
						//tmp4 = this->PatternDensity->GetDensityValue(index);
						tmp4 = tmpDensity->GetDensityValue(index)/100;

						
						tempDen = (tmp1+tmp2+tmp3+tmp4)/4;
						




/*
						float tempDen = 0;
						float tmp1 ,tmp2 ,tmp3 ,tmp4;
						this->Density->GetDensity_Value(tmp1,ii,jj);
						this->Density->GetDensity_Value(tmp2,ii+1,jj);
						this->Density->GetDensity_Value(tmp3,ii+1,jj+1);
						this->Density->GetDensity_Value(tmp4,ii,jj+1);

						
						tempDen = (tmp1+tmp2+tmp3+tmp4)/4;

*/

						float dot_dia = 0;


						int tmpIndex = tmpGridNumber.X*tmpGridNumber.Y + ii*(tmpGridNumber.Y-1) +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //圓形
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //矩形
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 8.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//設定位置
						//PointF tmpPos((ii+1)*size[0],(jj+1)*size[1]);
						//pt[tmpIndex].SetPointPosition(tmpPos.X,tmpPos.Y,0);

						PointF dot_coor((ii+1)*size[0],(jj+1)*size[1]);
						Point dot_Location(ii,jj);

						tmpDot->SetDotValue(dot_coor,dot_dia,tmpIndex);
				//		tmpDot->SetDotLocation(tmpIndex,dot_Location,false);


						Point tmpDenIndex1(ii,jj),tmpDenIndex2(ii+1,jj),tmpDenIndex3(ii+1,jj+1),tmpDenIndex4(ii,jj+1);
										
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex1,0,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex2,1,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex3,2,tmpIndex);
						tmpDot->DotDensity_Index->SetValue(tmpDenIndex4,3,tmpIndex);


					}
					this->toolStripProgressBar1->Value = 50+ 50*ii/(tmpGridNumber.X-2);
					this->statusStrip1->Update();
				}





		}

		

			
	/*	
		bool success = false;
		success = tmpDot->BuildOri_DotDia();
	*/	
		




	//}
	return true;

}			

/*
void Form1::ViewDraw(Graphics^ g){


	
	float PicWidth = Form1::pictureBox1->Size.Width;  //ScreenSize
	float PicHeight= Form1::pictureBox1->Size.Height;  //ScreenSize
	float PlateH = inputdata.PlateHeight;
	float PlateW = inputdata.PlateWidth;
	float PatternRadius = inputdata.PatternRadius;
	array<float,1>^buffer = gcnew array<float>(9);		
	buffer = g->Transform->Elements;
	float tmpscale = Convert::ToSingle(buffer->GetValue(0));
	float tmpscaleY = Convert::ToSingle(buffer->GetValue(3));
	float tmpTranslateX = Convert::ToSingle(buffer->GetValue(4));
	float tmpTranslateY = Convert::ToSingle(buffer->GetValue(5));
	delete[] buffer;

	
	

	
	Pen^ DrawSkyBluePen = gcnew Pen( Color::DeepSkyBlue,0.01/25.4 );
	Pen^ DrawDarkRedPen = gcnew Pen( Color::DarkRed,1/tmpscale );


	//重畫 實際密度
//	if(drawinfomation->RedrawActualDensity){	
		if (radioBtnRegular->Checked == true) {
			if(ShowActualResultDensityToolStripMenuItem->Checked == true && inputdata.MeshNumber[0]*inputdata.MeshNumber[1] > 0 && pt != nullptr && mg != nullptr){
				SolidBrush^ Brush = gcnew SolidBrush(Color::Purple );
				for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){	
					float *pos ,*size , actualDensity = 0;
					float R=0,G=0,B=0;
					size = mg[i].GetMeshSize();
					pos  = mg[i].GetMeshPosition(); 
					if (inputdata.PatternShape == 0){ //圓形
						actualDensity = 3.1415926535 *pt[mg[i].PtNumbers].Radius*pt[mg[i].PtNumbers].Radius/(size[0]*size[1]);
					}else if (inputdata.PatternShape == 1){ //矩形
						actualDensity = 4* pt[mg[i].PtNumbers].Radius*pt[mg[i].PtNumbers].Radius/(size[0]*size[1]);
					}else { //菱形
						actualDensity = 2* pt[mg[i].PtNumbers].Radius*pt[mg[i].PtNumbers].Radius/(size[0]*size[1]);
					}
					SetDensityColor(actualDensity,R,G,B);			
					Brush->Color = Color::FromArgb(R,G,B);
					g->FillRectangle(Brush,pos[0]-PlateW/2,pos[1]-PlateH/2,size[0],size[1]);
					
				};
				delete Brush;
			}
//		}else{
			if(ShowActualResultDensityToolStripMenuItem->Checked == true && inputdata.MeshNumber[0]*inputdata.MeshNumber[1] > 0 && pt != nullptr && mg != nullptr){
				if (flagReCalActDen == true) CalculatePtNumberInMash(mg,pt,inputdata,NR,flagReCalActDen);			
				SolidBrush^ Brush = gcnew SolidBrush(Color::Purple );
				for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){	
					float *pos ,*size , actualDensity = 0;
					float R=0,G=0,B=0;
					size = mg[i].GetMeshSize();
					pos  = mg[i].GetMeshPosition();
					actualDensity = 4*mg[i].PtNumbers*inputdata.PatternRadius*inputdata.PatternRadius/size[0]/size[1];
					SetDensityColor(actualDensity,R,G,B);			
					Brush->Color = Color::FromArgb(R,G,B);
					g->FillRectangle(Brush,pos[0]-PlateW/2,pos[1]-PlateH/2,size[0],size[1]);
					
				};
				delete Brush;
			};
		}
//	}

	//重劃 設計密度
//	if(drawinfomation->RedrawDesignDensity){
	
	    if (ShowDesignDensityToolStripMenuItem->Checked == true && mg != nullptr){

		//	if (DesignDensity_Bmp == nullptr){
				//DesignDensity_Bmp = gcnew Bitmap(this->pictureBox1->Size.Width,this->pictureBox1->Size.Height);
			//	DesignDensity_Bmp = gcnew Bitmap(inputdata.PlateWidth,inputdata.PlateHeight);
				Graphics ^tmp_g=Graphics::FromImage(DesignDensity_Bmp);
				SolidBrush^ Brush = gcnew SolidBrush( Color::Purple);	
				for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){
					float *pos ,*size;
					pos  = mg[i].GetMeshPosition();
					size = mg[i].GetMeshSize();				
					Brush->Color = Color::FromArgb(mg[i].Color_R,mg[i].Color_G,mg[i].Color_B);
					tmp_g->FillRectangle(Brush,pos[0]-PlateW/2,pos[1]-PlateH/2,size[0],size[1]);	
				}
				delete Brush;
				delete tmp_g;
			//}
			
		//	g->DrawImage(DesignDensity_Bmp,PointF(0,0));
			
		


		//20080806以前---------------------------------------------------------

		//	SolidBrush^ Brush = gcnew SolidBrush( Color::Purple);	
		//	for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){
		//		float *pos ,*size;
		//		pos  = mg[i].GetMeshPosition();
		//		size = mg[i].GetMeshSize();				
		//		Brush->Color = Color::FromArgb(mg[i].Color_R,mg[i].Color_G,mg[i].Color_B);
		//		g->FillRectangle(Brush,pos[0]-PlateW/2,pos[1]-PlateH/2,size[0],size[1]);	
		//	}
		//	delete Brush;

		//---------------------------------------------------------------------------

		}

//	}
	//重畫 網格
//	if (drawinfomation->RedrawMesh){
	//	drawinfomation->RedrawMesh = false;
		if( inputdata.MeshNumber[0]*inputdata.MeshNumber[1] > 0){

			if (mg != nullptr){
				for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){
					float *pos ,*size;
					pos  = mg[i].GetMeshPosition();
					size = mg[i].GetMeshSize();
					g->DrawRectangle(gcnew Pen( Color::Silver,1/tmpscale),pos[0]-PlateW/2,pos[1]-PlateH/2,size[0],size[1]);
					
				}

			}

		}
//	}

	//重畫 原始 Pattern
//	if(drawinfomation->RedrawOriPattern){
	//	drawinfomation->RedrawOriPattern = false;
		for(int i=1;i<=NR;i++){			
			if (X != nullptr && Y != nullptr  && ((X[i-1]-PlateW/2)*tmpscale+tmpTranslateX < PicWidth) && ((Y[i-1]-PlateH/2)*tmpscaleY+tmpTranslateY < PicHeight)){
				switch(inputdata.PatternShape){
					case 0: //圓形						
						g->DrawEllipse(DrawDarkRedPen,float(X[i-1])-PlateW/2,float(Y[i-1])-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));	
						break;
					case 1: //矩形						
						g->DrawRectangle(DrawDarkRedPen,float(X[i-1])-PlateW/2,float(Y[i-1])-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));
						break;
					case 2:	//菱形							
						PointF point1 = PointF(X[i-1]+PatternRadius-PlateW/2,Y[i-1]-PlateH/2);
						PointF point2 = PointF(X[i-1]+2*PatternRadius-PlateW/2,Y[i-1]+PatternRadius-PlateH/2);
						PointF point3 = PointF(X[i-1]+PatternRadius-PlateW/2,Y[i-1]+2*PatternRadius-PlateH/2);
						PointF point4 = PointF(X[i-1]-PlateW/2,Y[i-1]+PatternRadius-PlateH/2);
					    array<PointF>^ curvePoints = {point1,point2,point3,point4};
						g->DrawPolygon( DrawDarkRedPen, curvePoints );
						break;
				};
							
			};
			
		};

//	}
	//重畫 Pattern
//	if(drawinfomation->RedrawPattern){
	//	drawinfomation->RedrawPattern = false;

//-----20080806以後--------------------------------------------------------------------------------------------------
		if(PatternLocation_Bmp == nullptr){
			if(this->ShowCurrentPatternToolStripMenuItem->Checked == true && NR>0) {
			//	PatternLocation_Bmp = gcnew Bitmap(this->pictureBox1->Size.Width,this->pictureBox1->Size.Height);
			//	PatternLocation_Bmp = gcnew Bitmap(900,900);
				PatternLocation_Bmp = gcnew Bitmap(inputdata.PlateWidth*10,inputdata.PlateHeight*10);
		//----Resulotion 影響到的是畫面的品質和圖面大小無關
				PatternLocation_Bmp->SetResolution(this->pictureBox1->Size.Width*25.4/inputdata.PlateWidth*ViewScale,this->pictureBox1->Size.Height*25.4/inputdata.PlateHeight*ViewScale);
			//	PatternLocation_Bmp->SetResolution(10,10);
				
			
		
				Graphics ^tmp_g=Graphics::FromImage(PatternLocation_Bmp) ;	
			
			tmp_g->PageUnit = GraphicsUnit::Millimeter;
		//		MessageBox::Show(Convert::ToString(tmp_g->DpiX::get()));
				tmp_g->Clip= gcnew System::Drawing::Region( Rectangle(0,0,inputdata.PlateWidth,inputdata.PlateHeight) );
				float tmpScale;
			//	if (this->pictureBox1->Size.Width/inputdata.PlateWidth > this->pictureBox1->Size.Height/inputdata.PlateHeight)
			//			tmpScale = this->pictureBox1->Size.Height/inputdata.PlateHeight;
			//	else
			//			tmpScale =	this->pictureBox1->Size.Width/inputdata.PlateWidth;
			//	tmp_g->PageScale::set(ViewScale);
				//tmp_g->ScaleTransform(tmpScale*0.9,tmpScale*0.9);
				for(int i=1;i<=NR;i++){
					double px,py,pz;
						if (pt != nullptr) {
							pt[i-1].GetPointPosition(px,py,pz);	
							if ((pt[i-1].InsidePlateArea == true)  && ((px-PlateW/2)*tmpscale+tmpTranslateX < PicWidth) && ((py-PlateH/2)*tmpscaleY+tmpTranslateY < PicHeight)){
								switch(inputdata.PatternShape){
									case 0:  //圓形
									tmp_g->DrawEllipse(DrawSkyBluePen,float(px),float(py),float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));														
								break;
									case 1:	 //矩形
									tmp_g->DrawRectangle(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));								
								break;
									case 2:	 //菱形	
									PointF point1 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)-PlateH/2);
									PointF point2 = PointF(float(px)+2*pt[i-1].Radius-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);
									PointF point3 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)+2*pt[i-1].Radius-PlateH/2);
									PointF point4 = PointF(float(px)-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);				
									array<PointF>^ curvePoints = {point1,point2,point3,point4};
									tmp_g->DrawPolygon( DrawSkyBluePen, curvePoints);							
								break;
							};					
						};
					}						
				};

				delete  tmp_g;
				PatternLocation_Bmp->Save("testPattern");
			//	g->DrawImage(PatternLocation_Bmp,PointF(0,0));
			}

		}


//-------20080806以前--------------------------------------------------------------------------------------------------
//		if (NR != 0){		
//			g->DrawRectangle(gcnew Pen( Color::White,1/tmpscale),float(0)-PlateW/2,float(0)-PlateH/2,float(PlateW),float(PlateH));			
//		}
//		for(int i=1;i<=NR;i++){
//			double px,py,pz;
//			if (pt != nullptr) {
//				pt[i-1].GetPointPosition(px,py,pz);	
//				if ((pt[i-1].InsidePlateArea == true) &&(Form1::ShowCurrentPatternToolStripMenuItem->Checked == true) && ((px-PlateW/2)*tmpscale+tmpTranslateX < PicWidth) && ((py-PlateH/2)*tmpscaleY+tmpTranslateY < PicHeight)){
//					switch(inputdata.PatternShape){
//						case 0:  //圓形
//							g->DrawEllipse(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
//													
//							break;
//						case 1:	 //矩形
//							g->DrawRectangle(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
//							
//							break;
//						case 2:	 //菱形	
//							PointF point1 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)-PlateH/2);
//							PointF point2 = PointF(float(px)+2*pt[i-1].Radius-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);
//							PointF point3 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)+2*pt[i-1].Radius-PlateH/2);
//							PointF point4 = PointF(float(px)-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);
//							
//
//				
//							array<PointF>^ curvePoints = {point1,point2,point3,point4};
//							g->DrawPolygon( DrawSkyBluePen, curvePoints );							
//							break;
//
//					};
//					
//				};
//			}
//						
//		};
//----------------------------------------------------------------------------------------------------------------------

//	}
	//重畫 不適合網點
//	if(drawinfomation->RedrawUnSuitablePattern){
	//	drawinfomation->RedrawUnSuitablePattern = false;
		for(int i=1;i<=NR;i++){
			if (pt != nullptr) {
				if ( pt[i-1].Overlap == true) {
				double px,py,pz;		
					pt[i-1].GetPointPosition(px,py,pz);	
					switch(inputdata.PatternShape){
							case 0:  //圓形	
								g->DrawEllipse(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
								//g->DrawEllipse(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));	
								break;
							case 1:	//矩形	
								g->DrawRectangle(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));
								//g->DrawRectangle(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));						
								break;
							case 2:	//菱形	
								PointF point1 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)-PlateH/2);
								PointF point2 = PointF(float(px)+2*pt[i-1].Radius-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);
								PointF point3 = PointF(float(px)+pt[i-1].Radius-PlateW/2,float(py)+2*pt[i-1].Radius-PlateH/2);
								PointF point4 = PointF(float(px)-PlateW/2,float(py)+pt[i-1].Radius-PlateH/2);

							//	PointF point1 = PointF(px+PatternRadius-PlateW/2,py-PlateH/2);
							//	PointF point2 = PointF(px+2*PatternRadius-PlateW/2,py+PatternRadius-PlateH/2);
							//	PointF point3 = PointF(px+PatternRadius-PlateW/2,py+2*PatternRadius-PlateH/2);
							//	PointF point4 = PointF(px-PlateW/2,py+PatternRadius-PlateH/2);
								array<PointF>^ curvePoints = {point1,point2,point3,point4};
								g->DrawPolygon( gcnew Pen( Color::Yellow,1/tmpscale), curvePoints );
								break;
					};
				}
				
			};
		};

//	}
	//畫B-Spline Surface Controll Pt
	if (smoothSurfaceSet != nullptr && smoothSurfaceSet->Exist == true){
		if(smoothSurfaceSet->cboFuncSelect->SelectedIndex == 0){
			double px,py,pz;	
			for(int i = 0; i <surfacecontrollPt->Controll_Row_number; i++){
				for(int j = 0; j <surfacecontrollPt->Controll_Collum_number; j++) {				
					px = Convert::ToSingle(surfacecontrollPt->controllPt_X->GetValue(i,j));
					py = Convert::ToSingle(surfacecontrollPt->controllPt_Y->GetValue(i,j));
					SolidBrush^ Brush = gcnew SolidBrush( Color::BurlyWood);				
					grafx->Graphics->FillEllipse(Brush,(float)(px-PlateW/2-0.5),(float)(py-PlateH/2-0.5),10.0/tmpscale,10.0/tmpscaleY);				
					delete[] Brush;
				}
			}

			//畫作用中控制點的顏色

			if (surfacecontrollPt->SelectIndex_X>=0 && surfacecontrollPt->SelectIndex_Y >=0){
				px = Convert::ToSingle(surfacecontrollPt->controllPt_X->GetValue(surfacecontrollPt->SelectIndex_X,surfacecontrollPt->SelectIndex_Y));
				py = Convert::ToSingle(surfacecontrollPt->controllPt_Y->GetValue(surfacecontrollPt->SelectIndex_X,surfacecontrollPt->SelectIndex_Y));
				SolidBrush^ Brush = gcnew SolidBrush( Color::Red);				
				grafx->Graphics->FillEllipse(Brush,(float)(px-PlateW/2-0.5),(float)(py-PlateH/2-0.5),10.0/tmpscale,10.0/tmpscaleY);				
				delete[] Brush;
			}

		}else if(smoothSurfaceSet->cboFuncSelect->SelectedIndex == 1){
			double px,py,pz;	
			for(int i = 0; i <localsurfacecontrollPt->Controll_Row_number; i++){
				for(int j = 0; j <localsurfacecontrollPt->Controll_Collum_number; j++) {				
					px = Convert::ToSingle(localsurfacecontrollPt->controllPt_X->GetValue(i,j));
					py = Convert::ToSingle(localsurfacecontrollPt->controllPt_Y->GetValue(i,j));
					SolidBrush^ Brush = gcnew SolidBrush( Color::BurlyWood);				
					grafx->Graphics->FillRectangle(Brush,(float)(px-PlateW/2-0.5),(float)(py-PlateH/2-0.5),10.0/tmpscale,10.0/tmpscaleY);				
					delete[] Brush;
				}
			}

			//畫作用中控制點的顏色
			if (localsurfacecontrollPt->SelectIndex_X>=0 && localsurfacecontrollPt->SelectIndex_Y >=0){
				px = Convert::ToSingle(localsurfacecontrollPt->controllPt_X->GetValue(localsurfacecontrollPt->SelectIndex_X,localsurfacecontrollPt->SelectIndex_Y));
				py = Convert::ToSingle(localsurfacecontrollPt->controllPt_Y->GetValue(localsurfacecontrollPt->SelectIndex_X,localsurfacecontrollPt->SelectIndex_Y));
				SolidBrush^ Brush = gcnew SolidBrush( Color::Red);				
				grafx->Graphics->FillRectangle(Brush,(float)(px-PlateW/2-0.5),(float)(py-PlateH/2-0.5),10.0/tmpscale,10.0/tmpscaleY);				
				delete[] Brush;
			}





		}
	
	}
	


	delete DrawSkyBluePen;
	delete DrawDarkRedPen;
	

}
*/
void Form1::ModifyDotRate(ArrayList^ LocalAreaPara,array<float,2>^ tmpFM_DotSize){
	//局部修改-得到網點縮放比例 
	
	// Step 1 : 將局部修改表單中的參數(LocalAreaPara)轉換為Surface 可以儲存的資料後 ,存到SurfaceDataList 中
	// Step 2 : 讀入SurfaceDataList 資料 ,產生Surface 後,將surface 儲存到LocalSurface
    // Step 3 : 由Surface 資料 ,對應到網點座標 ,進行局部修改比例的計算        
	//         
	//         
	//




    //------------------------------Step 1 ----------------------------------------------------------------------
	//轉換參數
	//1,) 將局部修改中的資料 ,轉換為Surface 可以讀取的格式
	//2,) 建立一個array ,儲存局部修改表格中的陣列參數 (data[8] .data[9], data[10])


	ArrayList^ SurfaceDataList = gcnew ArrayList(); //儲存轉變為可讓Surface 讀入的array.
	array<PointF>^  number_pitch = gcnew array<PointF>(LocalAreaPara->Count) ; //定義為陣列的數目和間距
	array<int>^   direction = gcnew array<int>(LocalAreaPara->Count); //定義為陣列的方向
	


	for(int jj = 0 ; jj <LocalAreaPara->Count ;jj++){

		

		array<String^>^ data = (array<String^>^)LocalAreaPara->default[jj];
	

		//if(Convert::ToString(data->GetValue(data->Length-1)) == "1") {  //將啟用的數值轉換為Surface 可以讀取的參數 "1"表示啟用 ,"0"表示沒有啟用

			number_pitch[jj].X = Convert::ToInt16( data[9] );
			number_pitch[jj].Y = Convert::ToSingle(data[10]);
			direction[jj] = Convert::ToInt16(data[8]);



			

			
				
				//Surface 定義為 index: 0 -> 名稱 ,    對應到局部修改的參數是 index : 11;
				//Surface 定義為 index: 1-> U Value ,  對應到局部修改的參數是 index : 6;
				//Surface 定義為 index: 2 -> V Value , 對應到局部修改的參數是 index : 7;
				//Surface 定義為 index: 3 -> Resolution X ,  設定為 100
				//Surface 定義為 index: 4 -> Resolution Y ,  設定為 100
				//Surface 定義為 index: 5 -> 控制點數目 X ,  對應到局部修改的參數是 index : 12;
				//Surface 定義為 index: 6 -> 控制點數目 Y ,  對應到局部修改的參數是 index : 13;
				//Surface 定義為 index: 7 + 4 i -> X座標 ,   對應到局部修改的參數是 index : (16 + 4 i) + 左下角座標位置X + 陣列間距 * i;
				//Surface 定義為 index: 8 + 4 i-> Y座標 ,    對應到局部修改的參數是 index : (17 + 4 i) + 左下角座標位置Y + 陣列間距 * i;
				//Surface 定義為 index: 9 + 4 i-> Z直 ,      對應到局部修改的參數是 index : (14 + 4 i) ;
				//Surface 定義為 index: 10 + 4 i-> 權重 ,    對應到局部修改的參數是 index : (15 + 4 i) ;

				// 局部修改的 index : 8  定義為陣列的方向  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// 局部修改的 index : 9  定義為陣列數目
				// 局部修改的 index : 10  定義為陣列的Pitch 
				//			

			
				array<String^>^ surfacedata = gcnew array<String^>(7+ 4*Convert::ToInt16(data[12])*Convert::ToInt16(data[13])) ;

				surfacedata->SetValue(data[11],0);
				surfacedata->SetValue(data[6],1);
				surfacedata->SetValue(data[7],2);
				surfacedata->SetValue("100",3);
				surfacedata->SetValue("100",4);
				surfacedata->SetValue(data[12],5);
				surfacedata->SetValue(data[13],6);

				
				float shiftX = 0  ;
				float shiftY = 0  ;

				
				
			




				switch  (Convert::ToInt16(data[1])){
					case 0: //"左下點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2]) ;
						shiftY = Convert::ToSingle(data[3]) ;
											
						break;
					case 1: //"左上點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 2: //"右上點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 3: //"右下點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  ;

						break;
					case 4: //"中心點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 5: //"左中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 6: //"右中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 7: //"上中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

						break;
					case 8: //"下中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  ;


						break;


				}

				int count = 7 ;

				for(int ll= 0; ll <Convert::ToInt16(data[12]);ll++){
					for(int mm = 0; mm <Convert::ToInt16(data[13]);mm++){
						float tmpValue ;
						String^ tmpString;
						tmpValue = Convert::ToSingle(data[count+ 9]) + shiftX;
						tmpString = Convert::ToString(tmpValue);
						surfacedata->SetValue(tmpString,count  );
						count ++ ;
						tmpValue = Convert::ToSingle(data[count+ 9]) + shiftY;
						tmpString = Convert::ToString(tmpValue);
						surfacedata->SetValue(tmpString,count  );
						count ++ ;
						surfacedata->SetValue(data[count+ 5],count  );
						count ++ ;
						surfacedata->SetValue(data[count+ 5],count  );
						count ++ ;
						
						
					}
				}


				//加入到容器中
				SurfaceDataList->Add(surfacedata);
				

	//	}
		

	}


	////------------------------------Step 2 ----------------------------------------------------------------------
	//產生曲面 
		//將局部修改的輸入參數轉換為Surface 可以讀取的參數


	
	//將轉換好的參數儲存到Surface 中

	ArrayList^ LocalSurface = gcnew ArrayList();  //儲存Surface 的容器

	for( int ii = 0 ;ii < SurfaceDataList->Count ; ii ++){
		Nurbs::B_Spline_Surface^ tmp_Surface;
		tmp_Surface = gcnew B_Spline_Surface();


		array<String^>^ temp = (array<String^>^ )SurfaceDataList->default[ii];

		tmp_Surface->SaveSurfaceData(temp);
		tmp_Surface->ModifySurface_Resolution_Degree();

		//加入到容器中
		LocalSurface->Add(tmp_Surface);

	}






    //------------------------------Step 3 ----------------------------------------------------------------------
	//產生修改比例--------------------------------------------------------------------------------

	

	for(int ii = 0 ; ii < tmpFM_DotSize->GetLength(0) ; ii++){
		for(int mm = 0 ; mm < tmpFM_DotSize->GetLength(1) ; mm++){

			PointF coordinate = PointF(0.03125f+ii*(25.4/this->IJP_DPI) ,0.03125f+mm*(25.4/this->IJP_DPI));
			for(int jj = 0 ; jj <LocalSurface->Count ;jj++){
					Nurbs::B_Spline_Surface^ tmp_Surface =(Nurbs::B_Spline_Surface^)LocalSurface->default[jj];
					RectangleF tmp_boundary = tmp_Surface->Surface_Boundary::get();

				// 局部修改的 index : 8  定義為陣列的方向  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// 局部修改的 index : 9  定義為陣列數目
				// 局部修改的 index : 10  定義為陣列的Pitch 

					PointF tmp_coordinate ; //目前Surface座標的位置
				
					tmp_coordinate = coordinate ;

					for(int kk = 0 ; kk < number_pitch[jj].X ; kk ++){
						switch (direction[jj])
						{
							case 0 : 
								
								tmp_coordinate.X = coordinate.X - kk*number_pitch[jj].Y;
								break;
							case 1:
								
								tmp_coordinate.X = coordinate.X + kk*number_pitch[jj].Y;
								break;
							case 2:
								
								tmp_coordinate.Y = coordinate.Y -kk* number_pitch[jj].Y;
								break;
							case 3:
								
								tmp_coordinate.Y = coordinate.Y + kk*number_pitch[jj].Y;
								break;
						}

						if(tmp_boundary.Contains(tmp_coordinate) == true ){
							float rate = tmp_Surface->GetSurface_Z_Value(tmp_coordinate.X,tmp_coordinate.Y)/100;							
							if (rate <= -1.0f) rate = -1.0f;
							tmpFM_DotSize->SetValue(tmpFM_DotSize[ii,mm]*(rate+1.0f)*(rate+1.0f),ii,mm) ; 
							
							if(tmpFM_DotSize[ii,mm] < 0) tmpFM_DotSize->SetValue(0.0f,ii,mm);
							
						}

					}

				};

			}
				

		}

		

	





























}
void Form1::ModifyDotRate(ArrayList^ LocalAreaPara,Pattern^ Dot){

	// Step 0 : 初始化Dot Rate ;
	// Step 1 : 將局部修改表單中的參數(LocalAreaPara)轉換為Surface 可以儲存的資料後 ,存到SurfaceDataList 中
	// Step 2 : 讀入SurfaceDataList 資料 ,產生Surface 後,將surface 儲存到LocalSurface
    // Step 3 : 由Surface 資料 ,對應到網點座標 ,進行局部修改比例的計算        
	//         
	//         
	//

	//----------------------------Step 0 -----------------------------------------------------------------------


	for(int ii = 0 ; ii < Dot->GetDotNumber() ; ii++ ){
		Dot->ModifyRate_LocalArea[ii] = 1.0f;
	}


    //------------------------------Step 1 ----------------------------------------------------------------------
	//轉換參數
	//1,) 將局部修改中的資料 ,轉換為Surface 可以讀取的格式
	//2,) 建立一個array ,儲存局部修改表格中的陣列參數 (data[8] .data[9], data[10])


	ArrayList^ SurfaceDataList = gcnew ArrayList(); //儲存轉變為可讓Surface 讀入的array.
	array<PointF>^  number_pitch = gcnew array<PointF>(LocalAreaPara->Count) ; //定義為陣列的數目和間距
	array<int>^   direction = gcnew array<int>(LocalAreaPara->Count); //定義為陣列的方向
	


	for(int jj = 0 ; jj <LocalAreaPara->Count ;jj++){

		

		array<String^>^ data = (array<String^>^)LocalAreaPara->default[jj];
	

		//if(Convert::ToString(data->GetValue(data->Length-1)) == "1") {  //將啟用的數值轉換為Surface 可以讀取的參數 "1"表示啟用 ,"0"表示沒有啟用

			number_pitch[jj].X = Convert::ToInt16( data[9] );
			number_pitch[jj].Y = Convert::ToSingle(data[10]);
			direction[jj] = Convert::ToInt16(data[8]);



			

			
				
				//Surface 定義為 index: 0 -> 名稱 ,    對應到局部修改的參數是 index : 11;
				//Surface 定義為 index: 1-> U Value ,  對應到局部修改的參數是 index : 6;
				//Surface 定義為 index: 2 -> V Value , 對應到局部修改的參數是 index : 7;
				//Surface 定義為 index: 3 -> Resolution X ,  設定為 100
				//Surface 定義為 index: 4 -> Resolution Y ,  設定為 100
				//Surface 定義為 index: 5 -> 控制點數目 X ,  對應到局部修改的參數是 index : 12;
				//Surface 定義為 index: 6 -> 控制點數目 Y ,  對應到局部修改的參數是 index : 13;
				//Surface 定義為 index: 7 + 4 i -> X座標 ,   對應到局部修改的參數是 index : (16 + 4 i) + 左下角座標位置X + 陣列間距 * i;
				//Surface 定義為 index: 8 + 4 i-> Y座標 ,    對應到局部修改的參數是 index : (17 + 4 i) + 左下角座標位置Y + 陣列間距 * i;
				//Surface 定義為 index: 9 + 4 i-> Z直 ,      對應到局部修改的參數是 index : (14 + 4 i) ;
				//Surface 定義為 index: 10 + 4 i-> 權重 ,    對應到局部修改的參數是 index : (15 + 4 i) ;

				// 局部修改的 index : 8  定義為陣列的方向  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// 局部修改的 index : 9  定義為陣列數目
				// 局部修改的 index : 10  定義為陣列的Pitch 
				//			

			
				array<String^>^ surfacedata = gcnew array<String^>(7+ 4*Convert::ToInt16(data[12])*Convert::ToInt16(data[13])) ;

				surfacedata->SetValue(data[11],0);
				surfacedata->SetValue(data[6],1);
				surfacedata->SetValue(data[7],2);
				surfacedata->SetValue("100",3);
				surfacedata->SetValue("100",4);
				surfacedata->SetValue(data[12],5);
				surfacedata->SetValue(data[13],6);

				
				float shiftX = 0  ;
				float shiftY = 0  ;

				
				
			




				switch  (Convert::ToInt16(data[1])){
					case 0: //"左下點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2]) ;
						shiftY = Convert::ToSingle(data[3]) ;
											
						break;
					case 1: //"左上點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 2: //"右上點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 3: //"右下點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  ;

						break;
					case 4: //"中心點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 5: //"左中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 6: //"右中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 7: //"上中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

						break;
					case 8: //"下中點座標(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  ;


						break;


				}

				int count = 7 ;

				for(int ll= 0; ll <Convert::ToInt16(data[12]);ll++){
					for(int mm = 0; mm <Convert::ToInt16(data[13]);mm++){
						float tmpValue ;
						String^ tmpString;
						tmpValue = Convert::ToSingle(data[count+ 9]) + shiftX;
						tmpString = Convert::ToString(tmpValue);
						surfacedata->SetValue(tmpString,count  );
						count ++ ;
						tmpValue = Convert::ToSingle(data[count+ 9]) + shiftY;
						tmpString = Convert::ToString(tmpValue);
						surfacedata->SetValue(tmpString,count  );
						count ++ ;
						surfacedata->SetValue(data[count+ 5],count  );
						count ++ ;
						surfacedata->SetValue(data[count+ 5],count  );
						count ++ ;
						
						
					}
				}


				//加入到容器中
				SurfaceDataList->Add(surfacedata);
				

	//	}
		

	}


	////------------------------------Step 2 ----------------------------------------------------------------------
	//產生曲面 
		//將局部修改的輸入參數轉換為Surface 可以讀取的參數


	
	//將轉換好的參數儲存到Surface 中

	ArrayList^ LocalSurface = gcnew ArrayList();  //儲存Surface 的容器

	for( int ii = 0 ;ii < SurfaceDataList->Count ; ii ++){
		Nurbs::B_Spline_Surface^ tmp_Surface;
		tmp_Surface = gcnew B_Spline_Surface();


		array<String^>^ temp = (array<String^>^ )SurfaceDataList->default[ii];

		tmp_Surface->SaveSurfaceData(temp);
		tmp_Surface->ModifySurface_Resolution_Degree();

		//加入到容器中
		LocalSurface->Add(tmp_Surface);

	}






    //------------------------------Step 3 ----------------------------------------------------------------------
	//產生修改比例--------------------------------------------------------------------------------


		for(int ii = 0 ; ii < Dot->GetDotNumber() ; ii++){
			PointF coordinate = Dot->Dot_Coordinate[ii];
			for(int jj = 0 ; jj <LocalSurface->Count ;jj++){
				Nurbs::B_Spline_Surface^ tmp_Surface =(Nurbs::B_Spline_Surface^)LocalSurface->default[jj];
				RectangleF tmp_boundary = tmp_Surface->Surface_Boundary::get();

			// 局部修改的 index : 8  定義為陣列的方向  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
			// 局部修改的 index : 9  定義為陣列數目
			// 局部修改的 index : 10  定義為陣列的Pitch 

				PointF tmp_coordinate ; //目前Surface座標的位置
			
				tmp_coordinate = coordinate ;

				for(int kk = 0 ; kk < number_pitch[jj].X ; kk ++){
					switch (direction[jj])
					{
						case 0 : 
							
							tmp_coordinate.X = coordinate.X - kk*number_pitch[jj].Y;
							break;
						case 1:
							
							tmp_coordinate.X = coordinate.X + kk*number_pitch[jj].Y;
							break;
						case 2:
							
							tmp_coordinate.Y = coordinate.Y -kk* number_pitch[jj].Y;
							break;
						case 3:
							
							tmp_coordinate.Y = coordinate.Y + kk*number_pitch[jj].Y;
							break;
					}

					if(tmp_boundary.Contains(tmp_coordinate) == true ){
						float rate = tmp_Surface->GetSurface_Z_Value(tmp_coordinate.X,tmp_coordinate.Y)/100;
						Dot->ModifyRate_LocalArea[ii] = (float)Dot->ModifyRate_LocalArea[ii] * (rate+1.0f);
						if(Dot->ModifyRate_LocalArea[ii] < 0) Dot->ModifyRate_LocalArea[ii] = 0.0f;
					}

				}

			};
				

		}

		

	



}
GridDensity^ Form1::CalNearlyRegularDotDensity(Pattern^ tmpDot,PointF^ Size,RectangleF^ LGP){

	Point Mesh((int)Math::Round(LGP->Width/Size->X),(int)Math::Round(LGP->Height/Size->Y));
	RectangleF tmpLGP(LGP->X,LGP->Y,LGP->Width,LGP->Height) ;
	GridDensity^ PatternDensity = gcnew GridDensity(Mesh,tmpLGP);


	
	
		for(int ii = 0 ;ii < tmpDot->GetDotNumber() ;ii++){
				float Dia = (float)tmpDot->Dot_Diameter->GetValue(ii);
				PointF Coor = (PointF) tmpDot->Dot_Coordinate->GetValue(ii);
				float AddDen = Dia*Dia*3.1415926f/Size->X/Size->Y/4;
				Point Mesh = PatternDensity->GetMeshNumber();
				Point Index((int)Math::Round(Coor.X/LGP->Width*(float)(Mesh.X-1)) ,(int)Math::Round(Coor.Y/LGP->Height*(float)(Mesh.Y-1)));
				if(Index.X <=Mesh.X-1 && Index.Y <=Mesh.Y-1 && Index.X >= 0 && Index.Y >=0){
					float PreDen = PatternDensity->GetDensityValue(Index);
					PatternDensity->SetDensityValue(PreDen+AddDen,Index);
				}

		}

		//*
		for(int ii = 0 ; ii < PatternDensity->GetMeshNumber().X ; ii++){
			for( int jj =0 ;jj < PatternDensity->GetMeshNumber().Y ;jj ++){
				float PatternDen  = PatternDensity->GetDensityValue(Point(ii,jj));
				//45度
				float gap = 0.25;
				//float d = (1.32*1.414-2*gap)/2;
				//float den = 3.14*d*d/2/1.32/1.32;
				//----------------------------------
				//60度
				//float d = 1.4499-gap;
				//float den = 3.14*d*d/2/1.4499/2.5153;
				
				//if (PatternDen < den) PatternDensity->SetDensityValue(0,Point(ii,jj));

			}			
		}
		//*/



	return PatternDensity ;
}
GridDensity^ Form1::CalFMPatternDensity(array<float,2>^ tmpFM_DotSize ,Point tmpGridNumber , RectangleF tmpLGPSize ,Point tmpBlockSize ,float maxDen ){
		
	



			
			GridDensity^ PatternDensity = gcnew GridDensity(tmpGridNumber,tmpLGPSize);
			int temp ;
			int rX;
			int rY;

			temp = Math::DivRem(tmpFM_DotSize->GetLength(0),tmpBlockSize.X,rX);
			temp = Math::DivRem(tmpFM_DotSize->GetLength(1),tmpBlockSize.Y,rY);

			
			
			for(int ii = 0 ; ii <tmpFM_DotSize->GetLength(0) ;ii++){

				

				for(int jj = 0 ; jj <tmpFM_DotSize->GetLength(1) ;jj++){

					
					
					int iX = Math::DivRem(ii,tmpBlockSize.X,temp);
					int iY = Math::DivRem(jj,tmpBlockSize.Y,temp);

					Point index(iX , iY);
					float value = PatternDensity->GetDensityValue(index);
					float deltavalue = tmpFM_DotSize[ii,jj]*maxDen/100.0f;
					PatternDensity->SetDensityValue(deltavalue+value,index);					
				}
			}



			for(int ii = 0 ; ii <PatternDensity->GetMeshNumber().X ;ii++){
				for(int jj = 0 ; jj <PatternDensity->GetMeshNumber().Y ;jj++){
					float value = PatternDensity->GetDensityValue(Point(ii,jj));
				//	if(ii != (PatternDensity->GetMeshNumber().X-1) || jj != (PatternDensity->GetMeshNumber().Y-1)){
				//		value = value/size.X/size.Y*100.0f;
				//	}else{
					float tmpX = tmpBlockSize.X;
					float tmpY = tmpBlockSize.Y;

						if( ii == (PatternDensity->GetMeshNumber().X-1) ){
							if(rX == 0) rX = tmpBlockSize.X;
							tmpX = rX;
						}
						if(jj == (PatternDensity->GetMeshNumber().Y-1)){
							if(rY == 0) rY = tmpBlockSize.Y;
							tmpY = rY;
						}

						value = value/tmpX/tmpY*100.0f;

				//	}
					PatternDensity->SetDensityValue(value,Point(ii,jj));
				}
			}



			return PatternDensity ;
				
	





}
GridDensity^ Form1::CalRegularPatternDensity(Pattern^ tmpDot ,Point tmpGridNumber , RectangleF tmpLGPSize,int ShowingStyle){

	// Step 1 :  由網點計算出密度 (規則佈點是確定的數值 ,亂數佈點是概估的數值
	// Step 2 :  將密度資料存為GridDensity 的格式 ,此數值的範圍是0~1 (因為顯示密度的顏色數值是0~1)

	//Question : 在副函式中開一個物件 ,並且將此物件Return 到指標中 ,記憶體不會隨著副函式結束而消失 ,
	//           然而 ,若傳入一個指標,並且在副函式中開新的記憶體,則若副函式結束後 ,記億體就消失 ...
	//           Why ??




			GridDensity^ PatternDensity = gcnew GridDensity(tmpGridNumber,tmpLGPSize);

			int a  ;
			int b  ;
			array<float,2>^ ratio = gcnew array<float,2>(tmpGridNumber.X,tmpGridNumber.Y);
			PointF GridSize(tmpLGPSize.Width/tmpGridNumber.X,tmpLGPSize.Height/tmpGridNumber.Y);
	
			for(int ii = 0 ;ii <tmpDot->GetDotNumber();ii++){
					
				 float ModifyRate_LocalArea = 1.0f;
				 if(tmpDot->ModifyRate_LocalArea->Length >0){
					ModifyRate_LocalArea = (float)tmpDot->ModifyRate_LocalArea->GetValue(ii);
				 }

				
			
				float newDia = ModifyRate_LocalArea*(float)tmpDot->Dot_Diameter->GetValue(ii);


		


			//	if(this->MainData->RandomDot == false){
				if(this->MainData->DotType != 1){

					//計算變動後的密度(適用在不是由DXF 讀出網點的情況) ---------------------------------------------					
					float Den = 0;
					for(int jj = 0 ;jj< 4 ; jj++){
						Point tmpDenIndex(0,0);
						tmpDenIndex = (Point)tmpDot->DotDensity_Index->GetValue(jj,ii);
						float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  + 3.1415926f*newDia*newDia/16.0f/GridSize.X/GridSize.Y;
						ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);						
					}

					//-----------------------------------------------------------
					}else {
						PointF coodrinate;
						float dia;
						tmpDot->GetDotValue(coodrinate,dia,ii);
						
						a =(int)Math::Round(coodrinate.X/tmpLGPSize.Width*tmpGridNumber.X);						
						b =(int)Math::Round(coodrinate.Y/tmpLGPSize.Height*tmpGridNumber.Y);
						if(a>=0 && a < tmpGridNumber.X && b>=0 && b < tmpGridNumber.Y){
							Point tmpDenIndex(a,b);						
							float tmpRatio =(float) ratio->GetValue(tmpDenIndex.X,tmpDenIndex.Y)  +(float) Math::PI*dia*dia/4/GridSize.X/GridSize.Y;
							ratio->SetValue(tmpRatio,tmpDenIndex.X,tmpDenIndex.Y);
						}

					}
				

			}

			 for(int ii= 0 ;ii < tmpGridNumber.X ; ii++){
				  for(int jj= 0 ;jj < tmpGridNumber.Y ; jj++){
					 float tmpDen =  (float)ratio->GetValue(ii,jj);

					
					 Point index(ii,jj);
					
					if( ShowingStyle == 0) PatternDensity->SetDensityValue(tmpDen,index);
					else if(ShowingStyle == 1) PatternDensity->SetDensityValue(tmpDen*100.0f,index);
				  }
			 }

			return PatternDensity ;
				
			

}
void Form1::ModifyDot(){
/*
			int a  ;
			int b  ;
			this->btn_modifyDot->Enabled = false;
			array<float,2>^ ratio = gcnew array<float,2>(this->GirdNumber.X,this->GirdNumber.Y);
		
			PointF GridSize(this->MainData->LGPInformation.Width/this->GirdNumber.X,this->MainData->LGPInformation.Height/this->GirdNumber.Y);
			
			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("網點會限制最小Gap為 : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
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
					//計算變動後的密度(適用在不是由DXF 讀出網點的情況) ---------------------------------------------					
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
						
						 Point index(ii,jj);
						
						 this->PatternDensity->SetDensityValue(tmpDen,index);
					  }
				 }

			
				
			 }

		







*/


}
void Form1::DrawDesignGridDensity(GridDensity^ density){


	//畫一個新的圖形

		

	int Rx = Math::Round(1280/density->GetMeshNumber().X);
	int Ry = Math::Round(1024/density->GetMeshNumber().Y);
		
	if(Rx == 0 ) Rx = 1;
	if(Ry == 0 ) Ry = 1;
		

		this->Density_Bitmap  = gcnew Bitmap(density->GetMeshNumber().X*Rx,density->GetMeshNumber().Y*Ry);
		float R = 0 ;
		float G = 0 ;
		float B = 0 ;
		float tmpdensity = 0;
		for(int ii = 0 ; ii < density->GetMeshNumber().X ; ii ++){
			for(int jj = 0 ; jj < density->GetMeshNumber().Y ; jj++){
				tmpdensity = density->GetDensityValue(Point(ii,jj));
				this->SetDensityColor(tmpdensity,R,G,B);
				for(int mm = 0 ; mm < Rx ; mm ++){
					for(int ll = 0 ; ll< Ry ; ll++){
						this->Density_Bitmap->SetPixel(Rx*ii+mm,Ry*jj+ll,Color::FromArgb(R,G,B));	
					}
				}
				
			}
		}

		
		
		this->pictureBox1->Invalidate();





       
		
		
		
		




	

}
void Form1::DrawDesignGridDensity(B_Spline_Surface^ surface){



		//顯示顏色
		DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();
		Graphics^ test1 = this->pictureBox1->CreateGraphics();
		//Metafile^ Metafile1;

		
		Draw1->PageRange = test1->VisibleClipBounds;
		Draw1->CreatePageSurface(surface ,true ,Point(200,200));
		Metafile_DesignGridDensity = Draw1->DrawPageSurface(PointF(100,0),test1,true,true,true,false);




		delete test1;



		//this->PicSacleVaule = 1.0f;
		//ObjectCoordinate[0].X = this->MainData->LGPInformation.Width/2.0f;
		//ObjectCoordinate[0].Y = this->MainData->LGPInformation.Height/2.0f;
		//ObjectCoordinate[1].X = this->pictureBox1->Width/2.0f;
		//ObjectCoordinate[1].Y = this->pictureBox1->Height/2.0f;
	
		this->pictureBox1->Invalidate();



	


		






	

}
/*
void Form1::DrawDesignGridDensity(bool DrawDensity ,GridDensity^ density ,B_Spline_Surface^ surface){



		//顯示顏色
		DrawModule::FromGlobaltoPageModule^ Draw1 = gcnew FromGlobaltoPageModule();
		Graphics^ test1 = this->pictureBox1->CreateGraphics();
		//Metafile^ Metafile1;

		
		Draw1->PageRange = test1->VisibleClipBounds;
		if(DrawDensity == false){
			Draw1->CreatePageSurface(surface ,true ,Point(200,200));
			Metafile_DesignGridDensity = Draw1->DrawPageSurface(PointF(100,0),test1,true,true,true);
		}else{
			Draw1->CreatePageSurface(density);
			Metafile_DesignGridDensity = Draw1->DrawPageSurface(PointF(100,0),test1,true,true,false);
		}



		delete test1;

		Graphics^ temp = this->pictureBox1->CreateGraphics();
		
		this->DrawImage(temp);
		






	

}
*/
void Form1::CheckItem(){


//儲存 Pattern 檔案 
	if (this->Dot->Dot_Diameter != nullptr && this->Dot->GetDotNumber() > 0){
		this->儲存Pattern檔案ToolStripMenuItem->Enabled = true;
		
	}else{
		this->儲存Pattern檔案ToolStripMenuItem->Enabled = false;
		
	}

//儲存 LT 檔案
	if (this->Dot->Dot_Diameter != nullptr && this->Dot->GetDotNumber() > 0 && this->Set_Data != nullptr){
		this->SaveLTPatternFileToolStripMenuItem->Enabled = true;
	}else{
		this->SaveLTPatternFileToolStripMenuItem->Enabled = false;
	}	 


//確認網點修改的Button 
	if(this->Dot->GetDotNumber() == 0) this->btn_modifyDot->Enabled = false;
	if(this->Dot->GetDotNumber() == 0) this->btnResetModifyRate->Enabled = false;

//Button 防呆
	if (this->backgroundWorker1->IsBusy == true ) this->btn_ProducePattern->Enabled = false;
	else this->btn_ProducePattern->Enabled = true;


//	if (this->Density->DensityValue->LongLength == 0) {
//		this->btn_modifyDot->Enabled = false;
//		this->btnResetModifyRate->Enabled = false;
//	}else {
//		this->btn_modifyDot->Enabled = true;
//		this->btnResetModifyRate->Enabled = true;
//	}

	



//曲面調整均度是依據LGP尺寸 輸入有沒有錯誤決定是否可以啟用 ,但因為目前已對LGP尺寸進行防呆的功能 ,故設定永遠啟用 ...



//亮線修改 ,區域修改 , HotBar 修改
	/*
	if(this->Dot->GetDotNumber() > 0 && this->Dot->ModifyRate_HotSpot->Length > 0 ){			
	
		this->HotBar修改ToolStripMenuItem->Enabled = true;
	}else{			

		this->HotBar修改ToolStripMenuItem->Enabled = false;
	}
	*/

	if(this->Dot->GetDotNumber() > 0 && this->Dot->ModifyRate_LocalArea->Length > 0){		
	//	this->局部修改ToolStripMenuItem->Enabled = true;		
	}else{		
	//	this->局部修改ToolStripMenuItem->Enabled = false;		
	}

	if(this->SurfacePatternDensity != nullptr  && this->SurfacePatternDensity->IsDensityEmpty == false && this->MainData->LGPInformation.IsEmpty == false){
	//	this->HotBar修改ToolStripMenuItem->Enabled = true;
	}else{
	//	this->HotBar修改ToolStripMenuItem->Enabled = false;
	}
	


//產生網點按紐 
	if (this->GirdNumber.X != 0 && this->GirdNumber.Y != 0 && this->GirdNumber.IsEmpty == false && this->Surface_Global_Design != nullptr )
		this->btn_ProducePattern->Enabled = true;						
	else
		this->btn_ProducePattern->Enabled = false;



//Menu---儲存 MenuItem 控制

//儲存Pattern 檔案 ,儲存LT 檔案
	if( this->Dot->GetDotNumber()>0) {
		this->儲存Pattern檔案ToolStripMenuItem->Enabled = true;
		this->SaveLTPatternFileToolStripMenuItem->Enabled = true;
	}
	else{ 
		this->儲存Pattern檔案ToolStripMenuItem->Enabled = false;
		this->SaveLTPatternFileToolStripMenuItem->Enabled = false;
	}

//儲存IJP 檔案
//	if(this->IJP_DotSize != nullptr){
		if(this->IJP_DotSize != nullptr && (this->IJP_DotSize->GetLength(0) > 0) && (this->IJP_DotSize->GetLength(1) > 0))  this->Save_IJP_File->Enabled = true;
		else  this->Save_IJP_File->Enabled = false;
//	}



//儲存專案檔



//Menu--- 編輯 


	if(this->GirdNumber.X == 0 ||this->GirdNumber.Y == 0 || this->MainData->LGPInformation.Width == 0 || this->MainData->LGPInformation.Height == 0) this->曲面調整均度ToolStripMenuItem->Enabled = false;
	else this->曲面調整均度ToolStripMenuItem->Enabled = true;
	
//	if(this->Surface_Global_Design == nullptr || this->Surface_Global_Design->IsSurfaceEmpty == true) this->局部修改ToolStripMenuItem->Enabled = false ;
//	else this->局部修改ToolStripMenuItem->Enabled = true ;
	


//Menu-- 工具
	if(this->Dot->GetDotNumber()>0 || (this->PatternDensity != nullptr && this->PatternDensity->IsDensityEmpty == false) ) this->網點密度分析ToolStripMenuItem->Enabled = true;
	else this->網點密度分析ToolStripMenuItem->Enabled = false;

	if(this->Dot->GetDotNumber()>0) this->網紋分析ToolStripMenuItem->Enabled = true;
	else this->網紋分析ToolStripMenuItem->Enabled = false;

//Form Btn :
	//產生網點按鈕
	
	//if(this->Surface_Global_Design != nullptr && (this->Surface_Global_Design->IsInputDataChanged == true || this->localsurfacedata->Count > 0)) this->btn_ProducePattern->Enabled = true;
	//else this->btn_ProducePattern->Enabled = false;
	

	//顯示網紋按鈕
//	if(this->ScreenMuraData != nullptr){
	if(this->Dot->MuraValue != nullptr) this->btnShowMura->Enabled = true;
		else this->btnShowMura->Enabled = false;
//	}

	//修邊按紐
	if(this->LGPPolyLinePt != nullptr && this->LGPPolyLinePt->Count > 0 ) this->btn_CuttingShape->Enabled = true;
	else this->btn_CuttingShape->Enabled = false;
	






}
void Form1::DrawCurrentPattern(){


		MemoryStream_CurrentPattern = gcnew MemoryStream();			
		Graphics^ tmpG = this->pictureBox1->CreateGraphics();		
		Metafile_CurrentPattern =gcnew Metafile(MemoryStream_CurrentPattern,tmpG->GetHdc());
		tmpG->ReleaseHdc();




		Pen^ DrawSkyBluePen = gcnew Pen( Color::DeepSkyBlue,0.01f/25.4f );
		Graphics^ g = g->FromImage(Metafile_CurrentPattern);
		g->PageScale = 1;
		g->PageUnit= GraphicsUnit::Millimeter;
        //座標暫存區(垂直面)
		g->Clip =gcnew System::Drawing::Region( Rectangle(0,0,(int)this->MainData->LGPInformation.Width ,(int)this->MainData->LGPInformation.Height ) );
		
		g->Clear(Color::Black);
		
		


		for(int i=0;i< this->Dot->GetDotNumber();i++){
			PointF dot_coor;
			float dot_dia;
			this->Dot->GetDotValue(dot_coor,dot_dia,i);
			


			switch(this->MainData->Pattern_Shape){
				case 0:  //圓形
					//g->DrawEllipse(DrawSkyBluePen,float(px),float(py),(2*pt[i-1].Radius),(2*pt[i-1].Radius));	
					g->DrawEllipse(DrawSkyBluePen,dot_coor.X,dot_coor.Y,dot_dia,dot_dia);	
											
					break;
				case 1:	 //矩形
					//g->DrawRectangle(DrawSkyBluePen,float(px),float(py),float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
					g->DrawRectangle(DrawSkyBluePen,dot_coor.X,dot_coor.Y,dot_dia,dot_dia);
					break;
				
			};
					
				
			
		}

		g->DrawRectangle(DrawSkyBluePen,Rectangle(0,0,(int)this->MainData->LGPInformation.Width ,(int)this->MainData->LGPInformation.Height ));
		delete g;
		Graphics^ temp = this->pictureBox1->CreateGraphics();


		int picwidth = this->pictureBox1->Width;
		int picheight = this->pictureBox1->Height;	
		float scale = 0;
		if(this->MainData->LGPInformation.Height  >= this->MainData->LGPInformation.Width ){
			scale = picheight/this->MainData->LGPInformation.Height *0.8f;
			temp->DrawImage(this->Metafile_CurrentPattern,(int)(picwidth-scale*this->MainData->LGPInformation.Width )/2,(int)picheight/10,(int)(scale*this->MainData->LGPInformation.Width ),(int)(scale*this->MainData->LGPInformation.Height ));
			
		}
		else{
			scale = picwidth/this->MainData->LGPInformation.Width *0.8f;
			temp->DrawImage(this->Metafile_CurrentPattern,(int)picwidth/10,(int)(picheight-scale*this->MainData->LGPInformation.Height )/2,(int)(scale*this->MainData->LGPInformation.Width ),(int)(scale*this->MainData->LGPInformation.Height ));
			
		}


		
		

		delete temp;

		MemoryStream_CurrentPattern->Close();


}
void Form1::DrawLocalSurfaceData(Graphics^ g,ArrayList^ tmplocalsurfacedata){

		//畫局部修改外框<長方形>
		//此函式要放在DrawPic 後面 ,不然座標轉換會有問題

			array<PointF>^  number_pitch = gcnew array<PointF>(tmplocalsurfacedata->Count) ; //定義為陣列的數目和間距
			array<int>^   direction = gcnew array<int>(tmplocalsurfacedata->Count); //定義為陣列的方向
			Pen^ GreenPen = gcnew Pen( Color::Green,0.1/25.4 );
			

			for(int jj = 0 ; jj <tmplocalsurfacedata->Count ;jj++){

				array<String^>^ data = (array<String^>^)tmplocalsurfacedata->default[jj];
			
					number_pitch[jj].X = Convert::ToInt16( data[9] );
					number_pitch[jj].Y = Convert::ToSingle(data[10]);
					direction[jj] = Convert::ToInt16(data[8]);

						
					float shiftX = 0  ;
					float shiftY = 0  ;


					switch  (Convert::ToInt16(data[1])){
						case 0: //"左下點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2]) ;
							shiftY = Convert::ToSingle(data[3]) ;
												
							break;
						case 1: //"左上點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  ;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
							
							break;
						case 2: //"右上點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
							
							break;
						case 3: //"右下點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  ;

							break;
						case 4: //"中心點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 5: //"左中點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  ;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 6: //"右中點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 7: //"上中點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

							break;
						case 8: //"下中點座標(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
							shiftY = Convert::ToSingle(data[3])  ;


							break;


					}




					PointF coordinate;
					for(int kk = 0 ; kk < number_pitch[jj].X ; kk ++){
					switch (direction[jj])
					{
						case 0 : 
							
							coordinate.X = + kk*number_pitch[jj].Y;
							break;
						case 1:
							
							coordinate.X = - kk*number_pitch[jj].Y;
							break;
						case 2:
							
							coordinate.Y = + kk*number_pitch[jj].Y;
							break;
						case 3:
							
							coordinate.Y = - kk*number_pitch[jj].Y;
							break;
					}

					g->TranslateTransform(coordinate.X,coordinate.Y);
					g->DrawRectangle(GreenPen,shiftX,shiftY,Convert::ToSingle(data[4]),Convert::ToSingle(data[5]));
					g->TranslateTransform(-coordinate.X,-coordinate.Y);

				}						

			}



}
void Form1:: DrawHotSpotData(Graphics^ g,ArrayList^ tmphotspotdata){
	//此函式要放在DrawPic 後面
	//畫局部修改外框<橢圓形>

				
	float RotateAngle ;
	float LongAxis ;
	float ShortAxis ;
	PointF Coordinate;		
	int Number;
	float Pitch ;
	int Direction;

	Pen^ GreenPen = gcnew Pen( Color::Green,0.1/25.4 );
	//array<String^>^ tmparray;
	HotSpot_Part^ tmpLocalPart ;


	for(int ii = 0 ; ii < tmphotspotdata->Count ; ii++){

		//tmparray = (array<String^>^)tmphotspotdata->default[ii];
		tmpLocalPart = (HotSpot_Part^) tmphotspotdata->default[ii];
		
		//Number = Convert::ToInt16(tmparray[1]);
		Number = tmpLocalPart->Number;

		//Direction = Convert::ToInt16(tmparray[2]);
		Direction = tmpLocalPart->PitchDirectionIndex;

		//if(tmparray[3] != "") {
		//	Pitch = Convert::ToSingle(tmparray[3]);
		//}else{
		//	Pitch = 0 ;
		//}

		Pitch = tmpLocalPart->pitch;

		//Coordinate.X = Convert::ToSingle(tmparray[4]);
		//Coordinate.Y = Convert::ToSingle(tmparray[5]);

		Coordinate.X = tmpLocalPart->CenterCoordinate.X;
		Coordinate.Y = tmpLocalPart->CenterCoordinate.Y;


		//LongAxis = Convert::ToSingle(tmparray[6])/2.0f;
		//ShortAxis = Convert::ToSingle(tmparray[7])/2.0f ;

		LongAxis = tmpLocalPart->Length_X/2.0f;
		ShortAxis =tmpLocalPart->Length_Y/2.0f ;


		//RotateAngle = Convert::ToSingle(tmparray[8]) ;

		RotateAngle = tmpLocalPart->rotateAngle ;



		for(int jj = 0 ; jj <Number ; jj++){

			if(Direction == 0 ) {  //X 方向 
				g->TranslateTransform(Coordinate.X+jj*Pitch,Coordinate.Y);
			} else{  //Y 方向
				g->TranslateTransform(Coordinate.X,Coordinate.Y+jj*Pitch);
			}
			g->RotateTransform(-RotateAngle);
			
			if (tmpLocalPart->Shape == "橢圓形")
				g->DrawEllipse(GreenPen,-LongAxis,-ShortAxis,2*LongAxis,2*ShortAxis);
			else if (tmpLocalPart->Shape == "菱形"){
				array<PointF>^ pt = gcnew array<PointF>(4);
				pt[0] = PointF(-LongAxis,0); 
				pt[1] = PointF(0,ShortAxis); 
				pt[2] = PointF(LongAxis,0); 
				pt[3] = PointF(0,-ShortAxis); 

				g->DrawPolygon(GreenPen,pt);
			}

			//返回原始座標點
			g->RotateTransform(RotateAngle);
			if(Direction == 0 ) {  //X 方向 
				g->TranslateTransform(-(Coordinate.X+jj*Pitch),-Coordinate.Y);
			} else{  //Y 方向
				g->TranslateTransform(-Coordinate.X,-(Coordinate.Y+jj*Pitch));
			}
			
		}
					
	}



}
void Form1::DrawPic(Graphics^ g,Point ScaleCenter,float scale ,Point ScreenPt){



		
			

					//設定全局座標為左下角是原點 
				 	this->MainPicMatrix->Reset();
					this->MainPicMatrix->Scale(1,-1);
					

					this->MainPicMatrix->Translate(0,-this->pictureBox1->Height);
					

					g->Clear(Color::Black);
				
								
					//移動特定點圖形到螢幕上的某一點
					this->MainPicMatrix->Translate(ScreenPt.X- scale*ScaleCenter.X,ScreenPt.Y -scale*ScaleCenter.Y);

					//以特定點為中心Scale圖形 
					this->MainPicMatrix->Translate(scale*ScaleCenter.X,scale*ScaleCenter.Y);
					this->MainPicMatrix->Scale(scale,scale);					
					this->MainPicMatrix->Translate(-ScaleCenter.X,-ScaleCenter.Y);
					

					g->Transform::set(this->MainPicMatrix);
								
															
					g->DrawImage(this->Density_Bitmap,0.0f,0.0f,this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);

					

					if (this->IJP_TextBitmap != nullptr){
							
						if(IJPText_Index == 0 || IJPText_Index == 1 || IJPText_Index == 2)
							g->DrawImage(this->IJP_TextBitmap,this->IJP_TextRange);	
						else{
							g->DrawImage(this->IJP_TextBitmap,this->IJP_TextRange.X,this->IJP_TextRange.Y,this->IJP_TextRange.Height,this->IJP_TextRange.Width);	
						}
						
					}

					//畫LGP外框)
					Pen^ GreenPen = gcnew Pen( Color::Green,0.1/25.4 );
					g->DrawRectangle(GreenPen,this->MainData->LGPInformation.X,this->MainData->LGPInformation.Y,this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);

					//g->DrawEllipse(GreenPen,0,0,15,25);


					//畫修邊外型

					//畫剖面Profile


					//畫密度顏色圖表


					//畫控制點 
					

					

					
					
					



					













					



					

								

		



};
bool Form1::IsPtInside(PointF targetPt,List<PointF>^ LGP_PolyLine){

	
	int numpoints = LGP_PolyLine->Count;
   int X=0;
   int Y=1;
   if(numpoints < 3)
   {
     return false;
   }
    
  // const PointListType & points = >GetPoints();
  // typename PointListType::const_iterator it = points.begin();
  // typename PointListType::const_iterator itend = points.end();
  // itend--;
    
  // PointType first = (*it).GetPosition();
  // PointType last  = (*itend).GetPosition();
    
   // If last point same as first, don't bother with it.

   
 //  if( LGP_PolyLine->default[0].Equals(LGP_PolyLine->default[numpoints-1]))
  // {
  //   numpoints--;
  // }
 
    
   bool oddNodes = false;
    
   PointF node1;
   PointF node2;
    
   for(int i = 0; i < numpoints; i++)
   {

	 node1 =  LGP_PolyLine->default[i];   

     //it++;

     if(i == numpoints - 1)
     {
       node2 = node1;
     }
     else
     {
       node2 =  LGP_PolyLine->default[i+1];
     }
      
	 const double x = targetPt.X; 
	 const double y = targetPt.Y;
      
	 if((node1.Y < y && node2.Y >= y) ||
		 (node2.Y < y && node1.Y >= y))
     {
		 if( node1.X + (y - node1.Y)/
			 (node2.Y - node1.Y) * (node2.X - node1.X) < x )
       {
         oddNodes = !oddNodes;
       }
     }
   }
    
   return oddNodes;



	
}

void Form1::UpdateMessage(){


	//------------網點判定-------------------------------------------------------------------------------------------------------------------
	
		//確認網點是否符合Min Dot
		int countTV = 0;
		int countMNT = 0 ;
		int GapcountTV = 0;
		int GapcountMNT = 0;

	
		float MinGap = 1000.0f;

		

		//設定網點間的距離	
		float pitch = 0;
		switch (this->MainData->Pattern_Arrangment){
			case 0 :  //0度
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X;
				break;
			case 1:   //45度
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X*0.707;
				break;
			case 2:   //60度
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X;
				break;
			case 3:   //30度
				pitch = this->MainData->LGPInformation.Height/this->GirdNumber.Y;
				break;
		}
		
		for(int ii = 0 ; ii < this->Dot->GetDotNumber() ; ii++){
			PointF coordinate ;
			float Dia;
			this->Dot->GetDotValue(coordinate,Dia,ii);

			Dia = Dia*Convert::ToSingle(this->Dot->ModifyRate_LocalArea->GetValue(ii));

			if( pitch-Dia < MinGap) MinGap = pitch-Dia;

			if(Dia > 0.0f){
				if(Dia < 0.4f) countTV ++;
				if(Dia < 0.25f) countMNT ++;
				if(pitch-Dia < 0.1f) GapcountTV++;
				if(pitch-Dia < 0.08f) GapcountMNT++;
			}

		}
		
		if(countMNT > 0){
			MessageBox::Show("直徑小於 0.4 的網點有" + Convert::ToString(countTV) + "顆 ,直徑小於 0.25 的網點有" + Convert::ToString(countMNT) +"顆","警告",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}else if(countTV > 0){
			MessageBox::Show("直徑小於 0.4 的網點有" + Convert::ToString(countTV) + "顆","警告",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}

		if(GapcountMNT >0){
				MessageBox::Show("Gap小於 0.1 的網點有" + Convert::ToString(GapcountTV) + "顆 ,Gap小於 0.08 的網點有" + Convert::ToString(GapcountMNT) +"顆","警告",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}else if (GapcountTV >0){
				MessageBox::Show("Gap小於 0.1 的網點有" + Convert::ToString(GapcountTV) + "顆","警告",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}


		if(MinGap < 1000.0f)
			this->lblMinGap->Text = String::Format("(非擾動)規則佈點最小Gap : " + "{0:#0.0000}"+" mm ",MinGap);
		else
			this->lblMinGap->Text = String::Format("(非擾動)規則佈點最小Gap : ");

//-----------------------------------------------------------------------------------------------------------------------------




		float patternarea = 0 ;
		float MinDia = 0;
		float MaxDia = 0;

		for (int ii = 0 ;ii <this->Dot->GetDotNumber() ;ii++){
			PointF tmp;
			float dia;
			this->Dot->GetDotValue(tmp,dia,ii);			
			patternarea = patternarea + 3.1415f*dia*dia/4;
			if(ii == 0){
				MinDia = dia;
				MaxDia = dia;
			}
			if(dia > 0){
				MinDia = Math::Min(MinDia,dia);
				MaxDia = Math::Max(MaxDia,dia);
			}

		}

		
		this->lblavgDen->Text = String::Format("平均覆蓋率 : " + "{0:#0.00}"+" % ",patternarea/(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height)*100);
		this->lbl_MinPattern->Text = String::Format("最小網點(直徑) : " + "{0:#0.0000}"+" mm",MinDia);
		this->lbl_MaxPattern->Text = String::Format("最大網點(直徑) : " + "{0:#0.0000}"+" mm ",MaxDia);

	


}
bool Form1::ProduceHotSpotDensity(Pattern^ tmpDot ,ArrayList^ tmphotSpotData){

		float gainVaule;
		float SmoothingDegree;
		float RotateAngle ;
		float LongAxis ;
		float ShortAxis ;
		PointF Coordinate;
		PointF Pt1;
		PointF Pt2;
		PointF Pt3;
		

		int Number;
		float Pitch ;
		int Direction;

		array<String^>^ tmparray;
		HotSpot_Part^ tmpPart;

	for(int ii = 0 ; ii < tmphotSpotData->Count ; ii++){


		/*
		tmparray = (array<String^>^)tmphotSpotData->default[ii];


		
		
		Number = Convert::ToInt16(tmparray[1]);
		Direction = Convert::ToInt16(tmparray[2]);
		if(tmparray[3] != "") {
			Pitch = Convert::ToSingle(tmparray[3]);
		}else{
			Pitch = 0 ;
		}
		Coordinate.X = Convert::ToSingle(tmparray[4]);
		Coordinate.Y = Convert::ToSingle(tmparray[5]);
		LongAxis = Convert::ToSingle(tmparray[6])/2.0f;
		ShortAxis = Convert::ToSingle(tmparray[7])/2.0f ;
		RotateAngle = Convert::ToSingle(tmparray[8]) ;
		gainVaule = Convert::ToSingle(tmparray[9]);
		SmoothingDegree = Convert::ToInt16(tmparray[10]);
		
		// -------------產生Curve

		
		array<PointF>^ cPt = gcnew array<PointF>(5);
		cPt[0].Y = 1; //邊緣Gain 值永遠是1 
		cPt[0].X = 0;
		cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
		cPt[4].X = 1;

		cPt[1].X = Convert::ToSingle(tmparray[11]);
		cPt[1].Y = Convert::ToSingle(tmparray[12]);
		cPt[2].X = Convert::ToSingle(tmparray[13]);
		cPt[2].Y = Convert::ToSingle(tmparray[14]);
		cPt[3].X = Convert::ToSingle(tmparray[15]);
		cPt[3].Y = Convert::ToSingle(tmparray[16]);


		Nurbs::B_Spline_Curve^ tmpCurve = gcnew B_Spline_Curve();
	

		for(int ii = 0 ; ii < 5 ; ii ++){
			tmpCurve->ControllPt->Add(cPt[ii]);
		 }

		 tmpCurve->Set_k_Value(SmoothingDegree);
		 tmpCurve->ReProduceCurve(101);


		 //*/
		 //--------------------------



		tmpPart = (HotSpot_Part^)tmphotSpotData->default[ii];
		
		Number = tmpPart->Number;
		Direction = tmpPart->PitchDirectionIndex;
		Pitch = tmpPart->pitch;
	
		Coordinate.X = tmpPart->CenterCoordinate.X;
		Coordinate.Y = tmpPart->CenterCoordinate.Y;

		LongAxis = tmpPart->Length_X/2.0f ;
		ShortAxis =tmpPart->Length_Y/2.0f ;
		RotateAngle = tmpPart->rotateAngle ;
		gainVaule = tmpPart->CenterGainValue;
		SmoothingDegree = tmpPart->SmoothingDegree; 
		
		// -------------產生Curve

		tmpPart->BuildCurve(101);




		 //--------------------------













		 //產生新的密度


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //橢圓焦點
			 array<PointF>^ focusPt = gcnew array<PointF>(2) ;
			 float C ;
			 if(LongAxis >ShortAxis){
				C = Math::Sqrt(LongAxis*LongAxis-ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X+C;
				focusPt[1].X = Coordinate.X-C;
				focusPt[0].Y = Coordinate.Y;
				focusPt[1].Y = Coordinate.Y;

			
			 }else{ 
				C = Math::Sqrt(-LongAxis*LongAxis+ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X;
				focusPt[1].X = Coordinate.X;
				focusPt[0].Y = Coordinate.Y+C;
				focusPt[1].Y = Coordinate.Y-C;
			 }

			

			float value;

	
			for(int ii = 0 ; ii <tmpDot->GetDotNumber() ; ii++){


				

				for(int kk = 0 ; kk<Number; kk++){
						tmpDot->GetDotValue(pt,dia,ii) ;
						
						 if(Direction == 0 ) {//X 方向
							pt.X = pt.X - kk*Pitch ;	
						 }else {						
							pt.Y = pt.Y - kk*Pitch;
						 }
						
						 
						 //座標旋轉
						 tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
						 tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);

						 if(Block.Contains(pt) == true){


							  if(tmpPart->Shape == "橢圓形"){
									//進行橢圓形判斷						
									 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
								 
									//表示在橢圓內
									 if (value < 2*Math::Max(LongAxis,ShortAxis)){
										thda = Math::Atan2(tmp_pt.Y - Coordinate.Y,tmp_pt.X-  Coordinate.X);
										//float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
										//float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));
										//float tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);
										
										//float X0 = (tmp_pt.X-Coordinate.X);
										//float Y0 =  tmp_pt.Y-Coordinate.Y;										
										//float R2 = Math::Sqrt((ShortAxis*ShortAxis*X0*X0 + LongAxis*LongAxis*Y0*Y0)/(LongAxis*LongAxis*ShortAxis*ShortAxis));										
										//float tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2,0);


										float tmpZ = 0;
										if (tmpPart->SwapModeIndex == 0) {
											float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
											float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));									
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);
										}else {
											float X0 = (tmp_pt.X-Coordinate.X);
											float Y0 =  tmp_pt.Y-Coordinate.Y;										
											float R2 = Math::Sqrt((ShortAxis*ShortAxis*X0*X0 + LongAxis*LongAxis*Y0*Y0)/(LongAxis*LongAxis*ShortAxis*ShortAxis));										
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2,0);
										}



										float ratio = tmpDot->ModifyRate_LocalArea[ii];

										if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

										tmpDot->ModifyRate_LocalArea->SetValue(ratio*tmpZ,ii);															
									}
							  }else if(tmpPart->Shape == "菱形"){

								  	float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
									float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
									if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //表示在菱型內

										float tmpZ;
										if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
											//第一或第三象限
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
										}else{
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
										}

										float ratio = tmpDot->ModifyRate_LocalArea[ii];

										if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

										tmpDot->ModifyRate_LocalArea->SetValue(ratio*tmpZ,ii);	


									}


							  }

						 }
					 }

			}

								
	}

	return false;



}
bool Form1::ProduceHotSpotDensity(GridDensity^ tmpdensity ,ArrayList^ tmphotSpotData){ //產生HotSpot密度Data.



		float gainVaule;
		float SmoothingDegree;
		float RotateAngle ;
		float LongAxis ;
		float ShortAxis ;
		PointF Coordinate;
		PointF Pt1;
		PointF Pt2;
		PointF Pt3;
		

		int Number;
		float Pitch ;
		int Direction;

		array<String^>^ tmparray;
		HotSpot_Part^ tmpPart;

	for(int ii = 0 ; ii < tmphotSpotData->Count ; ii++){


		/*
		tmparray = (array<String^>^)tmphotSpotData->default[ii];


		
		Number = Convert::ToInt16(tmparray[1]);
		Direction = Convert::ToInt16(tmparray[2]);
		if(tmparray[3] != "") {
			Pitch = Convert::ToSingle(tmparray[3]);
		}else{
			Pitch = 0 ;
		}
		Coordinate.X = Convert::ToSingle(tmparray[4]);
		Coordinate.Y = Convert::ToSingle(tmparray[5]);
		LongAxis = Convert::ToSingle(tmparray[6])/2.0f;
		ShortAxis = Convert::ToSingle(tmparray[7])/2.0f ;
		RotateAngle = Convert::ToSingle(tmparray[8]) ;
		gainVaule = Convert::ToSingle(tmparray[9]);
		SmoothingDegree = Convert::ToInt16(tmparray[10]);
		
		// -------------產生Curve

		
		array<PointF>^ cPt = gcnew array<PointF>(5);
		cPt[0].Y = 1; //邊緣Gain 值永遠是1 
		cPt[0].X = 0;
		cPt[4].Y =  gainVaule; //中心Gain 值是使用者輸入
		cPt[4].X = 1;

		cPt[1].X = Convert::ToSingle(tmparray[11]);
		cPt[1].Y = Convert::ToSingle(tmparray[12]);
		cPt[2].X = Convert::ToSingle(tmparray[13]);
		cPt[2].Y = Convert::ToSingle(tmparray[14]);
		cPt[3].X = Convert::ToSingle(tmparray[15]);
		cPt[3].Y = Convert::ToSingle(tmparray[16]);


		Nurbs::B_Spline_Curve^ tmpCurve = gcnew B_Spline_Curve();
	

		for(int ii = 0 ; ii < 5 ; ii ++){
			tmpCurve->ControllPt->Add(cPt[ii]);
		 }

		 tmpCurve->Set_k_Value(SmoothingDegree);
		 tmpCurve->ReProduceCurve(101);


		 //*/
		 //--------------------------

		tmpPart = (HotSpot_Part^)tmphotSpotData->default[ii];
		
		Number = tmpPart->Number;
		Direction = tmpPart->PitchDirectionIndex;
		Pitch = tmpPart->pitch;
	
		Coordinate.X = tmpPart->CenterCoordinate.X;
		Coordinate.Y = tmpPart->CenterCoordinate.Y;

		LongAxis = tmpPart->Length_X/2.0f ;
		ShortAxis =tmpPart->Length_Y/2.0f ;
		RotateAngle = tmpPart->rotateAngle ;
		gainVaule = tmpPart->CenterGainValue;
		SmoothingDegree = tmpPart->SmoothingDegree; 
		
		// -------------產生Curve

		tmpPart->BuildCurve(101);




		 //--------------------------



		 //產生新的密度


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //橢圓焦點
			 array<PointF>^ focusPt = gcnew array<PointF>(2) ;
			 float C ;
			 if(LongAxis >ShortAxis){
				C = Math::Sqrt(LongAxis*LongAxis-ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X+C;
				focusPt[1].X = Coordinate.X-C;
				focusPt[0].Y = Coordinate.Y;
				focusPt[1].Y = Coordinate.Y;

			
			 }else{ 
				C = Math::Sqrt(-LongAxis*LongAxis+ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X;
				focusPt[1].X = Coordinate.X;
				focusPt[0].Y = Coordinate.Y+C;
				focusPt[1].Y = Coordinate.Y-C;
			 }


			float value;
			for(int ii = 0 ; ii <tmpdensity->GetMeshNumber().X ; ii ++){
				for(int jj = 0 ; jj < tmpdensity->GetMeshNumber().Y ; jj++){
					 MeshValue = tmpdensity->GetMeshValue(Point(ii,jj));

					 for(int kk = 0 ; kk<Number; kk++){
						 if(Direction == 0 ) {//X 方向
							pt.X = MeshValue.X+MeshValue.Width/2 - kk*Pitch ;
							pt.Y = MeshValue.Y+MeshValue.Height/2 ;
						 }else {
							pt.X = MeshValue.X+MeshValue.Width/2  ;
							pt.Y = MeshValue.Y+MeshValue.Height/2 - kk*Pitch;
						 }
						 
						 //座標旋轉
						 tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
						 tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);

						 if(Block.Contains(pt) == true){

							 if(tmpPart->Shape == "橢圓形"){
									//進行橢圓形判斷						
									 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
								 
									//表示在橢圓內
									 if (value < 2*Math::Max(LongAxis,ShortAxis)){
										thda = Math::Atan2(tmp_pt.Y - Coordinate.Y,tmp_pt.X-  Coordinate.X);
										//float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
										//float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));
										//float tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);

										//float X0 = (tmp_pt.X-Coordinate.X);
										//float Y0 =  tmp_pt.Y-Coordinate.Y;										
										//float R2 = Math::Sqrt((ShortAxis*ShortAxis*X0*X0 + LongAxis*LongAxis*Y0*Y0)/(LongAxis*LongAxis*ShortAxis*ShortAxis));										
										//float tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2,0);


										float tmpZ = 0;
										if (tmpPart->SwapModeIndex == 0) {
											float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
											float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));									
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);
										}else {
											float X0 = (tmp_pt.X-Coordinate.X);
											float Y0 =  tmp_pt.Y-Coordinate.Y;										
											float R2 = Math::Sqrt((ShortAxis*ShortAxis*X0*X0 + LongAxis*LongAxis*Y0*Y0)/(LongAxis*LongAxis*ShortAxis*ShortAxis));										
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2,0);
										}


										float den = tmpdensity->GetDensityValue(Point(ii,jj));

										if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

										tmpdensity->SetDensityValue(den*tmpZ*tmpZ,Point(ii,jj));
									
									}
							 }else if(tmpPart->Shape == "菱形"){

								float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //表示在菱型內

									float tmpZ;
									if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
										//第一或第三象限
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
									}else{
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
									}

									float den = tmpdensity->GetDensityValue(Point(ii,jj));

									if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

									tmpdensity->SetDensityValue(den*tmpZ*tmpZ,Point(ii,jj));
									
									//float den = tmpFM_DotSize[ii,jj];
									//tmpFM_DotSize->SetValue(den*tmpZ*tmpZ,ii,jj);




								}








							 }

						 }
					 }
				 }
			 }								
	}

	return false;


};
bool Form1::ProduceHotSpotDensity(array<float,2>^ tmpFM_DotSize ,ArrayList^ tmphotSpotData){
	//產生HotSpot FM網點

		float gainVaule;
		float SmoothingDegree;
		float RotateAngle ;
		float LongAxis ;
		float ShortAxis ;
		PointF Coordinate;
		PointF Pt1;
		PointF Pt2;
		PointF Pt3;
		

		int Number;
		float Pitch ;
		int Direction;

		array<String^>^ tmparray;
		HotSpot_Part^ tmpPart;

	for(int ii = 0 ; ii < tmphotSpotData->Count ; ii++){

		tmpPart = (HotSpot_Part^)tmphotSpotData->default[ii];
		
		Number = tmpPart->Number;
		Direction = tmpPart->PitchDirectionIndex;
		Pitch = tmpPart->pitch;
	
		Coordinate.X = tmpPart->CenterCoordinate.X;
		Coordinate.Y = tmpPart->CenterCoordinate.Y;

		LongAxis = tmpPart->Length_X/2.0f ;
		ShortAxis =tmpPart->Length_Y/2.0f ;
		RotateAngle = tmpPart->rotateAngle ;
		gainVaule = tmpPart->CenterGainValue;
		SmoothingDegree = tmpPart->SmoothingDegree; 
		
		// -------------產生Curve

		tmpPart->BuildCurve(101);




		 //--------------------------


		 //產生新的密度


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //橢圓焦點
			 array<PointF>^ focusPt = gcnew array<PointF>(2) ;
			 float C ;
			 if(LongAxis >ShortAxis){
				C = Math::Sqrt(LongAxis*LongAxis-ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X+C;
				focusPt[1].X = Coordinate.X-C;
				focusPt[0].Y = Coordinate.Y;
				focusPt[1].Y = Coordinate.Y;

			
			 }else{ 
				C = Math::Sqrt(-LongAxis*LongAxis+ShortAxis*ShortAxis);
				focusPt[0].X = Coordinate.X;
				focusPt[1].X = Coordinate.X;
				focusPt[0].Y = Coordinate.Y+C;
				focusPt[1].Y = Coordinate.Y-C;
			 }


			float value;
			
			for(int ii = 0 ; ii <tmpFM_DotSize->GetLength(0) ; ii ++){
				for(int jj = 0 ; jj < tmpFM_DotSize->GetLength(1) ; jj++){
					

					 for(int kk = 0 ; kk<Number; kk++){
						 if(Direction == 0 ) {//X 方向
							pt.X = 0.03175f + ii*(25.4/this->IJP_DPI) - kk*Pitch ;
							pt.Y = 0.03175f + jj*(25.4/this->IJP_DPI) ;
						 }else {
							pt.X = 0.03175f + ii*(25.4/this->IJP_DPI)  ;
							pt.Y = 0.03175f + jj*(25.4/this->IJP_DPI)  - kk*Pitch;
						 }
						 

						



						 


						 if(Block.Contains(pt) == true){

							 //座標旋轉
							tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
							tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);


							if(tmpPart->Shape == "橢圓形"){
								//進行橢圓形判斷						
								 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
							 
								//表示在橢圓內
								 if (value < 2*Math::Max(LongAxis,ShortAxis)){
									thda = Math::Atan2(tmp_pt.Y - Coordinate.Y,tmp_pt.X-  Coordinate.X);
									float tmpZ = 0;
									if (tmpPart->SwapModeIndex == 0) {
										float R1 = Math::Sqrt(Math::Pow(LongAxis*Math::Cos(thda),2) + Math::Pow(ShortAxis*Math::Sin(thda),2)); 
										float R2 = Math::Sqrt(Math::Pow(tmp_pt.X-Coordinate.X,2) + Math::Pow(tmp_pt.Y-Coordinate.Y,2));									
									    tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2/R1,0);
									}else {
										float X0 = (tmp_pt.X-Coordinate.X);
										float Y0 =  tmp_pt.Y-Coordinate.Y;										
										float R2 = Math::Sqrt((ShortAxis*ShortAxis*X0*X0 + LongAxis*LongAxis*Y0*Y0)/(LongAxis*LongAxis*ShortAxis*ShortAxis));										
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-R2,0);
									}


									float den = tmpFM_DotSize[ii,jj];

									if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

									tmpFM_DotSize->SetValue(den*tmpZ*tmpZ,ii,jj);
																
								}
							}else if(tmpPart->Shape == "菱形"){
								float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //表示在菱型內

									float tmpZ;
									if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
										//第一或第三象限
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
									}else{
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
									}
									
									float den = tmpFM_DotSize[ii,jj];

									if(tmpZ < 0) tmpZ = 0; // 設定下現值為0 

									tmpFM_DotSize->SetValue(den*tmpZ*tmpZ,ii,jj);




								}

							}

						 }
					 }
				 }
			 }								
	}

	return false;








}

//void Form1::ShowPercentage(int percentage){
	//this->toolStripProgressBar1->Value = percentage;
	//this->statusStrip1->Update();
//}
/*
void Form1::Viewoperation(int situation){


	grafx->Graphics->Clear(Color::Black);
	// Begin graphics container.
     // GraphicsContainer^ containerState = grafx->Graphics->BeginContainer();


	float PicWidth = Form1::pictureBox1->Size.Width;  //ScreenSize
	float PicHeight= Form1::pictureBox1->Size.Height;  //ScreenSize
	float PlateH = inputdata.PlateHeight;
	float PlateW = inputdata.PlateWidth;
		
	array<float,1>^buffer = gcnew array<float>(9);	
	buffer = grafx->Graphics->Transform->Elements;

	float tmpscale = Convert::ToSingle(buffer->GetValue(0));


	grafx->Graphics->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
	grafx->Graphics->InterpolationMode =  System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
	
	delete buffer;

// 20080806以前--------------------------------------------------------
//	switch (situation){	
//	case 0:		
//		break;
//	case 1:   //放大	
//
//		grafx->Graphics->ScaleTransform(1.1,1.1);	
//		break;
//	case 2: //縮小
//		grafx->Graphics->ScaleTransform(1/1.1,1/1.1);
//	
//
//		break;
//	case 3: //回覆原狀
//		double tempscale=1;
//		((PlateH/PicHeight) > (PlateW/PicWidth))? tempscale = PicHeight/PlateH*0.9: tempscale = PicWidth/PlateW*0.9 ;
//		grafx->Graphics->ResetTransform();
//		grafx->Graphics->TranslateTransform(PicWidth/2,PicHeight/2);
//		grafx->Graphics->ScaleTransform((float)tempscale,(float)tempscale);
//		break;
//	
//	}
//-----------------------------------------------------------------------
	
	ViewDraw(grafx->Graphics);			

// 20080806以後----------------------------------------------------------
      // Create parallelogram for drawing image.
      Point ulCorner = Point(100,100);
      Point urCorner = Point(500,100);
      Point llCorner = Point(500,5000);
      array<Point>^ destPara = {ulCorner,urCorner,llCorner};

      // Create rectangle for source image.
      Rectangle srcRect = Rectangle(50,50,150,150);
      GraphicsUnit units = GraphicsUnit::Pixel;

    
	
	switch (situation){	
	case 0:		
		break;
	case 1:   //放大	

	
		ViewScale = ViewScale *1.2;
		
		//grafx->Graphics->DrawImage(DesignDensity_Bmp,Rectangle(0,0,inputdata.PlateWidth*5,inputdata.PlateHeight*5));
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,PointF(0,0));
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,destPara);
		
     
		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width,this->pictureBox1->Size.Height),Rectangle(0,0,this->pictureBox1->Size.Width/ViewScale,this->pictureBox1->Size.Width/ViewScale),units);
		break;
	case 2: //縮小
		//grafx->Graphics->ScaleTransform(1/1.1,1/1.1);
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width/2,this->pictureBox1->Size.Height/2));
		  // Draw image to screen.
		ViewScale = ViewScale /1.2;

		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width,this->pictureBox1->Size.Height),Rectangle(0,0,this->pictureBox1->Size.Width/ViewScale,this->pictureBox1->Size.Width/ViewScale),units);

		//grafx->Graphics->DrawImage( PatternLocation_Bmp, destPara, srcRect, units );

		break;
	case 3: //回覆原狀
//		double tempscale=1;
//		((PlateH/PicHeight) > (PlateW/PicWidth))? tempscale = PicHeight/PlateH*0.9: tempscale = PicWidth/PlateW*0.9 ;
//		grafx->Graphics->ResetTransform();
//		grafx->Graphics->TranslateTransform(PicWidth/2,PicHeight/2);
//		grafx->Graphics->ScaleTransform((float)tempscale,(float)tempscale);
//		break;
//		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,inputdata.PlateWidth*5,inputdata.PlateHeight*5));
		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(this->pictureBox1->Size.Width*0.05,this->pictureBox1->Size.Height*0.05,this->pictureBox1->Size.Width*0.9,this->pictureBox1->Size.Height*0.9));
		break;
	}




//-----------------------------------------------------------------------



//	if (PatternLocation_Bmp != nullptr)
//		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(this->pictureBox1->Size.Width*0.05,this->pictureBox1->Size.Height*0.05,this->pictureBox1->Size.Width*0.9,this->pictureBox1->Size.Height*0.9));

	grafx->Render(ViewWindow);



}


*/




[STAThreadAttribute()]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	
	
	

	// Create the main window and run it
	
	//CSecurityApp computerdata;
	//char *tmp = nullptr;

	// 得到IP位址
//	tmp = computerdata.GetIPAddress();				
//	String^	IPAddress =gcnew String(tmp);		

	//得到網卡位址
	//tmp = computerdata.GetMACAddress();
	//String^	MacAddress =gcnew String(tmp);	
	

//	String^ Information = IPAddress+MacAddress+Environment::UserDomainName+Environment::UserName+Environment::MachineName;
	

	RegistryKey ^ rk; 
	rk = Registry::LocalMachine->OpenSubKey(L"SOFTWARE\\CLT");
	String^ version = Convert::ToString(rk->GetValue("Software Version"));
	String^ company = Convert::ToString(rk->GetValue("Company"));
	String^ designer = Convert::ToString(rk->GetValue("Designer"));
	
	
	if( company == nullptr || designer == nullptr || version == nullptr ||String::Compare(company,"CLO") != 0  || String::Compare(designer,"HuiChengLin")  != 0) {
		return 0;
	}
	rk->Close();
	
	delete rk;


	Application::Run(gcnew Form1());

	
	
	
	
	return 0;
}



