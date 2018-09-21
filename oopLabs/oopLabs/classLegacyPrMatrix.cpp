#include "pch.h"
#include "classLegacyPrMatrix.h"

classLegacyPrMatix::classLegacyPrMatix(int col, int row, int * matrix)
{
	colums = col;
	rows = row;
	inputMatrix( matrix );
	isCopy = false;
}
