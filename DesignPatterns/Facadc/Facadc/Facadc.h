#pragma once

#include <iostream>

//外观模式提供了一个统一接口，用来访问子系统中的一群接口，外观定义了一个高层接口，让子系统更容易使用;

class SubSystemOne
{
public:
	void MethodOne()
	{
		std::cout << "call subsystem method one" << std::endl;
	}
};

class SubSystemTwo
{
public:
	void MethodTwo()
	{
		std::cout << "call subsystem method two" << std::endl;
	}
};

class SubSystemThree
{
public:
	void MethodThree()
	{
		std::cout << "call subsystem method three" << std::endl;
	}
};

class SubSystemFour
{
public:
	void MethodFour()
	{
		std::cout << "call subsystem method four" << std::endl;
	}
};

class Facadc
{
public:
	//方法组合;
	void MethodA()
	{
		std::cout << "facadc.MethodA()" << std::endl;
		subSystemOne.MethodOne();
		subSystemFour.MethodFour();
	}

	//方法组合;
	void MethodB()
	{
		std::cout << "facadc.MethodB()" << std::endl;
		subSystemOne.MethodOne();
		subSystemTwo.MethodTwo();
		subSystemThree.MethodThree();
	}

private:
	SubSystemOne subSystemOne;
	SubSystemTwo subSystemTwo;
	SubSystemThree subSystemThree;
	SubSystemFour subSystemFour;

};