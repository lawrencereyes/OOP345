#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class Item{
	string name, installer, remover, code, desc;
public:
	Item(string name, string installer, string remover, string code, string desc);
	void display(ostream& os);
	void graph(ostream& os);
};

#endif