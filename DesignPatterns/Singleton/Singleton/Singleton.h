#pragma once

#include <iostream>
using namespace std;


class Singleton
{
public:
	~Singleton() {}
	const std::string getInfo() { return _info; }
	static Singleton* instance();

private:
	Singleton() { _info = "Singleton Info."; }

	static Singleton* _singleton;
	std::string _info;
	class GC
	{
	public:
		~GC()
		{
			if (NULL != _singleton)
			{
				delete _singleton;
				_singleton = NULL;
				cout << "delete Singleton" << endl;
			}
		}
	};

	static GC gc;
};

Singleton* Singleton::_singleton = NULL;
Singleton::GC Singleton::gc;

Singleton* Singleton::instance()
{
	if (NULL == _singleton)
	{
		cout << "new Singleton" << endl;

		_singleton = new Singleton();
	}
	return _singleton;
}

