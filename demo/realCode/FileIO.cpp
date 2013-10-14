#include "stdafx.h"
#include "FileIO.h"
#include < vcclr.h >
#include < stdio.h >
#include < stdlib.h >
//#include "Calculate.h"
using namespace System::Collections;
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
using namespace System::Drawing ;



//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//-------------V2 ���� -------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

bool SaveCLT_V3(StreamWriter ^ sr,int MFversion ,MainFormData^ formdata,int GSversion ,Nurbs::B_Spline_Surface^ Surface_Global_Design,int LSversion ,ArrayList^ Localsurfacedata,int GCversion ,B_Spline_Curve^ Curve_H,B_Spline_Curve^ Curve_V,int ProjVersion,Project_Information^ ProjInformation ,int HotSpotVersion ,ArrayList^ HotSpotData){
		bool success1,success2,success3,success4,success5 ;



		if (formdata != nullptr){
			success1 = SaveMainformPara(Convert::ToString(MFversion), sr,formdata);
		};
		if ( Surface_Global_Design != nullptr){
			success2 = SaveGlobalAreaPara(Convert::ToString(GSversion),sr,Surface_Global_Design);
		}else{
			success2 = true;
			MessageBox::Show("�L������ƥi�H�x�s");
		}
		if(Localsurfacedata->Count > 0){
			success3 = SaveLocalAreaPara(Convert::ToString(LSversion), sr, Localsurfacedata);
		}else{
			success3 = true;			
		}
		if(ProjInformation != nullptr){
			success4 =  SaveProjInformation(Convert::ToString(ProjVersion), sr, ProjInformation);
		}else{
			success4 = true;
		}
		if(HotSpotData != nullptr){
			success5 = SaveHotSpotData(Convert::ToString(HotSpotVersion), sr, HotSpotData);
		}
		




		//if(Curve_H->ControllPt->Count > 0 || Curve_V->ControllPt->Count > 0 ){
		//	success4 = SaveGlobalLinePara(Convert::ToString(GCversion), sr, Curve_H ,  Curve_V);
		//}
		//	bool SaveLGPPara(String^ version,StreamWriter ^ sr,array<String^>^ LGPPara);
  
	

		

		if(success1 == true && success2 == true && success3 == true && success4 == true){
		//if(success1 == true && success2 == true && success3 == true && success4 == true ){
			return true;
		}else{
			return false;
		}

};


//�}�ұM����---V3��
bool OpenCLT_V3(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,ArrayList^ Localsurfacedata,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve,Project_Information^ ProjInformation,ArrayList^ HotSpotData){

	//1) Ū����ƫ�,�P�O���S�� "$" �r�� ,������ ,�ھ�"$"�᪺��r�P�O�n�ϥέ����ɮ�Ū�h , "_" �᪺�ƾڬO�x�s�ɮת������X .
	//   �H���s�x�s��Ʈ� ,�i�H�ھڪ����X�h�ץ� 
	//2) "{"�r�� ,�O��Ū����ƪ��Y  , "}" �O�� .
	//3) ","�r�� ,�O���j��ƪ�����  ,��MainformPara �O�H " " �@�Ϲj
	//4) �Y�O�H��n�ܧ��� ,�Цb{ �M } ���W�[ ,�o�˵{���X��̤�..
	//
	//   LocalAreaPara  : �O�����ק��椤���Ѽ�
	//   GlobalAreaPara : �O�㭱�ק�ϥ�Surface ���Ѽ�
	//   GlobalLinePara : �O�㭱�ק�ϥΤ��� Line �M���� Line �ۭ� ���Ѽ�
	//   LGPPara        : �O����LGP�����Ѽƪ����Ѽ� ,�t�o������ ,���,�]�p�H����
	//   MainformPara   : �DForm�����





	try{

		
		//�N��ƲM��
		//Localsurfacedata->Clear();


		while(sr->EndOfStream != true){

			
			String^ str ;
			
			
			str = sr->ReadLine();
			if(str->Contains("$")){		

				//�w�q���Φr�� ,���Ϋ᪺�r��N�q�O :
				// Index 0 : None
				// Index 1 : Title
				// Index 2 : ����
				// Index 3 : �۹��������


				array<wchar_t>^ spchar = {'$','_','{','}'};   
				array<String^>^ tmpString;   // ���Ϋ᪺�r�궰�X
				tmpString = str->Split(spchar);

				String^ title = (String^)tmpString->GetValue(1);   // Title

				String^ version = (String^)tmpString->GetValue(2) ;			

				if(String::Compare("LocalAreaPara",title) == 0){
					LoadLocalAreaPara(tmpString,Localsurfacedata);
				}else if (String::Compare("GlobalAreaPara",title) == 0){
					LoadGlobalAreaPara(version, sr, Surface_Global_Design);
				}else if (String::Compare("GlobalLinePara",title) == 0){
					//LoadGlobalLinePara(version, sr, H_Curve ,  V_Curve);
				}else if (String::Compare("LGPPara",title) == 0){
					//	LoadLGPPara(version,sr,array<String^>^ LGPPara);
				}else if (String::Compare("MainformPara",title) == 0){
					 LoadMainformPara(version, sr , formdata);
				}else if (String::Compare("ProjInformation",title) == 0){
					 LoadProjInformation(version,sr,ProjInformation);
				}else if (String::Compare("HotSpotData",title) == 0){
					LoadHotSpotData(version, sr,HotSpotData);
				};

			}
			
		}

		return true;

	}catch(...){

		return false;

	}



}








