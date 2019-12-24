#pragma once

#include <iostream>
#include <list>
using namespace std;

class ObServer;
class Subject
{
public:
	Subject();
	~Subject();
	void addAttach(ObServer *obServer);
	void setState(const std::string &msg);
	const std::string &getState() { return _msg; }
private:
	list<ObServer*> listObServers;
	std::string _msg;
};