#include "pch.h"
#include "classLegacyPrMatrix.h"

classLegacyPrMatix::classLegacyPrMatix(int col, int row, int * matrix)
{
	colums = col;
	rows = row;
	size = col * rows;
	inputMatrix( matrix );
	isCopy = false;
}

void classLegacyPrMatix::SetColumsRows( int col, int row )
{
	colums = col;
	rows = row;
	size = col * rows;
}
