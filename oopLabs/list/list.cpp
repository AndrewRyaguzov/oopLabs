// list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "pch.h"
#include "Queue.h"
#include "QueueElement.h"
#include <iostream>

int main()
{
	Queue *list = new Queue;
	//QueueElement *elm_1 = new QueueElement;// = nullptr;
	//QueueElementChild *elm_2 = new QueueElementChild;// = nullptr;
	//QueueElement *next;
	//next = NULL;

	int choice = 1;
	
	while ( choice )
	{
		std::cout << "------------menu------------" << std::endl
			<< " 1 - add first type QE " << std::endl
			<< " 2 - add second type QE " << std::endl
			<< " 3 - del last elm " << std::endl
			<< " 4 - del by index " << std::endl
			<< " 5 - find by num " << std::endl
			<< " 6 - show elm by index " << std::endl
			<< " 7 - show full " << std::endl
			<< " 0 - exit" << std::endl 
			<< "----------------------------" << std::endl;
		std::cin >> choice;
		std::cout << "--------end of menu---------" << std::endl;

		switch ( choice )
		{
			case 1: 
			{
				QueueElement *elm_1 = new QueueElement;
				std::cout << " input num: ";
				int num;
				std::cin >> num;
				list->Add(elm_1, num);
				break;
			}
			case 2:
			{
				QueueElementChild *elm_2 = new QueueElementChild;
				std::cout << " input num: ";
				int num;
				std::cin >> num;
				list->Add(elm_2, num);
				break;
			}
			case 3:
			{
				list->Del();
				break;
			}
			case 4:
			{
				int num;
				std::cin >> num;
				list->DelByIndex( num );
				break;
			}
			case 5:
			{
				std::cout << " input num to find: ";
				int num;
				std::cin >> num;
				Queue **arr = list->Find(num);
				int count = reinterpret_cast<int> (arr[0]);
				for (int i = 1; i < count; i++)
					arr[i]->ShowElement();
				break;
			}
			case 6:
			{
				int num;
				std::cin >> num;
				list->ShowElement( num );
				break;
			}
			case 7:
			{
				list->ShowFull();
				break;
			}

			default:
				break;
		}
	}

	/*
	
	//list->ShowElement(arr[1]);
	*/
	return 0;
}

