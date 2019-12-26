// Bridge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Bridge.h"

int main()
{
	Shape *redCircle = new Circle(100, 100, 10, new RedCircle());
	Shape *greenCircle = new Circle(100, 100, 10, new GreenCircle());

	redCircle->draw();
	greenCircle->draw();

	getchar();
    return 0;
}

