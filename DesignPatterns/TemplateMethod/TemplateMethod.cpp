// TemplateMethod.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TemplateMethod.h"

int main()
{
	Game *cricketGame = new Cricket();
	cricketGame->play();

	cout << "\n\n"<<endl;

	Game *FootballGame = new Football();
	FootballGame->play();

	getchar();
}

