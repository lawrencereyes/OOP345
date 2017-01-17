#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define MAX_MESSAGES 10

namespace w5 {
	class Message {
		string user, tweet, reply;
	public:
		Message() {}
		Message(ifstream& in, char c);
		bool empty() const;
		void display(ostream& ostr) const;
	};
}