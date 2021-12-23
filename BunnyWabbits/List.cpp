#include "List.h"
#include "windows.h"



List::List()
{
	head = NULL;
	*bunnyID = 0;

}

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
		this->insertBunny(0, getNextBunnyID());
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

vector<int> List::checkOld()
{
	ListItem* current = head;

	while (current != NULL)
	{
		if (*current->getBunny()->checkAge() == 10)
		{
			oldBunnies.push_back(*current->getBunny()->getID());
		}
		current = current->getNext();
	}

	return oldBunnies;
}

void List::nextYear()
{
	ListItem* current = head;

	while (current != NULL)
	{
		current->getBunny()->growUp();
		current = current->getNext();
	}


}

void List::countMaleFemale()
{
	ListItem* current = head;
	*maleBunnies = 0;
	*femaleBunnies = 0;

	while (current != NULL)
	{
		if (*current->getBunny()->checkAge() > 3)
		{
			if (*current->getBunny()->getSex() == "Male")
			{
				(*maleBunnies)++;
			}
			else
			{
				(*femaleBunnies)++;
			}
		}
		current = current->getNext();
	}
}

int List::getMales()
{
	return *maleBunnies;
}

int List::getFemales()
{
	return *femaleBunnies;
}

int List::getNextBunnyID()
{
	return ++(*bunnyID);
}

void List::reproduce()
{
	int newBunnies = getMales() * getFemales();

	if (newBunnies == 0) return;


	for (int x = 0; x < newBunnies; x++)
	{
		insertBunny(0, getNextBunnyID());
	}
}

int List::countTotalItems()
{
	*totalBunnies = 0;
	ListItem* current = head;

	while (current != NULL)
	{
		current = current->getNext();
		(*totalBunnies)++;
	}

	return *totalBunnies;
}

void List::foodShortage(int total, int halfTotal)
{
	ListItem* current = head;
	

	while (total > halfTotal)
	{
		while (current != NULL)
		{
			int randomKill = rand() % 2;

			if (randomKill == 1)
			{
				randomBunnies.push_back(*current->getBunny()->getID());
			}

			if ((randomBunnies.size() > halfTotal) && (total < 51))
			{
				return;
			}

			current = current->getNext();
		}

		while (!randomBunnies.empty())
		{
			killBunny(randomBunnies.back());
			randomBunnies.pop_back();
		}

		total = countTotalItems();

		if (total > halfTotal)
		{
			foodShortage(countTotalItems(), halfTotal);
		}

		if (total > 50)
		{
			foodShortage(countTotalItems(), (countTotalItems() / 2));
		}
	}

}

void List::killOld(vector<int> oldBunnies)
{
	if (!oldBunnies.empty())
	{
		while (!oldBunnies.empty())
		{
			killBunny(oldBunnies.back());
			oldBunnies.pop_back();
			if (oldBunnies.empty() && (countTotalItems() == 0))
			{
				return;
			}
		}
	}
}
