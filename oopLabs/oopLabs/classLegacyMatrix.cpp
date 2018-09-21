#include "pch.h"
#include "classLegacyMatrix.h"

void classLegacyMatix::set( )
{
	if ( order < 1 && size < 1 ) return;

	matrix = new int[ size ];
	for (int i = 0, sdv = 0; i < size; i++)
	{
		matrix[i] = 0;
		if ( ( sdv == i ) || (i == 0))
		{
			sdv += order + 1;
			matrix[i] = 1;
		}
	}
}