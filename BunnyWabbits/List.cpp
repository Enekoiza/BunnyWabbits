#include "List.h"
#include "windows.h"
#include <algorithm>


//Constructor that creates the pointers and set the bunnyID to 0
List::List()
{
	bunnyID = new int;
	maleBunnies = new int;
	femaleBunnies = new int;
	head = new ListItem(NULL, NULL, NULL);
	head = NULL;
	*bunnyID = 0;

}

//Destructor
List::~List()
{
	if (bunnyID != NULL)
	{
		delete bunnyID;
	}
	if (maleBunnies != NULL)
	{
		delete maleBunnies;
	}
	if (femaleBunnies != NULL)
	{
		delete femaleBunnies;
	}
	if (head != NULL)
	{
		delete head;
	}

}

//Prints the whole list of items, calling the bunny object and using its printBunny() function
void List::printColony()
{
	ListItem* current = head;

	while (current != NULL)
	{
		current->getBunny()->printBunny();
		current = current->getNext();

	}
}

//As defined we want 5 bunnies at the beggining with random data but with age = 0 and getting the next ID
void List::createColony()
{
	for (int x = 0; x < 5; x++)
	{
		this->insertBunny(0, getNextBunnyID());
	}

}


//Inserting bunny to the list by pointing the next of the new bunny to the Head and the head to the new bunny
void List::insertBunny(int age, int ID)
{
	ListItem* bunny = new ListItem(age, ID, NULL);

	bunny->setNext(head);
	head = bunny;
	
	return;
}

//With the ID of the bunny we compare it to every bunny inside the list and if found, delete it and concatenate the list to not lose the track
bool List::killBunny(int ID)
{
	ListItem* current = head;
	ListItem* previous = new ListItem;

	while (current != NULL)
	{
		if (ID == *(current->getBunny()->getID()))
		{
			previous->setNext(current->getNext());
			if (current == head)
			{
				head = current->getNext();
			}
			delete current;
			return true;
		}

		previous = current;
		current = current->getNext();
	}
	return false;
}

//The worksheets ask to kill every bunny that is 10 years old, so we move through the list and return a vector with the ID of all old bunnies to kill.
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

//Every turn, the bunnies will grow up by 1 year, iterates through the list growing up every bunny
void List::nextYear()
{
	ListItem* current = head;

	while (current != NULL)
	{
		current->getBunny()->growUp();
		current = current->getNext();
	}


}

//A function to iterate through the list checking how many males and females are in it, adding them inside the pointer
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

//Returns a pointer to maleBunnies which stores the number of male bunnies in the list
int List::getMales()
{
	return *maleBunnies;
}

//Returns a pointer to femaleBunnies which stores the number of female bunnies in the list

int List::getFemales()
{
	return *femaleBunnies;
}

//A function that returns the next ID of the bunny list
int List::getNextBunnyID()
{
	return ++(*bunnyID);
}

//A function that insert a number of bunnies equal to females times males. If one of both sexes becomes 0 return without adding anything
void List::reproduce()
{
	int newBunnies = getMales() * getFemales();

	if (newBunnies == 0) return;


	for (int x = 0; x < newBunnies; x++)
	{
		insertBunny(0, getNextBunnyID());
	}
}

//A function that iterates through the list and counts how many items are inside the list
int List::countTotalItems()
{
	int totalBunnies = 0;
	ListItem* current = head;

	while (current != NULL)
	{
		current = current->getNext();
		totalBunnies++;
	}

	return totalBunnies;
}

//A function to kill bunnies in case that the population excees 50.
void List::foodShortage()
{
	int total = countTotalItems();

	int halfTotal = total / 2;

	while (total > halfTotal)
	{
		ListItem* current = head;
		while (current != NULL)
		{
			int randomKill = rand() % 2;

			if (randomKill == 1)
			{
				if (std::find(randomBunnies.begin(), randomBunnies.end(), *current->getBunny()->getID()) != randomBunnies.end())
				{
					break;
				}
				else
				{
					randomBunnies.push_back(*current->getBunny()->getID());
				}
			}

			if ((randomBunnies.size() > halfTotal) && (total < 51))
			{
				return;
			}

			current = current->getNext();
		}

		total = total - randomBunnies.size();

		while (!randomBunnies.empty())
		{
			killBunny(randomBunnies.back());
			randomBunnies.pop_back();
		}

	}

}

//A function which receives the oldBunnies vector and kills all the bunnies inside it
void List::killOld(vector<int> oldBunnies)
{

	while (!oldBunnies.empty())
	{
		killBunny(oldBunnies.back());
		oldBunnies.pop_back();
		if (oldBunnies.empty())
		{
			return;
		}
	}

}
