#pragma once
#include "classMatrix.h"

class classLegacyMatix : public classMatrix
{
public:
	classLegacyMatix() : classMatrix() 
	{
		std::cout << "legacy_1 contstructed, id - " << id << std::endl << std::endl;
	}
	classLegacyMatix( int order, int *matrix ) : classMatrix( order, matrix ) {};

private:
	int order = 0;

public:
	void set( );
	void setOrder( int ord )
	{
		order = ord ;
		size = order * order;
	}
	int getOrder()
	{
		return order;
	}

};