bool SaveProjInformation(String^ version,StreamWriter ^ sr,Project_Information^ ProjInformation){


	//��s�]�p���
	ProjInformation->DesignDate = Convert::ToString(System::DateTime::Now::get());

	try{

		sr->Write("$");
		sr->Write("ProjInformation_" + version);
		sr->Write('\n');
		sr->Write("{ ");
		sr->Write('\n');


			String^ str;		
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���ئW�� " , ProjInformation->projectName);		
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","Pattern���� ",ProjInformation->PatternVersion );
			sr->WriteLine(str); 
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���`�o�� ",Convert::ToString(ProjInformation->RegularInkProperty));
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�S��o�� ",ProjInformation->SpecialInk);		
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���O�j�p ",Convert::ToString(ProjInformation->ScreenSize));	
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���� ",Convert::ToString(ProjInformation->MeshSize));	
			sr->WriteLine(str);	
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�ūp ",Convert::ToString(ProjInformation->Thick));
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���O���� ",Convert::ToString(ProjInformation->ScreenAngle));
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�]�p�� ",ProjInformation->Designer);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�]�p��� ",ProjInformation->DesignDate);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","LGP�Ȥ�Ƹ� ",ProjInformation->LGP_PN_Number);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","���~���A ",Convert::ToString(ProjInformation->ProductionStyle));
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�s�y�a ",Convert::ToString(ProjInformation->LGP_Manufacture));
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","LGP���� ",Convert::ToString(ProjInformation->LGP_Material));
			sr->WriteLine(str);
			


		sr->Write(" }");
		sr->Write('\n');

			return true;

	}catch(...){
		return false;
	}




}
bool SaveLocalAreaPara(String^ version,StreamWriter ^ sr,ArrayList^ Localsurfacedata){


	try{

		for(int ii = 0 ; ii< Localsurfacedata->Count ; ii ++){
			array<String^>^ tmparray;
			tmparray = (array<String^>^)Localsurfacedata->default[ii];

			sr->Write("$LocalAreaPara_" + version + "{");
			for(int jj = 0 ;jj<tmparray->Length ; jj++){			
				sr->Write(tmparray->GetValue(jj));
				if(jj<tmparray->Length-1 ) sr->Write(',');
			}
			sr->Write("}");
			sr->Write('\n');

		}

		/*
		sr->Write("$");
		sr->Write("LocalAreaPara_" + version);
		sr->Write('\n');

		sr->Write("{");
		sr->Write('\n');

		for(int ii = 0 ; ii< Localsurfacedata->Count ; ii ++){
			array<String^>^ tmparray;
			tmparray = (array<String^>^)Localsurfacedata->default[ii];
			
			for(int jj = 0 ;jj<tmparray->Length ; jj++){			
				sr->Write(tmparray->GetValue(jj));
				if(jj<tmparray->Length-1 ) sr->Write(',');
			}
			sr->Write('\n');
			
		}
		sr->Write("}");
		sr->Write('\n');

		*/

			return true;

	}catch(...){
		return false;
	}





}
bool SaveGlobalAreaPara(String^ version ,StreamWriter ^ sr,B_Spline_Surface^ Surface_Global_Design){

	try{

		sr->Write("$");
		sr->Write("GlobalAreaPara_" + version);
		sr->Write('\n');

		array<String^>^ tmparray =  Surface_Global_Design->LoadSurfaceInputData();
		
		sr->Write("{ ");
		sr->Write('\n');
		
		for(int jj = 0 ;jj<tmparray->Length ; jj++){	
			
			sr->Write(Convert::ToString(tmparray[jj]));
			

			if(jj < tmparray->Length-1 ) sr->Write(',');

		}
		sr->Write('\n');
		sr->Write(" }");
		sr->Write('\n');

		return true;

	}catch(...){
		return false;
	}


}
bool SaveGlobalLinePara(String^ version ,StreamWriter ^ sr,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve){


	try{

		sr->Write("$");
		sr->Write("GlobalLinePara_" + version);
		sr->Write('\n');

		sr->Write("{ ");
		sr->Write('\n');


		for(int jj = 0 ;jj<H_Curve->ControllPt->Count ; jj++){		
			PointF tmpPt = (PointF)H_Curve->ControllPt->default[jj];
			sr->Write(Convert::ToString(tmpPt.X) );
			sr->Write(' ');
			sr->Write(Convert::ToString(tmpPt.Y) );
			sr->Write(' ');
		}
		sr->Write('\n');




		for(int jj = 0 ;jj<V_Curve->ControllPt->Count ; jj++){		
			PointF tmpPt = (PointF)V_Curve->ControllPt->default[jj];
			sr->Write(Convert::ToString(tmpPt.X) );
			sr->Write(' ');
			sr->Write(Convert::ToString(tmpPt.Y) );
			sr->Write(' ');
		}
		sr->Write('\n');


		sr->Write(" }");
		sr->Write('\n');


			return true;

	}catch(...){
		return false;
	}





}

bool SaveLGPPara(String^ version,StreamWriter ^ sr ,array<String^>^ LGPPara){

	return false;

}
bool SaveMainformPara(String^ version,StreamWriter ^ sr ,MainFormData^ formdata){

		try{

		sr->Write("$");
		sr->Write("MainformPara_" + version);
		sr->Write('\n');
		sr->Write("{ ");
		sr->Write('\n');


			String^ str;		
			//str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�G�I�覡" , formdata->RandomDot);	
			str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�G�I�覡" , formdata->DotType);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}","LGP�ؤo ",formdata->LGPInformation.Width ,formdata->LGPInformation.Height );
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤j���I ",formdata->MaxDot);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤p���I",formdata->MinDot);		
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤p���I����",formdata->MinDotGap);	
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","���I�Ϊ�",formdata->Pattern_Shape);	
			sr->WriteLine(str);	
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","���I�ƦC�覡",formdata->Pattern_Arrangment);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�üƺ��I�j�p",formdata->RandomDotSize);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","���I����Z��",formdata->RandomDotGap);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�B�⦸��",formdata->RandomDotIteration);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�B��k�h",formdata->RandomDotSimRule);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�Ѽ�K",formdata->Parameter_K);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�Ѽ�C",formdata->Parameter_C);
			sr->WriteLine(str);
			//Updata  20091203
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�K�׽վ�覡",formdata->DensityDesignMethod);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0}"+"	"+"{3:#0}","�üƱ���(Force,�֨�����,�֨�Force)",formdata->RandomStopForce,formdata->chkStopNmber,formdata->chkStopForce);
			sr->WriteLine(str);
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�ü� �����W�v",formdata->RandomRebuildFrequency);
			sr->WriteLine(str);

		//	if(version == "2"){
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","Pitch ��V",formdata->PitchDirection);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","Pitch �ƭ�",formdata->ActualPitchValue);
				sr->WriteLine(str);
				//20110907  �s�W
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","IJP BlockX",formdata->IJP_BlockX);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","IJP BlockY",formdata->IJP_BlockY);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","IJP DotSize",formdata->IJP_DotSize);
				sr->WriteLine(str);

				//20120319 IJP��r
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","IJP TextEdit",formdata->IJP_chkTextEdit);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","IJP TextLocation",formdata->IJP_TextLocation);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","IJP TextLocaX",formdata->IJP_TextLocation_X);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","IJP TextLocaY",formdata->IJP_TextLocation_Y);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","IJP TextHeight",formdata->IJP_TextHeight);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","IJP TextLength",formdata->IJP_TextLength);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","IJP Text",formdata->IJP_Text);
				sr->WriteLine(str);

				//20120319 FM�ü�
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","FM DotSize",formdata->FM_DotSize);
				sr->WriteLine(str);
				str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","FM DotGap",formdata->FM_MiniDotGap);
				sr->WriteLine(str);




		//	}


		sr->Write(" }");
		sr->Write('\n');

		return true;
	}catch(...){
	
		MessageBox::Show("�ѼƦs�ɿ��~");
		return false;
	}



}





bool LoadLocalAreaPara(array<String^>^ FileData ,ArrayList^ Localsurfacedata){


	try{

		
		


		if(String::Compare((String^)FileData->GetValue(2),"1")== 0){
			
			//�������Ĥ@�� :					
			array<String^>^ splitdata =Convert::ToString(FileData->GetValue(3))->Split(',') ;	
			//�[��ArrayList
			Localsurfacedata->Add(splitdata);
			
		}
/*
		do{
			bool startRead = false;
			str = (String^)(sr->ReadLine())->Trim();
			if(String::Compare(str ,"{")  == 0){
				startRead = true;
				 str = (String^)(sr->ReadLine())->Trim();
			}
			if(startRead = true){
				array<String^>^ splitdata =str->Split(',') ;	
				//�[��ArrayList
				Localsurfacedata->Add(splitdata);
			}
		}while(String::Compare(str,"}",true) != 0) ;
*/

		return true;

	}catch(...){

		return false;

	}



}

bool LoadGlobalAreaPara(String^ version,StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design){

	try{

		String^ str = (String^)(sr->ReadLine())->Trim();
		if(String::Compare(str ,"{")  == 0) {

			str = (String^)(sr->ReadLine())->Trim();

			while(String::Compare(str,"}",true) != 0){
				
				array<String^>^ splitdata =str->Split(',') ;	
				//�[��Surface
				Surface_Global_Design->SaveSurfaceData(splitdata);
				str = (String^)(sr->ReadLine())->Trim();				
			}
		}

		return true;

	}catch(...){

		return false;

	}






};
bool LoadGlobalLinePara(String^ version,StreamReader ^ sr,B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve){

/*
		try{

		String^ str = (String^)sr->ReadLine();
		if(String::Compare(str ,"{")  == 0) {
			while(String::Compare(Convert::ToString(sr->ReadLine()),"}",true) != 0){
				
				String^ localdata = (String^)sr->ReadLine();	
				array<String^>^ splitdata =localdata->Split(' ') ;	
				//�[��Surface
				Surface_Global_Design->SaveSurfaceData(splitdata);
				
			}
		}

		return true;

	}catch(...){

		return false;

	}


*/

return false;

};

bool LoadLGPPara(String^ version,StreamReader ^ sr,array<String^>^ LGPPara){
	return false;
};
bool LoadProjInformation(String^ version,StreamReader ^ sr,Project_Information^ ProjInformation){
	try{
				

		
	







		
		//Ū�ɮɥH "{" ���_�l , �H "}" ������ 




	String^ str = (String^)sr->ReadLine();
	if(String::Compare(str->Trim(),"{")  == 0) {
		
		
		int read_data_number = -1;	
		str = (String^)(sr->ReadLine())->Trim();


		while(String::Compare(str,"}",true) != 0){
			

			array<String^>^ SepData;
				
		
			if(SepData != nullptr) Array::Clear(SepData,0,SepData->Length);			
			SepData = str->Split('	');
			read_data_number ++;
			switch (read_data_number){
				case 0 : // Ū���M�צW��
					if(SepData->Length != 1)
					   ProjInformation->projectName = Convert::ToString(SepData->GetValue(1));
					else
						ProjInformation->projectName = "";

					break;
				case 1: // Ū��Pattern����
					if(SepData->Length != 1)
						ProjInformation->PatternVersion = Convert::ToString(SepData->GetValue(1));					
					else
						ProjInformation->PatternVersion = "";

					break;
				case 2: // Ū�����`�o��
					ProjInformation->RegularInkProperty = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 3:// Ū���S��o��

					if(SepData->Length != 1)
						ProjInformation->SpecialInk = Convert::ToString(SepData->GetValue(1));
					else
						ProjInformation->SpecialInk = "";

					break;
				case 4:// Ū�������j�p
					ProjInformation->ScreenSize = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 5:// ����
					ProjInformation->MeshSize = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 6:// �ūp
					ProjInformation->Thick = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 7:// ���O����
					ProjInformation->ScreenAngle = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 8:// �]�p��
					if(SepData->Length != 1)
						ProjInformation->Designer = Convert::ToString(SepData->GetValue(1));
					else
						ProjInformation->Designer = "";

					break;
				case 9:// �]�p���
					if(SepData->Length != 1)
						ProjInformation->DesignDate = Convert::ToString(SepData->GetValue(1));
					else
						ProjInformation->DesignDate = "";
					break;
				case 10:// LGP�Ȥ�Ƹ�
					if(SepData->Length != 1)
						ProjInformation->LGP_PN_Number = Convert::ToString(SepData->GetValue(1));
					else
						ProjInformation->LGP_PN_Number = "";
					break;
				case 11:// ���~���A
					
						ProjInformation->ProductionStyle = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 12:// �s�y�a					
						ProjInformation->LGP_Manufacture = Convert::ToSingle(SepData->GetValue(1));
					break;
				
				case 13:// LGP����					
						ProjInformation->LGP_Material = Convert::ToSingle(SepData->GetValue(1));					
					break;



		
			
			}

			str = (String^)(sr->ReadLine())->Trim();
			
			
		}



			
		}
	



	

		return true;

	}catch(...){

		sr->Close();
		MessageBox::Show("Ū�����ظ�T���~");

		return false;

	}

};
bool LoadMainformPara(String^ version,StreamReader ^ sr,MainFormData^ formdata){

	try{

			//Ū�ɮɥH "{" ���_�l , �H "}" ������ 




	String^ str = (String^)sr->ReadLine();
	if(String::Compare(str->Trim(),"{")  == 0) {
		
		
		int read_data_number = -1;	
		str = (String^)(sr->ReadLine())->Trim();


		while(String::Compare(str,"}",true) != 0){
			

			array<String^>^ SepData;
				
		
			if(SepData != nullptr) Array::Clear(SepData,0,SepData->Length);			
			SepData = str->Split('	');
			read_data_number ++;
			switch (read_data_number){
				case 0 : // Ū���G�I�覡
					if((version == "1") || (version == "2"))	{
						bool randomDot = Convert::ToBoolean(SepData->GetValue(1));
						if(randomDot == true) formdata->DotType = 1;
						else formdata->DotType = 0;						
					}else if(version == "3"){
						formdata->DotType = Convert::ToInt16(SepData->GetValue(1));
					}
					break;
				case 1: // Ū��LGP�ؤo
					formdata->LGPInformation.Width = Convert::ToSingle(SepData->GetValue(1));
					formdata->LGPInformation.Height = Convert::ToSingle(SepData->GetValue(2));
					formdata->LGPInformation.X = 0;
					formdata->LGPInformation.Y = 0;
					break;
				case 2: // Ū���̤j���I
					formdata->MaxDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 3:// Ū���̤p���I
					formdata->MinDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 4:// �̤p���I����
					formdata->MinDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 5:// ���I�Ϊ�
					formdata->Pattern_Shape = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 6:// ���I�ƦC�覡
					formdata->Pattern_Arrangment = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 7:// �üƺ��I�j�p
					formdata->RandomDotSize = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 8:// ���I����Z��
					formdata->RandomDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 9:// �B�⦸��
					formdata->RandomDotIteration = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 10:// �B��k�h
					formdata->RandomDotSimRule = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 11:// �Ѽ�K
					formdata->Parameter_K = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 12:// �Ѽ�C
					formdata->Parameter_C = Convert::ToSingle(SepData->GetValue(1));
					break;
				//Updata  20091203--------------------------------------------------------
				case 13:// �K�׽վ�覡
					formdata->DensityDesignMethod = Convert::ToInt16(SepData->GetValue(1));	
					break;
				case 14: //�üƱ���(Force,�֨�����,�֨�Force)
					formdata->RandomStopForce = Convert::ToSingle(SepData->GetValue(1));
					formdata->chkStopNmber = Convert::ToBoolean(SepData->GetValue(2));
					formdata->chkStopForce = Convert::ToBoolean(SepData->GetValue(3));						
					break;
				case 15: //�ü� �����W�v
					formdata->RandomRebuildFrequency = Convert::ToInt16(SepData->GetValue(1));
					break;	
				//Update 20110815
				case 16: //Pitch Direction
					formdata->PitchDirection = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 17: //Actual Pitch
					formdata->ActualPitchValue = Convert::ToSingle(SepData->GetValue(1));
					break;
					//Update 20110907
				case 18:
					formdata->IJP_BlockX = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 19:
					formdata->IJP_BlockY = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 20 :
					formdata->IJP_DotSize = Convert::ToSingle(SepData->GetValue(1));
					break;

				//Update 20120319 IJP��r
				case 21 :
					formdata->IJP_chkTextEdit = Convert::ToBoolean(SepData->GetValue(1));
					break;
				case 22:
					formdata->IJP_TextLocation = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 23:
					formdata->IJP_TextLocation_X = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 24:
					formdata->IJP_TextLocation_Y = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 25:
					formdata->IJP_TextHeight = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 26:
					formdata->IJP_TextLength =Convert::ToSingle(SepData->GetValue(1));
					break;
				case 27:{
						if(SepData->Length::get() ==2) 
							formdata->IJP_Text = Convert::ToString(SepData->GetValue(1));
						else{
							formdata->IJP_Text = "";
						}
						break;
						}
				case 28:
					formdata->FM_DotSize = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 29:
					formdata->FM_MiniDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
																		
			}

			str = (String^)(sr->ReadLine())->Trim();
			
			
		}



			
		}
	



	

		return true;

	}
	catch(...){
		sr->Close();
		MessageBox::Show("Ū������ƿ��~");

		return false;
	}






};




//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------AutoCAD------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------

bool SavePatternFile(StreamWriter ^ sr,array<RectangleF>^ OutLine,int patternShape,Pattern^ dot,Cosmetic_Data^ cosmetic_Data){
		

	try{

		//Header ����




		// Table ���� (�D�n�O�]�w��r);

		sr->WriteLine("  0");
			sr->WriteLine("SECTION");
		sr->WriteLine("  2");
			sr->WriteLine("TABLES");
		sr->WriteLine(" 0");
			sr->WriteLine("TABLE");
		sr->WriteLine("  2");
			sr->WriteLine("STYLE");
		sr->WriteLine(" 70");
			sr->WriteLine("1");
		sr->WriteLine("  0");
			sr->WriteLine("STYLE");
		sr->WriteLine("  2");
			sr->WriteLine("STANDARD");
		sr->WriteLine(" 70");
			sr->WriteLine("0");
		sr->WriteLine(" 40");
			sr->WriteLine("0.0");
		sr->WriteLine(" 41");
			sr->WriteLine("1.0");
		sr->WriteLine(" 50");
			sr->WriteLine("0.0");
		sr->WriteLine(" 71");
			sr->WriteLine("0");
		sr->WriteLine(" 42");
			sr->WriteLine("2.5");
		sr->WriteLine("  3");
			sr->WriteLine("txt.shx");
		sr->WriteLine("  4");
			sr->WriteLine("chineset.shx");
		sr->WriteLine("  0");
			sr->WriteLine("ENDTAB");
		sr->WriteLine("  0");
			sr->WriteLine("ENDSEC");


		
		//Entities ����
		sr->WriteLine("  0"); 
		sr->WriteLine("SECTION");
		sr->WriteLine("  2");
		sr->WriteLine("ENTITIES");


		
		

			
			
		for(int i = 0 ;i< dot->GetDotNumber() ;i++){
			
				float diameter;
				PointF coordinate;
				dot->GetDotValue(coordinate,diameter,i);
				RectangleF block(coordinate.X-diameter/2,coordinate.Y-diameter/2,diameter,diameter);
				if (diameter > 0) {   //20121105 �s�W�P�O ,���|��0�����I���x�s
					if(patternShape == 0){ //���
						xSaveAutoCad_Circle(sr,coordinate,diameter,(float)dot->ModifyRate_LocalArea->GetValue(i));
					}else if(patternShape == 1){ //�����
						RectangleF recF(coordinate.X-diameter/2,coordinate.Y-diameter/2,diameter,diameter);
						xSaveAutoCad_Rectangle( sr ,recF);
					}
				}

												
		}




		/*

		for(int ii = 0 ;ii<cosmetic_Data->LocalArea_History_Data->GetLength(0) ; ii ++){
			float tmpX = OutLine.X + (float) cosmetic_Data->LocalArea_History_Data->GetValue(ii,1);
			float tmpY = OutLine.Y + (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,2);
			float Length = (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,3);
			float Width = (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,4);




			RectangleF tmpRecF(tmpX,tmpY,Length,Width);
			xSaveAutoCad_Rectangle( sr ,tmpRecF);

			
			//�}�C������---------------------------

			int arraynumber = Convert::ToInt16(cosmetic_Data->LocalArea_History_Data->GetValue(ii,33));
			for(int jj = 1 ;jj<arraynumber  ; jj ++){
				switch(Convert::ToInt16(cosmetic_Data->LocalArea_History_Data->GetValue(ii,32))){
					case 0  : //+X
						tmpX = tmpX + Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));

						break;
					case 1  : //-X
						tmpX = tmpX - Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
					case 2 : //+Y
						tmpY = tmpY + Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
					case 3 : //-Y
						tmpY = tmpY - Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
				}
				RectangleF tmpRecF(tmpX,tmpY,Length,Width);
				xSaveAutoCad_Rectangle( sr ,tmpRecF);
			}

			//--------------------------------------
			 
		}

		*/


		for(int ii = 0 ; ii <OutLine->LongLength ;ii++){
			xSaveAutoCad_Rectangle( sr ,OutLine[ii]);
		}

			
		sr->WriteLine("  0"); 
		sr->WriteLine("ENDSEC"); 
		sr->WriteLine("  0"); 
		sr->WriteLine("EOF"); 
		sr->Close();
		

		return true;
		}
		catch(...){
			sr->Close();
			MessageBox::Show("DxfPattern�s�ɿ��~");
			return false;

		}




}

