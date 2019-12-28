// Memento.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Memento.h"

int main()
{
	Originator *originator = new Originator();
	originator->setState("On");
	originator->show();

	Caretaker *caretaker = new Caretaker();
	//保存状态;
	caretaker->setMemento(originator->createMemento());

	originator->setState("Off");
	originator->show();

	//恢复初始状态;
	originator->setMemento(caretaker->getMemento());
	originator->show();

	delete originator;
	originator = NULL;

	delete caretaker;
	caretaker = NULL;

	getchar();
    return 0;
}

