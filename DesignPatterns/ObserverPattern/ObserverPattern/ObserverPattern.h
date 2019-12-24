#pragma once

#include <iostream>
#include <list>
#include "ObserverPattern2.h"

//�۲���ģʽ;
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

//��һ���۲���;
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

//�ڶ����۲���;
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

//�������۲���;
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