bool SavePatternFile(StreamWriter ^ sr,MainFormData^ formdata,Pattern^ dot,Cosmetic_Data^ cosmetic_Data,Project_Information^ project){
	

	try{

		//Header ����
		/*
		sr->WriteLine("  0"); 
		sr->WriteLine("SECTION");
		sr->WriteLine("  2");
		sr->WriteLine("HEADER");
		sr->WriteLine(" 9");
		sr->WriteLine("$TEXTSIZE");
		sr->WriteLine(" 40");
		sr->WriteLine("2.5");
		sr->WriteLine(" 9");
		sr->WriteLine("$TEXTSTYLE");
		sr->WriteLine("	7");
		sr->WriteLine("	Standard");
		sr->WriteLine("  0"); 
		sr->WriteLine("ENDSEC"); 
		*/



		// Table ���� (�D�n�O�]�w��r);

		sr->WriteLine("  0");
			sr->WriteLine("SECTION");
		sr->WriteLine("  2");
			sr->WriteLine("TABLES");
		sr->WriteLine(" 0");
			sr->WriteLine("TABLE");
		sr->WriteLine("  2");
			sr->WriteLine("STYLE");
		sr->WriteLine(" 70");
			sr->WriteLine("1");
		sr->WriteLine("  0");
			sr->WriteLine("STYLE");
		sr->WriteLine("  2");
			sr->WriteLine("STANDARD");
		sr->WriteLine(" 70");
			sr->WriteLine("0");
		sr->WriteLine(" 40");
			sr->WriteLine("0.0");
		sr->WriteLine(" 41");
			sr->WriteLine("1.0");
		sr->WriteLine(" 50");
			sr->WriteLine("0.0");
		sr->WriteLine(" 71");
			sr->WriteLine("0");
		sr->WriteLine(" 42");
			sr->WriteLine("2.5");
		sr->WriteLine("  3");
			sr->WriteLine("txt.shx");
		sr->WriteLine("  4");
			sr->WriteLine("chineset.shx");
		sr->WriteLine("  0");
			sr->WriteLine("ENDTAB");
		sr->WriteLine("  0");
			sr->WriteLine("ENDSEC");


		
		//Entities ����
		sr->WriteLine("  0"); 
		sr->WriteLine("SECTION");
		sr->WriteLine("  2");
		sr->WriteLine("ENTITIES");


		
		
		if (formdata->Pattern_Shape == 0) {
			//���
			
			for(int i = 0 ;i< dot->GetDotNumber() ;i++){
				
					float diameter;
					PointF coordinate;

					dot->GetDotValue(coordinate,diameter,i);
				//	if(diameter > 0.0f && coordinate.X > diameter/2 && coordinate.X < formdata->LGPDimension.X- diameter/2 && coordinate.Y > diameter/2 && coordinate.Y < formdata->LGPDimension.Y - diameter/2  ) {
					if(diameter*(float)dot->ModifyRate_LocalArea->GetValue(i) > 0.0f && coordinate.X > formdata->LGPInformation.X + diameter/2 && coordinate.X < formdata->LGPInformation.X + formdata->LGPInformation.Width- diameter/2 && coordinate.Y > formdata->LGPInformation.Y + diameter/2 && coordinate.Y < formdata->LGPInformation.Y + formdata->LGPInformation.Height - diameter/2  ) {

							sr->WriteLine("  0");
							sr->WriteLine("CIRCLE");
							sr->WriteLine("  8");
							sr->WriteLine("0");
							float tmpRation = 1.0f;
						//	if(fabs((float)dot->ModifyRate_HotSpot->GetValue(i) - 1.0f)*diameter > 0.0001f && fabs((float)dot->ModifyRate_LocalArea->GetValue(i)-1.0f)*diameter > 0.0001f ){
						//		sr->WriteLine(" 62");
						//		sr->WriteLine("6");
						//	}else if(fabs((float)dot->ModifyRate_LocalArea->GetValue(i)-1.0f)*diameter > 0.0001f ){
						//		sr->WriteLine(" 62");
						//		sr->WriteLine("5");
						//	}else if(fabs((float)dot->ModifyRate_HotSpot->GetValue(i) - 1.0f)*diameter > 0.0001f){
						//		sr->WriteLine(" 62");
						//		sr->WriteLine("4");
						//	};
							if(fabs((float)dot->ModifyRate_LocalArea->GetValue(i)-1.0f)*diameter > 0.0001f ){
								sr->WriteLine(" 62");
								sr->WriteLine("5");
							}



							sr->WriteLine(" 10");
							sr->WriteLine(Convert::ToString(coordinate.X));
							
							sr->WriteLine(" 20");
						
						//	sr->WriteLine(Convert::ToString(2*formdata->LGPInformation.Y + formdata->LGPInformation.Height -coordinate.Y));
							sr->WriteLine(Convert::ToString(coordinate.Y));
							
							sr->WriteLine(" 30");
							sr->WriteLine("0");
							sr->WriteLine(" 40");
							sr->WriteLine(Convert::ToString(diameter/2*(float)dot->ModifyRate_LocalArea->GetValue(i)));

					}
					
				
			}
		}else if(formdata->Pattern_Shape == 1) {
			for(int i = 0 ;i< dot->GetDotNumber() ;i++){
				float length;
				PointF coordinate;
				dot->GetDotValue(coordinate,length,i);
			//	if(length > 0.0f && coordinate.X > length/2 && coordinate.X < formdata->LGPDimension.X- length/2 && coordinate.Y > length/2 && coordinate.Y < formdata->LGPDimension.Y - length/2  ) {
				if(length > 0.0f && coordinate.X > length/2 && coordinate.X < formdata->LGPInformation.Width- length/2 && coordinate.Y > length/2 && coordinate.Y < formdata->LGPInformation.Height - length/2  ) {

					RectangleF recF(coordinate.X,coordinate.Y,length,length);
				//	RectangleF recF(coordinate.X,formdata->LGPInformation.Height-coordinate.Y,length,length);
					xSaveAutoCad_Rectangle( sr ,recF);
				}
			}

		}




		for(int ii = 0 ;ii<cosmetic_Data->LocalArea_History_Data->GetLength(0) ; ii ++){
			float tmpX = formdata->LGPInformation.X + (float) cosmetic_Data->LocalArea_History_Data->GetValue(ii,1);
			float tmpY = formdata->LGPInformation.Y + (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,2);
			float Length = (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,3);
			float Width = (float)cosmetic_Data->LocalArea_History_Data->GetValue(ii,4);

		//	this->Current_InputData->SetValue(0,32); //�}�C��V
		//	this->Current_InputData->SetValue(1,33); //�}�C�ƥ�
		//	this->Current_InputData->SetValue(0,34); //�}�C���Z


			RectangleF tmpRecF(tmpX,tmpY,Length,Width);
			xSaveAutoCad_Rectangle( sr ,tmpRecF);

			
			//�}�C������---------------------------

			int arraynumber = Convert::ToInt16(cosmetic_Data->LocalArea_History_Data->GetValue(ii,33));
			for(int jj = 1 ;jj<arraynumber  ; jj ++){
				switch(Convert::ToInt16(cosmetic_Data->LocalArea_History_Data->GetValue(ii,32))){
					case 0  : //+X
						tmpX = tmpX + Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));

						break;
					case 1  : //-X
						tmpX = tmpX - Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
					case 2 : //+Y
						tmpY = tmpY + Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
					case 3 : //-Y
						tmpY = tmpY - Convert::ToSingle(cosmetic_Data->LocalArea_History_Data->GetValue(ii,34));
						break;
				}
				RectangleF tmpRecF(tmpX,tmpY,Length,Width);
				xSaveAutoCad_Rectangle( sr ,tmpRecF);
			}

			//--------------------------------------
			 
		}

	//	RectangleF BRecF(0,0,formdata->LGPDimension.X,formdata->LGPDimension.Y);		
	//	xSaveAutoCad_Rectangle( sr ,BRecF);
		xSaveAutoCad_Rectangle( sr ,formdata->LGPInformation);

		
	
		
		
	
		                      


		//���O��T .�o����T:
		String^ MeshSize;
		String^ Screen;
		String^ InkType;

		switch (project->ScreenSize){
			case 0:
				Screen = "1500 X 1800 ";
				break;
			case 1:
				Screen = "1300 X 1500 ";
				break;
			case 2:
				Screen = "1100 X 1300 ";
				break;
			case 3:
				Screen = "1300 X 1800 ";
				break;
			case 4:
				Screen = "900 X 1050 ";
				break;
			case 5:
				Screen = "800 X 800 ";
				break;

		}

		switch (project->MeshSize){
			case 0:
				MeshSize = "NBC 305S#";
				break;
			case 1:
				MeshSize = "NBC 315T#";
				break;
			case 2:
				MeshSize = "NBC 315S#";
				break;
			case 3:
				MeshSize = "NBC 420S#";
				break;

		}

		switch (project->RegularInkProperty){
			case 0:
				InkType = project->SpecialInk;
				break;
			case 1:
				InkType = "CLCD-B20-25";
				break;
			case 2:
				InkType = "CLCD-B20-20";
				break;
			case 3:
				InkType = "CLCD-B20-15";
				break;
			case 4:
				InkType = "CLCD-B20-10";
				break;
			case 5:
				InkType = "H(80:20)Ink";
				break;
			case 6:
				InkType = "G(70:30)Ink";
				break;
			case 7:
				InkType = "E(60:40)Ink";
				break;
			case 8:
				InkType = "C-Pius-I80(50:50-I80)";
				break;
			case 9:
				InkType = "C-Pius-I80(40:60-I80)";
				break;
			
		}


		PointF TextLocation(0,0);

		//��s�]�p���
		project->DesignDate = Convert::ToString(System::DateTime::Now::get());


		//------------------------------------------------------------------------------------------------------------------------------------------
		//���� ---Show�b LGP �W����~~
		String^ CustomerCode;
		String^ CLOCode;


		//Temp 
		String^ LGP_Material;
		String^ LGP_ManufactureLocation;

		String^ CLO_M;
		String^ CLO_P; 

	

		switch (project->LGP_Material){
			case 0:
				LGP_Material = "PMMA";
				break;
			case 1:
				LGP_Material = "LNX865";
				break;
		}

		switch (project->LGP_Manufacture){
			case 0:   //TW
				LGP_ManufactureLocation = "B484";
				CLO_M = "L";
				break;
			case 1:  // LC
				LGP_ManufactureLocation = "CLO-LC";
				CLO_M = "C";
				break;
			case 2: //LMO
				LGP_ManufactureLocation = "A732";
				CLO_M = "M";
				break;
		}


		//�Ȥ�n�D���s�X

		if(project->ProductionStyle == 0) {//BLU�X�f
			CLO_P = "B";
			CustomerCode = project->projectName  + ">" + LGP_Material + "<" + LGP_ManufactureLocation + "-" + project->PatternVersion ;
		}else  {//LGP ����
			CLO_P = "L";
			CustomerCode = project->LGP_PN_Number + ">" + LGP_Material + "<" + LGP_ManufactureLocation + "-" + project->PatternVersion ;
		}



		//�Ȥ�s�X 
		TextLocation.X = formdata->LGPInformation.X + formdata->LGPInformation.Width;
		TextLocation.Y = formdata->LGPInformation.Y + formdata->LGPInformation.Height-2;

		xSaveAutoCad_Mtext(sr,CustomerCode ,TextLocation ,1.5,true);


		//CLO�ۤv���s�X 
		DateTime establishTime;
		establishTime = DateTime::Now::get();
		int year = establishTime.Year;
		int month = establishTime.Month;
		int day = establishTime.Day;

		

		//*
		array<wchar_t>^ spchar = {'/',' '};  
		array<String^>^ date = Convert::ToString(DateTime::Now::get())->Split(spchar);
		
		array<wchar_t>^ DateCode = gcnew array<wchar_t>(3);
	
		//DateCode[0] = date[0]->default[3];
		DateCode[0] = Convert::ToString(establishTime.Year)->default[3];

		//int month ;
		//month = Convert::ToInt64(date[1]);
	
		if( month <=9 ){			
			DateCode[1] = Convert::ToChar(Convert::ToString(month));
		}else{
			DateCode[1] = Convert::ToChar(month+55);
		}

		//int day ;
		//day = Convert::ToInt64(date[2]);

		if( day <=9 ){			
			DateCode[2] = Convert::ToChar(Convert::ToString(day));
		}else if(day >9 && day <= 17){
			DateCode[2] = Convert::ToChar(day+55);
		}else if(day >17 && day <= 22){
			DateCode[2] = Convert::ToChar(day+56);
		}else{
			DateCode[2] = Convert::ToChar(day+57);
		}

		//*/


		CLOCode = project->projectName  + "-" +  project->PatternVersion + "-" + CLO_P + "-" +Convert::ToString(DateCode[0])+Convert::ToString(DateCode[1])+Convert::ToString(DateCode[2]) + "-" + CLO_M ;
		

		//CLO�ۤv���s�X  
		TextLocation.X = formdata->LGPInformation.X + formdata->LGPInformation.Width;
		TextLocation.Y = 0.5;
		xSaveAutoCad_Mtext(sr,CLOCode ,TextLocation ,1.5,true);



		//------------------------------------------------------------------------------------------------------------------------------------------------

				

		TextLocation.X = formdata->LGPInformation.X + formdata->LGPInformation.Width/2.5f;
		TextLocation.Y = formdata->LGPInformation.Y - formdata->LGPInformation.Height/5.0f;

		


		//�N�M�׸�T�g�JAutoCad ��
		xSaveAutoCad_Mtext(sr,"���ئW��     : " + project->projectName ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"���I����     : " + CLOCode ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"�]�p���     : " + project->DesignDate ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"�]�p��      : " + project->Designer ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"���O�j�p     : " + Screen,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"���ؼ�      : " + MeshSize ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"���O�ūp     : " + Convert::ToString(project->Thick) ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"���O����     : " + Convert::ToString(project->ScreenAngle) ,TextLocation,5,false);
		TextLocation.Y = TextLocation.Y - 6;
		xSaveAutoCad_Mtext(sr,"�o������     : " + InkType ,TextLocation,5,false);
	



		
		
		
		

		sr->WriteLine("  0"); 
		sr->WriteLine("ENDSEC"); 
		sr->WriteLine("  0"); 
		sr->WriteLine("EOF"); 
		sr->Close();
		

		return true;
		}
		catch(...){
			sr->Close();
			MessageBox::Show("DxfPattern�s�ɿ��~");
			return false;

		}


}
void xSaveAutoCad_Mtext(StreamWriter ^ sr ,String^ TextContent,PointF Location ,float TextSize ,bool reverseText){



	String^ reverse = "0";
	if(reverseText == true) reverse = "2"; //���k�A�ˬ�2 


	sr->WriteLine("0");
		sr->WriteLine("TEXT");
	sr->WriteLine( "8");
		sr->WriteLine("0");
	sr->WriteLine("10");
		sr->WriteLine(Convert::ToString(Location.X));
	sr->WriteLine("20");
		sr->WriteLine(Convert::ToString(Location.Y));
	sr->WriteLine("30");
		sr->WriteLine("0.0");
	sr->WriteLine("40");
		sr->WriteLine(Convert::ToString(TextSize));
	sr->WriteLine("71");		 
		sr->WriteLine(reverse);
	sr->WriteLine("1");
	sr->WriteLine(TextContent);
	
	
}
void xSaveAutoCad_Rectangle(StreamWriter ^ sr ,RectangleF^ recF){


	String^ str = nullptr;

	sr->WriteLine("  0");
	sr->WriteLine("POLYLINE");
	//sr->WriteLine("5");
	//sr->WriteLine("F8"); 
	sr->WriteLine("  8");
	sr->WriteLine("0");
	sr->WriteLine(" 62");
	sr->WriteLine("3");
	sr->WriteLine(" 66");
	sr->WriteLine("1");
	sr->WriteLine (" 10");
	sr->WriteLine("0"); 
	sr->WriteLine(" 20");
	sr->WriteLine("0");
	sr->WriteLine (" 30");
	sr->WriteLine("0");
	sr->WriteLine(" 70");
	sr->WriteLine ("1");
	sr->WriteLine ("  0");
	sr->WriteLine("VERTEX");
	//sr->WriteLine("5");
	//sr->WriteLine("109");
	sr->WriteLine("  8");
	sr->WriteLine("0");
	sr->WriteLine(" 10");
	
	

	str = Convert::ToString(recF->Location.X);
	sr->WriteLine(str);

	sr->WriteLine(" 20");

	
	str = Convert::ToString(recF->Location.Y);
	sr->WriteLine(str);

	sr->WriteLine(" 30");
	sr->WriteLine ("0.0");
	sr->WriteLine ( "  0");
	sr->WriteLine("VERTEX");
	//sr->WriteLine("5");
	//sr->WriteLine("10A");
	sr->WriteLine("  8");
	sr->WriteLine("0");
	sr->WriteLine(" 10");

	
	str = Convert::ToString(recF->Right);
	sr->WriteLine(str);

	sr->WriteLine(" 20");

	
	str = Convert::ToString(recF->Location.Y);
	sr->WriteLine(str);

	sr->WriteLine(" 30");
	sr->WriteLine("0.0");
	sr->WriteLine("  0");
	sr->WriteLine("VERTEX");
	//sr->WriteLine("5");
	//sr->WriteLine("10B");
	sr->WriteLine("  8");
	sr->WriteLine("0");
	sr->WriteLine(" 10");

	
	str = Convert::ToString(recF->Right);
	sr->WriteLine(str);

    sr->WriteLine(" 20");

	
	str = Convert::ToString(recF->Bottom);
	sr->WriteLine(str);

	sr->WriteLine(" 30");
	sr->WriteLine("0.0");
	sr->WriteLine("  0");
	sr->WriteLine("VERTEX");
	//sr->WriteLine("5");
	//sr->WriteLine("10C");
	sr->WriteLine("  8");
	sr->WriteLine("0");
	sr->WriteLine(" 10");

	
	str = Convert::ToString(recF->Location.X);
	sr->WriteLine(str);

	sr->WriteLine(" 20");

	
	str =Convert::ToString( recF->Bottom);
	sr->WriteLine(str);

	sr->WriteLine(" 30");
	sr->WriteLine("0.0");
	sr->WriteLine ("  0");
	sr->WriteLine("SEQEND");
	//sr->WriteLine("5");
	//sr->WriteLine("158");
	sr->WriteLine("  8");
	sr->WriteLine("0");

}
void xSaveAutoCad_Circle(StreamWriter ^ sr ,PointF Coor,float dia,float increaseRatio){
		
		
		

		sr->WriteLine("  0");
		sr->WriteLine("CIRCLE");
		sr->WriteLine("  8");
		sr->WriteLine("0");
		float tmpRation = 1.0f;

		// ����C��
		if((increaseRatio-1.0f)*dia > 0.0001f ){
			sr->WriteLine(" 62");
			sr->WriteLine("5");
		}else if((increaseRatio-1.0f)*dia < -0.0001f){
			sr->WriteLine(" 62");
			sr->WriteLine("6");
		}



		sr->WriteLine(" 10");
		sr->WriteLine(Convert::ToString(Coor.X));
		
		sr->WriteLine(" 20");						
		sr->WriteLine(Convert::ToString(Coor.Y));
		
		sr->WriteLine(" 30");
		sr->WriteLine("0");
		sr->WriteLine(" 40");
		sr->WriteLine(Convert::ToString(dia/2*increaseRatio));

		

}

