#include "Bunny.h"


Bunny::Bunny(int ages, int IDs)
{
	ID = new int;
	colour = new string;
	sex = new string;
	name = new string;
	age = new int;
	*ID = IDs;
	*age = ages;
	int randomColour = rand() % 4;
	int randomName = rand() % 10;
	int randomSex = rand() % 2;
	*colour = allColours[randomColour];
	*name = allNames[randomName];
	*sex = allSexs[randomSex];
}

Bunny::~Bunny()
{
	if (ID != NULL)
	{
		delete ID;
	}
	if (sex != NULL)
	{
		delete sex;
	}
	if (colour != NULL)
	{
		delete colour;
	}
	if (name != NULL)
	{
		delete name;
	}
	if (age != NULL)
	{
		delete age;
	}
}

void Bunny::growUp()
{
	(*age)++;
}

string* Bunny::getSex()
{
	return sex;
}

int* Bunny::checkAge()
{
	return age;
}

int* Bunny::getID()
{
	return ID;
}

void Bunny::setID(int IDs)
{
	*ID = IDs;
}

void Bunny::printBunny()
{
	cout << "--------------" << endl;
	cout << "Name: " << *name << endl;
	cout << "Colour: " << *colour << endl;
	cout << "Age: " << *age << endl;
	cout << "Sex: " << *sex << endl;
}



