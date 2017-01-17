#include "Factory.h"
#include <iomanip>

Factory::Factory(TaskManager & tm, OrderManager& om, ItemManager& im){
	findSource(tm);
	findAllJobs(om);
	createAllMachines(tm);
	timeLoop(im);
}

void Factory::findSource(TaskManager& tm){
	vector<Task> tasks = tm.getTasks();

	for (auto &task : tasks){
		if (sourceNode == nullptr){
			if (task.hasAccept() && !task.hasReject()){
				int i = 0;
				for (; i < tasks.size(); i++){
					if (task.getName() == tasks[i].getAccept() || task.getName() == tasks[i].getReject())
						break;
				}

				if (i == tasks.size())
					sourceNode = &task;
			}
		}
		else
			cerr << "Multiple source nodes found." << endl;
	}

	if (sourceNode != nullptr){
		cout << "Source node found: '" << sourceNode->getName() << "'" << endl;

		int index = 0;
		for (; index < tasks.size(); index++){
			if (tasks[index].getName() == sourceNode->getName())
				break;
		}

		machines.push_back(Machine(index, *sourceNode, true));
		machines[0].display(cout);
	}
	else
		cerr << "No source nodes found." << endl;
}

void Factory::findAllJobs(OrderManager& om){
	for (auto order : om.getOrders())
		jobs.push_back(order);
}

void Factory::createAllMachines(TaskManager& tm){
	vector<Task> tasks = tm.getTasks();
	for (int i = 0; i < tasks.size(); i++){
		if (tasks[i].getName() != sourceNode->getName())
			machines.push_back(Machine(i, tasks[i], false));
	}
}

void Factory::timeLoop(ItemManager& im){
	int time = 0, jobIndex = 0;

	for (auto &mach : machines)	{
		if (mach.isSource()){
			curMach = &mach;

			for (auto &next : machines) {
				if (mach.getTask().getAccept() == next.getTask().getName())
					nextMach = &next;
			}
			break;
		}
	}

	if (curMach != nullptr){
		while (jobs.size() > 0){
			cout << endl << "Time loop time: " << time + 1 << endl;
			cout << "Current machine: " << curMach->getTask().getName() << endl;

			if (!curMach->getTask().hasAccept() && !curMach->getTask().hasReject()){
				jobs.erase(jobs.begin() + jobIndex);
				jobIndex++;
			}

			if (jobs.size() > 0){
				cout << "Jobs to process:" << endl
					<< '\t' << "Customer: " << jobs[jobIndex].getCustName() << endl
					<< '\t' << "Product: " << jobs[jobIndex].getProdName() << endl
					<< '\t' << "Items: " << endl;
				for (auto item : jobs[jobIndex].getItemList())
					cout << "\t\t" << item << endl;

				int result = curMach->process(jobs[jobIndex], im);
				if (result == 1){
					for (auto &next : machines){
						if (curMach->getTask().getAccept() == next.getTask().getName())
							nextMach = &next;
					}

					cout << "Coin flip passed!" << endl;

					moveToNextMachine();
				}
				else if (result == 0){
					for (auto &next : machines){
						if (curMach->getTask().getReject() == next.getTask().getName())
							nextMach = &next;
					}

					cout << "Coin flip failed!" << endl;

					moveToNextMachine();
				}
				else{
					moveToNextMachine();
				}
			}

			time++;
		}

		cout << endl
			<< setw(29) << setfill('-') << '-' << endl
			<< "No jobs left to process." << endl
			<< "Factory simulation completed." << endl
			<< setw(29) << setfill('-') << '-' << setfill(' ')
			<< endl << endl;
	}
	else
		cout << "No source machine found, exiting simulation." << endl;
}

void Factory::moveToNextMachine(){
	if (nextMach != nullptr){
		cout << "Moving from machine " << curMach->getTask().getName() << " to " << nextMach->getTask().getName() << endl;
		curMach = nextMach;
		nextMach = nullptr;
	}
}