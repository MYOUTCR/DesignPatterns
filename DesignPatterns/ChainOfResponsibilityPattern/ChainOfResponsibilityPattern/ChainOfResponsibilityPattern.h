#pragma once

#include <iostream>

using namespace std;

class AbstractLogger
{
public:
	AbstractLogger(int nLevel, AbstractLogger *nextLogger) :_nLevel(nLevel), _nextLogger(nextLogger) {}
	~AbstractLogger(){}

	void loggerMessage(int nLevel, const std::string &log)
	{
		if (_nLevel <= nLevel)
		{
			write(log);
		}
		
		if (NULL != _nextLogger)
		{
			_nextLogger->loggerMessage(nLevel, log);
		}
	}

	virtual void write(const std::string &log) = 0;

private:
	AbstractLogger *_nextLogger;
	int _nLevel;
};


class ConsoleLogger :public AbstractLogger
{
public:
	ConsoleLogger(int nLevel, AbstractLogger *nextLogger):AbstractLogger(nLevel, nextLogger){}

	virtual void write(const std::string &log) override
	{
		cout << "ConsoleLogger: " << log.c_str() << endl;
	}
};

class FileLogger :public AbstractLogger
{
public:
	FileLogger(int nLevel, AbstractLogger *nextLogger) :AbstractLogger(nLevel, nextLogger) {}

	virtual void write(const std::string &log) override
	{
		cout << "FileLogger: " << log.c_str() << endl;
	}
};

class ErrorLogger :public AbstractLogger
{
public:
	ErrorLogger(int nLevel, AbstractLogger *nextLogger) :AbstractLogger(nLevel, nextLogger) {}

	virtual void write(const std::string &log) override
	{
		cout << "ErrorLogger: " << log.c_str() << endl;
	}
};


