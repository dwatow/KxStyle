#include "stdafx.h"
#include "DataStructure.h"


void SettingData::Initialize_LT_Setting(){
	this->X_direction_Shift = 0;
	this->Y_direction_Shift = 0;
	this->LTPattern_Shape = 0;
	this->LTPattern_Style = 0;
	this->PatternDeep = 0.02f;
}
void HotSpot_Part::BuildCurve(int tmpSampling){

		array<PointF>^ cPt = gcnew array<PointF>(2);
		cPt[0].Y = 1; //邊緣Gain 值永遠是1 
		cPt[0].X = 0;
		cPt[1].Y = this->CenterGainValue; //中心Gain 值是使用者輸入
		cPt[1].X = 1;

	


		this->tmpCurve = gcnew B_Spline_Curve();
	


		tmpCurve->ControllPt->Add(cPt[0]);

		for(int ii = 0 ; ii < 3 ; ii ++){
			tmpCurve->ControllPt->Add((PointF)this->ConrollPt->GetValue(ii));
		 }

		tmpCurve->ControllPt->Add(cPt[1]);
		tmpCurve->Set_k_Value(this->SmoothingDegree);
		tmpCurve->ReProduceCurve(tmpSampling);





};
String^ HotSpot_Part::Save(){

	String^ tmpSting;


	tmpSting = this->CenterCoordinate.X.ToString() +"," + this->CenterCoordinate.Y.ToString()  +  ";" +
		this->CenterGainValue.ToString() +  ";" +
		this->ConrollPt[0].X.ToString() + "," + this->ConrollPt[0].Y.ToString() +  ";" +
		this->ConrollPt[1].X.ToString() + "," + this->ConrollPt[1].Y.ToString() +  ";" +
		this->ConrollPt[2].X.ToString() + "," + this->ConrollPt[2].Y.ToString() +  ";" +
		this->Length_X.ToString() +  ";" +
		this->Length_Y.ToString() +  ";" +
		this->Name->ToString() +  ";" +
		this->Number.ToString() +  ";" +
		this->pitch.ToString() +  ";" +
		this->PitchDirection->ToString() +  ";" +
		this->PitchDirectionIndex.ToString() +  ";" +
		this->rotateAngle.ToString() +  ";" +
		this->Shape->ToString() +  ";" +
		this->ShapeIndex.ToString() +  ";" +
		this->SmoothingDegree.ToString() +  ";" +
		this->SwapModeIndex.ToString();  //20120920 增加 
		
	return tmpSting;





}

