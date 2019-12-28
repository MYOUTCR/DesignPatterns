#pragma once

#include <iostream>
#include <vector>

//迭代器抽象类;
class Iterator
{
public:
	virtual const std::string frist() = 0;
	virtual const std::string next() = 0;
	virtual const std::string currentItem() = 0;
	virtual bool isDone() = 0;
	virtual ~Iterator() {}
};

//聚集抽象类;
class Aggregate
{
public:
	virtual Iterator *createIterator() = 0;
	virtual void push(const std::string &value) = 0;
	virtual const std::string value(int nIndex) = 0;
	virtual int count() = 0;
};

//具体迭代类;
class ConcreteIterator :public Iterator
{
public:
	ConcreteIterator(Aggregate *aggregate) :_aggregate(aggregate), _nIndex(0) {}

	virtual const std::string frist() override
	{
		return _aggregate->value(0);
	}

	virtual const std::string next() override
	{
		std::string strValue = "";
		_nIndex++;

		if (_nIndex < _aggregate->count())
		{
			strValue = _aggregate->value(_nIndex);
		}

		return strValue;
	}

	virtual bool isDone()
	{
		return _nIndex < _aggregate->count();
	}

	virtual const std::string currentItem()
	{
		std::string strValue = "";

		if (_nIndex < _aggregate->count())
		{
			strValue = _aggregate->value(_nIndex);
		}

		return strValue;
	}
protected:
	Aggregate *_aggregate;
	int _nIndex;
};

class  ConcreteAggregate :public Aggregate
{
public:
	ConcreteAggregate()
	{
		_iterator = NULL;
		_items.clear();
	}

	~ConcreteAggregate()
	{
		if (NULL != _iterator)
		{
			if (NULL != _iterator)
			{
				delete _iterator;
				_iterator = NULL;
			}
		}
	}

	virtual Iterator *createIterator() override
	{
		if (NULL == _iterator)
			_iterator = new ConcreteIterator(this);

		return _iterator;
	}

	virtual void push(const std::string &value) override
	{
		_items.push_back(value);
	}
	 
	virtual const std::string value(int nIndex) override
	{
		std::string strValue = "";
		if (nIndex < _items.size())
		{
			strValue = _items[nIndex];
		}

		return strValue;
	}

	virtual int count() override
	{
		return _items.size();
	}

private:
	std::vector<std::string> _items;
	Iterator *_iterator;
};

