#include "StdAfx.h"
#include "FileIO_OLD.h"
#include < vcclr.h >
#include < stdio.h >
#include < stdlib.h >

using namespace System::Collections;
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
using namespace System::Drawing ;



//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------- OLD Version --------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------



bool OpenB_Spline_Curve(StreamReader ^ sr,B_Spline_Curve^ Curve){

		array<String^>^ SepData;
		

		try{
			Curve->ControllPt->Clear();
			String^ str;
			str = sr->ReadLine();
			//str = "# ControlPt Location/Parameter Export file";			
			str = sr->ReadLine();
			int num = Convert::ToInt16(str); 
			str = sr->ReadLine();
		//	str = "X-Direction" + "	"+"Y-Direction ";					
			


			for(int i=0 ; i<num ;i++){	

				str = sr->ReadLine();
				SepData = str->Split('	');
				PointF tmpPt(Convert::ToSingle(SepData->GetValue(0)),Convert::ToSingle(SepData->GetValue(1)));
				Curve->ControllPt->Insert(i,tmpPt);
			
				
				Array::Clear(SepData,0,SepData->Length);	
			}			
			
			return true;
		
		}catch(...){
			sr->Close();
			MessageBox::Show(" 曲線參數 讀檔錯誤");
			return false;
		}



}




//-----Pt Number Reset----------------------------------
//-----Mesh Number Reset -------------------------------
//-----Inputdata Reset ---------------------------------




