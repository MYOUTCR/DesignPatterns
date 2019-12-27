#pragma once

#include <iostream>

class Strategy
{
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd :public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override
	{
		return num1 + num2;
	}
};

class OperationSubstract :public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override
	{
		return num1 - num2;
	}
};

class OperationMultiply :public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override
	{
		return num1* num2;
	}
};

class Context
{
public:
	Context() :_strategy(NULL) {}
	void setStrategy(Strategy *strategy)
	{
		_strategy = strategy;
	}

	int executeStrategy(int num1, int num2)
	{
		if (NULL != _strategy)
		{
			return _strategy->doOperation(num1, num2);
		}

		return 0;
	}

private:
	Strategy *_strategy;
};