void HotSpot_Part::Load(String^ tmpData ,int version){


	if(version == 1){

		//Software Version 3.5.1版之前
		array<String^>^ splitdata =tmpData->Split(',') ;	
		this->Name = Convert::ToString(splitdata[0]);
		this->Number = Convert::ToUInt16(splitdata[1]);
		this->PitchDirectionIndex =  Convert::ToInt16(splitdata[2]);
		if(splitdata[3] != "") this->pitch = Convert::ToSingle(splitdata[3]);
		else this->pitch = 0;
		this->CenterCoordinate.X = Convert::ToSingle(splitdata[4]);
		this->CenterCoordinate.Y = Convert::ToSingle(splitdata[5]);
		this->Length_X = Convert::ToSingle(splitdata[6]);
		this->Length_Y = Convert::ToSingle(splitdata[7]);
		this->rotateAngle = Convert::ToSingle(splitdata[8]);
		this->CenterGainValue =  Convert::ToSingle(splitdata[9]);
		this->SmoothingDegree = Convert::ToInt16(splitdata[10]);
		this->ConrollPt[0].X = Convert::ToSingle(splitdata[11]);
		this->ConrollPt[0].Y = Convert::ToSingle(splitdata[12]);
		this->ConrollPt[1].X = Convert::ToSingle(splitdata[13]);
		this->ConrollPt[1].Y = Convert::ToSingle(splitdata[14]);
		this->ConrollPt[2].X = Convert::ToSingle(splitdata[15]);
		this->ConrollPt[2].Y = Convert::ToSingle(splitdata[16]);

		//額外的
		if(this->PitchDirectionIndex == 0)
			this->PitchDirection = "X方向";
		else 
			this->PitchDirection = "Y方向";

		this->Shape = "橢圓形";
		this->ShapeIndex = 0;


	}else if(version == 2){

		//Software Version 3.6版之後
		array<String^,1>^ arrayString = tmpData->Split(';');
		array<String^,1>^ tmp;


		//座標位置
		tmp = arrayString[0]->Split(',');
		this->CenterCoordinate.X = Convert::ToSingle(tmp[0]);
		this->CenterCoordinate.Y = Convert::ToSingle(tmp[1]);

		//中心Gain 值
		this->CenterGainValue = Convert::ToSingle(arrayString[1]);

		//控制點數值
		tmp = arrayString[2]->Split(',');
		this->ConrollPt[0].X = Convert::ToSingle(tmp[0]);
		this->ConrollPt[0].Y = Convert::ToSingle(tmp[1]);

		tmp = arrayString[3]->Split(',');
		this->ConrollPt[1].X = Convert::ToSingle(tmp[0]);
		this->ConrollPt[1].Y = Convert::ToSingle(tmp[1]);

		tmp = arrayString[4]->Split(',');
		this->ConrollPt[2].X = Convert::ToSingle(tmp[0]);
		this->ConrollPt[2].Y = Convert::ToSingle(tmp[1]);


		//半長軸 or X 方向長度
		this->Length_X = Convert::ToSingle(arrayString[5]);

		//半短軸 or Y 方向長度
		this->Length_Y = Convert::ToSingle(arrayString[6]);

		//名稱
		this->Name = arrayString[7];

		//陣列數目
		this->Number = Convert::ToSingle(arrayString[8]);

		//Pitch 
		this->pitch =  Convert::ToSingle(arrayString[9]);

		//Pitch方向
		this->PitchDirection = arrayString[10];

		//Pitch Index 
		this->PitchDirectionIndex = Convert::ToSingle(arrayString[11]);

		//Rotate Angle
		this->rotateAngle = Convert::ToSingle(arrayString[12]);

		//形狀 (橢圓 or 菱形)
		this->Shape = arrayString[13];

		//形狀 Index (橢圓 or 菱形)
		this->ShapeIndex = Convert::ToSingle(arrayString[14]);

		//平順度
		this->SmoothingDegree = Convert::ToSingle(arrayString[15]);

		//20120920 增加 
		if(arrayString->Length >= 17) {
			this->SwapModeIndex = Convert::ToInt16(arrayString[16]);
		}else{
			this->SwapModeIndex = 0 ; //舊版本是等比Swap .
		}


	}













};


