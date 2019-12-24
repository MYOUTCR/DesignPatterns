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

class Color
{
public:
	virtual void fill() = 0;
};

class Red :public Color
{
public:
	virtual void fill() override
	{
		cout << "Red fill" << endl;
	}
};

class Green :public Color
{
public:
	virtual void fill() override
	{
		cout << "Green fill" << endl;
	}
};

class Blue :public Color
{
public:
	virtual void fill() override
	{
		cout << "Blue fill" << endl;
	}
};

class AbstractFactory
{
public:
	virtual Color* getColor(const std::string &ColorName) = 0;
	virtual Shape* getShape(const std::string &shapeName) = 0;
};

class ShapeFactory:public AbstractFactory
{
public:
	virtual Shape* getShape(const std::string &shapeName) override
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

	virtual Color* getColor(const std::string &ColorName) override
	{
		return NULL;
	}
};

class ColorFactory :public AbstractFactory
{
public:
	virtual Color* getColor(const std::string &ColorName) override
	{
		if ("Red" == ColorName)
		{
			return new Red();
		}
		else if ("Green" == ColorName)
		{
			return new Green();
		}
		else if ("Blue" == ColorName)
		{
			return new Blue();
		}

		return NULL;
	}

	virtual Shape* getShape(const std::string &shapeName) override
	{
		return NULL;
	}
};

class FactoryProducer
{
public: 
	static AbstractFactory* getFactory(const std::string &choice)
	{
		if ("Shape" == choice)
		{
			cout << "draw ShapeFactory" << endl;

			return new ShapeFactory();
		}
		else if ("Color" == choice)
		{
			cout << "\n" << "draw ColorFactory" << endl;

			return new ColorFactory();
		}

		return NULL;
	}
};

