#include "StdAfx.h"
#include "Cosmetic_LocalArea_Form.h"
using namespace std;
using namespace PatternContruction;



array<String^>^ Cosmetic_LocalArea_Form::ToSurfaceInputData(array<String^,1>^ data){

	//--------------------------------------------------------------------------------------------------
	//將arraylist 容器中的輸入參數資料轉為 Surface 可以接收的資料...
	//Surface 定義資料是 Index 0 ->Name;
	//Surface 定義資料是 Index 1 ->U Value (平滑度X);
	//Surface 定義資料是 Index 2 ->V Value (平滑度Y);
	//Surface 定義資料是 Index 3 ->解析度 X;
	//Surface 定義資料是 Index 4 ->解析度 Y;
	//Surface 定義資料是 Index 5 ->控制點數X ;
	//Surface 定義資料是 Index 6 ->控制點數Y ;
	//Surface Index 7 以後的陣列資料是 :
	// count + 0 -> 控制點座標X  ,count + 1 --> 控制點座標Y ,count + 2 --> Z Value ,count + 3 ->權重 
	//--------------------------------------------------------------------------------------------------
	// ArrayList 中的資料是 ...(此資料是局部修改的資料)
	// Index 0 --> 資料在DataGrid 的索引數值
	// Index 1 -->座標定義方式(左上,右上 ,...)
	// Index 2 --> X 座標
	// Index 3 --> Y 座標
	// Index 4 --> X 方向大小
	// Index 5 --> Y 方向大小
	// Index 6 -->U_Value (平滑度X)
	// Index 7 -->V_Value (平滑度Y)
	// Index 8 -->陣列方向 (+X ,-X ,...)
	// Index 9 -->陣列數目 
	// Index 10 -->陣列Pitch
	// Index 11 -->名稱 
	// Index 12 -->控制點X  
	// Index 13 -->控制點Y 
	// Index 14 以後的陣列資料是 :
	// count + 0 -> Z Value   ,count + 1 --> 權重 ,count + 2 --> X座標 ,count + 3 ->Y座標 
    //------------------------------------------------------------------------------------------------


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

			return surfacedata;
	


/*


	int NumX = Convert::ToInt16(forminputdata->GetValue(12));
	int NumY = Convert::ToInt16(forminputdata->GetValue(13));

	array<float,1>^ surfacedata = gcnew array<float,1>(6+NumX*NumY) ;

	//surfacedata->SetValue(forminputdata->GetValue(11),0); ->不紀錄Name....
	surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(6)),1);
	surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(7)),2);
	surfacedata->SetValue(100,3);
	surfacedata->SetValue(100,4);
	surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(12)),5);
	surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(13)),6);

	int count = 7;
	for(int ii = 0 ; ii <NumX ;ii ++){
		for(int jj = 0 ; jj <NumY ; jj ++){
			surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(7+count + 2)),count);
			
			surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(7+count + 3)),count);
			
			surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(7+count)),count);
			
			surfacedata->SetValue(Convert::ToSingle(forminputdata->GetValue(7+count+1)),count);
			count =count +4 ;


		}
	}

*/
	
















}
void Cosmetic_LocalArea_Form::ShowData(array<String^,1>^ inputdata,int currentRow){

		this->dataGridView_History->ColumnCount::set(6);
		this->dataGridView_History->default[0,currentRow]->Value = (String^)inputdata->GetValue(11); //Name 

		String^ location;
		switch (Convert::ToInt16(inputdata->GetValue(1))){
			case 0:
				location = "左下點(X,Y) :";
			break;
			case 1:
				location = "左上點(X,Y) :";
			break;
			case 2:
				location = "右上點(X,Y) :";
			break;
			case 3:
				location = "右下點(X,Y) :";
			break;
			case 4:
				location = "中心點(X,Y) :";
			break;
			case 5:
				location = "左中點(X,Y) :";
			break;
			case 6:
				location = "右中點(X,Y) :";
			break;
			case 7:
				location = "上中點(X,Y) :";
			break;
			case 8:
				location = "下中點(X,Y) :";
			break;


		}

		//this->dataGridView_History->default[1,currentRow]->Value = (String^)inputdata->GetValue(2); //啟用或不啟用
		this->dataGridView_History->default[1,currentRow]->Value = location;  //座標位置
		this->dataGridView_History->default[2,currentRow]->Value = (String^)inputdata->GetValue(2);  // X 座標
		this->dataGridView_History->default[3,currentRow]->Value = (String^)inputdata->GetValue(3);  // Y 座標
		this->dataGridView_History->default[4,currentRow]->Value = (String^)inputdata->GetValue(4);  // 長
		this->dataGridView_History->default[5,currentRow]->Value = (String^)inputdata->GetValue(5);  // 寬

}
void Cosmetic_LocalArea_Form::ArraytoData(ArrayList^ SurfaceArrayList , int index){

	//-----------------------------------------------------------------------
	//將ArrayList 中的資料顯示到輸入表單 .
	//-----------------------------------------------------------------------
	array<String^,1>^ inputdata = (array<String^,1>^)SurfaceArrayList->default[index];



	//區域參數輸入範圍
	this->cboPointLocation->SelectedIndex = Convert::ToInt16(inputdata[1]);
	this->txt_X_Value->Text = inputdata[2];
	this->txt_Y_Value->Text = inputdata[3];
	this->txt_Area_Length->Text = inputdata[4];
    this->txt_Area_Width->Text = inputdata[5];
	
	//重新定義hScrollBar Max Value :	
	this->hScrollBar_U_Value->Maximum = Convert::ToInt16(inputdata[12]);
	this->hScrollBar_V_Value->Maximum = Convert::ToInt16(inputdata[13]);




	this->hScrollBar_U_Value->Value =Convert::ToInt16(inputdata[6]);
	this->hScrollBar_V_Value->Value =Convert::ToInt16(inputdata[7]);

	//陣列數值

	this->cboArratDirection->SelectedIndex = Convert::ToInt16(inputdata[8]);
	this->txtArrayNumber->Text = inputdata[9];
	this->txtArrayDistance->Text =  inputdata[10];

	

	 //控制點數目和名稱

	this->txtSurfaceName->Text =  inputdata[11];
	this->txtNumX->Text =  inputdata[12];
	this->txtNumY->Text =  inputdata[13];



     //控制點數值

	 int count = 14;
	for(int jj = 0 ;jj < Convert::ToInt16(this->txtNumY->Text)  ; jj++){
		for(int ii = 0 ;ii < Convert::ToInt16(this->txtNumX->Text) ; ii++){
		

			this->dataGridView_ModifyPara->default[ii,jj]->Value = (String^)inputdata[count] ;
			count ++;
			this->dataGridControllPtWeight->default[ii,jj]->Value =  (String^)inputdata[count] ;			
			count ++;
			this->dataGrid_Cpt_X->default[ii,jj]->Value =(String^) inputdata[count] ;	
			count ++;
			this->dataGrid_Cpt_Y->default[ii,jj]->Value = (String^)inputdata[count] ;	
			count ++;
							
		}
	}





}
bool Cosmetic_LocalArea_Form::DatatoArray(int checkedItem){

	//-----------------------------------------------------------------------
	//將局部修改的輸入資料存入Array 中 ,然後用arrayList 容器接收這些資料 ...
	//-----------------------------------------------------------------------
	
	
	try{


		int number = Convert::ToInt16(this->txtNumX->Text) * Convert::ToInt16(this->txtNumY->Text) ;		
		this->InputData = gcnew array<String^,1>(14 +4*number );
        //增加啟用或不啟用的Item	
	//	 this->InputData = gcnew array<String^,1>(15 +4*number );


	
		//對應到DataGrid 的Index .
		int currentRow = this->dataGridView_History->RowCount + 1;
		this->InputData->SetValue(Convert::ToString(currentRow),0);

		 //區域參數輸入範圍
		
		this->InputData->SetValue(Convert::ToString(this->cboPointLocation->SelectedIndex),1);
		this->InputData->SetValue(this->txt_X_Value->Text,2);
		this->InputData->SetValue(this->txt_Y_Value->Text,3);
		this->InputData->SetValue(this->txt_Area_Length->Text,4);
		this->InputData->SetValue(this->txt_Area_Width->Text,5);
		this->InputData->SetValue(Convert::ToString(this->hScrollBar_U_Value->Value),6);
		this->InputData->SetValue(Convert::ToString(this->hScrollBar_V_Value->Value),7);
		

		//陣列數值
		if(this->txtArrayNumber->Text == "") this->txtArrayNumber->Text = "1";
		if(this->txtArrayNumber->Text == "1") this->txtArrayDistance->Text = "0";
		if(Convert::ToInt16(this->txtArrayNumber->Text) > 1 &&  this->txtArrayDistance->Text == ""){
			MessageBox::Show("請填入陣列距離~");
			return false;
		}

		
		this->InputData->SetValue(Convert::ToString(this->cboArratDirection->SelectedIndex),8);
		this->InputData->SetValue(this->txtArrayNumber->Text,9);
		this->InputData->SetValue(this->txtArrayDistance->Text,10);
		

		 //控制點數目和名稱

		this->InputData->SetValue(this->txtSurfaceName->Text,11);
		this->InputData->SetValue(this->txtNumX->Text,12);
		this->InputData->SetValue(this->txtNumY->Text,13);

	

		 int count = 14;
		 for(int jj = 0 ;jj < Convert::ToInt16(this->txtNumY->Text)  ; jj++){
			for(int ii = 0 ;ii < Convert::ToInt16(this->txtNumX->Text) ; ii++){
			 	
				this->InputData->SetValue(Convert::ToString(this->dataGridView_ModifyPara->default[ii,jj]->Value )->Trim() ,count);
				count ++;
				this->InputData->SetValue(Convert::ToString(this->dataGridControllPtWeight->default[ii,jj]->Value)->Trim() ,count);
				count ++;
				this->InputData->SetValue(Convert::ToString(this->dataGrid_Cpt_X->default[ii,jj]->Value)->Trim(),count);
				count ++;
				this->InputData->SetValue(Convert::ToString(this->dataGrid_Cpt_Y->default[ii,jj]->Value)->Trim(),count);
				count ++;
								

			}
		}

		 //將啟用與不啟用的數值填入 add 20110929		
		// this->InputData->SetValue(Convert::ToString(checkedItem),count);

		 return true;

	}catch(...){
		MessageBox::Show("資料輸入錯誤 !!");
		return false;
	}


};
/*
bool Cosmetic_LocalArea_Form::Input(){
/*
	 try{
				 //參數輸入Current InputData
				RectangleF tmpRec;
				tmpRec.Width = Convert::ToSingle(this->txt_Area_Length->Text);
				tmpRec.Height = Convert::ToSingle(this->txt_Area_Width->Text);
				switch (this->cboPointLocation->SelectedIndex){

					 case 0 : //左下
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text);
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text);
						 break;
					 case 1: //左上
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text);
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text)-tmpRec.Height;
						 break;
					 case 2: //右上
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text)-tmpRec.Width;
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text)-tmpRec.Height;
						 break;
					 case 3: //右下
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text)-tmpRec.Width;
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text);
						 break;
					 case 4: //中心 
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text)-tmpRec.Width/2;
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text)-tmpRec.Height/2;
						 break;

				 }



				this->tmpLocalData->Current_InputData->SetValue(this->cboPointLocation->SelectedIndex,0);
				this->tmpLocalData->Current_InputData->SetValue(tmpRec.X,1);
				this->tmpLocalData->Current_InputData->SetValue(tmpRec.Y,2);
				this->tmpLocalData->Current_InputData->SetValue(tmpRec.Width,3);
				this->tmpLocalData->Current_InputData->SetValue(tmpRec.Height,4);
				this->tmpLocalData->Current_InputData->SetValue((float)this->hScrollBar_U_Value->Value,5);
				this->tmpLocalData->Current_InputData->SetValue((float)this->hScrollBar_V_Value->Value,6);

				

				for(int ii = 0 ;ii< 5 ;ii++){
					 for(int jj = 0 ;jj < 5 ;jj++){
						 float tmpV = Convert::ToSingle(this->dataGridView_ModifyPara->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpV,7+ii*5+jj);

						 //權重
						 tmpV = Convert::ToSingle(this->dataGridControllPtWeight->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpV,35+ii*5+jj);  
						//控制點X
						 PointF tmpPt;
						 tmpPt.X = Convert::ToSingle(this->dataGrid_Cpt_X->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpPt.X,60+ii*5+jj);  
						//控制點Y
						 tmpPt.Y = Convert::ToSingle(this->dataGrid_Cpt_Y->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpPt.Y,85+ii*5+jj);  

					 }
				 }

				//----------------------------------------------

				//----------------------------------------------

			
				//陣列資料輸入
				this->tmpLocalData->Current_InputData->SetValue(this->cboArratDirection->SelectedIndex,32); //陣列方向
				this->tmpLocalData->Current_InputData->SetValue(Convert::ToInt16(this->txtArrayNumber->Text),33); //陣列數目
				this->tmpLocalData->Current_InputData->SetValue(Convert::ToSingle(this->txtArrayDistance->Text),34); //陣列距離


					
				



					 


				


				return true;

			 }catch(...){
				 MessageBox::Show("資料輸入錯誤");

				 return false;
			 }



}
*/