#pragma once

#include <iostream>

#include "State1.h"

class State
{
public:
	virtual void doAction(Context *context) = 0;
	virtual const std::string to_String()=0;
};

class StartState :public State
{
public:
	virtual void doAction(Context *context) override
	{
		if (NULL != context)
		{
			std::cout << "Player is in start state." << std::endl;
			context->setState(this);
		}
	}

	virtual const std::string to_String()override
	{
		return "Start state";
	}
};

class StopState :public State
{
public:
	virtual void doAction(Context *context) override
	{
		if (NULL != context)
		{
			std::cout << "Player is in stop state." << std::endl;
			context->setState(this);
		}
		
	}

	virtual const std::string to_String()override
	{
		return "Stop state";
	}

};


