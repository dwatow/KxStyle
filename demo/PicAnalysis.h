#pragma once


#include "Calculate.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;



using namespace DensityClass; 

namespace PatternContruction {

	/// <summary>
	/// PicAnalysis 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class PicAnalysis : public System::Windows::Forms::Form
	{
	public:
		PicAnalysis(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~PicAnalysis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCalculate;
	protected: 

	protected: 
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  btnTransfer;
	private: System::Windows::Forms::PictureBox^  picTransfer;
	private: System::Windows::Forms::PictureBox^  picOri;
	private: System::Windows::Forms::TextBox^  txtRatioY;
	private: System::Windows::Forms::TextBox^  txtRatioX;


	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtMeshY;
	private: System::Windows::Forms::TextBox^  txtMeshX;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  btnLoad;



	private:
		/// <summary>
		/// 設計工具所需的變數。
			DensityClass::GridDensity^ Density;
			Bitmap^ image1;
			Bitmap^ image2;
			Rectangle SelectRange;
			bool SelectWindows;

			 Graphics^ pic ;


	private: System::Windows::Forms::Label^  lbl_Value;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  btnSelect;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnMeasure;


			 //void SetDensityColor(float density, float &R, float &G, float &B ,PointF DensityRange);
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->picTransfer = (gcnew System::Windows::Forms::PictureBox());
			this->picOri = (gcnew System::Windows::Forms::PictureBox());
			this->txtRatioY = (gcnew System::Windows::Forms::TextBox());
			this->txtRatioX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtMeshY = (gcnew System::Windows::Forms::TextBox());
			this->txtMeshX = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->lbl_Value = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnSelect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnMeasure = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picTransfer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picOri))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCalculate
			// 
			this->btnCalculate->Location = System::Drawing::Point(440, 347);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(72, 32);
			this->btnCalculate->TabIndex = 20;
			this->btnCalculate->Text = L"計算";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &PicAnalysis::btnCalculate_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(282, 106);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(260, 202);
			this->dataGridView1->TabIndex = 17;
			// 
			// btnTransfer
			// 
			this->btnTransfer->Enabled = false;
			this->btnTransfer->Location = System::Drawing::Point(129, 433);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(73, 32);
			this->btnTransfer->TabIndex = 14;
			this->btnTransfer->Text = L"轉換";
			this->btnTransfer->UseVisualStyleBackColor = true;
			this->btnTransfer->Visible = false;
			this->btnTransfer->Click += gcnew System::EventHandler(this, &PicAnalysis::btnTransfer_Click);
			// 
			// picTransfer
			// 
			this->picTransfer->BackColor = System::Drawing::Color::Black;
			this->picTransfer->Location = System::Drawing::Point(10, 219);
			this->picTransfer->Name = L"picTransfer";
			this->picTransfer->Size = System::Drawing::Size(253, 208);
			this->picTransfer->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picTransfer->TabIndex = 13;
			this->picTransfer->TabStop = false;
			this->picTransfer->MouseLeave += gcnew System::EventHandler(this, &PicAnalysis::picTransfer_MouseLeave);
			this->picTransfer->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PicAnalysis::picTransfer_MouseMove);
			this->picTransfer->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &PicAnalysis::picTransfer_MouseClick);
			this->picTransfer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PicAnalysis::picTransfer_MouseDown);
			this->picTransfer->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PicAnalysis::picTransfer_MouseUp);
			// 
			// picOri
			// 
			this->picOri->BackColor = System::Drawing::Color::Black;
			this->picOri->Location = System::Drawing::Point(10, 5);
			this->picOri->Name = L"picOri";
			this->picOri->Size = System::Drawing::Size(253, 208);
			this->picOri->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picOri->TabIndex = 12;
			this->picOri->TabStop = false;
			// 
			// txtRatioY
			// 
			this->txtRatioY->Location = System::Drawing::Point(388, 65);
			this->txtRatioY->Margin = System::Windows::Forms::Padding(4);
			this->txtRatioY->Name = L"txtRatioY";
			this->txtRatioY->Size = System::Drawing::Size(56, 22);
			this->txtRatioY->TabIndex = 48;
			this->txtRatioY->Text = L"0";
			// 
			// txtRatioX
			// 
			this->txtRatioX->Location = System::Drawing::Point(388, 39);
			this->txtRatioX->Margin = System::Windows::Forms::Padding(4);
			this->txtRatioX->Name = L"txtRatioX";
			this->txtRatioX->Size = System::Drawing::Size(56, 22);
			this->txtRatioX->TabIndex = 47;
			this->txtRatioX->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(280, 73);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 12);
			this->label7->TabIndex = 44;
			this->label7->Text = L"Y方向內縮";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(280, 49);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 12);
			this->label6->TabIndex = 43;
			this->label6->Text = L"X方向內縮";
			// 
			// txtMeshY
			// 
			this->txtMeshY->Location = System::Drawing::Point(447, 13);
			this->txtMeshY->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshY->Name = L"txtMeshY";
			this->txtMeshY->Size = System::Drawing::Size(61, 22);
			this->txtMeshY->TabIndex = 42;
			this->txtMeshY->Text = L"5";
			// 
			// txtMeshX
			// 
			this->txtMeshX->Location = System::Drawing::Point(388, 13);
			this->txtMeshX->Margin = System::Windows::Forms::Padding(4);
			this->txtMeshX->Name = L"txtMeshX";
			this->txtMeshX->Size = System::Drawing::Size(56, 22);
			this->txtMeshX->TabIndex = 41;
			this->txtMeshX->Text = L"5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(280, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 12);
			this->label5->TabIndex = 40;
			this->label5->Text = L"網格數";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &PicAnalysis::openFileDialog1_FileOk);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(282, 347);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(73, 32);
			this->btnLoad->TabIndex = 49;
			this->btnLoad->Text = L"載入";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &PicAnalysis::btnLoad_Click);
			// 
			// lbl_Value
			// 
			this->lbl_Value->AutoSize = true;
			this->lbl_Value->Location = System::Drawing::Point(12, 442);
			this->lbl_Value->Name = L"lbl_Value";
			this->lbl_Value->Size = System::Drawing::Size(71, 12);
			this->lbl_Value->TabIndex = 50;
			this->lbl_Value->Text = L"相對亮度值 :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(451, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 12);
			this->label1->TabIndex = 51;
			this->label1->Text = L"%";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(451, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 12);
			this->label2->TabIndex = 52;
			this->label2->Text = L"%";
			// 
			// progressBar1
			// 
			this->progressBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->progressBar1->Location = System::Drawing::Point(0, 475);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(572, 20);
			this->progressBar1->TabIndex = 53;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->Location = System::Drawing::Point(288, 385);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(146, 57);
			this->richTextBox1->TabIndex = 54;
			this->richTextBox1->Text = L"相對亮度值僅為參考用\n";
			// 
			// btnSelect
			// 
			this->btnSelect->Enabled = false;
			this->btnSelect->Location = System::Drawing::Point(361, 347);
			this->btnSelect->Name = L"btnSelect";
			this->btnSelect->Size = System::Drawing::Size(72, 32);
			this->btnSelect->TabIndex = 55;
			this->btnSelect->Text = L"窗選";
			this->btnSelect->UseVisualStyleBackColor = true;
			this->btnSelect->Click += gcnew System::EventHandler(this, &PicAnalysis::btnSelect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(291, 322);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 12);
			this->label3->TabIndex = 56;
			this->label3->Text = L"平均值  :";
			// 
			// btnMeasure
			// 
			this->btnMeasure->Enabled = false;
			this->btnMeasure->Location = System::Drawing::Point(440, 385);
			this->btnMeasure->Name = L"btnMeasure";
			this->btnMeasure->Size = System::Drawing::Size(72, 32);
			this->btnMeasure->TabIndex = 57;
			this->btnMeasure->Text = L"尺寸量測";
			this->btnMeasure->UseVisualStyleBackColor = true;
			this->btnMeasure->Click += gcnew System::EventHandler(this, &PicAnalysis::btnMeasure_Click);
			// 
			// PicAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 495);
			this->Controls->Add(this->btnMeasure);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnSelect);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_Value);
			this->Controls->Add(this->btnLoad);
			this->Controls->Add(this->txtRatioY);
			this->Controls->Add(this->txtRatioX);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtMeshY);
			this->Controls->Add(this->txtMeshX);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnTransfer);
			this->Controls->Add(this->picTransfer);
			this->Controls->Add(this->picOri);
			this->Name = L"PicAnalysis";
			this->Text = L"PicAnalysis";
			this->Load += gcnew System::EventHandler(this, &PicAnalysis::PicAnalysis_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picTransfer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picOri))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnTransfer_Click(System::Object^  sender, System::EventArgs^  e) {

				 			


		



			 }
