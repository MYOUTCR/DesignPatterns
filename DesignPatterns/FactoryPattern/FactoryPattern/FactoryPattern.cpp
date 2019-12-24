// FactoryPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//
//��������;

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

