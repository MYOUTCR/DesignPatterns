// Interpreter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Interpreter.h"

int main()
{
	//����:Robert��John������;
	Expression *robert = new TerminalExpression("Robert");
	Expression *john = new TerminalExpression("John");
	Expression *isMale = new OrExpression(robert, john);

	//����:Julie��һ���ѻ��Ůʿ;
	Expression *julie = new TerminalExpression("Julie");
	Expression *married = new TerminalExpression("Married");
	Expression *isMarriedWoman = new AndExpression(julie, married);

	std::cout << "John is male? " << isMale->Interpreter("John") << std::endl;
	std::cout << "JJulie is a married women? " << isMarriedWoman->Interpreter("Married Julie")<< std::endl;


	delete robert;
	robert = NULL;
	delete john;
	john = NULL;
	delete isMale;
	isMale = NULL;

	delete julie;
	julie = NULL;
	delete married;
	married = NULL;
	delete isMarriedWoman;
	isMarriedWoman = NULL;

	getchar();
    return 0;
}

