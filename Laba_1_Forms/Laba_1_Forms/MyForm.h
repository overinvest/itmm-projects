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
			this->label4->Location = System::Drawing::Point(65, 310);
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
			this->button3->Location = System::Drawing::Point(234, 254);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(36, 54);
			this->button3->TabIndex = 8;
			this->button3->Text = L"~";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(876, 513);
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

		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

			
			
			this->textBox2->Visible = false;
			this->textBox3->Visible = false;
			this->label2->Visible = false;
			this->label3->Visible = false;
			
			if (this->textBox1->Text != "") {
				this->textBox2->Visible = true;
				this->textBox3->Visible = true;
				this->label2->Visible = true;
				this->label3->Visible = true;
				u_size = Convert::ToInt64(this->textBox1->Text);


			}

		}



		
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		TSet A(u_size);
		TSet B(u_size);

		for (int i = 0; i < this->textBox2->Text->Split(' ')->Length; i++) {
			A.Add(Convert::ToInt64(this->textBox2->Text->Split(' ')[i]));
		}

		for (int i = 0; i < this->textBox3->Text->Split(' ')->Length; i++) {
			B.Add(Convert::ToInt64(this->textBox3->Text->Split(' ')[i]));
		}

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
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;

		if (textBox2->Text != "" && textBox2->Text[0] == ' ') {
			textBox2->Text = textBox2->Text->Remove(0, 1);
		}
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;

		if (textBox3->Text != "" && textBox3->Text[0] == ' ') {
			textBox3->Text = textBox3->Text->Remove(0, 1);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		TSet A(u_size);
		TSet B(u_size);

		for (int i = 0; i < this->textBox2->Text->Split(' ')->Length; i++) {
			A.Add(Convert::ToInt64(this->textBox2->Text->Split(' ')[i]));
		}

		for (int i = 0; i < this->textBox3->Text->Split(' ')->Length; i++) {
			B.Add(Convert::ToInt64(this->textBox3->Text->Split(' ')[i]));
		}

		string res = (A | B).TSetToString();
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
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox4->Text = "";

		TSet A(u_size);
		TSet B(u_size);

		for (int i = 0; i < this->textBox2->Text->Split(' ')->Length; i++) {
			A.Add(Convert::ToInt64(this->textBox2->Text->Split(' ')[i]));
		}

		for (int i = 0; i < this->textBox3->Text->Split(' ')->Length; i++) {
			B.Add(Convert::ToInt64(this->textBox3->Text->Split(' ')[i]));
		}

		string res = (~(A | B)).TSetToString();
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
};
}