#include "TaskManager.h"
#include <sstream>
#include <algorithm>

TaskManager::TaskManager(std::string& file, char delim){
	readCSV(file, delim);
}

void TaskManager::readCSV(std::string& file, char delim){
	std::ifstream is;
	std::vector<std::string> fields;

	try{
		is.open(file);

		if (is.good()){
			std::string buf, buf2;
			std::stringstream ss;

			int line = 0;

			while (std::getline(is, buf)){
				line++;

				ss << buf;
				while (std::getline(ss, buf2, delim)){
					buf2.erase(0, buf2.find_first_not_of(' '));
					buf2.erase(buf2.find_last_not_of(' ') + 1);

					if (!buf2.empty())
						fields.push_back(buf2);
				}

				addTask(fields, line);
				fields.clear();

				ss.clear();
			}
			is.close();
		}
		else
			throw "Failed to open file: " + std::string(file);
	}
	catch (std::string err){
		std::cout << err << std::endl;
	}
}

void TaskManager::addTask(std::vector<std::string> fields, int line){
	int count = fields.size();
	std::string name, slots = "0", accept = "", reject = "";

	switch (count){
	case 4:
		reject = fields[3];
	case 3:
		accept = fields[2];
	case 2:
		slots = fields[1];
	case 1:
		name = fields[0];
		break;
	default:
		std::cerr << "Line " << line << ": expected 1-4 fields for a task, found " << count << std::endl;
		break;
	}

	if (!name.empty())
		tasks.push_back(Task(name, slots, accept, reject));
}

void TaskManager::display(std::ostream& os){
	for (auto task : tasks)
		task.display(os);
}

void TaskManager::graph(std::string file){
	std::ofstream os;
	std::string gvFile = file + ".gv";
	std::string pngFile = gvFile + ".png";
	os.open(gvFile);

	os << "digraph task" << " {" << std::endl;

	for (auto task : tasks)
		task.graph(os);

	os << "}";
	os.close();	

	std::string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;
	std::cout << "> " << cmd << std::endl;
	system(cmd.c_str());
	std::cout << "> " << pngFile << std::endl;
	system(pngFile.c_str());
}