bool OpenDetailModifyPara(StreamReader ^ sr,ArrayList^ Localsurfacedata){


	//先清除舊有的資料~~<因為後面會用Add 的功能>
	Localsurfacedata->Clear();

	String^ str;
	array<String^>^ SepData;
	array<String^,1>^ Filedata;

	//跳過 Hot Spot 儲存資料
	for(int ii = 0 ; ii < 4 ; ii ++){
		str = sr->ReadLine(); // 讀取Hot Spot Data
	}

	//讀取LocalArea資料
	str = sr->ReadLine();
	int num = Convert::ToInt16(str); //得到資料筆數

	for(int ii = 0 ; ii < num ; ii ++){

		str = sr->ReadLine(); // 讀取LocalArea Data		

		

		SepData = str->Split('	');

  		Filedata = gcnew array<String^,1>(114); //開立一個新的記億體

		 Filedata->SetValue(Convert::ToString(ii), 0);
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(0)),1); //座標位置
		 float X_Coordinate = Convert::ToSingle(SepData->GetValue(1)); //左下角X 座標 
		 float Y_Coordinate = Convert::ToSingle(SepData->GetValue(2)); //左下角Y 座標
		 float Width = Convert::ToSingle(SepData->GetValue(3));
		 float Height = Convert::ToSingle(SepData->GetValue(4));

		 switch (Convert::ToInt16(SepData->GetValue(0))){
			 case 0: //左下				
				 break;
			 case 1: //左上 				
				 Y_Coordinate = Y_Coordinate + Height;
				 break;
			 case 2: //右上
				 X_Coordinate = X_Coordinate + Width;
				 Y_Coordinate = Y_Coordinate + Height;
				 break;
			 case 3: //右下
				 X_Coordinate = X_Coordinate + Width;
				 break;
			 case 4: //中心
				  X_Coordinate = X_Coordinate + Width/2;
				 Y_Coordinate = Y_Coordinate + Height/2;
				 break;
			 case 5: //左中
				 
				 Y_Coordinate = Y_Coordinate + Height/2;
				 break;
			 case 6: //右中
				 X_Coordinate = X_Coordinate + Width;
				 Y_Coordinate = Y_Coordinate + Height/2;
				 break;
			 case 7: //上中
				 X_Coordinate = X_Coordinate + Width/2;
				 Y_Coordinate = Y_Coordinate + Height;
				 break;
			 case 8: //下中
				  X_Coordinate = X_Coordinate + Width/2;
				 break;

		 }
		 Filedata->SetValue(Convert::ToString(X_Coordinate),2) ; //X 座標-->舊版是儲存左下角座標 ,必須重新換算
		 Filedata->SetValue(Convert::ToString(Y_Coordinate),3) ; //Y 座標-->舊版是儲存左下角座標 ,必須重新換算
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(3)),4) ; //Width
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(4)),5) ; //Height
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(5)),6) ; //U Value
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(6)),7) ; //V Value
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(32)),8) ; //陣列方向 -->舊版沒有
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(33)),9) ; //陣列數目 -->舊版沒有
		 Filedata->SetValue(Convert::ToString(SepData->GetValue(34)),10) ; //陣列間距 -->舊版沒有
		 Filedata->SetValue("",11) ; //名稱
		 Filedata->SetValue("5",12) ; //控制點數目X
		 Filedata->SetValue("5",13) ; //控制點數目Y
		int count = 14;
		 for(int i = 0 ;i < 5 ; i++){
			 for(int j = 0 ;j < 5  ; j++){			
				Filedata->SetValue(Convert::ToString(SepData->GetValue(7+i+j*5)) ,count);  //Z 值
				count ++;
				if(SepData->Length > 36 && SepData->Length <= 61){ 
					Filedata->SetValue(Convert::ToString(SepData->GetValue(35+i*5+j)) ,count);//Weight-->新版
				}else {
					Filedata->SetValue("1.0" ,count);//舊版
				}
					count ++;
				if(SepData->Length > 61 && SepData->Length <= 86) {
					Filedata->SetValue(Convert::ToString(SepData->GetValue(60+i*5+j)),count);  //X -->新版
				}else{
					Filedata->SetValue(Convert::ToString(Convert::ToSingle(SepData[3])/4*j) ,count);//舊版
				}
					count ++;
				
				if(SepData->Length > 86 ) {
					Filedata->SetValue(Convert::ToString(SepData->GetValue(85+i+j*5)),count);  //Y -->新版
				}else{
					Filedata->SetValue(Convert::ToString(Convert::ToSingle(SepData[4])/4*(4-i)) ,count);//舊版
				}
					count ++;
				
						
				//Notice : 舊版沒有的資料 ,程式在讀入時,會自動計算,呈現在表單中 .

			}
		}

		Array::Clear(SepData,0,SepData->Length);	

		Localsurfacedata->Add(Filedata);

		

	}	

	return true;

}
bool OpenDetailModifyPara(StreamReader ^ sr,Cosmetic_Data^ Cosmetic_Data){
	

	String^ str;
	array<String^>^ SepData;



	// Hot Spot 儲存
	Cosmetic_Data->HotBar_History_Data = gcnew array<String^,2>(4,81);
	
	for(int ii = 0 ; ii < 4 ; ii ++){
		str = sr->ReadLine(); // 讀取Hot Spot Data
			
		SepData = str->Split('	');
	
		for(int jj = 0 ; jj < SepData->Length-1 ; jj ++){  //SepData->Length-1 是扣除 換行
			if(Convert::ToString(SepData->GetValue(jj)) != ""){
				Cosmetic_Data->HotBar_History_Data->SetValue(Convert::ToString(SepData->GetValue(jj)),ii,jj);
			}
		}	
		Array::Clear(SepData,0,SepData->Length);
	}

	//Local Area 儲存
	
	str = sr->ReadLine();
	int num = Convert::ToInt16(str);

	Cosmetic_Data->LocalArea_History_Data = gcnew array<float,2>(num,110);

	for(int ii = 0 ; ii < num ; ii ++){
		str = sr->ReadLine(); // 讀取Hot Spot Data
		
		SepData = str->Split('	');

		for(int jj = 0 ; jj < SepData->Length-1 ; jj ++){		//SepData->Length-1 是扣除 換行	
			Cosmetic_Data->LocalArea_History_Data->SetValue(Convert::ToSingle(SepData->GetValue(jj)),ii,jj);					
		}	
		Array::Clear(SepData,0,SepData->Length);	

		//舊版資料沒有array 數目 ....定義為 1 		
		 if(Convert::ToInt16(Cosmetic_Data->LocalArea_History_Data->GetValue(ii,33)) < 1) 
			Cosmetic_Data->LocalArea_History_Data->SetValue(1,ii,33);

		 //舊版沒有定義weight .....定義為 1 
	}
	
	return true;

};



//開啟專案檔 ---Old Version
void OpenCLT_Characteristic_File(GridDensity^ tmpDensity,StreamReader ^ sr,DataInput &inputdata,bool &filenew){
		
	bool success1;
	MeshGrid *mg = nullptr;

	//sr->WriteLine("Version  1.0.0------------------------------------");
	sr->ReadLine();
	//sr->WriteLine("Part1---------------------------------------------");
	sr->ReadLine();

	success1 = OpenParaFile_071005(sr,inputdata,filenew);
	//success1 = SaveInputParaFile_071003(sr,inputdata);		
	
	sr->ReadLine();
	//sr->WriteLine("Part2---------------------------------------------");

	//--------暫時關閉------------------
	//mg = OpenDensityWithDimFile_071005(sr,inputdata,filenew);


	sr->Close();

	



}

