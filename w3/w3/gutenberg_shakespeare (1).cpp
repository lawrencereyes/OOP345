#include "Text.h"

using namespace w3;
using namespace std;

size_t Text::size() {
	return count;
}

Text::Text(const char* filename) : count(0), lineTable('\0') {
	ifstream is(filename);

	if (is.is_open()) {
		string line;

		while (getline(is, line))
			count++;

		lineTable = new string[count];

		is.clear();
		is.seekg(0);
		for (size_t line = 0; line < count; line++) {
			getline(is, lineTable[line]);
			auto cr = lineTable[line].find('\r');
			if (cr != string::npos) {
				lineTable[line].erase(cr);
			}
		}

		is.close();
	}
	else {
		cerr << "Cannot open file '" << filename << "'.\n";
		exit(3);
	}
}

Text& Text::operator=(const Text& t) {
	if (this != &t) {
		if (lineTable) {
			delete[] lineTable;
			lineTable = '\0';
			count = 0;
		}

		if (t.lineTable) {
			count = t.count;
			lineTable = new string[count];

			for (size_t line = 0; line < count; line++) {
				lineTable[line] = t.lineTable[line];
			}
		}
	}

	return *this;
}

Text&& Text::operator= (Text&& t) {

	if (this != &t) {
		if (lineTable) {
			delete[] lineTable;
			lineTable = '\0';
			count = 0;
		}//zombiefied

		count = t.count;
		lineTable = t.lineTable;

		t.count = 0;
		t.lineTable = '\0';
	}
	return move(*this);
}

Text::Text(const Text& t) {
	count = 0;
	lineTable = '\0';
	*this = t;
}

Text::Text(Text&& t) {
	count = 0;
	lineTable = '\0';
	*this = move(t);
}

Text::~Text() {
	delete[]lineTable;
}