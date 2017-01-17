#include "Stations.h"

w2::Stations::Stations(char * s) {
	fstream data_file;
	data_file.open(s, ios::in);

	Station sta;
	char station_name[20];

	if (!data_file.fail()) {
		/*
		* reads the values from the file
		*/
		data_file >> number_of_stations;
		data_file.ignore(5, ';');
		data_file.ignore(1, '\n');

		for (int s = 0; s < number_of_stations; s++) {
			//name of the station
			data_file.getline(station_name, 20, ';');

			stations_ = station_name;

			//number of student passes
			data_file >> file_student_passes;
			data_file.ignore(5, ' ');

			//number of adult passes
			data_file >> file_adult_passes;
			data_file.ignore(5, '\n');

			sta.set(stations_, file_student_passes, file_adult_passes);

			/*
			* Updates the file with the new values
			*/
			data_file << number_of_stations << ';' << endl;

			//name of station entered in the file
			data_file << station_name << ';';

			//new amount of passes
			data_file << file_student_passes << ' ' << file_adult_passes << endl;
		}
	}
	else {
		std::cout << "ERROR... File could not be open." << endl;
	}
	data_file.close();
}

w2::Stations::~Stations() {
	stations_ = '\0';
}

void w2::Stations::update() const {
	/*
	* Takes input from the user
	*/
	Station s;

	std::cout << "Passes Sold : " << endl;
	std::cout << "--------------" << endl;

	for (int p = 0; p < number_of_stations; p++) {
		int student_passes_sold, adult_passes_sold;

		//accepts the number of passes sold and updates the data for each station
		std::cout << stations_ << endl;

		//takes the amount of student passes sold
		std::cout << " Student Passes sold : ";
		std::cin >> student_passes_sold;

		//takes the amount of adult passes sold
		std::cout << " Adult   Passes sold : ";
		std::cin >> adult_passes_sold;

		student_passes_sold *= -1;
		adult_passes_sold *= -1;

		s.set(stations_, student_passes_sold, adult_passes_sold);
	}

	cout << endl;
}

void w2::Stations::restock() const {

	/*
	* Takes input from the user
	*/
	Station s;

	cout << "Passes Added : " << endl;
	cout << "--------------" << endl;

	for (int p = 0; p < number_of_stations; p++) {
		int student_passes_added, adult_passes_added;

		//accepts the number of passes added and updates the data for each station
		cout << stations_ << endl;

		//takes the amount of student passes added
		cout << " Student Passes added : ";
		cin >> student_passes_added;

		//takes the amount of adult passes added
		cout << " Adult   Passes added : ";
		cin >> adult_passes_added;

		/*
		* Updates the file with the new values
		*/
		s.set(stations_, student_passes_added, adult_passes_added);
	}

	cout << endl;
}

void w2::Stations::report() const {
	/*
	*outputs the values of passes for each station
	*/
	cout << setw(32) << "Passes in Stock : Student Adult" << endl;
	
	cout << ' ';
	for (int i = 0; i < 31; i++) {
		cout << '-';
	}
	cout << endl;

	for (int o = 0; o < number_of_stations; o++) {
		cout << left << setw(19) << stations_ << setfill(' ')
			<< right << setw(7) << file_student_passes << setfill(' ')
			<< right << setw(6) << file_adult_passes << setfill(' ') << endl;
	}
}
