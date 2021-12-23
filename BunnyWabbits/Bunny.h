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
	int *ID = new int;
	string* colour = new string;
	string* name = new string;
	int* age = new int;
	string* sex = new string;
	vector<string> allNames = { "Thor", "Capt. America", "Ironman", "Black Widow", "Spiderman", "Superman", "Ant Man", "Batman", "Flash", "Aquaman" };
	vector<string> allSexs = { "Male", "Female" };
	vector<string> allColours = { "White", "Brown", "Black", "Spotted"};


public:
	Bunny() {};
	~Bunny() {};

	void growUp();
	void printBunny();
	void generateBunnyValues(int age, int ID);
	int* checkAge();
	int* getID();
	void setID(int ID);
	string* getSex();

};












#endif
