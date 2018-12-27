#pragma once
#include "pch.h"
#include <fstream>
#include "Queue.h"

void Queue::Add( QueueElement *obj, int num)
{
	obj->Num = num;
	obj->isEmpty = false;

	if (globIndex < totalElm)
	{		
		globIndex++;

		if (this->_list == nullptr)
		{
			_list = new QueueElement;
			obj->next = obj;
			obj->prev = obj;

			_list = obj;
			_list->index++;
			return;
		}

		QueueElement *findLast = _list;

		for (; findLast->next != this->_list; findLast = findLast->next);
		obj->next = _list;
		obj->prev = findLast;
		_list->prev = obj;
		obj->index = globIndex;
		findLast->next = obj;
	}
	else
	{
		std::cout << _list->prev << std::endl;
		_list = _list->next;
		
		QueueElement *findLast = _list;
		for (; findLast->next->next != this->_list; findLast = findLast->next)
			findLast->index--;

		findLast->index--;
		obj->next = _list;
		obj->prev = findLast;

		obj->index = totalElm;
		_list->prev = obj;
 		findLast->next = obj;
	}
}

void Queue::Del()
{
	QueueElement *findLast = _list;
	
	if (this->_list->index == this->_list->next->index)
	{
		_list = nullptr;
		globIndex--;
		return;
	}
	for (; findLast->next != this->_list; findLast = findLast->next);
	findLast->prev->next = _list;
	_list->prev = findLast->prev;

	globIndex--;
}

/*void Queue::AddByIndex( QueueElement *obj, int index, int num)
{
	QueueElement *tmp = _list;
	obj->Num = num;
	obj->isEmpty = false;
	globIndex++;
	for (;; tmp = tmp->next)
	{
		if (tmp->index == index)
		{
			tmp = obj;
			obj->next = obj;
			obj->prev = obj;
			obj->index = globIndex;
			return;
		}

		if (tmp->next == _list && index > tmp->index)
		{
			QueueElement *emptyObj = new QueueElement;
			emptyObj->isEmpty = true;

			tmp->next = obj;
			obj->next = _list;
			tmp->prev = tmp;
		}
	}
}
*/
void Queue::AddByIndex(QueueElement *obj, int index, int num)
{
	if (index - 1 > globIndex || index > totalElm)
	{
		std::cout << "wrong index" << std::endl;
		return;
	}
	
	obj->Num = num;
	obj->isEmpty = false;

	if (globIndex < totalElm)
	{
		globIndex++;
		if (this->_list == nullptr)
		{
			_list = new QueueElement;
			obj->next = obj;
			obj->prev = obj;

			_list = obj;
			_list->index++;
			return;
		}
		
		bool finded = false;
		QueueElement *findLast = _list;
		for (; findLast->next != this->_list; findLast = findLast->next)
		{
			if (findLast->index == index && !false)
			{
				obj->next = findLast->next;
				obj->prev = findLast->prev;
				obj->index = findLast->index;
				findLast = obj;
				finded = true;
			}
			if (finded)findLast->index--;
		}
		if (!finded)
		{
			obj->next = _list;
			obj->prev = findLast;
			obj->index = globIndex;
			findLast->next = obj;
		}
	}
	else
	{
		QueueElement *end = _list->prev;
		_list = _list->next;
		end->next = _list;
		_list->prev = end;
		QueueElement *findLast = _list;
		for (; findLast->next != this->_list; findLast = findLast->next)
		{
			if (findLast->index == index)
			{
				QueueElement * tmp_prev = findLast->prev;
				obj->next = findLast;
				obj->prev = findLast->prev;
				obj->index = findLast->index;
				obj->index++;
				tmp_prev->next = obj;
			}
		}
		findLast = _list;
		for (; findLast->next != this->_list; findLast = findLast->next)
			findLast->index--;
	}
}

void Queue::DelByIndex( int index )
{
	if (index > globIndex || index < 0)
	{
		std::cerr << " wrong index!" << std::endl;
		return;
	}
	if (_list->index == globIndex)
	{
		_list = nullptr;
		globIndex--;
		return;
	}
	if (_list->index == index)
	{
		QueueElement *end = _list->prev;
		_list = _list->next;
		_list->prev = end;
		end->next = _list;
		end->index--;

		QueueElement *findLast = _list;
		for (; findLast->next != this->_list; findLast = findLast->next)
			findLast->index--;
		return;
	}
	QueueElement *tmp = _list;
	bool finded = false;
	globIndex--;
	
	for (;; tmp = tmp->next)
	{
		if (index == tmp->index && !finded)		//|| tmp->isEmpty  
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;

			finded = true;
			continue;
		}
		
		if (index == 1 && !finded)
		{
			_list = _list->next;
			QueueElement *findLast = _list;
			for (; findLast->next->next != _list; findLast = findLast->next);
			findLast->next = _list;
			finded = true;
		}
		if (finded)
			tmp->index -= 1;

		if (globIndex == tmp->index) 
			return;
	}
}

