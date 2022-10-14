#pragma once
#include "TSet.h"
#include "MyString.h"

namespace Laba1Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void string_split_smart(string str, string razd, string*& result, int& count) {
		for (int i = 0; i < str.length(); i++) {
			int l = razd.find(str[i]);
			if (l < 0 || l > razd.length()) {
				result[count] = result[count] + str[i];
			}
			else {
				if (str[i] == ' ') {
					if (result[count] != "") {
						result[++count] = "";
					}
				}
				else {
					if (result[count] != "") {
						count++;
					}
					result[count] = str[i];
					result[++count] = "";
				}
			}
		}
	}

	TSet A;
	TSet B;

	bool manual_change = false;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

		int u_size = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(534, 9);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Universe:";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(530, 45);
			this->textBox1->MaxLength = 10;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(256, 29);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(69, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(330, 29);
			this->textBox2->TabIndex = 2;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(23, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 31);
			this->label2->TabIndex = 3;
			this->label2->Text = L"A:";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(23, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 31);
			this->label3->TabIndex = 5;
			this->label3->Text = L"B:";
			this->label3->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(69, 179);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(330, 29);
			this->textBox3->TabIndex = 4;
			this->textBox3->Visible = false;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(111, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(42, 54);
			this->button1->TabIndex = 6;
			this->button1->Text = L"∩";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(174, 254);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(39, 54);
			this->button2->TabIndex = 7;
			this->button2->Text = L"∪";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(69, 346);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(717, 155);
			this->textBox4->TabIndex = 9;
			this->textBox4->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(65, 319);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Result:";
			this->label4->Visible = false;
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(342, 231);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(36, 29);
			this->button3->TabIndex = 8;
			this->button3->Text = L"~";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(530, 100);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(114, 29);
			this->textBox5->TabIndex = 11;
			this->textBox5->Visible = false;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress_1);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(530, 179);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(114, 29);
			this->textBox6->TabIndex = 12;
			this->textBox6->Visible = false;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox6_KeyPress);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Location = System::Drawing::Point(650, 100);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(67, 29);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Add";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Location = System::Drawing::Point(723, 100);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(91, 29);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Delete";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Location = System::Drawing::Point(723, 179);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(91, 29);
			this->button6->TabIndex = 16;
			this->button6->Text = L"Delete";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Location = System::Drawing::Point(650, 179);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(67, 29);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Add";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Location = System::Drawing::Point(342, 279);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(36, 29);
			this->button8->TabIndex = 17;
			this->button8->Text = L"~";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(296, 231);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 31);
			this->label5->TabIndex = 18;
			this->label5->Text = L"A:";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(296, 277);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 31);
			this->label6->TabIndex = 19;
			this->label6->Text = L"B:";
			this->label6->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(876, 513);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: System::String^ prev_A = "";
		public: System::String^ prev_B = "";

		private: void ChangeVisible(bool vis) {
			this->textBox2->Visible = vis;
			this->label2->Visible = vis;

			this->label3->Visible = vis;
			this->textBox3->Visible = vis;

			this->button1->Visible = vis;
			this->button2->Visible = vis;

			this->textBox4->Visible = vis;
			this->label4->Visible = vis;

			// Add a
			this->textBox5->Visible = vis;
			this->button4->Visible = vis;
			this->button5->Visible = vis;

			// Add B
			this->textBox6->Visible = vis;
			this->button6->Visible = vis;
			this->button7->Visible = vis;

			// ~ A
			this->button3->Visible = vis;
			this->label5->Visible = vis;

			// ~ B
			this->button8->Visible = vis;
			this->label6->Visible = vis;
		}

		private: void ChangeVisibleAdditionButtons(bool vis) {
			// Add a
			this->textBox5->Visible = vis;
			this->button4->Visible = vis;
			this->button5->Visible = vis;

			// Add B
			this->textBox6->Visible = vis;
			this->button6->Visible = vis;
			this->button7->Visible = vis;
		}

		private: void ChangeVisibleFunctionsButtons(bool vis) {
			this->textBox2->Visible = vis;
			this->label2->Visible = vis;

			this->label3->Visible = vis;
			this->textBox3->Visible = vis;

			this->button1->Visible = vis && A.GetSize() > 0 && B.GetSize() > 0;
			this->button2->Visible = vis && A.GetSize() > 0 && B.GetSize() > 0;
		}

		private: void ChangeVisibleResult(bool vis) {
			this->textBox4->Visible = vis && (A.GetSize() > 0 || B.GetSize() > 0);
			this->label4->Visible = vis && (A.GetSize() > 0 || B.GetSize() > 0);

			if ( !(vis && (A.GetSize() > 0 || B.GetSize() > 0)) ) {
				this->textBox4->Text = "";
			}
		}

		private: void ChangeVisibleA(bool vis) {
			// ~ A
			this->button3->Visible = vis && A.GetSize() > 0;
			this->label5->Visible = vis && A.GetSize() > 0;
		}

		private: void ChangeVisibleB(bool vis) {
			// ~ B
			this->button8->Visible = vis && B.GetSize() > 0;
			this->label6->Visible = vis && B.GetSize() > 0;
		}

		private: bool contains(System::Array^ data, System::Object^ val) {

			for (int i = 0; i < data->Length; i++) {
				if (data->GetValue(i) == val) {
					return true;
				}
			}
			return false;
		}

		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

			ChangeVisible(false);
			
			if (this->textBox1->Text != "") {

				ChangeVisibleAdditionButtons(true);
				ChangeVisibleFunctionsButtons(true);

				u_size = Convert::ToInt64(this->textBox1->Text);

				A = TSet(u_size);
				B = TSet(u_size);
			}

		}
		
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		string res = (A & B).TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox4->Text += Convert::ToString(atoi(splitted[i].c_str())) + " ";
		}
			 
		this->textBox4->Visible = true;
		this->label4->Visible = true;

	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar))/* && e->KeyChar != '.'*/) {
			e->Handled = true;
		}

	}

	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar)) && e->KeyChar != ' ') {
			e->Handled = true;
		}
	}
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar)) && e->KeyChar != ' ') {
			if (this->textBox3->Text[0] != ' ') {
				e->Handled = true;
			}
		}
	}
	private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar))/* && e->KeyChar != '.'*/) {
			if (this->textBox4->Text[0] != ' ') {
				e->Handled = true;
			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		string res = (A | B).TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox4->Text += Convert::ToString(atoi(splitted[i].c_str())) + " ";
		}

		ChangeVisibleResult(true);

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		string res = (~A).TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox4->Text += Convert::ToString(atoi(splitted[i].c_str())) + " ";
		}

		ChangeVisibleResult(true);

	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox5->Text->Length == 0)
			return;

		manual_change = true;

		this->textBox2->Text = "";

		A.Add(Convert::ToInt64(this->textBox5->Text));

		string res = A.TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox2->Text += Convert::ToString(atoi(splitted[i].c_str()));
			if (i < count) {
				this->textBox2->Text += " ";
			}
		}

		prev_A = this->textBox2->Text;

		ChangeVisibleFunctionsButtons(true);
		ChangeVisibleA(true);
		ChangeVisibleResult(true);
	}	
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox5->Text->Length == 0)
			return;

		manual_change = true;

		this->textBox2->Text = "";

		A.Del(Convert::ToInt64(this->textBox5->Text));

		string res = A.TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox2->Text += Convert::ToString(atoi(splitted[i].c_str()));
			if (i < count) {
				this->textBox2->Text += " ";
			}
		}

		ChangeVisibleFunctionsButtons(true);
		ChangeVisibleA(true);
		ChangeVisibleResult(true);
	}
	private: System::Void textBox5_KeyPress_1(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar))/* && e->KeyChar != '.'*/) {
			e->Handled = true;
		}
	}
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!(System::Char::IsControl(e->KeyChar)) && !(System::Char::IsDigit(e->KeyChar))/* && e->KeyChar != '.'*/) {
			e->Handled = true;
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox6->Text->Length == 0)
			return;

		manual_change = true;

		this->textBox3->Text = "";

		B.Add(Convert::ToInt64(this->textBox6->Text));

		string res = B.TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox3->Text += Convert::ToString(atoi(splitted[i].c_str()));
			if (i < count) {
				this->textBox3->Text += " ";
			}
		}

		ChangeVisibleFunctionsButtons(true);
		ChangeVisibleB(true);
		ChangeVisibleResult(true);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox6->Text->Length == 0)
			return;

		manual_change = true;

		this->textBox3->Text = "";

		B.Del(Convert::ToInt64(this->textBox6->Text));

		string res = B.TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox3->Text += Convert::ToString(atoi(splitted[i].c_str()));
			if (i < count) {
				this->textBox3->Text += " ";
			}
		}

		ChangeVisibleFunctionsButtons(true);
		ChangeVisibleB(true);
		ChangeVisibleResult(true);
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox4->Text = "";

		string res = (~B).TSetToString();
		string* splitted;
		int count = 0;

		splitted = new string[res.length() / 2 + 2];

		splitted[0] = "";

		string_split_smart(res, " ", splitted, count);

		for (int i = 0; i < count + 1; i++) {
			this->textBox4->Text += Convert::ToString(atoi(splitted[i].c_str())) + " ";
		}

		ChangeVisibleResult(true);
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (manual_change) {
			manual_change = false;
			return;
		}

		string res = A.TSetToString();
		if (res.length() > 0) {
			string* splitted;
			int count = 0;

			splitted = new string[res.length() / 2 + 2];

			splitted[0] = "";

			string_split_smart(res, " ", splitted, count);

			for (int i = 0; i < count + 1; i++) {
				if (splitted[i] != "") {
					A.Del(atoi(splitted[i].c_str()));
					ChangeVisibleFunctionsButtons(true);
					ChangeVisibleA(true);
					ChangeVisibleResult(true);
				}
			}
		}

		System::Array^ A_data = this->textBox2->Text->Split(' ');
		int current_size = A_data->Length;

		for (int i = 0; i < current_size; i++) {
			System::Object^ val = A_data->GetValue(i);

			bool is_int = true;

			try {
				Convert::ToInt64(A_data->GetValue(i));
			}
			catch (...) {
				is_int = false;
			}

			if (is_int) {
				A.Add(Convert::ToInt64(A_data->GetValue(i)));
				ChangeVisibleFunctionsButtons(true);
				ChangeVisibleA(true);
				ChangeVisibleResult(true);
			}
		}

	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (manual_change) {
			manual_change = false;
			return;
		}

		string res = B.TSetToString();
		if (res.length() > 0) {
			string* splitted;
			int count = 0;

			splitted = new string[res.length() / 2 + 2];

			splitted[0] = "";

			string_split_smart(res, " ", splitted, count);

			for (int i = 0; i < count + 1; i++) {
				if (splitted[i] != "") {
					B.Del(atoi(splitted[i].c_str()));
					ChangeVisibleFunctionsButtons(true);
					ChangeVisibleB(true);
					ChangeVisibleResult(true);
				}
			}
		}

		System::Array^ B_data = this->textBox3->Text->Split(' ');
		int current_size = B_data->Length;

		for (int i = 0; i < current_size; i++) {
			System::Object^ val = B_data->GetValue(i);

			bool is_int = true;

			try {
				Convert::ToInt64(B_data->GetValue(i));
			}
			catch (...) {
				is_int = false;
			}

			if (is_int) {
				B.Add(Convert::ToInt64(B_data->GetValue(i)));
				ChangeVisibleFunctionsButtons(true);
				ChangeVisibleB(true);
				ChangeVisibleResult(true);
			}
		}
	}
};
}