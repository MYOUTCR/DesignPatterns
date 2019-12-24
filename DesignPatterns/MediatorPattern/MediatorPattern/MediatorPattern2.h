#pragma once

#include <iostream>

using namespace std;
class Mediator;

class user
{
public:
	user(const std::string &name, Mediator *mediator) :_name(name), _mediator(mediator) {}
	~user() {}
	void setMessage(const std::string &msg);
	const std::string getName() { return _name; }
private:
	Mediator *_mediator;
	std::string _name;
};

