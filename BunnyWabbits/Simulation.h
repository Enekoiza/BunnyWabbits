#include "List.h"

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation
{
private:
	List* colony = NULL;		//The list that will hold the bunnies
public:
	Simulation();		//Constructor
	
	~Simulation();		//Destructor

	void Simulate();	//A function that performs the algorith of the exercise as it indicates

};



#endif