/*
void MeshGridInfo::ClearAll(){
//清空密度資料和在此網格內的關聯網點Index資料
	if (this->Empty == false){		
		//青空資料
		for(int i = 0 ; i <this->PtInDensityGrid->GetLength(0) ; i++){
			for(int j = 0 ; j < this->PtInDensityGrid->GetLength(1); j++){
				array<int>^ tmp;
				//轉換指標形態
				tmp = reinterpret_cast<array<int>^>(this->PtInDensityGrid->GetValue(i,j));			
				Array::Clear(tmp,0,tmp->Length);
			}
		}
		Array::Clear(this->PtInDensityGrid,0,this->PtInDensityGrid->Length);
		Array::Clear(this->Density,0,this->Density->Length);
		Array::Clear(this->ChangedDensity,0,this->ChangedDensity->Length);
		this->Empty = true;
	}
	

};
*/
/*
void MeshGridInfo::Initailize(int Number_X, int Number_Y, float IniDensity){
//初始化

	//清空資料
	this->ClearAll();

	this->Number_X = Number_X;
	this->Number_Y = Number_Y;
	this->IniDensity = IniDensity;

	this->Density = gcnew array<float,2>(this->Number_X,this->Number_Y);
	for(int i=0 ; i<this->Density->GetLength(0) ; i++){
		for(int j=0 ; j<this->Density->GetLength(1) ; j++){
			this->Density->SetValue(this->IniDensity,i,j);
		}
	}
	
	this->ChangedDensity = gcnew array<float,2>(this->Number_X,this->Number_Y);
	for(int i=0 ; i<this->ChangedDensity->GetLength(0) ; i++){
		for(int j=0 ; j<this->ChangedDensity->GetLength(1) ; j++){
			this->Density->SetValue(0,i,j);
		}
	}
	
	
	this->PtInDensityGrid = gcnew array<array<int>^,2>(this->Number_X,this->Number_Y);
	for(int i = 0 ; i <this->PtInDensityGrid->GetLength(0) ; i++){
		for(int j = 0 ; j < this->PtInDensityGrid->GetLength(1); j++){
			array<int>^ tmp;
			tmp = gcnew array<int>(1);
			tmp->SetValue(-1,0);
			this->PtInDensityGrid->SetValue(tmp,i,j);			
		}
	}

    this->Empty = false;

}
*/
void SmoothSurfaceInfo::SetControllPt_Number_IniValue(int X_Number, int Y_Number,float Ini_Z){


	this->IniValue_Z = Ini_Z;
	this->Controll_Row_number = X_Number;
	this->Controll_Collum_number = Y_Number;



	//建立ControllPt 的數目

	this->controllPt_X = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
	this->controllPt_Y = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
	this->controllPt_Z = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
	


	//設定ControllPt的數值

	for(int i= 0 ;i <this->Controll_Row_number ;i++){
		for(int j= 0 ;j<this->Controll_Collum_number ;j++){
			float tmpX,tmpY;
			tmpX = this->PlateW/(this->Controll_Row_number-1);
			tmpY = this->PlateH/(this->Controll_Collum_number-1);
			
			this->controllPt_X->SetValue(tmpX*i,i,j);
			this->controllPt_Y->SetValue(tmpY*j,i,j);
			this->controllPt_Z->SetValue(this->IniValue_Z,i,j);
		}
	}
	
	
}
void SmoothSurfaceInfo::Initialize(float PlateWidth,float PlateHeight,float IniValue_Z){

	//Ini CurrentControllPt的數值
	this->SelectIndex_X = -1;
	this->SelectIndex_Y = -1;
	this->Controll_Row_number = 5;
	this->Controll_Collum_number = 5;
	this->IniValue_Z = IniValue_Z;

	this->PlateH = PlateHeight;
	this->PlateW = PlateWidth;

	this->SetControllPt_Number_IniValue(this->Controll_Row_number,this->Controll_Collum_number,this->IniValue_Z);

	//建立ControllPt 的數目

	//this->controllPt_X = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
	//this->controllPt_Y = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
	//this->controllPt_Z = gcnew array<float,2>(this->Controll_Row_number,this->Controll_Collum_number);
		

	//設定ControllPt的數值

	//for(int i= 0 ;i <this->Controll_Row_number ;i++){
	//	for(int j= 0 ;j<this->Controll_Collum_number ;j++){
	//		float tmpX,tmpY,tmpZ;
	//		tmpX = PlateWidth/(this->Controll_Row_number-1);
	//		tmpY = PlateHeight/(this->Controll_Collum_number-1);
			
	//		this->controllPt_X->SetValue(tmpX*i,i,j);
	//		this->controllPt_Y->SetValue(tmpY*j,i,j);
	//		this->controllPt_Z->SetValue(this->IniValue_Z,i,j);
	//	}
	//}


	

	Empty = false;




}

void SetDensityColor(float &density ,float &R ,float &G ,float &B){



	if (density > 1) density = 1.0f;
	if (density < 0) density = 0.0f;
	
	float tempvalue = density*400+380;
	//float R,G,B;
	float Gamma =  0.8f;
    float IntensityMax = 255.0f;
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

		R = 1.0f;
        G = (tempvalue - 645) / (780 - 645);
        B = (tempvalue - 645) / (780 - 645);
		Gamma = 1.0f;

	}else{
		R = 1.0f;
        G = 1.0f;
        B = 1.0f;
	};

	if (tempvalue >= 380 && tempvalue <= 420){
		factor = 0.3f + 0.7f*(tempvalue - 380) / (420 - 380);
	}else if(tempvalue >= 420 && tempvalue <= 700){
		factor = 1.0f;
	}else{
		factor = 1.0f;
		 //factor = 0.3 + 0.7*(780 - tempvalue) / (780 - 700);
	};


	
	R = (IntensityMax * pow(R * factor, Gamma));
	G = (IntensityMax * pow(G * factor, Gamma));
	B = (IntensityMax * pow(B * factor, Gamma));
	
};

void MeshGrid::SetMeshSize(float meshsize[2]){
	for(int i=0;i<2;i++){
		MeshSize[i] = meshsize[i];
	}
};
void MeshGrid::SetMeshPosition(float pos[2]){
	for(int i=0;i<2;i++) MeshPosition[i] = pos[i];
};
float *MeshGrid::GetMeshPosition(){
	return &MeshPosition[0];
};

