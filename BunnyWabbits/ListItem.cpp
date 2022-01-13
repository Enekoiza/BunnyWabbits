#include "ListItem.h"


//Constructor that receives the age and ID, and with the bunny constructor generates a new instance of Bunny and set the next to the passed next.
ListItem::ListItem(int age, int ID, ListItem *next)
{
	b1 = new Bunny(age, ID);
	this->next = next;
}

//Destructor that deletes the private variables of the class
ListItem::~ListItem()
{
	if (b1 != NULL)
	{
		delete b1;
	}
}

//A function that returns the address of the next item
ListItem* ListItem::getNext()
{
	return next;
}

//A function to set the value of the next item
void ListItem::setNext(ListItem* next)
{
	this->next = next;
}

//A function that will return the value of the bunny inside of the instance called
Bunny* ListItem::getBunny()
{
	return b1;
}
