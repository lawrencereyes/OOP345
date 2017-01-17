#include "Station.h"

Station::Station() {
	station_ = '\0';
}

void Station::set(const string & station, unsigned int student_, unsigned int adult_) {
	station_ = station;
	student_passes = student_;
	adult_passes = adult_;
}

void Station::update(PassType station_passes, int numOfPasses) {
	switch (station_passes) {
	case student: student_passes += numOfPasses; break;
	case adult: adult_passes += numOfPasses; break;
	}
}

unsigned Station::inStock(PassType station_passes) {
	int passes;

	if (station_passes == student) {
		passes = student;
	}
	else if (station_passes == adult) {
		passes = adult;
	}

	return passes;
}

const string & Station::getName() const {
	return station_;
}