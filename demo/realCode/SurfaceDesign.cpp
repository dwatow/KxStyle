#include "StdAfx.h"
#include "SurfaceDesign.h"



using namespace PatternContruction;
using namespace System::Drawing::Drawing2D;


void SurfaceDesign::Build_DataGrid(){
	
	int Num_H = Convert::ToInt16(this->txtH_Controll_Num->Text); 
	int Num_V = Convert::ToInt16(this->txtV_Controll_Num->Text);

	this->dataGridView1->ColumnCount::set(Num_H) ;
	this->dataGridView_X_Location->ColumnCount::set(Num_H);
	this->dataGridView_Y_Location->ColumnCount::set(Num_H);

	this->dataGridView1->RowCount::set(Num_V) ;
	this->dataGridView_X_Location->RowCount::set(Num_V);
	this->dataGridView_Y_Location->RowCount::set(Num_V);




	
	
//*
			for(int ii= 0 ; ii<Num_H ; ii++){
			//	System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
			//	Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			//	this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {Column1});
			//	Column1->HeaderText = L"橫向控制點"+ Convert::ToString(ii +1);
			//	Column1->Name = L"Column" + Convert::ToString(ii+1);
				this->dataGridView1->Columns->default[ii]->Name = L"橫向控制點: " + Convert::ToString(ii+1);
				

				for(int jj = 0 ; jj <Num_V ;jj++){
					
					dataGridView1->default[ii,jj]->Value = nullptr;
					
					
				}
			}
//*/
	
	/*


				 System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
				Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {Column1});
				Column1->HeaderText = L"Column1";
				Column1->Name = L"Column1";

				String^ test = Convert::ToString(this->dataGridView1->default[0,0]->Value);

				MessageBox::Show(test);
				
*/				
	

	

}

