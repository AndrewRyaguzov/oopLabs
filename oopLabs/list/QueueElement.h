#pragma once
#include <iostream>

class QueueElement
{
public:
	QueueElement();
	virtual ~QueueElement();

private:
	const char* _who = " i'm parent ";

public:
	int Num = 0;
	bool isEmpty = false;

public:
	virtual void WhoAreYou()
	{
		std::cout << _who << std::endl;
	}
};


class QueueElementChild : public QueueElement
{
public:
	//QueueElementChild() : QueueElement() {};

private:
	const char* _who = " i'm child 1 (one) ";

public:
	virtual void WhoAreYou(void)
	{
		std::cout << _who << std::endl;
		std::cout << " and i can more, then my parent in same named function! " << std::endl;
	}

};
