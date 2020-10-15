#include "Algorytm.h"

bool Sudoku::checkSudoku()
{
	std::vector <int> nine;
	for (int g = 0; g < 9; g++)
		nine.push_back(0);
	for(int i = 0; i < 9; i++)
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

bool Sudoku::laodSudoku(std::string filename)
{
	file_name = filename;
	std::fstream file;
	file.open(filename, std::ios::in);
	if (file.good())
	{
		std::string tmp = "";
		int nr = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				file >> tmp;
				if (tmp.length() != 1)
					return false;
				else if (!isdigit(tmp[0]))
					return false;
				else
				{
					nr = (int)(tmp[0]);
					if (nr < 1 && nr > 9)
						return false;
				}
				tab[j][i] = nr;
			}
		if (!file.eof())
			return false;
		file.close();
	}
	return true;
}
