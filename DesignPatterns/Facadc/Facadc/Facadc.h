#pragma once

#include <iostream>

//���ģʽ�ṩ��һ��ͳһ�ӿڣ�����������ϵͳ�е�һȺ�ӿڣ���۶�����һ���߲�ӿڣ�����ϵͳ������ʹ��;

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
	//�������;
	void MethodA()
	{
		std::cout << "facadc.MethodA()" << std::endl;
		subSystemOne.MethodOne();
		subSystemFour.MethodFour();
	}

	//�������;
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