#pragma once

#include <string>
#include <xstring>
#include <windows.h>
#include <iostream>

namespace ITMMGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ITMM_Form
	/// </summary>
	public ref class ITMM_Form : public System::Windows::Forms::Form
	{
	public:
		ITMM_Form(void)
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
		~ITMM_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		/// 
		
		int current_tab = 1;
		int entered_integer;

		int x_integer, y_integer;

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(0, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Задание 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ITMM_Form::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(201, 1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(205, 31);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Задание 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ITMM_Form::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(403, 1);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(205, 31);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Задание 3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ITMM_Form::button3_Click);
			//
			// button4
			//
			this->button4->Location = System::Drawing::Point(12, 112 + 36);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(64, 31);
			this->button4->TabIndex = 2;
			this->button4->Text = L"-";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ITMM_Form::button4_Click);
			//
			// button4
			//
			this->button5->Location = System::Drawing::Point(12 + 66, 112 + 36);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(64, 31);
			this->button5->TabIndex = 2;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ITMM_Form::button5_Click);
			//
			// button4
			//
			this->button6->Location = System::Drawing::Point(12 + 66 * 2, 112 + 36);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(64, 31);
			this->button6->TabIndex = 2;
			this->button6->Text = L"*";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ITMM_Form::button6_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 64);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(202, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"1";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ITMM_Form::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox2->Location = System::Drawing::Point(12, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(202, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"1";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &ITMM_Form::textBox2_TextChanged);
			//
			this->textBox3->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox3->Location = System::Drawing::Point(12, 112 + 36 + 45);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(202, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &ITMM_Form::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"X:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Y:";
			// 
			// label2
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 181);
			this->label3->Name = L"label2";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Result";
			// 
			// ITMM_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(609, 385);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"ITMM_Form";
			this->Text = L"ITMM GUI | uwu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		current_tab = 1;


		label1->Visible = true;
		label2->Visible = true;
		textBox1->Visible = true;
		textBox2->Visible = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		current_tab = 2;

		label1->Visible = false;
		label2->Visible = false;
		textBox1->Visible = false;
		textBox2->Visible = false;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		current_tab = 3;

		label1->Visible = false;
		label2->Visible = false;
		textBox1->Visible = false;
		textBox2->Visible = false;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int result = x_integer - y_integer;

		textBox3->Text = System::Convert::ToString(result);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		int result = x_integer + y_integer;

		textBox3->Text = System::Convert::ToString(result);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		int result = x_integer * y_integer;

		textBox3->Text = System::Convert::ToString(result);
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
		const std::string integers = "1234567890";
	
		for (int j = 0; j < textBox1->Text->Length; j++) {
			bool is_int = false;
	
			for (int i = 0; i < integers.length(); i++) {
	
				if ((textBox1->Text[j] == integers[i])) {
					is_int = true;
					break;
				}
			}
	
			if (!is_int) {
				textBox1->Text = textBox1->Text->Remove(j, 1);
			}
		}
	
		if (textBox1->Text->Length > 0) {
			x_integer = System::Convert::ToInt32(textBox1->Text);
	
			// textBox2->Text = System::Convert::ToString(entered_integer * 2);
		}
		else {
			x_integer = 0;
			// textBox2->Text = System::Convert::ToString(0);
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	   const std::string integers = "1234567890";

	   for (int j = 0; j < textBox2->Text->Length; j++) {
		   bool is_int = false;

		   for (int i = 0; i < integers.length(); i++) {

			   if ((textBox2->Text[j] == integers[i])) {
				   is_int = true;
				   break;
			   }
		   }

		   if (!is_int) {
			   textBox2->Text = textBox2->Text->Remove(j, 1);
		   }
	   }

	   if (textBox2->Text->Length > 0) {
		   y_integer = System::Convert::ToInt32(textBox2->Text);

		   // textBox2->Text = System::Convert::ToString(entered_integer * 2);
	   }
	   else {
		   y_integer = 0;
		   // textBox2->Text = System::Convert::ToString(0);
	   }
	}
};
}
