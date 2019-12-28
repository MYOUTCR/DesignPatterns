#pragma once
#include <iostream>
#include <map>


class Flyweight
{
public:
	virtual void Operation(int extrinsicstate) = 0;
	virtual ~Flyweight(){}
};

class ConcreteFlyweight :public Flyweight
{
public:
	virtual void Operation(int extrinsicstate)
	{
		std::cout << "ConcreteFlyweight" << extrinsicstate << std::endl;
	}
};

class UnsharedConcreteFlyweight :public Flyweight
{
public:
	virtual void Operation(int extrinsicstate)
	{
		std::cout << "UnsharedConcreteFlyweight" << extrinsicstate << std::endl;
	}
};


class FlyweightFactory
{
public:
	Flyweight *getFlyweight(const std::string &key)
	{
		if (NULL == _flyweight[key])
			_flyweight[key] = new ConcreteFlyweight();

		return _flyweight[key];
	}

	~FlyweightFactory()
	{
		if (!_flyweight.empty())
		{
			for (auto itr = _flyweight.begin(); itr != _flyweight.end(); itr++)
			{
				if (NULL != itr->second)
				{
					delete itr->second;
					itr->second = NULL;
				}
			}
			_flyweight.clear();
		}
	}
private:
	std::map<std::string, Flyweight*>  _flyweight;
};