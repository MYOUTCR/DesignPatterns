// ChainOfResponsibilityPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ChainOfResponsibilityPattern.h"

int main()
{
	AbstractLogger *errorLogger = new ErrorLogger(3, NULL);
	AbstractLogger *fileLogger = new FileLogger(2, errorLogger);
	AbstractLogger *consoleLogger = new ConsoleLogger(1, fileLogger);

	consoleLogger->loggerMessage(3, "错误信息");
	cout << "\n" << endl;
	consoleLogger->loggerMessage(2, "测试信息");
	cout << "\n" << endl;
	consoleLogger->loggerMessage(1, "控制台信息");

	getchar();
	return 0;
}

