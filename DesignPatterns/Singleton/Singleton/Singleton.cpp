// Singleton.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Singleton.h"

int main()
{
	Singleton *singleton = Singleton::instance();
	if (NULL != singleton)
	{
		cout << singleton->getInfo().c_str() << endl;
	}

	getchar();
	return 0;
}

