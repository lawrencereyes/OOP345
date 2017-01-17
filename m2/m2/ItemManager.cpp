#include "ItemManager.h"
#include <sstream>
#include <algorithm>

ItemManager::ItemManager(string& file, char delim){
	readCSV(file, delim);
}

void ItemManager::readCSV(string& file, char delim){
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

					// make sure it isn't an empty line and add it to fields
					if (!buf2.empty())
						fields.push_back(buf2);
				}

				// add to items
				addItem(fields, line);
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

void ItemManager::addItem(vector<string> fields, int line){
	int count = fields.size();
	string name, installer, remover, code, desc = "";

	switch (count)
	{
	case 5:
		desc = fields[4];
	case 4:
		name = fields[0];
		installer = fields[1];
		remover = fields[2];
		code = fields[3];
		break;
	default:
		cerr << "Line " << line << ": expected 4 or 5 fields for an item, found " << count << endl;
		break;
	}

	if (!name.empty())
		items.push_back(Item(name, installer, remover, code, desc));
}

void ItemManager::display(ostream& os){
	for (auto item : items)
		item.display(os);
}

void ItemManager::graph(string file){
	ofstream os;
	string gvFile = file + ".gv";
	string pngFile = gvFile + ".png";
	os.open(gvFile);

	os << "digraph item" << " {" << endl;

	for (auto item : items)
		item.graph(os);

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