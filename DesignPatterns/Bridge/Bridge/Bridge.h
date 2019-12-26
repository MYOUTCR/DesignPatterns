#pragma once

#include <iostream>

using namespace std;

//创建桥接实现接口;
class DrawAPI
{
public:
	virtual void drawCircle(int nRadius, int nX, int nY) = 0;
};

class RedCircle :public DrawAPI
{
public:
	virtual void drawCircle(int nRadius, int nX, int nY) override
	{
		cout << "Draw Circle[ Color:Red,radius:" << nRadius << " X:" << nX << ",Y:" << nY << " ]" << endl;
	}
};

class GreenCircle :public DrawAPI
{
public:
	virtual void drawCircle(int nRadius, int nX, int nY) override
	{
		cout << "Draw Circle[ Color:Green,Radius:" << nRadius << " X:" << nX << ",Y:" << nY << " ]" << endl;
	}
};


class Shape
{
public:
	Shape(DrawAPI *drawAPI) :_drawAPI(drawAPI) {}
	virtual void draw() = 0;
protected:
	DrawAPI *_drawAPI;
};

class Circle :public Shape
{
public:
	Circle(int nRadius, int nX, int nY, DrawAPI *drawAPI)
		:_nX(nX),
		 _nY(nY),
		_nRadius(nRadius),
		Shape(drawAPI)
	{

	}

	virtual void draw() override
	{
		if (NULL != _drawAPI)
		{
			_drawAPI->drawCircle(_nRadius, _nX, _nY);
		}
	}

private:
	int _nX;
	int _nY;
	int _nRadius;
};