// Iterator.cpp : �������̨Ӧ�ó������ڵ㡣
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

