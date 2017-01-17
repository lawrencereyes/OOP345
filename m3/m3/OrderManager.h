#ifndef ORDER_MANAGER_H_
#define ORDER_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Order.h"

using namespace std;

class OrderManager
{
	vector<Order> orders;
	void addOrder(vector<string> fields, int line);

public:
	OrderManager(string& file, char delim);
	void readCSV(string& file, char delim);
	void display(ostream& os);
	void graph(string file);
	bool validate();

	vector<Order> getOrders();
};

#endif