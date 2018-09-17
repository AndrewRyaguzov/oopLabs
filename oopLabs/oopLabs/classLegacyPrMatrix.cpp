#include "pch.h"
#include "classLegacyPrMatrix.h"

classLegacyPrMatix::classLegacyPrMatix(int col, int row, int * matrix)
{
	colums = col;
	rows = row;
	input( matrix );
	isCopy = false;
}
