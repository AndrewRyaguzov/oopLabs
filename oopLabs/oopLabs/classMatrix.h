#pragma once
#include <iostream>
#include <fstream>

class classMatrix
{
	friend class mtx;
	class mtx
	{
		classMatrix &tmp;
		int i;
		mtx(classMatrix &tempObj, int i_) : tmp(tempObj), i(i_) {}
		mtx(const mtx &);
		friend class classMatrix;
	public:
		int &operator[](int j) const;
	};

public:
	classMatrix();
	classMatrix( int, int * );
	classMatrix( const classMatrix & );
	~classMatrix( ); 

public:

protected:
	int  size = 0,
		*matrix,
		**matrixDouble,
		id;
	bool isCopy;

private:
	int order = 0,
		determinant;
	static int count;

public:
	void setOrder( int );
	void inputMatrix( int * );

	void inputAll();

	void TransformToDoubleMatrix( int * );

	void transponMatrix();
	void findDeterminant();
	void showMatrix( int );
	void showMatrixInfo();
	int getDet()
	{
		return determinant;
	};
	int getOrder()
	{
		return order;
	}

	classMatrix operator+( classMatrix & );
	classMatrix &operator=( classMatrix &);
	void operator()();
	mtx operator[](int& index);

	friend std::istream& operator>>( std::istream &, classMatrix & );
	friend std::ostream& operator<<( std:: ostream &, classMatrix & );
	
	friend std::ifstream& operator>>( std::ifstream &, classMatrix & );
	friend std::ofstream& operator<<( std::ofstream &, classMatrix & );

	friend std::ifstream& binRead( std::ifstream &, classMatrix & );
	friend std::ofstream& binWrite( std::ofstream &, classMatrix & );

};

int fD(int, int*);