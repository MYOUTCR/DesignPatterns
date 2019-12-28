// Iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Iterator.h"

int main()
{
	Aggregate *aggregate = new ConcreteAggregate();

	aggregate->push("hello");
	aggregate->push("C++");

	Iterator *itr = new ConcreteIterator(aggregate);

	while (itr->isDone())
	{
		std::cout << itr->currentItem().c_str() << std::endl;
		itr->next();
	}

	delete aggregate;
	aggregate = NULL;
	delete itr;
	itr = NULL;

	getchar();
    return 0;
}