void MeshGrid::SetPatternDensityinMesh(float density){
	float R,G,B;
	SetDensityColor(density,R,G,B);
	PatternDensityinMesh = density;
	SqrtDensity = sqrt(density);
	if (SqrtDensity > 0.001) {
		DividSqrtDensity = 1/SqrtDensity;
	}
	else{
		DividSqrtDensity = 1000;
	}
	
	
	Color_R = (int)R;
	Color_G = (int)G;
	Color_B = (int)B;

};

float *MeshGrid::GetMeshSize(){
	return &MeshSize[0];
};

float MeshGrid::GetPatternDensityinMesh(){
	return PatternDensityinMesh;
};

void Point3d::SetPointPosition(double x ,double y,double z){
	X=(float)x;
	Y=(float)y;
	Z=(float)z;
};

void Point3d::GetPointPosition(double &x,double &y,double &z){
	x = X;
	y = Y;
	z = Z;
};

void Point3d::IniPt(){
	X = -1;
	Y = -1;
	Z = -1;
	MeshIndex = -1;
	IniForce();
    Overlap = true;
    InsidePlateArea = true;


};
int Point3d::GetMeshIndex(){
	return MeshIndex;
};

void Point3d::SetMeshIndex(int mindex){
	MeshIndex = mindex;
};
void Point3d::AddForce(Force f){
	totalforce.Fx = totalforce.Fx + f.Fx;
	totalforce.Fy = totalforce.Fy + f.Fy;
	totalforce.Fz = totalforce.Fz + f.Fz;
	
};

void Point3d::IniForce(){
	totalforce.Fx = 0;
	totalforce.Fy = 0;
	totalforce.Fz = 0;
};
void  Point3d::GetForce(Force &force){
	force.Fx = totalforce.Fx;
	force.Fy = totalforce.Fy;
	force.Fz = totalforce.Fz;
	
};
/*
void DrawInfo::Initial(){
	RedrawPattern = true;
	RedrawOriPattern = true;
	RedrawUnSuitablePattern = true;
	RedrawDesignDensity = true;
	RedrawActualDensity = true;
	RedrawMesh = true;

};
*/

void DataInput::Initial(){
		PlateWidth = 0;      //導光版寬度
		PlateHeight = 0;     //導光版長度		
		MeshNumber[0] = 1;		//網格大小(N X N個網格)
		MeshNumber[1] = 1;		//網格大小(N X N個網格)
		PatternNumberSelection = 0; //選擇網點數目 (0表示根據密度設定 ,1表示自行設定)
		PatternNumber = 0;		//網點數目
		StopCriteria = 1;      //終止分子動力模擬條件( 1 表示次數 , 4 表示達到適當距離 )
		StopCriteriaIteriation = 10;    //終止條件之次數
		PatternRadius = 0.2f;
		CalMode = 1;
		Boundary_Up = 0;
		Boundary_Down = 0;
		Boundary_Left = 0;
		Boundary_Right = 0;
		Pattern_Space = 0;
		PatternShape = 0;  //0表示圓形 ,1表示矩形
		SimShape = 0 ;			//模擬設定( 0表示為 橢圓形 ,1表示為矩形)
		Parameter_K = 1;		//參數K設定
		Parameter_C = 0.5;		//參數C設定

}


void MainFormData::GetInputData(DataInput oldform){
	
		

//	this->LGPDimension = PointF(oldform.PlateWidth,oldform.PlateHeight);	
	this->LGPInformation = RectangleF(0,0,oldform.PlateWidth,oldform.PlateHeight);

	this->Pattern_Shape = oldform.PatternShape;
	
	if(oldform.PatternMode == 1) {
		//this->RandomDot = true;
		this->DotType = 1;
		this->RandomDotSize = oldform.PatternRadius*2;
		this->RandomDotGap = oldform.Pattern_Space;
		this->RandomDotIteration = oldform.StopCriteriaIteriation;
		this->RandomDotSimRule = oldform.SimShape;
		this->Parameter_K = oldform.Parameter_K;
		this->Parameter_C = oldform.Parameter_C;

		//未設定的值 ::: Default 為0
		
		//規則網點初始化參數
		this->MaxDot = 0;
		this->MinDot = 0;
		this->MinDotGap = 0;
		this->Pattern_Shape = 0 ;
		this->Pattern_Arrangment = 0;


	}else{
		//this->RandomDot = false;
		this->DotType = 0;
		this->MaxDot = oldform.PatternRadius*2;
		this->MinDot = 0;
		this->MinDotGap = 0;
		this->Pattern_Shape = oldform.PatternShape;
		this->Pattern_Arrangment = oldform.PatternMode-2;
		
		//未設定的值 ::: Default 為0
		
		//亂數網點初始化參數
		this->RandomDotSize = 0;
		this->RandomDotGap = 0;
		this->RandomDotIteration = 0;
		this->RandomDotSimRule = 0;
		this->Parameter_K = 0;
		this->Parameter_C = 0;
		
	}

			
	
}