//開啟專案檔 ---專案檔CLT_090112
bool OpenCLT_Characteristic_090112_File(StreamReader ^ sr,DataInput &inputdata,bool &filenew ,B_Spline_Surface^ Surface_Global_Design){

	bool success1,success2;
	

	//sr->WriteLine("Version  1.0.0------------------------------------");
	sr->ReadLine();
	//sr->WriteLine("Part1---------------------------------------------");
	sr->ReadLine();

	success1 = OpenParaFile_071005(sr,inputdata,filenew);
	//success1 = SaveInputParaFile_071003(sr,inputdata);		
	
	sr->ReadLine();
	//sr->WriteLine("Part2---------------------------------------------");

	success2 = OpenB_Spline_Surface(sr, Surface_Global_Design);

	

	sr->ReadLine();
	//sr->WriteLine("PartFinish----------------------------------------");

	sr->Close();

	if(success1 == true  && success2 == true){
		return true;
	}else{
		return false;
	}

	




};








//開啟專案檔 ---R1
bool OpenCLT_R1(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,ArrayList^ Localsurfacedata , B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve){

	bool success1,success2,success3;
	int fileversion = 0;



	array<String^>^ SepData;
	String^ str;
	str = sr->ReadLine(); // 讀取檔案版本
	//Array::Clear(SepData,0,SepData->Length);					
	SepData = str->Split('	');		
	fileversion = Convert::ToInt16(SepData->GetValue(1));
	
	if (fileversion == 1) {
	
		sr->ReadLine();   //("Part1---------------------------------------------");
		success1 = OpenParaFile_R1( sr,formdata);				
	//	sr->ReadLine();  //("Part2---------------------------------------------");
		success2 = OpenB_Spline_Surface(sr, Surface_Global_Design);
		sr->ReadLine();//("PartFinish----------------------------------------");
		sr->Close();

		success3 = true;

	}else if(fileversion == 2) {
		sr->ReadLine();   //("Part1---------------------------------------------");
		success1 = OpenParaFile_R1( sr,formdata);				
	//	sr->ReadLine();  //("Part2---------------------------------------------");
		success2 = OpenB_Spline_Surface(sr, Surface_Global_Design);
		sr->ReadLine();//("Part3----------------------------------------");
	//	success3 = OpenDetailModifyPara( sr, Cosmetic_Data);
		success3 = OpenDetailModifyPara( sr, Localsurfacedata);
		sr->ReadLine();//("PartFinish----------------------------------------");
		sr->Close();
	}else if(fileversion == 3){
		sr->ReadLine();   //("Part1---------------------------------------------");
		success1 = OpenParaFile_R1( sr,formdata);				
	//	sr->ReadLine();  //("Part2---------------------------------------------");
		success2 = OpenB_Spline_Surface(sr, Surface_Global_Design);
		sr->ReadLine();//("Part3----------------------------------------");
	//	success3 = OpenDetailModifyPara( sr, Cosmetic_Data);
		success3 = OpenDetailModifyPara( sr, Localsurfacedata);
		//str = sr->ReadLine(); //更改程式碼後 ,需要多讀一行Data
		//sr->ReadLine();//("Part4-1  Horizontal----------------------------------------");
		//success4 = OpenB_Spline_Curve( sr,H_Curve);
		//sr->ReadLine();//("Part4-2  Vertical ----------------------------------------");
		//success5 =OpenB_Spline_Curve( sr,V_Curve);
		//sr->ReadLine();//("PartFinish----------------------------------------");
		sr->Close();
	}

	if(success1 == true  && success2 == true && success3 == true){
		return true;
	}else{
		return false;
	}


}
//附屬儲存子函式

