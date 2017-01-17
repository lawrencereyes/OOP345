#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w3 {
	class Text {
		size_t  count;
		string *lineTable;
	public:
		size_t size();
		Text() : count(0) {}
		Text(const char* filename);
		Text& operator=(const Text& t);
		Text&& operator= (Text&& t);
		Text(const Text& t);
		Text(Text&& t);
		~Text();
	};
}