#include "ListItem.h"


#ifndef LIST_H
#define LIST_H


class List
{
private:
	ListItem* head;							//A listItem pointer to be the start point of the list
	int* bunnyID;							//An integer pointer to store the bunnyID so every bunny will be different from the rest and in the future we could see how many bunnies did populate our colony
	vector<int> oldBunnies;					//A vector to store the bunnyID of the bunnies that are 10 years old in the next turn and need to die
	int* maleBunnies;						//An integer to store the number of male bunnies
	int* femaleBunnies;						//An integer to store the number of female bunnies
	vector<int> randomBunnies;				//A vector to store the bunnyID of the bunnies that will die if the population exceed 50

public:
	List();									//Constructor
	~List();								//Destructor

	void printColony();						//A function that will move through the list and print the bunnies' information
	void createColony();					//A function that will create the 5 first bunnies of the colony and join them into the head
	void insertBunny(int age, int ID);		//A function that will call the listItem constructor and will insert the bunny into the list
	bool killBunny(int ID);					//A function that will return true if the bunnyID passed into it has been killed/deleted
	vector<int> checkOld();					//A function that will return a vector<int> with all the BunnyID that need to be killed because they will be 10 years old next turn
	void nextYear();						//A function that will go through all the list aging all the bunnies by 1 year (NEW TURN)
	void countMaleFemale();					//A function that will increase the maleBunnies and femaleBunnies pointers each time a male or female is found inside the list
	int getMales();							//A function that return the pointer to maleBunnies
	int getFemales();						//A function that return the pointer to femaleBunnies
	int getNextBunnyID();					//A function that will check the last ID used to create a bunny and will return the next to it
	void reproduce();						//A function that will take the number of male bunnies and female bunnies and will create as many bunnies as necesary
	int countTotalItems();					//A function that will go through the list counting how many listItem are currently in the list, it will return the number
	void foodShortage();					//A function that will kill half of the population of the list when it reaches 50 or more
	void killOld(vector<int> oldBunnies);	//A function that will kill the oldBunnies found in the list
};


#endif