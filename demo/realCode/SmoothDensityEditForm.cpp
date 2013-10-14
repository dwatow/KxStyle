#include "StdAfx.h"
#include "SmoothDensityEditForm.h"
#include <math.h>
#include "FileIO.h"
#define Iterative  24               /* 曲線模擬的線數(必須小於32) */
#define Iterative2 (Iterative*Iterative)
#define Iterative3 (Iterative2*Iterative)









using namespace PatternContruction ;
void SmoothDensityEditForm::DrawCoordinate(float X_Coordinate_Range, float Y_Coordinate_Range , Graphics^ CurrentDraw,int Grid){
	//Left_Right
	



	System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",8 );
	SolidBrush^ drawBrush = gcnew SolidBrush( Color::Red );
	String^ drawString = nullptr;
	PointF drawPoint ;

	

		//畫邊框
			CurrentDraw->DrawLine(gcnew Pen( Color::SkyBlue,1),(float)30,(float)30,(float)FrameSize_W-30,(float)30);
			CurrentDraw->DrawLine(gcnew Pen( Color::SkyBlue,1),(float)30,(float)FrameSize_H-30,(float)FrameSize_W-30,(float)FrameSize_H-30);
			CurrentDraw->DrawLine(gcnew Pen( Color::SkyBlue,1),(float)30,(float)30,(float)30,(float)FrameSize_H-30);
			CurrentDraw->DrawLine(gcnew Pen( Color::SkyBlue,1),(float)FrameSize_W-30,(float)30,(float)FrameSize_W-30,(float)FrameSize_H-30);

		//畫網格

		for(float i = 1 ; i < Grid ; i ++){
			CurrentDraw->DrawLine(gcnew Pen( Color::Silver,1),(float)30,(float)(i)*(FrameSize_H-60)/Grid+30,(float)FrameSize_W-30,(float)(i)*(FrameSize_H-60)/Grid+30);
			CurrentDraw->DrawLine(gcnew Pen( Color::Silver,1),(float)(i)*(FrameSize_W-60)/Grid+30,(float)30,(float)(i)*(FrameSize_W-60)/Grid+30,(float)FrameSize_H-30);
	
		}

		//畫位置和密度座標

		for(float i = 0 ; i <= Grid ; i ++){
			//畫水平座標
			drawString = Convert::ToString(i*X_Coordinate_Range/Grid);
			drawPoint = PointF((i)*((float)FrameSize_W-60)/(float)Grid+30,(float)FrameSize_H-30);
			// Draw string to screen.			
			CurrentDraw->DrawString(drawString, drawFont, drawBrush, drawPoint);
		
			//畫垂直座標
			// Create string to draw.
			if (i!=0){
				drawString = Convert::ToString(i*Y_Coordinate_Range/Grid);
				drawPoint = PointF(5,(Grid-i)*(FrameSize_H-60)/Grid+30);
				// Draw string to screen.			
				CurrentDraw->DrawString(drawString, drawFont, drawBrush, drawPoint);	
			}
		}

		//畫單位

			drawString = "mm";
			drawPoint = PointF((float)FrameSize_W-20,(float)FrameSize_H-15);
			CurrentDraw->DrawString(drawString, drawFont, drawBrush, drawPoint);
			drawString = "Den";
			drawPoint = PointF(5,5);
			CurrentDraw->DrawString(drawString, drawFont, drawBrush, drawPoint);


	
//	}



}

