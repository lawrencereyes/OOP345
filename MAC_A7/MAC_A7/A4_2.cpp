#include <iostream>
#include <string>

using namespace std;

void address(char *address, char *city);

int main(void) {
	char address_[100] = "3400 Riverspray Crescent";
	char city_[50] = "Mississauga";

	char user_city_[50];
	cout << "Enter city: ";
	cin >> user_city_;

	bool validation = false;
	do{
		if (strncmp(city_, user_city_, 50) == 0) {
			address(address_, city_);
			validation = true;
		}
		else {
			cout << "The city entered do not match any on our records." << endl;
			cout << endl;

			cout << "Enter city: ";
			cin >> user_city_;
		}
	}while (validation == false);

	system("pause");
	return 0;
}

void address(char *address, char *city) {
	cout << address << ", " << city << endl;
}