//舊專案檔適用
bool OpenParaFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew){



	try{


			String^ fileVersion = "ParaFileVersion 1.0.0";
			
			String^ str ;
			String^ buffer;
			String^ buffer2;
			//讀取檔案版本格式
			int found = 0 ,found2 = 0; 
			int compare = -1;
			str = sr->ReadLine();

			found = str->IndexOf("	");
			if (found != -1)
				//buffer =str->Substring(found)->Trim();
				buffer =str->Substring(0,found);
			else
				buffer =str->Substring(0)->Trim();


			//str=String::Format("{0:F}","ParaFileVersion 1.0.0");
			compare = String::Compare(buffer,fileVersion);
			if (compare != 0 ) {
				sr->Close();
				MessageBox::Show("讀取的檔案版本與此軟體不相容 ,此軟體允許版本為 : " + fileVersion);
				return false ;
			}



		found = 0;
		str = sr->ReadLine();
		
		found = str->IndexOf( "	" );
		if (found != -1)
			buffer =str->Substring(0,found);
		else
			buffer =str->Substring(0)->Trim();
		//str=String::Format("{0:F}",inputdata.PatternMode);	
		inputdata.PatternMode = (int)Convert::ToSingle(buffer);  //不能直接用Convert::ToInt16 轉換


		str = sr->ReadLine();
		float tmp[4];
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.PatternNumberSelection,inputdata.PatternNumber);
			
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer = str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 
			
			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.PatternNumberSelection = Convert::ToInt16(tmp[0]) ;
		inputdata.PatternNumber = Convert::ToInt16(tmp[1]);

		
		str = sr->ReadLine();
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.PlateWidth,inputdata.PlateHeight);
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.PlateWidth  = tmp[0] ;
		inputdata.PlateHeight  = tmp[1];


		str = sr->ReadLine();
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.PatternShape,inputdata.PatternRadius);
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.PatternShape = Convert::ToInt16(tmp[0]) ;
		inputdata.PatternRadius = tmp[1];


		str = sr->ReadLine();
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.MeshNumber[0],inputdata.MeshNumber[1]);	
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.MeshNumber[0] = Convert::ToInt16(tmp[0]);
		inputdata.MeshNumber[1] = Convert::ToInt16(tmp[1]);


		//str = sr->ReadLine();
		//for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.MeshNumber[0],inputdata.MeshNumber[1]);	
		//	found = str->IndexOf( "	" );
		//	if (found != -1){
		//		buffer   =str->Substring(0,found);
		//		buffer2  =str->Substring(found)->Trim(); 
		//	}else
		//		buffer = str->Substring(0)->Trim(); 
