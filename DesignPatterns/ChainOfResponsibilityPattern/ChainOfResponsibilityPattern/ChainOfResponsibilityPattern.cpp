// ChainOfResponsibilityPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ChainOfResponsibilityPattern.h"

int main()
{
	AbstractLogger *errorLogger = new ErrorLogger(3, NULL);
	AbstractLogger *fileLogger = new FileLogger(2, errorLogger);
	AbstractLogger *consoleLogger = new ConsoleLogger(1, fileLogger);

	consoleLogger->loggerMessage(3, "������Ϣ");
	cout << "\n" << endl;
	consoleLogger->loggerMessage(2, "������Ϣ");
	cout << "\n" << endl;
	consoleLogger->loggerMessage(1, "����̨��Ϣ");

	getchar();
	return 0;
}

