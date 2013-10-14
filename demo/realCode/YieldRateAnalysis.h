#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PatternContruction {

	/// <summary>
	/// YieldRateAnalysis 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class YieldRateAnalysis : public System::Windows::Forms::Form
	{
	public:
		YieldRateAnalysis(void)
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
		~YieldRateAnalysis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label9;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(298, 154);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 21);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(227, 129);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"BLU購規";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->textBox5);
			this->tabPage2->Controls->Add(this->textBox4);
			this->tabPage2->Controls->Add(this->textBox3);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Location = System::Drawing::Point(4, 21);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(290, 129);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"LightBar 購規";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->label9);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label8);
			this->tabPage3->Controls->Add(this->label7);
			this->tabPage3->Location = System::Drawing::Point(4, 21);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(288, 129);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"LGP 製程能力";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"輝度(MIN)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"均度(MIN)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 12);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Typ Bin Lm 值";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(78, 12);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Min Bin Lm 值";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 65);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 12);
			this->label6->TabIndex = 3;
			this->label6->Text = L"單Bin Range";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 12);
			this->label7->TabIndex = 1;
			this->label7->Text = L"輝度";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(141, 21);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 12);
			this->label8->TabIndex = 2;
			this->label8->Text = L"均度";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 74);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 12);
			this->label10->TabIndex = 4;
			this->label10->Text = L"標準差";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 46);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 12);
			this->label11->TabIndex = 5;
			this->label11->Text = L"平均值";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(114, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(61, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(114, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(61, 22);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(90, 6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 22);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(90, 34);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(61, 22);
			this->textBox4->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 12);
			this->label2->TabIndex = 5;
			this->label2->Text = L"來料 LightBar";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(114, 68);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(78, 20);
			this->comboBox1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(226, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"計算";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(90, 62);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(61, 22);
			this->textBox5->TabIndex = 6;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(141, 46);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 12);
			this->label9->TabIndex = 6;
			this->label9->Text = L"平均值";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(141, 74);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 12);
			this->label12->TabIndex = 7;
			this->label12->Text = L"標準差";
			// 
			// YieldRateAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(322, 213);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"YieldRateAnalysis";
			this->Text = L"YieldRateAnalysis";
			this->Load += gcnew System::EventHandler(this, &YieldRateAnalysis::YieldRateAnalysis_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void YieldRateAnalysis_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
