#pragma once
class IQueueClass
{
public:
	static int id;

public:
	virtual void add( IQueueClass*, int ) = 0;
	//virtual void del() = 0;
	//virtual void setByNumber( int ) = 0;
	//virtual void delByNumber( int ) = 0;
	//virtual void find() = 0;
	//virtual void show() = 0;
	//virtual void setId( int ) = 0;
	virtual IQueueClass getNext() = 0;
};

//int IQueueClass::_id = 0;
//int IQueueClass::_id = 0;
