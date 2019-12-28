#pragma once

#include <iostream>


//Subject 定义了RealSubject和Proxy;
class Subject
{
public:
	virtual void Request() = 0;
	virtual ~Subject() {}
};

class RealSubject :public Subject
{
public:
	virtual void Request() override
	{
		std::cout << "RealSubject" << std::endl;
	}
};

class Proxy :public Subject
{
public:
	Proxy() { _realSubject = NULL; }
	virtual ~Proxy()
	{
		if (NULL != _realSubject)
		{
			delete _realSubject;
			_realSubject = NULL;
		}
	}
	virtual void Request() override
	{
		if (NULL == _realSubject)
			_realSubject = new RealSubject();

		_realSubject->Request();
	}

private:
	RealSubject *_realSubject;
};