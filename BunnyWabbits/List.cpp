#include "List.h"
#include "windows.h"



void List::printColony()
{
	ListItem* current = head;

	while (current != NULL)
	{
		current->getBunny()->printBunny();
		current = current->getNext();

	}
}

void List::createColony()
{
	for (int x = 0; x < 5; x++)
	{
		this->insertBunny(0, 2);
	}

}

void List::insertBunny(int age, int ID)
{
	ListItem* bunny = new ListItem(age, ID, NULL);

	bunny->setNext(head);
	head = bunny;
	
	return;
}

ListItem* List::getHead()
{
	return head;
}

bool List::killBunny(int ID)
{
	ListItem* current = head;
	ListItem* previous = new ListItem;

	while (current != NULL)
	{
		if (ID == *(current->getBunny()->getID()))
		{
			previous->setNext(current->getNext());
			delete current;
			return true;
		}

		previous = current;
		current = current->getNext();
	}
	return false;
}

