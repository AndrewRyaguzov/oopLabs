#pragma once
#include <iostream>
#include <fstream>

class classMatrix
{
public:
	classMatrix();
	classMatrix( int, int * );
	classMatrix( const classMatrix & );
	~classMatrix( );

protected:
	int order = 0,
		size = 0,
		*matrix,
		id,
		determinant;

	bool isCopy;
	//static int count;

public:
	void setOrder( int );
	void input( int * );

	void transponMatrix();
	void findDeterminant();
	void showMatrix();

	classMatrix &operator+( classMatrix & );
	classMatrix &operator=( classMatrix & );
	void operator()();
	int operator[]( const int& ) const;

	friend std::istream& operator>>( std::istream &, classMatrix & );
	friend std::ifstream& operator>>( std::ifstream &, classMatrix & );
	friend std::ofstream& operator<<( std::ofstream &, classMatrix const & );

	friend std::ifstream& binRead( std::ifstream &, classMatrix & );
	friend std::ofstream& binWrite( std::ofstream &, classMatrix & );
};

int fD(int, int*);