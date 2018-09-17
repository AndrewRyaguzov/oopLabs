#include "pch.h"
#include "classMatrix.h"

classMatrix::classMatrix()
{
	isCopy = false;
}

classMatrix::classMatrix( int inputOrder, int *inputNums )
{	
	setOrder( inputOrder );
	input( inputNums );
	isCopy = false;
}

classMatrix::classMatrix( const classMatrix & inp )
{
	std::cout << " copy construct " << std::endl;

	this->setOrder( inp.order );
	this->input( inp.matrix );
	isCopy = true;

}

classMatrix::~classMatrix()
{
	std::cout << "destruct" << std::endl;
}

classMatrix &classMatrix::operator+( classMatrix &rght )
{
	if ( size != rght.size )
		for ( int i = 0; i < size; i++ )
			matrix[ i ] += rght.matrix[ i ];
	return *this;
}

int classMatrix::operator[]( const int &index ) const
{
	if (index > size) return 1;
	return this->matrix[ index - 1 ];
}

classMatrix &classMatrix::operator=( classMatrix & inp )
{
	order = inp.order;
	size = order * order;
	this->input( inp.matrix );
	return *this;
}

void classMatrix::operator()()
{
	determinant = fD(order, matrix);
}

void classMatrix::setOrder( int inputOrder )
{
	order = inputOrder;
	size = order * order;
}

void classMatrix::input( int * inputNums )
{
	if (order < 1 && size < 1) return;

	matrix = new int[ size ];
	for (int i = 0; i < size; i++)
	{
		matrix[ i ] = inputNums[ i ];
	}
}

void classMatrix::transponMatrix()
{
	int *newMtr = new int [ size ];
	for (int i = 0, num = 0, row = 0; i < size; num++, i++)
	{  
		if (i % order == 0 && i != 0)
		{
			num = 0;
			row++;
		}
		newMtr[ i ] = matrix[ row + num * order];
	}
	for (int i = 0; i < size; i++) matrix[i] = newMtr[ i ];
	delete[]newMtr;
}

void classMatrix::findDeterminant()
{
	determinant = fD(order, matrix);
}

int fD(int order, int * smMtx)
{
	int detCounter = 0;
	if (order*order > 4)
	{
		for (int i = 0; i < order; i++)
		{
			int *smallMtx = new int[order - 1];
			for (int j = 0, cs = 0; j < order*order; j++)
			{
				if ( j >= order && (j - i) % order != 0 )
				{
					smallMtx[cs] = smMtx[j];
					cs++;
				}
			}
			if (i % 2 == 0)
			{
				detCounter += smMtx[i] * fD(order - 1, smallMtx);
				std::cout << detCounter << std::endl;
			}
			if (i % 2 != 0)
			{
				detCounter -= smMtx[i] * fD(order - 1, smallMtx);
				std::cout << detCounter << std::endl;
			}
		}
		
	}
	else
	{
		int res = (smMtx[0] * smMtx[3]) - (smMtx[1] * smMtx[2]);
		return res;

	}
	return detCounter;
}

void classMatrix::showMatrix()
{
	std::cout << "isCopy: " << isCopy << std::endl
		<< "ID: " << id << std::endl
		<< "determ: " << determinant << std::endl << std::endl;
	std::cout << '|';
	for (int i = 0; i < size; i++)
	{
		std::cout << matrix[i];

		if (i + 1 != size)
		{
			if ((i + 1) % order == 0)
			{
				std::cout << '|' << std::endl << '|';
			}
			else
			{
				std::cout << ' ';
			}
		}
	}
	std::cout << '|' << std::endl
		<< std::endl;
}
