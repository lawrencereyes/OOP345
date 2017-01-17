#include "Grades.h"

Grades::Grades(const char* filePath)
{
	ifstream is;

	try{
		is.open(filePath);

		if (is.fail())
			throw "Failed to open file: " + string(filePath);

		string buf;
		double grade;

		while (is.good()){
			getline(is, buf, '\n');
			count++;
		}

		is.clear();
		is.seekg(0, ios::beg);
		
		students = new string[count];
		grades = new double[count];

		int i = 0;
		while (is.good()){
			getline(is, students[i], ' ');

			getline(is, buf, '\n');
			grade = atof(buf.c_str());
			grades[i] = grade;

			i++;
		}
	}
	catch (std::string err){
		cout << err << endl;
	}
}