//
//			tmp[i] = Convert::ToSingle(buffer);
//			str = buffer2;
//		}
//		inputdata.MeshNumber[0] = tmp[0];
//		inputdata.MeshNumber[1] = tmp[1];
		
	
		str = sr->ReadLine();
		for (int i = 0 ; i <4 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}"+"	"+ "{2:F}"+"	"+"{3:F}",inputdata.Boundary_Up,inputdata.Boundary_Down,inputdata.Boundary_Left,inputdata.Boundary_Right);	
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.Boundary_Up = tmp[0];
		inputdata.Boundary_Down = tmp[1];
		inputdata.Boundary_Left = tmp[2];
		inputdata.Boundary_Right = tmp[3];
		

		str = sr->ReadLine();		
		found = str->IndexOf( "	" );
		if (found != -1)
			buffer =str->Substring(0,found);
		else
			buffer = str->Substring(0)->Trim(); 
		//str=String::Format("{0:F}",inputdata.Pattern_Space);
		inputdata.Pattern_Space = Convert::ToSingle(buffer);
		
			
		str = sr->ReadLine();
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.StopCriteria,inputdata.StopCriteriaIteriation);
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else
				buffer = str->Substring(0)->Trim(); 

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.StopCriteria = Convert::ToInt16(tmp[0]);
		inputdata.StopCriteriaIteriation = Convert::ToInt16(tmp[1]);

		

		str = sr->ReadLine();		
		found = str->IndexOf( "	" );
		if (found != -1)
			buffer =str->Substring(0,found);
		else
			buffer = str->Substring(0)->Trim(); 
		//str=String::Format("{0:F}",inputdata.CalMode);
		inputdata.CalMode =(int)Convert::ToSingle(buffer);   //不能直接用Convert::ToInt16 轉換 
		


		

		str = sr->ReadLine();		
		found = str->IndexOf( "	" );
		if (found != -1)
			buffer =str->Substring(0,found);
		else
			buffer = str->Substring(0)->Trim(); 

		//str=String::Format("{0:F}",inputdata.SimShape);	
		inputdata.SimShape = (int)Convert::ToSingle(buffer);  //不能直接用Convert::ToInt16 轉換 


		str = sr->ReadLine();
		for (int i = 0 ; i <2 ; i++){
			//str=String::Format("{0:F}"+"	"+"{1:F}",inputdata.Parameter_K,inputdata.Parameter_C);	
			found = str->IndexOf( "	" );
			if (found != -1){
				buffer   =str->Substring(0,found);
				buffer2  =str->Substring(found)->Trim(); 
			}else{
				buffer = str->Substring(0)->Trim(); 
			}

			tmp[i] = Convert::ToSingle(buffer);
			str = buffer2;
		}
		inputdata.Parameter_K = tmp[0];
		inputdata.Parameter_C = tmp[1];
		

		return true;

	}
	catch(...){
		sr->Close();
		MessageBox::Show("專案檔_參數讀檔_錯誤");
		filenew = true;
		return false;
	}




};
MeshGrid  *OpenDensityWithDimFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew){
	





	float pos[2],size[2];
//	float density;
	float tmp[4];
	MeshGrid *mg = nullptr;
//	String^ str ;
//	String^ buffer;
	//int length;

		
		try{


			String^ fileVersion = "DenSityVersion 1.0.0";
			
			String^ str ;
			String^ buffer;
			String^ buffer2;
			//讀取檔案版本格式
			int found = 0 ,found2 = 0; 
			int compare = -1;
			str = sr->ReadLine();

			found = str->IndexOf("	");
			if (found != -1)
				//buffer =str->Substring(found)->Trim();
				buffer =str->Substring(0,found);
			else
				buffer =str->Substring(0)->Trim();


			//str=String::Format("{0:F}","DenSityVersion 1.0.0");		
			compare = String::Compare(buffer,fileVersion);
			if (compare != 0 ) {
				sr->Close();
				MessageBox::Show("讀取的檔案版本與此軟體不相容 ,此軟體允許版本為 : " + fileVersion);
				return false ;
			}

		
			mg = new MeshGrid[inputdata.MeshNumber[0]*inputdata.MeshNumber[1]];
			
		
			for(int i=0;i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1];i++){


				str = sr->ReadLine();
				
				for (int jj = 0 ; jj <3 ; jj++){
					//str=String::Format("{0:F}"+"	"+"{1:F}"+"	"+"{2:F}",pos[0],pos[1],mg[i].GetPatternDensityinMesh());	
					found = str->IndexOf( "	" );
					if (found != -1){
						buffer   =str->Substring(0,found);
						buffer2  =str->Substring(found)->Trim(); 
					}else
						buffer = str->Substring(0)->Trim(); 

					tmp[jj] = Convert::ToSingle(buffer);
					str = buffer2;
				}
				pos[0] = tmp [0];
				pos[1] = tmp [1];

				mg[i].SetMeshPosition(pos);
				mg[i].SetPatternDensityinMesh(tmp[2]);
					
				size[0] = inputdata.PlateWidth /inputdata.MeshNumber[0];
				size[1] = inputdata.PlateHeight /inputdata.MeshNumber[1];
				mg[i].SetMeshSize(size);
				mg[i].PtNumbers = 0;



			}
			//sr->Close();
			return mg;
	
		}
		catch(...)
		{
			//sr->Close();
			MessageBox::Show("Density讀檔錯誤!");
			filenew = true;
			mg = nullptr;
			return mg;
			
		}
		
		
		



	

}//




