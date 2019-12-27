// Visitor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "visitor.h"
#include "visitor2.h"

void KeyBoard::accept(ComputerVisitor &computerVisitor)
{
	computerVisitor.visit(this);
}

void Monitor::accept(ComputerVisitor &computerVisitor)
{
	computerVisitor.visit(this);
}

void Mouse::accept(ComputerVisitor &computerVisitor)
{
	computerVisitor.visit(this);
}

void Computer::accept(ComputerVisitor &computerVisitor)
{
	if (!_listChPart.empty())
	{
		for (auto itr = _listChPart.begin(); itr != _listChPart.end(); itr++)
		{
			(*itr)->accept(computerVisitor);
		}
	}

	computerVisitor.visit(this);
}

int main()
{
	ComputerPart *cp = new Computer;
	ComputerPartDisplayVisitor cpVisitor;
	cp->accept(cpVisitor);

	getchar();
    return 0;
}

