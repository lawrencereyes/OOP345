#pragma once

#include "Message.h"

using namespace std;

namespace w5 {
	class Notifications {
		Message *msg;
		int count;
	public:
		Notifications() : count(0), msg(new Message[MAX_MESSAGES]) {}
		Notifications(const Notifications& n);
		Notifications& operator=(const Notifications& n);
		Notifications(const Notifications&& n);
		Notifications&& operator=(Notifications&& n);
		~Notifications();
		void operator+=(const Message& msg_);
		void display(ostream& os) const;
	};
}