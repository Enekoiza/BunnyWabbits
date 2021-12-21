#include "Bunny.h"




void Bunny::printBunny()
{
	cout << "--------------" << endl;
	cout << "Name: " << *name << endl;
	cout << "Colour: " << *colour << endl;
	cout << "Age: " << *age << endl;
	cout << "Sex: " << *sex << endl;
}

void Bunny::generateBunnyValues(int age)
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
