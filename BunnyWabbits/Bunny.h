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
	int *ID = NULL;
	string* colour = NULL;
	string* name = NULL;
	int* age = NULL;
	string* sex = NULL;
	vector<string> allNames = { "Thor", "Capt. America", "Ironman", "Black Widow", "Spiderman", "Superman", "Ant Man", "Batman", "Flash", "Aquaman" };
	vector<string> allSexs = { "Male", "Female" };
	vector<string> allColours = { "White", "Brown", "Black", "Spotted"};


public:
	Bunny() {};
	Bunny(int ages, int IDs);
	~Bunny();

	void growUp();
	void printBunny();
	int* checkAge();
	int* getID();
	void setID(int ID);
	string* getSex();

};












#endif
