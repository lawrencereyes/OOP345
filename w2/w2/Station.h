#pragma once

#include <iostream>
#include <string.h>

using namespace std;

enum PassType { student, adult };

class Station {
	string station_;
	unsigned int student_passes;
	unsigned int adult_passes;
public:
	Station();
	void set(const string& station, unsigned int student_, unsigned int adult_);
	void update(PassType, int numOfPasses);
	unsigned inStock(PassType);
	const string& getName() const;
};