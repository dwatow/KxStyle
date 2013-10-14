#pragma once
#include "DataStructure.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace DensityClass;

namespace PatternContruction {

	/// <summary>
	/// ScreenMura 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class ScreenMura : public System::Windows::Forms::Form
	{
	public:
		ScreenMura(Pattern^ Dot ,GridDensity^ ScreenMura , RectangleF LGPRange ,Point GirdNumber ,int Pattern_Arrangment)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			tmpDot = Dot;
			tmpScreenMura = ScreenMura;
			tmpLGPRange = LGPRange;
			tmpGridNumber = GirdNumber;
		    tmpPattern_Arrangment = Pattern_Arrangment ;

		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~ScreenMura()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::TextBox^  txtScreenAngle;
	private: System::Windows::Forms::TextBox^  txtStartPos;




	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		Pattern^ tmpDot;
		GridDensity^ tmpScreenMura;
		GridDensity^ tmpDifData;
		RectangleF tmpLGPRange;
		Point tmpGridNumber;
		int tmpPattern_Arrangment;
		

	private: System::Windows::Forms::TextBox^  txtStartPosY;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  cboScreenSpec;
	private: System::Windows::Forms::TextBox^  txtLayerThick;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtMeshVariation;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnCalGap;
	private: System::Windows::Forms::Label^  lbl_Gap;
	private: System::Windows::Forms::HScrollBar^  Disturb_ScrollBarValue;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btnWave;
	private: System::Windows::Forms::ComboBox^  cboWaveDirection;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txt_Range;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtperiod;




			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
	//	float CalculateMuraValue(PointF DotCoordinate,float DotDiameter);







		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtScreenAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtStartPos = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtStartPosY = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cboScreenSpec = (gcnew System::Windows::Forms::ComboBox());
			this->txtLayerThick = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtMeshVariation = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnCalGap = (gcnew System::Windows::Forms::Button());
			this->lbl_Gap = (gcnew System::Windows::Forms::Label());
			this->Disturb_ScrollBarValue = (gcnew System::Windows::Forms::HScrollBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btnWave = (gcnew System::Windows::Forms::Button());
			this->cboWaveDirection = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_Range = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtperiod = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"網紗角度";
			// 
			// txtScreenAngle
			// 
			this->txtScreenAngle->Location = System::Drawing::Point(110, 71);
			this->txtScreenAngle->Name = L"txtScreenAngle";
			this->txtScreenAngle->Size = System::Drawing::Size(65, 22);
			this->txtScreenAngle->TabIndex = 6;
			this->txtScreenAngle->Text = L"33";
			// 
			// txtStartPos
			// 
			this->txtStartPos->Location = System::Drawing::Point(264, 46);
			this->txtStartPos->Name = L"txtStartPos";
			this->txtStartPos->Size = System::Drawing::Size(65, 22);
			this->txtStartPos->TabIndex = 7;
			this->txtStartPos->Text = L"0";
			this->txtStartPos->Visible = false;
			this->txtStartPos->TextChanged += gcnew System::EventHandler(this, &ScreenMura::txtStartPos_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 137);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 25);
			this->button1->TabIndex = 8;
			this->button1->Text = L"計算分析";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ScreenMura::button1_Click);
			// 
			// txtStartPosY
			// 
			this->txtStartPosY->Location = System::Drawing::Point(335, 46);
			this->txtStartPosY->Name = L"txtStartPosY";
			this->txtStartPosY->Size = System::Drawing::Size(65, 22);
			this->txtStartPosY->TabIndex = 10;
			this->txtStartPosY->Text = L"0";
			this->txtStartPosY->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 25);
			this->button2->TabIndex = 12;
			this->button2->Text = L"網點擾動";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ScreenMura::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 12);
			this->label6->TabIndex = 13;
			this->label6->Text = L"乳劑厚";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 12);
			this->label7->TabIndex = 14;
			this->label7->Text = L"網紗規格";
			// 
			// cboScreenSpec
			// 
			this->cboScreenSpec->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboScreenSpec->FormattingEnabled = true;
			this->cboScreenSpec->Location = System::Drawing::Point(110, 17);
			this->cboScreenSpec->Name = L"cboScreenSpec";
			this->cboScreenSpec->Size = System::Drawing::Size(97, 20);
			this->cboScreenSpec->TabIndex = 15;
			// 
			// txtLayerThick
			// 
			this->txtLayerThick->Location = System::Drawing::Point(110, 99);
			this->txtLayerThick->Name = L"txtLayerThick";
			this->txtLayerThick->Size = System::Drawing::Size(65, 22);
			this->txtLayerThick->TabIndex = 16;
			this->txtLayerThick->Text = L"15";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(181, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 12);
			this->label1->TabIndex = 17;
			this->label1->Text = L"(um)";
			this->label1->Click += gcnew System::EventHandler(this, &ScreenMura::label1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->progressBar1->Location = System::Drawing::Point(0, 269);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(427, 18);
			this->progressBar1->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 12);
			this->label2->TabIndex = 20;
			this->label2->Text = L"網紗變異(+/- 3%)";
			// 
			// txtMeshVariation
			// 
			this->txtMeshVariation->Location = System::Drawing::Point(110, 43);
			this->txtMeshVariation->Name = L"txtMeshVariation";
			this->txtMeshVariation->Size = System::Drawing::Size(65, 22);
			this->txtMeshVariation->TabIndex = 21;
			this->txtMeshVariation->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(179, 46);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 12);
			this->label8->TabIndex = 22;
			this->label8->Text = L"(%)";
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(6, 230);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(80, 25);
			this->btnClose->TabIndex = 23;
			this->btnClose->Text = L"離開";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &ScreenMura::btnClose_Click);
			// 
			// btnCalGap
			// 
			this->btnCalGap->Location = System::Drawing::Point(335, 12);
			this->btnCalGap->Name = L"btnCalGap";
			this->btnCalGap->Size = System::Drawing::Size(80, 25);
			this->btnCalGap->TabIndex = 24;
			this->btnCalGap->Text = L"Gap 計算";
			this->btnCalGap->UseVisualStyleBackColor = true;
			this->btnCalGap->Visible = false;
			this->btnCalGap->Click += gcnew System::EventHandler(this, &ScreenMura::btnCalGap_Click);
			// 
			// lbl_Gap
			// 
			this->lbl_Gap->AutoSize = true;
			this->lbl_Gap->Location = System::Drawing::Point(275, 18);
			this->lbl_Gap->Name = L"lbl_Gap";
			this->lbl_Gap->Size = System::Drawing::Size(48, 12);
			this->lbl_Gap->TabIndex = 25;
			this->lbl_Gap->Text = L"最小Gap";
			this->lbl_Gap->Visible = false;
			// 
			// Disturb_ScrollBarValue
			// 
			this->Disturb_ScrollBarValue->LargeChange = 1;
			this->Disturb_ScrollBarValue->Location = System::Drawing::Point(146, 171);
			this->Disturb_ScrollBarValue->Maximum = 5;
			this->Disturb_ScrollBarValue->Minimum = 1;
			this->Disturb_ScrollBarValue->Name = L"Disturb_ScrollBarValue";
			this->Disturb_ScrollBarValue->Size = System::Drawing::Size(126, 13);
			this->Disturb_ScrollBarValue->TabIndex = 62;
			this->Disturb_ScrollBarValue->Value = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(93, 171);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 12);
			this->label9->TabIndex = 63;
			this->label9->Text = L"程度 : 高";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(275, 172);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 12);
			this->label10->TabIndex = 64;
			this->label10->Text = L"低";
			// 
			// btnWave
			// 
			this->btnWave->Location = System::Drawing::Point(6, 196);
			this->btnWave->Name = L"btnWave";
			this->btnWave->Size = System::Drawing::Size(80, 25);
			this->btnWave->TabIndex = 65;
			this->btnWave->Text = L"Wave擾動";
			this->btnWave->UseVisualStyleBackColor = true;
			this->btnWave->Click += gcnew System::EventHandler(this, &ScreenMura::btnWave_Click);
			// 
			// cboWaveDirection
			// 
			this->cboWaveDirection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboWaveDirection->FormattingEnabled = true;
			this->cboWaveDirection->Location = System::Drawing::Point(92, 199);
			this->cboWaveDirection->Name = L"cboWaveDirection";
			this->cboWaveDirection->Size = System::Drawing::Size(69, 20);
			this->cboWaveDirection->TabIndex = 66;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(172, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 12);
			this->label4->TabIndex = 67;
			this->label4->Text = L"振幅";
			// 
			// txt_Range
			// 
			this->txt_Range->Location = System::Drawing::Point(207, 197);
			this->txt_Range->Name = L"txt_Range";
			this->txt_Range->Size = System::Drawing::Size(36, 22);
			this->txt_Range->TabIndex = 68;
			this->txt_Range->Text = L"0.08";
			this->txt_Range->TextChanged += gcnew System::EventHandler(this, &ScreenMura::textBox1_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(249, 202);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 12);
			this->label5->TabIndex = 69;
			this->label5->Text = L"週期";
			// 
			// txtperiod
			// 
			this->txtperiod->Location = System::Drawing::Point(284, 197);
			this->txtperiod->Name = L"txtperiod";
			this->txtperiod->Size = System::Drawing::Size(36, 22);
			this->txtperiod->TabIndex = 70;
			this->txtperiod->Text = L"15";
			// 
			// ScreenMura
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 287);
			this->Controls->Add(this->txtperiod);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txt_Range);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cboWaveDirection);
			this->Controls->Add(this->btnWave);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Disturb_ScrollBarValue);
			this->Controls->Add(this->lbl_Gap);
			this->Controls->Add(this->btnCalGap);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->txtMeshVariation);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtLayerThick);
			this->Controls->Add(this->cboScreenSpec);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->txtStartPosY);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtStartPos);
			this->Controls->Add(this->txtScreenAngle);
			this->Controls->Add(this->label3);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ScreenMura";
			this->Text = L"ScreenMura";
			this->Load += gcnew System::EventHandler(this, &ScreenMura::ScreenMura_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ScreenMura_Load(System::Object^  sender, System::EventArgs^  e) {
				 

				 if(this->cboScreenSpec->Items->Count != 4){
					 this->cboScreenSpec->Items->Add("NBC 305S#");
					 this->cboScreenSpec->Items->Add("NBC 315T#");
					 this->cboScreenSpec->Items->Add("NBC 315S#");
					 this->cboScreenSpec->Items->Add("NBC 420S#");
					 this->cboScreenSpec->SelectedIndex::set(0);
				 }

				 this->cboWaveDirection->Items->Add("X方向波動");
				 this->cboWaveDirection->Items->Add("Y方向波動");
				 this->cboWaveDirection->SelectedIndex::set(0);

				 


				 

			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


			 float StartPosX = Convert::ToSingle(this->txtStartPos->Text);
			 float StartPosY = Convert::ToSingle(this->txtStartPosY->Text);
			 float angle = Convert::ToSingle(this->txtScreenAngle->Text)*(float)Math::PI/180;  //角度
			 float LayerThick = Convert::ToSingle(this->txtLayerThick->Text)/1000;   //乳後


			 float ScreenPitch; //= Convert::ToSingle(this->txtScreenPitch->Text);  // 開孔  + 縣境
			 float ScreenThick; //= Convert::ToSingle(this->txtScreenThick->Text); //縣境 
			 float ScreenThink_2;    //沙厚

			 float meshVary =  Convert::ToSingle(this->txtMeshVariation->Text);

			 switch(this->cboScreenSpec->SelectedIndex){
					case 0: //305S
						ScreenThick = 0.03f;	
						ScreenPitch = 0.083f*(1.0f+0.01f*meshVary);   //0.03 + 0.053
						ScreenThink_2 = 0.046f;
				
						break;
					case 1: //315T
						ScreenThick = 0.03f;	
						ScreenPitch = 0.079f*(1.0f+0.01f*meshVary);
						ScreenThink_2 = 0.045f;
						break;
					case 2: //315S
						ScreenThick = 0.027f;	
						ScreenPitch = 0.081f*(1.0f+0.01f*meshVary); //0.027+0.054
						ScreenThink_2 = 0.04f;
						break;
					case 3: //420S
						ScreenThick = 0.027f;	
						ScreenPitch = 0.057f*(1.0f+0.01f*meshVary); //0.027+0.03
						ScreenThink_2 = 0.04f;
						break;
			 }

			



			

			

			 array<float>^ Decrease_Area = gcnew array<float>(this->tmpDot->GetDotNumber()) ;
			 array<float>^ Layer_Area = gcnew array<float>(this->tmpDot->GetDotNumber()) ;
			 this->tmpDot->MuraValue = gcnew array<float>(this->tmpDot->GetDotNumber());

			 Point number = tmpScreenMura->GetMeshNumber();
				tmpDifData = gcnew GridDensity(number,tmpLGPRange);





			 // 進行網紋分析  X 方向

			 //*

				 for(int kk = 0 ; kk < 1 ; kk ++){



					for(int ii = 0 ; ii <number.X ;ii++){
						for(int jj = 0 ; jj <number.Y ;jj++){
							this->tmpScreenMura->SetDensityValue(0.0f,Point(ii,jj));
						}
					}
				 
			 		
					for(int ii = 0 ; ii <number.X ;ii++){
						for(int jj = 0 ; jj <number.Y ;jj++){
							tmpDifData->SetDensityValue(0.0f,Point(ii,jj));
						}
					}
					
					 for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
						Decrease_Area[ii] = 0;
						Layer_Area[ii] = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]*(float)Math::PI/4;

						
					 }




			//		StartPosX = StartPosX + 0.01f ;


			


					 this->progressBar1->Value::set(0);

					 for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
					

					this->progressBar1->Value::set(ii*100/(this->tmpDot->GetDotNumber()-1));
					this->progressBar1->Update();

					 PointF Coordinate ;
					 //座標轉換
					 Coordinate.X = (float)Math::Cos(angle)*this->tmpDot->Dot_Coordinate[ii].X - (float)Math::Sin(angle)*this->tmpDot->Dot_Coordinate[ii].Y ;
					 Coordinate.Y = (float)Math::Sin(angle)*this->tmpDot->Dot_Coordinate[ii].X + (float)Math::Cos(angle)*this->tmpDot->Dot_Coordinate[ii].Y ;



					float oriArea = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]*(float)Math::PI/4;


					
					// X 方向參數
					

					//*

					float h1 ;
					float h2 ;
					float line1 ;
					float line2 ;
					int tmp ;
					float dis ;

					dis = fabs(StartPosX - (Coordinate.X-this->tmpDot->Dot_Diameter[ii]/2));
					tmp = (int)Math::Truncate(dis/ScreenPitch) ;
					if(StartPosX >= Coordinate.X){					
						line1 = StartPosX - tmp*ScreenPitch - Coordinate.X;
					}else{					
						line1 = StartPosX + (tmp+1)*ScreenPitch - Coordinate.X ;
					}
					

					/*
					if(StartPosX >= Coordinate.X){
						tmp = Math::Truncate((StartPosX - (Coordinate.X-this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) ;
						line1 = StartPosX - Coordinate.X - tmp*ScreenPitch;
					}else{
						tmp = Math::Truncate((Coordinate.X-this->tmpDot->Dot_Diameter[ii]/2 -StartPosX)/ScreenPitch) + 1 ;
						line1 = StartPosX - Coordinate.X + tmp*ScreenPitch;
					}
					*/

					line2 = line1 + ScreenThick;

					h1 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line1*line1 ;
					h2 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line2*line2 ;
					

					while (h1 >= 0 || h2 >= 0 ){
						 
						
						
						

						 if((h1<=0 && h2 >=0) || (h1 >=0 && h2 <=0)){
							 if(h1<=0) h1 = 0;
							 if(h2<=0) h2 = 0;
						 }

						 if(h1<=0 && h2 <=0) break;

						
						 
						 if(h1== 0) {
							Decrease_Area[ii] = Decrease_Area[ii] + ((float)Math::Sqrt(h1) + (float)Math::Sqrt(h2))*fabs(line2-this->tmpDot->Dot_Diameter[ii]/2)/2;

							Layer_Area[ii] = Layer_Area[ii] - fabs(line2-this->tmpDot->Dot_Diameter[ii]/2)*(float)Math::Sqrt(h2)/2;
						 }else if(h2 == 0){
							Decrease_Area[ii] = Decrease_Area[ii] + ((float)Math::Sqrt(h1) + (float)Math::Sqrt(h2))*fabs(line1-this->tmpDot->Dot_Diameter[ii]/2)/2;

							Layer_Area[ii] = Layer_Area[ii] - fabs(line1-this->tmpDot->Dot_Diameter[ii]/2)*(float)Math::Sqrt(h1)/2;
						 }else{
							Decrease_Area[ii] = Decrease_Area[ii] + ((float)Math::Sqrt(h1) + (float)Math::Sqrt(h2))*ScreenThick/2;
						 }
						 

					
						line1 = line1 + ScreenPitch;
						line2 = line1 + ScreenThick;

						h1 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line1*line1 ;
						h2 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line2*line2 ;



					};


					//*/

					// 進行網紋分析  Y 方向
					//*

					float h3 ;
					float h4 ;
					float line3 ;
					float line4 ;

					int tmp2 ;




					if(StartPosY >= Coordinate.Y){
						tmp2 = (int)Math::Truncate((StartPosY - (Coordinate.Y-this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) ;
						line3 = StartPosY - Coordinate.Y - tmp2*ScreenPitch;
					}else{
						tmp2 = (int)Math::Truncate((Coordinate.Y-this->tmpDot->Dot_Diameter[ii]/2 -StartPosY)/ScreenPitch) + 1 ;
						line3 = StartPosY - Coordinate.Y + tmp2*ScreenPitch;
					}





					line4 = line3 + ScreenThick;

					h3 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line3*line3 ;
					h4 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line4*line4 ;



					while (h3 >= 0 || h4 >= 0  ){
						 
						
						
						

						 if((h3<=0 && h4 >=0) || (h3 >=0 && h4 <=0)){
							 if(h3<=0) h3 = 0;
							 if(h4<=0) h4 = 0;
						 }

						 if(h3<=0 && h4 <=0) break;

						//int tmpnumber = Math::Truncate((Math::Sqrt(h1)+ Math::Sqrt(h2))/ScreenPitch);
						int tmpnumber = 0 ; 
		
						 
						 float tmpheight = 0 ;
						 if(h3 == 0 ){
							tmpheight =fabs(line4-this->tmpDot->Dot_Diameter[ii]/2);
							//考慮膜厚因素 
							Layer_Area[ii] = Layer_Area[ii] - tmpheight*(float)Math::Sqrt(h4)/2;
							

						 }else if (h4 == 0) {
							tmpheight =fabs(line3-this->tmpDot->Dot_Diameter[ii]/2);
							//考慮膜厚因素 
							Layer_Area[ii] = Layer_Area[ii] - tmpheight*(float)Math::Sqrt(h3)/2;
						 }else{
							tmpheight = ScreenThick;
							//考慮膜厚因素 
						 }
					   //  Decrease_Area[ii] = Decrease_Area[ii] + (Math::Sqrt(h3) + Math::Sqrt(h4))*tmpheight -tmpnumber*ScreenThick*ScreenThick ;
						 Decrease_Area[ii] = Decrease_Area[ii] + ((float)Math::Sqrt(h3) + (float)Math::Sqrt(h4))*tmpheight/2  ;

						 line3 = line3 + ScreenPitch;
						 line4 = line3 + ScreenThick;

						 h3 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line3*line3 ;
						 h4 = this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - line4*line4 ;


					};

					//*/


					//-----------------------節點間數值---------------------------------------------------------------
						//*

					float lineA ;  //X Left
					float lineB ;  //X Right
					float lineC ;  //Y Left
					float lineD ;  //Y Right
					int tmp3 ;	

					if(StartPosX >= Coordinate.X){
						tmp3 = (int)Math::Truncate((StartPosX - (Coordinate.X-this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) ;
						lineA = StartPosX - Coordinate.X - tmp3*ScreenPitch;
					}else{
						tmp3 = (int)Math::Truncate((Coordinate.X-this->tmpDot->Dot_Diameter[ii]/2 -StartPosX)/ScreenPitch) + 1 ;
						
						lineA = StartPosX - Coordinate.X + tmp3*ScreenPitch;
					}

					if(StartPosX >= Coordinate.X){
						tmp3 = (int)Math::Truncate((StartPosX - (Coordinate.X+this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) +1 ;
						lineB = StartPosX - Coordinate.X - tmp3*ScreenPitch;
					}else{
						tmp3 = (int)Math::Truncate((Coordinate.X+this->tmpDot->Dot_Diameter[ii]/2 -StartPosX)/ScreenPitch)  ;
						
						lineB = StartPosX - Coordinate.X + tmp3*ScreenPitch;
					}

					if(StartPosY >= Coordinate.Y){
						tmp3 = (int)Math::Truncate((StartPosY - (Coordinate.Y-this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) ;
					
						lineC = StartPosY - Coordinate.Y - tmp3*ScreenPitch;
					}else{
						tmp3 = (int)Math::Truncate((Coordinate.Y-this->tmpDot->Dot_Diameter[ii]/2 -StartPosY)/ScreenPitch) + 1 ;
						
						lineC = StartPosY - Coordinate.Y + tmp3*ScreenPitch;
					}

					if(StartPosY >= Coordinate.Y){
						tmp3 = (int)Math::Truncate((StartPosY - (Coordinate.Y + this->tmpDot->Dot_Diameter[ii]/2))/ScreenPitch) +1 ;
						lineD = StartPosY - Coordinate.Y - tmp3*ScreenPitch;
					}else{
						tmp3 = (int)Math::Truncate((Coordinate.Y + this->tmpDot->Dot_Diameter[ii]/2 -StartPosY)/ScreenPitch)  ;
						
						lineD = StartPosY - Coordinate.Y + tmp3*ScreenPitch;
					}


					int NumberX =(int) Math::Round((lineB-lineA-ScreenThick)/ScreenPitch) ;
					int NumberY =(int) Math::Round((lineD-lineC-ScreenThick)/ScreenPitch) ;

				



					for(int aa = 0 ; aa < NumberX ; aa ++){
						for(int bb = 0 ; bb < NumberY ;bb ++){
							int count = 0;
							PointF DL(lineA + aa*ScreenThick ,lineC + bb*ScreenThick);
							PointF UL(lineA + aa*ScreenThick ,lineC + (bb+1)*ScreenThick);
							PointF DR(lineA + (aa+1)*ScreenThick ,lineC + bb*ScreenThick);
							PointF UR(lineA + (aa+1)*ScreenThick ,lineC + (bb+1)*ScreenThick);

							
		
							bool DL_Inside = false;
							bool UL_Inside = false;
							bool DR_Inside = false;
							bool UR_Inside = false;
							




							
							
							if(Math::Sqrt(DL.X*DL.X+DL.Y*DL.Y) <=this->tmpDot->Dot_Diameter[ii]/2){
								count ++;
								DL_Inside = true;
							}
							if(Math::Sqrt(UL.X*UL.X+UL.Y*UL.Y) <=this->tmpDot->Dot_Diameter[ii]/2){
								count ++;
								UL_Inside = true;
							}
							if(Math::Sqrt(DR.X*DR.X+DR.Y*DR.Y) <=this->tmpDot->Dot_Diameter[ii]/2){
								count ++;
								DR_Inside = true;
							}
							if(Math::Sqrt(UR.X*UR.X+UR.Y*UR.Y) <=this->tmpDot->Dot_Diameter[ii]/2){
								count ++;
								UR_Inside = true;
							}

							if (count == 4 ){
								Decrease_Area[ii] = Decrease_Area[ii] -ScreenThick*ScreenThick ; //全部方塊在圓形網點內
							}else if(count == 3){
								PointF outPt;

								if(DL_Inside == false){
									outPt.X = DL.X;
									outPt.Y = DL.Y;
								}else if(UL_Inside == false){
									outPt.X = UL.X;
									outPt.Y = UL.Y;

								}else if(DR_Inside == false){
									outPt.X = DR.X;
									outPt.Y = DR.Y;

								}else{
									outPt.X = UR.X;
									outPt.Y = UR.Y;
								}
								float a = fabs(fabs(outPt.Y) -(float)Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - outPt.X*outPt.X));	
								float b = fabs(fabs(outPt.X) -(float)Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - outPt.Y*outPt.Y));	
								Decrease_Area[ii] = Decrease_Area[ii] -(ScreenThick*ScreenThick-a*b/2) ;

							}else if(count == 2){
								PointF Pt_1;
								PointF Pt_2;


								if(DL_Inside == true && UL_Inside == true){
									Pt_1.Y = DL.X;
									Pt_1.X = DL.Y;
									Pt_2.Y = UL.X;
									Pt_2.X = UL.Y;

								}else if(DL_Inside == true && DR_Inside == true ){

									Pt_1.Y = DL.Y;
									Pt_1.X = DL.X;
									Pt_2.Y = DR.Y;
									Pt_2.X = DR.X;


								}else if(UL_Inside == true && UR_Inside == true ){

									Pt_1.Y = UL.Y;
									Pt_1.X = UL.X;
									Pt_2.Y = UR.Y;
									Pt_2.X = UR.X;


								}else{
									Pt_1.Y = DR.X;
									Pt_1.X = DR.Y;
									Pt_2.Y = UR.X;
									Pt_2.X = UR.Y;

								}

								float a = fabs(fabs(Pt_1.Y) -(float)Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - Pt_1.X*Pt_1.X));	
								float b = fabs(fabs(Pt_2.Y) -(float)Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - Pt_2.X*Pt_2.X));	
								Decrease_Area[ii] = Decrease_Area[ii] -(a+b)*ScreenThick/2 ;



							}else if(count == 1){

								PointF insidePt;

								if(DL_Inside == true){
									insidePt.X = DL.X;
									insidePt.Y = DL.Y;
								}else if(UL_Inside == true){
									insidePt.X = UL.X;
									insidePt.Y = UL.Y;

								}else if(DR_Inside == true){
									insidePt.X = DR.X;
									insidePt.Y = DR.Y;

								}else{
									insidePt.X = UR.X;
									insidePt.Y = UR.Y;
								}
								float a = (float)fabs(fabs(insidePt.Y) -Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - insidePt.X*insidePt.X));	
								float b = (float)fabs(fabs(insidePt.X) -Math::Sqrt( this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii]/4 - insidePt.Y*insidePt.Y));	
								Decrease_Area[ii] = Decrease_Area[ii] -(a*b/2) ;
							};

						}
					}

					


					
					  		
					this->tmpDot->MuraValue[ii] =   ((oriArea- Decrease_Area[ii])*ScreenThink_2 + Layer_Area[ii]*LayerThick)/ oriArea;
				

				 }

			 






			 }
			 //------------------KK______________________________________________________________________________

			 for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
				 this->tmpDot->MuraValue[ii] = this->tmpDot->MuraValue[ii] /1;
