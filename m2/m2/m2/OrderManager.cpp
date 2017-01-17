#include "OrderManager.h"
#include <sstream>
#include <algorithm>

OrderManager::OrderManager(string& file, char delim){
	readCSV(file, delim);
}

void OrderManager::readCSV(string& file, char delim){
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

				addOrder(fields, line);
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

void OrderManager::addOrder(vector<string> fields, int line){
	int count = fields.size();
	string custName = "", prodName = "";
	vector<string> itemList;

	if (count < 3)
		cerr << "Line " << line << ": expected 3 or more fields for an order, found " << count << endl;
	else{
		custName = fields[0];
		prodName = fields[1];

		for (int i = 2; i < count; i++)
			itemList.push_back(fields[i]);
	}

	if (!custName.empty())
		orders.push_back(Order(custName, prodName, itemList));
}

void OrderManager::display(ostream& os){
	for (auto order : orders)
		order.display(os);
}