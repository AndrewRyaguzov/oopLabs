#pragma once
class IQueueClass
{
	int _id;

public:
	virtual void add() = 0;
	virtual void del() = 0;
	virtual void setByNumber( int ) = 0;
	virtual void delByNumber( int ) = 0;
	virtual void find() = 0;
	virtual void show() = 0;
	virtual void setId()
	{
		_id = 0;
	}
};

