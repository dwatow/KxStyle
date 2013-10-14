#pragma once

#include "DataStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PatternContruction {

	/// <summary>
	/// SettingForm ���K�n
	///
	/// ĵ�i: �p�G�z�ܧ�o�����O���W�١A�N�����ܧ�P�o�����O�Ҩ̾ڤ��Ҧ� .resx �ɮ����p��
	///          Managed �귽�sĶ���u�㪺 'Resource File Name' �ݩʡC
	///          �_�h�A�o�ǳ]�p�u��
	///          �N�L�k�P�o�Ӫ�����p����a�y�t�Ƹ귽
	///          ���T���ʡC
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
	public:
		SettingForm(SettingData^ Set_Data)
		{
			InitializeComponent();
			//
			tmpSet_Data = Set_Data;
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~SettingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl_Setting;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  lbl_PatternStyle;
	private: System::Windows::Forms::ComboBox^  cboBox_Pattern_Style;
	private: System::Windows::Forms::ComboBox^  cboBox_Pattern_Shape;



	private: System::Windows::Forms::Label^  lbl_PatternShape;
	private: System::Windows::Forms::TextBox^  txt_Y_Shift;

	private: System::Windows::Forms::TextBox^  txt_X_Shift;

	private: System::Windows::Forms::Label^  lbl_Y_direction_Shift;
	private: System::Windows::Forms::Label^  lbl_X_direction_Shift;
	private: System::Windows::Forms::Button^  btn_Reset;
	private: System::Windows::Forms::Button^  btn_Cancel;
	private: System::Windows::Forms::Button^  btn_OK;
	private: System::Windows::Forms::TextBox^  txtPatternDeep;
	private: System::Windows::Forms::Label^  label1;










	private: System::Windows::Forms::GroupBox^  groupBox2;
	


	








   
 //Curve Data -------------------------------------------------------







	public: 


//------------------------------------------------------------------
			

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		
		SettingData^ tmpSet_Data;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numUpperDensity;
	private: System::Windows::Forms::NumericUpDown^  numLowerDensity;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  chkLimitDotSize;






			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�o�Ӥ�k�����e�C
		///
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingForm::typeid));
			this->tabControl_Setting = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->txtPatternDeep = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_Reset = (gcnew System::Windows::Forms::Button());
			this->txt_Y_Shift = (gcnew System::Windows::Forms::TextBox());
			this->txt_X_Shift = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Y_direction_Shift = (gcnew System::Windows::Forms::Label());
			this->lbl_X_direction_Shift = (gcnew System::Windows::Forms::Label());
			this->cboBox_Pattern_Shape = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_PatternShape = (gcnew System::Windows::Forms::Label());
			this->lbl_PatternStyle = (gcnew System::Windows::Forms::Label());
			this->cboBox_Pattern_Style = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->chkLimitDotSize = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->numLowerDensity = (gcnew System::Windows::Forms::NumericUpDown());
			this->numUpperDensity = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->btn_OK = (gcnew System::Windows::Forms::Button());
			this->tabControl_Setting->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numLowerDensity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpperDensity))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl_Setting
			// 
			this->tabControl_Setting->Controls->Add(this->tabPage1);
			this->tabControl_Setting->Controls->Add(this->tabPage2);
			this->tabControl_Setting->Location = System::Drawing::Point(4, 3);
			this->tabControl_Setting->Name = L"tabControl_Setting";
			this->tabControl_Setting->SelectedIndex = 0;
			this->tabControl_Setting->Size = System::Drawing::Size(410, 356);
			this->tabControl_Setting->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->txtPatternDeep);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->btn_Reset);
			this->tabPage1->Controls->Add(this->txt_Y_Shift);
			this->tabPage1->Controls->Add(this->txt_X_Shift);
			this->tabPage1->Controls->Add(this->lbl_Y_direction_Shift);
			this->tabPage1->Controls->Add(this->lbl_X_direction_Shift);
			this->tabPage1->Controls->Add(this->cboBox_Pattern_Shape);
			this->tabPage1->Controls->Add(this->lbl_PatternShape);
			this->tabPage1->Controls->Add(this->lbl_PatternStyle);
			this->tabPage1->Controls->Add(this->cboBox_Pattern_Style);
			this->tabPage1->Location = System::Drawing::Point(4, 21);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(402, 331);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"LT�Ѽ��ɳ]�w";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// txtPatternDeep
			// 
			this->txtPatternDeep->Location = System::Drawing::Point(268, 19);
			this->txtPatternDeep->Name = L"txtPatternDeep";
			this->txtPatternDeep->Size = System::Drawing::Size(59, 22);
			this->txtPatternDeep->TabIndex = 12;
			this->txtPatternDeep->Text = L"0";
			this->txtPatternDeep->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(201, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 11;
			this->label1->Text = L"���I�`��";
			// 
			// btn_Reset
			// 
			this->btn_Reset->Location = System::Drawing::Point(12, 142);
			this->btn_Reset->Name = L"btn_Reset";
			this->btn_Reset->Size = System::Drawing::Size(54, 35);
			this->btn_Reset->TabIndex = 10;
			this->btn_Reset->Text = L"���]";
			this->btn_Reset->UseVisualStyleBackColor = true;
			this->btn_Reset->Click += gcnew System::EventHandler(this, &SettingForm::btn_Reset_Click);
			// 
			// txt_Y_Shift
			// 
			this->txt_Y_Shift->Location = System::Drawing::Point(102, 108);
			this->txt_Y_Shift->Name = L"txt_Y_Shift";
			this->txt_Y_Shift->Size = System::Drawing::Size(59, 22);
			this->txt_Y_Shift->TabIndex = 7;
			this->txt_Y_Shift->Text = L"0";
			this->txt_Y_Shift->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// txt_X_Shift
			// 
			this->txt_X_Shift->Location = System::Drawing::Point(102, 80);
			this->txt_X_Shift->Name = L"txt_X_Shift";
			this->txt_X_Shift->Size = System::Drawing::Size(59, 22);
			this->txt_X_Shift->TabIndex = 6;
			this->txt_X_Shift->Text = L"0";
			this->txt_X_Shift->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbl_Y_direction_Shift
			// 
			this->lbl_Y_direction_Shift->AutoSize = true;
			this->lbl_Y_direction_Shift->Location = System::Drawing::Point(13, 111);
			this->lbl_Y_direction_Shift->Name = L"lbl_Y_direction_Shift";
			this->lbl_Y_direction_Shift->Size = System::Drawing::Size(73, 12);
			this->lbl_Y_direction_Shift->TabIndex = 5;
			this->lbl_Y_direction_Shift->Text = L"Y��V�����q";
			// 
			// lbl_X_direction_Shift
			// 
			this->lbl_X_direction_Shift->AutoSize = true;
			this->lbl_X_direction_Shift->Location = System::Drawing::Point(13, 83);
			this->lbl_X_direction_Shift->Name = L"lbl_X_direction_Shift";
			this->lbl_X_direction_Shift->Size = System::Drawing::Size(73, 12);
			this->lbl_X_direction_Shift->TabIndex = 4;
			this->lbl_X_direction_Shift->Text = L"X��V�����q";
			// 
			// cboBox_Pattern_Shape
			// 
			this->cboBox_Pattern_Shape->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboBox_Pattern_Shape->FormattingEnabled = true;
			this->cboBox_Pattern_Shape->Location = System::Drawing::Point(70, 47);
			this->cboBox_Pattern_Shape->Name = L"cboBox_Pattern_Shape";
			this->cboBox_Pattern_Shape->Size = System::Drawing::Size(104, 20);
			this->cboBox_Pattern_Shape->TabIndex = 3;
			// 
			// lbl_PatternShape
			// 
			this->lbl_PatternShape->AutoSize = true;
			this->lbl_PatternShape->Location = System::Drawing::Point(13, 50);
			this->lbl_PatternShape->Name = L"lbl_PatternShape";
			this->lbl_PatternShape->Size = System::Drawing::Size(53, 12);
			this->lbl_PatternShape->TabIndex = 2;
			this->lbl_PatternShape->Text = L"���I�Ϊ�";
			// 
			// lbl_PatternStyle
			// 
			this->lbl_PatternStyle->AutoSize = true;
			this->lbl_PatternStyle->Location = System::Drawing::Point(13, 22);
			this->lbl_PatternStyle->Name = L"lbl_PatternStyle";
			this->lbl_PatternStyle->Size = System::Drawing::Size(53, 12);
			this->lbl_PatternStyle->TabIndex = 1;
			this->lbl_PatternStyle->Text = L"���I����";
			// 
			// cboBox_Pattern_Style
			// 
			this->cboBox_Pattern_Style->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboBox_Pattern_Style->FormattingEnabled = true;
			this->cboBox_Pattern_Style->Location = System::Drawing::Point(70, 19);
			this->cboBox_Pattern_Style->Name = L"cboBox_Pattern_Style";
			this->cboBox_Pattern_Style->Size = System::Drawing::Size(104, 20);
			this->cboBox_Pattern_Style->TabIndex = 0;
			this->cboBox_Pattern_Style->SelectedIndexChanged += gcnew System::EventHandler(this, &SettingForm::cboBox_Pattern_Style_SelectedIndexChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 21);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(402, 331);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"�t�ΰѼ�";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chkLimitDotSize);
			this->groupBox1->Location = System::Drawing::Point(6, 65);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(390, 47);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			// 
			// chkLimitDotSize
			// 
			this->chkLimitDotSize->AutoSize = true;
			this->chkLimitDotSize->Enabled = false;
			this->chkLimitDotSize->Location = System::Drawing::Point(8, 19);
			this->chkLimitDotSize->Name = L"chkLimitDotSize";
			this->chkLimitDotSize->Size = System::Drawing::Size(180, 16);
			this->chkLimitDotSize->TabIndex = 14;
			this->chkLimitDotSize->Text = L"����Ҧ����I�I�Z�j��]�w��";
			this->chkLimitDotSize->UseVisualStyleBackColor = true;
			this->chkLimitDotSize->CheckedChanged += gcnew System::EventHandler(this, &SettingForm::chkLimitDotSize_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->numLowerDensity);
			this->groupBox2->Controls->Add(this->numUpperDensity);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(390, 53);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			// 
			// numLowerDensity
			// 
			this->numLowerDensity->Enabled = false;
			this->numLowerDensity->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numLowerDensity->Location = System::Drawing::Point(264, 14);
			this->numLowerDensity->Name = L"numLowerDensity";
			this->numLowerDensity->ReadOnly = true;
			this->numLowerDensity->Size = System::Drawing::Size(72, 22);
			this->numLowerDensity->TabIndex = 16;
			this->numLowerDensity->TabStop = false;
			this->numLowerDensity->ValueChanged += gcnew System::EventHandler(this, &SettingForm::numLowerDensity_ValueChanged);
			// 
			// numUpperDensity
			// 
			this->numUpperDensity->Enabled = false;
			this->numUpperDensity->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numUpperDensity->Location = System::Drawing::Point(89, 14);
			this->numUpperDensity->Name = L"numUpperDensity";
			this->numUpperDensity->ReadOnly = true;
			this->numUpperDensity->Size = System::Drawing::Size(72, 22);
			this->numUpperDensity->TabIndex = 15;
			this->numUpperDensity->TabStop = false;
			this->numUpperDensity->ValueChanged += gcnew System::EventHandler(this, &SettingForm::numUpperDensity_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(181, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 12);
			this->label3->TabIndex = 14;
			this->label3->Text = L"��ܱK�פU��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 12);
			this->label2->TabIndex = 13;
			this->label2->Text = L"��ܱK�פW��";
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Location = System::Drawing::Point(433, 310);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(54, 35);
			this->btn_Cancel->TabIndex = 9;
			this->btn_Cancel->Text = L"����";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &SettingForm::btn_Cancel_Click);
			// 
			// btn_OK
			// 
			this->btn_OK->Location = System::Drawing::Point(433, 269);
			this->btn_OK->Name = L"btn_OK";
			this->btn_OK->Size = System::Drawing::Size(54, 35);
			this->btn_OK->TabIndex = 8;
			this->btn_OK->Text = L"�T�w";
			this->btn_OK->UseVisualStyleBackColor = true;
			this->btn_OK->Click += gcnew System::EventHandler(this, &SettingForm::btn_OK_Click);
			// 
			// SettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 367);
			this->Controls->Add(this->tabControl_Setting);
			this->Controls->Add(this->btn_OK);
			this->Controls->Add(this->btn_Cancel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"SettingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"�ѼƳ]�w";
			this->Load += gcnew System::EventHandler(this, &SettingForm::SettingForm_Load);
			this->tabControl_Setting->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numLowerDensity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numUpperDensity))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void SettingForm_Load(System::Object^  sender, System::EventArgs^  e) {
				
			cboBox_Pattern_Style->Text = "���I����";
			cboBox_Pattern_Style->Items->Add("2D���I");
			cboBox_Pattern_Style->Items->Add("3D���I");
			

			cboBox_Pattern_Shape->Text = "���I�Ϊ�";
			cboBox_Pattern_Shape->Items->Add("���");
			//cboBox_Pattern_Shape->Items->Add("�x��");
			//cboBox_Pattern_Shape->Items->Add("�٧�");
			


			cboBox_Pattern_Style->SelectedIndex = tmpSet_Data->LTPattern_Style;
			cboBox_Pattern_Shape->SelectedIndex = tmpSet_Data->LTPattern_Shape;
			this->txt_X_Shift->Text = Convert::ToString(tmpSet_Data->X_direction_Shift);
			this->txt_Y_Shift->Text	= Convert::ToString(tmpSet_Data->Y_direction_Shift);
			if(tmpSet_Data->PatternDeep >0)
				this->txtPatternDeep->Text =Convert::ToString(tmpSet_Data->PatternDeep);
			else
				this->txtPatternDeep->Text = L"0";

			this->numUpperDensity->Value = Convert::ToInt16(tmpSet_Data->Color_MaxDenValue);
			this->numLowerDensity->Value = Convert::ToInt16(tmpSet_Data->Color_MinDenValue);



			this->chkLimitDotSize->Checked = this->tmpSet_Data->LimitDotSize;
			
			

			//�\�����
			//this->tabPage2->Enabled = false;



			 }
