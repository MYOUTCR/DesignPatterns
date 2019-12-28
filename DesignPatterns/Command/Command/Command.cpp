// Command.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Command.h"

int main()
{
	Received *received = new Received();
	ConcreteCommand *concreteCommand = new ConcreteCommand(received);
	Invoker *invoker = new Invoker(concreteCommand);

	invoker->call();

	//delete received;
	///received = NULL;

	delete concreteCommand;
	concreteCommand = NULL;

	delete invoker;
	invoker = NULL;

	getchar();
    return 0;
}

