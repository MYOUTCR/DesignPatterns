// Composite.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Composite.h"

int main()
{
	Component *root = new Composilt("root");

	root->add(new Leaf("Leaf A"));
	root->add(new Leaf("Leaf B"));

	Component *comp = new Composilt("Composilt X");
	comp->add(new Leaf("Leaf XA"));
	comp->add(new Leaf("Leaf XB"));
	root->add(comp);

	Component *comp2 = new Composilt("Composilt O");
	comp2->add(new Leaf("Leaf OA"));
	comp2->add(new Leaf("Leaf OB"));
	root->add(comp2);

	root->display(1);

	getchar();
    return 0;
}