/*
void GridDensity::GetDensity_Color(int &R,int &G ,int &B,Point index){
	R = this->DensityColor_R[index.X,index.Y];
	G = this->DensityColor_G[index.X,index.Y];
	B = this->DensityColor_B[index.X,index.Y];
}
void GridDensity::SetDensity(float tmpDen,Point tmpIndex){
	float R,G,B;

	if (tmpDen > 1) tmpDen = 1;
	if (tmpDen < 0) tmpDen = 0;
	
	this->SetDensityColor(tmpDen,R,G,B);
	this->DensityColor_R->SetValue((int)R,tmpIndex.X,tmpIndex.Y);
	this->DensityColor_G->SetValue((int)G,tmpIndex.X,tmpIndex.Y);
	this->DensityColor_B->SetValue((int)B,tmpIndex.X,tmpIndex.Y);
	this->DensityValue->SetValue(tmpDen,tmpIndex.X,tmpIndex.Y);	
}
void GridDensity::SetDensity(float tmpDen,int indexX,int indexY){
	float R,G,B;

	if (tmpDen > 1) tmpDen = 1;
	if (tmpDen < 0) tmpDen = 0;
	
	this->SetDensityColor(tmpDen,R,G,B);
	this->DensityColor_R->SetValue((int)R,indexX,indexY);
	this->DensityColor_G->SetValue((int)G,indexX,indexY);
	this->DensityColor_B->SetValue((int)B,indexX,indexY);
	this->DensityValue->SetValue(tmpDen,indexX,indexY);	
}

void GridDensity::SetDensityColor(float density, float &R, float &G, float &B){
	



	

	density =  (density-this->minDensity_Color/100)/(this->maxDensity_Color/100-this->minDensity_Color/100);
	if (density <= 0 ) density = 0;
	if (density > 1 ) density = 1;


	
	float tempvalue = density*400+380;
	//float R,G,B;
	float Gamma =  0.80;
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
		factor = 0.3 + 0.7*(tempvalue - 380) / (420 - 380);
	}else if(tempvalue >= 420 && tempvalue <= 700){
		factor = 1.0;
	}else{
		factor = 1.0;
		 //factor = 0.3 + 0.7*(780 - tempvalue) / (780 - 700);
	};


	
	R = (IntensityMax * pow(R * factor, Gamma));
	G = (IntensityMax * pow(G * factor, Gamma));
	B = (IntensityMax * pow(B * factor, Gamma));

}


float GridDensity::GetDensity_Value_FromDotCood(PointF dotCoodrinate,RectangleF LGPInformation,Point GridNumber){



	float den = 0;
	Point denIndex(0,0);
	
	if(dotCoodrinate.X >= LGPInformation.Left && dotCoodrinate.X <= LGPInformation.Right && dotCoodrinate.Y <= LGPInformation.Bottom && dotCoodrinate.Y >= LGPInformation.Top){
		//表示網點在LGP內
		denIndex.X = Math::Round(GridNumber.X*(dotCoodrinate.X-LGPInformation.Left)/LGPInformation.Width);
		denIndex.Y = Math::Round(GridNumber.Y*(dotCoodrinate.Y-LGPInformation.Top)/LGPInformation.Height);
		
	//	if(denIndex.X < 0 ) denIndex.X = 0 ;
	//	if(denIndex.X > GridNumber.X-1 ) denIndex.X = GridNumber.X-1 ;
	//	if(denIndex.Y < 0 ) denIndex.Y = 0 ;
	//	if(denIndex.Y > GridNumber.Y-1 ) denIndex.Y = GridNumber.Y-1;

		if(denIndex.X < 0 || denIndex.X > GridNumber.X || denIndex.Y < 0 || denIndex.Y > GridNumber.Y){
			den = 0;
		}else{
			if(denIndex.X == GridNumber.X) denIndex.X = GridNumber.X -1;
			if(denIndex.Y == GridNumber.Y) denIndex.Y = GridNumber.Y -1;
			den = this->DensityValue[denIndex.X,denIndex.Y];
		}
	};
	
	return den;

}
void GridDensity::GetDensity_Value(float &den, Point index){	
//	den = (float)this->DensityValue->GetValue(index.X,index.Y);
	den = DensityValue[index.X,index.Y];
}
void GridDensity::GetDensity_Value(float &den,int indexX,int indexY){	
	den = (float)this->DensityValue->GetValue(indexX,indexY);
//	den = DensityValue[indexX,indexY];
}
void GridDensity::CreateGridDensity(Point GridNumber){
	
	this->DensityValue = gcnew array<float,2>(GridNumber.X,GridNumber.Y);
	this->DensityColor_R = gcnew array<int,2>(GridNumber.X,GridNumber.Y);
	this->DensityColor_G = gcnew array<int,2>(GridNumber.X,GridNumber.Y);
	this->DensityColor_B = gcnew array<int,2>(GridNumber.X,GridNumber.Y);

}
void GridDensity::xClearAll(){

		delete[] this->DensityValue ;
		delete[] this->DensityColor_R ;
		delete[] this->DensityColor_G ;
		delete[] this->DensityColor_B ;
	
	//	this->DensityValue = gcnew array<float,2>(0,0);
	//	this->DensityColor_R = gcnew array<int,2>(0,0);
	//	this->DensityColor_G = gcnew array<int,2>(0,0);
	//	this->DensityColor_B = gcnew array<int,2>(0,0);
		
}

//*/
void Pattern::BuildPattern(long DotNumber){
	this->Dot_Coordinate =gcnew array<PointF>(DotNumber) ;
	this->Dot_Diameter = gcnew array<float>(DotNumber);
	this->ModifyRate_LocalArea = gcnew array<float>(DotNumber);

	for(int ii = 0 ;ii <DotNumber ;ii++){
		this->ModifyRate_LocalArea->SetValue(1.0f,ii);
	}
	
	


}
void Pattern::BuildRegularPattern(int GridX, int GridY, int PatternArrangement){
	int NR = 0;
	if(PatternArrangement == 0){ //規則排列
		NR = GridX*GridY;
//		this->Outside_Dot_Index = gcnew array<int,2>(GridX,GridY);
//		this->Inside_Dot_Index = gcnew array<int,2>(0,0);
	}else if (PatternArrangement == 1 || PatternArrangement == 2 || PatternArrangement == 3) {  //45度或60度,30度錯排
		NR = GridX*GridY +  (GridX-1)*(GridY-1) ;
//		this->Outside_Dot_Index = gcnew array<int,2>(GridX,GridY);
//		this->Inside_Dot_Index = gcnew array<int,2>(GridX-1,GridY-1);
	}

	this->Dot_Coordinate =gcnew array<PointF>(NR) ;
	this->Dot_Diameter = gcnew array<float>(NR);
//	this->ModifyRate_HotSpot = gcnew array<float>(NR);
	this->ModifyRate_LocalArea = gcnew array<float>(NR);
//	this->Dot_ModifyRate = gcnew array<float>(NR);
	for(int ii = 0 ;ii <NR ;ii++){
		this->ModifyRate_LocalArea->SetValue(1.0f,ii);
	}

	




};
/*
void Pattern::SetDotLocation(int Dot_Index,Point Corresponddot_Location,bool OutsideDot){
	
	if(OutsideDot == true){
		this->Outside_Dot_Index->SetValue(Dot_Index,Corresponddot_Location.X,Corresponddot_Location.Y);
	}else{
		this->Inside_Dot_Index->SetValue(Dot_Index,Corresponddot_Location.X,Corresponddot_Location.Y);
	}

}
*/
/*
bool Pattern::BuildOri_DotDia(){
	if(this->GetDotNumber()>0){
		this->Origional_Dot_Diameter = gcnew array<float>(this->GetDotNumber());
		Array::Copy(this->Dot_Diameter,this->Origional_Dot_Diameter,this->GetDotNumber());
		return true;
	}else
		return false;
}
*/

