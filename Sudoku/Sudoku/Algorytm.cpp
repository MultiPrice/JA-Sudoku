#include "pch.h"
#include "Algorytm.h"
//
//Sudoku_spr::Sudoku_spr()
//{
//	file_name = "";
//}
//
//Sudoku_spr::Sudoku_spr(std::string file_name)
//{
//	laodSudoku(file_name);
//}
//
//bool Sudoku_spr::checkSudoku()
//{
//	std::vector <int> nine;
//	for (int g = 0; g < 9; g++)
//		nine.push_back(0);
//	for(int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++)
//		{
//			nine[tab[j][i]]++;
//			for (int g = 0; g < 9; g++)
//			{
//				if (nine[g] != 1)
//					return false;
//				nine[g] = 0;
//			}
//		}
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++)
//		{
//			nine[tab[i][j]]++;
//			for (int g = 0; g < 9; g++)
//			{
//				if (nine[g] != 1)
//					return false;
//				nine[g] = 0;
//			}
//		}
//	for (int k = 0; k < 9; k += 3)
//		for (int i = k; i < k + 3; i++)
//			for (int l = 0; l < 9; l += 3)
//				for (int j = l; j < l + 3; j++)
//				{
//					nine[tab[j][i]]++;
//					for (int g = 0; g < 9; g++)
//					{
//						if (nine[g] != 1)
//							return false;
//						nine[g] = 0;
//					}
//				}
//	return true;
//}
//
//bool Sudoku_spr::laodSudoku(std::string filename)
//{
//	file_name = filename;
//	std::fstream file;
//	file.open(filename, std::ios::in);
//	if (file.good())
//	{
//		std::string tmp = "";
//		int nr = 0;
//		for (int i = 0; i < 9; i++)
//			for (int j = 0; j < 9; j++)
//			{
//				file >> tmp;
//				if (tmp.length() != 1)
//					return false;
//				else if (!isdigit(tmp[0]))
//					return false;
//				else
//				{
//					nr = (int)(tmp[0]);
//					if (nr < 1 && nr > 9)
//						return false;
//				}
//				tab[j][i] = nr;
//			}
//		if (!file.eof())
//			return false;
//		file.close();
//	}
//	return checkSudoku();
//}

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
		for (int j = 0; j < 9; j++)
		{
			nine[tab[j][i]]++;
			for (int g = 0; g < 9; g++)
			{
				if (nine[g] != 1)
					return false;
				nine[g] = 0;
			}
		}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			nine[tab[i][j]]++;
			for (int g = 0; g < 9; g++)
			{
				if (nine[g] != 1)
					return false;
				nine[g] = 0;
			}
		}
	for (int k = 0; k < 9; k += 3)
		for (int i = k; i < k + 3; i++)
			for (int l = 0; l < 9; l += 3)
				for (int j = l; j < l + 3; j++)
				{
					nine[tab[j][i]]++;
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
	Tuple<String^, String^>^ params = (Tuple<String^, String^>^) parametry; // krotka z parametrami
	// przepisanie parametrów z krotki

	//string bmpPath = msclr::interop::marshal_as<string>(params->Item1);
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(params->Item1)).ToPointer();
	const char* chars2 = (const char*)(Marshal::StringToHGlobalAnsi(params->Item2)).ToPointer();
	string txtPath = chars;
	string savePath = chars2;
	std::fstream file;
	file.open(txtPath, std::ios::in);
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	Marshal::FreeHGlobal(IntPtr((void*)chars2));
	int tab[9][9];
	if (file.good())
	{
		std::string tmp = "";
		int nr = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				file >> tmp;
				if (tmp.length() != 1)
					return;
				else if (!isdigit(tmp[0]))
					return;
				else
				{
					nr = (int)(tmp[0]);
					if (nr < 1 && nr > 9)
						return;
				}
				tab[j][i] = nr;
			}
		if (!file.eof())
			return;
		file.close();
	}
	if (checkSudoku(tab))
		save_to_file(txtPath, savePath, true);
	else
		save_to_file(txtPath, savePath, false);
}
