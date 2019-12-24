#pragma once

#include <iostream>
#include <list>
#include "ObserverPattern2.h"

//观察者模式;
using namespace std;

class ObServer
{
public:
	virtual void update() = 0;

	ObServer(Subject *subject)
		:_subject(subject)
	{
		if (NULL != subject)
		{
			subject->addAttach(this);
		}
	}

protected:
	Subject *_subject;
};

//第一个观察者;
class F_ObServer :public ObServer
{
public:
	F_ObServer(Subject *subject) :ObServer(subject)
	{

	}

	virtual void update()
	{
		if (NULL != _subject)
		{
			cout << "F_ObServer " << _subject->getState().c_str() << endl;
		}
	}
};

//第二个观察者;
class S_ObServer :public ObServer
{
public:
	S_ObServer(Subject *subject) :ObServer(subject)
	{

	}

	virtual void update()
	{
		if (NULL != _subject)
		{
			cout << "S_ObServer " << _subject->getState().c_str() << endl;
		}
	}
};

//第三个观察者;
class T_ObServer :public ObServer
{
public:
	T_ObServer(Subject *subject) :ObServer(subject)
	{

	}

	virtual void update()
	{
		if (NULL != _subject)
		{
			cout << "T_ObServer " << _subject->getState().c_str() << endl;
		}
	}
};