bool xOpenAutoCad_Rectangle_NonR12(StreamReader ^ sr ,RectangleF^ LGP_Dimension,int readIndex){
	try{

		List<PointF>^ tmpListPt = gcnew List<PointF>(0);	
		List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;	
		PointF tmpPt(0,0);
		
		bool In_X = false , In_Y = false ;
	


			
			
			String^ str ;
		//	String^ buffer;	

//		while(count < 4 || readIndex == 2 ){
		while(count < 4 ){

			str = sr->ReadLine();

//			if (str->CompareTo("CIRCLE") == 0){
//				readIndex = 0;
//			}else if (str->CompareTo("POLYLINE") == 0){
//				readIndex = 1;
//				
//			}else if (str->CompareTo("AcDbPolyline") == 0){
//				readIndex = 2;
//			}

				
			if(str->CompareTo(" 10") == 0 ){
				str = sr->ReadLine();   //X				
				tmpPt.X = Convert::ToSingle(str);	
				In_X = true;
			}
				
			if(str->CompareTo(" 20") == 0){
				str = sr->ReadLine();   //Y
				tmpPt.Y = Convert::ToSingle(str);	
				In_Y = true;
			};

			if ( In_X == true &&  In_Y  ==true) {
					tmpListPt->Add(tmpPt);												
					In_X = false , In_Y = false ;
					count ++; 
			};

		}

	

		if(tmpListPt->Count > 0){

			PointF tmpPt = tmpListPt[0];
			PointF MaxPt = tmpListPt[0];
			PointF MinPt = tmpListPt[0];

			for(int ii = 0 ; ii < tmpListPt->Count ; ii++){
				tmpPt = tmpListPt[ii];
				MaxPt.X = Math::Max(tmpPt.X ,MaxPt.X);
				MaxPt.Y = Math::Max(tmpPt.Y ,MaxPt.Y);
				MinPt.X = Math::Min(tmpPt.X ,MinPt.X);
				MinPt.Y = Math::Min(tmpPt.Y ,MinPt.Y);
			}

				LGP_Dimension->X = MinPt.X ;
				LGP_Dimension->Y = MinPt.Y ;
				LGP_Dimension->Width = MaxPt.X - MinPt.X ;
				LGP_Dimension->Height= MaxPt.Y - MinPt.Y ;

			

			return true;
		}
			


		MessageBox::Show("Ū������LGP�~���ؤo��T !!!");

		return false;
		
	}catch(...){
		return false;
	}





	


}
bool xOpenAutoCad_PolyLine(StreamReader ^ sr ,List<PointF>^ PolyLinePt){

		try{

	
	//	List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;	
		PointF tmpPt(0,0);
		

		bool In_X = false , In_Y = false ;
	
		bool readdataVertex = false;


			
			
			String^ str ;
			str = sr->ReadLine();
		//	String^ buffer;	

		while( str->Trim() != "SEQEND" ){

			str = sr->ReadLine();
			if (str->Trim() == "VERTEX"){
				readdataVertex = true;
			}
				
			if(str->Trim() == "10"  && readdataVertex == true ){
				str = sr->ReadLine();   //X				
				tmpPt.X = Convert::ToSingle(str);	
				In_X = true;
			}
				
			if(str->Trim() == "20" && readdataVertex == true){
				str = sr->ReadLine();   //Y
				tmpPt.Y = Convert::ToSingle(str);	
				In_Y = true;
			};

			if ( In_X == true &&  In_Y  ==true) {
					PolyLinePt->Add(tmpPt);								
					readdataVertex = false;
					In_X = false , In_Y = false ;
					count ++; 
			};

		}

	

		if(PolyLinePt->Count > 0){			
			return true;
		}else{		
			MessageBox::Show("Ū������PolyLine��T !!!");
			return false;
		}
		
	}catch(...){
		return false;
	}


}
bool xOpenAutoCad_Rectangle(StreamReader ^ sr ,RectangleF^ LGP_Dimension){

		try{

		List<PointF>^ tmpListPt = gcnew List<PointF>(0);	
		List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;	
		PointF tmpPt(0,0);
		

		bool In_X = false , In_Y = false ;
	
		bool readdataVertex = false;


			
			
			String^ str ;
		//	String^ buffer;	

		while(count < 4 || str->Trim() != "SEQEND" ){

			str = sr->ReadLine();
			if (str->Trim() == "VERTEX"){
				readdataVertex = true;
			}
				
			if(str->Trim() == "10"  && readdataVertex == true ){
				str = sr->ReadLine();   //X				
				tmpPt.X = Convert::ToSingle(str);	
				In_X = true;
			}
				
			if(str->Trim() == "20" && readdataVertex == true){
				str = sr->ReadLine();   //Y
				tmpPt.Y = Convert::ToSingle(str);	
				In_Y = true;
			};

			if ( In_X == true &&  In_Y  ==true) {
					tmpListPt->Add(tmpPt);								
					readdataVertex = false;
					In_X = false , In_Y = false ;
					count ++; 
			};

		}

	

		if(tmpListPt->Count > 0){

			PointF tmpPt = tmpListPt[0];
			PointF MaxPt = tmpListPt[0];
			PointF MinPt = tmpListPt[0];

			for(int ii = 0 ; ii < tmpListPt->Count ; ii++){
				tmpPt = tmpListPt[ii];
				MaxPt.X = Math::Max(tmpPt.X ,MaxPt.X);
				MaxPt.Y = Math::Max(tmpPt.Y ,MaxPt.Y);
				MinPt.X = Math::Min(tmpPt.X ,MinPt.X);
				MinPt.Y = Math::Min(tmpPt.Y ,MinPt.Y);
			}

				LGP_Dimension->X = MinPt.X ;
				LGP_Dimension->Y = MinPt.Y ;
				LGP_Dimension->Width = MaxPt.X - MinPt.X ;
				LGP_Dimension->Height= MaxPt.Y - MinPt.Y ;

			

			return true;
		}
			


		MessageBox::Show("Ū������LGP�~���ؤo��T !!!");

		return false;
		
	}catch(...){
		return false;
	}





	





}
bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot,RectangleF^ LGP_Dimension){

	try{

		List<PointF>^ tmpListPt = gcnew List<PointF>(0);	
		List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;
		int LGPCount = 0;
		PointF tmpPt(0,0);
		float tmpRadius = 0;

		bool In_X = false , In_Y = false ,In_Raduis = false;
		bool readLGP = false;

		int readIndex = -1;  // 0���Ū�� Circle ���  , 1���Ū�� R12 ���x�θ�� , 2���Ū�� �DR12���x�θ��
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show("�O�_Ū��LGP��T ? ��LGP��T�����H�x�Ϊ��!!" ,"Ū��LGP",MessageBoxButtons::YesNo);
		if ( result == ::DialogResult::Yes ){
			readLGP = true;
		}else{
			readLGP = false;
			
		}




		while(sr->EndOfStream != true){
			
			
			String^ str ;
					
			str = sr->ReadLine();
			if (str->CompareTo("CIRCLE") == 0){
				readIndex = 0;
			}else if (str->CompareTo("POLYLINE") == 0){
				readIndex = 1;
				
			}else if (str->CompareTo("AcDbPolyline") == 0){
				readIndex = 2;
			}

			if(readIndex == 0){	
				if(str->CompareTo(" 10") == 0){
					str = sr->ReadLine();   //X				
					tmpPt.X = Convert::ToSingle(str);	
					In_X = true;
				}
					
				if(str->CompareTo(" 20") == 0){
					str = sr->ReadLine();   //Y
					tmpPt.Y = Convert::ToSingle(str);	
					In_Y = true;
				};
				if(str->CompareTo(" 40") == 0){
					str = sr->ReadLine();   //Radius		
					tmpRadius = Convert::ToSingle(str);
					In_Raduis = true;
				};
				if ( In_X == true && In_Y == true && In_Raduis ==true) {
						tmpListPt->Add(tmpPt);			
						tmpListRadius->Add(tmpRadius);	
						readIndex = -1;
						In_X = false , In_Y = false ,In_Raduis = false;
				};
			}else if(readIndex == 1 && readLGP == true){
				xOpenAutoCad_Rectangle(sr,LGP_Dimension);
				LGPCount ++ ;
				readIndex = -1;
				
			}else if(readIndex == 2 && readLGP == true){
				xOpenAutoCad_Rectangle_NonR12(sr,LGP_Dimension,readIndex);
				LGPCount ++ ;
				readIndex = -1;

			}


			
			

		}
		
		if(LGPCount > 1){
			MessageBox::Show("Ū�����x��LGP��T�W�L�@�� ,�|�����~����!!! ");
		}else if(readLGP == true && LGPCount == 0 ){
			MessageBox::Show("Ū����x��LGP��T!!! ");
		}
			

	
		
		Dot->BuildPattern(tmpListPt->Count);
		for (int i= 0 ; i < tmpListPt->Count ; i++){
			//�y���ഫ
			PointF tmppt(tmpListPt->default[i].X , 2*LGP_Dimension->Y + LGP_Dimension->Height -tmpListPt->default[i].Y);	
			tmpListPt->default[i] = tmppt ;
			Dot->SetDotValue(tmpListPt->default[i],2*tmpListRadius->default[i],i);
			
		};







		return true;
	}catch(...){
		return false;
	}













}
bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot){

	try{

		List<PointF>^ tmpListPt = gcnew List<PointF>(0);	
		List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;	
		PointF tmpPt(0,0);
		float tmpRadius = 0;

		bool In_X = false , In_Y = false ,In_Raduis = false;
		bool readdata = false;

		while(sr->EndOfStream != true){
			
			
			String^ str ;
				
			str = sr->ReadLine();
			if (str->Trim() == "CIRCLE"){
				readdata = true;
			}

				
			if(str->CompareTo(" 10") == 0 && readdata == true){
				str = sr->ReadLine();   //X				
				tmpPt.X = Convert::ToSingle(str);	
				In_X = true;
			}
				
			if(str->Trim() == "20" && readdata == true){
				str = sr->ReadLine();   //Y
				tmpPt.Y = Convert::ToSingle(str);	
				In_Y = true;
			};
			if(str->Trim() == "40" && readdata == true ){
				str = sr->ReadLine();   //Radius		
				tmpRadius = Convert::ToSingle(str);
				In_Raduis = true;
			};
			if ( In_X == true && In_Y == true &&  In_Raduis ==true) {
					tmpListPt->Add(tmpPt);			
					tmpListRadius->Add(tmpRadius);	
					readdata = false;
					In_X = false , In_Y = false ,In_Raduis = false;
			};

			

		}
			

		Dot->BuildPattern(tmpListPt->Count);
		for (int i= 0 ; i < tmpListPt->Count ; i++){
			Dot->SetDotValue(tmpListPt->default[i],2*tmpListRadius->default[i],i);
		};

		return true;
	}catch(...){
		return false;
	}



}

