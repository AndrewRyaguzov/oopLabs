#pragma once
#include <exception>
#include <iostream>
class exceptionClassMatrix :
	public std::exception
	
{
public:
	exceptionClassMatrix();
	/*
	exceptionClassMatrix( const char *message, int correct, int overSize);
	exceptionClassMatrix( const char *message, int );
	exceptionClassMatrix( const char * );
	*/
	~exceptionClassMatrix();
};

