#include "Simulation.h"
#include <windows.h>

Simulation::Simulation()
{
	colony = new List;
}

Simulation::~Simulation()
{
	if (colony != NULL)
	{
		delete colony;
	}
}

void Simulation::Simulate()
{
	vector<int> oldBunnies;

	colony->createColony();
	while (true)
	{
		cout << "--------------------NEXT ROUND--------------------" << endl;
		colony->countMaleFemale();
		colony->reproduce();
		colony->printColony();
		colony->nextYear();
		Sleep(1000);
		colony->killOld(colony->checkOld());
		if (colony->countTotalItems() > 50)
		{
			colony->foodShortage();
		}
		cout << "--------------------END ROUND--------------------" << colony->countTotalItems() << endl;
		Sleep(2000);
	}
}


