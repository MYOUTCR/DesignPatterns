// Proxy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Proxy.h"

int main()
{
	Proxy *proxy = new Proxy();
	proxy->Request();

	delete proxy;
	proxy = NULL;
	getchar();
    return 0;
}

