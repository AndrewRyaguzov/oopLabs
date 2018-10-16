#include "pch.h"
#include "classMatrix.h"


std::istream & operator>>( std::istream &cl, classMatrix &obj )
{
	std::cout << "input order: ";
	cl >> obj.order;
	obj.size = obj.order * obj.order;
	std::cout << "input matrix:" << std::endl;
	obj.matrix = new int[ obj.size ];
	for ( int i = 0; i < obj.size; i++)
	{
		cl >> obj.matrix[i];
	}
	std::cout << std::endl;
	return cl;
}

std::ofstream &operator<<( std::ostream &cl, classMatrix &obj )
{
	std::cout << " << ";
	obj.showMatrix();
}

std::ifstream &operator>>( std::ifstream &readStream, classMatrix &obj )
{
	readStream.open("dataForClass.txt");
	if ( readStream.is_open() )
	{
		readStream >> obj.order;
		for (int i = 0; i < obj.order*obj.order; i++)
		{
			readStream >> obj.matrix[i];
		}
		return readStream;
	}
	readStream.close();
	return readStream;
}

std::ofstream & operator<<( std::ofstream &writeStream, classMatrix const &obj )
{
	writeStream.open("dataFromClass.txt");
	if ( writeStream.is_open() )
	{
		writeStream << obj.order << ' ';
		for (int i = 0; i < obj.order*obj.order; i++)
		{
			writeStream << obj.matrix[i] << ' ';
		}
	}
	writeStream.close();
	return writeStream;
}

std::ifstream & binRead(std::ifstream & writeBinaryStream, classMatrix &obj )
{
	writeBinaryStream.open( "binaryDataForClass.bin", std::ios::binary | std::ios::in );
	writeBinaryStream.read( reinterpret_cast< char * > ( &obj ), sizeof( classMatrix ) );
	std::cout << "read bin " << std::endl;
	writeBinaryStream.close();
	return writeBinaryStream;
}

std::ofstream & binWrite(std::ofstream &readBinaryStream, classMatrix &obj )
{
	readBinaryStream.open( "binaryDataForClass.bin", std::ios::binary | std::ios::out );
	readBinaryStream.write( reinterpret_cast< char * > ( &obj ), sizeof( classMatrix ) );
	readBinaryStream.close();
	return readBinaryStream;
}


