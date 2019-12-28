// Flyweight.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Flyweight.h"

int main()
{
	int extrinsicstate = 20;

	FlyweightFactory *f = new FlyweightFactory();

	Flyweight *fx = f->getFlyweight("X");
	fx->Operation(--extrinsicstate);

	Flyweight *fy = f->getFlyweight("Y");
	fy->Operation(--extrinsicstate);

	Flyweight *fz = f->getFlyweight("Z");
	fz->Operation(--extrinsicstate);

	Flyweight *unf = new UnsharedConcreteFlyweight();
	unf->Operation(--extrinsicstate);

	delete unf;
	unf = NULL;
	delete f;
	f = NULL;

	getchar();
    return 0;
}

