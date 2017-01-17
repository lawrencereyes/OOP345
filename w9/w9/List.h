#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

using namespace std;

namespace w9 {
	template <typename T>
	class List {
		vector<T> list;
	public:
		List() { }
		List(const char* fn) {
		ifstream file(fn);
			if (!file)
				throw string("*** Failed to open file ") +
			string(fn) + string(" ***");
			while (file) {
				T e;
				if (e.load(file))
					list.push_back(*new T(e));
			}
		}

		size_t size() const { return list.size(); }

		const T& operator[](size_t i) const { return list[i]; }

		void operator+=(const unique_ptr<T> &p) {
			list.push_back(*p);
		}

		void display(ostream& os) const {
			os << fixed << setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}