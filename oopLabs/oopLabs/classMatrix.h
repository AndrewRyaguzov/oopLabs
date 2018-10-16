#pragma once
#include <iostream>
#include <fstream>

class classMatrix
{
public:
	classMatrix();
	classMatrix(int, int [][]);
	classMatrix( int, int * );
	classMatrix( const classMatrix & );
	~classMatrix( );

public:
	static int count;

protected:
	int order = 0,
		size = 0,
		*matrix,
		**matrixDouble,
		id;
	bool isCopy;

private:
	int determinant;

public:
	void setOrder( int );
	void inputMatrix( int * );

	void setOrder();
	void inputAll();

	void transponMatrix();
	void findDeterminant();
	void showMatrix();
	void showMatrixInfo();
	int getDet()
	{
		return determinant;
	};

	classMatrix &operator+( classMatrix & );
	classMatrix &operator=( classMatrix & );
	void operator()();
	int *operator[]( int& ) const;

	friend std::istream& operator>>( std::istream &, classMatrix & );
	friend std::ostream& operator<<( std:: ostream &, classMatrix & );
	
	friend std::ifstream& operator>>( std::ifstream &, classMatrix & );
	friend std::ofstream& operator<<( std::ofstream &, classMatrix const & );

	friend std::ifstream& binRead( std::ifstream &, classMatrix & );
	friend std::ofstream& binWrite( std::ofstream &, classMatrix & );

};

int fD(int, int*);