//
			 }









			

			


			    //取平均值
			//	float value = 0 ;
			//	for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
			//		value = value + this->tmpDot->MuraValue[ii] ;
			//	}
			//	value = value/(float)this->tmpDot->GetDotNumber();
			//	for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
			//		this->tmpDot->MuraValue[ii] = this->tmpDot->MuraValue[ii]/value;
			//
			//	}

				

			 

				//將資料存入ScreenMuraData中 ,並且進行繪圖的動作 

				//*
				Point Mesh = this->tmpScreenMura->GetMeshNumber();


				float deltaX = this->tmpLGPRange.Width/2.0f/(float)Mesh.X;		
				float deltaY = this->tmpLGPRange.Height/2.0f/(float)Mesh.Y;

				this->progressBar1->Value::set(0);
				
				for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){


					this->progressBar1->Value::set(ii*100/(this->tmpDot->GetDotNumber()-1));
					this->progressBar1->Update();


					 
					PointF Coordinate1(this->tmpDot->Dot_Coordinate[ii].X + deltaX ,this->tmpDot->Dot_Coordinate[ii].Y + deltaY);
					PointF Coordinate2(this->tmpDot->Dot_Coordinate[ii].X + deltaX,this->tmpDot->Dot_Coordinate[ii].Y - deltaY);
					PointF Coordinate3(this->tmpDot->Dot_Coordinate[ii].X - deltaX,this->tmpDot->Dot_Coordinate[ii].Y + deltaY);
					PointF Coordinate4(this->tmpDot->Dot_Coordinate[ii].X - deltaX,this->tmpDot->Dot_Coordinate[ii].Y - deltaY);

					



					float v1 = this->tmpScreenMura->GetDensityValue(Coordinate1);
					float v2 = this->tmpScreenMura->GetDensityValue(Coordinate2);
					float v3 = this->tmpScreenMura->GetDensityValue(Coordinate3);
					float v4 = this->tmpScreenMura->GetDensityValue(Coordinate4);

					float d1 = tmpDifData->GetDensityValue(Coordinate1);
					float d2 = tmpDifData->GetDensityValue(Coordinate2);
					float d3 = tmpDifData->GetDensityValue(Coordinate3);
					float d4 = tmpDifData->GetDensityValue(Coordinate4);
					



					float test = (this->tmpDot->Dot_Diameter[ii]*this->tmpDot->Dot_Diameter[ii])/deltaX/deltaY;
					//float test = (this->tmpDot->Dot_Coordinate[ii].Y);
					


					if(tmpLGPRange.Contains(Coordinate1) == true) {
						this->tmpScreenMura->SetDensityValue(this->tmpDot->MuraValue[ii]/4 + v1 ,Coordinate1);
						//霧化參數
						tmpDifData->SetDensityValue(d1 + test,Coordinate1);
					}
					if(tmpLGPRange.Contains(Coordinate2) == true) {
						this->tmpScreenMura->SetDensityValue(this->tmpDot->MuraValue[ii]/4 + v2,Coordinate2);
						//霧化參數
						tmpDifData->SetDensityValue(d2 +test,Coordinate2);
					}
					if(tmpLGPRange.Contains(Coordinate3) == true) {
						this->tmpScreenMura->SetDensityValue(this->tmpDot->MuraValue[ii]/4 + v3,Coordinate3);
						//霧化參數
						tmpDifData->SetDensityValue(d3 + test,Coordinate3);
					}
					if(tmpLGPRange.Contains(Coordinate4) == true) {
						this->tmpScreenMura->SetDensityValue(this->tmpDot->MuraValue[ii]/4 + v4,Coordinate4);
						//霧化參數
						tmpDifData->SetDensityValue(d4 + test,Coordinate4);
					}
					

				}



				


				





				Point tmpMesh = this->tmpScreenMura->GetMeshNumber();




				//霧化度 ------------------------------------------------------
								
				GridDensity^ tmpDif = gcnew GridDensity(tmpMesh,tmpLGPRange);

				
				int dif = 0;
				float f1 = 0;
				//float f2;
				//float f3;
				//float f4;

				this->progressBar1->Value::set(0);

				for(int ii = 0 ; ii <tmpMesh.X ; ii++){

					this->progressBar1->Value::set((int)(ii*100.0f/(float)(tmpMesh.X-1.0f)));
					this->progressBar1->Update();

					for(int jj = 0 ; jj <tmpMesh.Y ; jj++){
						dif = 2*(int)Math::Round(tmpDifData->GetDensityValue(Point(ii,jj)))+1;
					//	dif = 3;
						f1 = 0;
						if(ii < tmpMesh.X-dif+1 && jj < tmpMesh.Y-dif+1){
							
							for(int kk = 0 ; kk < dif ; kk ++){
								for(int ll = 0 ; ll < dif ;ll++){
									float factor = 1;
									
									f1 = f1 + factor*this->tmpScreenMura->GetDensityValue(Point(ii+kk,jj+ll));							
								}
							}
							f1 = f1/dif/dif;
						}
						tmpDif->SetDensityValue(f1,Point(ii,jj));


					}
				}

				for(int ii = 0 ; ii <tmpMesh.X ; ii++){
					for(int jj = 0 ; jj <tmpMesh.Y ; jj++){
						this->tmpScreenMura->SetDensityValue(tmpDif->GetDensityValue(Point(ii,jj)),Point(ii,jj));

					}
				}
				



				//*/
				//取平均值
				float value = 0 ;
				for(int ii = 0 ; ii <tmpMesh.X ; ii++){
					for(int jj = 0 ; jj <tmpMesh.Y ; jj++){
						value =  value + this->tmpScreenMura->GetDensityValue(Point(ii,jj));	
					}
				}
				value = 2*value/(float)(tmpMesh.X*tmpMesh.Y);

				for(int ii = 0 ; ii <tmpMesh.X ; ii++){
					for(int jj = 0 ; jj <tmpMesh.Y ; jj++){
						this->tmpScreenMura->SetDensityValue(this->tmpScreenMura->GetDensityValue(Point(ii,jj))/value,Point(ii,jj));
						
					}
				}







			

					

					
					

				 




		 }
