#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ AssemblerChcekButton;
	private: System::Windows::Forms::RadioButton^ CppCheckButton;
	private: System::Windows::Forms::Button^ SetThreadsButton;
	private: System::Windows::Forms::NumericUpDown^ ThreadsNumber;


	private: System::Windows::Forms::Label^ threadsLabel;
	private: System::Windows::Forms::TextBox^ TimeTextBox;

	private: System::Windows::Forms::TextBox^ SudokuDirecoryText;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ SudokuDirectoryButton;
	private: System::Windows::Forms::Button^ ResultDirectoryButton;


	protected:

	protected:

	protected:


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AssemblerChcekButton = (gcnew System::Windows::Forms::RadioButton());
			this->CppCheckButton = (gcnew System::Windows::Forms::RadioButton());
			this->SetThreadsButton = (gcnew System::Windows::Forms::Button());
			this->ThreadsNumber = (gcnew System::Windows::Forms::NumericUpDown());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->TimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SudokuDirecoryText = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SudokuDirectoryButton = (gcnew System::Windows::Forms::Button());
			this->ResultDirectoryButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsNumber))->BeginInit();
			this->SuspendLayout();
			// 
			// AssemblerChcekButton
			// 
			this->AssemblerChcekButton->AutoSize = true;
			this->AssemblerChcekButton->Location = System::Drawing::Point(254, 129);
			this->AssemblerChcekButton->Margin = System::Windows::Forms::Padding(2);
			this->AssemblerChcekButton->Name = L"AssemblerChcekButton";
			this->AssemblerChcekButton->Size = System::Drawing::Size(73, 17);
			this->AssemblerChcekButton->TabIndex = 0;
			this->AssemblerChcekButton->TabStop = true;
			this->AssemblerChcekButton->Text = L"Assembler";
			this->AssemblerChcekButton->UseVisualStyleBackColor = true;
			// 
			// CppCheckButton
			// 
			this->CppCheckButton->AutoSize = true;
			this->CppCheckButton->Location = System::Drawing::Point(254, 150);
			this->CppCheckButton->Margin = System::Windows::Forms::Padding(2);
			this->CppCheckButton->Name = L"CppCheckButton";
			this->CppCheckButton->Size = System::Drawing::Size(44, 17);
			this->CppCheckButton->TabIndex = 1;
			this->CppCheckButton->TabStop = true;
			this->CppCheckButton->Text = L"C++";
			this->CppCheckButton->UseVisualStyleBackColor = true;
			// 
			// SetThreadsButton
			// 
			this->SetThreadsButton->Location = System::Drawing::Point(315, 12);
			this->SetThreadsButton->Name = L"SetThreadsButton";
			this->SetThreadsButton->Size = System::Drawing::Size(75, 20);
			this->SetThreadsButton->TabIndex = 32;
			this->SetThreadsButton->Text = L"Set threads";
			this->SetThreadsButton->UseVisualStyleBackColor = true;
			// 
			// ThreadsNumber
			// 
			this->ThreadsNumber->Location = System::Drawing::Point(263, 12);
			this->ThreadsNumber->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->ThreadsNumber->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ThreadsNumber->Name = L"ThreadsNumber";
			this->ThreadsNumber->Size = System::Drawing::Size(46, 20);
			this->ThreadsNumber->TabIndex = 31;
			this->ThreadsNumber->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Location = System::Drawing::Point(208, 16);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(49, 13);
			this->threadsLabel->TabIndex = 30;
			this->threadsLabel->Text = L"Threads:";
			// 
			// TimeTextBox
			// 
			this->TimeTextBox->Location = System::Drawing::Point(202, 176);
			this->TimeTextBox->Multiline = true;
			this->TimeTextBox->Name = L"TimeTextBox";
			this->TimeTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->TimeTextBox->Size = System::Drawing::Size(179, 46);
			this->TimeTextBox->TabIndex = 33;
			// 
			// SudokuDirecoryText
			// 
			this->SudokuDirecoryText->Location = System::Drawing::Point(12, 38);
			this->SudokuDirecoryText->Multiline = true;
			this->SudokuDirecoryText->Name = L"SudokuDirecoryText";
			this->SudokuDirecoryText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->SudokuDirecoryText->Size = System::Drawing::Size(195, 70);
			this->SudokuDirecoryText->TabIndex = 34;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(387, 38);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(206, 70);
			this->textBox1->TabIndex = 35;
			// 
			// SudokuDirectoryButton
			// 
			this->SudokuDirectoryButton->Location = System::Drawing::Point(38, 114);
			this->SudokuDirectoryButton->Name = L"SudokuDirectoryButton";
			this->SudokuDirectoryButton->Size = System::Drawing::Size(126, 23);
			this->SudokuDirectoryButton->TabIndex = 36;
			this->SudokuDirectoryButton->Text = L"Open sudoku directory";
			this->SudokuDirectoryButton->UseVisualStyleBackColor = true;
			// 
			// ResultDirectoryButton
			// 
			this->ResultDirectoryButton->Location = System::Drawing::Point(434, 114);
			this->ResultDirectoryButton->Name = L"ResultDirectoryButton";
			this->ResultDirectoryButton->Size = System::Drawing::Size(119, 23);
			this->ResultDirectoryButton->TabIndex = 37;
			this->ResultDirectoryButton->Text = L"Open resoult directory";
			this->ResultDirectoryButton->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 357);
			this->Controls->Add(this->ResultDirectoryButton);
			this->Controls->Add(this->SudokuDirectoryButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->SudokuDirecoryText);
			this->Controls->Add(this->TimeTextBox);
			this->Controls->Add(this->SetThreadsButton);
			this->Controls->Add(this->ThreadsNumber);
			this->Controls->Add(this->threadsLabel);
			this->Controls->Add(this->CppCheckButton);
			this->Controls->Add(this->AssemblerChcekButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Sudoku";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsNumber))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
