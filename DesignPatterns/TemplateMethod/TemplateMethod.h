#pragma once

#include<iostream>
using namespace std;

class Game
{
public:
	Game() {};
	~Game() {};

	virtual void play() final
	{
		initialize();
		startPlay();
		endPlay();
	}

	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;
};

class Cricket:public Game
{
public:
	Cricket() {}
	~Cricket() {};

	virtual void initialize()
	{
		cout << "Cricket Game initialize playing" << endl;
	}
	virtual void startPlay()
	{
		cout << "Cricket Game startPlay playing" << endl;
	}
	virtual void endPlay()
	{
		cout << "Cricket Game endPlay playing" << endl;
	}
};

class Football:public Game
{
public:
	Football() {}
	~Football() {};

	virtual void initialize()
	{
		cout << "Football  Game initialize playing" << endl;
	}
	virtual void startPlay()
	{
		cout << "Football  Game startPlay playing" << endl;
	}
	virtual void endPlay()
	{
		cout << "Football  Game endPlay playing" << endl;
	}

// 	virtual void play()//无法被重写
// 	{
// 		cout << "Football  Game play playing" << endl;
// 	}
};