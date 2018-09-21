#include "pch.h"
#include "classMatrix.h"
#include "exceptionClassMatrix.h"
#include <cctype> //только ради isdigit

classMatrix::classMatrix()
{
	isCopy = false;
}

classMatrix::classMatrix( int inputOrder, int *inputNums )
{	
	setOrder( inputOrder );
	inputMatrix( inputNums );
	isCopy = false;
}

classMatrix::classMatrix( const classMatrix & inp )
{
	std::cout << " copy construct " << std::endl;

	this->setOrder( inp.order );
	this->inputMatrix( inp.matrix );
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
	try
	{
		//if (index > size) throw exceptionClassMatrix("out of range", size, index);
		if (index > size) throw exceptionClassMatrix();
	}
	catch ( exceptionClassMatrix &ex )
	{
		std::cout << "[EXCEPTION] : [out of range]" << "puted: " << index << " max: " << size << std::endl;
		return 1;
	}
	return this->matrix[ index - 1 ];
}


classMatrix &classMatrix::operator=( classMatrix & inp )
{
	order = inp.order;
	size = order * order;
	this->inputMatrix( inp.matrix );
	return *this;
}

void classMatrix::operator()()
{
	determinant = fD(order, matrix);
}

inline void classMatrix::setOrder( int inputOrder )
{
	order = inputOrder;
	size = order * order;
}

void classMatrix::setOrder()
{
	std::cin >> order;
	size = order * order;
}

void classMatrix::inputMatrix( int * inputNums )
{
	try
	{
		if (order < 1 && size < 1) throw exceptionClassMatrix( );
		matrix = new int[size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = inputNums[i];
		}
	}
	catch ( exceptionClassMatrix &ex )
	{
		std::cerr << "[EXCEPTION] : [empty order]" << std::endl;
	}
}

void classMatrix::inputAll()
{
	std::cout << "input order: ";
	std::cin >> order;
	size = order * order;
	std::cout << "input matrix:" << std::endl;
	matrix = new int[order];

	std::cin.exceptions(std::istream::failbit | std::istream::badbit);
	try 
	{
		for ( int i = 0; i < size; i++)
			std::cin >> matrix[ i ];
	}
	catch (...)
	{
		std::cerr << "NaN" << std::endl;
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