void Pattern::SetDotValue(System::Drawing::PointF dot_coor, float dot_dia, long Dot_Index){
	this->Dot_Coordinate->SetValue(dot_coor,Dot_Index);
	this->Dot_Diameter->SetValue(dot_dia,Dot_Index);
}
/*
void Pattern::SetDotModifyRateValue( float modifyrate, int row , int column,bool cross_arrangement){
	
	//必須先確定 Dot-Index 的 Array 已經建立 ,且已經把 index 的資訊記錄起來 


	int tmpIndexX = 0 ,tmpIndexY = 0, dotIndex = 0;
	if (cross_arrangement == true) {
		
		if(row % 2 == 1 && column % 2 == 1){  //表示外圍的Pattern
			tmpIndexY = (row-1) /2;
			tmpIndexX = (column -1) /2;
			dotIndex = (int)this->Outside_Dot_Index->GetValue(tmpIndexX,tmpIndexY);
			this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);
		}else if(row % 2 == 0 && column % 2 == 0){ //表示內圍的Pattern
			tmpIndexY = (row) /2;
			tmpIndexX = (column ) /2;
			dotIndex = (int)this->Outside_Dot_Index->GetValue(tmpIndexX,tmpIndexY);	
			this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);
		}
	}else{  //表示只有外圍 Pattern
		dotIndex = (int)this->Outside_Dot_Index->GetValue(column,row);
		this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);		
	}


}
*/

