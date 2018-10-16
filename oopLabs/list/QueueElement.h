#pragma once
#include "IQueueClass.h"

class QueueElement : public IQueueClass
{
public:
	QueueElement();
	~QueueElement();

	//static int IQueueClass::_id;
	int ownId;
private:
	/*IQueueClass IQueueClass::*last,
				IQueueClass::*next;
				*/
	IQueueClass *_last,
				*_next;
	int value;

public:
	
	void IQueueClass::add( IQueueClass *, int ) override;
	//void IQueueClass::del( ) override;
	//void IQueueClass::setByNumber( int ) override;
	//void IQueueClass::delByNumber(int) override;
	//void IQueueClass::find() override;
	//void IQueueClass::show() override;
	//void IQueueClass::setId(int) override;
};
