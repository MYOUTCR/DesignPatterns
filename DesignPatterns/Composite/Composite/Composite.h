#pragma once
#include <iostream>
#include <list>

class Component
{
public:
	Component(const std::string &name)
		:_name(name)
	{
	}

	virtual ~Component() {}
	virtual void add(Component * component) = 0;
	virtual void remove(Component * component) = 0;
	virtual void display(int depth) = 0;

protected:
	std::string _name;
};

class Leaf :public Component
{
public:
	Leaf(const std::string &name) :Component(name) {}

	virtual void add(Component * component) override {}
	virtual void remove(Component * component) override {}
	virtual void display(int depth)override
	{
		std::cout << _name.c_str() << std::endl;
	}
};

class Composilt :public Component
{
public:
	Composilt(const std::string &name) :Component(name) {}

	virtual void add(Component * component) override
	{
		_children.push_back(component);
	}
	virtual void remove(Component * component) override
	{
		_children.remove(component);
	}
	virtual void display(int depth) override
	{
		std::cout << _name.c_str() << "   " << depth << std::endl;

		if (!_children.empty())
		{
			for (auto itr = _children.begin(); itr != _children.end(); itr++)
			{
				(*itr)->display(depth + 1);
			}
		}
	}

private:
	std::list<Component *> _children;
};