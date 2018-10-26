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

std::ostream &operator<<( std::ostream &cl, classMatrix &obj )
{
	std::cout << " |";

	for (int i = 0; i < obj.size; i++)
	{
		std::cout << obj.matrix[i];

		if (i + 1 != obj.size)
		{
			if ((i + 1) % obj.order == 0)
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
	return cl;
}

std::ifstream &operator>>( std::ifstream &readStream, classMatrix &obj )
{
	readStream.open("text files/dataForClass.txt");
	if ( readStream.is_open() )
	{
		int order_;
		readStream >> order_;
		obj.setOrder(order_);
		obj.matrix = new int[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			readStream >> obj.matrix[i];
		}
		return readStream;
	}
	readStream.close();
	return readStream;
}

std::ofstream & operator<<( std::ofstream &writeStream, classMatrix &obj )
{
	writeStream.open("text files/dataForClass.txt");
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
	//writeBinaryStream.open( "text files/binaryDataForClass.bin", std::ios::binary | std::ios::in | std::ios::app );
	if (writeBinaryStream.is_open())
	{
		writeBinaryStream.read(reinterpret_cast<char *> (&obj.order), sizeof(int));
		writeBinaryStream.read( reinterpret_cast< char * > ( &obj.size ), sizeof( int ) );
		writeBinaryStream.read( reinterpret_cast< char * > ( &obj.matrix ), obj.size * sizeof( int ));
	}
	//writeBinaryStream.close();
	return writeBinaryStream;
}

std::ofstream & binWrite(std::ofstream &readBinaryStream, classMatrix &obj )
{
	//readBinaryStream.open( "text files/binaryDataForClass.bin", std::ios::binary | std::ios::out );
	//int matrixSize = obj.size;

	if (readBinaryStream.is_open())
	{
		readBinaryStream.write(reinterpret_cast <char *> ( &obj.order ), sizeof(int));
		readBinaryStream.write(reinterpret_cast <char *> (&obj.size), sizeof(int));
		readBinaryStream.write(reinterpret_cast<char *> ( &obj.matrix), obj.size * sizeof(int));
	}
	//readBinaryStream.close();
	return readBinaryStream;
}


