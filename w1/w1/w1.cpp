/*
using namespace std;
using namespace w1;

int main() {
	char* command = "w1 oop345 btp305";

	CString str(command);

	return 0;
}*/

/* strtok example */
#include <iostream>
#include "CString.h"

using namespace std;
using namespace w1;

int main(int argc, char argv[]){

	cout << "Command Line: ";

	for (int r = 0; r < argc; r++) {
		cout << argv[r];
	}

	cout << "Maximum number of charaters stored : " << MAX << endl;

	for (int args = 1; args < MAX; args++) {
		cout << args - 1 << ": ";
	}

	if (argc == 1) {
		cout << "Insufficient number of arguments (min 1)" << endl;
	}
	system("pause");
	return 0;
}