int *Queue::Find( int num )
{
	QueueElement *tmp = _list;
	int *queueArray = new int [globIndex];
	queueArray[0] = 0;
	int	count = 1;

	do
	{
		if (tmp->Num == num)
		{
			queueArray[count] = tmp->index;
			count++;
		}
		tmp = tmp->next;
	} while (tmp != _list);
	if (count == 1)
		std::cerr << " not found!" << std::endl;	
	if (count)
	{
		queueArray[0] = count - 1;
		return queueArray;
	}
}

void Queue::ShowElement(int index)
{
	if (index > globIndex || index < 0)
	{
		std::cerr << " wrong index! " << std::endl;
		return;
	}
	QueueElement *tmp = _list;
	do
	{
		if (tmp->index == index)
		{
			std::cout << "_____________________________" << std::endl;
			std::cout << " Queue element index - " << tmp->index << std::endl
				<< " Element num = " << tmp->Num << std::endl;
			std::cout << "_____________________________" << std::endl;
		}
		tmp = tmp->next;
	} while (tmp != _list);
}

void Queue::ShowElement()
{
	std::cout << "_____________________________" << std::endl
		<< " Queue element index - " << _list->index << std::endl
		<< " Element num = " << _list->Num << std::endl;
	std::cout << "_____________________________" << std::endl;
}

void Queue::ShowFull()
{

	if (globIndex == 0)
	{
		std::cout << " Queue is empty! " << std::endl;
		return;
	}
	QueueElement *findLast = _list;
	std::cout << "Total elemen " << totalElm << std::endl
			  << "_____________________________" << std::endl;
	do 
	{
		if(!findLast->isEmpty)
		{
			std::cout << " Queue element index - " << findLast->index << std::endl
				<< " Element num = " << findLast->Num << std::endl
				<< " Element addr: " << findLast << std::endl;
				findLast->_whoAre();
				std::cout << " Addr	 prev: " << findLast->prev << std::endl
				<< " Addr	 next: " << findLast->next << std::endl;
			std::cout << "_____________________________" << std::endl;
		}
		findLast = findLast->next;
	} while (findLast != _list);
}


std::ofstream & binWrite(std::ofstream &writeBinaryStream, Queue *&obj)
{
	QueueElement *findLast = obj->_list;
	if (writeBinaryStream.is_open())
	{
		writeBinaryStream.write(reinterpret_cast <char *> (&obj->globIndex), sizeof(int));
		std::cout << "type " << findLast->getType() << std::endl;
		int tmp_type;
		for (; findLast->next != obj->_list; findLast = findLast->next)
		{
			tmp_type = findLast->getType();
			writeBinaryStream.write(reinterpret_cast <char *> (&tmp_type), sizeof(int));
			writeBinaryStream.write(reinterpret_cast <char *> (&findLast->index), sizeof(int));
			writeBinaryStream.write(reinterpret_cast <char *> (&findLast->isEmpty), sizeof(bool));
			writeBinaryStream.write(reinterpret_cast <char *> (&findLast->Num), sizeof(int));
		}
		tmp_type = findLast->getType();
		writeBinaryStream.write(reinterpret_cast <char *> (&tmp_type), sizeof(int));
		writeBinaryStream.write(reinterpret_cast <char *> (&findLast->index), sizeof(int));
		writeBinaryStream.write(reinterpret_cast <char *> (&findLast->isEmpty), sizeof(bool));
		writeBinaryStream.write(reinterpret_cast <char *> (&findLast->Num), sizeof(int));
	}
	return writeBinaryStream;
}

std::ifstream & binRead(std::ifstream &readBinaryStream, Queue *&obj)
{
	obj->_list = new QueueElement;
	
	QueueElement *tmp_list = new QueueElement, 
				 *first = nullptr;

	if (readBinaryStream.is_open())
	{
		readBinaryStream.read(reinterpret_cast <char *> (&obj->globIndex), sizeof(int));
		std::cout << obj->globIndex << std::endl;
		for (size_t i = 0; i < obj->globIndex; i++)
		{
			QueueElement *findLast = nullptr;
			int type;
			readBinaryStream.read(reinterpret_cast <char *> (&type), sizeof(int));
			std::cout << "type " << type << std::endl;
			if (type == 0)
				findLast = new QueueElement;
			if (type == 1)
				findLast = new QueueElementChild;
			readBinaryStream.read(reinterpret_cast <char *> (&findLast->index), sizeof(int));
			readBinaryStream.read(reinterpret_cast <char *> (&findLast->isEmpty), sizeof(bool));
			readBinaryStream.read(reinterpret_cast <char *> (&findLast->Num), sizeof(int));

			if (i == 0)
			{
				tmp_list = findLast;
				tmp_list->next = findLast;
				tmp_list->prev = findLast;
				first = tmp_list;
				std::cout << first << std::endl;
				continue;
			}			
			tmp_list->next = findLast;

			tmp_list->next->prev = tmp_list;
			tmp_list->next->next = first;
			first->prev = tmp_list->next;
			tmp_list = tmp_list->next;
		}
		obj->_list = first;
	}
	return readBinaryStream;
}

