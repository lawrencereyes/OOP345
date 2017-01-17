#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Grades{
	string* students;
	double* grades;
	string* letters;
	int count = 0;

public:
	Grades(const char* filePath);

	template<typename func>
	void displayGrades(ostream &os, func exp) const{
		for (int i = 0; i < count; i++){
			auto letter = exp(grades[i]);
			os << students[i].c_str() << " " << grades[i] << " " << letter << endl;
		}
	}

	Grades(const Grades& other) = delete;
	Grades(Grades&& other) = delete;
	Grades& operator=(const Grades& other) = delete;
	Grades&& operator=(Grades&& other) = delete;
};