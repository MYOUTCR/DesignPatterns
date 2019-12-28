// Proxy.cpp : 定义控制台应用程序的入口点。
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

