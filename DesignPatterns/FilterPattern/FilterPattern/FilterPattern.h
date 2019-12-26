#pragma once

#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
	Person(const std::string &name, const std::string &gender, const std::string &maritaStatus)
		:_name(name),
		_gender(gender),
		_maritalStatus(maritaStatus)
		{

		}
	const std::string getName()
	{
		return _name;
	}

	const std::string getGender()
	{
		return _gender;
	}

	const std::string getMaritalStatus()
	{
		return _maritalStatus;
	}

private:
	std::string _name;
	std::string _gender;
	std::string _maritalStatus;
};

class Criteria
{
public:
	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) = 0;
private:
	std::list<Person*> _meetPersons;
};

class CriteriaMale:public Criteria
{
public:
	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) override
	{
		std::list<Person*> malePersons;
		if (!persons.empty())
		{
			for (auto itr = persons.begin(); itr != persons.end(); itr++)
			{
				if ((*itr)->getGender() == "Male")
				{
					malePersons.push_back(*itr);
				}
			}
		}

		return malePersons;
	}
};

class CriteriaFeMale :public Criteria
{
public:
	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) override
	{
		std::list<Person*> malePersons;
		if (!persons.empty())
		{
			for (auto itr = persons.begin(); itr != persons.end(); itr++)
			{
				if ((*itr)->getGender() == "Female")
				{
					malePersons.push_back(*itr);
				}
			}
		}

		return malePersons;
	}
};

class CriteriaSingle :public Criteria
{
public:
	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) override
	{
		std::list<Person*> malePersons;
		if (!persons.empty())
		{
			for (auto itr = persons.begin(); itr != persons.end(); itr++)
			{
				if ((*itr)->getMaritalStatus() == "Single")
				{
					malePersons.push_back(*itr);
				}
			}
		}

		return malePersons;
	}
};

class AndCriteria :public Criteria
{
public:
	AndCriteria(Criteria *criteria, Criteria *otherCriteria)
		:_criteria(criteria),
		_otherCriteria(otherCriteria)
	{

	}

	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) override
	{
		std::list<Person*> malePersons = _criteria->meetCriteria(persons);
		return _criteria->meetCriteria(malePersons);
	}

private:
	Criteria *_criteria;
	Criteria *_otherCriteria;
};

class OrCriteria :public Criteria
{
public:
	OrCriteria(Criteria *criteria, Criteria *otherCriteria)
		:_criteria(criteria),
		_otherCriteria(otherCriteria)
	{

	}

	virtual std::list<Person*> meetCriteria(std::list<Person*> &persons) override
	{
		std::list<Person*> malePersons;
		std::list<Person*> fristMalePersons = _criteria->meetCriteria(persons);
		std::list<Person*> oterMalePersons = _otherCriteria->meetCriteria(persons);

		if (!fristMalePersons.empty())
			malePersons = fristMalePersons;
		if (!oterMalePersons.empty())
		{
			for (auto itr = oterMalePersons.begin(); itr != oterMalePersons.end(); itr++)
			{
				if (!malePersons.empty())
					if (std::find(malePersons.begin(), malePersons.end(), *itr) != malePersons.end())continue;

				malePersons.push_back(*itr);
			}
		}

		return malePersons;
	}

private:
	Criteria *_criteria;
	Criteria *_otherCriteria;
};

void printPersons(std::list<Person*> persons) {

	if (!persons.empty())
	{
		for (auto itr = persons.begin(); itr != persons.end(); itr++)
		{
			cout << "Person : [Name:" << (*itr)->getName().c_str()
				<< ", Gender : " << (*itr)->getGender().c_str()
				<< ", Marital Status : " << (*itr)->getMaritalStatus().c_str() << " ]" << endl;
		}
	}
}