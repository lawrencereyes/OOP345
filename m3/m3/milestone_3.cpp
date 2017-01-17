#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"
#include "Factory.h"
#include <iomanip>

using namespace std;

int main(int argc, char** argv){
	if (argc != 5) {
		cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]items file [3]orders file [4]file delimiter" << endl;
		return 1;
	}
	cout << "Command Line Arguments" << endl << setw(22) << setfill('-') << '-' << endl << setfill(' ');
	cout << "Tasks File Specified          = " << argv[1] << endl;
	cout << "Items File Specified          = " << argv[2] << endl;
	cout << "Orders File Specified         = " << argv[3] << endl;
	cout << "Record Field Delimiter        = " << argv[4][0] << endl;

	// create a new task manager
	cout << endl << "Building the Network of Tasks" << endl << setw(29) << setfill('-') << '-' << endl << setfill(' ');
	TaskManager tm = TaskManager(string(argv[1]), argv[4][0]);
	tm.display(cout);
	tm.graph(string(argv[1]));

	// create a new order manager
	cout << endl << "List of Accepted Customer Orders" << endl << setw(32) << setfill('-') << '-' << endl << setfill(' ');
	OrderManager om = OrderManager(string(argv[3]), argv[4][0]);
	om.display(cout);
	om.graph(string(argv[3]));

	// create a new item manager
	cout << endl << "List of In-Stock Items" << endl << setw(22) << setfill('-') << '-' << endl << setfill(' ');
	ItemManager im = ItemManager(string(argv[2]), argv[4][0]);
	im.display(cout);
	im.graph(string(argv[2]));

	// validate tasks
	cout << endl << "Validating Tasks" << endl << setw(16) << setfill('-') << '-' << endl << setfill(' ');
	if (!tm.validate())
		cout << "Task integrity check failed." << endl;
	else
		cout << "Task integrity check passed." << endl;

	// validate orders
	cout << endl << "Validating Orders" << endl << setw(17) << setfill('-') << '-' << endl << setfill(' ');
	if (!om.validate())
		cout << "Order integrity check failed." << endl;
	else
		cout << "Order integrity check passed." << endl;

	// validate items
	cout << endl << "Validating Items" << endl << setw(16) << setfill('-') << '-' << endl << setfill(' ');
	if (!im.validate())
		cout << "Item integrity check failed." << endl;
	else
		cout << "Item integrity check passed." << endl;

	// create a factory
	cout << endl << "Starting factory" << endl << setw(16) << setfill('-') << '-' << endl << setfill(' ');
	Factory f(tm, om, im);

	cout << "Press Enter Key to Exit ... " << endl;
	cin.get();
	cin.ignore(1000, '\n');

	return 0;
}