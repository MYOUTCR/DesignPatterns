// Builder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Builder.h"

int main()
{

	MealBuilder *mealBuilder = new MealBuilder;

	Meal *vegMeal = mealBuilder->prepareVegMeal();
	cout << "veg Meal" << endl;
	vegMeal->showItem();
	cout << "Total Cost:" << vegMeal->getCost()<< endl;

	Meal *nonVegMeal = mealBuilder->prepareNonVegMeal();
	cout << "nonVeg Meal" << endl;
	nonVegMeal->showItem();
	cout << "Total Cost:" << nonVegMeal->getCost() << endl;

	getchar();
    return 0;
}

