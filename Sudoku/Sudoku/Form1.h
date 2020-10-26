#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
//#include <Windows.h>
#include <string>
//#include <msclr\marshal_cppstd.h>
#include <chrono>
#include <thread>
#include <filesystem>
#include <experimental/filesystem>

#include "Algorytm.h"
#include "pch.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::Configuration;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace std::chrono;
	using namespace Runtime::InteropServices;
	//using namespace msclr::interop;
	namespace fs = std::experimental::filesystem::v1;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Sudoku_s^ sud;
		Form1(void)
		{
			InitializeComponent();
			sud = gcnew Sudoku_s();
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



	private: System::Windows::Forms::TextBox^ TimeTextBox;

	private: System::Windows::Forms::TextBox^ SudokuDirecoryText;
	private: System::Windows::Forms::TextBox^ ResoultFileText;


	private: System::Windows::Forms::Button^ SudokuDirectoryButton;
	private: System::Windows::Forms::Button^ ResultFileButton;

	System::String^ strfilename;
	bool CppOrAsm;
	System::String^ directoryname;
	
	private: System::Windows::Forms::Button^ Start;

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
			this->TimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SudokuDirecoryText = (gcnew System::Windows::Forms::TextBox());
			this->ResoultFileText = (gcnew System::Windows::Forms::TextBox());
			this->SudokuDirectoryButton = (gcnew System::Windows::Forms::Button());
			this->ResultFileButton = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsNumber))->BeginInit();
			this->SuspendLayout();
			// 
			// AssemblerChcekButton
			// 
			this->AssemblerChcekButton->AutoSize = true;
			this->AssemblerChcekButton->Location = System::Drawing::Point(339, 159);
			this->AssemblerChcekButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AssemblerChcekButton->Name = L"AssemblerChcekButton";
			this->AssemblerChcekButton->Size = System::Drawing::Size(95, 21);
			this->AssemblerChcekButton->TabIndex = 0;
			this->AssemblerChcekButton->TabStop = true;
			this->AssemblerChcekButton->Text = L"Assembler";
			this->AssemblerChcekButton->UseVisualStyleBackColor = true;
			this->AssemblerChcekButton->CheckedChanged += gcnew System::EventHandler(this, &Form1::AssemblerChcekButton_CheckedChanged);
			// 
			// CppCheckButton
			// 
			this->CppCheckButton->AutoSize = true;
			this->CppCheckButton->Location = System::Drawing::Point(339, 185);
			this->CppCheckButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CppCheckButton->Name = L"CppCheckButton";
			this->CppCheckButton->Size = System::Drawing::Size(54, 21);
			this->CppCheckButton->TabIndex = 1;
			this->CppCheckButton->TabStop = true;
			this->CppCheckButton->Text = L"C++";
			this->CppCheckButton->UseVisualStyleBackColor = true;
			this->CppCheckButton->CheckedChanged += gcnew System::EventHandler(this, &Form1::CppCheckButton_CheckedChanged);
			// 
			// SetThreadsButton
			// 
			this->SetThreadsButton->Location = System::Drawing::Point(389, 15);
			this->SetThreadsButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->SetThreadsButton->Name = L"SetThreadsButton";
			this->SetThreadsButton->Size = System::Drawing::Size(100, 25);
			this->SetThreadsButton->TabIndex = 32;
			this->SetThreadsButton->Text = L"Set threads";
			this->SetThreadsButton->UseVisualStyleBackColor = true;
			this->SetThreadsButton->Click += gcnew System::EventHandler(this, &Form1::SetThreadsButton_Click);
			// 
			// ThreadsNumber
			// 
			this->ThreadsNumber->Location = System::Drawing::Point(305, 15);
			this->ThreadsNumber->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ThreadsNumber->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->ThreadsNumber->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ThreadsNumber->Name = L"ThreadsNumber";
			this->ThreadsNumber->Size = System::Drawing::Size(76, 22);
			this->ThreadsNumber->TabIndex = 31;
			this->ThreadsNumber->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ThreadsNumber->ValueChanged += gcnew System::EventHandler(this, &Form1::ThreadsNumber_ValueChanged);
			// 
			// TimeTextBox
			// 
			this->TimeTextBox->Location = System::Drawing::Point(277, 212);
			this->TimeTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->TimeTextBox->Multiline = true;
			this->TimeTextBox->Name = L"TimeTextBox";
			this->TimeTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->TimeTextBox->Size = System::Drawing::Size(237, 56);
			this->TimeTextBox->TabIndex = 33;
			this->TimeTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::TimeTextBox_TextChanged);
			// 
			// SudokuDirecoryText
			// 
			this->SudokuDirecoryText->Location = System::Drawing::Point(16, 47);
			this->SudokuDirecoryText->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->SudokuDirecoryText->Multiline = true;
			this->SudokuDirecoryText->Name = L"SudokuDirecoryText";
			this->SudokuDirecoryText->ReadOnly = true;
			this->SudokuDirecoryText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->SudokuDirecoryText->Size = System::Drawing::Size(259, 85);
			this->SudokuDirecoryText->TabIndex = 34;
			this->SudokuDirecoryText->TextChanged += gcnew System::EventHandler(this, &Form1::SudokuDirecoryText_TextChanged);
			// 
			// ResoultFileText
			// 
			this->ResoultFileText->Location = System::Drawing::Point(516, 47);
			this->ResoultFileText->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ResoultFileText->Multiline = true;
			this->ResoultFileText->Name = L"ResoultFileText";
			this->ResoultFileText->ReadOnly = true;
			this->ResoultFileText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->ResoultFileText->Size = System::Drawing::Size(273, 85);
			this->ResoultFileText->TabIndex = 35;
			this->ResoultFileText->TextChanged += gcnew System::EventHandler(this, &Form1::ResoultFileText_TextChanged);
			// 
			// SudokuDirectoryButton
			// 
			this->SudokuDirectoryButton->Location = System::Drawing::Point(51, 140);
			this->SudokuDirectoryButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->SudokuDirectoryButton->Name = L"SudokuDirectoryButton";
			this->SudokuDirectoryButton->Size = System::Drawing::Size(168, 28);
			this->SudokuDirectoryButton->TabIndex = 36;
			this->SudokuDirectoryButton->Text = L"Open sudoku directory";
			this->SudokuDirectoryButton->UseVisualStyleBackColor = true;
			this->SudokuDirectoryButton->Click += gcnew System::EventHandler(this, &Form1::SudokuDirectoryButton_Click);
			// 
			// ResultFileButton
			// 
			this->ResultFileButton->Location = System::Drawing::Point(579, 140);
			this->ResultFileButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ResultFileButton->Name = L"ResultFileButton";
			this->ResultFileButton->Size = System::Drawing::Size(159, 28);
			this->ResultFileButton->TabIndex = 37;
			this->ResultFileButton->Text = L"Open resoult file";
			this->ResultFileButton->UseVisualStyleBackColor = true;
			this->ResultFileButton->Click += gcnew System::EventHandler(this, &Form1::ResultFileButton_Click);
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(339, 276);
			this->Start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(100, 25);
			this->Start->TabIndex = 38;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(809, 439);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->ResultFileButton);
			this->Controls->Add(this->SudokuDirectoryButton);
			this->Controls->Add(this->ResoultFileText);
			this->Controls->Add(this->SudokuDirecoryText);
			this->Controls->Add(this->TimeTextBox);
			this->Controls->Add(this->SetThreadsButton);
			this->Controls->Add(this->ThreadsNumber);
			this->Controls->Add(this->CppCheckButton);
			this->Controls->Add(this->AssemblerChcekButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Sudoku";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsNumber))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void SudokuDirecoryText_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			SudokuDirecoryText->Text = directoryname;
		}
		private: System::Void SudokuDirectoryButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			FolderBrowserDialog^ folderBrowserDialog1;
			folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;
			Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

			directoryname = folderBrowserDialog1->SelectedPath;
			SudokuDirecoryText_TextChanged(sender, e);
			//buttonStart->Enabled = true;
		}
		public: System::Void ResoultFileText_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			ResoultFileText->Text = strfilename;
		}
		private: System::Void ResultFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Stream^ myStream;
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if ((myStream = openFileDialog1->OpenFile()) != nullptr)
				{
					strfilename = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
					//System::String^ Readfile = File::ReadAllText(strfilename);
					ResoultFileText_TextChanged(sender, e);
					myStream->Close();
				}
			}
		}
		private: System::Void AssemblerChcekButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			CppOrAsm = false;
		}
		private: System::Void CppCheckButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			CppOrAsm = true;
		}
		private: System::Void TimeTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{

		}
		private: System::Void ThreadsNumber_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
		{

		}
		private: System::Void SetThreadsButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{

		}
		private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			// initialize
			int fileCount = 0;
			int threadCounter = 0;
			int threadMax = Decimal::ToInt32(ThreadsNumber->Value);
			Generic::List<Thread^>^ threadList = gcnew Generic::List<Thread^>();


			System::String^ tmp = directoryname;

			for (const auto& entry : fs::directory_iterator((const char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer()))
			{
				if (entry.path().extension().string() == ".txt")
					if (entry.path().string() != (const char*)(Marshal::StringToHGlobalAnsi(strfilename)).ToPointer())
						fileCount++;
			}
			// leave if none found
			if (fileCount == 0)
			{
				MessageBox::Show("Brak plików w danej lokalizacji!");
				return;
			}
			else if (fileCount < threadMax)
				threadMax = fileCount;

			remove((const char*)(Marshal::StringToHGlobalAnsi(strfilename)).ToPointer());
			fstream file;
			file.open((const char*)(Marshal::StringToHGlobalAnsi(strfilename)).ToPointer());
			file << "";
			file.close();

			//rozpoczêcie zegara do zliczania czasu wykonania
			auto start = high_resolution_clock::now();

			// Wyszukanie plików txt
			for (const auto& entry : fs::directory_iterator((const char*)(Marshal::StringToHGlobalAnsi(tmp)).ToPointer()))
			{
				if (entry.path().extension().string() == ".txt")
				{
					std::string txtPath = entry.path().string();
					
						// Obs³uga w¹tków
						if (threadCounter < threadMax)
						{
							threadList->Add(gcnew Thread(gcnew ParameterizedThreadStart(sud, &Sudoku_s::laodSudoku)));
							
							Tuple<System::String^, System::String^, bool>^ parameter = gcnew Tuple<System::String^, System::String^, bool>(
								gcnew String(txtPath.c_str()),
								strfilename,
								CppOrAsm);

							threadList[threadCounter]->Start(parameter);
							threadCounter++;
						}
						else
						{
							bool found = false;
							while (!found)
							{
								for (int i = 0; i < threadMax; i++)
								{
									if (!threadList[i]->IsAlive)
									{
										found = true;
										threadList[i] = gcnew Thread(gcnew ParameterizedThreadStart(sud, &Sudoku_s::laodSudoku));
										Tuple<System::String^, System::String^, bool>^ parameter = gcnew Tuple<System::String^, System::String^, bool>(
											gcnew String(txtPath.c_str()),
											strfilename,
											CppOrAsm);
										threadList[i]->Start(parameter);
									}
									if (found) break;
								}
							}
						}
				}
			}

			for (int i = 0; i < threadList->Count; i++)
			{
				threadList[i]->Join();
			}

			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			System::String^ timePassed = gcnew String(to_string(duration.count()).c_str());
			TimeTextBox->Text = timePassed;
			MessageBox::Show("Wykonano." + threadMax.ToString());
		}
};
}
