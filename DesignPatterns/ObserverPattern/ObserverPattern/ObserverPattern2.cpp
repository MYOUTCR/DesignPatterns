
#include "stdafx.h"
#include "ObserverPattern2.h"
#include "ObserverPattern.h"

Subject::Subject()
{

}

Subject::~Subject()
{
	for (auto itr = listObServers.begin(); itr != listObServers.end(); itr++)
	{
		ObServer *ob = *itr;
		delete ob;
		ob = NULL;
	}

	listObServers.clear();
}


void Subject::addAttach(ObServer *obServer)
{
	if (NULL != obServer)
	{
		if (!listObServers.empty())
		{
			if (std::find(listObServers.begin(), listObServers.end(), obServer) != listObServers.end())
				return;
		}

		listObServers.push_back(obServer);
	}
}

void Subject::setState(const std::string &msg)
{
	_msg = msg;

	for (auto itr = listObServers.begin(); itr != listObServers.end(); itr++)
	{
		ObServer *ob = *itr;
		ob->update();
	}
}

int main()
{
	Subject *subject = new Subject();
	ObServer *f1 = new F_ObServer(subject);
	ObServer *s2 = new S_ObServer(subject);
	ObServer *t3 = new T_ObServer(subject);

	subject->setState("msg1");
	cout << "\n\n " << endl;
	subject->setState("msg2");
	getchar();
	return 0;
}
