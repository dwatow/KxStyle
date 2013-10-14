#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "DataStructure.h"

namespace PatternContruction {

	/// <summary>
	/// Summary for ProjectInformation
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ProjectInformation : public System::Windows::Forms::Form
	{
	public:
		ProjectInformation(Project_Information^ prjInfo)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			tmpprjInfo = prjInfo;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProjectInformation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cboMeshSize;
	protected: 

	private: System::Windows::Forms::ComboBox^  cboRegularInk;
	private: System::Windows::Forms::TextBox^  txtSpecialInk;


	private: System::Windows::Forms::ComboBox^  cboScreenSize;
	private: System::Windows::Forms::TextBox^  txtDesignDate;
	private: System::Windows::Forms::TextBox^  txtDesigner;
	private: System::Windows::Forms::TextBox^  txtAngle;
	private: System::Windows::Forms::TextBox^  txtThick;
	private: System::Windows::Forms::TextBox^  txtPatternVersion;
	private: System::Windows::Forms::TextBox^  txtProjectName;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		Project_Information^ tmpprjInfo;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  txtLGP_PNumber;


	private: System::Windows::Forms::ComboBox^  cboLGPMaterial;
	private: System::Windows::Forms::ComboBox^  cboManufactureLocation;

	private: System::Windows::Forms::ComboBox^  cboProductStyle;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btnOk;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cboMeshSize = (gcnew System::Windows::Forms::ComboBox());
			this->cboRegularInk = (gcnew System::Windows::Forms::ComboBox());
			this->txtSpecialInk = (gcnew System::Windows::Forms::TextBox());
			this->cboScreenSize = (gcnew System::Windows::Forms::ComboBox());
			this->txtDesignDate = (gcnew System::Windows::Forms::TextBox());
			this->txtDesigner = (gcnew System::Windows::Forms::TextBox());
			this->txtAngle = (gcnew System::Windows::Forms::TextBox());
			this->txtThick = (gcnew System::Windows::Forms::TextBox());
			this->txtPatternVersion = (gcnew System::Windows::Forms::TextBox());
			this->txtProjectName = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->txtLGP_PNumber = (gcnew System::Windows::Forms::TextBox());
			this->cboLGPMaterial = (gcnew System::Windows::Forms::ComboBox());
			this->cboManufactureLocation = (gcnew System::Windows::Forms::ComboBox());
			this->cboProductStyle = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cboMeshSize
			// 
			this->cboMeshSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboMeshSize->FormattingEnabled = true;
			this->cboMeshSize->Location = System::Drawing::Point(110, 213);
			this->cboMeshSize->Name = L"cboMeshSize";
			this->cboMeshSize->Size = System::Drawing::Size(154, 20);
			this->cboMeshSize->TabIndex = 42;
			// 
			// cboRegularInk
			// 
			this->cboRegularInk->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboRegularInk->FormattingEnabled = true;
			this->cboRegularInk->Location = System::Drawing::Point(110, 66);
			this->cboRegularInk->Name = L"cboRegularInk";
			this->cboRegularInk->Size = System::Drawing::Size(154, 20);
			this->cboRegularInk->TabIndex = 40;
			this->cboRegularInk->SelectedIndexChanged += gcnew System::EventHandler(this, &ProjectInformation::cboRegularInk_SelectedIndexChanged);
			// 
			// txtSpecialInk
			// 
			this->txtSpecialInk->Location = System::Drawing::Point(110, 94);
			this->txtSpecialInk->Name = L"txtSpecialInk";
			this->txtSpecialInk->Size = System::Drawing::Size(93, 22);
			this->txtSpecialInk->TabIndex = 39;
			// 
			// cboScreenSize
			// 
			this->cboScreenSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboScreenSize->FormattingEnabled = true;
			this->cboScreenSize->Location = System::Drawing::Point(110, 182);
			this->cboScreenSize->Name = L"cboScreenSize";
			this->cboScreenSize->Size = System::Drawing::Size(154, 20);
			this->cboScreenSize->TabIndex = 38;
			// 
			// txtDesignDate
			// 
			this->txtDesignDate->Location = System::Drawing::Point(110, 154);
			this->txtDesignDate->Name = L"txtDesignDate";
			this->txtDesignDate->ReadOnly = true;
			this->txtDesignDate->Size = System::Drawing::Size(154, 22);
			this->txtDesignDate->TabIndex = 37;
			// 
			// txtDesigner
			// 
			this->txtDesigner->Location = System::Drawing::Point(110, 126);
			this->txtDesigner->Name = L"txtDesigner";
			this->txtDesigner->Size = System::Drawing::Size(93, 22);
			this->txtDesigner->TabIndex = 36;
			// 
			// txtAngle
			// 
			this->txtAngle->Location = System::Drawing::Point(110, 267);
			this->txtAngle->Name = L"txtAngle";
			this->txtAngle->Size = System::Drawing::Size(93, 22);
			this->txtAngle->TabIndex = 35;
			// 
			// txtThick
			// 
			this->txtThick->Location = System::Drawing::Point(110, 239);
			this->txtThick->Name = L"txtThick";
			this->txtThick->Size = System::Drawing::Size(93, 22);
			this->txtThick->TabIndex = 34;
			// 
			// txtPatternVersion
			// 
			this->txtPatternVersion->Location = System::Drawing::Point(110, 34);
			this->txtPatternVersion->Name = L"txtPatternVersion";
			this->txtPatternVersion->Size = System::Drawing::Size(93, 22);
			this->txtPatternVersion->TabIndex = 33;
			// 
			// txtProjectName
			// 
			this->txtProjectName->Location = System::Drawing::Point(110, 6);
			this->txtProjectName->Name = L"txtProjectName";
			this->txtProjectName->Size = System::Drawing::Size(93, 22);
			this->txtProjectName->TabIndex = 32;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 41);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(61, 12);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Pattern版次";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 157);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 12);
			this->label8->TabIndex = 30;
			this->label8->Text = L"設計日期";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 129);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 12);
			this->label7->TabIndex = 29;
			this->label7->Text = L"設計者";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 270);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 12);
			this->label6->TabIndex = 28;
			this->label6->Text = L"網版角度";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 12);
			this->label5->TabIndex = 27;
			this->label5->Text = L"乳厚";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 12);
			this->label4->TabIndex = 26;
			this->label4->Text = L"網目";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 25;
			this->label3->Text = L"網版大小";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 12);
			this->label2->TabIndex = 24;
			this->label2->Text = L"油墨種類";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 23;
			this->label1->Text = L"機種名稱";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnOk);
			this->groupBox1->Controls->Add(this->txtLGP_PNumber);
			this->groupBox1->Controls->Add(this->cboLGPMaterial);
			this->groupBox1->Controls->Add(this->cboManufactureLocation);
			this->groupBox1->Controls->Add(this->cboProductStyle);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Location = System::Drawing::Point(1, 295);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(297, 150);
			this->groupBox1->TabIndex = 43;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"產品訊息";
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(220, 103);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(71, 30);
			this->btnOk->TabIndex = 44;
			this->btnOk->Text = L"確定";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &ProjectInformation::btnOk_Click_1);
			// 
			// txtLGP_PNumber
			// 
			this->txtLGP_PNumber->Location = System::Drawing::Point(109, 21);
			this->txtLGP_PNumber->Name = L"txtLGP_PNumber";
			this->txtLGP_PNumber->Size = System::Drawing::Size(154, 22);
			this->txtLGP_PNumber->TabIndex = 43;
			// 
			// cboLGPMaterial
			// 
			this->cboLGPMaterial->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboLGPMaterial->FormattingEnabled = true;
			this->cboLGPMaterial->Location = System::Drawing::Point(109, 112);
			this->cboLGPMaterial->Name = L"cboLGPMaterial";
			this->cboLGPMaterial->Size = System::Drawing::Size(105, 20);
			this->cboLGPMaterial->TabIndex = 42;
			// 
			// cboManufactureLocation
			// 
			this->cboManufactureLocation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboManufactureLocation->FormattingEnabled = true;
			this->cboManufactureLocation->Location = System::Drawing::Point(109, 84);
			this->cboManufactureLocation->Name = L"cboManufactureLocation";
			this->cboManufactureLocation->Size = System::Drawing::Size(105, 20);
			this->cboManufactureLocation->TabIndex = 41;
			// 
			// cboProductStyle
			// 
			this->cboProductStyle->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboProductStyle->FormattingEnabled = true;
			this->cboProductStyle->Location = System::Drawing::Point(109, 55);
			this->cboProductStyle->Name = L"cboProductStyle";
			this->cboProductStyle->Size = System::Drawing::Size(105, 20);
			this->cboProductStyle->TabIndex = 40;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(11, 112);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(50, 12);
			this->label13->TabIndex = 32;
			this->label13->Text = L"LGP材質";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 84);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 12);
			this->label12->TabIndex = 31;
			this->label12->Text = L"製造地";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(11, 58);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 12);
			this->label11->TabIndex = 30;
			this->label11->Text = L"產品型態";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(11, 30);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(74, 12);
			this->label10->TabIndex = 29;
			this->label10->Text = L"LGP客戶料號";
			// 
			// ProjectInformation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 445);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->cboMeshSize);
			this->Controls->Add(this->cboRegularInk);
			this->Controls->Add(this->txtSpecialInk);
			this->Controls->Add(this->cboScreenSize);
			this->Controls->Add(this->txtDesignDate);
			this->Controls->Add(this->txtDesigner);
			this->Controls->Add(this->txtAngle);
			this->Controls->Add(this->txtThick);
			this->Controls->Add(this->txtPatternVersion);
			this->Controls->Add(this->txtProjectName);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ProjectInformation";
			this->Text = L"ProjectInformation";
			this->Load += gcnew System::EventHandler(this, &ProjectInformation::ProjectInformation_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ProjectInformation_Load(System::Object^  sender, System::EventArgs^  e) {

				this->cboRegularInk->Items->Add("Others ....");
				this->cboRegularInk->Items->Add("CLCD-B20-25");
				this->cboRegularInk->Items->Add("CLCD-B20-20");
				this->cboRegularInk->Items->Add("CLCD-B20-15");
				this->cboRegularInk->Items->Add("CLCD-B20-10");
				this->cboRegularInk->Items->Add("H(80:20)Ink");
				this->cboRegularInk->Items->Add("G(70:30)Ink");
				this->cboRegularInk->Items->Add("E(60:40)Ink");
				//MNT 用的油墨  
				this->cboRegularInk->Items->Add("C-Pius-I80(50:50-I80)");
				this->cboRegularInk->Items->Add("C-Pius-I80(40:60-I80)");


				this->cboScreenSize->Items->Add("1500 X 1800 ");
				this->cboScreenSize->Items->Add("1300 X 1500 ");
				this->cboScreenSize->Items->Add("1100 X 1300 ");
				this->cboScreenSize->Items->Add("1300 X 1800 ");
				//MNT 用的網版
				this->cboScreenSize->Items->Add("900 X 1050 ");
				this->cboScreenSize->Items->Add("800 X 800 ");
				

				this->cboMeshSize->Items->Add("NBC 305S#");
				this->cboMeshSize->Items->Add("NBC 315T#");
				this->cboMeshSize->Items->Add("NBC 315S#");
				this->cboMeshSize->Items->Add("NBC 420S#");



				this->txtAngle->Text = Convert::ToString(tmpprjInfo->ScreenAngle);
			    this->txtDesigner->Text = tmpprjInfo->Designer;
			    this->txtDesignDate->Text = tmpprjInfo->DesignDate;
			    this->txtPatternVersion->Text = tmpprjInfo->PatternVersion;
			    this->txtProjectName->Text = tmpprjInfo->projectName;
			    this->txtSpecialInk->Text = tmpprjInfo->SpecialInk;
			    this->txtThick->Text = Convert::ToString(tmpprjInfo->Thick);
			    this->cboMeshSize->SelectedIndex::set(tmpprjInfo->MeshSize);
			    this->cboRegularInk->SelectedIndex::set(tmpprjInfo->RegularInkProperty);
			    this->cboScreenSize->SelectedIndex::set(tmpprjInfo->ScreenSize);



				//產品特性 --------------------------------------------------------------------

				//產品型態 :
				this->cboProductStyle->Items->Add("BLU");
				this->cboProductStyle->Items->Add("LGP");

				//製造地 :
				this->cboManufactureLocation->Items->Add("台灣-TW");
				this->cboManufactureLocation->Items->Add("大陸-LC");
				this->cboManufactureLocation->Items->Add("大陸-LMO");


				//LGP材質 :

				this->cboLGPMaterial->Items->Add("PMMA");
				this->cboLGPMaterial->Items->Add("三菱-LNX865");
				

				this->cboProductStyle->SelectedIndex::set(tmpprjInfo->ProductionStyle);
				this->cboLGPMaterial->SelectedIndex::set(tmpprjInfo->LGP_Material);
				this->cboManufactureLocation->SelectedIndex::set(tmpprjInfo->LGP_Manufacture);
				this->txtLGP_PNumber->Text = tmpprjInfo->LGP_PN_Number;

				

				//------------------------------------------------------------------------------


			 }
private: System::Void cboRegularInk_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 	if(this->cboRegularInk->SelectedIndex == 0){
					this->txtSpecialInk->Enabled = true;
				}else{
					this->txtSpecialInk->Enabled = false;
				}
		 }
