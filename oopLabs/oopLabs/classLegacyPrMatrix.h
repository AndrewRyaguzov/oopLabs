#pragma once
#include "classMatrix.h"

class classLegacyPrMatix : public classMatrix
{
public:
	classLegacyPrMatix() : classMatrix() 
	{
		std::cout << "legacy_2 contstructed, id - " << id << std::endl;
	}
	classLegacyPrMatix( int, int, int * );

private:
	int colums,
		rows;
	//~classLegacyMatix();

public:
	void SetColumsRows( int, int );
	int GetColums()
	{
		return colums;
	}

};