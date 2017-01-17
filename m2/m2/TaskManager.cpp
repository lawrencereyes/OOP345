#include "TaskManager.h"
#include <sstream>
#include <algorithm>

TaskManager::TaskManager(string& file, char delim){
	readCSV(file, delim);
}

void TaskManager::readCSV(string& file, char delim){
	ifstream is;
	vector<string> fields;

	try{
		is.open(file);

		if (is.good()){
			string buf, buf2;
			stringstream ss;

			int line = 0;

			while (getline(is, buf)){
				line++;

				ss << buf;
				while (getline(ss, buf2, delim)){
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
			throw "Failed to open file: " + string(file);
	}
	catch (string err){
		cout << err << endl;
	}
}

void TaskManager::addTask(vector<string> fields, int line){
	int count = fields.size();
	string name, slots = "0", accept = "", reject = "";

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
		cerr << "Line " << line << ": expected 1-4 fields for a task, found " << count << endl;
		break;
	}

	if (!name.empty())
		tasks.push_back(Task(name, slots, accept, reject));
}

void TaskManager::display(ostream& os){
	for (auto task : tasks)
		task.display(os);
}

void TaskManager::graph(string file){
	ofstream os;
	string gvFile = file + ".gv";
	string pngFile = gvFile + ".png";
	os.open(gvFile);

	os << "digraph task" << " {" << endl;

	for (auto task : tasks)
		task.graph(os);

	os << "}";
	os.close();	

	string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

#ifdef _WIN32
	cmd = "\"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng " + gvFile + " -o " + pngFile;
#endif

	cout << "> " << cmd << endl;
	system(cmd.c_str());

	cout << "Would you like to open file: '" << pngFile << "'? (Y/N)" << endl;
	char opt;
	cin >> opt;
	if (tolower(opt) == 'y'){
		cout << "> " << pngFile << endl;
		system(pngFile.c_str());
	}
}