private: System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e) {


			 
		 }
private: System::Void btnOk_Click_1(System::Object^  sender, System::EventArgs^  e) {


			 if(this->txtAngle->Text != "") tmpprjInfo->ScreenAngle = Convert::ToSingle(this->txtAngle->Text);
			 else tmpprjInfo->ScreenAngle = 0;
			 tmpprjInfo->Designer    = this->txtDesigner->Text ;
			 tmpprjInfo->DesignDate  = this->txtDesignDate->Text ; 
			 tmpprjInfo->PatternVersion = this->txtPatternVersion->Text;
			 tmpprjInfo->projectName = this->txtProjectName->Text;
			 tmpprjInfo->SpecialInk  = this->txtSpecialInk->Text;
			 if(this->txtThick->Text != "") tmpprjInfo->Thick = Convert::ToSingle(this->txtThick->Text) ;
			 else tmpprjInfo->Thick = 0;
			 tmpprjInfo->MeshSize    = this->cboMeshSize->SelectedIndex::get();
			 tmpprjInfo->RegularInkProperty = this->cboRegularInk->SelectedIndex::get();
			 tmpprjInfo->ScreenSize  = this->cboScreenSize->SelectedIndex::get();


			 //產品資訊 

			 tmpprjInfo->LGP_Manufacture = this->cboManufactureLocation->SelectedIndex::get();
			 tmpprjInfo->LGP_Material    = this->cboLGPMaterial->SelectedIndex::get();
			 tmpprjInfo->ProductionStyle = this->cboProductStyle->SelectedIndex::get();
			 tmpprjInfo->LGP_PN_Number   = this->txtLGP_PNumber->Text;






			 this->Close();



		 }
};
}