bool OpenPatternFile(StreamReader ^ sr,Pattern^ Dot,PointF^ Pitch,RectangleF^ LGP){

	try{

		List<PointF>^ tmpListPt = gcnew List<PointF>(0);	
		List<float>^ tmpListRadius = gcnew List<float>(0) ;	

		int count = 0;	
		PointF tmpPt(0,0);
		float tmpRadius = 0;

		bool In_X = false , In_Y = false ,In_Raduis = false;
		bool readdata = false;

		//���Pitch �MLGP ��T�Ϊ� ...

		float maxX= -10000 ,maxY = -10000;
	    Pitch->X = 10000 ;
		Pitch->Y = 10000;
		float maxRadius = 0;
		LGP->X = 10000; LGP->Y = 10000;
		
		//

		while(sr->EndOfStream != true){
			
			
			String^ str ;
						
			str = sr->ReadLine();
			if (str->CompareTo("CIRCLE") == 0){
				readdata = true ;
			}

			if(readdata == true) {

				if(str->CompareTo(" 10") == 0){
					str = sr->ReadLine();   //X				
					tmpPt.X = Convert::ToSingle(str);	
					In_X = true;
					//��LGP ��T
					if(tmpPt.X < LGP->X) LGP->X = tmpPt.X;
					if(tmpPt.X > maxX) maxX = tmpPt.X;
				}
					
				if(str->CompareTo(" 20") == 0){
					str = sr->ReadLine();   //Y
					tmpPt.Y = Convert::ToSingle(str);	
					In_Y = true;
					//��LGP ��T
					if(tmpPt.Y < LGP->Y) LGP->Y = tmpPt.Y;				
					if(tmpPt.Y > maxY) maxY = tmpPt.Y;
				};
				if(str->CompareTo(" 40") == 0){
					str = sr->ReadLine();   //Radius		
					tmpRadius = Convert::ToSingle(str);
					In_Raduis = true;
				};
				if ( In_X == true && In_Y == true && In_Raduis ==true) {
						tmpListPt->Add(tmpPt);			
						tmpListRadius->Add(tmpRadius);	
						In_X = false , In_Y = false ,In_Raduis = false;
						readdata = false;
				};
				

				
				
				//��Radio��T
				if(tmpRadius > maxRadius) maxRadius = tmpRadius;
				


			}


			
			

		

		}

		// �]�w LGP Information 
		LGP->Width = maxX - LGP->X +maxRadius ;
		LGP->Height = maxY - LGP->Y+maxRadius ;
	//	if((tmpPt.X-LGP->X) > maxRadius && (tmpPt.X-LGP->X) < pitchX) pitchX = tmpPt.X-LGP->X;
	//	if((tmpPt.Y-LGP->Y) > maxRadius && (tmpPt.Y-LGP->Y) < pitchY) pitchY = tmpPt.Y-LGP->Y;
	//	Pitch->X = 2*pitchX;
	//	Pitch->Y = 2*pitchY;




		Dot->BuildPattern(tmpListPt->Count);
		for (int i= 0 ; i < tmpListPt->Count ; i++){
			Dot->SetDotValue(tmpListPt->default[i],2*tmpListRadius->default[i],i);

			//���Pitch : X
			float tmpPitchX = Math::Abs(tmpListPt->default[i].X - tmpListPt->default[0].X);
			if(tmpPitchX >= 2*maxRadius && tmpPitchX < Pitch->X){
				Pitch->X = tmpPitchX;
			};
			//���Pitch : Y 
			float tmpPitchY = Math::Abs(tmpListPt->default[i].Y - tmpListPt->default[0].Y);
			if(tmpPitchY >= 2*maxRadius && tmpPitchY < Pitch->Y){
				Pitch->Y = tmpPitchY;
			};


			
		};

		return true;
	}catch(...){
		return false;
	}



}


//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------LT ------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------


bool SaveLTPatternFile(StreamWriter ^ sr,Pattern^ dot,MainFormData^ formdata,SettingData^ x_SetData){
	try{

		PointF pt_coor(0,0);
		float tmp_dotDia = 0;

		String^ str;
		str = "# LightTools 5.2.0 ";
		sr->WriteLine(str);
		str = "# Texture Placement/Parameter Export file";
		sr->WriteLine(str);

		switch(x_SetData->LTPattern_Style){
		case 0:
			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}", "X","Y" ,"Radius");
			sr->WriteLine(str);
			
			for(int ii = 0 ;ii < dot->GetDotNumber();ii++){
				dot->GetDotValue(pt_coor,tmp_dotDia,ii);
			//	if(tmp_dotDia > 0 && pt_coor.X > tmp_dotDia/2 && pt_coor.X < formdata->LGPDimension.X-tmp_dotDia/2 && pt_coor.Y > tmp_dotDia/2 && pt_coor.Y < formdata->LGPDimension.Y - tmp_dotDia/2){
				if(tmp_dotDia > 0 && pt_coor.X > tmp_dotDia/2 && pt_coor.X < formdata->LGPInformation.Width-tmp_dotDia/2 && pt_coor.Y > tmp_dotDia/2 && pt_coor.Y < formdata->LGPInformation.Height - tmp_dotDia/2){
					str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}", pt_coor.X + x_SetData->X_direction_Shift,pt_coor.Y + x_SetData->Y_direction_Shift, tmp_dotDia/2);
					sr->WriteLine(str);
				}
			}

			break;
		case 1:

			str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}"+"	"+"{3:#0.00##}", "X","Y","MaximumHeight","Radius");
			sr->WriteLine(str);

			for(int ii = 0 ;ii < dot->GetDotNumber();ii++){
				dot->GetDotValue(pt_coor,tmp_dotDia,ii);
			//	if(tmp_dotDia > 0 && pt_coor.X > tmp_dotDia/2 && pt_coor.X < formdata->LGPDimension.X-tmp_dotDia/2 && pt_coor.Y > tmp_dotDia/2 && pt_coor.Y < formdata->LGPDimension.Y - tmp_dotDia/2){
				if(tmp_dotDia > 0 && pt_coor.X > tmp_dotDia/2 && pt_coor.X < formdata->LGPInformation.Width-tmp_dotDia/2 && pt_coor.Y > tmp_dotDia/2 && pt_coor.Y < formdata->LGPInformation.Height - tmp_dotDia/2){
					float tmp_PatternRadius;				
					tmp_PatternRadius = 0.5f*(x_SetData->PatternDeep* x_SetData->PatternDeep+tmp_dotDia*tmp_dotDia/4)/x_SetData->PatternDeep;				
					str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}"+"	"+"{3:#0.00##}", pt_coor.X + x_SetData->X_direction_Shift,pt_coor.Y + x_SetData->Y_direction_Shift,x_SetData->PatternDeep, tmp_PatternRadius);
					sr->WriteLine(str);
				}
			}			

			break;

		}

				
		


		return true;
	}catch(...){
		MessageBox::Show("LTPattern�s�ɿ��~");
		return false;

	}


}


//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------IJP --------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------






bool Save_IJP_PatternFile(StreamWriter ^ sr,array<float,2>^ IJP_DotSize ,int &totalNumber,float IJP_DPI){


	try{

		long tmp = 0;
		for(int ii = 0 ; ii <IJP_DotSize->GetLength(0) ; ii ++){
			for(int jj = 0 ; jj <IJP_DotSize->GetLength(1) ; jj++){

				float dia = Convert::ToSingle(IJP_DotSize->GetValue(ii,jj));
				if( dia> 0){
					String^ str;
					str=String::Format("{0:#0.000##}"+" "+"{1:#0.000##}"+" "+"{2:#0.000##}",dia/1000.0f , ii*(25.4/IJP_DPI),jj*(25.4/IJP_DPI));
					sr->WriteLine(str);
					tmp ++;
				}
			}
		}

		totalNumber = tmp;

		return true;

	}catch(...){
		MessageBox::Show("IJP_Pattern�s�ɿ��~");
		return false;

	}






}

