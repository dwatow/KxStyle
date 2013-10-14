#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PatternContruction {

	/// <summary>
	/// IJP_Primer_Pattern 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class IJP_Primer_Pattern : public System::Windows::Forms::Form
	{
	public:
		IJP_Primer_Pattern(bool *modifyShape ,float *dotsize , float *dotGap , int *Filenumber ,RectangleF LGPSize ,Point *ArrayNumber ,PointF *ArrayPitch)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			tmp_modifyShape = modifyShape;
			tmp_dotsize = dotsize;
			tmp_dotGap = dotGap;
			tmp_Filenumber = Filenumber ;
			tmpLGPSize = LGPSize;
			tmp_ArrayPitch = ArrayPitch;
			tmp_ArrayNumber = ArrayNumber;


			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~IJP_Primer_Pattern()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtDotSize;
	private: System::Windows::Forms::TextBox^  txtDotGap;
	private: System::Windows::Forms::TextBox^  txtFileNumber;



	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cboModifyShape;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		bool *tmp_modifyShape;
		float *tmp_dotsize;
		float *tmp_dotGap;
		int *tmp_Filenumber;
		Point *tmp_ArrayNumber;
		PointF *tmp_ArrayPitch;
		RectangleF tmpLGPSize;
	private: System::Windows::Forms::Label^  lblLGPSize;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtArrayX;
	private: System::Windows::Forms::TextBox^  txtArrayY;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtPitchX;
	private: System::Windows::Forms::TextBox^  txtPitchY;


			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtDotSize = (gcnew System::Windows::Forms::TextBox());
			this->txtDotGap = (gcnew System::Windows::Forms::TextBox());
			this->txtFileNumber = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cboModifyShape = (gcnew System::Windows::Forms::ComboBox());
			this->lblLGPSize = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtArrayX = (gcnew System::Windows::Forms::TextBox());
			this->txtArrayY = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtPitchX = (gcnew System::Windows::Forms::TextBox());
			this->txtPitchY = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"網點直徑";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(12, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"網點Gap";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(12, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"分割檔案數";
			// 
			// txtDotSize
			// 
			this->txtDotSize->Location = System::Drawing::Point(137, 38);
			this->txtDotSize->Name = L"txtDotSize";
			this->txtDotSize->Size = System::Drawing::Size(77, 22);
			this->txtDotSize->TabIndex = 3;
			// 
			// txtDotGap
			// 
			this->txtDotGap->Location = System::Drawing::Point(137, 66);
			this->txtDotGap->Name = L"txtDotGap";
			this->txtDotGap->Size = System::Drawing::Size(77, 22);
			this->txtDotGap->TabIndex = 4;
			this->txtDotGap->TextChanged += gcnew System::EventHandler(this, &IJP_Primer_Pattern::textBox2_TextChanged);
			// 
			// txtFileNumber
			// 
			this->txtFileNumber->Location = System::Drawing::Point(137, 94);
			this->txtFileNumber->Name = L"txtFileNumber";
			this->txtFileNumber->Size = System::Drawing::Size(77, 22);
			this->txtFileNumber->TabIndex = 5;
			this->txtFileNumber->TextChanged += gcnew System::EventHandler(this, &IJP_Primer_Pattern::textBox3_TextChanged);
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(137, 209);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 25);
			this->btnOK->TabIndex = 6;
			this->btnOK->Text = L"確定";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &IJP_Primer_Pattern::btnOK_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(12, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(108, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"進行修邊(Y/N)";
			// 
			// cboModifyShape
			// 
			this->cboModifyShape->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboModifyShape->FormattingEnabled = true;
			this->cboModifyShape->Location = System::Drawing::Point(137, 121);
			this->cboModifyShape->Name = L"cboModifyShape";
			this->cboModifyShape->Size = System::Drawing::Size(77, 20);
			this->cboModifyShape->TabIndex = 34;
			// 
			// lblLGPSize
			// 
			this->lblLGPSize->AutoSize = true;
			this->lblLGPSize->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->lblLGPSize->Location = System::Drawing::Point(12, 9);
			this->lblLGPSize->Name = L"lblLGPSize";
			this->lblLGPSize->Size = System::Drawing::Size(68, 16);
			this->lblLGPSize->TabIndex = 35;
			this->lblLGPSize->Text = L"LGP尺寸";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(12, 151);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 16);
			this->label5->TabIndex = 36;
			this->label5->Text = L"陣列[X,Y]";
			// 
			// txtArrayX
			// 
			this->txtArrayX->Location = System::Drawing::Point(94, 151);
			this->txtArrayX->Name = L"txtArrayX";
			this->txtArrayX->Size = System::Drawing::Size(57, 22);
			this->txtArrayX->TabIndex = 37;
			// 
			// txtArrayY
			// 
			this->txtArrayY->Location = System::Drawing::Point(157, 151);
			this->txtArrayY->Name = L"txtArrayY";
			this->txtArrayY->Size = System::Drawing::Size(57, 22);
			this->txtArrayY->TabIndex = 38;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(12, 181);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 16);
			this->label6->TabIndex = 39;
			this->label6->Text = L"Pitch[X,Y]";
			// 
			// txtPitchX
			// 
			this->txtPitchX->Location = System::Drawing::Point(94, 179);
			this->txtPitchX->Name = L"txtPitchX";
			this->txtPitchX->Size = System::Drawing::Size(57, 22);
			this->txtPitchX->TabIndex = 40;
			// 
			// txtPitchY
			// 
			this->txtPitchY->Location = System::Drawing::Point(157, 179);
			this->txtPitchY->Name = L"txtPitchY";
			this->txtPitchY->Size = System::Drawing::Size(57, 22);
			this->txtPitchY->TabIndex = 41;
			// 
			// IJP_Primer_Pattern
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(234, 246);
			this->Controls->Add(this->txtPitchY);
			this->Controls->Add(this->txtPitchX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtArrayY);
			this->Controls->Add(this->txtArrayX);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblLGPSize);
			this->Controls->Add(this->cboModifyShape);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->txtFileNumber);
			this->Controls->Add(this->txtDotGap);
			this->Controls->Add(this->txtDotSize);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"IJP_Primer_Pattern";
			this->Text = L"設定";
			this->Load += gcnew System::EventHandler(this, &IJP_Primer_Pattern::IJP_Primer_Pattern_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void IJP_Primer_Pattern_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->cboModifyShape->Items->Add("Yes");
				 this->cboModifyShape->Items->Add("No");

				
				 //Loading 參數--------------------------------------------------
				 

				 this->lblLGPSize->Text = "LGP尺寸: " + String::Format("{0:#0.00##}"+ " , " + "{1:#0.00##}",this->tmpLGPSize.Width,this->tmpLGPSize.Height );
				 this->txtDotGap->Text = String::Format("{0:#0.00##}",*this->tmp_dotGap);
				 this->txtDotSize->Text = String::Format("{0:#0.00##}",*this->tmp_dotsize);
				 this->txtFileNumber->Text = String::Format("{0:#0}",*this->tmp_Filenumber);
				 this->txtArrayX->Text = String::Format("{0:#0}",this->tmp_ArrayNumber->X);
				 this->txtArrayY->Text = String::Format("{0:#0}",this->tmp_ArrayNumber->Y);
				 this->txtPitchX->Text = String::Format("{0:#0.00##}",this->tmp_ArrayPitch->X);
				 this->txtPitchY->Text = String::Format("{0:#0.00##}",this->tmp_ArrayPitch->Y);

				 if(*this->tmp_modifyShape == false){
					 this->cboModifyShape->SelectedIndex = 1;
					 this->cboModifyShape->Enabled = false;
				 }else{
					 this->cboModifyShape->SelectedIndex = 0;
				 }



			 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {

			 
			 *this->tmp_dotGap = Convert::ToSingle(this->txtDotGap->Text);
			 *this->tmp_dotsize = Convert::ToSingle(this->txtDotSize->Text);
			 *this->tmp_Filenumber = Convert::ToInt16(this->txtFileNumber->Text);
			 *this->tmp_modifyShape =! Convert::ToBoolean(this->cboModifyShape->SelectedIndex);
			 this->tmp_ArrayNumber->X = Convert::ToInt16(this->txtArrayX->Text);
			 this->tmp_ArrayNumber->Y = Convert::ToInt16(this->txtArrayY->Text);
			 this->tmp_ArrayPitch->X = Convert::ToSingle(this->txtPitchX->Text);
			 this->tmp_ArrayPitch->Y = Convert::ToSingle(this->txtPitchY->Text);


			 this->Close();

			 
		 }
};
}