/*
void Pattern::SetDotModifyRateValue( float modifyrate, int selectedNumber ,bool cross_arrangement,bool row){
	
	//必須先確定 Dot-Index 的 Array 已經建立 ,且已經把 index 的資訊記錄起來 


	
	if (cross_arrangement == true) {
		
		if(selectedNumber % 2 == 1 ){  //表示外圍的Pattern
			int tmpIndex = (selectedNumber-1) /2;
			if (row == true){
				int number = this->Outside_Dot_Index->GetLength(0);
				for(int ii = 0 ;ii < number ;ii++){
					int dotIndex = (int)this->Outside_Dot_Index->GetValue(ii,tmpIndex);
					this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);
				}
			}else{

				int number = this->Outside_Dot_Index->GetLength(1);
				for(int ii = 0 ;ii < number ;ii++){
					int dotIndex = (int)this->Outside_Dot_Index->GetValue(tmpIndex,ii);
					this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);					
				}
			}


		}else if(selectedNumber % 2 == 0){ //表示內圍的Pattern
			int tmpIndex = (selectedNumber)/2-1;
			if(row == true){
				int number = this->Inside_Dot_Index->GetLength(0);
				for(int ii = 0 ;ii < number ;ii++){
					int dotIndex = (int)this->Inside_Dot_Index->GetValue(ii,tmpIndex);	
					this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);
				}
			}else{
				int number = this->Inside_Dot_Index->GetLength(1);
				for(int ii = 0 ;ii < number ;ii++){
					int dotIndex = (int)this->Inside_Dot_Index->GetValue(tmpIndex,ii);	
					this->Dot_ModifyRate->SetValue(modifyrate,dotIndex);
				}



			}
		}
	}else
	{  //表示只有外圍 Pattern
		
		if(row == true){
			int number = this->Outside_Dot_Index->GetLength(0);
			for(int jj = 0 ;jj < number ;jj++){
				int tmp = (int)(this->Outside_Dot_Index->GetValue(jj,selectedNumber-1));
				this->Dot_ModifyRate->SetValue(modifyrate,tmp);
			}
		}else{
			int number = this->Outside_Dot_Index->GetLength(1);
			for(int jj = 0 ;jj < number ;jj++){
				int tmp = (int)this->Outside_Dot_Index->GetValue(selectedNumber-1,jj);
				this->Dot_ModifyRate->SetValue(modifyrate,tmp);
			}

		}

	}



}


*/

