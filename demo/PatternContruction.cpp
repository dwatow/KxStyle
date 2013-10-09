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


//Reg ��~~
using namespace Microsoft::Win32;



[STAThreadAttribute]
//[STAThreadAttribute]

//----------------------------------------------------------------------------------------------------
//Find�\�� ,��X�b���椺��B-SplineSurface�I-----------------------------------------------------------
//----------------------------------------------------------------------------------------------------









//-----------------------------------------------------------------------------------------------------
//�p��Regular�G�IOverlap ���ƥ�------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
/*
void Form1::CalculateRegularPatternOverlapNumber(){

	//���沣�ͺ��I���ˬd

	float size[2];
	int index = Form1::comboBoxRegularStyle->SelectedIndex;
	Mesh = inputdata.MeshNumber;		
	size[0] = inputdata.PlateWidth/(float)Mesh[0]; //���e��
	size[1] = inputdata.PlateHeight/(float)Mesh[1]; //������
	float tmpminvalue =  min(size[0],size[1]); //����j�p,���O�b�|
	int tmpOverlapCount = 0;
	for(int i = 0 ;i<NR ;i++){

		pt[i].Overlap = false; //��l���I���A

		switch(index){
			case 0: //�D����(�x�αƦC)
				if(pt[i].Radius > tmpminvalue/2  )	{					
					tmpOverlapCount++;					
					pt[i].Overlap = true;
				}
				break;
			case 1: //����
				if(inputdata.PatternShape == 0 && pt[i].Radius > tmpminvalue/1.414/2 ){ //���
					tmpOverlapCount++;	
					pt[i].Overlap = true;
				}else if(inputdata.PatternShape == 1 && pt[i].Radius > tmpminvalue/2) {  //�x��
					tmpOverlapCount++;
					pt[i].Overlap = true;
				}else if(inputdata.PatternShape == 2 && pt[i].Radius > tmpminvalue/2){  //�٧�
					tmpOverlapCount++;
					pt[i].Overlap = true;
				}

				break;
		}
	}
	

	ShowOverlap->Text = "���|���I�ƥ� : " + Convert::ToString(tmpOverlapCount);


}
*/

//-------------------------------------------------------------------------------------------------------
//�p�⤹�\�̤j�]�p�K�שM�̤p�]�p�K��---------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
/*
void Form1::CalculateMax_Min_AllowanceDensity(){
	float size[2];
	int index = Form1::comboBoxRegularStyle->SelectedIndex;
	Mesh = inputdata.MeshNumber;		
	size[0] = inputdata.PlateWidth/(float)Mesh[0]; //���e��
	size[1] = inputdata.PlateHeight/(float)Mesh[1]; //������
	float tmpminvalue =  min(size[0],size[1]); //����j�p,���O�b�|
	float maxden = 0,minden=0;

	switch(index){
		case 0: //�D����(�x�αƦC)
			
			if(inputdata.PatternShape == 0){ //���				
				maxden = 3.1415926535*tmpminvalue*tmpminvalue /(4*size[0]*size[1]);
				minden = 3.1415926535* 0.025 *0.025/(size[0] *size[1]);
			}else if(inputdata.PatternShape == 1) {  //�x��
				maxden = tmpminvalue*tmpminvalue /(size[0]*size[1]);
				minden = 0.05*0.05/(size[0] *size[1]);
			}else{  //�٧�
				maxden = tmpminvalue*tmpminvalue /(2*size[0]*size[1]);
				minden = 2* 0.025 *0.025/(size[0] *size[1]);
			}

			break;
		case 1: //���P			
			
			if(inputdata.PatternShape == 0){ //���
				maxden = 3.1415926535*tmpminvalue*tmpminvalue /(4*size[0]*size[1]);
				minden = 2*3.1415926535* 0.025 *0.025/(size[0] *size[1]);
			}else if(inputdata.PatternShape == 1) {  //�x��
				maxden = 2*tmpminvalue*tmpminvalue /(size[0]*size[1]);
				minden = 2*0.05*0.05/(size[0] *size[1]);
			}else{  //�٧�
				maxden = 2*tmpminvalue*tmpminvalue /(2*size[0]*size[1]);;
				minden = 2*2* 0.025 *0.025/(size[0] *size[1]);
			}

			break;
	}

	


		
	
		lblInformation ->Text = "" ;

}
*/
//-------------------------------------------------------------------------------------------------------
//�p�����ƥت��\��(�u���W�h�G�I����)-------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
/*
void Form1::CalculateRegularMeshNumber(){


	

	//�W�h�G�I��Grid�ƥس]�w
	if (radioBtnRegular->Checked == true) {
		int index = Form1::comboBoxRegularStyle->SelectedIndex;
		int pre_Mesh0 = inputdata.MeshNumber[0];
		int pre_Mesh1 = inputdata.MeshNumber[1];

		switch (index){
			case 0: //�D����
				inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
				inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2;							
				break;
			case 1://45��-����
				if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //��ΩM�٧�
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2/1.414;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/1.414;  //45D					
				}
				else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // �x��
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/2;
				}
				break;
			case 2://60��-����
				if(Form1::comboBoxPatternShape->SelectedIndex == 0 || Form1::comboBoxPatternShape->SelectedIndex == 2){   //��ΩM�٧�
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2/1.414;												
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/1.414/1.732;  //60D
				}
				else if(Form1::comboBoxPatternShape->SelectedIndex == 1){  // �x��
					MessageBox::Show("�ثe�x�εL60�׿���,�N��45�׿��ƨ��N");
					inputdata.MeshNumber[0] = (int)inputdata.PlateWidth/inputdata.PatternRadius/2;							
					inputdata.MeshNumber[1] = (int)inputdata.PlateHeight/inputdata.PatternRadius/2/2;
				}
				break;

		}
		//���b (�����J�� 0�����p��.�p��K�׷|�����D�o��)
		if (inputdata.PatternRadius == 0 || inputdata.PlateWidth == 0 || inputdata.PlateHeight == 0 ) {
			inputdata.MeshNumber[0] = 1;
			inputdata.MeshNumber[1] = 1;
		}


		//�Y����ƥا��� ,�K�׸�ƥ����M�� ,�GReset ,�B���I��Ƥ]�n�M��ResetPointData()
		if (pre_Mesh0 != inputdata.MeshNumber[0] || pre_Mesh1 != inputdata.MeshNumber[1])	{
			ResetMeshDate();
			ResetPointData();
		}
			
	}


}
*/

// -----------------------------------------------------------------------------------------------------
// ��ܻP�ˬd�\�� --------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

