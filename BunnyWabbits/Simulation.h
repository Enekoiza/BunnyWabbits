#include "List.h"



class Simulation
{
private:
	List* colony = new List;
	vector<int> oldBunnies;
public:
	void Simulate();
	void nextYear();
	void killOld();

};