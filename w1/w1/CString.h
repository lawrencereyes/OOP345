#ifndef	W1_CSTRING_H_
#define W1_CSTRING_H_

#include <iostream>
#include <string.h>

using namespace std;

#define MAX 3

namespace w1 {
	class CString {
		char str[MAX + 1];
	public:
		CString(char* args);
		void display(ostream& ostr);
	};
	ostream& operator<<(ostream& ostr, CString& cs);
}
#endif
