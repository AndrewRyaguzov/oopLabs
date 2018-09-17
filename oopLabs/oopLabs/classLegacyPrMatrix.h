#pragma once
#include "classMatrix.h"

class classLegacyPrMatix : public classMatrix
{
public:
	classLegacyPrMatix() : classMatrix() {};
	classLegacyPrMatix( int, int, int * );

	//~classLegacyMatix();
	void set();

};