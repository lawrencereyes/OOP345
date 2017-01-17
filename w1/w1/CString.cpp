#include "CString.h"

using namespace w1;

CString::CString(char* s) {
	if (s = nullptr){
		str[0] = '\0';
	}
	else {
		for (int i = 0; i < MAX; i++) {
			str[i] = s[i];
			if (s[i] == '\0') {
				break;
			}
		}
		str[MAX] = '\0';
	}
}

void CString::display(ostream & ostr) {
	ostr << str;
}

ostream & w1::operator<<(ostream & ostr, CString & cs){
	static int counter = 0;

	cout << counter << ": ";
	cs.display(cout);
	counter++;

	return ostr;
}