/*
private: System::Void btnRandom_Click(System::Object^  sender, System::EventArgs^  e) {

			 //
			 float MovingRange = Convert::ToSingle(this->txtScreenPitch->Text);
			 float average = 0;
			  for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
				  average = average + this->tmpDot->MuraValue[ii];
			  }
			  average = average/this->tmpDot->GetDotNumber();

			  for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){



				  Point MinIndex ;
				  float minRatio = 1;

				  int Value = Math::Round(MovingRange/0.005);

				  for(int jj = 0 ; jj <Value  ;jj ++){
					    for(int kk = 0 ; kk < Value ;kk ++){
							PointF Dot;
							Dot.X = this->tmpDot->Dot_Coordinate[ii].X - (Value-1)*0.0025 + jj*0.005;
							Dot.Y = this->tmpDot->Dot_Coordinate[ii].Y - (Value-1)*0.0025 + kk*0.005;

							float tmpValue = fabs(this->CalculateMuraValue(Dot,this->tmpDot->Dot_Diameter[ii])/average-1);

							if( tmpValue < minRatio){
								minRatio = tmpValue;
								MinIndex.X = jj;
								MinIndex.Y = kk;
							}

						}
				  }


				  this->tmpDot->Dot_Coordinate[ii].X = this->tmpDot->Dot_Coordinate[ii].X -(Value-1)*0.0025 + MinIndex.X*0.005;
				  this->tmpDot->Dot_Coordinate[ii].Y = this->tmpDot->Dot_Coordinate[ii].Y -(Value-1)*0.0025 + MinIndex.Y*0.005;



				

			}



		 }
*/
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


			 float ScreenPitch; //= Convert::ToSingle(this->txtScreenPitch->Text);  // 開孔  + 縣境
			

			 switch(this->cboScreenSpec->SelectedIndex){
					case 0: //305S
						ScreenPitch = 0.083f;
						break;
					case 1: //315T							
						ScreenPitch = 0.079f;						
						break;
					case 2: //315S						
						ScreenPitch = 0.081f;						
						break;
					case 3: //420S					
						ScreenPitch = 0.057f;						
						break;
			 }



			  Random^ autoRand = gcnew Random(0);
			  float pitchX = this->tmpLGPRange.Width/(float)this->tmpScreenMura->GetMeshNumber().X;
			  float pitchY = this->tmpLGPRange.Height/(float)this->tmpScreenMura->GetMeshNumber().Y;

			  this->progressBar1->Value::set(0);

			  float distance = 0 ;
			  switch(this->tmpPattern_Arrangment){
					case 0: //矩形
						distance =Math::Min( this->tmpLGPRange.Width/this->tmpGridNumber.X ,this->tmpLGPRange.Height/this->tmpGridNumber.Y)-0.01f;
						break;
					case 1: //45度
						distance =Math::Min( 0.707f* this->tmpLGPRange.Width/this->tmpGridNumber.X ,0.707f* this->tmpLGPRange.Height/this->tmpGridNumber.Y)-0.01f;
						break;
					case 2: //60度
						distance =Math::Min( this->tmpLGPRange.Width/this->tmpGridNumber.X ,this->tmpLGPRange.Height/this->tmpGridNumber.Y)-0.01f;
						break;
					case 3 ://30度
						distance =Math::Min( this->tmpLGPRange.Width/this->tmpGridNumber.X ,this->tmpLGPRange.Height/this->tmpGridNumber.Y)-0.01f;
						break;
			  }


			  float value = (float)this->Disturb_ScrollBarValue->Value;
			  

			  
			  for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){



				  //  Halton Sequence Method

					int temppp ;
				    float H = 0 ;
					float half = 1/2.0f ;
					int tmpI = ii+1 ;
					int digit;
					while (tmpI != 0.0f ){
						Math::DivRem ( tmpI, 2 ,digit ) ;
						H = H + (float)digit * half ;
						tmpI = ( tmpI - digit )/2.0f ;
						half = half/2.0f ;
					}


					float HY = 0 ;
					half = 1.0f/3.0f ;
					tmpI = ii+1 ;
					digit= 0 ;
					while (tmpI != 0.0f ){
						Math::DivRem ( tmpI, 3 ,digit ) ;
						HY = HY + (float)digit * half ;
						tmpI = (tmpI - digit )/3.0f ;
						half = half/3.0f ;
					}
			
				
					int index ;

					float H_Index = 0 ;
					half = 1.0f/5.0f ;
					tmpI = ii+1 ;
					digit= 0 ;
					while (tmpI != 0.0f ){
						Math::DivRem ( tmpI, 5 ,digit ) ;
						H_Index = H_Index + (float)digit * half ;
						tmpI = (tmpI - digit )/5.0f ;
						half = half/5.0f ;
					}


					index = H_Index*this->tmpDot->GetDotNumber();


				  this->progressBar1->Value::set(ii*100/(this->tmpDot->GetDotNumber()-1));
					this->progressBar1->Update();

				   float diameter = this->tmpDot->Dot_Diameter[ii];
				   float tmpScreenPitch;

				 
				    if(diameter >= distance-0.1) tmpScreenPitch = 0;
					//else if (distance-diameter-ScreenPitch < 0 && diameter < distance ) tmpScreenPitch = distance-diameter;
					else tmpScreenPitch = distance-diameter-0.1;
				  				   
				//	this->tmpDot->Dot_Coordinate[ii].X = this->tmpDot->Dot_Coordinate[ii].X +  3*tmpScreenPitch/value *(H-0.5f);
				//	this->tmpDot->Dot_Coordinate[ii].Y = this->tmpDot->Dot_Coordinate[ii].Y +  3*tmpScreenPitch/value *(HY-0.5f);

					//PChange Model Setting 
					this->tmpDot->Dot_Coordinate[index].X = this->tmpDot->Dot_Coordinate[index].X +  tmpScreenPitch/1.414*1.732 *(H-0.5f);
					this->tmpDot->Dot_Coordinate[index].Y = this->tmpDot->Dot_Coordinate[index].Y +  tmpScreenPitch/1.414 *(HY-0.5f);

				
					//DChange Model Setting 20%
					//this->tmpDot->Dot_Diameter[index] = this->tmpDot->Dot_Diameter[index] + this->tmpDot->Dot_Diameter[index]*(H-0.5f)*0.2f;

					//DChange Model Setting 40%
					//this->tmpDot->Dot_Diameter[index] = this->tmpDot->Dot_Diameter[index] + this->tmpDot->Dot_Diameter[index]*(H-0.5f)*0.4f;
				
				  
					
				   


			   }



		 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtStartPos_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
			 //this->Hide();
			 this->Close();
		 }
