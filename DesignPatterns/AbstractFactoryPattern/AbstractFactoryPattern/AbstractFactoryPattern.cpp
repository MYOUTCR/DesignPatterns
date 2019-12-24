// AbstractFactoryPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"AbstractFactoryPattern.h"


int main()
{
	//获取形状工厂;
	AbstractFactory *shapeFactory = FactoryProducer::getFactory("Shape");
	if (NULL != shapeFactory)
	{
		Shape *rectangle = shapeFactory->getShape("Rectangle");
		if (NULL != rectangle)
		{
			rectangle->draw();
		}

		Shape *square = shapeFactory->getShape("Square");
		if (NULL != square)
		{
			square->draw();
		}

		Shape *circle = shapeFactory->getShape("Circle");
		if (NULL != circle)
		{
			circle->draw();
		}
	}

	//获取颜色工厂;
	AbstractFactory *colorFactory = FactoryProducer::getFactory("Color");
	if (NULL != colorFactory)
	{
		Color *red = colorFactory->getColor("Red");
		if (NULL != red)
		{
			red->fill();
		}

		Color *green = colorFactory->getColor("Green");
		if (NULL != green)
		{
			green->fill();
		}

		Color *blue = colorFactory->getColor("Blue");
		if (NULL != blue)
		{
			blue->fill();
		}
	}

	getchar();
    return 0;
}

