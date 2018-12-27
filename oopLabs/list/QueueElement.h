#pragma once
#include <iostream>

class QueueElement
{
public:
	QueueElement()
	{
		std::cout << "constr QE" << Num << std::endl;
	}
	virtual ~QueueElement()
	{
		std::cout << "destruct element - " << Num << std::endl;
	}

public:
	QueueElement *prev,
		*next;
	int index;
	int type = 0;
	virtual int getType() { return type; }
	const char *_who = "i'm parent";
	virtual void _whoAre() { std::cout << " " << _who << std::endl; }
	int Num = 0;
	bool isEmpty = false;
};


class QueueElementChild : public QueueElement
{
public:
	QueueElementChild()
	{
		std::cout << "constr QEC" << Num << std::endl;
	}
	int type = 1;
	int getType() { return type; }
	const char *_who = "i'm child";
	void _whoAre() { std::cout << " " << _who << std::endl; }
};