bool SaveHotSpotData(String^ version,StreamWriter ^ sr,ArrayList^ HotSpotData){

	try{

		for(int jj = 0 ;jj<HotSpotData->Count ; jj++){	

			sr->Write("$");
			sr->Write("HotSpotData_" + version);
			sr->Write('\n');		
			sr->Write("{ ");
			sr->Write('\n');
			/* old version
			array<String^>^ tmparray = (array<String^>^)HotSpotData->default[jj];

			for(int ii = 0 ; ii < tmparray->Length ; ii++){
				sr->Write(tmparray[ii]);
				if(ii < tmparray->Length-1 ) sr->Write(',');
			}*/

			// Version 3.6���᪺
			HotSpot_Part^ tmpData = (HotSpot_Part^) HotSpotData->default[jj];
			sr->Write(tmpData->Save());
			



			sr->Write('\n');
			sr->Write(" }");
			sr->Write('\n');

		}
		


		return true;



		return true;

	}catch(...){
		MessageBox::Show("�����ק�(���)�s�ɿ��~");
		return false;

	}



}
bool LoadHotSpotData(String^ version,StreamReader ^ sr,ArrayList^ HotSpotData){

	try{

		String^ str = (String^)(sr->ReadLine())->Trim();
		if(String::Compare(str ,"{")  == 0) {

			str = Convert::ToString(sr->ReadLine())->Trim();

			

			while(String::Compare(str,"}",true) != 0){
				
			//	if(version == "1"){
			//		array<String^>^ splitdata =str->Split(',') ;	
			//		//�[��HotSpotData
			//		HotSpotData->Add(splitdata);
			//		str = (String^)(sr->ReadLine())->Trim();

			//	}else if(version == "2"){

					//V3.6���᪺�s�[�c(Class �[�c)

					HotSpot_Part^ tmpPart = gcnew HotSpot_Part() ;
					tmpPart->Load(str,Convert::ToUInt16(version));

					HotSpotData->Add(tmpPart);
					str = (String^)(sr->ReadLine())->Trim();

			//	}

			}
		}

		return true;

	}catch(...){

		return false;

	}







}






//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------- OLD Version --------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

/*
bool SaveLTPatternFile(StreamWriter ^ sr, Point3d *pt ,long NR,MainFormData^ formdata,SettingData^ x_SetData){


	

	try{

		String^ str = "# LightTools 5.2.0 ";
		sr->WriteLine(str);
		str = "# Texture Placement/Parameter Export file";
		sr->WriteLine(str);
		
		
		if (x_SetData->LTPattern_Style == 0) {
			str = "                   X                   Y              Radius";	
			sr->WriteLine(str);
			for ( int  i =0 ; i<NR ; i++){
				if (pt[i].InsidePlateArea == true){
						double px ,py, pz;
						pt[i].GetPointPosition(px,py,pz);						
						//str = Convert::ToString(px-formdata->LGPDimension.X/2+x_SetData.X_direction_Shift)->PadLeft(21) + Convert::ToString(py-formdata->LGPDimension.Y /2+x_SetData.Y_direction_Shift)->PadLeft(21)+Convert::ToString(pt[i].Radius)->PadLeft(21);	
						str = Convert::ToString(px+x_SetData->X_direction_Shift)->PadLeft(21) + Convert::ToString(py+x_SetData->Y_direction_Shift)->PadLeft(21)+Convert::ToString(pt[i].Radius)->PadLeft(21);	
						sr->WriteLine(str);
					}
			}
		

		}else {
			
			str = "                   X                   Y       MaximumHeight              Radius";	
			sr->WriteLine(str);
			for ( int  i =0 ; i<NR ; i++){
				if (pt[i].InsidePlateArea == true){
						double px ,py, pz;
						float tmp_PatternRadius;
						tmp_PatternRadius = 0.5*(x_SetData->PatternDeep* x_SetData->PatternDeep+pt[i].Radius*pt[i].Radius)/x_SetData->PatternDeep;

						pt[i].GetPointPosition(px,py,pz);						
						//str = Convert::ToString(px-formdata->LGPDimension.X /2+x_SetData.X_direction_Shift)->PadLeft(21) + Convert::ToString(py-formdata->LGPDimension.Y /2+x_SetData.Y_direction_Shift)->PadLeft(21) + Convert::ToString(x_SetData.PatternDeep)->PadLeft(21) + Convert::ToString(tmp_PatternRadius)->PadLeft(21);
						str = Convert::ToString(px+x_SetData->X_direction_Shift)->PadLeft(21) + Convert::ToString(py+x_SetData->Y_direction_Shift)->PadLeft(21) + Convert::ToString(x_SetData->PatternDeep)->PadLeft(21) + Convert::ToString(tmp_PatternRadius)->PadLeft(21);
						sr->WriteLine(str);
					}
			}
		}
	//	sr->Close();
		return true;

	}catch(...){
	//	sr->Close();
		MessageBox::Show("LTPattern�s�ɿ��~");
		return false;

	}

	
}


*/

/*
bool SaveFormParaFile(StreamWriter ^ sr,MainFormData^ formdata){

	try{
		String^ str;		
		str=String::Format("{0:#0.00##}"+"	"+"{1:0}","�G�I�覡" , formdata->RandomDot);		
		sr->WriteLine(str);
	//	str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}","LGP�ؤo ",formdata->LGPDimension.X ,formdata->LGPDimension.Y );
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0.00##}","LGP�ؤo ",formdata->LGPInformation.Width ,formdata->LGPInformation.Height );
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤j���I ",formdata->MaxDot);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤p���I",formdata->MinDot);		
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�̤p���I����",formdata->MinDotGap);	
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","���I�Ϊ�",formdata->Pattern_Shape);	
		sr->WriteLine(str);	
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","���I�ƦC�覡",formdata->Pattern_Arrangment);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�üƺ��I�j�p",formdata->RandomDotSize);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","���I����Z��",formdata->RandomDotGap);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�B�⦸��",formdata->RandomDotIteration);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�B��k�h",formdata->RandomDotSimRule);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�Ѽ�K",formdata->Parameter_K);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}","�Ѽ�C",formdata->Parameter_C);
		sr->WriteLine(str);
		//Updata  20091203
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�K�׽վ�覡",formdata->DensityDesignMethod);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}"+"	"+"{2:#0}"+"	"+"{3:#0}","�üƱ���(Force,�֨�����,�֨�Force)",formdata->RandomStopForce,formdata->chkStopNmber,formdata->chkStopForce);
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}","�ü� �����W�v",formdata->RandomRebuildFrequency);
		sr->WriteLine(str);		

		return true;
	}catch(...){
	
		MessageBox::Show("�ѼƦs�ɿ��~");
		return false;
	}





}




*/
/*
bool SaveB_Spline_Curve(StreamWriter ^ sr,B_Spline_Curve^ Curve){
		
	

		try{	
			String^ str;
			str = "# ControlPt Location/Parameter Export file";
			sr->WriteLine(str);
			str = Convert::ToString(Curve->ControllPt->Count);
			sr->WriteLine(str);
			str = "X-Direction" + "	"+"Y-Direction ";					
			sr->WriteLine(str);

			for(int i=0 ; i<Curve->ControllPt->Count ;i++){											
				str=String::Format("{0:F}"+"	"+"{1:F}",Curve->ControllPt->default[i].X,Curve->ControllPt->default[i].Y);						
				sr->WriteLine(str);
			}			
			
			return true;
		
		}catch(...){
			sr->Close();
			MessageBox::Show(" ���u�Ѽ� �s�ɿ��~");
			return false;
		}
	

}
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
			MessageBox::Show(" ���u�Ѽ� Ū�ɿ��~");
			return false;
		}



}
*/
/*
bool SavePatternFile(StreamWriter ^ sr,MainFormData^ formdata,Point3d *pt,long NR,int startpt ,int endpt){
	

	try{

		
		sr->WriteLine("0"); 
		sr->WriteLine("SECTION");
		sr->WriteLine("2");
		sr->WriteLine("ENTITIES");
		
		if (formdata->Pattern_Shape == 0) {
			//���
			for(int i = startpt ;i< endpt ;i++){
				if(pt[i].InsidePlateArea == true && pt[i].Radius > 0.0f){
					double px,py,pz;
					pt[i].GetPointPosition(px,py,pz);
					sr->WriteLine("0");
					sr->WriteLine("CIRCLE");
					sr->WriteLine("8");
					sr->WriteLine("0");
					sr->WriteLine("10");
					sr->WriteLine(Convert::ToString((float)px+ pt[i].Radius));
					//sr->WriteLine(Convert::ToString(px+ inputdata.PatternRadius));
					sr->WriteLine("20");
					sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y -(float)py- pt[i].Radius));
					//sr->WriteLine(Convert::ToString(inputdata.PlateHeight-py- inputdata.PatternRadius));
					sr->WriteLine("30");
					sr->WriteLine("0");
					sr->WriteLine("40");
					sr->WriteLine(Convert::ToString(pt[i].Radius));
					//sr->WriteLine(Convert::ToString(inputdata.PatternRadius));
				}
			}
		}
		else if(formdata->Pattern_Shape == 1){
			//�x��

			for(int i = startpt ;i< endpt ;i++){
				if(pt[i].InsidePlateArea == true){
					double px0,py0,pz0;
					pt[i].GetPointPosition(px0,py0,pz0);
					double px[5],py[5];
					px[0] = px0 ;
					py[0] = py0 ;
					px[1] = px0 + 2*pt[i].Radius ;
					py[1] = py0 ;
					px[2] = px0 + 2*pt[i].Radius ;
					py[2] = py0 + 2*pt[i].Radius;
					px[3] = px0 ;
					py[3] = py0 +2*pt[i].Radius ;

					//px[0] = px0 - inputdata.PatternRadius+ inputdata.PatternRadius;
					//py[0] = py0 - inputdata.PatternRadius+ inputdata.PatternRadius ;
					//px[1] = px0 + inputdata.PatternRadius+ inputdata.PatternRadius ;
					//py[1] = py0 - inputdata.PatternRadius + inputdata.PatternRadius;
					//px[2] = px0 + inputdata.PatternRadius+ inputdata.PatternRadius ;
					//py[2] = py0 + inputdata.PatternRadius + inputdata.PatternRadius;
					//px[3] = px0 - inputdata.PatternRadius+ inputdata.PatternRadius ;
					//py[3] = py0 + inputdata.PatternRadius+ inputdata.PatternRadius ;
					px[4] = px[0];
					py[4] = py[0];

					for(int j=0 ;j<4;j++){
						sr->WriteLine("0"); 
						sr->WriteLine("LINE"); 
						sr->WriteLine("8"); 
						sr->WriteLine("0"); 
						sr->WriteLine("10"); 
						sr->WriteLine(Convert::ToString(px[j])); 
						sr->WriteLine( "20"); 
						sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y -py[j])); 
						sr->WriteLine( "30"); 
						sr->WriteLine( "0"); 
						sr->WriteLine( "11"); 
						sr->WriteLine(Convert::ToString(px[j+1])); 
						sr->WriteLine( "21"); 
						sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y -py[j+1])); 
						sr->WriteLine( "31"); 
						sr->WriteLine( "0"); 
					}
				}
			}		
		}
		else{
			//�٧�
			for(int i = startpt ;i< endpt ;i++){
				if(pt[i].InsidePlateArea == true){
					double px0,py0,pz0;
					pt[i].GetPointPosition(px0,py0,pz0);
					double px[5],py[5];
					px[0] = px0 + pt[i].Radius;
					py[0] = py0  ;
					px[1] = px0 + 2*pt[i].Radius ;
					py[1] = py0 + pt[i].Radius;
					px[2] = px0 + pt[i].Radius ;
					py[2] = py0 + 2*pt[i].Radius;
					px[3] = px0  ;
					py[3] = py0 + pt[i].Radius;
					px[4] = px[0];
					py[4] = py[0];

					//px[0] = px0 + inputdata.PatternRadius;
					//py[0] = py0  ;
					//px[1] = px0 + inputdata.PatternRadius+ inputdata.PatternRadius ;
					//py[1] = py0 + inputdata.PatternRadius;
					//px[2] = px0 + inputdata.PatternRadius ;
					//py[2] = py0 + inputdata.PatternRadius + inputdata.PatternRadius;
					//px[3] = px0  ;
					//py[3] = py0 + inputdata.PatternRadius;
					//px[4] = px[0];
					//py[4] = py[0];

					for(int j=0 ;j<4;j++){
						sr->WriteLine("0"); 
						sr->WriteLine("LINE"); 
						sr->WriteLine("8"); 
						sr->WriteLine("0"); 
						sr->WriteLine("10"); 
						sr->WriteLine(Convert::ToString(px[j])); 
						sr->WriteLine( "20"); 
						sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y -py[j])); 
						sr->WriteLine( "30"); 
						sr->WriteLine( "0"); 
						sr->WriteLine( "11"); 
						sr->WriteLine(Convert::ToString(px[j+1])); 
						sr->WriteLine( "21"); 
						sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y -py[j+1])); 
						sr->WriteLine( "31"); 
						sr->WriteLine( "0"); 
					}
				}
			}		
		}


		sr->WriteLine("0"); 
		sr->WriteLine("LINE"); 
		sr->WriteLine("8"); 
		sr->WriteLine("0"); 
		sr->WriteLine("10"); 
		sr->WriteLine("0"); 
		sr->WriteLine("20"); 
		sr->WriteLine("0"); 
		sr->WriteLine("30"); 
		sr->WriteLine("0"); 
		sr->WriteLine("11"); 
		sr->WriteLine("0"); 
		sr->WriteLine("21"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y )); 
		sr->WriteLine("31"); 
		sr->WriteLine("0"); 
		sr->WriteLine("0"); 
		sr->WriteLine("LINE"); 
		sr->WriteLine("8"); 
		sr->WriteLine("0"); 
		sr->WriteLine("10"); 
		sr->WriteLine("0"); 
		sr->WriteLine("20"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y )); 
		sr->WriteLine("30"); 
		sr->WriteLine("0"); 
		sr->WriteLine("11"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.X ));
		sr->WriteLine("21"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y ));
		sr->WriteLine("31"); 
		sr->WriteLine("0"); 

		sr->WriteLine("0"); 
		sr->WriteLine("LINE"); 
		sr->WriteLine("8"); 
		sr->WriteLine("0"); 
		sr->WriteLine("10"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.X )); 
		sr->WriteLine("20"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.Y )); 
		sr->WriteLine("30"); 
		sr->WriteLine("0"); 
		sr->WriteLine("11"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.X )); 
		sr->WriteLine("21"); 
		sr->WriteLine("0"); 
		sr->WriteLine("31"); 
		sr->WriteLine("0"); 

		sr->WriteLine("0"); 
		sr->WriteLine("LINE"); 
		sr->WriteLine("8"); 
		sr->WriteLine("0"); 
		sr->WriteLine("10"); 
		sr->WriteLine(Convert::ToString(formdata->LGPDimension.X )); 
		sr->WriteLine("20"); 
		sr->WriteLine("0"); 
		sr->WriteLine("30"); 
		sr->WriteLine("0"); 
		sr->WriteLine("11"); 
		sr->WriteLine("0"); 
		sr->WriteLine("21"); 
		sr->WriteLine("0"); 
		sr->WriteLine("31"); 
		sr->WriteLine("0"); 

		sr->WriteLine("0"); 
		sr->WriteLine("ENDSEC"); 
		sr->WriteLine("0"); 
		sr->WriteLine("EOF"); 
		sr->Close();
		

		return true;
		}
		catch(...){
			sr->Close();
			MessageBox::Show("DxfPattern�s�ɿ��~");
			return false;

		}


}
*/

