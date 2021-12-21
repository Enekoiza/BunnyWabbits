#include "Bunny.h"

Bunny::Bunny(int age)
{
	this->age = &age;
	srand(time(NULL));
	int randomColour = rand() % 4;
	int randomName = rand() % 10;
	int randomSex = rand() % 2;
	this->colour = &allColours[randomColour];
	this->name = &allNames[randomName];
	this->sex = &allSexs[randomSex];


}

Bunny::~Bunny()
{
	if (name != NULL)
	{
		delete this->name;
	}
	if (colour != NULL)
	{
		delete this->colour;
	}
	if (age != NULL)
	{
		delete this->age;
	}
	if (sex != NULL)
	{
		delete this->sex;
	}
}
