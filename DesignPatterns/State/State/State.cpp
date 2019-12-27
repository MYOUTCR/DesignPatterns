// State.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "State.h"

int main()
{
	Context *context = new Context;


	State *startState = new StartState();
	startState->doAction(context);

	std::cout << context->getState()->to_String().c_str() << std::endl;

	State *stopState = new StopState();
	stopState->doAction(context);

	std::cout << context->getState()->to_String().c_str() << std::endl;

	getchar();
    return 0;
}

