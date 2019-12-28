// Interpreter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Interpreter.h"

int main()
{
	//规则:Robert和John是男性;
	Expression *robert = new TerminalExpression("Robert");
	Expression *john = new TerminalExpression("John");
	Expression *isMale = new OrExpression(robert, john);

	//规则:Julie是一个已婚的女士;
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

