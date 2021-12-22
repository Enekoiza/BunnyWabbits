#include "Bunny.h"




void Bunny::growUp()
{
	(*age)++;
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

void Bunny::generateBunnyValues(int ages, int IDs)
{
	*ID = IDs;
	*age = ages;
	int randomColour = rand() % 4;
	int randomName = rand() % 10;
	int randomSex = rand() % 2;
	this->colour = &allColours[randomColour];
	this->name = &allNames[randomName];
	this->sex = &allSexs[randomSex];

}