void Form1::ResetAll(){

	//�S�� Renew  ���Ѽ� : String^ Version ,String^ InputFileName 
// SettingForm ^ Set_Data_Form ,B_Spline_Curve^ Curve_Horizontal ,B_Spline_Curve^ Curve_Vertical 

			//���I����
			
			// �W�h�G�I
			if(this->Dot != nullptr){
				delete this->Dot;
				this->Dot = nullptr;
				this->Dot = gcnew Pattern();
				//this->Dot->Initialize_me();		
			}

			// IJP�G�I

			if(this->IJP_DotSize != nullptr){
				delete[] this->IJP_DotSize;

			}




			
			if(this->PatternDensity != nullptr)
				this->PatternDensity->ClearAll();


			//�M�׸�T
			if(this->project != nullptr){
				this->project->ClearAll();
			}
			
			
			this->GirdNumber = this->GirdNumber.Empty;
			//Main��� �Ѽ�
			if(this->MainData != nullptr){
				this->MainData->Initialize();
				this->UpdateMainFormData();
			}
			//Surface �Ѽ�
			if(this->Surface_Global_Design != nullptr) {
				
				delete this->Surface_Global_Design;
				this->Surface_Global_Design = nullptr;
				this->Surface_Global_Design = gcnew Nurbs::B_Spline_Surface();
				
				
			}
			

			//Curve �Ѽ�
			if(this->Curve_Horizontal != nullptr) {
				this->Curve_Horizontal = gcnew B_Spline_Curve();
				this->Curve_Horizontal->xInitialize(PointF(0,120),PointF(543,120));
			}
			if(this->Curve_Vertical != nullptr){
				this->Curve_Vertical = gcnew B_Spline_Curve();
				this->Curve_Vertical->xInitialize(PointF(0,120),PointF(543,120));
			}

			//LocalArea �Ѽ�,HotSpot �Ѽ�
			this->Cosmetic_LocalAreaData->Initialize();

			//�����ק�Ѽ�
			if(this->localsurfacedata != nullptr)
				this->localsurfacedata->Clear();

			//HotSpot �Ѽƭק�
			if(this->HotSpotData != nullptr){
				this->HotSpotData->Clear();
			}


			//LGP����Ѽ�
			if( this->LGPPolyLinePt != nullptr)
				this->LGPPolyLinePt->Clear();



			//LT�Ѽ� 
			this->Set_Data->Initialize_LT_Setting();

			
			//SurfaceDensity�Ѽ�
			if (this->SurfacePatternDensity != nullptr)
				this->SurfacePatternDensity->ClearAll();

			//PatternDensity�Ѽ�
			if (this->PatternDensity != nullptr)
				this->PatternDensity->ClearAll();
			
			delete this->Metafile_DesignGridDensity;
			this->Metafile_DesignGridDensity = nullptr;
			
			if(this->MemoryStream_DesignGridDensity != nullptr) this->MemoryStream_DesignGridDensity->Close();
				
			FileKind = -1;
			pictureBox1->Refresh();
			maxDen = 1000;

			
			//�ϧΤƥ\��Ѽ�Reset 

			if(this->MainPicMatrix != nullptr) this->MainPicMatrix->Reset() ;
			//if (this->ObjectCoordinate != nullptr)  ;  -->�٭n���]~~
			PicSacleVaule = 1.0f;
			if( this->Density_Bitmap != nullptr) {
				delete Density_Bitmap;
				Density_Bitmap = nullptr;
			}
			
			
			
	

		
			
			
			//�T��Reset

			this->lbl_DotPitch->Text = String::Format("���I Pitch (X,Y) = ");	
			this->lbl_AllowMaxDen->Text =String::Format("���\�̤j�K��  = " );
			this->lbl_AllowMinDen->Text = String::Format("���\�̤p�K��  = " );		
			this->lblActualDensityRange->Text = String::Format("�K�׽d��  = " );
			this->lbl_Total_Num->Text =  String::Format("�`���I�ƥ�  = " );		
			this->lbl_Current_File->Text = "�M���ɦW�� : " ;
			this->lbl_Pattern_File->Text = "Pattern�ɮצW�� :";
			Form1::Text ="CLT�G�I�{�� " + Version + " �ثe���| : " ;
			this->lblavgDen->Text = "�����л\�v : " ;
			this->lbl_MinPattern->Text = "�̤p���I(���|) : ";
			this->lbl_MaxPattern->Text = "�̤j���I(���|) : ";
			this->lblMinGap->Text = String::Format("(�D�Z��)�W�h�G�I�̤pGap : ");

		
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

	//�üƷs�W�Ѽ�
	this->txt_RandomCuttingForce->Text =  Convert::ToString(this->MainData->RandomStopForce);
	this->txt_RandomRebuildFrequency->Text =  Convert::ToString(this->MainData->RandomRebuildFrequency);
	this->chkRamdomStopForce->Checked =  (this->MainData->chkStopForce);
	this->chkRandomStopNumber->Checked = (this->MainData->chkStopNmber);

	//�K�׳]�p�覡 (���u�Φ���)
	switch(this->MainData->DensityDesignMethod) {
		case 0:
			this->���u�վ㧡��ToolStripMenuItem->Checked = true;
			this->�����վ㧡��ToolStripMenuItem->Checked = false;
			break;
		case 1:
			this->���u�վ㧡��ToolStripMenuItem->Checked = false;
			this->�����վ㧡��ToolStripMenuItem->Checked = true;
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

	//20110907 IJP�W�[�\��

	this->IJP_txt_DotSize->Text = Convert::ToString(this->MainData->IJP_DotSize);
	this->IJP_txt_BlockX->Text = Convert::ToString(this->MainData->IJP_BlockX);
	this->IJP_txt_BlockY->Text = Convert::ToString(this->MainData->IJP_BlockY);

	
	
						
	//20120319 UJP��r
	this->IJP_chk_TextEdit->Checked = this->MainData->IJP_chkTextEdit;
	this->IJP_cbo_TextLocation->SelectedIndex = this->MainData->IJP_TextLocation;
	this->IJP_txt_TextLocaX->Text = Convert::ToString(this->MainData->IJP_TextLocation_X);
	this->IJP_txt_TextLocaY->Text = Convert::ToString(this->MainData->IJP_TextLocation_Y);
	this->IJP_txt_TextHeight->Text = Convert::ToString(this->MainData->IJP_TextHeight);
	this->IJP_txt_TextLength->Text = Convert::ToString(this->MainData->IJP_TextLength);	
	this->IJP_txt_TEXT->Text = this->MainData->IJP_Text;





	//20120319 FM �üƧG�I
	this->txtFMPattern->Text = Convert::ToString(this->MainData->FM_DotSize);
	this->txtFMPatternGap->Text  = Convert::ToString(this->MainData->FM_MiniDotGap);
					
	if(this->CurrentDictionary != "")	Directory::SetCurrentDirectory(this->CurrentDictionary) ;

	//��ܥثe�@�Τ����ɮ� :
	if(this->InputFileName == "")		
		this->lbl_Current_File->Text = "�M���ɦW�� : " ;
	else
		this->lbl_Current_File->Text = "�M���ɦW�� : " + this->InputFileName;
		

	//DXF�ɮצW��  :
	this->lbl_Pattern_File->Text = "Pattern�ɮצW�� :" + this->PatternName;

	//���Title :
	Form1::Text ="CLT�G�I�{�� " + Version + " �ثe���| : "  + this->CurrentDictionary;







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
// 20090304���ͺ���K�� _�Q�Φ��u���ͺ���K��

	
		//���u�վ㧡��
		B_Spline_Curve^ tmpCurve_Vertical = gcnew B_Spline_Curve() ;
		B_Spline_Curve^ tmpCurve_Horizontal = gcnew B_Spline_Curve();



		try{	

			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("���I�|����̤pGap�� : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
			}
			

			//this->Density = gcnew GridDensity(this->GirdNumber.X,this->GirdNumber.Y,this->Set_Data->Color_MaxDenValue,this->Set_Data->Color_MinDenValue,this->btn_ProducePattern);  20091226�H�e
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
			
			
		
			this->toolStripStatusLabel1->Text = "���ͱK��";
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
						
					
				//	this->Density->SetDensity(tmpDen/100,ii,jj);  //20091226�H�e
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
			MessageBox::Show("���ͱK�׿��~!!");
			return false;
		}

		return true;
			
			
					
			
				


		








}
/*
bool Form1::ProduceGridDensity_FromDot(Point GridNumber ,GridDensity^ density ,Pattern^ dot){
	//���ͮ��I�K��,�Ѻ��I�p��o��,����Ƥ��i�H�Ӧh,�_�h�~�t�|�ܤj
//	density->xClearAll();  //20091226�H�e
	density->ClearAll();
	
	density->CreateGridDensity(GridNumber);
	//BuildRelation(dot,density,this->MainData ,GridNumber);







	return false ;


};
*/
 
bool Form1::ProduceGridDensity(){
// 20090304���ͺ���K��

	

		try{		
			

			
			this->PatternDensity = gcnew GridDensity(this->GirdNumber,this->MainData->LGPInformation);
			

			

			float size[2];
			float pos[2];

			size[0] = this->MainData->LGPInformation.Width  /this->GirdNumber.X;
			size[1] = this->MainData->LGPInformation.Height  / this->GirdNumber.Y;

			int tmpX ,tmpY;
			
			float tmpZ_pre;


		
			Point Resolution(this->GirdNumber.X+1,this->GirdNumber.Y+1); //Surface�n + 1
		//	Point Resolution(this->GirdNumber.X,this->GirdNumber.Y);

			this->Surface_Global_Design->ModifySurface_Resolution_Degree(Resolution);
			//this->Surface_Global_Design->ProduceSurface(this->GirdNumber.X+1,this->GirdNumber.Y+1);
			this->toolStripProgressBar1->Value = 0;
			this->toolStripStatusLabel1->Text = "���ͱK��";
			this->statusStrip1->Update();

			if(this->Set_Data->LimitDotSize == true){
				MessageBox::Show("���I�|����̤pGap�� : "+String::Format("{0:0.000}",this->MainData->MinDotGap));
			}

			Point SurfaceResolution = this->Surface_Global_Design->GetSurfaceResolution();

			for(int ii = 0 ; ii < this->GirdNumber.X ; ii++) {
				for(int jj = 0 ; jj<this->GirdNumber.Y ; jj++){
					int tmpIndex;
					pos[0] = (ii)*size[0];
					pos[1] = (jj)*size[1];
					tmpIndex = ii*this->GirdNumber.Y+jj;
						//��X���M�D�I�����
						float targetX,targetY;

						targetX = (ii +0.5f)*size[0];
						targetY = (jj +0.5f)*size[1];
					

						
						tmpX = (int)((ii/(float)this->GirdNumber.X)*(SurfaceResolution.X-1)) ;
						tmpY = (int)((jj/(float)this->GirdNumber.Y)*(SurfaceResolution.Y-1)) ;
						tmpZ_pre = this->Surface_Global_Design->GetSurface_Z_Value(targetX,targetY,tmpX,tmpY);
					
						if(this->Set_Data->LimitDotSize == true){
							if(tmpZ_pre >=this->maxDen) tmpZ_pre = this->maxDen;
						}
					//	this->Density->SetDensity(tmpZ_pre/100,ii,jj);  //20091226�H�e

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
			//	this->Density->GetDensity_Value(den,ii,jj);  //20091226�H�e
				Point index(ii,jj);
				den = this->Density->GetDensityValue(index);
				ratio = ratio + den;
			}
		}
		//�����л\�v
		ratio = ratio/(this->GirdNumber.X*this->GirdNumber.Y);

		DotNum = Math::Round(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height*ratio/(Math::PI*this->MainData->RandomDotSize*this->MainData->RandomDotSize/4));

		this->lbl_RandomTotalNum->Text = "�`���I�� : " + Convert::ToString(DotNum) ;

		this->Dot->BuildPattern(DotNum);

		this->Dot->ModifyRate_HotSpot = gcnew array<float>(this->Dot->GetDotNumber());
		this->Dot->ModifyRate_LocalArea = gcnew array<float>(this->Dot->GetDotNumber());
		for(int ii = 0 ; ii <this->Dot->GetDotNumber() ; ii++){
			this->Dot->ModifyRate_HotSpot->SetValue(1.0f,ii);
			this->Dot->ModifyRate_LocalArea->SetValue(1.0f,ii);
		}

		this->Dot->Dot_Force = gcnew array<PointF>(this->Dot->GetDotNumber());

		
		
		toolStripStatusLabel1->Text = "�ü�-Ū��LDS";

		double buffer[3] ={0,0,0};
		long bases[3];
		long ReadPrime;
		ReadPrime = ReadPrimes(&bases[0], 3);
		if (ReadPrime == 0){
			MessageBox::Show("ŪPrime�ɮ׿��~");
			return false;
		}
		LDSqBase*Numbers;
		Numbers=(LDSqBase*)new LDSqHalton(&bases[0], 3, DotNum, BGENAU, GENAU);


		//���LDS���
		toolStripStatusLabel1->Text = "�ü�-���GLDS";

		//�x�sLDS Z Value ,�@�����K�ײӤ��ɨϥ�
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

		//�p��Ҧ��K�׼ƭ�
		float tmp = 0;
		double totalDen = 0;
		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){				
			//	this->Density->GetDensity_Value(tmp,ii,jj);  20091226�H�e

				Point index(ii,jj);
				tmp = this->Density->GetDensityValue(index);
				totalDen = totalDen + tmp;				
			}
		}

		
		//���ͱK�װ϶�
		array<PointF,2>^ RatioRange = gcnew array<PointF,2>(this->GirdNumber.X,this->GirdNumber.Y);

		 tmp = 0;
		float tmpDen = 0;
		for(int ii = 0 ;ii <this->GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < this->GirdNumber.Y ;jj++){
				
				//this->Density->GetDensity_Value(tmp,ii,jj);  20091226�H�e
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


		toolStripStatusLabel1->Text = "�ü�-�������";

		//�إ߹������
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
			// a = Math::DivRem(10,3,b); b�O�l��
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



					
		toolStripStatusLabel1->Text = "�ü�-��l���I";

		
		//���ͪ�Ϻ��I
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

		

		//Verlet �p��
		
	
		array<array<int>^,2>^ PtIndex = gcnew array<array<int>^,2>(GirdNumber.X,GirdNumber.Y);

		//�NList �ഫ��Array
		BuildDensityArrayData(this->Dot,this->Density,this->GirdNumber , PtIndex);

		toolStripStatusLabel1->Text = "�ü�-Verlet�p��";

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
			this->lbl_RandomIteration->Text = "�|�N���� : " + Convert::ToString(countNumber);
			this->lbl_AverageForce->Text = "�����@�ΤO : " + Convert::ToString(maxForcePow2);
			this->lbl_RandomTotalNum->Text = "�`���I�� : " + Convert::ToString(DotNum-UnselectPt );
			this->lbl_SmallGapNumber->Text = "�p��Gap���I�� :" + Convert::ToString(SmallGapNumber );


			
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

	//��J�Ѽ� : 
	// GirdNumber,LGPInformation     --> �D�n�O�n�o��y��
	// Pattern_Arrangment , SurfacePatternDensity--> �ƦC�覡�M�K�ײ��͹��������|

	//���X�ƭ�
	//  array<PointF>^ Dot_Coordinate --> OK
	//	array<float>^ Dot_Diameter --> OK;	
	//	array<Point,2>^ DotDensity_Index -->OK;
	

	//�����X���ƭ�
	//	array<float>^ ModifyRate_HotSpot --> NA;
	//	array<float>^ ModifyRate_LocalArea --> NA;
	//	array<PointF>^ Dot_Force --> NA;
	//	array<float>^ MuraValue --> NA;

	


	
	
	
	
//	if (radioBtnRegular->Checked == true) {
		


		
		
		size[0] = tmpLGPSize.Width /tmpGridNumber.X; //���e��
		size[1] = tmpLGPSize.Height /tmpGridNumber.Y; //������
		//float tmpminvalue =  min(size[0],size[1]);
		float den = 0 ,maxden = 0 ,minden = 0;

		int tmpcount = 0;
		
		tmpDot->BuildRegularPattern(tmpGridNumber.X,tmpGridNumber.Y,tmpPatternArrangeMent);


	
	
		
		tmpDot->DotDensity_Index = gcnew array<Point,2>(4,tmpDot->GetDotNumber());
		
		


		switch(tmpPatternArrangeMent){

			

			case 0: //�D����(�x�αƦC)
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						
						float dot_dia = 0;


						//�]�w�b�|
						float tempDen = 0 ;
					
						Point index(ii,jj);
				
						//tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;


						int tmpIndex = ii*tmpGridNumber.Y +jj ;
						if(this->MainData->Pattern_Shape == 0){ //���						
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��							
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 4.0f);
						}

						//�]�w��m
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
				case 1  : // 45,60�׿��P
				//����W�����I�j�p
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//�]�w�b�|
						float dot_dia = 0;
						float tempDen = 0 ;
						

						

						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;


						int tmpIndex = ii*this->GirdNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //���							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��							
							float dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//�]�w��m
						
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
				
				//���涡������j�p

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//�]�w�b�|
						
						
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
						
						if(this->MainData->Pattern_Shape == 0){ //���							
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��							
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
			case 2 : // 45,60�׿��P



				//����W�����I�j�p
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//�]�w�b�|
						float dot_dia = 0;
						float tempDen = 0 ;
						
						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;



						int tmpIndex = ii*this->GirdNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //���
							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��
							
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
				
				//���涡������j�p

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//�]�w�b�|
						
							
						
						
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
						
						if(this->MainData->Pattern_Shape == 0){ //���
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 8.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//�]�w��m
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
				case 3: //30 �׿��P

					//����W�����I�j�p
				for(int ii = 0 ;ii < tmpGridNumber.X ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y ; jj++){

						//�]�w�b�|
						float dot_dia = 0;
						float tempDen = 0 ;
						
						Point index(ii,jj);
					
					//	tempDen = this->PatternDensity->GetDensityValue(index);
						tempDen = tmpDensity->GetDensityValue(index)/100;

						int tmpIndex = ii*tmpGridNumber.Y +jj ;
						
						if(this->MainData->Pattern_Shape == 0){ //���
							
							 dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��
							
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
				
				//���涡������j�p

				for(int ii = 0 ;ii < tmpGridNumber.X-1 ; ii++){
					for(int jj = 0 ;jj < tmpGridNumber.Y-1 ; jj++){

						//�]�w�b�|
						
							
						
						
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
						
						if(this->MainData->Pattern_Shape == 0){ //���
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 3.1415926535f/2.0f);
						}else if(this->MainData->Pattern_Shape == 1){  //�x��
							//pt[tmpIndex].Radius = sqrt(size[0] * size[1] * tempDen / 8.0f);
							dot_dia = 2*sqrt(size[0] * size[1] * tempDen / 8.0f);
						}

						//�]�w��m
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


	//���e ��ڱK��
//	if(drawinfomation->RedrawActualDensity){	
		if (radioBtnRegular->Checked == true) {
			if(ShowActualResultDensityToolStripMenuItem->Checked == true && inputdata.MeshNumber[0]*inputdata.MeshNumber[1] > 0 && pt != nullptr && mg != nullptr){
				SolidBrush^ Brush = gcnew SolidBrush(Color::Purple );
				for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){	
					float *pos ,*size , actualDensity = 0;
					float R=0,G=0,B=0;
					size = mg[i].GetMeshSize();
					pos  = mg[i].GetMeshPosition(); 
					if (inputdata.PatternShape == 0){ //���
						actualDensity = 3.1415926535 *pt[mg[i].PtNumbers].Radius*pt[mg[i].PtNumbers].Radius/(size[0]*size[1]);
					}else if (inputdata.PatternShape == 1){ //�x��
						actualDensity = 4* pt[mg[i].PtNumbers].Radius*pt[mg[i].PtNumbers].Radius/(size[0]*size[1]);
					}else { //�٧�
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

	//���� �]�p�K��
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
			
		


		//20080806�H�e---------------------------------------------------------

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
	//���e ����
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

	//���e ��l Pattern
//	if(drawinfomation->RedrawOriPattern){
	//	drawinfomation->RedrawOriPattern = false;
		for(int i=1;i<=NR;i++){			
			if (X != nullptr && Y != nullptr  && ((X[i-1]-PlateW/2)*tmpscale+tmpTranslateX < PicWidth) && ((Y[i-1]-PlateH/2)*tmpscaleY+tmpTranslateY < PicHeight)){
				switch(inputdata.PatternShape){
					case 0: //���						
						g->DrawEllipse(DrawDarkRedPen,float(X[i-1])-PlateW/2,float(Y[i-1])-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));	
						break;
					case 1: //�x��						
						g->DrawRectangle(DrawDarkRedPen,float(X[i-1])-PlateW/2,float(Y[i-1])-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));
						break;
					case 2:	//�٧�							
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
	//���e Pattern
//	if(drawinfomation->RedrawPattern){
	//	drawinfomation->RedrawPattern = false;

//-----20080806�H��--------------------------------------------------------------------------------------------------
		if(PatternLocation_Bmp == nullptr){
			if(this->ShowCurrentPatternToolStripMenuItem->Checked == true && NR>0) {
			//	PatternLocation_Bmp = gcnew Bitmap(this->pictureBox1->Size.Width,this->pictureBox1->Size.Height);
			//	PatternLocation_Bmp = gcnew Bitmap(900,900);
				PatternLocation_Bmp = gcnew Bitmap(inputdata.PlateWidth*10,inputdata.PlateHeight*10);
		//----Resulotion �v�T�쪺�O�e�����~��M�ϭ��j�p�L��
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
									case 0:  //���
									tmp_g->DrawEllipse(DrawSkyBluePen,float(px),float(py),float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));														
								break;
									case 1:	 //�x��
									tmp_g->DrawRectangle(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));								
								break;
									case 2:	 //�٧�	
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


//-------20080806�H�e--------------------------------------------------------------------------------------------------
//		if (NR != 0){		
//			g->DrawRectangle(gcnew Pen( Color::White,1/tmpscale),float(0)-PlateW/2,float(0)-PlateH/2,float(PlateW),float(PlateH));			
//		}
//		for(int i=1;i<=NR;i++){
//			double px,py,pz;
//			if (pt != nullptr) {
//				pt[i-1].GetPointPosition(px,py,pz);	
//				if ((pt[i-1].InsidePlateArea == true) &&(Form1::ShowCurrentPatternToolStripMenuItem->Checked == true) && ((px-PlateW/2)*tmpscale+tmpTranslateX < PicWidth) && ((py-PlateH/2)*tmpscaleY+tmpTranslateY < PicHeight)){
//					switch(inputdata.PatternShape){
//						case 0:  //���
//							g->DrawEllipse(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
//													
//							break;
//						case 1:	 //�x��
//							g->DrawRectangle(DrawSkyBluePen,float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
//							
//							break;
//						case 2:	 //�٧�	
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
	//���e ���A�X���I
//	if(drawinfomation->RedrawUnSuitablePattern){
	//	drawinfomation->RedrawUnSuitablePattern = false;
		for(int i=1;i<=NR;i++){
			if (pt != nullptr) {
				if ( pt[i-1].Overlap == true) {
				double px,py,pz;		
					pt[i-1].GetPointPosition(px,py,pz);	
					switch(inputdata.PatternShape){
							case 0:  //���	
								g->DrawEllipse(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));	
								//g->DrawEllipse(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));	
								break;
							case 1:	//�x��	
								g->DrawRectangle(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*pt[i-1].Radius),float(2*pt[i-1].Radius));
								//g->DrawRectangle(gcnew Pen( Color::Yellow,1/tmpscale),float(px)-PlateW/2,float(py)-PlateH/2,float(2*PatternRadius),float(2*PatternRadius));						
								break;
							case 2:	//�٧�	
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
	//�eB-Spline Surface Controll Pt
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

			//�e�@�Τ������I���C��

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

			//�e�@�Τ������I���C��
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
	//�����ק�-�o����I�Y���� 
	
	// Step 1 : �N�����ק��椤���Ѽ�(LocalAreaPara)�ഫ��Surface �i�H�x�s����ƫ� ,�s��SurfaceDataList ��
	// Step 2 : Ū�JSurfaceDataList ��� ,����Surface ��,�Nsurface �x�s��LocalSurface
    // Step 3 : ��Surface ��� ,��������I�y�� ,�i�槽���ק��Ҫ��p��        
	//         
	//         
	//




    //------------------------------Step 1 ----------------------------------------------------------------------
	//�ഫ�Ѽ�
	//1,) �N�����ק襤����� ,�ഫ��Surface �i�HŪ�����榡
	//2,) �إߤ@��array ,�x�s�����ק��椤���}�C�Ѽ� (data[8] .data[9], data[10])


	ArrayList^ SurfaceDataList = gcnew ArrayList(); //�x�s���ܬ��i��Surface Ū�J��array.
	array<PointF>^  number_pitch = gcnew array<PointF>(LocalAreaPara->Count) ; //�w�q���}�C���ƥةM���Z
	array<int>^   direction = gcnew array<int>(LocalAreaPara->Count); //�w�q���}�C����V
	


	for(int jj = 0 ; jj <LocalAreaPara->Count ;jj++){

		

		array<String^>^ data = (array<String^>^)LocalAreaPara->default[jj];
	

		//if(Convert::ToString(data->GetValue(data->Length-1)) == "1") {  //�N�ҥΪ��ƭ��ഫ��Surface �i�HŪ�����Ѽ� "1"��ܱҥ� ,"0"��ܨS���ҥ�

			number_pitch[jj].X = Convert::ToInt16( data[9] );
			number_pitch[jj].Y = Convert::ToSingle(data[10]);
			direction[jj] = Convert::ToInt16(data[8]);



			

			
				
				//Surface �w�q�� index: 0 -> �W�� ,    �����짽���ק諸�ѼƬO index : 11;
				//Surface �w�q�� index: 1-> U Value ,  �����짽���ק諸�ѼƬO index : 6;
				//Surface �w�q�� index: 2 -> V Value , �����짽���ק諸�ѼƬO index : 7;
				//Surface �w�q�� index: 3 -> Resolution X ,  �]�w�� 100
				//Surface �w�q�� index: 4 -> Resolution Y ,  �]�w�� 100
				//Surface �w�q�� index: 5 -> �����I�ƥ� X ,  �����짽���ק諸�ѼƬO index : 12;
				//Surface �w�q�� index: 6 -> �����I�ƥ� Y ,  �����짽���ק諸�ѼƬO index : 13;
				//Surface �w�q�� index: 7 + 4 i -> X�y�� ,   �����짽���ק諸�ѼƬO index : (16 + 4 i) + ���U���y�Ц�mX + �}�C���Z * i;
				//Surface �w�q�� index: 8 + 4 i-> Y�y�� ,    �����짽���ק諸�ѼƬO index : (17 + 4 i) + ���U���y�Ц�mY + �}�C���Z * i;
				//Surface �w�q�� index: 9 + 4 i-> Z�� ,      �����짽���ק諸�ѼƬO index : (14 + 4 i) ;
				//Surface �w�q�� index: 10 + 4 i-> �v�� ,    �����짽���ק諸�ѼƬO index : (15 + 4 i) ;

				// �����ק諸 index : 8  �w�q���}�C����V  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// �����ק諸 index : 9  �w�q���}�C�ƥ�
				// �����ק諸 index : 10  �w�q���}�C��Pitch 
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
					case 0: //"���U�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2]) ;
						shiftY = Convert::ToSingle(data[3]) ;
											
						break;
					case 1: //"���W�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 2: //"�k�W�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 3: //"�k�U�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  ;

						break;
					case 4: //"�����I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 5: //"�����I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 6: //"�k���I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 7: //"�W���I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

						break;
					case 8: //"�U���I�y��(X,Y) :"
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


				//�[�J��e����
				SurfaceDataList->Add(surfacedata);
				

	//	}
		

	}


	////------------------------------Step 2 ----------------------------------------------------------------------
	//���ͦ��� 
		//�N�����ק諸��J�Ѽ��ഫ��Surface �i�HŪ�����Ѽ�


	
	//�N�ഫ�n���Ѽ��x�s��Surface ��

	ArrayList^ LocalSurface = gcnew ArrayList();  //�x�sSurface ���e��

	for( int ii = 0 ;ii < SurfaceDataList->Count ; ii ++){
		Nurbs::B_Spline_Surface^ tmp_Surface;
		tmp_Surface = gcnew B_Spline_Surface();


		array<String^>^ temp = (array<String^>^ )SurfaceDataList->default[ii];

		tmp_Surface->SaveSurfaceData(temp);
		tmp_Surface->ModifySurface_Resolution_Degree();

		//�[�J��e����
		LocalSurface->Add(tmp_Surface);

	}






    //------------------------------Step 3 ----------------------------------------------------------------------
	//���ͭק���--------------------------------------------------------------------------------

	

	for(int ii = 0 ; ii < tmpFM_DotSize->GetLength(0) ; ii++){
		for(int mm = 0 ; mm < tmpFM_DotSize->GetLength(1) ; mm++){

			PointF coordinate = PointF(0.03125f+ii*(25.4/this->IJP_DPI) ,0.03125f+mm*(25.4/this->IJP_DPI));
			for(int jj = 0 ; jj <LocalSurface->Count ;jj++){
					Nurbs::B_Spline_Surface^ tmp_Surface =(Nurbs::B_Spline_Surface^)LocalSurface->default[jj];
					RectangleF tmp_boundary = tmp_Surface->Surface_Boundary::get();

				// �����ק諸 index : 8  �w�q���}�C����V  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// �����ק諸 index : 9  �w�q���}�C�ƥ�
				// �����ק諸 index : 10  �w�q���}�C��Pitch 

					PointF tmp_coordinate ; //�ثeSurface�y�Ъ���m
				
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

	// Step 0 : ��l��Dot Rate ;
	// Step 1 : �N�����ק��椤���Ѽ�(LocalAreaPara)�ഫ��Surface �i�H�x�s����ƫ� ,�s��SurfaceDataList ��
	// Step 2 : Ū�JSurfaceDataList ��� ,����Surface ��,�Nsurface �x�s��LocalSurface
    // Step 3 : ��Surface ��� ,��������I�y�� ,�i�槽���ק��Ҫ��p��        
	//         
	//         
	//

	//----------------------------Step 0 -----------------------------------------------------------------------


	for(int ii = 0 ; ii < Dot->GetDotNumber() ; ii++ ){
		Dot->ModifyRate_LocalArea[ii] = 1.0f;
	}


    //------------------------------Step 1 ----------------------------------------------------------------------
	//�ഫ�Ѽ�
	//1,) �N�����ק襤����� ,�ഫ��Surface �i�HŪ�����榡
	//2,) �إߤ@��array ,�x�s�����ק��椤���}�C�Ѽ� (data[8] .data[9], data[10])


	ArrayList^ SurfaceDataList = gcnew ArrayList(); //�x�s���ܬ��i��Surface Ū�J��array.
	array<PointF>^  number_pitch = gcnew array<PointF>(LocalAreaPara->Count) ; //�w�q���}�C���ƥةM���Z
	array<int>^   direction = gcnew array<int>(LocalAreaPara->Count); //�w�q���}�C����V
	


	for(int jj = 0 ; jj <LocalAreaPara->Count ;jj++){

		

		array<String^>^ data = (array<String^>^)LocalAreaPara->default[jj];
	

		//if(Convert::ToString(data->GetValue(data->Length-1)) == "1") {  //�N�ҥΪ��ƭ��ഫ��Surface �i�HŪ�����Ѽ� "1"��ܱҥ� ,"0"��ܨS���ҥ�

			number_pitch[jj].X = Convert::ToInt16( data[9] );
			number_pitch[jj].Y = Convert::ToSingle(data[10]);
			direction[jj] = Convert::ToInt16(data[8]);



			

			
				
				//Surface �w�q�� index: 0 -> �W�� ,    �����짽���ק諸�ѼƬO index : 11;
				//Surface �w�q�� index: 1-> U Value ,  �����짽���ק諸�ѼƬO index : 6;
				//Surface �w�q�� index: 2 -> V Value , �����짽���ק諸�ѼƬO index : 7;
				//Surface �w�q�� index: 3 -> Resolution X ,  �]�w�� 100
				//Surface �w�q�� index: 4 -> Resolution Y ,  �]�w�� 100
				//Surface �w�q�� index: 5 -> �����I�ƥ� X ,  �����짽���ק諸�ѼƬO index : 12;
				//Surface �w�q�� index: 6 -> �����I�ƥ� Y ,  �����짽���ק諸�ѼƬO index : 13;
				//Surface �w�q�� index: 7 + 4 i -> X�y�� ,   �����짽���ק諸�ѼƬO index : (16 + 4 i) + ���U���y�Ц�mX + �}�C���Z * i;
				//Surface �w�q�� index: 8 + 4 i-> Y�y�� ,    �����짽���ק諸�ѼƬO index : (17 + 4 i) + ���U���y�Ц�mY + �}�C���Z * i;
				//Surface �w�q�� index: 9 + 4 i-> Z�� ,      �����짽���ק諸�ѼƬO index : (14 + 4 i) ;
				//Surface �w�q�� index: 10 + 4 i-> �v�� ,    �����짽���ק諸�ѼƬO index : (15 + 4 i) ;

				// �����ק諸 index : 8  �w�q���}�C����V  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
				// �����ק諸 index : 9  �w�q���}�C�ƥ�
				// �����ק諸 index : 10  �w�q���}�C��Pitch 
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
					case 0: //"���U�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2]) ;
						shiftY = Convert::ToSingle(data[3]) ;
											
						break;
					case 1: //"���W�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 2: //"�k�W�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
						
						break;
					case 3: //"�k�U�I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  ;

						break;
					case 4: //"�����I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 5: //"�����I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  ;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 6: //"�k���I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

						break;
					case 7: //"�W���I�y��(X,Y) :"
						shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
						shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

						break;
					case 8: //"�U���I�y��(X,Y) :"
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


				//�[�J��e����
				SurfaceDataList->Add(surfacedata);
				

	//	}
		

	}


	////------------------------------Step 2 ----------------------------------------------------------------------
	//���ͦ��� 
		//�N�����ק諸��J�Ѽ��ഫ��Surface �i�HŪ�����Ѽ�


	
	//�N�ഫ�n���Ѽ��x�s��Surface ��

	ArrayList^ LocalSurface = gcnew ArrayList();  //�x�sSurface ���e��

	for( int ii = 0 ;ii < SurfaceDataList->Count ; ii ++){
		Nurbs::B_Spline_Surface^ tmp_Surface;
		tmp_Surface = gcnew B_Spline_Surface();


		array<String^>^ temp = (array<String^>^ )SurfaceDataList->default[ii];

		tmp_Surface->SaveSurfaceData(temp);
		tmp_Surface->ModifySurface_Resolution_Degree();

		//�[�J��e����
		LocalSurface->Add(tmp_Surface);

	}






    //------------------------------Step 3 ----------------------------------------------------------------------
	//���ͭק���--------------------------------------------------------------------------------


		for(int ii = 0 ; ii < Dot->GetDotNumber() ; ii++){
			PointF coordinate = Dot->Dot_Coordinate[ii];
			for(int jj = 0 ; jj <LocalSurface->Count ;jj++){
				Nurbs::B_Spline_Surface^ tmp_Surface =(Nurbs::B_Spline_Surface^)LocalSurface->default[jj];
				RectangleF tmp_boundary = tmp_Surface->Surface_Boundary::get();

			// �����ק諸 index : 8  �w�q���}�C����V  value = 0  : +X , value=1 : -X , value=2 : +Y .value= 3 : -Y
			// �����ק諸 index : 9  �w�q���}�C�ƥ�
			// �����ק諸 index : 10  �w�q���}�C��Pitch 

				PointF tmp_coordinate ; //�ثeSurface�y�Ъ���m
			
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
				//45��
				float gap = 0.25;
				//float d = (1.32*1.414-2*gap)/2;
				//float den = 3.14*d*d/2/1.32/1.32;
				//----------------------------------
				//60��
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

	// Step 1 :  �Ѻ��I�p��X�K�� (�W�h�G�I�O�T�w���ƭ� ,�üƧG�I�O�������ƭ�
	// Step 2 :  �N�K�׸�Ʀs��GridDensity ���榡 ,���ƭȪ��d��O0~1 (�]����ܱK�ת��C��ƭȬO0~1)

	//Question : �b�ƨ禡���}�@�Ӫ��� ,�åB�N������Return ����Ф� ,�O���餣�|�H�۰ƨ禡�����Ӯ��� ,
	//           �M�� ,�Y�ǤJ�@�ӫ���,�åB�b�ƨ禡���}�s���O����,�h�Y�ƨ禡������ ,�O����N���� ...
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

					//�p���ܰʫ᪺�K��(�A�Φb���O��DXF Ū�X���I�����p) ---------------------------------------------					
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
						
						 Point index(ii,jj);
						
						 this->PatternDensity->SetDensityValue(tmpDen,index);
					  }
				 }

			
				
			 }

		







*/


}
void Form1::DrawDesignGridDensity(GridDensity^ density){


	//�e�@�ӷs���ϧ�

		

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



		//����C��
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



		//����C��
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


//�x�s Pattern �ɮ� 
	if (this->Dot->Dot_Diameter != nullptr && this->Dot->GetDotNumber() > 0){
		this->�x�sPattern�ɮ�ToolStripMenuItem->Enabled = true;
		
	}else{
		this->�x�sPattern�ɮ�ToolStripMenuItem->Enabled = false;
		
	}

//�x�s LT �ɮ�
	if (this->Dot->Dot_Diameter != nullptr && this->Dot->GetDotNumber() > 0 && this->Set_Data != nullptr){
		this->SaveLTPatternFileToolStripMenuItem->Enabled = true;
	}else{
		this->SaveLTPatternFileToolStripMenuItem->Enabled = false;
	}	 


//�T�{���I�ק諸Button 
	if(this->Dot->GetDotNumber() == 0) this->btn_modifyDot->Enabled = false;
	if(this->Dot->GetDotNumber() == 0) this->btnResetModifyRate->Enabled = false;

//Button ���b
	if (this->backgroundWorker1->IsBusy == true ) this->btn_ProducePattern->Enabled = false;
	else this->btn_ProducePattern->Enabled = true;


//	if (this->Density->DensityValue->LongLength == 0) {
//		this->btn_modifyDot->Enabled = false;
//		this->btnResetModifyRate->Enabled = false;
//	}else {
//		this->btn_modifyDot->Enabled = true;
//		this->btnResetModifyRate->Enabled = true;
//	}

	



//�����վ㧡�׬O�̾�LGP�ؤo ��J���S�����~�M�w�O�_�i�H�ҥ� ,���]���ثe�w��LGP�ؤo�i�樾�b���\�� ,�G�]�w�û��ҥ� ...



//�G�u�ק� ,�ϰ�ק� , HotBar �ק�
	/*
	if(this->Dot->GetDotNumber() > 0 && this->Dot->ModifyRate_HotSpot->Length > 0 ){			
	
		this->HotBar�ק�ToolStripMenuItem->Enabled = true;
	}else{			

		this->HotBar�ק�ToolStripMenuItem->Enabled = false;
	}
	*/

	if(this->Dot->GetDotNumber() > 0 && this->Dot->ModifyRate_LocalArea->Length > 0){		
	//	this->�����ק�ToolStripMenuItem->Enabled = true;		
	}else{		
	//	this->�����ק�ToolStripMenuItem->Enabled = false;		
	}

	if(this->SurfacePatternDensity != nullptr  && this->SurfacePatternDensity->IsDensityEmpty == false && this->MainData->LGPInformation.IsEmpty == false){
	//	this->HotBar�ק�ToolStripMenuItem->Enabled = true;
	}else{
	//	this->HotBar�ק�ToolStripMenuItem->Enabled = false;
	}
	


//���ͺ��I���� 
	if (this->GirdNumber.X != 0 && this->GirdNumber.Y != 0 && this->GirdNumber.IsEmpty == false && this->Surface_Global_Design != nullptr )
		this->btn_ProducePattern->Enabled = true;						
	else
		this->btn_ProducePattern->Enabled = false;



//Menu---�x�s MenuItem ����

//�x�sPattern �ɮ� ,�x�sLT �ɮ�
	if( this->Dot->GetDotNumber()>0) {
		this->�x�sPattern�ɮ�ToolStripMenuItem->Enabled = true;
		this->SaveLTPatternFileToolStripMenuItem->Enabled = true;
	}
	else{ 
		this->�x�sPattern�ɮ�ToolStripMenuItem->Enabled = false;
		this->SaveLTPatternFileToolStripMenuItem->Enabled = false;
	}

//�x�sIJP �ɮ�
//	if(this->IJP_DotSize != nullptr){
		if(this->IJP_DotSize != nullptr && (this->IJP_DotSize->GetLength(0) > 0) && (this->IJP_DotSize->GetLength(1) > 0))  this->Save_IJP_File->Enabled = true;
		else  this->Save_IJP_File->Enabled = false;
//	}



//�x�s�M����



//Menu--- �s�� 


	if(this->GirdNumber.X == 0 ||this->GirdNumber.Y == 0 || this->MainData->LGPInformation.Width == 0 || this->MainData->LGPInformation.Height == 0) this->�����վ㧡��ToolStripMenuItem->Enabled = false;
	else this->�����վ㧡��ToolStripMenuItem->Enabled = true;
	
//	if(this->Surface_Global_Design == nullptr || this->Surface_Global_Design->IsSurfaceEmpty == true) this->�����ק�ToolStripMenuItem->Enabled = false ;
//	else this->�����ק�ToolStripMenuItem->Enabled = true ;
	


//Menu-- �u��
	if(this->Dot->GetDotNumber()>0 || (this->PatternDensity != nullptr && this->PatternDensity->IsDensityEmpty == false) ) this->���I�K�פ��RToolStripMenuItem->Enabled = true;
	else this->���I�K�פ��RToolStripMenuItem->Enabled = false;

	if(this->Dot->GetDotNumber()>0) this->�������RToolStripMenuItem->Enabled = true;
	else this->�������RToolStripMenuItem->Enabled = false;

//Form Btn :
	//���ͺ��I���s
	
	//if(this->Surface_Global_Design != nullptr && (this->Surface_Global_Design->IsInputDataChanged == true || this->localsurfacedata->Count > 0)) this->btn_ProducePattern->Enabled = true;
	//else this->btn_ProducePattern->Enabled = false;
	

	//��ܺ������s
//	if(this->ScreenMuraData != nullptr){
	if(this->Dot->MuraValue != nullptr) this->btnShowMura->Enabled = true;
		else this->btnShowMura->Enabled = false;
//	}

	//�������
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
        //�y�мȦs��(������)
		g->Clip =gcnew System::Drawing::Region( Rectangle(0,0,(int)this->MainData->LGPInformation.Width ,(int)this->MainData->LGPInformation.Height ) );
		
		g->Clear(Color::Black);
		
		


		for(int i=0;i< this->Dot->GetDotNumber();i++){
			PointF dot_coor;
			float dot_dia;
			this->Dot->GetDotValue(dot_coor,dot_dia,i);
			


			switch(this->MainData->Pattern_Shape){
				case 0:  //���
					//g->DrawEllipse(DrawSkyBluePen,float(px),float(py),(2*pt[i-1].Radius),(2*pt[i-1].Radius));	
					g->DrawEllipse(DrawSkyBluePen,dot_coor.X,dot_coor.Y,dot_dia,dot_dia);	
											
					break;
				case 1:	 //�x��
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

		//�e�����ק�~��<�����>
		//���禡�n��bDrawPic �᭱ ,���M�y���ഫ�|�����D

			array<PointF>^  number_pitch = gcnew array<PointF>(tmplocalsurfacedata->Count) ; //�w�q���}�C���ƥةM���Z
			array<int>^   direction = gcnew array<int>(tmplocalsurfacedata->Count); //�w�q���}�C����V
			Pen^ GreenPen = gcnew Pen( Color::Green,0.1/25.4 );
			

			for(int jj = 0 ; jj <tmplocalsurfacedata->Count ;jj++){

				array<String^>^ data = (array<String^>^)tmplocalsurfacedata->default[jj];
			
					number_pitch[jj].X = Convert::ToInt16( data[9] );
					number_pitch[jj].Y = Convert::ToSingle(data[10]);
					direction[jj] = Convert::ToInt16(data[8]);

						
					float shiftX = 0  ;
					float shiftY = 0  ;


					switch  (Convert::ToInt16(data[1])){
						case 0: //"���U�I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2]) ;
							shiftY = Convert::ToSingle(data[3]) ;
												
							break;
						case 1: //"���W�I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  ;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
							
							break;
						case 2: //"�k�W�I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);
							
							break;
						case 3: //"�k�U�I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  ;

							break;
						case 4: //"�����I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 5: //"�����I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  ;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 6: //"�k���I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4]);
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5])/2;

							break;
						case 7: //"�W���I�y��(X,Y) :"
							shiftX = Convert::ToSingle(data[2])  - Convert::ToSingle(data[4])/2;
							shiftY = Convert::ToSingle(data[3])  - Convert::ToSingle(data[5]);

							break;
						case 8: //"�U���I�y��(X,Y) :"
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
	//���禡�n��bDrawPic �᭱
	//�e�����ק�~��<����>

				
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

			if(Direction == 0 ) {  //X ��V 
				g->TranslateTransform(Coordinate.X+jj*Pitch,Coordinate.Y);
			} else{  //Y ��V
				g->TranslateTransform(Coordinate.X,Coordinate.Y+jj*Pitch);
			}
			g->RotateTransform(-RotateAngle);
			
			if (tmpLocalPart->Shape == "����")
				g->DrawEllipse(GreenPen,-LongAxis,-ShortAxis,2*LongAxis,2*ShortAxis);
			else if (tmpLocalPart->Shape == "�٧�"){
				array<PointF>^ pt = gcnew array<PointF>(4);
				pt[0] = PointF(-LongAxis,0); 
				pt[1] = PointF(0,ShortAxis); 
				pt[2] = PointF(LongAxis,0); 
				pt[3] = PointF(0,-ShortAxis); 

				g->DrawPolygon(GreenPen,pt);
			}

			//��^��l�y���I
			g->RotateTransform(RotateAngle);
			if(Direction == 0 ) {  //X ��V 
				g->TranslateTransform(-(Coordinate.X+jj*Pitch),-Coordinate.Y);
			} else{  //Y ��V
				g->TranslateTransform(-Coordinate.X,-(Coordinate.Y+jj*Pitch));
			}
			
		}
					
	}



}
void Form1::DrawPic(Graphics^ g,Point ScaleCenter,float scale ,Point ScreenPt){



		
			

					//�]�w�����y�Ь����U���O���I 
				 	this->MainPicMatrix->Reset();
					this->MainPicMatrix->Scale(1,-1);
					

					this->MainPicMatrix->Translate(0,-this->pictureBox1->Height);
					

					g->Clear(Color::Black);
				
								
					//���ʯS�w�I�ϧΨ�ù��W���Y�@�I
					this->MainPicMatrix->Translate(ScreenPt.X- scale*ScaleCenter.X,ScreenPt.Y -scale*ScaleCenter.Y);

					//�H�S�w�I������Scale�ϧ� 
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

					//�eLGP�~��)
					Pen^ GreenPen = gcnew Pen( Color::Green,0.1/25.4 );
					g->DrawRectangle(GreenPen,this->MainData->LGPInformation.X,this->MainData->LGPInformation.Y,this->MainData->LGPInformation.Width,this->MainData->LGPInformation.Height);

					//g->DrawEllipse(GreenPen,0,0,15,25);


					//�e����~��

					//�e�孱Profile


					//�e�K���C��Ϫ�


					//�e�����I 
					

					

					
					
					



					













					



					

								

		



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


	//------------���I�P�w-------------------------------------------------------------------------------------------------------------------
	
		//�T�{���I�O�_�ŦXMin Dot
		int countTV = 0;
		int countMNT = 0 ;
		int GapcountTV = 0;
		int GapcountMNT = 0;

	
		float MinGap = 1000.0f;

		

		//�]�w���I�����Z��	
		float pitch = 0;
		switch (this->MainData->Pattern_Arrangment){
			case 0 :  //0��
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X;
				break;
			case 1:   //45��
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X*0.707;
				break;
			case 2:   //60��
				pitch = this->MainData->LGPInformation.Width/this->GirdNumber.X;
				break;
			case 3:   //30��
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
			MessageBox::Show("���|�p�� 0.4 �����I��" + Convert::ToString(countTV) + "�� ,���|�p�� 0.25 �����I��" + Convert::ToString(countMNT) +"��","ĵ�i",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}else if(countTV > 0){
			MessageBox::Show("���|�p�� 0.4 �����I��" + Convert::ToString(countTV) + "��","ĵ�i",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}

		if(GapcountMNT >0){
				MessageBox::Show("Gap�p�� 0.1 �����I��" + Convert::ToString(GapcountTV) + "�� ,Gap�p�� 0.08 �����I��" + Convert::ToString(GapcountMNT) +"��","ĵ�i",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}else if (GapcountTV >0){
				MessageBox::Show("Gap�p�� 0.1 �����I��" + Convert::ToString(GapcountTV) + "��","ĵ�i",MessageBoxButtons::OK,MessageBoxIcon::Warning);
		}


		if(MinGap < 1000.0f)
			this->lblMinGap->Text = String::Format("(�D�Z��)�W�h�G�I�̤pGap : " + "{0:#0.0000}"+" mm ",MinGap);
		else
			this->lblMinGap->Text = String::Format("(�D�Z��)�W�h�G�I�̤pGap : ");

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

		
		this->lblavgDen->Text = String::Format("�����л\�v : " + "{0:#0.00}"+" % ",patternarea/(this->MainData->LGPInformation.Width*this->MainData->LGPInformation.Height)*100);
		this->lbl_MinPattern->Text = String::Format("�̤p���I(���|) : " + "{0:#0.0000}"+" mm",MinDia);
		this->lbl_MaxPattern->Text = String::Format("�̤j���I(���|) : " + "{0:#0.0000}"+" mm ",MaxDia);

	


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
		
		// -------------����Curve

		
		array<PointF>^ cPt = gcnew array<PointF>(5);
		cPt[0].Y = 1; //��tGain �ȥû��O1 
		cPt[0].X = 0;
		cPt[4].Y =  gainVaule; //����Gain �ȬO�ϥΪ̿�J
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
		
		// -------------����Curve

		tmpPart->BuildCurve(101);




		 //--------------------------













		 //���ͷs���K��


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //���J�I
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
						
						 if(Direction == 0 ) {//X ��V
							pt.X = pt.X - kk*Pitch ;	
						 }else {						
							pt.Y = pt.Y - kk*Pitch;
						 }
						
						 
						 //�y�б���
						 tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
						 tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);

						 if(Block.Contains(pt) == true){


							  if(tmpPart->Shape == "����"){
									//�i����ΧP�_						
									 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
								 
									//��ܦb��ꤺ
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

										if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

										tmpDot->ModifyRate_LocalArea->SetValue(ratio*tmpZ,ii);															
									}
							  }else if(tmpPart->Shape == "�٧�"){

								  	float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
									float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
									if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //��ܦb�٫���

										float tmpZ;
										if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
											//�Ĥ@�βĤT�H��
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
										}else{
											tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
										}

										float ratio = tmpDot->ModifyRate_LocalArea[ii];

										if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

										tmpDot->ModifyRate_LocalArea->SetValue(ratio*tmpZ,ii);	


									}


							  }

						 }
					 }

			}

								
	}

	return false;



}
bool Form1::ProduceHotSpotDensity(GridDensity^ tmpdensity ,ArrayList^ tmphotSpotData){ //����HotSpot�K��Data.



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
		
		// -------------����Curve

		
		array<PointF>^ cPt = gcnew array<PointF>(5);
		cPt[0].Y = 1; //��tGain �ȥû��O1 
		cPt[0].X = 0;
		cPt[4].Y =  gainVaule; //����Gain �ȬO�ϥΪ̿�J
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
		
		// -------------����Curve

		tmpPart->BuildCurve(101);




		 //--------------------------



		 //���ͷs���K��


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //���J�I
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
						 if(Direction == 0 ) {//X ��V
							pt.X = MeshValue.X+MeshValue.Width/2 - kk*Pitch ;
							pt.Y = MeshValue.Y+MeshValue.Height/2 ;
						 }else {
							pt.X = MeshValue.X+MeshValue.Width/2  ;
							pt.Y = MeshValue.Y+MeshValue.Height/2 - kk*Pitch;
						 }
						 
						 //�y�б���
						 tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
						 tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);

						 if(Block.Contains(pt) == true){

							 if(tmpPart->Shape == "����"){
									//�i����ΧP�_						
									 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
								 
									//��ܦb��ꤺ
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

										if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

										tmpdensity->SetDensityValue(den*tmpZ*tmpZ,Point(ii,jj));
									
									}
							 }else if(tmpPart->Shape == "�٧�"){

								float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //��ܦb�٫���

									float tmpZ;
									if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
										//�Ĥ@�βĤT�H��
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
									}else{
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
									}

									float den = tmpdensity->GetDensityValue(Point(ii,jj));

									if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

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
	//����HotSpot FM���I

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
		
		// -------------����Curve

		tmpPart->BuildCurve(101);




		 //--------------------------


		 //���ͷs���K��


		 	float max = Math::Max(2*LongAxis,2*ShortAxis);

			 RectangleF Block(Coordinate.X-max/2,Coordinate.Y-max/2,max,max);

			 float thda;
			 PointF pt ;
			 PointF tmp_pt;
			 float dia;

			 float R1 ;
			 float ratio = 1 ;
			
			 RectangleF MeshValue;

			 
			 //���J�I
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
						 if(Direction == 0 ) {//X ��V
							pt.X = 0.03175f + ii*(25.4/this->IJP_DPI) - kk*Pitch ;
							pt.Y = 0.03175f + jj*(25.4/this->IJP_DPI) ;
						 }else {
							pt.X = 0.03175f + ii*(25.4/this->IJP_DPI)  ;
							pt.Y = 0.03175f + jj*(25.4/this->IJP_DPI)  - kk*Pitch;
						 }
						 

						



						 


						 if(Block.Contains(pt) == true){

							 //�y�б���
							tmp_pt.X =Coordinate.X+ Math::Cos(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) - Math::Sin(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);
							tmp_pt.Y =Coordinate.Y+ Math::Sin(RotateAngle*Math::PI/180)*(pt.X-Coordinate.X) + Math::Cos(RotateAngle*Math::PI/180)*(pt.Y-Coordinate.Y);


							if(tmpPart->Shape == "����"){
								//�i����ΧP�_						
								 value =  Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[0].X,2) + Math::Pow(tmp_pt.Y-focusPt[0].Y,2)) +Math::Sqrt(Math::Pow(tmp_pt.X-focusPt[1].X,2) + Math::Pow(tmp_pt.Y-focusPt[1].Y,2));
							 
								//��ܦb��ꤺ
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

									if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

									tmpFM_DotSize->SetValue(den*tmpZ*tmpZ,ii,jj);
																
								}
							}else if(tmpPart->Shape == "�٧�"){
								float valueA = (tmp_pt.X-  Coordinate.X)/LongAxis-(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								float valueB = (tmp_pt.X-  Coordinate.X)/LongAxis+(tmp_pt.Y - Coordinate.Y)/ShortAxis ;
								if( valueA <=1 && valueA >=-1 && valueB <=1 && valueB >=-1){ //��ܦb�٫���

									float tmpZ;
									if((tmp_pt.X-  Coordinate.X)*(tmp_pt.Y - Coordinate.Y)>=0){
										//�Ĥ@�βĤT�H��
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueB) ,0);
									}else{
										tmpZ = tmpPart->tmpCurve->GetCurve_Z_Value(1.0f-Math::Abs(valueA) ,0);
									}
									
									float den = tmpFM_DotSize[ii,jj];

									if(tmpZ < 0) tmpZ = 0; // �]�w�U�{�Ȭ�0 

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

// 20080806�H�e--------------------------------------------------------
//	switch (situation){	
//	case 0:		
//		break;
//	case 1:   //��j	
//
//		grafx->Graphics->ScaleTransform(1.1,1.1);	
//		break;
//	case 2: //�Y�p
//		grafx->Graphics->ScaleTransform(1/1.1,1/1.1);
//	
//
//		break;
//	case 3: //�^�Э쪬
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

// 20080806�H��----------------------------------------------------------
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
	case 1:   //��j	

	
		ViewScale = ViewScale *1.2;
		
		//grafx->Graphics->DrawImage(DesignDensity_Bmp,Rectangle(0,0,inputdata.PlateWidth*5,inputdata.PlateHeight*5));
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,PointF(0,0));
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,destPara);
		
     
		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width,this->pictureBox1->Size.Height),Rectangle(0,0,this->pictureBox1->Size.Width/ViewScale,this->pictureBox1->Size.Width/ViewScale),units);
		break;
	case 2: //�Y�p
		//grafx->Graphics->ScaleTransform(1/1.1,1/1.1);
		//grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width/2,this->pictureBox1->Size.Height/2));
		  // Draw image to screen.
		ViewScale = ViewScale /1.2;

		grafx->Graphics->DrawImage(PatternLocation_Bmp,Rectangle(0,0,this->pictureBox1->Size.Width,this->pictureBox1->Size.Height),Rectangle(0,0,this->pictureBox1->Size.Width/ViewScale,this->pictureBox1->Size.Width/ViewScale),units);

		//grafx->Graphics->DrawImage( PatternLocation_Bmp, destPara, srcRect, units );

		break;
	case 3: //�^�Э쪬
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

	// �o��IP��}
//	tmp = computerdata.GetIPAddress();				
//	String^	IPAddress =gcnew String(tmp);		

	//�o����d��}
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



