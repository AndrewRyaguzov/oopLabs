#include "pch.h"
#include "exceptionClassMatrix.h"


exceptionClassMatrix::exceptionClassMatrix()
{
	std::cerr << "CATCHED!" << std::endl;
}
/*
exceptionClassMatrix::exceptionClassMatrix( const char *message, int correct, int overSize )
{
	std::cout << "[EXCEPTION] : [" << message << "] puted: " << overSize << " max: " << correct << std::endl;
}

exceptionClassMatrix::exceptionClassMatrix( const char *message, int uncorrect)
{
	std::cout << "[EXCEPTION] : [" << message << "] order now: " << uncorrect << std::endl;
}

exceptionClassMatrix::exceptionClassMatrix( const char *message )
{
	std::cout << "[EXCEPTION] : [" << message << ']' << std::endl;
}
*/

exceptionClassMatrix::~exceptionClassMatrix()
{
}