private: System::Void btn_Reset_Click(System::Object^  sender, System::EventArgs^  e) {

			this->cboBox_Pattern_Shape->SelectedIndex = 0;
			this->cboBox_Pattern_Style->SelectedIndex = 0;
			this->txt_X_Shift->Text = L"0";	
			this->txt_Y_Shift->Text = L"0";
			this->txtPatternDeep->Text = L"0";

		 }
private: System::Void btn_OK_Click(System::Object^  sender, System::EventArgs^  e) {



			 try{
				 // �t�ΰѼ�
				
				this->tmpSet_Data->Color_MaxDenValue = (float)this->numUpperDensity->Value;
				this->tmpSet_Data->Color_MinDenValue = (float)this->numLowerDensity->Value;
				this->tmpSet_Data->LimitDotSize = this->chkLimitDotSize->Checked;
				

				// LT �Ѽ�
				 this->tmpSet_Data->LTPattern_Shape = this->cboBox_Pattern_Shape->SelectedIndex;
				 this->tmpSet_Data->LTPattern_Style = this->cboBox_Pattern_Style->SelectedIndex;
				 this->tmpSet_Data->X_direction_Shift = Convert::ToSingle(this->txt_X_Shift->Text);
				 this->tmpSet_Data->Y_direction_Shift = Convert::ToSingle(this->txt_Y_Shift->Text);
				
				 if (this->cboBox_Pattern_Style->SelectedIndex == 1 && Convert::ToSingle(this->txtPatternDeep->Text) <= 0) {
					MessageBox::Show("�`�׭Ȥ@�w�n�j��0");
					return;
				 }else{
					  this->tmpSet_Data->PatternDeep = Convert::ToSingle(this->txtPatternDeep->Text);
					 
				 }
					
				 this->Close();
				
			 }catch(...){
				 MessageBox::Show("��J���~,�Э���");
			 }
			 
		 }

private: System::Void btn_Cancel_Click(System::Object^  sender, System::EventArgs^  e) {
			  this->Close();
		 }



private: System::Void numLowerDensity_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->numLowerDensity->Maximum = this->numUpperDensity->Value;
		 }
private: System::Void numUpperDensity_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->numUpperDensity->Minimum = this->numLowerDensity->Value;
		 }
private: System::Void cboBox_Pattern_Style_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->cboBox_Pattern_Style->SelectedIndex == 0){
				 this->txtPatternDeep->Enabled = false;
			 }else{
				 this->txtPatternDeep->Enabled = true;
			 }
		 }
private: System::Void chkLimitDotSize_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
