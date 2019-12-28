#pragma once

#include <iostream>

//����¼;
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

//������;
class Caretaker
{
public:
	Memento *getMemento() { return _memento; }
	void setMemento(Memento *memento) { _memento = memento; }
	~Caretaker(){}
private:
	Memento *_memento;
};

//��Ҫ������Ϣ�Ķ���;
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

	//��������¼,������Ϣ;
	Memento *createMemento() { return new Memento(_state); }
	//�ӱ���¼�лָ���Ϣ;
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
	std::string _state;//��Ҫ���������;
};
