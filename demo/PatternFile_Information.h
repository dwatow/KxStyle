#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PatternContruction {

	/// <summary>
	/// Summary for PatternFile_Information
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PatternFile_Information : public System::Windows::Forms::Form
	{
	public:
		PatternFile_Information()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
		

			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PatternFile_Information()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txt_PtichX;
	private: System::Windows::Forms::TextBox^  txt_PitchY;
	private: System::Windows::Forms::TextBox^  txt_LGP_X;
	private: System::Windows::Forms::TextBox^  txt_LGPY;
	private: System::Windows::Forms::TextBox^  txt_NumberX;
	private: System::Windows::Forms::TextBox^  txt_Number_Y;








	public:

	RectangleF^ LGPInformation;
	PointF^ Pitch;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.



		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_PtichX = (gcnew System::Windows::Forms::TextBox());
			this->txt_PitchY = (gcnew System::Windows::Forms::TextBox());
			this->txt_LGP_X = (gcnew System::Windows::Forms::TextBox());
			this->txt_LGPY = (gcnew System::Windows::Forms::TextBox());
			this->txt_NumberX = (gcnew System::Windows::Forms::TextBox());
			this->txt_Number_Y = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(194, 137);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"確定";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PatternFile_Information::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pitch X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Pitch Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 12);
			this->label3->TabIndex = 3;
			this->label3->Text = L"LGP 左下角座標";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 12);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Dot數目(X,Y方向)";
			// 
			// txt_PtichX
			// 
			this->txt_PtichX->Location = System::Drawing::Point(121, 20);
			this->txt_PtichX->Name = L"txt_PtichX";
			this->txt_PtichX->Size = System::Drawing::Size(57, 22);
			this->txt_PtichX->TabIndex = 5;
			// 
			// txt_PitchY
			// 
			this->txt_PitchY->Location = System::Drawing::Point(121, 48);
			this->txt_PitchY->Name = L"txt_PitchY";
			this->txt_PitchY->Size = System::Drawing::Size(57, 22);
			this->txt_PitchY->TabIndex = 6;
			// 
			// txt_LGP_X
			// 
			this->txt_LGP_X->Location = System::Drawing::Point(121, 76);
			this->txt_LGP_X->Name = L"txt_LGP_X";
			this->txt_LGP_X->Size = System::Drawing::Size(57, 22);
			this->txt_LGP_X->TabIndex = 7;
			// 
			// txt_LGPY
			// 
			this->txt_LGPY->Location = System::Drawing::Point(184, 76);
			this->txt_LGPY->Name = L"txt_LGPY";
			this->txt_LGPY->Size = System::Drawing::Size(57, 22);
			this->txt_LGPY->TabIndex = 8;
			// 
			// txt_NumberX
			// 
			this->txt_NumberX->Location = System::Drawing::Point(121, 104);
			this->txt_NumberX->Name = L"txt_NumberX";
			this->txt_NumberX->Size = System::Drawing::Size(57, 22);
			this->txt_NumberX->TabIndex = 9;
			// 
			// txt_Number_Y
			// 
			this->txt_Number_Y->Location = System::Drawing::Point(184, 104);
			this->txt_Number_Y->Name = L"txt_Number_Y";
			this->txt_Number_Y->Size = System::Drawing::Size(57, 22);
			this->txt_Number_Y->TabIndex = 10;
			// 
			// PatternFile_Information
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 171);
			this->Controls->Add(this->txt_Number_Y);
			this->Controls->Add(this->txt_NumberX);
			this->Controls->Add(this->txt_LGPY);
			this->Controls->Add(this->txt_LGP_X);
			this->Controls->Add(this->txt_PitchY);
			this->Controls->Add(this->txt_PtichX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"PatternFile_Information";
			this->Text = L"PatternFile_Information";
			this->Load += gcnew System::EventHandler(this, &PatternFile_Information::PatternFile_Information_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PatternFile_Information_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


			try{
				this->Pitch->X = Convert::ToSingle(this->txt_PtichX->Text) ;
				this->Pitch->Y = Convert::ToSingle(this->txt_PitchY->Text) ;
				this->LGPInformation->X = Convert::ToSingle(this->txt_LGP_X->Text);
				this->LGPInformation->Y = Convert::ToSingle(this->txt_LGPY->Text);
				this->LGPInformation->Width = Convert::ToInt16(this->txt_NumberX->Text) *this->Pitch->X;
				this->LGPInformation->Height = Convert::ToInt16(this->txt_Number_Y->Text) *this->Pitch->Y;
				this->Close();
			}
			catch(...){
				 MessageBox::Show("輸入參數錯誤!!");
			}

			 
		 }
};
}
