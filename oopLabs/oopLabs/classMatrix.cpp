#include "pch.h"
#include "classMatrix.h"

int &classMatrix::mtx::operator[](int j) const
{
	if (j < 1) throw exp_mtx(" wrong index! ");
	return tmp.matrixDouble[i - 1][j - 1];
}

classMatrix::classMatrix()
{
	isCopy = false;
	id = ++count;
}

classMatrix::classMatrix( int inputOrder, int *inputNums )
{	
	setOrder( inputOrder );
	inputMatrix( inputNums );
	isCopy = false;
	id = ++count;
}

classMatrix::classMatrix( const classMatrix &inp )
{
	this->id = ++count;
	this->setOrder( inp.order );
	this->inputMatrix( inp.matrix );
	this->isCopy = true;
}

classMatrix::~classMatrix()
{
	std::cout << "destructor - " << id << std::endl;
	delete[] matrix;
}

classMatrix classMatrix::operator+( classMatrix &rght )
{
	if (size != rght.size) throw exp_mtx("different order of matrix");
		
	classMatrix temp;
	temp.setOrder( order );
	temp.matrix = new int[ size ];
	for (int i = 0; i < size; i++)
		temp.matrix[i] = matrix[i] + rght.matrix[i];
	return temp;
}

classMatrix &classMatrix::operator=( classMatrix &inp )
{
	this->order = inp.order;
	this->size = order * order;
	this->inputMatrix( inp.matrix );
	return *this;
}

void classMatrix::operator()()
{
	determinant = fD(order, matrix);
}

classMatrix::mtx classMatrix::operator[](int & index)
{
	if (index < 1) throw exp_mtx(" wrong index! ");
	TransformToDoubleMatrix(matrix);
	return mtx(*this, index);
}


inline void classMatrix::setOrder( int inputOrder )
{
	if (inputOrder < 0) order = -1 * inputOrder; 
	else order = inputOrder;	
	size = order * order;
}

void classMatrix::inputMatrix( int *inputNums )
{
	if (order < 1 && size < 1) throw exp_mtx( "empty order" );
	matrix = new int[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = inputNums[i];
	}
}

void classMatrix::inputAll()
{
	std::cout << "input order: ";
	std::cin >> order;
	size = order * order;
	std::cout << "input matrix:" << std::endl;
	matrix = new int[size];

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

void classMatrix::TransformToDoubleMatrix(int *mtx)
{
	matrixDouble = new int *[order];
	int k = 0;
	for (int i = 0; i < order; i++)
	{
		matrixDouble[i] = new int[order];
		for (int j = 0; j < order; j++, k++)
			matrixDouble[i][j] = matrix[k];
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

	delete[] matrix;
	matrix = newMtr;
}

void classMatrix::findDeterminant()
{
	determinant = fD(order, matrix);
	std::cout << "Determinant: " << determinant << std::endl;
}

int fD(int order, int * smMtx)
{
	int detCounter = 0,
		size = order*order,
		smSize = ( order - 1 ) * ( order - 1 );

	if (size > 4)
	{
		for (int i = 0; i < order; i++)
		{
			int *smallMtx = new int[ smSize ];
			for (int j = 0, cs = 0; j < size; j++)
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
				//std::cout << smMtx[i] << " * detCounter: " << detCounter << '+' << std::endl << std::endl;
			}
			if (i % 2 != 0)
			{
				detCounter -= smMtx[i] * fD(order - 1, smallMtx);
				//std::cout << smMtx[i] << " detCounter: " << detCounter << '-' << std::endl << std::endl;
			}
		}
		
	}
	else
	{
		int res = (smMtx[0] * smMtx[3]) - (smMtx[1] * smMtx[2]);
		//std::cout << "local det" << res << std::endl << std::endl;
		return res;

	}
	return detCounter;
}

void classMatrix::showMatrix(  )
{
	std::cout << " |";
	
	for (int i = 0; i < size; i++)
	{
		std::cout << matrix[i];

		if (i + 1 != size)
		{
			if ((i + 1) % order == 0)
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

void classMatrix::showMatrixInfo()
{
	std::cout << " isCopy: " << isCopy << std::endl
		<< " ID: " << id << std::endl
		<< " determ: " << determinant << std::endl << std::endl;

}

int classMatrix::count = 0;