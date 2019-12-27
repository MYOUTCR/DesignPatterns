// Strategy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Strategy.h"

int main()
{

	Context context;

	Strategy *addStrategy = new OperationAdd();
	Strategy *sunStrategy = new OperationSubstract();
	Strategy *multStrategy = new OperationMultiply();

	context.setStrategy(addStrategy);
	std::cout << "10+5= " << context.executeStrategy(10, 5) << std::endl;

	context.setStrategy(sunStrategy);
	std::cout << "10-5= " << context.executeStrategy(10, 5) << std::endl;

	context.setStrategy(multStrategy);
	std::cout << "10*5= " << context.executeStrategy(10, 5) << std::endl;


	getchar();
    return 0;
}

