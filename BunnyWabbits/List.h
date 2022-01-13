#include "ListItem.h"


#ifndef LIST_H
#define LIST_H


class List
{
private:
	ListItem* head;
	int* bunnyID;
	vector<int> oldBunnies;
	int* maleBunnies;
	int* femaleBunnies;
	vector<int> randomBunnies;

public:
	List();
	~List();

	void printColony();
	void createColony();
	void insertBunny(int age, int ID);
	ListItem* getHead();
	bool killBunny(int ID);
	vector<int> checkOld();
	void nextYear();
	void countMaleFemale();
	int getMales();
	int getFemales();
	int getNextBunnyID();
	void reproduce();
	int countTotalItems();
	void foodShortage();
	void killOld(vector<int> oldBunnies);
};












#endif