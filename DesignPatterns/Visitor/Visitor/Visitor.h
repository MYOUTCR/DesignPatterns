#pragma once

#include <iostream>
#include <list>


class ComputerVisitor;

class ComputerPart
{
public:
	virtual void accept(ComputerVisitor &computerVisitor) {};
};

class KeyBoard :public ComputerPart
{
public:
	virtual void accept(ComputerVisitor &computerVisitor);
};

class Monitor :public ComputerPart
{
public:
	virtual void accept(ComputerVisitor &computerVisitor);
};

class Mouse :public ComputerPart
{
public:
	virtual void accept(ComputerVisitor &computerVisitor);
};

class Computer :public ComputerPart
{
public:
	Computer()
	{
		_listChPart.push_back(new KeyBoard());
		_listChPart.push_back(new Monitor());
		_listChPart.push_back(new Mouse());
	}
	virtual void accept(ComputerVisitor &computerVisitor);

private:
	std::list<ComputerPart *> _listChPart;
};


