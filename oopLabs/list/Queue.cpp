#pragma once
#include "pch.h"
#include "Queue.h"


Queue::Queue()
{
	index = countElements++;
	std::cout << "construct index - " << index << std::endl;
}

Queue::~Queue()
{
	std::cout << "destruct - " << index << std::endl;
	delete _element;
	--countElements;
}

void Queue::Add( QueueElement *obj, int num)
{
	//obj = new QueueElement;
	obj->Num = num;

	if (this->next == nullptr)
	{
		this->_element = obj;
		this->next = this;
		this->prev = this;
		return;
	}
	
	Queue *findLast = this,
		  *newObj = new Queue;

	for (; findLast->next != this; findLast = findLast->next);
	findLast->next = newObj;
	newObj->_element = obj;
	newObj->next = this;
	newObj->prev = findLast;
	this->prev = newObj;
}

void Queue::Del()
{
	Queue *findLast = this;

	if (this->index == this->next->index)
	{
		this->next = nullptr;
		this->prev = nullptr;
		//delete _element;
		return;
	}
	for (; findLast->next != this; findLast = findLast->next);
	findLast->prev->next = this;
	this->prev = findLast->prev;
	//findLast = nullptr;
	findLast->~Queue();

}

void Queue::AddByIndex( QueueElement *obj, int index, int num)
{
	Queue *tmp = this;
		  
	for (;; tmp = tmp->next)
	{
		if (tmp->index == index)
		{
			//obj = new QueueElement;
			obj->Num = num;
			obj->isEmpty = false;
			tmp->_element = obj;
			return;
		}

		if (tmp->next == this && index > tmp->index)
		{
			//obj = new QueueElement;

			Queue *newObj = new Queue;
			QueueElement *emptyObj = new QueueElement;
			emptyObj->isEmpty = true;

			tmp->next = newObj;
			newObj->_element = emptyObj;
			newObj->next = this;
			newObj->prev = tmp;
			this->prev = newObj;
		}
	}
}

void Queue::DelByIndex( int index )
{

	if (index > this->prev->index || index < 0)
	{
		std::cerr << " wrong index!" << std::endl;
		return;
	}

	if (this->index == this->prev->index)
	{
		this->next = nullptr;
		this->prev = nullptr;
		return;
	}

	Queue *tmp = this;
	int maxIndex = this->prev->index - 1;
	bool finded = false;

	for (;; tmp = tmp->next)
	{
		if (index == tmp->index || tmp->_element->isEmpty && !finded)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->~Queue();
			finded = true;
		}
		if (index < tmp->index)
		{
			tmp->index -= 1;
		}
		if (maxIndex == tmp->index) return;
	}
}

Queue **Queue::Find( int num )
{
	Queue *tmp = this;
	Queue **queueArray = new Queue*;

	int	count = 1;

	do
	{
		if (tmp->_element->Num == num) //
			queueArray[count++] = tmp;
		tmp = tmp->next;
	} while (tmp->index != 0);

	if (count == 1) std::cerr << " not found!" << std::endl;	
	if ( count ) 
	{
		void* qA = queueArray;
		int *n = reinterpret_cast<int*>(qA);
		*n = count;
		return queueArray;
	}
}

/*
uint8_t * Queue::Find(int num)
{
	Queue *tmp = this;
	Queue **queueArray = new Queue*;

	uint8_t *Array = new uint8_t;
	void *voidArray = &(Array[4]);


	int	count = 0;

	do
	{
		if (tmp->_element->Num == num)
			queueArray[count++] = tmp;
		tmp = tmp->next;
	} while (tmp->next != this);

	voidArray = queueArray;

	if (count == 0) std::cerr << " not found!" << std::endl;
	if (count)
	{
		//void* qA = queueArray;
		int *n = reinterpret_cast<int*>(Array);
		*n = count;
		return Array;
	}
}*/

void Queue::ShowElement(int index)
{
	if (index > this->prev->index || index < 0)
	{
		std::cerr << " wrong index! " << std::endl;
		return;
	}
	Queue *tmp = this;
	do
	{
		if (tmp->index == index)
		{
			std::cout << "_____________________________" << std::endl;
			std::cout << " Queue element index - " << tmp->index << std::endl
				<< " Element num = " << tmp->_element->Num << std::endl;
			tmp->_element->WhoAreYou();
			std::cout << "_____________________________" << std::endl;
		}
		tmp = tmp->next;
	} while (tmp->index != 0);
}

void Queue::ShowElement()
{
	std::cout << "_____________________________" << std::endl
		<< " Queue element index - " << this->index << std::endl
		<< " Element num = " << this->_element->Num << std::endl;
	this->_element->WhoAreYou();
	std::cout << "_____________________________" << std::endl;
}

void Queue::ShowFull()
{
	if (this->next == nullptr)
	{
		std::cout << " Queue is empty! " << std::endl;
		return;
	}
	Queue *findLast = this;
	std::cout << "_____________________________" << std::endl;
	do 
	{
		if(!findLast->_element->isEmpty)
		{
			std::cout << " Queue element index - " << findLast->index << std::endl
				<< " Element num = " << findLast->_element->Num << std::endl;
			findLast->_element->WhoAreYou();
			std::cout << "_____________________________" << std::endl;
		}
		findLast = findLast->next;
	} while (findLast->index != 0);
}

int Queue::countElements = 0;
