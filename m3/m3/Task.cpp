#include "Task.h"
#include <iomanip>

Task::Task(string name, string slots, string accept, string reject)
	: name(name), slots(slots), accept(accept), reject(reject){ }

void Task::display(ostream& os){
	os << setw(13) << left << "Task Name" << ": " << setw(16) << '[' + name + ']' << '[' << slots << ']';

	if (!accept.empty()){
		os << endl << setw(13) << left << " Continue to" << ": " << '[' << accept << ']';

		if (!reject.empty()){
			os << endl << setw(13) << left << " Redirect to" << ": " << '[' << reject << ']' << endl;
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

bool Task::hasAccept(){
	return !accept.empty();
}

bool Task::hasReject(){
	return !reject.empty();
}

string Task::getName(){
	return name;
}

string Task::getSlots(){
	return slots;
}

string Task::getAccept(){
	return accept;
}

string Task::getReject(){
	return reject;
}