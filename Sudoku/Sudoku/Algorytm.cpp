#include "pch.h"
#include "Algorytm.h"

Sudoku_s::Sudoku_s()
{
	//throw gcnew System::NotImplementedException();
}

void Sudoku_s::save_to_file(std::string file_name, std::string save_file, bool good)
{
	fstream file;
	file.open(file_name, std::ios::app);
	file << save_file << " ";
	if (good)
		file << "dobrze" << std::endl;
	else file << "zle" << std::endl;
}

bool Sudoku_s::checkSudoku(int tab[9][9])
{
	std::vector <int> nine;
	for (int g = 0; g < 9; g++)
		nine.push_back(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			nine[tab[j][i] - 1]++;
		for (int g = 0; g < 9; g++)
		{
			if (nine[g] != 1)
				return false;
			nine[g] = 0;
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			nine[tab[i][j] - 1]++;
		for (int g = 0; g < 9; g++)
		{
			if (nine[g] != 1)
				return false;
			nine[g] = 0;
		}
	}

	for (int k = 0; k < 9; k += 3)
		for (int i = k; i < k + 3; i++)
		{
			for (int l = 0; l < 9; l += 3)
				for (int j = l; j < l + 3; j++)
					nine[tab[j][i] - 1]++;
				for (int g = 0; g < 9; g++)
				{
					if (nine[g] != 1)
						return false;
					nine[g] = 0;
				}
		}
	return true;
}

void Sudoku_s::laodSudoku(Object^ parametry)
{
	Tuple<String^, String^, bool>^ params = (Tuple<String^, String^, bool>^) parametry; // krotka z parametrami
	// przepisanie parametrów z krotki
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(params->Item1)).ToPointer();
	const char* chars2 = (const char*)(Marshal::StringToHGlobalAnsi(params->Item2)).ToPointer();
	bool cppOrAsm = params->Item3;
	string txtPath = chars;
	string savePath = chars2;
	std::fstream file;
	file.open(txtPath, std::ios::in);
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	Marshal::FreeHGlobal(IntPtr((void*)chars2));
	int tab[9][9];
	if (file.good())
	{
		char tmp;
		int nr = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				file >> tmp;
				if (!isdigit(tmp))
				{
					save_to_file(savePath, txtPath, false);
					return;
				}
				else
				{
					nr = (int)(tmp);
					nr -= 48;
					if (nr < 1 && nr > 9)
					{
						save_to_file(savePath, txtPath, false);
						return;
					}
				}
				tab[j][i] = nr;
			}
		file.close();
	}
	if (cppOrAsm)
	{
		if (checkSudoku(tab))
			save_to_file(savePath, txtPath, true);
		else
			save_to_file(savePath, txtPath, false);
	}
	else
	{
		int* tablicowanie = new int [81];
		int index = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				tablicowanie[index] = tab[j][i];
				//MessageBox::Show(tablicowanie[i + j].ToString());
				index++;
			}
		if (asmCheckSudoku(tablicowanie))
		{
			MessageBox::Show("asm true");
			save_to_file(savePath, txtPath, true);
		}
		else
		{
			MessageBox::Show("asm false");
			save_to_file(savePath, txtPath, false);
		}
	}
}