bool OpenControllPt(StreamReader ^ sr,SmoothSurfaceInfo^ controllpt,DataInput inputdata){
	
	try{
			String^ fileVersion = "ControllPt_Part_V1.0.0";


			String^ str ;
			String^ buffer;
			String^ buffer2;
			//讀取檔案版本格式
			int found = 0 ,found2 = 0; 
			int compare = -1;
			str = sr->ReadLine();
			found = str->IndexOf( "	" );
			if (found != -1)
				//buffer =str->Substring(found)->Trim();
				buffer =str->Substring(0,found);
			else
				buffer = str->Substring(0)->Trim(); 
			//str =String::Format("{0:F}","ControllPt_Part_V1.0.0");
			compare = String::Compare(buffer,fileVersion);
			if (compare != 0 ) {
				sr->Close();
				MessageBox::Show("讀取的檔案版本與此軟體不相容 ,此軟體允許版本為 : " + fileVersion);
				return false;
			}


			float tmp[2];

			found = 0;			
			str = sr->ReadLine();
			for (int i = 0 ; i <2 ; i++){
				//str=String::Format("{0:F}"+"	"+"{1:F}",controllpt->Controll_Row_number,controllpt->Controll_Collum_number);
				found = str->IndexOf( "	" );
				if (found != -1){
					buffer   =str->Substring(0,found);
					buffer2  =str->Substring(found)->Trim(); 
				}else
					buffer = str->Substring(0)->Trim(); 
				tmp[i] = Convert::ToSingle(buffer);
				str = buffer2;
			}
			//controllpt->Controll_Row_number = tmp[0];
			//controllpt->Controll_Collum_number = tmp[1];

		
			controllpt->Initialize(inputdata.PlateWidth ,inputdata.PlateHeight ,0);
			
			controllpt->Controll_Row_number = (int)tmp[0];
			controllpt->Controll_Collum_number = (int)tmp[1];

			controllpt->SetControllPt_Number_IniValue(controllpt->Controll_Row_number,controllpt->Controll_Collum_number,controllpt->IniValue_Z);

			str = sr->ReadLine();
			//str = "X-Location";
		

			for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
				str = sr->ReadLine();
				for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
					//str =String::Format("{0:F}"+"	",controllpt->controllPt_X->GetValue(i,j));
					found = str->IndexOf( "	" );
					if (found != -1){
						buffer   =str->Substring(0,found);
						buffer2  =str->Substring(found)->Trim(); 
					}else
						buffer = str->Substring(0)->Trim();
					controllpt->controllPt_X->SetValue(Convert::ToSingle(buffer),i,j);
					str = buffer2;
					
				}
			}


			str = sr->ReadLine();			
			//str = "Y-Location";

			
			for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
				str = sr->ReadLine();
				for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
					//str =String::Format("{0:F}"+"	",controllpt->controllPt_Y->GetValue(i,j));
					found = str->IndexOf( "	" );
					if (found != -1){
						buffer   =str->Substring(0,found);
						buffer2  =str->Substring(found)->Trim(); 
					}else
						buffer = str->Substring(0)->Trim(); 

					controllpt->controllPt_Y->SetValue(Convert::ToSingle(buffer),i,j);
					str = buffer2;
					
				}
			}


			str = sr->ReadLine();			
			//str = "Z-Location";


			for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
				str = sr->ReadLine();
				for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
					//str =String::Format("{0:F}"+"	",controllpt->controllPt_Z->GetValue(i,j));
					found = str->IndexOf( "	" );
					if (found != -1){
						buffer   =str->Substring(0,found);
						buffer2  =str->Substring(found)->Trim(); 
					}else
						buffer = str->Substring(0)->Trim(); 

					controllpt->controllPt_Z->SetValue(Convert::ToSingle(buffer),i,j);
				
					str = buffer2;
					
				}
			}



			str = sr->ReadLine();			
			//str = "IniValue_Z";
			

			str = sr->ReadLine();		
			found = str->IndexOf( "	" );
			if (found != -1)
				buffer =str->Substring(0,found);
			else
				buffer = str->Substring(0)->Trim(); 
			//str = Convert::ToString(controllpt->IniValue_Z);
			controllpt->IniValue_Z = Convert::ToSingle(buffer);
			
			str = sr->ReadLine();	
			//str = "Current Controll Pt Index";

			
			str = sr->ReadLine();
			for (int i = 0 ; i <2 ; i++){
				//str=String::Format("{0:F}"+"	"+"{1:F}",controllpt->SelectIndex_X,controllpt->SelectIndex_Y);
				found = str->IndexOf( "	" );
				if (found != -1){
					buffer   =str->Substring(0,found);
					buffer2  =str->Substring(found)->Trim(); 
				}else
					buffer = str->Substring(0)->Trim(); 

				tmp[i] = Convert::ToSingle(buffer);
				str = buffer2;
			}
			controllpt->SelectIndex_X = (int)tmp[0];
			controllpt->SelectIndex_Y = (int)tmp[1];

			
			str = sr->ReadLine();
			//str = "Bool Empty";

			str = sr->ReadLine();		
			found = str->IndexOf( "	" );
			if (found != -1)
				buffer =str->Substring(0,found);
			else
				buffer = str->Substring(0)->Trim(); 
		
			
			CompareInfo^ myCompare = CultureInfo::InvariantCulture->CompareInfo;
					
			if(myCompare->Compare(buffer,"True",CompareOptions::IgnoreCase) == 0)
				controllpt->Empty =true;
			else
				controllpt->Empty =false;
			
			return true;
	}
	catch(...){
		MessageBox::Show("Surface-ControllPt讀檔錯誤");
		return false;
	}

};





