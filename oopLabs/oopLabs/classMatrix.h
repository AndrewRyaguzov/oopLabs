#pragma once
#include <iostream>
#include <fstream>
#include <exception>

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
		order = 0,
		id;
	bool isCopy;

private:
	int	determinant;
	static int count;

public:
	virtual void setOrder( int );
	void inputMatrix( int * );

	virtual void inputAll();

	void TransformToDoubleMatrix( int * );

	virtual void transponMatrix();
	virtual void findDeterminant();
	virtual void showMatrix(  );
	void showMatrixInfo();
	virtual int getDet()
	{
		return determinant;
	};
	virtual int getOrder()
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

class exp_mtx : public std::exception
{
public:
	exp_mtx(const char* msg)
	{
		std::cerr << "[EXCEPTION] : [" << msg << "] CATCHED!" << std::endl;
	}
};

int fD(int, int*);