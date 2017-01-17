#pragma once

#include <iostream>

using namespace std;

namespace w10 {

	class Cryptor {
	public:
		char operator()(char in, char key) const { return in ^ key; }
	};
	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};
	ostream& operator<<(ostream&, const SecureData&);
}