void Pattern::GetDotValue(System::Drawing::PointF &dot_coor, float &dot_dia, int Index){
	//dot_coor = (PointF)this->Dot_Coordinate->GetValue(Index);
	//dot_dia  = (float)this->Dot_Diameter->GetValue(Index);

	dot_coor = this->Dot_Coordinate[Index] ;
	dot_dia  = this->Dot_Diameter[Index];

}
/*
void Pattern::GetDotValue(System::Drawing::PointF &dot_coor, float &dot_dia, Point dot_Location, bool OutsideDot){
	int tmpIndex = 0;
	if (OutsideDot == true){
		tmpIndex = (int)this->Outside_Dot_Index->GetValue(dot_Location.X,dot_Location.Y);
	}else{
		tmpIndex = (int)this->Inside_Dot_Index->GetValue(dot_Location.X,dot_Location.Y);
	}

	dot_coor = (PointF)this->Dot_Coordinate->GetValue(tmpIndex);
	dot_dia  = (float)this->Dot_Diameter->GetValue(tmpIndex);
}
*/
void Pattern::ClearAll(){

	

	if(this->Dot_Diameter != nullptr)	        delete[] this->Dot_Diameter;
	if(this->Dot_Coordinate != nullptr)         delete[] this->Dot_Coordinate;
//	if(this->ModifyRate_HotSpot != nullptr)     delete[] this->ModifyRate_HotSpot;
	if(this->ModifyRate_LocalArea != nullptr)   delete[] this->ModifyRate_LocalArea;
	if(this->DotDensity_Index != nullptr)       delete[] this->DotDensity_Index;
	if(this->Dot_Force != nullptr)				delete[] this->Dot_Force;
	if(this->MuraValue != nullptr)				delete[] this->MuraValue;
	
	
		

}
void Pattern::Initialize_me(){

	/*
	if(this->ModifyRate_HotSpot != nullptr)	
		Array::Resize(this->ModifyRate_HotSpot,0);
	else	
		this->ModifyRate_HotSpot = gcnew array<float>(0);
		*/

	if(this->ModifyRate_LocalArea != nullptr)
		Array::Resize(this->ModifyRate_LocalArea,0);
	else
		this->ModifyRate_LocalArea = gcnew array<float>(0);


	if(this->Dot_Diameter != nullptr)
		Array::Resize(this->Dot_Diameter,0);
	else
		Dot_Diameter = gcnew array<float>(0);

	if(this->Dot_Coordinate != nullptr)
		Array::Resize(this->Dot_Coordinate,0);
	else
		Dot_Coordinate = gcnew array<PointF>(0);

	if(DotDensity_Index != nullptr)
		Array::Resize(this->Dot_Coordinate,0);
	else
		DotDensity_Index = gcnew array<Point,2>(4,0);
}
long Pattern::GetDotNumber(){
	return (long)this->Dot_Coordinate->LongLength;
}
void Cosmetic_Data::Initialize(){

	
	this->Current_InputData = gcnew array<float>(110);

	//紀錄區域修改的輸入參數
	this->LocalArea_History_Data = gcnew array<float,2>(0,110);

	//亮線修改的輸入參數 "第一筆資料紀錄行數筆數和列數的筆數
	this->Line_History_Data = gcnew array<float,2>(1,4); 
	//紀錄HotBar 資料 ~~
	this->HotBar_History_Data = gcnew array<String^,2>(4,81);
	for(int ii = 0 ;ii < 4 ; ii++){
		this->HotBar_History_Data->SetValue("4",ii,4);
		this->HotBar_History_Data->SetValue("4",ii,5);
	}

	for(int ii = 0 ;ii <29 ; ii ++){
		this->Current_InputData->SetValue(0.0f,ii);
	};
	this->Current_InputData->SetValue(2.0f,4);
	this->Current_InputData->SetValue(2.0f,5);
	//輸入陣列的初始值
	this->Current_InputData->SetValue(0.0f,32); //陣列方向
	this->Current_InputData->SetValue(1.0f,33); //陣列數目
	this->Current_InputData->SetValue(0.0f,34); //陣列間距
	//輸入權重
	for(int ii = 35 ;ii <60 ; ii ++){
		this->Current_InputData->SetValue(1,ii);
	};

	
}
void Project_Information::ClearAll(){
	this->DesignDate = "";
	this->Designer = "";
	this->LGP_Manufacture = 0;
	this->LGP_Material = 0 ;
	this->LGP_PN_Number = "" ;
	this->MeshSize = 0;
	this->PatternVersion = "" ;
	this->ProductionStyle =0 ;
	this->projectName = "" ;
	this->ScreenAngle = 0.0f;
	this->ScreenSize = 0;
	this->SpecialInk = "" ;
	this->Thick = 0.0f;
	
	
	
}
