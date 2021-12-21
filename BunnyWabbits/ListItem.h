#include "Bunny.h"

#ifndef LISTITEM_H
#define LISTITEM_H


class ListItem
{
private:
	Bunny *b1 = new Bunny;
	ListItem *next = new ListItem;

public:
	ListItem() { next = NULL; };
	ListItem(int age);
	~ListItem();


};
















#endif