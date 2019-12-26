#pragma once

#include<iostream>
using namespace std;

class SDCard
{
public:
	virtual const std::string readSD() = 0;
	virtual void writeSD(const std::string msg) = 0;
};

class SDCardImpl :public SDCard
{
public:
	virtual const std::string readSD()
	{
		return "sd card read a msg: hello sd card.";
	}

	virtual void writeSD(const std::string msg)
	{
		cout << "sd card write a msg:" << msg.c_str();
	}

};

class Computer
{
public:
	virtual	const std::string readSD(SDCard *sDCard) = 0;
};

class thinkPadComputer :public Computer
{
public:
	const std::string readSD(SDCard *sDCard)
	{
		if (NULL != sDCard)
		{
			return sDCard->readSD();
		}
		return "";
	}
};


class TFCard
{
public:
	virtual const std::string readTF() = 0;
	virtual void writeTF(const std::string msg) = 0;
};

class TFCardImpl :public TFCard
{
public:
	virtual const std::string readTF() override
	{
		return "tf card read a msg: hello tf card.";
	}
	virtual void writeTF(const std::string msg) override
	{
		cout << "tf card write a msg:" << msg.c_str();
	}
};

class SDAdapterTF :public SDCard
{
public:
	SDAdapterTF(TFCard *tfCard) :_tfCard(tfCard) {}

	virtual const std::string readSD()
	{
		if (NULL != _tfCard)
		{
			cout << "adapter read tf card "<<endl;
			return _tfCard->readTF();
		}

		return "";
	}

	virtual void writeSD(const std::string msg)
	{
		if (NULL != _tfCard)
		{
			cout << "adapter write tf card ";
			_tfCard->writeTF(msg);
		}
	}

private:
	TFCard *_tfCard;
};

// void computerReadSDCard()
// {
// 	Computer *computer = new thinkPadComputer();
// 
// 	std::string readCardMsg = computer->readSD(new SDCardImpl());
// 
// 	cout << readCardMsg.c_str();
// 
// }

// void computerRead()
// {
// 	Computer *computer = new thinkPadComputer();
// 	std::string readCardMsg = computer->readSD(new SDCardImpl());
// 	cout << readCardMsg.c_str() << endl;
// 	cout << "=============================" << endl
// 
// 		TFCard *tfCard = new TFCardImpl();
// 	SDCard *sDAdapterTF = new SDAdapterTF(tfCard);
// 	cout << computer->readSD(sDAdapterTF).c_str() << endl;
// 
// }


