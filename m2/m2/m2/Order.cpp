#include "Order.h"

Order::Order(string custName, string prodName, vector<string> itemList)
	: custName(custName), prodName(prodName), itemList(itemList) { }

void Order::display(ostream& os){
	os << "Customer Name: " << '"' << custName << '"'
		<< ", Product Name: " << '"' << prodName << '"'
		<< ", Item List: ";

	for (int i = 0; i < itemList.size(); i++){
		if (i != itemList.size() - 1)
			os << '"' << itemList[i] << '"' << ", ";
		else
			os << '"' << itemList[i] << '"' << endl;
	}
}