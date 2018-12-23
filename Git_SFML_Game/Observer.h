#pragma once
class Observer
{
public:
	Observer();
	~Observer();
	virtual void Notify() = 0;
};

