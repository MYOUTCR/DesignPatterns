
#include "stdafx.h"
#include "MediatorPattern.h"
#include "MediatorPattern2.h"

void user::setMessage(const std::string &msg)
{
	if(NULL != _mediator)
	{
		_mediator->showMessage(this, msg);
	}
}


int main()
{
	Mediator *mediator = new Mediator;

	user *userA = new user("A", mediator);
	user *userB = new user("B", mediator);

	userA->setMessage("hello B");
	userB->setMessage("hello A");

	getchar();
}