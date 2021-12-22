#include "ListItem.h"


#ifndef LIST_H
#define LIST_H


class List
{
private:
	ListItem* head;



public:
	List() { head = NULL; };

	void printColony();
	void createColony();
	void insertBunny(int age, int ID);
	ListItem* getHead();
	bool killBunny(int ID);
};












#endif