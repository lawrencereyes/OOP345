#include <memory>
#include <iostream>
#include <iomanip>
#include "Element.h"
#include "List.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

w9::List<w9::Product> merge(const w9::List<w9::Description>& desc, const w9::List<w9::Price>& price) {
	w9::List<w9::Product> priceList;

	for (size_t i = 0; i < desc.size(); i++){
		for (size_t j = 0; j < price.size(); j++){
			if (desc[i].code == price[j].code){
				unique_ptr<w9::Product> prod(new w9::Product(desc[i].desc, price[j].price));
				prod->validate();
				priceList += prod;
			}
		}
	}
	return priceList;
}

int main(int argc, char** argv) {
	cout << "\nCommand Line : ";

	for (int i = 0; i < argc; i++) {
		cout << argv[i] << ' ';
	}

	 cout << endl;

	if (argc != 3) {
		cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}

	try {
		w9::List<w9::Description> desc(argv[1]);
		cout << endl;

		cout << setw(FWC) << "Code" <<
			setw(FWD) << "Description" << endl;
		cout << desc << endl;

		w9::List<w9::Price> price(argv[2]);
		cout << endl;

		cout << setw(FWC) << "Code" <<
			setw(FWP) << "Price" << endl;
		cout << price << endl;

		w9::List<w9::Product> priceList = merge(desc, price);
		cout << endl;

		cout << setw(FWD) << "Description" <<
			setw(FWP) << "Price" << endl;
		cout << priceList << endl;
	}

	catch (const string& msg) {
		cerr << msg << endl;
	}

	catch (const char* msg) {
		cerr << msg << endl;
	}

	cout << "\nPress any key to continue ... ";
	cin.get();
}