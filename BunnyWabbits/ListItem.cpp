#include "ListItem.h"

ListItem::ListItem(int age, int ID, ListItem *next)
{
	b1->generateBunnyValues(age, ID);
	this->next = next;
}

ListItem::~ListItem()
{
	if (b1 != NULL)
	{
		delete b1;
	}
}

ListItem* ListItem::getNext()
{

	return next;
}

void ListItem::setNext(ListItem* next)
{
	this->next = next;
}

Bunny* ListItem::getBunny()
{
	return b1;
}
