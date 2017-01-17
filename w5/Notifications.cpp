#include "Notifications.h"

using namespace w5;

Notifications::Notifications(const Notifications & n) {
	msg = 0;
	*this = n;
}

Notifications & Notifications::operator=(const Notifications & n) {
	if (this != &n) {
		if (msg) {
			delete[]msg;

			msg = 0;
			count = 0;

			if (n.msg) {
				count = n.count;
				msg = new Message[MAX_MESSAGES];

				for (int m = 0; m < count; m++) {
					msg[m] = n.msg[m];
				}
			}
		}
		return *this;
	}
}

Notifications::Notifications(const Notifications && n) {
	msg = 0;
	*this = move(n);
}

Notifications && Notifications::operator=(Notifications && n) {
	if (this != &n) {
		if (msg) delete[]msg;

		msg = 0;
		count = 0;
	
		count = n.count;
		msg = n.msg;

		n.count = 0;
		n.msg = 0;
	}

	return move(*this);
}

Notifications::~Notifications() {
	if(msg) delete[]msg;
}

void Notifications::operator+=(const Message & msg_) {
	if (count < MAX_MESSAGES) {
		msg[count] = msg_;
		count++;
	}
}

void Notifications::display(ostream & os) const {
	for (int m = 0; m < count; m++) {
		msg[m].display(os);
	}
}