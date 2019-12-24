// TemplateMethod.cpp : 定义控制台应用程序的入口点。
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

