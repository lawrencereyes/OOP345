#pragma once

#include "Station.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace w2 {
	class Stations : public Station {
		string stations_;
		int number_of_stations;
		int file_student_passes, file_adult_passes;
	public:
		Stations(char* s);
		~Stations();
		void update() const;
		void restock() const;
		void report() const;
	};
}