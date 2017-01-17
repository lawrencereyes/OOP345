#ifndef FACTORY_H_
#define FACTORY_H_

#include "TaskManager.h"
#include "Machine.h"
#include "OrderManager.h"
#include <deque>

using namespace std;

class Factory
{
	vector<Machine> machines;
	Task* sourceNode = nullptr;
	deque<Order> jobs;
	Machine* curMach, *nextMach;
	bool sinkNode = false;

public:
	Factory(TaskManager& tm, OrderManager& om, ItemManager& im);

	void findSource(TaskManager& tm);
	void findAllJobs(OrderManager& om);
	void createAllMachines(TaskManager& tm);
	void timeLoop(ItemManager& im);
	void moveToNextMachine();
};

#endif