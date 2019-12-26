// AdapterPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "AdapterPattern.h"

int main()
{
	Computer *computer = new thinkPadComputer();
	std::string readCardMsg = computer->readSD(new SDCardImpl());
	cout << readCardMsg.c_str() << endl;
	cout << "=============================" << endl;

	TFCard *tfCard = new TFCardImpl();
	SDCard *sDAdapterTF = new SDAdapterTF(tfCard);
	cout << computer->readSD(sDAdapterTF).c_str() << endl;
	
	getchar();
    return 0;
}

