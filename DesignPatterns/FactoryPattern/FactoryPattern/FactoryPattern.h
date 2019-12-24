#pragma once

#include <iostream>

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};

class Rectangle :public Shape
{
public:
	virtual void draw() override
	{
		cout << "draw Rectangle" << endl;
	}
};

class Square :public Shape
{
public:
	virtual void draw() override
	{
		cout << "draw Square" << endl;
	}
};

class Circle :public Shape
{
public:
	virtual void draw() override
	{
		cout << "draw Circle" << endl;
	}
};

class ShapeFactory
{
public:
	static Shape* getShape(const std::string &shapeName)
	{
		if ("Rectangle" == shapeName)
		{
			return new Rectangle();
		}
		else if ("Square" == shapeName)
		{
			return new Square();
		}
		else if ("Circle" == shapeName)
		{
			return new Circle();
		}

		return NULL;
	}
};