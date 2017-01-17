#include "ItemManager.h"
#include <sstream>
#include <algorithm>

ItemManager::ItemManager(std::string& file, char delim){
	readCSV(file, delim);
}

void ItemManager::readCSV(std::string& file, char delim){
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

				addItem(fields, line);
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

void ItemManager::addItem(std::vector<std::string> fields, int line){
	int count = fields.size();
	std::string name, installer, remover, code, desc = "";

	switch (count){
	case 5:
		desc = fields[4];
	case 4:
		name = fields[0];
		installer = fields[1];
		remover = fields[2];
		code = fields[3];
		break;
	default:
		std::cerr << "Line " << line << ": expected 4 or 5 fields for an item, found " << count << std::endl;
		break;
	}

	if (!name.empty())
		items.push_back(Item(name, installer, remover, code, desc));
}

void ItemManager::display(std::ostream& os){
	for (auto item : items)
		item.display(os);
}

void ItemManager::graph(std::string file){
	std::ofstream os;
	std::string gvFile = file + ".gv";
	std::string pngFile = gvFile + ".png";
	os.open(gvFile);

	os << "digraph item" << " {" << std::endl;

	for (auto item : items)
		item.graph(os);

	os << "}";
	os.close();	

	std::string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

#ifdef _WIN32
	cmd = "\"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng " + gvFile + " -o " + pngFile;
#endif

	std::cout << "> " << cmd << std::endl;
	if (system(cmd.c_str()) == 0){
		std::cout << "Would you like to open file: '" << pngFile << "'? (Y/N)" << std::endl;
		char opt;
		std::cin >> opt;
		if (tolower(opt) == 'y'){
			std::cout << "> " << pngFile << std::endl;
			system(pngFile.c_str());
		}
	}
	else
		std::cerr << "Creation of flowchart file '" << pngFile << "' failed." << std::endl;
}

bool ItemManager::validate(){
	bool allValid = true;

	for (auto item : items){
		if (!item.hasInstaller())
			std::cerr << item.getName() << ": missing or invalid installer." << std::endl;
		if (!item.hasRemover())
			std::cerr << item.getName() << ": missing or invalid remover." << std::endl;

		if (!item.hasInstaller() || !item.hasRemover())
			allValid = false;
	}

	return allValid;
}

std::vector<Item> ItemManager::getItems(){
	return items;
}