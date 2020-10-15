#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class Sudoku
{
	std::string file_name;
	int tab[9][9];

public:
	bool checkSudoku();
	bool laodSudoku(std::string filename);

};