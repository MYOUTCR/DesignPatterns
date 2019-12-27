#pragma once

class State;

class Context
{
public:
	Context() :_state(NULL) {}

	void setState(State *state)
	{
		_state = state;
	}

	State *getState()
	{
		return _state;
	}

private:
	State *_state;
};

