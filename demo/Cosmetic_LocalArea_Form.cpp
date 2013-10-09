#include "StdAfx.h"
#include "Cosmetic_LocalArea_Form.h"
using namespace std;
using namespace PatternContruction;



array<String^>^ Cosmetic_LocalArea_Form::ToSurfaceInputData(array<String^,1>^ data){

	//--------------------------------------------------------------------------------------------------
	//�Narraylist �e��������J�ѼƸ���ର Surface �i�H���������...
	//Surface �w�q��ƬO Index 0 ->Name;
	//Surface �w�q��ƬO Index 1 ->U Value (���ƫ�X);
	//Surface �w�q��ƬO Index 2 ->V Value (���ƫ�Y);
	//Surface �w�q��ƬO Index 3 ->�ѪR�� X;
	//Surface �w�q��ƬO Index 4 ->�ѪR�� Y;
	//Surface �w�q��ƬO Index 5 ->�����I��X ;
	//Surface �w�q��ƬO Index 6 ->�����I��Y ;
	//Surface Index 7 �H�᪺�}�C��ƬO :
	// count + 0 -> �����I�y��X  ,count + 1 --> �����I�y��Y ,count + 2 --> Z Value ,count + 3 ->�v�� 
	//--------------------------------------------------------------------------------------------------
	// ArrayList ������ƬO ...(����ƬO�����ק諸���)
	// Index 0 --> ��ƦbDataGrid �����޼ƭ�
	// Index 1 -->�y�Щw�q�覡(���W,�k�W ,...)
	// Index 2 --> X �y��
	// Index 3 --> Y �y��
	// Index 4 --> X ��V�j�p
	// Index 5 --> Y ��V�j�p
	// Index 6 -->U_Value (���ƫ�X)
	// Index 7 -->V_Value (���ƫ�Y)
	// Index 8 -->�}�C��V (+X ,-X ,...)
	// Index 9 -->�}�C�ƥ� 
	// Index 10 -->�}�CPitch
	// Index 11 -->�W�� 
	// Index 12 -->�����IX  
	// Index 13 -->�����IY 
	// Index 14 �H�᪺�}�C��ƬO :
	// count + 0 -> Z Value   ,count + 1 --> �v�� ,count + 2 --> X�y�� ,count + 3 ->Y�y�� 
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

	//surfacedata->SetValue(forminputdata->GetValue(11),0); ->������Name....
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
				location = "���U�I(X,Y) :";
			break;
			case 1:
				location = "���W�I(X,Y) :";
			break;
			case 2:
				location = "�k�W�I(X,Y) :";
			break;
			case 3:
				location = "�k�U�I(X,Y) :";
			break;
			case 4:
				location = "�����I(X,Y) :";
			break;
			case 5:
				location = "�����I(X,Y) :";
			break;
			case 6:
				location = "�k���I(X,Y) :";
			break;
			case 7:
				location = "�W���I(X,Y) :";
			break;
			case 8:
				location = "�U���I(X,Y) :";
			break;


		}

		//this->dataGridView_History->default[1,currentRow]->Value = (String^)inputdata->GetValue(2); //�ҥΩΤ��ҥ�
		this->dataGridView_History->default[1,currentRow]->Value = location;  //�y�Ц�m
		this->dataGridView_History->default[2,currentRow]->Value = (String^)inputdata->GetValue(2);  // X �y��
		this->dataGridView_History->default[3,currentRow]->Value = (String^)inputdata->GetValue(3);  // Y �y��
		this->dataGridView_History->default[4,currentRow]->Value = (String^)inputdata->GetValue(4);  // ��
		this->dataGridView_History->default[5,currentRow]->Value = (String^)inputdata->GetValue(5);  // �e

}
void Cosmetic_LocalArea_Form::ArraytoData(ArrayList^ SurfaceArrayList , int index){

	//-----------------------------------------------------------------------
	//�NArrayList ���������ܨ��J��� .
	//-----------------------------------------------------------------------
	array<String^,1>^ inputdata = (array<String^,1>^)SurfaceArrayList->default[index];



	//�ϰ�Ѽƿ�J�d��
	this->cboPointLocation->SelectedIndex = Convert::ToInt16(inputdata[1]);
	this->txt_X_Value->Text = inputdata[2];
	this->txt_Y_Value->Text = inputdata[3];
	this->txt_Area_Length->Text = inputdata[4];
    this->txt_Area_Width->Text = inputdata[5];
	
	//���s�w�qhScrollBar Max Value :	
	this->hScrollBar_U_Value->Maximum = Convert::ToInt16(inputdata[12]);
	this->hScrollBar_V_Value->Maximum = Convert::ToInt16(inputdata[13]);




	this->hScrollBar_U_Value->Value =Convert::ToInt16(inputdata[6]);
	this->hScrollBar_V_Value->Value =Convert::ToInt16(inputdata[7]);

	//�}�C�ƭ�

	this->cboArratDirection->SelectedIndex = Convert::ToInt16(inputdata[8]);
	this->txtArrayNumber->Text = inputdata[9];
	this->txtArrayDistance->Text =  inputdata[10];

	

	 //�����I�ƥةM�W��

	this->txtSurfaceName->Text =  inputdata[11];
	this->txtNumX->Text =  inputdata[12];
	this->txtNumY->Text =  inputdata[13];



     //�����I�ƭ�

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
	//�N�����ק諸��J��Ʀs�JArray �� ,�M���arrayList �e�������o�Ǹ�� ...
	//-----------------------------------------------------------------------
	
	
	try{


		int number = Convert::ToInt16(this->txtNumX->Text) * Convert::ToInt16(this->txtNumY->Text) ;		
		this->InputData = gcnew array<String^,1>(14 +4*number );
        //�W�[�ҥΩΤ��ҥΪ�Item	
	//	 this->InputData = gcnew array<String^,1>(15 +4*number );


	
		//������DataGrid ��Index .
		int currentRow = this->dataGridView_History->RowCount + 1;
		this->InputData->SetValue(Convert::ToString(currentRow),0);

		 //�ϰ�Ѽƿ�J�d��
		
		this->InputData->SetValue(Convert::ToString(this->cboPointLocation->SelectedIndex),1);
		this->InputData->SetValue(this->txt_X_Value->Text,2);
		this->InputData->SetValue(this->txt_Y_Value->Text,3);
		this->InputData->SetValue(this->txt_Area_Length->Text,4);
		this->InputData->SetValue(this->txt_Area_Width->Text,5);
		this->InputData->SetValue(Convert::ToString(this->hScrollBar_U_Value->Value),6);
		this->InputData->SetValue(Convert::ToString(this->hScrollBar_V_Value->Value),7);
		

		//�}�C�ƭ�
		if(this->txtArrayNumber->Text == "") this->txtArrayNumber->Text = "1";
		if(this->txtArrayNumber->Text == "1") this->txtArrayDistance->Text = "0";
		if(Convert::ToInt16(this->txtArrayNumber->Text) > 1 &&  this->txtArrayDistance->Text == ""){
			MessageBox::Show("�ж�J�}�C�Z��~");
			return false;
		}

		
		this->InputData->SetValue(Convert::ToString(this->cboArratDirection->SelectedIndex),8);
		this->InputData->SetValue(this->txtArrayNumber->Text,9);
		this->InputData->SetValue(this->txtArrayDistance->Text,10);
		

		 //�����I�ƥةM�W��

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

		 //�N�ҥλP���ҥΪ��ƭȶ�J add 20110929		
		// this->InputData->SetValue(Convert::ToString(checkedItem),count);

		 return true;

	}catch(...){
		MessageBox::Show("��ƿ�J���~ !!");
		return false;
	}


};
/*
bool Cosmetic_LocalArea_Form::Input(){
/*
	 try{
				 //�Ѽƿ�JCurrent InputData
				RectangleF tmpRec;
				tmpRec.Width = Convert::ToSingle(this->txt_Area_Length->Text);
				tmpRec.Height = Convert::ToSingle(this->txt_Area_Width->Text);
				switch (this->cboPointLocation->SelectedIndex){

					 case 0 : //���U
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text);
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text);
						 break;
					 case 1: //���W
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text);
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text)-tmpRec.Height;
						 break;
					 case 2: //�k�W
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text)-tmpRec.Width;
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text)-tmpRec.Height;
						 break;
					 case 3: //�k�U
						tmpRec.X = Convert::ToSingle(this->txt_X_Value->Text)-tmpRec.Width;
						tmpRec.Y = Convert::ToSingle(this->txt_Y_Value->Text);
						 break;
					 case 4: //���� 
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

						 //�v��
						 tmpV = Convert::ToSingle(this->dataGridControllPtWeight->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpV,35+ii*5+jj);  
						//�����IX
						 PointF tmpPt;
						 tmpPt.X = Convert::ToSingle(this->dataGrid_Cpt_X->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpPt.X,60+ii*5+jj);  
						//�����IY
						 tmpPt.Y = Convert::ToSingle(this->dataGrid_Cpt_Y->default[ii,jj]->Value);
						 this->tmpLocalData->Current_InputData->SetValue(tmpPt.Y,85+ii*5+jj);  

					 }
				 }

				//----------------------------------------------

				//----------------------------------------------

			
				//�}�C��ƿ�J
				this->tmpLocalData->Current_InputData->SetValue(this->cboArratDirection->SelectedIndex,32); //�}�C��V
				this->tmpLocalData->Current_InputData->SetValue(Convert::ToInt16(this->txtArrayNumber->Text),33); //�}�C�ƥ�
				this->tmpLocalData->Current_InputData->SetValue(Convert::ToSingle(this->txtArrayDistance->Text),34); //�}�C�Z��


					
				



					 


				


				return true;

			 }catch(...){
				 MessageBox::Show("��ƿ�J���~");

				 return false;
			 }



}
*/