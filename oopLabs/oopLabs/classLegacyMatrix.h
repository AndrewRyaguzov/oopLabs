#pragma once
#include "classMatrix.h"

class classLegacyMatix : public classMatrix
{
public:
	classLegacyMatix() : classMatrix() {};
	classLegacyMatix( int order, int *matrix ) : classMatrix( order, matrix ) {};

	//~classLegacyMatix();
	void set( );

};