/*
bool SaveDetailModifyPara(StreamWriter ^ sr,Cosmetic_Data^ Cosmetic_Data){
	

	// Hot Spot �x�s
	for(int ii = 0 ; ii < 4 ; ii ++){
		for(int jj = 0 ; jj < 81 ; jj ++){
			String^ str = Convert::ToString(Cosmetic_Data->HotBar_History_Data->GetValue(ii,jj));
			sr->Write(str);
			sr->Write("	");
		}	
		sr->Write('\n');

	}

	//Local Area �x�s
	int num = Convert::ToInt16(Cosmetic_Data->LocalArea_History_Data->GetLength(0));
	int num2 = Convert::ToInt16(Cosmetic_Data->LocalArea_History_Data->GetLength(1));
	sr->WriteLine(Convert::ToString(num)); 
	for(int ii = 0 ; ii < num ; ii ++){
		for(int jj = 0 ; jj < num2 ; jj ++){
			String^ str = Convert::ToString(Cosmetic_Data->LocalArea_History_Data->GetValue(ii,jj));
			sr->Write(str);
			sr->Write("	");
		}	
		sr->Write('\n');

	}
	
	return true;

};
bool SaveCLT_Characteristic_File_V3(StreamWriter ^ sr,MainFormData^ formdata,Nurbs::B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data,B_Spline_Curve^ Curve_H,B_Spline_Curve^ Curve_V){
		bool success1,success2,success3,success4 ,success5;
	
		sr->WriteLine("Part1---------------------------------------------");
		//success1 = SaveInputParaFile_071003(sr,inputdata);
		success1 = SaveFormParaFile( sr,formdata);
		sr->WriteLine("Part2---------------------------------------------");
		success2 = SaveB_Spline_Surface(sr,Surface_Global_Design);
		sr->WriteLine("Part3---------------------------------------------");
		success3 = SaveDetailModifyPara(sr,Cosmetic_Data);
		sr->WriteLine("Part4-1 -Curve_Horizontal------------------------");
		success4 = SaveB_Spline_Curve( sr,Curve_H);
		sr->WriteLine("Part4-2 -Curve_Vertical--------------------------");
		success5 = SaveB_Spline_Curve( sr,Curve_V);
		sr->WriteLine("PartFinish----------------------------------------");
		

		
		if(success1 == true && success2 == true && success3 == true && success4 == true && success5 == true){
			return true;
		}else{
			return false;
		}

};

bool SaveCLT_Characteristic_File_V2(StreamWriter ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data){
		bool success1,success2,success3,success4;
	
		sr->WriteLine("Part1---------------------------------------------");
		//success1 = SaveInputParaFile_071003(sr,inputdata);
		success1 = SaveFormParaFile( sr,formdata);
		sr->WriteLine("Part2---------------------------------------------");
		success2 = SaveB_Spline_Surface(sr,Surface_Global_Design);
		sr->WriteLine("Part3---------------------------------------------");
		success3 = SaveDetailModifyPara(sr,Cosmetic_Data);
		sr->WriteLine("PartFinish----------------------------------------");
		

		
		if(success1 == true && success2 == true && success3 == true){
			return true;
		}else{
			return false;
		}

}
bool SaveCLT_Characteristic_File_V1(StreamWriter ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design){
		bool success1,success2,success3,success4;
	
		sr->WriteLine("Part1---------------------------------------------");
		//success1 = SaveInputParaFile_071003(sr,inputdata);
		success1 = SaveFormParaFile( sr,formdata);
		sr->WriteLine("Part2---------------------------------------------");
		success2 = SaveB_Spline_Surface(sr,Surface_Global_Design);
		sr->WriteLine("PartFinish----------------------------------------");
		

		
		if(success1 == true && success2 == true ){
			return true;
		}else{
			return false;
		}





}

bool SaveB_Spline_Surface(StreamWriter ^ sr,B_Spline_Surface^ Surface_Global_Design){

/*	
	try{
	
		array<String^>^ SurfaceData =  Surface_Global_Design->LoadSurfaceInputData();


		



		String^ str;		
		str =String::Format("{0:#0.00##}","Surface_Para_V1.0.1");  //1.01 ����Y�y���A�˪����D~~
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}"+"	"+"{2:#0}","�����I�ƥ�(�� X �a)",SurfaceData->GetValue(5),SurfaceData->GetValue(6));
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}"+"	"+"{2:#0}","�ѪR��(�� X �a)",SurfaceData->GetValue(3),SurfaceData->GetValue(4));
		sr->WriteLine(str);
		int tmpU = 0,tmpV = 0 ;
		Surface_Global_Design->Get_uv_Value(tmpU,tmpV);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0}"+"	"+"{2:#0}","���ƫ�(�� X �a)",tmpU,tmpV);
		sr->WriteLine(str);
		str =String::Format("{0:#0}","���K�Ѽ�");
		sr->WriteLine(str);
		//�����T�{��ЩM�a�y��OK��OK~~
		for(int j = 0 ; j <	Surface_Global_Design->ControllPt_Z->GetLength(1) ; j ++){
			for(int i = 0 ; i <	Surface_Global_Design->ControllPt_Z->GetLength(0) ; i++){
				str =String::Format("{0:#0.00##}"+"	",SurfaceData->GetValue(7+));
				sr->Write(str);
			}
			sr->Write(sr->NewLine);
		}
		str =String::Format("{0:#0}","(X,Y)�y�Ц�m�Ѽ�");
		sr->WriteLine(str);
		//�����T�{��ЩM�a�y��OK��OK~~
		for(int j = 0 ; j <	Surface_Global_Design->ControllPt->GetLength(1) ; j ++){
			for(int i = 0 ; i <	Surface_Global_Design->ControllPt->GetLength(0) ; i++){			
				PointF tmpLocation = (PointF)Surface_Global_Design->ControllPt->GetValue(i,j); 
				str =String::Format("{0:#0.00##}"+" , " + "{1:#0.00##}" + "	",tmpLocation.X ,tmpLocation.Y);
				sr->Write(str);
			}
			sr->Write(sr->NewLine);
		}

			
		return true;



	}catch(...){
		MessageBox::Show("Surface �ѼƦs�ɿ��~");
		return false;
	}

*/
//return false;
//}

/*
bool SaveControllpt(StreamWriter ^ sr,SmoothSurfaceInfo^ controllpt){


	try{
		String^ str;		
		str =String::Format("{0:#0.00##}","ControllPt_Part_V1.0.0");
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}",controllpt->Controll_Row_number,controllpt->Controll_Collum_number);
		sr->WriteLine(str);
		str = "X-Location";
		sr->WriteLine(str);
		for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
			for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
				str =String::Format("{0:#0.00##}"+"	",controllpt->controllPt_X->GetValue(i,j));
				sr->Write(str);
			}
			sr->Write(sr->NewLine);
		}
		str = "Y-Location";
		sr->WriteLine(str);
		for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
			for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
				str =String::Format("{0:#0.00##}"+"	",controllpt->controllPt_Y->GetValue(i,j));
				sr->Write(str);
			}
			sr->Write(sr->NewLine);
		}
		str = "Z-Value";
		sr->WriteLine(str);
		for(int i = 0 ; i <controllpt->Controll_Row_number ; i ++){
			for(int j = 0 ; j <controllpt->Controll_Collum_number ; j++){
				str =String::Format("{0:#0.00##}"+"	",controllpt->controllPt_Z->GetValue(i,j));
				sr->Write(str);
			}
			sr->Write(sr->NewLine);
		}
		str = "IniValue_Z";
		sr->WriteLine(str);
		str = Convert::ToString(controllpt->IniValue_Z);
		sr->WriteLine(str);
		str = "Current Controll Pt Index";
		sr->WriteLine(str);
		str=String::Format("{0:#0.00##}"+"	"+"{1:#0.00##}",controllpt->SelectIndex_X,controllpt->SelectIndex_Y);
		sr->WriteLine(str);
		//str = Convert::ToString(controllpt->SelectIndex_X)->PadLeft(15) + Convert::ToString(controllpt->SelectIndex_Y)->PadLeft(15);
		//sr->WriteLine(str);
		str = "Bool Empty";
		sr->WriteLine(str);
		sr->WriteLine(controllpt->Empty);
		return true;
	}
	catch(...){
		MessageBox::Show("ControllPt�s�ɿ��~");
		return false;
	}

}



//-----Pt Number Reset----------------------------------
//-----Mesh Number Reset -------------------------------
//-----Inputdata Reset ---------------------------------


void FileNew(Pattern^ tmpdot,GridDensity^ tmpDensity,Point &tmpGirdNumber,MainFormData^ tmpMainData,B_Spline_Surface^ tmpSurface_Global_Design){
	//���I����
	//tmpdot->ClearAll();
	//tmpDensity->xClearAll();
	//tmpGirdNumber.Empty;
	//Main��� �Ѽ�
	//tmpMainData->Initialize();
	//Surface �Ѽ�
	//tmpSurface_Global_Design->xInitialize();
	
}

*/
/*
bool OpenDetailModifyPara(StreamReader ^ sr,Cosmetic_Data^ Cosmetic_Data){
	

	String^ str;
	array<String^>^ SepData;



	// Hot Spot �x�s
	Cosmetic_Data->HotBar_History_Data = gcnew array<String^,2>(4,81);
	
	for(int ii = 0 ; ii < 4 ; ii ++){
		str = sr->ReadLine(); // Ū��Hot Spot Data
			
		SepData = str->Split('	');
	
		for(int jj = 0 ; jj < SepData->Length-1 ; jj ++){  //SepData->Length-1 �O���� ����
			if(Convert::ToString(SepData->GetValue(jj)) != ""){
				Cosmetic_Data->HotBar_History_Data->SetValue(Convert::ToString(SepData->GetValue(jj)),ii,jj);
			}
		}	
		Array::Clear(SepData,0,SepData->Length);
	}

	//Local Area �x�s
	
	str = sr->ReadLine();
	int num = Convert::ToInt16(str);

	Cosmetic_Data->LocalArea_History_Data = gcnew array<float,2>(num,110);

	for(int ii = 0 ; ii < num ; ii ++){
		str = sr->ReadLine(); // Ū��Hot Spot Data
		
		SepData = str->Split('	');

		for(int jj = 0 ; jj < SepData->Length-1 ; jj ++){		//SepData->Length-1 �O���� ����	
			Cosmetic_Data->LocalArea_History_Data->SetValue(Convert::ToSingle(SepData->GetValue(jj)),ii,jj);					
		}	
		Array::Clear(SepData,0,SepData->Length);	

		//�ª���ƨS��array �ƥ� ....�w�q�� 1 		
		 if(Convert::ToInt16(Cosmetic_Data->LocalArea_History_Data->GetValue(ii,33)) < 1) 
			Cosmetic_Data->LocalArea_History_Data->SetValue(1,ii,33);

		 //�ª��S���w�qweight .....�w�q�� 1 
		 

		
		

	}
	
	return true;

};

*/

