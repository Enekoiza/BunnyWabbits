#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>



#ifndef BUNNY_H
#define BUNNY_H

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Bunny
{
private:
	int *ID = NULL;				//A integer pointer that will hold the unique ID
	string* colour = NULL;		//A string pointer that will hold the colour randomly generated
	string* name = NULL;		//A string pointer that will hold the name randomly generated
	int* age = NULL;			//An integer pointer that will hold the age
	string* sex = NULL;			//A string pointer that will hold the sex randomly generated
	//Vector that contains elements to be randomized for the bunny characteristics
	vector<string> allNames = { "Thor", "Capt. America", "Ironman", "Black Widow", "Spiderman", "Superman", "Ant Man", "Batman", "Flash", "Aquaman" };
	vector<string> allSexs = { "Male", "Female" };
	vector<string> allColours = { "White", "Brown", "Black", "Spotted"};


public:
	Bunny() {};					//Constructor
	Bunny(int ages, int IDs);	//Constructor
	~Bunny();					//Destructor

	void growUp();				//A function that increases the age of the bunny by 1
	void printBunny();			//A function that prints into the screen the bunny characteristics/parameters
	int* checkAge();			//A function that returns the age of the bunny
	int* getID();				//A function that returns the ID of the bunny
	void setID(int ID);			//A function to set the ID of the bunny
	string* getSex();			//A function that returns the sex of the bunny

};












#endif
