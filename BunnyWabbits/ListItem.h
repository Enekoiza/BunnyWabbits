#include "Bunny.h"

#ifndef LISTITEM_H
#define LISTITEM_H


class ListItem
{
private:
	Bunny* b1 = NULL;
	ListItem *next = NULL;

public:
	ListItem() { next = NULL; };
	ListItem(int age, int ID, ListItem* next);
	~ListItem();

	ListItem* getNext();

	void setNext(ListItem* next);

	Bunny* getBunny();
};
















#endif