//�}��AutoCad Pattern �ɮ�...
/*
Point3d* OpenPatternFile(StreamReader ^ sr,long &NR){

	//*
	List<PointF>^ tmpListPt = gcnew List<PointF>(0);
	PointF tmpPt(0,0);
	List<float>^ tmpListRadius = gcnew List<float>(0) ;
	float tmpRadius = 0;
	int count = 0;
	bool In_X = false , In_Y = false ,In_Raduis = false;


	
	while(sr->EndOfStream != true){	
		String^ str ;
		String^ buffer;	
		
		str = sr->ReadLine();
		if (str == "CIRCLE"){

			//�ե� AUTOCAD R12 DXF �榡 ,���A�Υثe�s�X�h��DXF�榡
			str = sr->ReadLine();   // ---> �ثe�s�X�h��DXF�榡�S������
			str = sr->ReadLine();   // ---> �ثe�s�X�h��DXF�榡�S������
			str = sr->ReadLine();
			str = sr->ReadLine();
			str = sr->ReadLine();
			
			

			if(str == " 10") {	
				str = sr->ReadLine();   //X				
				tmpPt.X = Convert::ToSingle(str);
				In_X = true;
				
			}
			str = sr->ReadLine();
			if(str == " 20") {
				str = sr->ReadLine();   //Y			
				tmpPt.Y = Convert::ToSingle(str);
				In_Y = true;
			}
			str = sr->ReadLine();
			str = sr->ReadLine();			
			str = sr->ReadLine();
			if(str == " 40"){
				str = sr->ReadLine();   //Radius		
				tmpRadius = Convert::ToSingle(str);
				In_Raduis = true;
			}
			if ( In_X * In_Y * In_Raduis ==true) {
				tmpListPt->Add(tmpPt);
				tmpListRadius->Add(tmpRadius);		
			}
		}
		
	}






	Point3d *pt = new Point3d[tmpListPt->Count];

	for (int i= 0 ; i < tmpListPt->Count ; i++){
		pt[i].X = tmpListPt->default[i].X;
		pt[i].Y = tmpListPt->default[i].Y;
		pt[i].Radius = tmpListRadius->default[i];
		pt[i].InsidePlateArea = true;
	};
	

	NR = (long)tmpListPt->Count;
			
		
	return pt;

}


*/


/*
//�}�ұM���� ---Old Version
void OpenCLT_Characteristic_File(GridDensity^ tmpDensity,StreamReader ^ sr,DataInput &inputdata,bool &filenew){
		
	bool success1,success2,success3,success4;
	MeshGrid *mg = nullptr;

	//sr->WriteLine("Version  1.0.0------------------------------------");
	sr->ReadLine();
	//sr->WriteLine("Part1---------------------------------------------");
	sr->ReadLine();

	success1 = OpenParaFile_071005(sr,inputdata,filenew);
	//success1 = SaveInputParaFile_071003(sr,inputdata);		
	
	sr->ReadLine();
	//sr->WriteLine("Part2---------------------------------------------");

	//--------�Ȯ�����------------------
	//mg = OpenDensityWithDimFile_071005(sr,inputdata,filenew);


	sr->Close();

	



}

//�}�ұM���� ---�M����CLT_090112
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








//�}�ұM���� ---R1
bool OpenCLT_R1(StreamReader ^ sr,MainFormData^ formdata,B_Spline_Surface^ Surface_Global_Design,Cosmetic_Data^ Cosmetic_Data , B_Spline_Curve^ H_Curve , B_Spline_Curve^ V_Curve){

	bool success1,success2,success3,success4,success5;
	int fileversion = 0;



	array<String^>^ SepData;
	String^ str;
	str = sr->ReadLine(); // Ū���ɮת���
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
		success3 = OpenDetailModifyPara( sr, Cosmetic_Data);
		sr->ReadLine();//("PartFinish----------------------------------------");
		sr->Close();
	}else if(fileversion == 3){
		sr->ReadLine();   //("Part1---------------------------------------------");
		success1 = OpenParaFile_R1( sr,formdata);				
	//	sr->ReadLine();  //("Part2---------------------------------------------");
		success2 = OpenB_Spline_Surface(sr, Surface_Global_Design);
		sr->ReadLine();//("Part3----------------------------------------");
		success3 = OpenDetailModifyPara( sr, Cosmetic_Data);
		sr->ReadLine();//("Part4-1  Horizontal----------------------------------------");
		success4 = OpenB_Spline_Curve( sr,H_Curve);
		sr->ReadLine();//("Part4-2  Vertical ----------------------------------------");
		success5 =OpenB_Spline_Curve( sr,V_Curve);
		sr->ReadLine();//("PartFinish----------------------------------------");
		sr->Close();
	}

	if(success1 == true  && success2 == true && success3 == true){
		return true;
	}else{
		return false;
	}


}
//�����x�s�l�禡

//�±M���ɾA��
bool OpenParaFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew){



	try{


			String^ fileVersion = "ParaFileVersion 1.0.0";
			
			String^ str ;
			String^ buffer;
			String^ buffer2;
			//Ū���ɮת����榡
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
				MessageBox::Show("Ū�����ɮת����P���n�餣�ۮe ,���n�餹�\������ : " + fileVersion);
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
		inputdata.PatternMode = (int)Convert::ToSingle(buffer);  //���ઽ����Convert::ToInt16 �ഫ


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
		inputdata.CalMode =(int)Convert::ToSingle(buffer);   //���ઽ����Convert::ToInt16 �ഫ 
		


		

		str = sr->ReadLine();		
		found = str->IndexOf( "	" );
		if (found != -1)
			buffer =str->Substring(0,found);
		else
			buffer = str->Substring(0)->Trim(); 

		//str=String::Format("{0:F}",inputdata.SimShape);	
		inputdata.SimShape = (int)Convert::ToSingle(buffer);  //���ઽ����Convert::ToInt16 �ഫ 


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
		MessageBox::Show("�M����_�Ѽ�Ū��_���~");
		filenew = true;
		return false;
	}




};
MeshGrid  *OpenDensityWithDimFile_071005(StreamReader ^ sr,DataInput &inputdata,bool &filenew){
	





	float pos[2],size[2];
	float density;
	float tmp[4];
	MeshGrid *mg = nullptr;
	String^ str ;
	String^ buffer;
	int length;

		
		try{


			String^ fileVersion = "DenSityVersion 1.0.0";
			
			String^ str ;
			String^ buffer;
			String^ buffer2;
			//Ū���ɮת����榡
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
				MessageBox::Show("Ū�����ɮת����P���n�餣�ۮe ,���n�餹�\������ : " + fileVersion);
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
			MessageBox::Show("DensityŪ�ɿ��~!");
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
			//Ū���ɮת����榡
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
				MessageBox::Show("Ū�����ɮת����P���n�餣�ۮe ,���n�餹�\������ : " + fileVersion);
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
			
			controllpt->Controll_Row_number = tmp[0];
			controllpt->Controll_Collum_number = tmp[1];

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
			controllpt->SelectIndex_X = tmp[0];
			controllpt->SelectIndex_Y = tmp[1];

			
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
		MessageBox::Show("Surface-ControllPtŪ�ɿ��~");
		return false;
	}

};





//�M���� CLT_090112 �A��
bool OpenB_Spline_Surface(StreamReader ^ sr,B_Spline_Surface^ Surface_Global_Design){

	try{
		String^ fileVersion = "Surface_Para_V1.0.0";
		String^ fileVersion2 = "Surface_Para_V1.0.1";
		String^ str;
		int version = 0;
		
		int compare = -1;
		int compare2 = -1;

		array<String^>^ SepData;
		str = sr->ReadLine(); // Ū���ɮת���
		SepData = str->Split('	');	
		compare = String::Compare(Convert::ToString(SepData->GetValue(0)),fileVersion);
		compare2 = String::Compare(Convert::ToString(SepData->GetValue(0)),fileVersion2);

		if (compare != 0 && compare2 != 0) {
			sr->Close();
			MessageBox::Show("Ū�����ɮת����P���n�餣�ۮe ,���n�餹�\������ : " + fileVersion + "��" + fileVersion2 );
			return false;
		}else{
			if(compare  == 0) version = 100 ;
			if(compare2 == 0) version = 101 ;
		}





		str = sr->ReadLine(); // Ū�������I�ƥ�
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
		int Num_H = 0 ,Num_V = 0;
		Num_H = Convert::ToInt64(SepData->GetValue(1));
		Num_V = Convert::ToInt16(SepData->GetValue(2));
		


		str = sr->ReadLine(); // Ū���ѪR��
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
		int resolution_H = 0 ,resolution_V = 0;
		resolution_H = Convert::ToInt16(SepData->GetValue(1));
		resolution_V = Convert::ToInt16(SepData->GetValue(2));


		
		str = sr->ReadLine(); // Ū�����ƫ�
		Array::Clear(SepData,0,SepData->Length);					
		SepData = str->Split('	');
		int tmpU = 0,tmpV = 0 ;
		tmpU = Convert::ToInt16(SepData->GetValue(1));
		tmpV = Convert::ToInt16(SepData->GetValue(2));
//		Surface_Global_Design->Set_uv_Value(tmpU,tmpV);
		
		
		str = sr->ReadLine(); // ���K�Ѽ� Mark

		Point CptNum(Num_H,Num_V); Point Degree(tmpU,tmpV); Point Resolution(resolution_H,resolution_V);
		Surface_Global_Design->CreateZeroSurface(CptNum,Degree,Resolution);


		array<PointF,2>^ ControllPt = gcnew array<PointF,2>(Num_H,Num_V);
		array<float,2>^ ControllPt_Z = gcnew array<float,2>(Num_H,Num_V);
		array<float,2>^ Weight = gcnew array<float,2>(Num_H,Num_V);


		//-----------------------------------------------------------------------
		for(int j = 0 ; j <	Num_V ; j ++){
			str = sr->ReadLine(); // Ū�����K�Ѽ�
			Array::Clear(SepData,0,SepData->Length);					
			SepData = str->Split('	');
			for(int i = 0 ; i <	Num_H ; i++){
				float tmpZ = Convert::ToSingle(SepData->GetValue(i));

				if(version == 100) ControllPt_Z->SetValue(tmpZ,i,Num_V-1-j);
				else if(version == 101) ControllPt_Z->SetValue(tmpZ,i,j);

				Weight->SetValue(1.0f,i,j);
			
			}			
		}


		

		str = sr->ReadLine(); // (X,Y)�y�аѼ� Mark

		for(int j = 0 ; j <	Num_V ; j ++){
			
			str = sr->ReadLine(); // Ū��(X,Y)�y�аѼưѼ�
			Array::Clear(SepData,0,SepData->Length);					
			SepData = str->Split('	');

			array<String^>^ XYData;
			PointF tmpCoor(0,0);
			
			for(int i = 0 ; i <	Num_H ; i++){
				
								
				XYData = Convert::ToString(SepData->GetValue(i))->Split(',');
				tmpCoor.X = Convert::ToSingle(XYData->GetValue(0));
				tmpCoor.Y = Convert::ToSingle(XYData->GetValue(1));


				ControllPt->SetValue(tmpCoor,i,j);

				Array::Clear(XYData,0,XYData->Length);	

			
			}
			
		}



		Surface_Global_Design->SetSurfaceData(ControllPt,ControllPt_Z,Weight);




		return true;

	}catch(...){
		MessageBox::Show("Surface �Ѽ�Ū�ɿ��~");
		return false;
	}





};


//�M����R1���A��
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
				case 0 : // Ū���G�I�覡
					formdata->RandomDot = Convert::ToBoolean(SepData->GetValue(1));
					break;
				case 1: // Ū��LGP�ؤo
					formdata->LGPInformation.Width = Convert::ToSingle(SepData->GetValue(1));
					formdata->LGPInformation.Height = Convert::ToSingle(SepData->GetValue(2));
					formdata->LGPInformation.X = 0;
					formdata->LGPInformation.Y = 0;
					break;
				case 2: // Ū���̤j���I
					formdata->MaxDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 3:// Ū���̤p���I
					formdata->MinDot = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 4:// �̤p���I����
					formdata->MinDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 5:// ���I�Ϊ�
					formdata->Pattern_Shape = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 6:// ���I�ƦC�覡
					formdata->Pattern_Arrangment = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 7:// �üƺ��I�j�p
					formdata->RandomDotSize = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 8:// ���I����Z��
					formdata->RandomDotGap = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 9:// �B�⦸��
					formdata->RandomDotIteration = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 10:// �B��k�h
					formdata->RandomDotSimRule = Convert::ToInt16(SepData->GetValue(1));
					break;
				case 11:// �Ѽ�K
					formdata->Parameter_K = Convert::ToSingle(SepData->GetValue(1));
					break;
				case 12:// �Ѽ�C
					formdata->Parameter_C = Convert::ToSingle(SepData->GetValue(1));
					break;
				//Updata  20091203--------------------------------------------------------
				case 13:// �K�׽վ�覡
					formdata->DensityDesignMethod = Convert::ToInt16(SepData->GetValue(1));	
					break;
				case 14: //�üƱ���(Force,�֨�����,�֨�Force)
					formdata->RandomStopForce = Convert::ToSingle(SepData->GetValue(1));
					formdata->chkStopNmber = Convert::ToBoolean(SepData->GetValue(2));
					formdata->chkStopForce = Convert::ToBoolean(SepData->GetValue(3));						
					break;
				case 15: //�ü� �����W�v
					formdata->RandomRebuildFrequency = Convert::ToInt16(SepData->GetValue(1));
					break;				
			}

			str = sr->ReadLine();
			
			
		}

	

		return true;

	}
	catch(...){
		sr->Close();
		MessageBox::Show("�M����_�Ѽ�Ū��_���~");

		return false;
	}




};




*/