#include "pch.h"
#include "classMatrix.h"
#include "classLegacyPrMatrix.h"


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
	return readStream;
}

std::ofstream & operator<<( std::ofstream &writeStream, classMatrix &obj )
{
	if ( writeStream.is_open() )
	{
		writeStream << obj.order << ' ';
		for (int i = 0; i < obj.order*obj.order; i++)
		{
			writeStream << obj.matrix[i] << ' ';
		}
	}
	return writeStream;
}

std::ifstream & binRead(std::ifstream & writeBinaryStream, classMatrix &obj )
{
	if (writeBinaryStream.is_open())
	{
		writeBinaryStream.read(reinterpret_cast<char *> (&obj.order), sizeof(int));
		writeBinaryStream.read( reinterpret_cast< char * > ( &obj.size ), sizeof( int ) );
		
		obj.matrix = new int[obj.size];
	
		writeBinaryStream.read( reinterpret_cast< char * > ( obj.matrix ), (obj.size * sizeof( int )));
	}
	return writeBinaryStream;
}

std::ofstream & binWrite(std::ofstream &readBinaryStream, classMatrix &obj )
{
	if (readBinaryStream.is_open())
	{
		readBinaryStream.write(reinterpret_cast <char *> ( &obj.order ), sizeof(int));
		readBinaryStream.write(reinterpret_cast <char *> ( &obj.size), sizeof(int));
		for (int i = 0; i < obj.size; i++)
		{
			//std::cout << &obj.matrix[i] << ' ';
			readBinaryStream.write(reinterpret_cast<char *> ( &obj.matrix[i] ), sizeof(int));
		}
	}
	return readBinaryStream;
}



std::ofstream & binWrite(std::ofstream &readBinaryStream, classLegacyPrMatix &obj)
{
	if (readBinaryStream.is_open())
	{
		readBinaryStream.write(reinterpret_cast <char *> (&obj.colums), sizeof(int));
		readBinaryStream.write(reinterpret_cast <char *> (&obj.rows), sizeof(int));

		readBinaryStream.write(reinterpret_cast <char *> (&obj.size), sizeof(int));
		for (int i = 0; i < obj.size; i++)
		{
			//std::cout << &obj.matrix[i] << ' ';
			readBinaryStream.write(reinterpret_cast<char *> (&obj.matrix[i]), sizeof(int));
		}
	}
	return readBinaryStream;
}

std::ifstream & binRead(std::ifstream & writeBinaryStream, classLegacyPrMatix &obj)
{
	if (writeBinaryStream.is_open())
	{
		writeBinaryStream.read(reinterpret_cast<char *> (&obj.colums), sizeof(int));
		writeBinaryStream.read(reinterpret_cast<char *> (&obj.rows), sizeof(int));

		writeBinaryStream.read(reinterpret_cast<char *> (&obj.size), sizeof(int));

		obj.matrix = new int[obj.size];

		writeBinaryStream.read(reinterpret_cast<char *> (obj.matrix), (obj.size * sizeof(int)));
	}
	return writeBinaryStream;
}