#pragma once
//#include <iostream>
//#include <vector>
//
//class Sudoku_spr
//{
//	std::string file_name;
//	int tab[9][9];
//
//public:
//	Sudoku_spr();
//	Sudoku_spr(std::string file_name);
//	bool checkSudoku();
//	bool laodSudoku(std::string filename);
//
//};
//#include <Windows.h>
#include <fstream>
#include<string>
#include <vector>
//#include <msclr\marshal_cppstd.h>

extern "C" bool asmCheckSudoku(int* tab);

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Configuration;
using namespace Runtime::InteropServices;

public ref class Sudoku_s
{
public:
	Sudoku_s();
	void save_to_file(std::string file_name, std::string save_file, bool good);
	bool checkSudoku(int tab[9][9]);
	void laodSudoku(Object^ parametry);
};

