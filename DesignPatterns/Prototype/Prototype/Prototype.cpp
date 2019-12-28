// Prototype.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Prototype.h"

int main()
{
	char *s = "hello c++";

	Prototype *prototype = new ConcretePrototype1("1", s);
	Prototype *copy = prototype->clone();

	std::cout << "prototype: " <<"id: "<< prototype->getId().c_str() << " chr: " << prototype->getChr() << std::endl;
	std::cout << "copy:      " << "id: " << copy->getId().c_str() << " chr: " << copy->getChr() << std::endl;

	delete prototype;
	delete copy;

	getchar();
    return 0;
}

