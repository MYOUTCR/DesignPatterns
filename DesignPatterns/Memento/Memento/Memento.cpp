// Memento.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Memento.h"

int main()
{
	Originator *originator = new Originator();
	originator->setState("On");
	originator->show();

	Caretaker *caretaker = new Caretaker();
	//����״̬;
	caretaker->setMemento(originator->createMemento());

	originator->setState("Off");
	originator->show();

	//�ָ���ʼ״̬;
	originator->setMemento(caretaker->getMemento());
	originator->show();

	delete originator;
	originator = NULL;

	delete caretaker;
	caretaker = NULL;

	getchar();
    return 0;
}