private: System::Void PicAnalysis_Load(System::Object^  sender, System::EventArgs^  e) {

			 this->btnCalculate->Enabled = false;
			 this->btnTransfer->Enabled = false;

			  pic = this->picTransfer->CreateGraphics();


			 


		 }

private: System::Void btnCalculate_Click(System::Object^  sender, System::EventArgs^  e) {


			  //Density 密度
				 Point Mesh = this->Density->GetMeshNumber();

				 SolidBrush^ eBrush = gcnew SolidBrush(Color::Red );
				


				 int NumX = Convert::ToUInt16(this->txtMeshX->Text);
				 int NumY = Convert::ToInt16(this->txtMeshY->Text);
				 int RatioX ;int RatioY;

				 PointF Scale((float)this->SelectRange.Width/(float)this->picTransfer->Width,(float)this->SelectRange.Height/(float)picTransfer->Height);
								

				
				

				
				//窗選後的範圍 :
				 Mesh.X =(int)( Mesh.X*Scale.X);
				 Mesh.Y= (int)( Mesh.Y*Scale.Y);

				//窗選後的起始點 :
				 Point stPt((int)(this->SelectRange.X*Scale.X),(int)(this->SelectRange.Y*Scale.Y));


				float rX = Convert::ToSingle(this->txtRatioX->Text)/100.f;
				float rY = Convert::ToSingle(this->txtRatioY->Text)/100.f;
				
				RatioX =(int) (Convert::ToSingle(this->txtRatioX->Text)*Mesh.X/100.f);
				RatioY =(int) (Convert::ToSingle(this->txtRatioY->Text)*Mesh.Y/100.f);

				 




				 if(NumX <2 || NumY <2){
					 MessageBox::Show("數值不能夠小於2!!");					 
				 }else {
					this->dataGridView1->ColumnCount::set(NumX);
					this->dataGridView1->RowCount::set(NumY);
					
					 pic->DrawImage(this->image2,Rectangle(0,0,this->picTransfer->Width,this->picTransfer->Height)); 

					 float value = 0;

					for(int ii = 0 ; ii < NumX ; ii ++){
						for(int jj = 0 ;jj < NumY ;jj ++){
							
							int a = stPt.X  + RatioX + (int)((float)(Mesh.X-1-2*RatioX)/(float)(NumX-1)*(float)ii); // 一定要用float ,不然整數除以整數數值會有問題
							int b = stPt.Y  + RatioY + (int)((float)(Mesh.Y-1-2*RatioY)/(float)(NumY-1)*(float)jj); // 一定要用float ,不然整數除以整數數值會有問題							
							float Z = 0;	
						//	Point Index(a ,b);
						//	Z = this->Density->GetDensityValue(Index);
						//	this->dataGridView1->default[ii,jj]->Value = String::Format("{0:0.000}",100*Z);
							

	
							

							

							int coordX = this->SelectRange.X +(int)(rX*this->SelectRange.Width) +  this->SelectRange.Width*(1-2*rX)*ii/(NumX-1.0f);
							int coordY = this->SelectRange.Y +(int)(rY*this->SelectRange.Height) + this->SelectRange.Height*(1-2*rY)*jj/(NumY-1.0f);
					
							pic->FillEllipse(eBrush,coordX-2.5,coordY-2.5,5,5);

							int denX = coordX/(float)this->picTransfer->Width*this->Density->GetMeshNumber().X;
							int denY = coordY/(float)this->picTransfer->Height*this->Density->GetMeshNumber().Y;
							Point Index(denX ,denY);
							Z = this->Density->GetDensityValue(Index);
							this->dataGridView1->default[ii,jj]->Value = String::Format("{0:0.000}",100*Z);

							value = value + 100*Z;


							
																	 
						 }
					}

					value = value/(float)(NumX)/(float)(NumY);

					this->label3->Text = "平均值為 : " + Convert::ToString(value);
				 }


			 

				 



		 }