//專案檔 CLT_090112 適用
bool OpenB_Spline_Surface(StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design){

	try{

	//-----------------------------------------------------------------------------------------
	//Surface 定義資料是 Index 0 ->Name;
	//Surface 定義資料是 Index 1 ->U Value (平滑度X);
	//Surface 定義資料是 Index 2 ->V Value (平滑度Y);
	//Surface 定義資料是 Index 3 ->解析度 X;
	//Surface 定義資料是 Index 4 ->解析度 Y;
	//Surface 定義資料是 Index 5 ->控制點數X ;
	//Surface 定義資料是 Index 6 ->控制點數Y ;
	//Surface Index 7 以後的陣列資料是 :
	// count + 0 -> 控制點座標X  ,count + 1 --> 控制點座標Y ,count + 2 --> Z Value ,count + 3 ->權重 
    //-------------------------------------------------------------------------------------------

		array<String^>^ FileData;
	

		String^ fileVersion = "Surface_Para_V1.0.0";
		String^ fileVersion2 = "Surface_Para_V1.0.1";
		String^ str;
		int version = 0;		
		int compare = -1;
		int compare2 = -1;

		array<String^>^ SepData;
		str = sr->ReadLine(); // 讀取檔案版本
		SepData = str->Split('	');	
		compare = String::Compare(Convert::ToString(SepData->GetValue(0)),fileVersion);
		compare2 = String::Compare(Convert::ToString(SepData->GetValue(0)),fileVersion2);

		if (compare != 0 && compare2 != 0) {
			sr->Close();
			MessageBox::Show("讀取的檔案版本與此軟體不相容 ,此軟體允許版本為 : " + fileVersion + "或" + fileVersion2 );
			return false;
		}else{
			if(compare  == 0) version = 100 ;
			if(compare2 == 0) version = 101 ;
		}





		str = sr->ReadLine(); // 讀取控制點數目
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
		//int Num_H = 0 ,Num_V = 0;
		FileData = gcnew array<String^>(4*Convert::ToInt16(SepData[1])*Convert::ToInt16(SepData[2])+7);  
		FileData->SetValue(SepData[1],5);
		FileData->SetValue(SepData[2],6);
		//Num_V = Convert::ToInt16(SepData->GetValue(2));
		


		str = sr->ReadLine(); // 讀取解析度
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
	//	int resolution_H = 0 ,resolution_V = 0;
	//	resolution_H = Convert::ToInt16(SepData->GetValue(1));
	//	resolution_V = Convert::ToInt16(SepData->GetValue(2));
		FileData->SetValue(SepData[1],3);
		FileData->SetValue(SepData[2],4);


		
		str = sr->ReadLine(); // 讀取平滑度
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
	//	int tmpU = 0,tmpV = 0 ;
	//	tmpU = Convert::ToInt16(SepData->GetValue(1));
	//	tmpV = Convert::ToInt16(SepData->GetValue(2));
		FileData->SetValue(SepData[1],1);
		FileData->SetValue(SepData[2],2);


//		Surface_Global_Design->Set_uv_Value(tmpU,tmpV);
		
		
		str = sr->ReadLine(); // 疏密參數 Mark

		
	//	Point CptNum(Num_H,Num_V); Point Degree(tmpU,tmpV); Point Resolution(resolution_H,resolution_V);

    //  這個要加下去 ,...目前只是暫時關必
	//	Surface_Global_Design->CreateZeroSurface(CptNum,Degree,Resolution);



	//	array<PointF,2>^ ControllPt = gcnew array<PointF,2>(Num_H,Num_V);
	//	array<float,2>^ ControllPt_Z = gcnew array<float,2>(Num_H,Num_V);
	//	array<float,2>^ Weight = gcnew array<float,2>(Num_H,Num_V);


		//-----------------------------------------------------------------------
		int count = 7;

		for(int j = 0 ; j <	Convert::ToInt16(FileData[6]) ; j ++){
			str = sr->ReadLine(); // 讀取疏密參數
			Array::Clear(SepData,0,SepData->Length);					
			SepData = str->Split('	');
			for(int i = 0 ; i <	Convert::ToInt16(FileData[5]) ; i++){
				float tmpZ = Convert::ToSingle(SepData->GetValue(i));


			//	if(version == 100) FileData->SetValue(Convert::ToString(tmpZ),count+2) ;
			//	else if(version == 101) FileData->SetValue(Convert::ToString(tmpZ),4*Convert::ToInt16(FileData[5])*Convert::ToInt16(FileData[6])+5 + 7 -count);
				FileData->SetValue(Convert::ToString(tmpZ),count+2) ;

				FileData->SetValue("1.0",count+3);
				
				count = count + 4;
			
			}			
		}


		

		str = sr->ReadLine(); // (X,Y)座標參數 Mark

		count = 7;

		for(int j = 0 ; j <	Convert::ToInt16(FileData[6]) ; j ++){
			
			str = sr->ReadLine(); // 讀取(X,Y)座標參數參數
			Array::Clear(SepData,0,SepData->Length);					
			SepData = str->Split('	');

			array<String^>^ XYData;
			PointF tmpCoor(0,0);
			
			for(int i = 0 ; i <	Convert::ToInt16(FileData[5]) ; i++){
				
			
				//V1.01版 Y 座標沒有進行處理的

			//	XYData = Convert::ToString(SepData->GetValue(i))->Split(',');
			//	FileData->SetValue(XYData[0],count) ;
			//	FileData->SetValue(XYData[1],count+1) ;
			//	count = count + 4;

				// Y 座標要進行處理的 
				if(version == 100) {
					XYData = Convert::ToString(SepData->GetValue(i))->Split(',');
					FileData->SetValue(XYData[0],count) ;
					FileData->SetValue(XYData[1],4*Convert::ToInt16(FileData[5])*Convert::ToInt16(FileData[6])+7-(count+3-7)) ;
					count = count + 4;
				}else{
					XYData = Convert::ToString(SepData->GetValue(i))->Split(',');
					FileData->SetValue(XYData[0],count) ;
					FileData->SetValue(XYData[1],count+1) ;
					count = count + 4;
				}

				

			

			
			}
			
		}




		Surface_Global_Design->SaveSurfaceData(FileData);


		


	//	Surface_Global_Design->SetSurfaceData(ControllPt,ControllPt_Z,Weight);
	//	




		return true;

	}catch(...){
		MessageBox::Show("Surface 參數讀檔錯誤");
		return false;
	}





};


