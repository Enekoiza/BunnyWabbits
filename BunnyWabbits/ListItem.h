#include "Bunny.h"

#ifndef LISTITEM_H
#define LISTITEM_H


class ListItem
{
private:
	Bunny* b1 = NULL;								//An instance of the class Bunny that will hold the attributes of the bunny
	ListItem *next = NULL;							//A listItem pointer that will be used to know which is the address of the next item in the list

public:
	ListItem() { next = NULL; };					//Constructor
	ListItem(int age, int ID, ListItem* next);		//Constructor
	~ListItem();									//Destructor

	ListItem* getNext();							//A function that returns the address of the next item

	void setNext(ListItem* next);					//A function to set the value of the next item

	Bunny* getBunny();								//A function that will return the value of the bunny inside of the instance called
};



#endif