/*
void SurfaceDesign::DrawSurface1214(){
		int picwidth = this->pic_SurfaceDesign->Width;
	int picheight = this->pic_SurfaceDesign->Height;

	// --- 20080903--------繪圖------
	MemoryStream_DesignDensity = gcnew MemoryStream();			
	Graphics^ tmpG = this->pic_SurfaceDesign->CreateGraphics();		
	Metafile_DesignDensity =gcnew Metafile(MemoryStream_DesignDensity,tmpG->GetHdc());
	tmpG->ReleaseHdc();

	SurfaceDensity = this->pic_SurfaceDesign->CreateGraphics();



	Graphics^ g = g->FromImage(this->Metafile_DesignDensity);

	 Matrix^ myMatrix = gcnew Matrix(1,0,0,-1,0,0);
   
	 g->Transform = myMatrix;

	 
	g->PageScale =1;
	g->PageUnit= GraphicsUnit::Millimeter;
    //座標暫存區(垂直面)
	g->Clip =gcnew System::Drawing::Region( RectangleF(0.0f,0.0f,this->PlateWidth,this->PlateHeight) );
	g->Clear(Color::Black);

	
	SolidBrush^ Brush = gcnew SolidBrush(Color::Purple );
							
	for(int ii = 0 ;ii < Uni_Surface->Surface->GetLength(0)-1 ; ii ++){
		for (int jj = 0 ; jj < Uni_Surface->Surface->GetLength(1)-1 ;jj++){
			

			float tmpZ = (Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii,jj))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii,jj+1))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii+1,jj))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii+1,jj+1)))/400;
			PointF tmpLocation1 = (PointF)(this->Uni_Surface->Surface->GetValue(ii,jj));
			PointF tmpLocation2 = (PointF)(this->Uni_Surface->Surface->GetValue(ii,jj+1));
			PointF tmpLocation3 = (PointF)(this->Uni_Surface->Surface->GetValue(ii+1,jj+1));
			PointF tmpLocation4 = (PointF)(this->Uni_Surface->Surface->GetValue(ii+1,jj));

			array<PointF>^ curvePoints = {tmpLocation1,tmpLocation2,tmpLocation3,tmpLocation4};

			float R,G,B;
			SetDensityColor(tmpZ,R,G,B);			
			Brush->Color = Color::FromArgb((int)R,(int)G,(int)B);
			
			g->FillPolygon(Brush,curvePoints);
		
		}
	}


	delete g;
	 this->SurfaceDensity->ScaleTransform(0.5,0.5);
	
    this->SurfaceDensity->DrawImage(this->Metafile_DesignDensity,0,0);


	
	MemoryStream_DesignDensity->Close();

}
*/
/*
void SurfaceDesign::DrawSurface(){

	int picwidth = this->pic_SurfaceDesign->Width;
	int picheight = this->pic_SurfaceDesign->Height;

	// --- 20080903--------繪圖------
	MemoryStream_DesignDensity = gcnew MemoryStream();			
	Graphics^ tmpG = this->pic_SurfaceDesign->CreateGraphics();		
	Metafile_DesignDensity =gcnew Metafile(MemoryStream_DesignDensity,tmpG->GetHdc());
	tmpG->ReleaseHdc();

	SurfaceDensity = this->pic_SurfaceDesign->CreateGraphics();



	Graphics^ g = g->FromImage(this->Metafile_DesignDensity);
	g->PageScale = 1;
	g->PageUnit= GraphicsUnit::Pixel;
    //座標暫存區(垂直面)
	g->Clip =gcnew System::Drawing::Region( RectangleF(0.0f,0.0f,this->PlateWidth,this->PlateHeight) );
	g->Clear(Color::Black);

	
	SolidBrush^ Brush = gcnew SolidBrush(Color::Purple );
							
	for(int ii = 0 ;ii < Uni_Surface->Surface->GetLength(0)-1 ; ii ++){
		for (int jj = 0 ; jj < Uni_Surface->Surface->GetLength(1)-1 ;jj++){
			

			float tmpZ = (Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii,jj))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii,jj+1))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii+1,jj))+Convert::ToSingle(this->Uni_Surface->Surface_Z->GetValue(ii+1,jj+1)))/400;
			PointF tmpLocation1 = (PointF)(this->Uni_Surface->Surface->GetValue(ii,jj));
			PointF tmpLocation2 = (PointF)(this->Uni_Surface->Surface->GetValue(ii,jj+1));
			PointF tmpLocation3 = (PointF)(this->Uni_Surface->Surface->GetValue(ii+1,jj+1));
			PointF tmpLocation4 = (PointF)(this->Uni_Surface->Surface->GetValue(ii+1,jj));

			array<PointF>^ curvePoints = {tmpLocation1,tmpLocation2,tmpLocation3,tmpLocation4};

			float R,G,B;
			SetDensityColor(tmpZ,R,G,B);			
			Brush->Color = Color::FromArgb(R,G,B);
			
			g->FillPolygon(Brush,curvePoints);
		
		}
	}

	delete g;


	float scale = 0;
	if(this->PlateHeight >= this->PlateWidth){
		scale = picheight/this->PlateHeight*0.8f;
		this->SurfaceDensity->DrawImage(this->Metafile_DesignDensity,(picwidth-scale*this->PlateWidth)/2,(float)picheight/10,scale*this->PlateWidth,scale*this->PlateHeight);
	}
	else{
		scale = picwidth/this->PlateWidth*0.8f;
		this->SurfaceDensity->DrawImage(this->Metafile_DesignDensity,(float)picwidth/10,(picheight-scale*this->PlateHeight)/2,scale*this->PlateWidth,scale*this->PlateHeight);
	}
	
	MemoryStream_DesignDensity->Close();
	
}
*/
void SurfaceDesign::SetDensityColor(float &density ,float &R ,float &G ,float &B){

	
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
void SurfaceDesign::SetDataGridRow_Column(Point PtNumber){

			

			//建立DataGrid ------------------------------------------------------------------------------------
			this->dataGridView1->ColumnCount::set(PtNumber.X) ;
			this->dataGridView_X_Location->ColumnCount::set(PtNumber.X);
			this->dataGridView_Y_Location->ColumnCount::set(PtNumber.X);
			this->dataGridView_Weight->ColumnCount::set(PtNumber.X);
			this->dataGridView_ActualDesign_Density->ColumnCount::set(PtNumber.X);

			this->dataGridView1->RowCount::set(PtNumber.Y) ;
			this->dataGridView_X_Location->RowCount::set(PtNumber.Y);
			this->dataGridView_Y_Location->RowCount::set(PtNumber.Y);
			this->dataGridView_Weight->RowCount::set(PtNumber.Y);
			this->dataGridView_ActualDesign_Density->RowCount::set(PtNumber.Y);



}