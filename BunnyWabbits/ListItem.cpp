#include "ListItem.h"

ListItem::ListItem(int age)
{
	b1->generateBunnyValues(age);
	next = NULL;
}

ListItem::~ListItem()
{
	if (b1 != NULL)
	{
		delete b1;
	}
}
