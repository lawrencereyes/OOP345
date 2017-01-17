#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <vector>

using namespace std;

class Order{
	string custName, prodName;
	vector<string> itemList;
public:
	Order(string custName, string prodName, vector<string> itemList);
	void display(ostream& os);
};

#endif