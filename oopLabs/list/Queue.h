#pragma once
#include <iostream>
#include "QueueElement.h"

class Queue
{
public:
	Queue();
	~Queue();

private:
	static int countElements;
	int index;
	Queue *prev,
		  *next;
	QueueElement *_element;

public:
	void Add( QueueElement*, int );
	void Del();
	void AddByIndex( QueueElement*, int, int );
	void DelByIndex( int );
	//uint8_t *Find( int );
	Queue **Find( int num );
	void ShowElement( int );
	void ShowElement( );
	void ShowFull();
};

