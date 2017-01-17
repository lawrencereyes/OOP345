#include "Task.h"

Task::Task(string name, string slots, string accept, string reject)
	: name(name), slots(slots), accept(accept), reject(reject){ }

void Task::display(ostream& os){
	os << "Name: " << '"' << name << '"';

	if (slots != "0"){
		os << ", Slots: " << '"' << slots << '"';

		if (!accept.empty()){
			os << ", Accept: " << '"' << accept << '"';

			if (!reject.empty()){
				os << ", Reject: " << '"' << reject << '"' << endl;
			}
			else
				os << endl;
		}
		else
			os << endl;
	}
	else
		os << endl;
}

void Task::graph(ostream& os){
	if (!accept.empty())
		os << '"' << name << '"' << "->" << '"' << accept << '"' << " [color=green];" << endl;
	if (!reject.empty())
		os << '"' << name << '"' << "->" << '"' << reject << '"' << " [color=red];" << endl;

	if (accept.empty() && reject.empty())
		os << '"' << name << '"' << " [shape=box];" << endl;
}