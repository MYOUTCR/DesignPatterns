#pragma once

#include <iostream>

//备忘录;
class Memento
{
public:
	Memento(const std::string &s) :_state(s) {}
	const std::string getState()
	{
		return _state;
	}
	void setState(const std::string &s)
	{
		_state = s;
	}
private:
	std::string _state;
};

//管理者;
class Caretaker
{
public:
	Memento *getMemento() { return _memento; }
	void setMemento(Memento *memento) { _memento = memento; }
	~Caretaker(){}
private:
	Memento *_memento;
};

//需要保存信息的对象;
class Originator
{
public:
	const std::string getState()
	{
		return _state;
	}
	void setState(const std::string &s)
	{
		_state = s;
	}

	//创建备忘录,保存信息;
	Memento *createMemento() { return new Memento(_state); }
	//从备忘录中恢复信息;
	void setMemento(Memento *memento) {
		if (NULL != memento)
		{
			_state = memento->getState();
		}
	}

	void show()
	{
		std::cout << "state: " << _state.c_str() << std::endl;
	}

private:
	std::string _state;//需要保存的属性;
};
