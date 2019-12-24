#pragma once

#include <iostream>
#include "MediatorPattern2.h"

using namespace std;
class Mediator
{
public:
	void showMessage(user *use, const std::string &msg)
	{
		cout << use->getName().c_str() << ": " << msg.c_str() << endl;
	}
};

