#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"

using namespace std;

int main(int argc, char** argv){
	if (argc != 7) {
		 cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]tasks delimiter [3]items file [4]items delimiter [5]orders file [6]orders delimiter" <<  endl;
		return 1;
	}
	cout << "Command Line Arguments" << endl << "--------------------------------" << endl;
	cout << "Tasks File Specified          = " << argv[1] << endl;
	cout << "Task Record Field Delimiter   = " << argv[2][0] << endl;
	cout << "Items File Specified          = " << argv[3] << endl;
	cout << "Items Record Field Delimiter  = " << argv[4][0] << endl;
	cout << "Orders File Specified         = " << argv[5] << endl;
	cout << "Orders Record Field Delimiter = " << argv[6][0] << endl;
	cout << "-------------------------------" << endl;

	cout << endl << "Tasks" << endl << "-------------------------------" << endl;
	TaskManager tm = TaskManager( string(argv[1]), argv[2][0]);
	tm.display(cout);
	cout << "-------------------------------" << endl << endl;
	tm.graph( string(argv[1]));

	cout <<  endl << "Items" << endl << "-------------------------------" << endl;
	ItemManager im = ItemManager( string(argv[3]), argv[4][0]);
	im.display(cout);
	cout << "-------------------------------" << endl << endl;
	im.graph( string(argv[3]));

	cout << endl << "Orders" << endl << "-------------------------------" << endl;
	OrderManager om = OrderManager( string(argv[5]), argv[6][0]);
	om.display(cout);
	cout << "-------------------------------" << endl << endl;

	cout << "Press Enter Key to Exit ... " << endl;
	cin.get();
	cin.ignore(1000, '\n');

	return 0;
}