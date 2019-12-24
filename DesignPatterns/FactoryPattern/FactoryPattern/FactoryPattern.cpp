// FactoryPattern.cpp : 定义控制台应用程序的入口点。
//
//工厂方法;

#include "stdafx.h"
#include "FactoryPattern.h"

int main()
{
	Shape *rectangle = ShapeFactory::getShape("Rectangle");
	if (NULL != rectangle)
	{
		rectangle->draw();
	}

	Shape *square = ShapeFactory::getShape("Square");
	if (NULL != square)
	{
		square->draw();
	}

	Shape *circle = ShapeFactory::getShape("Circle");
	if (NULL != circle)
	{
		circle->draw();
	}

	getchar();
    return 0;
}