private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) {

			   openFileDialog1->FileName = "PictureFile";
				openFileDialog1->Filter = "圖片 (*.jpg)|*.jpg";
				openFileDialog1->FilterIndex = 1;
				openFileDialog1->RestoreDirectory = true;
				openFileDialog1->DefaultExt=".jpg";
				openFileDialog1->InitialDirectory = Directory::GetCurrentDirectory();	

				
				openFileDialog1->ShowDialog();


				




			
			


		 }
private: System::Void picTransfer_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
//*
			
			 Pen^ ePen = gcnew Pen( Color::Red,0.1f/25.4f );
			


			
			 
			

			  if(this->Density != nullptr){
				   Point Mesh = this->Density->GetMeshNumber();
				  // if(e->X >0 ,e->Y >0 && e->X <Mesh.X && e->Y < Mesh.Y ) { 
					 //  int denX = e->X/(float)this->picTransfer->Width*this->image2->Width;
					 //  int denY = e->Y/(float)this->picTransfer->Height*this->image2->Height;
					 
					  // Color pixelcolor = image2->GetPixel(denX,denY);
					  // float value = (0.299f * pixelcolor.R + 0.587f * pixelcolor.G + 0.114f * pixelcolor.B)/255.0f;
					  //  this->lbl_Value->Text ="相對亮度值 : "  + Convert::ToString(value);
					//  }
				  if(SelectWindows == true && this->SelectRange.IsEmpty == false ){
							
					  pic->DrawImage(this->image2,Rectangle(0,0,this->picTransfer->Width,this->picTransfer->Height));  					

					this->SelectRange.Width = e->X- this->SelectRange.X;
					this->SelectRange.Height = e->Y - this->SelectRange.Y;		
					if(this->SelectRange.Width > 0 && this->SelectRange.Height>0) {
						pic->DrawRectangle(ePen,this->SelectRange);
					}

					
					
				

				   }				
				  
			  }
 // */
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {



			if(openFileDialog1->CheckFileExists == true){

					
				image1 = gcnew Bitmap(openFileDialog1->FileName,true );
				image2 = gcnew Bitmap(image1->Width,image1->Height);
			
				


					//檔案轉換

					this->progressBar1->Value = 0 ;
					RectangleF Range(PointF(0,0) ,this->picTransfer->Size);
					Point Pixel(image1->Width,image1->Height);
					this->Density = gcnew GridDensity(Pixel,Range);
				
					 for(int ii= 0 ; ii <image1->Width ;ii++){
						 for(int jj = 0 ; jj <image1->Height ; jj++){
							 Color pixelcolor = image1->GetPixel(ii,jj);
							 float value = (0.299f * pixelcolor.R + 0.587f * pixelcolor.G + 0.114f * pixelcolor.B)/255.0f;
							 this->Density->SetDensityValue(value,Point(ii,jj));
							 float R,G,B;
							 //PointF denboundary(100.0f,0.0f);					 
							 SetDensityColor(value,R,G,B);
							 Color newColor = Color::FromArgb((int) R,(int) G,(int) B );
							 image2->SetPixel( ii, jj, newColor );
							this->progressBar1->Value = 100*ii/(image1->Width) ;
							
							
						 }
					 }
					 
					 this->picOri->Image = image1;
					 this->picTransfer->Image = image2;
					 //this->btnCalculate->Enabled = true;
					 this->btnSelect->Enabled = true;






				}






			  

		 }
