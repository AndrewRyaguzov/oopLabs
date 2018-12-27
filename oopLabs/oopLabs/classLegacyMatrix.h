#pragma once
#include "classMatrix.h"

class classLegacyMatrix : public classMatrix
{
public:
	classLegacyMatrix() : classMatrix() 
	{
		std::cout << "legacy_1 contstructed, id - " << id << std::endl << std::endl;
	}
	classLegacyMatrix(int _order)
	{
		order = _order;
		size = order * order;
		if (order < 1 && size < 1) return;

		matrix = new int[size];
		for (int i = 0, sdv = 0; i < size; i++)
		{
			matrix[i] = 0;
			if ((sdv == i) || (i == 0))
			{
				sdv += order + 1;
				matrix[i] = 1;
			}
		}
	}

	friend std::ifstream& binRead(std::ifstream &, classMatrix &);
	friend std::ofstream& binWrite(std::ofstream &, classMatrix &);
};
