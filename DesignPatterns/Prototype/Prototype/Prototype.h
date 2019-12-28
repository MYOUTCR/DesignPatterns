#pragma once

#include <iostream>

class Prototype
{
public:
	Prototype(const std::string &id, char *s)
	{
		_id = id;

		int len = std::strlen(s);

		_chr = new char[len + 1];
		std::cout << &_chr << std::endl;//Êä³ö_chrµØÖ·;
		std::strcpy(_chr, s);
		_chr[len] = '\0';
	}
	virtual ~Prototype()
	{
		delete[]_chr;
	}

	const std::string getId() { return _id; }
	char *getChr() { return _chr; }

	virtual Prototype *clone() = 0;
protected:
	std::string _id;
	char *_chr;
};

class ConcretePrototype1 :public Prototype
{
public:
	ConcretePrototype1(const std::string &id, char *s)
		:Prototype(id, s) {}
	ConcretePrototype1(ConcretePrototype1 *concretePrototype)
		:Prototype(concretePrototype->getId(), concretePrototype->getChr())
	{}

	virtual Prototype *clone() override
	{
		return new ConcretePrototype1(this);
	}

};

class ConcretePrototype2 :public Prototype
{
public:
	ConcretePrototype2(const std::string &id, char *s)
		:Prototype(id, s) {}
	ConcretePrototype2(ConcretePrototype2 *concretePrototype)
		:Prototype(concretePrototype->getId(), concretePrototype->getChr())
	{}

	virtual Prototype *clone() override
	{
		return new ConcretePrototype2(this);
	}
};