private: System::Void picTransfer_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
		 }
private: System::Void btnSelect_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->richTextBox1->Text = " 進行窗選,請選擇左上點!";
			 SelectWindows = true;
			 this->SelectRange = Rectangle(0,0,0,0);
			 this->btnCalculate->Enabled = false;
			 
			 



		 }
private: System::Void picTransfer_MouseLeave(System::Object^  sender, System::EventArgs^  e) {


		 }
private: System::Void picTransfer_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if(SelectWindows == true){
				this->richTextBox1->Text = " 左上點已選擇 !";
				this->SelectRange.X = e->X;
				this->SelectRange.Y = e->Y;
				
				
			}
		 }
private: System::Void picTransfer_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			
			 if(SelectWindows == true && this->SelectRange.IsEmpty == false) {
				
				
				int tmpWidth = e->X- this->SelectRange.X;
				int tmpHeight = e->Y - this->SelectRange.Y;
				
				if (tmpWidth <= 0 || tmpHeight <= 0) {
					this->SelectRange.Empty;
					this->richTextBox1->Text = " 取消窗選 !";

				}
				else {
					this->SelectRange.Width = tmpWidth;
					this->SelectRange.Height = tmpHeight;
					this->btnCalculate->Enabled = true;
					this->richTextBox1->Text = " 窗選結束 !";
				}				
				//this->SelectRange = this->picTransfer->RectangleToScreen(this->SelectRange);				

			}
			 SelectWindows = false;
		 }
private: System::Void btnMeasure_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
