#include "Bunny.h"

//Constructor that randomized the colour, sex and name, and gives an exclusive ID and the age. It also creates the pointers of the private variables.
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

//Destructor that delete all the pointers inside the bunny class
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

//A function that increases the age of the bunny by 1
void Bunny::growUp()
{
	(*age)++;
}

//A function that returns the sex of the bunny
string* Bunny::getSex()
{
	return sex;
}

//A function that returns the age of the bunny
int* Bunny::checkAge()
{
	return age;
}

//A function that returns the ID of the bunny
int* Bunny::getID()
{
	return ID;
}

//A function to set the ID of the bunny
void Bunny::setID(int IDs)
{
	*ID = IDs;
}

//A function that prints into the screen the bunny characteristics/parameters
void Bunny::printBunny()
{
	cout << "--------------" << endl;
	cout << "Name: " << *name << endl;
	cout << "Colour: " << *colour << endl;
	cout << "Age: " << *age << endl;
	cout << "Sex: " << *sex << endl;
}



