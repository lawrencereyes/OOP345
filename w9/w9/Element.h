#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

using namespace std;

namespace w9 {
	struct Description {
		unsigned code;
		string desc;

		bool load(ifstream& f) {
			f >> code >> desc;
			return f.good();
		}

		void display(ostream& os) const {
			os << setw(FWC) << code << setw(FWD)
				<< desc << endl;
		}
	};

	struct Price {
		unsigned code;
		double price;

		bool load(ifstream& f) {
			f >> code >> price;
			return f.good();
		}

		void display(ostream& os) const {
			os << setw(FWC) << code << setw(FWP)
				<< price << endl;
		}
	};

	struct Product {
		string desc;
		double price;

		Product() {}

		Product(const string& str, double p) : desc(str), price(p) {}

		void display(ostream& os) const {
			os << setw(FWD) << desc << setw(FWP)
				<< price << endl;
		}

		void validate() const
		{
			if (price < 0.00)
			{
				throw "***Negative prices are invalid***";
			}
		}
	};
}