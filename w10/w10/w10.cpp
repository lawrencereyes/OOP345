#include <iostream>
#include <string>
#include "SecureData.h"

int main(int argc, char** argv) {
	cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << ' ';
	}
	cout << endl;
	if (argc != 4) {
		cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	char key = argv[3][0];

	try {
		w10::SecureData sd(argv[1], key);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << endl;

	}
	catch (const string& msg) {
		cerr << msg << endl;
	}

	cout << "\nPress any key to continue ... ";
	cin.get();
}