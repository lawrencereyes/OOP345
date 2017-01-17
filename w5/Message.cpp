#include "Message.h"

using namespace w5;

Message::Message(ifstream & in, char c) {
	string line;

	getline(in, line, c);

	auto cr = line.find("\r");
	if (cr != string::npos){
		line.erase(line.begin() + cr);
	}

	int index = 0;

	while (index < line.size() && line[index] != ' '){
		user += line[index++];
	}

	index++; 

	if (index < line.size() && line[index] == '@'){
		index++;

		while (index < line.size() && line[index] != ' '){
			reply += line[index++];
		}
		index++;
	}

	while (index < line.size()){
		tweet += line[index++];
	}
}

bool Message::empty() const {
	return tweet.empty();
}

void Message::display(ostream & ostr) const {
	if (!empty()) {
		ostr << "Message\n";
		ostr << "  User  : " << user << "\n";
		if (!reply.empty()) {
			ostr << "  Reply : " << reply << "\n";
		}
		ostr << "  Tweet : " << tweet << "\n";
	}
}