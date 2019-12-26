// FilterPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FilterPattern.h"

int main()
{
	std::list<Person*> listPerson;

	listPerson.push_back(new Person("Robert", "Male", "Single"));
	listPerson.push_back(new Person("John", "Male", "Married"));
	listPerson.push_back(new Person("Laura", "Female", "Married"));
	listPerson.push_back(new Person("Diana", "Female", "Single"));
	listPerson.push_back(new Person("Mike", "Male", "Single"));
	listPerson.push_back(new Person("Bobby", "Male", "Single"));

	Criteria *male = new CriteriaMale();
	Criteria *female = new CriteriaFeMale();
	Criteria *single = new CriteriaSingle();
	Criteria *singleMale = new AndCriteria(single, male);
	Criteria *singleOrFemale = new OrCriteria(single, female);

	cout << "Males: " << endl;
	printPersons(male->meetCriteria(listPerson));

	cout << "\nFemales: " << endl;
	printPersons(female->meetCriteria(listPerson));

	cout << "\nSingle Males:" << endl;
	printPersons(singleMale->meetCriteria(listPerson));

	cout << "\nSingle Or Females:" << endl;
	printPersons(singleOrFemale->meetCriteria(listPerson));

	getchar();
    return 0;
}

