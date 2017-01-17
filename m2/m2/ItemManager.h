#ifndef ITEM_MANAGER_H_
#define ITEM_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class ItemManager{
	vector<Item> items;
	void addItem(vector<string> fields, int line);
public:
	ItemManager(string& file, char delim);
	void readCSV(string& file, char delim);
	void display(ostream& os);
	void graph(string file);
};

#endif