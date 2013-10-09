#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PatternContruction {

	/// <summary>
	/// DataBaseForm ���K�n
	///
	/// ĵ�i: �p�G�z�ܧ�o�����O���W�١A�N�����ܧ�P�o�����O�Ҩ̾ڤ��Ҧ� .resx �ɮ����p��
	///          Managed �귽�sĶ���u�㪺 'Resource File Name' �ݩʡC
	///          �_�h�A�o�ǳ]�p�u��
	///          �N�L�k�P�o�Ӫ�����p����a�y�t�Ƹ귽
	///          ���T���ʡC
	/// </summary>
	public ref class DataBaseForm : public System::Windows::Forms::Form
	{
	public:
		DataBaseForm(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~DataBaseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  idDataGridViewTextBoxColumn;
	private: System::Windows::Forms::BindingSource^  parameterDataBindingSource;
	private: PatternContruction::ParameterData^  ParameterData;
	private: System::Windows::Forms::Button^  btnDB;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�o�Ӥ�k�����e�C
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->parameterDataBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->ParameterData = (gcnew PatternContruction::ParameterData());
			this->btnDB = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->parameterDataBindingSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ParameterData))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->DataMember = L"DataTable1";
			this->dataGridView1->DataSource = this->parameterDataBindingSource;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(312, 272);
			this->dataGridView1->TabIndex = 0;
			// 
			// parameterDataBindingSource
			// 
			this->parameterDataBindingSource->DataSource = this->ParameterData;
			this->parameterDataBindingSource->Position = 0;
			// 
			// ParameterData
			// 
			this->ParameterData->DataSetName = L"ParameterData";
			this->ParameterData->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
			// 
			// btnDB
			// 
			this->btnDB->Location = System::Drawing::Point(12, 290);
			this->btnDB->Name = L"btnDB";
			this->btnDB->Size = System::Drawing::Size(85, 29);
			this->btnDB->TabIndex = 1;
			this->btnDB->Text = L"�s�����Ʈw";
			this->btnDB->UseVisualStyleBackColor = true;
			this->btnDB->Click += gcnew System::EventHandler(this, &DataBaseForm::btnDB_Click);
			// 
			// DataBaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 331);
			this->Controls->Add(this->btnDB);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"DataBaseForm";
			this->Text = L"DataBaseForm";
			this->Load += gcnew System::EventHandler(this, &DataBaseForm::DataBaseForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->parameterDataBindingSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ParameterData))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DataBaseForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void btnDB_Click(System::Object^  sender, System::EventArgs^  e) {


			 

			 
			
			

			 

			 
		 }
};
}
