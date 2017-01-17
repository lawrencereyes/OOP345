#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <iostream>

using namespace std;

class Task{
	string name, slots, accept, reject;
public:
	Task(string name, string slots, string accept, string reject);
	void display(ostream& os);
	void graph(ostream& os);
};

#endif