#pragma once
#include "classMatrix.h"

class classLegacyPrMatix : public classMatrix
{
public:
	classLegacyPrMatix() : classMatrix() 
	{
		std::cout << "legacy_2 contstructed, id - " << id << std::endl;
	}

private:
	int colums,
		rows,
		*matrix;
	
public:
	void inputAll()
	{
		std::cout << "input colums: ";
		std::cin >> colums;
		std::cout << "input rows: ";
		std::cin >> rows;

		size = colums * rows;

		if (rows < 1 && colums < 1) std::cout << "wrong order" << std::endl;
		matrix = new int[size];
		std::cout << "Input matrix" << std::endl;
		for (int i = 0; i < size; i++)
			std::cin >> matrix[i];
	}
	
	void transponMatrix()
	{
		int *tmpMatrix = new int[size];
		for (int i = 0, num = 0, row = 0; i < size; num++, i++)
		{
			if (i % rows == 0 && i != 0)
			{
				num = 0;
				row++;
			}
			tmpMatrix[i] = matrix[row + num * colums];
		}

		delete[] matrix;
		matrix = tmpMatrix;

		int tmp = colums;
		colums = rows;
		rows = tmp;
	}

	void showMatrix()
	{
		std::cout << " |";

		for (int i = 0; i < size; i++)
		{
			std::cout << matrix[i];

			if (i + 1 != size)
			{
				if ((i + 1) % colums == 0)
				{
					std::cout << '|' << std::endl << " |";
				}
				else
				{
					std::cout << '\t';
				}
			}
		}
		std::cout << '|' << std::endl
			<< std::endl;
	}

	friend std::ofstream& binWrite(std::ofstream &, classLegacyPrMatix &);
	friend std::ifstream& binRead(std::ifstream &, classLegacyPrMatix &);
};