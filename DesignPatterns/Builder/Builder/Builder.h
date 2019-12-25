#pragma once
#include <iostream>
#include <list>
using namespace std;

//������ģʽʹ��һ�����򵥵Ķ��󹹽���һ�����ӵĶ����������ģʽ���ͳ�Ϊ������ģʽ��

//ʳ���װ;
class Packing
{
public:
	virtual const std::string pack() = 0;
};

//ʳ����Ŀ;
class Item
{
public:
	virtual std::string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};

class Wrapper :public Packing
{
public:
	virtual const std::string pack()
	{
		return "Wrapper";
	}
};

class Bottle :public Packing
{
public:
	virtual const std::string pack()
	{
		return "Bottle";
	}
};


class Burger :public Item
{
public:
	virtual Packing* packing()
	{
		return new Wrapper();
	}
	virtual float price() = 0;
};

class ColdDrink :public Item
{
	virtual Packing* packing()
	{
		return new Bottle();
	}
	virtual float price() = 0;
};


class VegBurger :public Burger
{
public:
	virtual float price()
	{
		return 25;
	}

	std::string name()
	{
		return "Veg Burger";
	}
};

class ChickenBurger :public Burger
{
public:
	virtual float price()
	{
		return 50.5;
	}

	std::string name()
	{
		return "Chicken Burger";
	}
};

class Coke :public ColdDrink
{
public:
	virtual float price()
	{
		return 30.5;
	}

	std::string name()
	{
		return "Coke";
	}
};

class Pepsi :public ColdDrink
{
public:
	virtual float price()
	{
		return 28.5;
	}

	std::string name()
	{
		return "Pepsi";
	}
};


class Meal
{
public:
	void addItem(Item* item)
	{
		if (NULL != item)
		{
			listItem.push_back(item);
		}
	}

	float getCost()
	{
		float fCost = 0.0;
		if (!listItem.empty())
		{
			for (auto itr = listItem.begin(); itr != listItem.end(); itr++)
			{
				fCost += (*itr)->price();
			}
		}

		return fCost;
	}

	void showItem()
	{
		if (!listItem.empty())
		{
			for (auto itr = listItem.begin(); itr != listItem.end(); itr++)
			{
				cout << "Item: " << (*itr)->name().c_str()<<", ";
				cout << "packing: " << (*itr)->packing()->pack().c_str() << ", ";
				cout << "price: " << (*itr)->price() << endl;

			}
		}
	}

private:
	list<Item*> listItem;
};

//ʵ�ʵ�builder�ฺ�𴴽�Meal����;
class MealBuilder
{
public:
	Meal *prepareVegMeal()
	{
		Meal *meal = new Meal;
		meal->addItem(new VegBurger());
		meal->addItem(new Coke());

		return meal;
	}

	Meal *prepareNonVegMeal()
	{
		Meal *meal = new Meal;
		meal->addItem(new ChickenBurger());
		meal->addItem(new Pepsi());

		return meal;
	}
};
