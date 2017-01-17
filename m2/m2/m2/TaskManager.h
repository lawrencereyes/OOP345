#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Task.h"

using namespace std;

class TaskManager{
	vector<Task> tasks;
	void addTask(vector<string> fields, int line);
public:
	TaskManager(string& file, char delim);
	void readCSV(string& file, char delim);
	void display(ostream& os);
	void graph(string file);
};

#endif