/*

void SmoothDensityEditForm::AddControlPt(int X,int Y,int DrawPic){

	if (DrawPic == 0){
		Array::Resize(ControlPt_X,  ControlPt_X->Length+ 1);
		Array::Resize(ControlPt_Y, ControlPt_Y->Length + 1);
		ControlPt_X->SetValue(X,ControlPt_X->Length-1);
		ControlPt_Y->SetValue(Y,ControlPt_Y->Length-1);
		Array::Sort(ControlPt_X,ControlPt_Y);
		



	}else{
		Array::Resize(ControlPt_X_L,ControlPt_X_L->Length+ 1);
		Array::Resize(ControlPt_Y_L,ControlPt_Y_L->Length + 1);
		ControlPt_X_L->SetValue(X,ControlPt_X_L->Length-1);
		ControlPt_Y_L->SetValue(Y,ControlPt_Y_L->Length-1);
		Array::Sort(ControlPt_X_L,ControlPt_Y_L);

	}

};
void SmoothDensityEditForm::RemoveControlPt(int X ,int Y,int DrawPic){
	
	if (DrawPic == 0){
		int Length_X;
		Length_X = ControlPt_X->Length;
		for(int i= 0 ;i <Length_X ; i++){
			if(fabs(Convert::ToSingle(ControlPt_X->GetValue(i))-X) <5 && fabs(Convert::ToSingle(ControlPt_Y->GetValue(i))-Y) < 5){
				if ( i == CurrentControlPt_Index ) CurrentControlPt_Index = -1;
                if ( i < CurrentControlPt_Index  ) CurrentControlPt_Index = CurrentControlPt_Index-1;
				Array::Clear(ControlPt_X,i,1);
				Array::Clear(ControlPt_Y,i,1);			
				Array::Sort(ControlPt_X,ControlPt_Y);
				Array::Reverse(ControlPt_X);
				Array::Reverse(ControlPt_Y);
				Array::Resize(ControlPt_X,  ControlPt_X->Length-1);
				Array::Resize(ControlPt_Y,  ControlPt_Y->Length-1);
				Array::Reverse(ControlPt_X);
				Array::Reverse(ControlPt_Y);			
				break;
			}
		}
	}else{
		int Length_X;
		Length_X = ControlPt_X_L->Length;
		for(int i= 0 ;i <Length_X ; i++){
			if(fabs(Convert::ToSingle(ControlPt_X_L->GetValue(i))-X) <5 && fabs(Convert::ToSingle(ControlPt_Y_L->GetValue(i))-Y) < 5){
				if ( i == CurrentControlPt_Index ) CurrentControlPt_Index = -1;
                if ( i < CurrentControlPt_Index  ) CurrentControlPt_Index = CurrentControlPt_Index-1;
				Array::Clear(ControlPt_X_L,i,1);
				Array::Clear(ControlPt_Y_L,i,1);			
				Array::Sort(ControlPt_X_L,ControlPt_Y_L);
				Array::Reverse(ControlPt_X_L);
				Array::Reverse(ControlPt_Y_L);
				Array::Resize(ControlPt_X_L,  ControlPt_X_L->Length-1);
				Array::Resize(ControlPt_Y_L,  ControlPt_Y_L->Length-1);
				Array::Reverse(ControlPt_X_L);
				Array::Reverse(ControlPt_Y_L);			
				break;
			}
		}

	}

};
void SmoothDensityEditForm::MoveControlPt(int X,int Y ,int DrawPic){





	
	if (DrawPic == 0){
		
		if (CurrentControlPt_Index != -1) {
			ControlPt_X->SetValue(X,CurrentControlPt_Index);
			ControlPt_Y->SetValue(Y,CurrentControlPt_Index);
			Array::Sort(ControlPt_X,ControlPt_Y);
		}
		//SmoothDensityEditForm::Distribution_Vertical->Cursor = System::Windows::Forms::Cursors::Hand;

//
//		int Length_X;
//		Length_X = ControlPt_X->Length;
//		for(int i= 0 ;i <Length_X ; i++){
//			if(fabs(Convert::ToSingle(ControlPt_X->GetValue(i))-X) < 5 && fabs(Convert::ToSingle(ControlPt_Y->GetValue(i))-Y) < 5){
//				SmoothDensityEditForm::Distribution_Vertical->Cursor = System::Windows::Forms::Cursors::Hand;
//				SmoothDensityEditForm::Distribution_Horizontal->Cursor = System::Windows::Forms::Cursors::Hand;
//				ControlPt_X->SetValue(X,i);
//				ControlPt_Y->SetValue(Y,i);
//				Array::Sort(ControlPt_X,ControlPt_Y);
//
//				break;
//			}
//		}
//
	}else{


		if (CurrentControlPt_Index != -1) {
			ControlPt_X_L->SetValue(X,CurrentControlPt_Index);
			ControlPt_Y_L->SetValue(Y,CurrentControlPt_Index);
			Array::Sort(ControlPt_X_L,ControlPt_Y_L);
		}
		
//		int Length_X;
//		Length_X = ControlPt_X_L->Length;
//		for(int i= 0 ;i <Length_X ; i++){
//			if(fabs(Convert::ToSingle(ControlPt_X_L->GetValue(i))-X) < 5 && fabs(Convert::ToSingle(ControlPt_Y_L->GetValue(i))-Y) < 5){
//				SmoothDensityEditForm::Distribution_Vertical->Cursor = System::Windows::Forms::Cursors::Hand;
//				SmoothDensityEditForm::Distribution_Horizontal->Cursor = System::Windows::Forms::Cursors::Hand;
//				ControlPt_X_L->SetValue(X,i);
//				ControlPt_Y_L->SetValue(Y,i);
//				Array::Sort(ControlPt_X_L,ControlPt_Y_L);
//
//				break;
//			}
//		}
		

	}
	
};

void SmoothDensityEditForm::GetKnotVector(array<float>^ &KnotVector,int n_value , int k_value){
	// 開放式均勻節點向量
	Array::Resize(KnotVector,n_value+k_value+1);
	for(int i =1 ; i<= (n_value+k_value+1) ; i++){
		if(1<=i && (i)<= k_value) KnotVector->SetValue(0/(n_value+2-k_value),i-1);
		if(k_value+1<=i && (i)<= n_value+1) KnotVector->SetValue((float)(i-k_value)/(float)(n_value+2-k_value),i-1);
		if(n_value+2<=i && (i)<= n_value+k_value+1) KnotVector->SetValue((n_value+2-k_value)/(n_value+2-k_value),i-1);	
	}

}
void SmoothDensityEditForm::GetNikValue(array<float>^ &NikVector , array<float>^ KnotVector , int k_value ,float t,int n_value){

	//正規化的B-spline基底函數
	
	//k_value 為 階數
	//NiVector的數目 為 n_value + 1 
	//KnotVector 的數目 為 n_value + k_value + 1
	//tmpNikVector 為 Previous NiVector
	Array::Clear(NikVector,0,NikVector->Length);
	Array::Resize(NikVector,n_value+1);

	array<float>^ tmpNikVector = gcnew array<float>(0);
	Array::Resize(tmpNikVector,n_value+1);

	for(int k = 1 ; k <= k_value ; k++){
		//Array::Clear(tmpNikVector,0,tmpNikVector->Length);
		
		
		for(int i= 1 ; i<=(n_value+1) ; i++){
			if( k == 1) {
				if (t >=Convert::ToSingle(KnotVector->GetValue(i-1)) && t < Convert::ToSingle(KnotVector->GetValue(i))) NikVector->SetValue(1,i-1);
				else NikVector->SetValue(0,i-1);
				//if (t >=Convert::ToSingle(KnotVector->GetValue(i-1)) && t <= Convert::ToSingle(KnotVector->GetValue(i))) NikVector->SetValue(1,i-1);
				//else NikVector->SetValue(0,i-1);
			}else{
				float tmpa;
				float tmpb;

				if(Convert::ToSingle(KnotVector->GetValue(i+k_value-1-1))-Convert::ToSingle(KnotVector->GetValue(i-1)) == 0) tmpa = 0;
				//else tmpa = (t-Convert::ToSingle(KnotVector->GetValue(i-1))) *Convert::ToSingle(NikVector->GetValue(i-1))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1-1))-Convert::ToSingle(KnotVector->GetValue(i-1)));
				else tmpa = (t-Convert::ToSingle(KnotVector->GetValue(i-1))) *Convert::ToSingle(tmpNikVector->GetValue(i-1))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1-1))-Convert::ToSingle(KnotVector->GetValue(i-1)));


				if((Convert::ToSingle(KnotVector->GetValue(i+k_value-1))-Convert::ToSingle(KnotVector->GetValue(i))) == 0) tmpb = 0;
				//else tmpb = (Convert::ToSingle(KnotVector->GetValue(i+k_value-1))- t) *Convert::ToSingle(NikVector->GetValue(i))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1))-Convert::ToSingle(KnotVector->GetValue(i)));
				else tmpb = (Convert::ToSingle(KnotVector->GetValue(i+k_value-1))- t) *Convert::ToSingle(tmpNikVector->GetValue(i))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1))-Convert::ToSingle(KnotVector->GetValue(i)));

				NikVector->SetValue( tmpa + tmpb ,i-1) ;
				//NikVector->SetValue( tmpa + tmpb ,i-1) ;


			}
		}
	
		for(int j = 0; j<n_value+1 ; j++){
			tmpNikVector->SetValue(Convert::ToSingle(NikVector->GetValue(j)),j);
		}


	}

}
void SmoothDensityEditForm::Get_Point_In_BSplineCurve(float &Pt_X, float &Pt_Y,array<float>^ Bij_X ,array<float>^ Bij_Y , int k_value ,float t,int n_value){

	//B-spline曲線數學模式 
	//得到 B-Spline上的某一點 P(t) 位置座標
	Pt_X = 0;
	Pt_Y = 0;

	array<float>^ KnotVector = gcnew array<float>(0);
	Array::Resize(KnotVector,n_value+k_value+1);
	GetKnotVector(KnotVector,n_value ,k_value);
	Array::Sort(KnotVector);
	array<float>^ tmpNikVector = gcnew array<float>(0);	
	Array::Resize(tmpNikVector,n_value+1);
	GetNikValue(tmpNikVector,KnotVector,k_value,t,n_value);


	for(int i = 0 ; i <	n_value+1 ; i++){		
		Pt_X = Pt_X + (Convert::ToSingle(Bij_X->GetValue(i))*Convert::ToSingle(tmpNikVector->GetValue(i)));
		Pt_Y = Pt_Y + (Convert::ToSingle(Bij_Y->GetValue(i))*Convert::ToSingle(tmpNikVector->GetValue(i)));
	}

	

	delete KnotVector;
	delete tmpNikVector;

}
void SmoothDensityEditForm::ProduceDenSity_Array(MeshGridInfo ^ ori_mg_array){

	for(int i = 0 ; i < ori_mg_array->Density->GetLength(0) ; i++){

		float DenY1;
		float tmp = pinputdata->PlateWidth/pinputdata->MeshNumber[0]*(i+0.5);
		GetDensityValue(tmp,DenY1,1);

		for(int j = 0 ; j < ori_mg_array->Density->GetLength(1) ; j++){
			float Den;

			float DenY2;
			float tmp = pinputdata->PlateHeight/pinputdata->MeshNumber[1]*(j+0.5);
			GetDensityValue(tmp,DenY2,0);
			Den = DenY1*DenY2;

			if (radioButton2->Checked == true || radioButton3->Checked == true){
				float tmpData = 0;
				tmpData = Convert::ToSingle(ori_mg_array->Density->GetValue(i,j));
				if (radioButton2->Checked == true){
					Den = Den + tmpData ;
					if (Den > 1) Den = 1;
				}
				if (radioButton3->Checked == true) {
					Den =tmpData - Den ;
					if (Den < 0) Den = 0;				
				}
			}

			ori_mg_array->Density->SetValue(Den,i,j);
		}
	}
	




}
void SmoothDensityEditForm::ProduceDenSity(MeshGrid *mg){

	int count = 0;
	float size[2];
	size[0] = pinputdata->PlateWidth/pinputdata->MeshNumber[0];
	size[1] = pinputdata->PlateHeight/pinputdata->MeshNumber[1];

	

//20080725---------------------------------------------------------------------
// 定義 tempDenY1 ,tempDenY2 為暫存密度資料(Array)
//	DenY1  : 垂值橫斷面密度分佈
//	DenY2  : 水平橫斷面密度分佈


	array<float,1>^ tempDenY1;
	array<float,1>^ tempDenY2;


	Array::Resize(tempDenY1,pinputdata->MeshNumber[0]);
	Array::Resize(tempDenY2,pinputdata->MeshNumber[1]);
	for(int i=0;i<pinputdata->MeshNumber[0];i++){
		float tmp = pinputdata->PlateWidth/pinputdata->MeshNumber[0]*(i+0.5);
		float DenY1;
		GetDensityValue(tmp,DenY1,1);
		tempDenY1->SetValue(DenY1,i);
	}
	for(int j=0;j<pinputdata->MeshNumber[1];j++){
		float tmp = pinputdata->PlateHeight/pinputdata->MeshNumber[1]*(j+0.5);
		float DenY2;
		GetDensityValue(tmp,DenY2,0);
		tempDenY2->SetValue(DenY2,j);
	}

	for(int i=0;i<pinputdata->MeshNumber[0];i++){
		for(int j = 0 ; j<pinputdata->MeshNumber[1] ; j++){
			float Den = 0;
			float pos[2];
			Den = Convert::ToSingle(tempDenY1->GetValue(i))*Convert::ToSingle(tempDenY2->GetValue(j));
			pos[0] = i*size[0];
			pos[1] = j*size[1];			
			mg[count].SetMeshPosition(pos);
			mg[count].SetMeshSize(size);
			mg[count].PtNumbers = 0;
		
			float tmpData = 0;

			tmpData = mg[count].GetPatternDensityinMesh();
			if (radioButton2->Checked == true){
				Den = Den + tmpData ;
				if (Den > 1) Den = 1;
			}
			if (radioButton3->Checked == true) {
				Den =tmpData - Den ;
				if (Den < 0) Den = 0;				
			}


			mg[count].SetPatternDensityinMesh(Den);	

			count ++;

		}
	}




//-----20080725以前----------------------------------------------------------

//	for(int i=0;i<pinputdata->MeshNumber[0];i++){
//		float DenY1;
//		float tmp = pinputdata->PlateWidth/pinputdata->MeshNumber[0]*(i+0.5);
//		GetDensityValue(tmp,DenY1,1);
//		for(int j = 0 ; j<pinputdata->MeshNumber[1] ; j++){
//			float Den;
//			float pos[2];
//			float DenY2;
//			float tmp = pinputdata->PlateHeight/pinputdata->MeshNumber[1]*(j+0.5);
//			GetDensityValue(tmp,DenY2,0);
//			//if (DenY1 < 0) DenY1 = 0;
//			//if (DenY2 < 0) DenY2 = 0;
//			Den = DenY1*DenY2;
//			pos[0] = i*size[0];
//			pos[1] = j*size[1];
//		    
//			
//			
//			mg[count].SetMeshPosition(pos);
//			mg[count].SetMeshSize(size);
//			mg[count].PtNumbers = 0;
//		
//			float tmpData = 0;
//
//			tmpData = mg[count].GetPatternDensityinMesh();
//			if (radioButton2->Checked == true){
//				Den = Den + tmpData ;
//				if (Den > 1) Den = 1;
//			}
//			if (radioButton3->Checked == true) {
//				Den =tmpData - Den ;
//				if (Den < 0) Den = 0;				
//			}
//
//
//			mg[count].SetPatternDensityinMesh(Den);	
//
//			count ++;
//		}
//		
//	}

			


};

void SmoothDensityEditForm::GetDensityValue(float X ,float &Y,int DrawPic){

	//產生實際的Density數值
		//Up_Down
	if (DrawPic == 0){
		for(int i = 0 ; i <Pt_X->Length-1 ; i ++){
			float TmpX1,TmpX2 ,TmpY1,TmpY2 ;
			TmpX1 = (Convert::ToSingle(Pt_X->GetValue(i))-30)/(FrameSize_W-60)*pinputdata->PlateHeight;
			TmpX2 = (Convert::ToSingle(Pt_X->GetValue(i+1))-30)/(FrameSize_W-60)*pinputdata->PlateHeight;
			TmpY1 = Convert::ToSingle(Pt_Y->GetValue(i));
			TmpY2 = Convert::ToSingle(Pt_Y->GetValue(i+1));


			if ( (TmpX1 < X && TmpX2 > X) || ( TmpX1 > X &&  TmpX2 < X))
			{
			
				Y = (X - TmpX1)/(TmpX2 - TmpX1) * (TmpY2 - TmpY1) + TmpY1 ;
				Y = (MaxDen-MinDen)*(FrameSize_H-30-Y)/(FrameSize_H-60);
				if (Y < 0 ) Y = 0;
				if (Y > 1 ) Y = 1;
				
				break ;			
			}
		}
	}else{
		//Right_Left
		for(int i = 0 ; i <Pt_X_L->Length-1 ; i ++){
			float TmpX1,TmpX2 ,TmpY1,TmpY2 ;
			TmpX1 = (Convert::ToSingle(Pt_X_L->GetValue(i))-30)/(FrameSize_W-60)*pinputdata->PlateWidth;
			TmpX2 = (Convert::ToSingle(Pt_X_L->GetValue(i+1))-30)/(FrameSize_W-60)*pinputdata->PlateWidth;
			TmpY1 = Convert::ToSingle(Pt_Y_L->GetValue(i));
			TmpY2 = Convert::ToSingle(Pt_Y_L->GetValue(i+1));

			if ( (TmpX1 < X && TmpX2 > X) || ( TmpX1 > X &&  TmpX2 < X))
			{
			
				Y = (X - TmpX1)/(TmpX2 - TmpX1) * (TmpY2 - TmpY1) + TmpY1 ;
				Y = (MaxDen-MinDen)*(FrameSize_H-30-Y)/(FrameSize_H-60);

				if (Y < 0 ) Y = 0;
				if (Y > 1 ) Y = 1;
				
				break ;			
			}
		}
	}


}


void SmoothDensityEditForm::DrawB_Spline_Curve(Graphics^ CurrentDraw,array<float>^ CurrentPt_X,array<float>^ CurrentPt_Y,array<float>^ CurrentControl_Pt_X ,array<float>^ CurrentControl_Pt_Y){


			Pen^ greenPen = gcnew Pen( Color::Green);
			Pen^ redPen = gcnew Pen( Color::Red);
						
			 float tmpPt_X ,tmpPt_Y;					 							
			 for (float i = 0 ; i <= 1 ; i= i+0.001){

				int tmpK;
				tmpK = CurrentControl_Pt_X->Length;
				if (tmpK >=4) tmpK =4 ;
				 Get_Point_In_BSplineCurve(tmpPt_X, tmpPt_Y, CurrentControl_Pt_X , CurrentControl_Pt_Y ,tmpK ,i,CurrentControl_Pt_X->Length-1 );
				// 將密度低於 0的數值設為 0
				 if(tmpPt_Y > FrameSize_H-30 )  tmpPt_Y = FrameSize_H-30;
				// 將密度高於 1的數值設為 1
				  if(tmpPt_Y < 30 )  tmpPt_Y =30;
				CurrentPt_X->SetValue(tmpPt_X,Convert::ToInt32(i/0.001));
				CurrentPt_Y->SetValue(tmpPt_Y,Convert::ToInt32(i/0.001));
			 }
			 for(int i = 0 ; i<Pt_X->Length-1 ; i++){				 
				 CurrentDraw->DrawLine(redPen,Convert::ToSingle(CurrentPt_X->GetValue(i)),Convert::ToSingle(CurrentPt_Y->GetValue(i))
				 ,Convert::ToSingle(CurrentPt_X->GetValue(i+1)),Convert::ToSingle(CurrentPt_Y->GetValue(i+1)));
			 }
			 SmoothDensityEditForm::Distribution_Vertical->Cursor = System::Windows::Forms::Cursors::Default;
			 SmoothDensityEditForm::Distribution_Horizontal->Cursor = System::Windows::Forms::Cursors::Default;
			delete greenPen;
			delete redPen;		

};
void SmoothDensityEditForm::DrawB_Controll_Pt(Graphics^ CurrentDraw,array<float>^ Current_Control_Pt_X ,array<float>^ Current_Control_Pt_Y){


			//畫Control Pt
			SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
			for(int i=0 ; i<Current_Control_Pt_X->Length ;i++){
				Point tmppt = Point(Convert::ToInt32(Current_Control_Pt_X->GetValue(i)),Convert::ToInt32(Current_Control_Pt_Y->GetValue(i)));						
				CurrentDraw->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10,10,0,360);

			}
			//畫作用中的ControlPT
			if (CurrentControlPt_Index != -1) {
				Point tmppt = Point(Convert::ToInt32(Current_Control_Pt_X->GetValue(CurrentControlPt_Index)),Convert::ToInt32(Current_Control_Pt_Y->GetValue(CurrentControlPt_Index)));	
				Brush->Color::set(Color::Coral);
				CurrentDraw->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10,10,0,360);
				
			}

			delete Brush;


};

*/
void SmoothDensityEditForm::TranslateDatatoCurve(){

			//獲得輸入的資料
			
			float tmpX,tmpY = 0;
			tmpX = Convert::ToSingle(this->numericUpDown_ControlPtLocation->Value);
			tmpY = Convert::ToSingle(this->numericUpDown_ControlPt_Den->Value);
			PointF ControllPt(tmpX,tmpY);
			PointF ScreenPt(0,0);
			SizeF frameSize = SizeF((float)FrameSize_W,(float)FrameSize_H);

			//判別作用中的控制點是屬於哪一個作用中的視窗 ,並在所屬的視窗中畫圖

			if(Active_Window == 1 && CurrentControlPt_Index != -1){

				grafx1->Graphics->DrawImage(Vertical_Pic_Metafile_Base,0,0);
				//轉換座標到Screen中 ,並取代舊有的座標位置
				ScreenPt = TranslateFormula->Translate_Pt_From_BSplineCoordinate_To_Screen(ControllPt,frameSize,30,30,this->LGPInformation.Height,100);
				this->Curve_Vertical->ControllPt->default[CurrentControlPt_Index] = ScreenPt;

				//在Grafx1 畫Curve
				Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
				this->Curve_Vertical->ReProduceCurve(1000,tmpBoundary);					
				Pen^ redPen = gcnew Pen( Color::Red);
				grafx1->Graphics->DrawLines(redPen,Curve_Vertical->GetCurve());  
				delete redPen;

				//畫ControllPt
				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Vertical->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Vertical->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;
					grafx1->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);
				}

				grafx1->Render(Vertical_Window);



			}
			else if (Active_Window == 2 && CurrentControlPt_Index != -1) {

				grafx2->Graphics->DrawImage(Horizontal_Pic_Metafile_Base,0,0);

				//轉換座標到Screen中 ,並取代舊有的座標位置
				ScreenPt = TranslateFormula->Translate_Pt_From_BSplineCoordinate_To_Screen(ControllPt,frameSize,30,30,this->LGPInformation.Width,100);
				this->Curve_Horizontal->ControllPt->default[CurrentControlPt_Index] = ScreenPt;
				
				//在Grafx2 畫Curve
				Rectangle tmpBoundary(30,30,FrameSize_W-60,FrameSize_H-60);
				this->Curve_Horizontal->ReProduceCurve(1000,tmpBoundary);				
				Pen^ redPen = gcnew Pen( Color::Red);
				grafx2->Graphics->DrawLines(redPen,Curve_Horizontal->GetCurve());  
				delete redPen;
			
				//畫Control Pt

				SolidBrush^ Brush = gcnew SolidBrush(Color::Yellow );
				for(int i=0 ; i<Curve_Horizontal->ControllPt->Count ;i++){	
					PointF tmppt = Curve_Horizontal->ControllPt->default[i];	
					if (i != CurrentControlPt_Index) 	Brush->Color = Color::Yellow;
					else  Brush->Color = Color::Purple;

					grafx2->Graphics->FillPie(Brush,tmppt.X-5,tmppt.Y-5,10.0,10.0,0.0,360.0);

				}

				grafx2->Render(Horizontal_Window);


			}


};


int ComapreControllPt(PointF xtmpPt1,PointF xtmpPt2){
	if (xtmpPt1.X > xtmpPt2.X)	return 1;
	else if (xtmpPt1.X == xtmpPt2.X)  return 0;
	else  return -1;
}
