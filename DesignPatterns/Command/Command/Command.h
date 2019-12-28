#pragma once

#include <iostream>

//����������;
class Command
{
public: 
	Command(){}
	virtual ~Command(){}
	virtual void execute() = 0;
};

//����ִ�ж���;
class Received
{
public:
	void action()
	{
		std::cout << "Received action" << std::endl;
	}
};


//����������;
class ConcreteCommand :public Command
{
public:
	ConcreteCommand(Received *received)
		:_received(received)
	{

	}

	virtual ~ConcreteCommand()
	{
		if (NULL != _received)
		{
			delete _received;
			_received = NULL;
		}
	}

	virtual void execute() override
	{
		if (NULL != _received)
		{
			std::cout << "ConcreteCommand::execute" << std::endl;
			_received->action();
		}
	}
protected:
	Received *_received;
};

//���������;
class Invoker
{
public:
	Invoker(Command *command)
		:_command(command)
	{

	}

	virtual ~Invoker() {}

	void call()
	{
		if (NULL != _command)
		{
			_command->execute();
		}
	}

protected:
	Command *_command;
};