//專案檔R1版適用
bool OpenParaFile_R1(StreamReader ^ sr,MainFormData^ formdata){



	try{



		String^ str =nullptr;
		array<String^>^ SepData;
		int read_data_number = -1;
		str = sr->ReadLine();
		while(String::Compare(str,"Part2---------------------------------------------") != 0 ){
			
		//	if (String::Compare(str,"Part2---------------------------------------------") == 0 )  break;
			if(SepData != nullptr) Array::Clear(SepData,0,SepData->Length);			
			SepData = str->Split('	');
			read_data_number ++;
			switch (read_data_number){
				case 0 : // 讀取佈點方式
				//	formdata->RandomDot = Convert::ToBoolean(SepData->GetValue(1));
					formdata->DotType = Convert::ToInt16(Convert::ToBoolean(SepData->GetValue(1)));
					break;
				case 1: // 讀取LGP尺寸
					formdata->LGPInformation.Width = Convert::ToSingle(SepData->GetValue(1));
					formdata->LGPInformation.Height = Convert::ToSingle(SepData->GetValue(2));
					formdata->LGPInformation.X = 0;
					formdata->LGPInformation.Y = 0;
					break;
				case 2: // 讀取最大網點
					formdata->MaxDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 3:// 讀取最小網點
					formdata->MinDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 4:// 最小網點間格
					formdata->MinDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 5:// 網點形狀
					formdata->Pattern_Shape = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 6:// 網點排列方式
					formdata->Pattern_Arrangment = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 7:// 亂數網點大小
					formdata->RandomDotSize = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 8:// 網點期望距離
					formdata->RandomDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 9:// 運算次數
					formdata->RandomDotIteration = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 10:// 運算法則
					formdata->RandomDotSimRule = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 11:// 參數K
					formdata->Parameter_K = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 12:// 參數C
					formdata->Parameter_C = Convert::ToSingle(SepData->GetValue(1));
					break;
				//Updata  20091203--------------------------------------------------------
				case 13:// 密度調整方式
					formdata->DensityDesignMethod = Convert::ToInt16(SepData->GetValue(1));	
					break;
				case 14: //亂數條件(Force,核取次數,核取Force)
					formdata->RandomStopForce = Convert::ToSingle(SepData->GetValue(1));
					formdata->chkStopNmber = Convert::ToBoolean(SepData->GetValue(2));
					formdata->chkStopForce = Convert::ToBoolean(SepData->GetValue(3));						
					break;
				case 15: //亂數 重建頻率
					formdata->RandomRebuildFrequency = Convert::ToInt16(SepData->GetValue(1));
					break;				
			}

			str = sr->ReadLine();
			
			
		}

	

		return true;

	}
	catch(...){
		sr->Close();
		MessageBox::Show("專案檔_參數讀檔_錯誤");

		return false;
	}




};