private: System::Void btnCalGap_Click(System::Object^  sender, System::EventArgs^  e) {
			 float minGap = 10000;

			 
			 for(int ii = 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){
				  for(int jj = ii ; jj <this->tmpDot->GetDotNumber()  ; jj++){

					  float gap ;
					  float maxDis;					 
					  maxDis = (this->tmpDot->Dot_Diameter[ii]/2 + this->tmpDot->Dot_Diameter[jj]/2.0f + 0.2f);
					  PointF Dis(this->tmpDot->Dot_Coordinate[ii].X -this->tmpDot->Dot_Coordinate[jj].X ,this->tmpDot->Dot_Coordinate[ii].Y -this->tmpDot->Dot_Coordinate[jj].Y);

					  if(fabs(Dis.X) < maxDis && fabs(Dis.Y) < maxDis && jj!= ii){
						  gap = (float)Math::Sqrt(Dis.X*Dis.X + Dis.Y*Dis.Y)-this->tmpDot->Dot_Diameter[ii]/2-this->tmpDot->Dot_Diameter[jj]/2;
						if (gap < minGap)  minGap = gap;
					  }

				  }
				this->progressBar1->Value::set(ii*100/(this->tmpDot->GetDotNumber()-1));
				this->progressBar1->Update();
			 }

			 this->lbl_Gap->Text = "最小Gap為  : " + Convert::ToString(minGap);

			 
			
		 }
