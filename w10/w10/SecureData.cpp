#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include "SecureData.h"

namespace w10 {
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		fstream input(file, ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		nbytes = 0;
		input >> noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}

		nbytes--;
		input.clear();
		input.seekg(0, ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		code(key);
		cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(ostream& os) const {
		if (text && !encoded)
			os << text << endl;
		else if (encoded)
			throw string("\n***Data is encoded***\n");
		else
			throw string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		//converter(text, key, nbytes, Cryptor());

		thread t1(bind(converter, text, key, nbytes / 2, Cryptor()));
		thread t2(bind(converter, text + nbytes / 2, key, nbytes - (nbytes / 2), Cryptor()));

		t1.join();
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw string("\n***No data stored***\n");
		else if (!encoded)
			throw string("\n***Data is not encoded***\n");
		else {
			ofstream ofs(file, ios::binary | ios::trunc);
			if (!ofs)
			{
				throw string("\n***Fuke could not be opened***\n");
			}

			ofs.write(text, nbytes);
			ofs.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		ifstream ifs(file, ios::binary);
		if (!ifs)
		{
			throw string("\nFile not opened\n");
		}

		if (text)
		{
			delete[] text;
		}

		ifs.seekg(0, ios::end);
		nbytes = (int)ifs.tellg();
		text = new char[nbytes + 1];

		ifs.seekg(0, ios::beg);
		ifs.read(text, nbytes);
		text[nbytes] = '\0';
		ifs.close();

		cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		code(key);
		cout << "Data decrypted in memory\n\n";
	}

	ostream& operator<<(ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}