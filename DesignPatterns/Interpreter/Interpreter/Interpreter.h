#pragma once
#include <iostream>

class Expression
{
public:
	virtual bool Interpreter(const std::string &context) = 0;
};

class TerminalExpression :public Expression
{
public:
	TerminalExpression(const std::string &data)
		:_data(data) {}
	virtual bool Interpreter(const std::string &context) override
	{
		if (context.find(_data) != context.npos)
		{
			return true;
		}

		return false;
	}
private:
	std::string _data;
};

class OrExpression :public Expression
{
public:
	OrExpression(Expression *exp1, Expression *exp2)
		:_exp1(exp1), _exp2(exp2) {}

	virtual bool Interpreter(const std::string &context) override
	{
		if (NULL != _exp1&&NULL != _exp2)
			return (_exp1->Interpreter(context) || _exp2->Interpreter(context));

		return false;
	}
private:
	Expression *_exp1;
	Expression *_exp2;
};

class AndExpression :public Expression
{
public:
	AndExpression(Expression *exp1, Expression *exp2)
		:_exp1(exp1), _exp2(exp2) {}

	virtual bool Interpreter(const std::string &context) override
	{
		if (NULL != _exp1&&NULL != _exp2)
			return (_exp1->Interpreter(context) && _exp2->Interpreter(context));

		return false;
	}
private:
	Expression *_exp1;
	Expression *_exp2;
};
