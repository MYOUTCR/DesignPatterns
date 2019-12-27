#pragma once

#include "visitor.h"

class ComputerVisitor
{
public:
	virtual void visit(KeyBoard *keyBoard) = 0;
	virtual void visit(Monitor *monitor) = 0;
	virtual void visit(Mouse *mouse) = 0;
	virtual void visit(Computer *computer) = 0;

	//virtual void visit(ComputerPart *computerPart) = 0;
};

class ComputerPartDisplayVisitor :public ComputerVisitor
{
public:
	virtual void visit(KeyBoard *keyBoard) override
	{
		std::cout << "Displaying KeyBoard" << std::endl;
	}
	virtual void visit(Monitor *monitor) override
	{
		std::cout << "Displaying Monitor" << std::endl;
	}
	virtual void visit(Mouse *mouse) override
	{
		std::cout << "Displaying Mouse" << std::endl;
	}

	virtual void visit(Computer *computer) override
	{
		std::cout << "Displaying Computer" << std::endl;
	}
};