private: System::Void btnWave_Click(System::Object^  sender, System::EventArgs^  e) {


			 float ScreenPitch; //= Convert::ToSingle(this->txtScreenPitch->Text);  // 開孔  + 縣境
			

			 switch(this->cboScreenSpec->SelectedIndex){
					case 0: //305S
						ScreenPitch = 0.083f;
						break;
					case 1: //315T							
						ScreenPitch = 0.079f;						
						break;
					case 2: //315S						
						ScreenPitch = 0.081f;						
						break;
					case 3: //420S					
						ScreenPitch = 0.057f;						
						break;
			 }


			
			

			  this->progressBar1->Value::set(0);



			


			  float Amplitude = Convert::ToSingle(this->txt_Range->Text);
			  float Period = Convert::ToSingle(this->txtperiod->Text);



			  
			  for(int ii= 0 ; ii < this->tmpDot->GetDotNumber() ; ii++){

				  this->progressBar1->Value::set(ii*100/(this->tmpDot->GetDotNumber()-1));
					this->progressBar1->Update();

				   if(this->cboWaveDirection->SelectedIndex == 0) { //X 方向

					   this->tmpDot->Dot_Coordinate[ii].Y = this->tmpDot->Dot_Coordinate[ii].Y + Amplitude* Math::Sin((this->tmpDot->Dot_Coordinate[ii].X/Period)*2*Math::PI);
					   if( this->tmpDot->Dot_Coordinate[ii].Y >= this->tmpLGPRange.Height) this->tmpDot->Dot_Coordinate[ii].Y = this->tmpDot->Dot_Coordinate[ii].Y -this->tmpLGPRange.Height ;
					   if( this->tmpDot->Dot_Coordinate[ii].Y <= 0) this->tmpDot->Dot_Coordinate[ii].Y = this->tmpDot->Dot_Coordinate[ii].Y +this->tmpLGPRange.Height ;

				   //}else { //Y 方向

					   this->tmpDot->Dot_Coordinate[ii].X = this->tmpDot->Dot_Coordinate[ii].X + Amplitude* Math::Sin((this->tmpDot->Dot_Coordinate[ii].Y/Period)*2*Math::PI);
					   if( this->tmpDot->Dot_Coordinate[ii].X >= this->tmpLGPRange.Width) this->tmpDot->Dot_Coordinate[ii].X = this->tmpDot->Dot_Coordinate[ii].X -this->tmpLGPRange.Width ;
					   if( this->tmpDot->Dot_Coordinate[ii].X <= 0) this->tmpDot->Dot_Coordinate[ii].X = this->tmpDot->Dot_Coordinate[ii].X +this->tmpLGPRange.Width ;

				   }


			   }







		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
