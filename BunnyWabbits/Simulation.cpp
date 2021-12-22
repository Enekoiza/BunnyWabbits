#include "Simulation.h"
#include <windows.h>

void Simulation::Simulate()
{
	colony->createColony();
	for (int x = 0; x < 11; x++)
	{
		colony->printColony();
		this->nextYear();
		this->killOld();
		Sleep(50);
	}

	colony->printColony();
}

void Simulation::nextYear()
{
	ListItem* current = colony->getHead();

	while (current != NULL)
	{
		current->getBunny()->growUp();
		current = current->getNext();
	}


}

void Simulation::killOld()
{
	


}
