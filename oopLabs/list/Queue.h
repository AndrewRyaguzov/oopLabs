#pragma once
#include <iostream>
#include "QueueElement.h"


class Queue
{
public:
	Queue(int size) { totalElm = size; }

private:
	int globIndex = 0,
		totalElm;

	QueueElement *_list = nullptr;

public:
	void Add( QueueElement*, int );
	void Del();
	void AddByIndex( QueueElement*, int, int );
	void DelByIndex( int );

	int *Find( int num );
	void ShowElement( int );
	void ShowElement( );
	void ShowFull();

	friend std::ifstream& binRead(std::ifstream &, Queue *&);
	friend std::ofstream& binWrite(std::ofstream &, Queue *&);
};

