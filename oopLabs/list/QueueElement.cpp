#include "pch.h"
#include "QueueElement.h"


QueueElement::QueueElement()
{
}


QueueElement::~QueueElement()
{
}

void QueueElement::add( IQueueClass *Elm, int val )
{
	//QueueElement *newElement = new QueueElement;

	IQueueClass *baseElm = new QueueElement;
	IQueueClass *testElm = this;

	//baseElm::QueueElement ;
	//list *tt = new list;
	//newElement->value = val;
	//sp->next = NULL;

	if ( this->last == nullptr && this->next == nullptr )
	{
		this->value = val;
		this->last = this;
		return;
	}
	for (testElm; testElm->next != this; testElm = testElm->next);
	testElm = Elm;
	testElm->next = this;
	testElm->last = this;
}
