/*
Program Name: Assignment 1 Question 1
Developer: Seyon Umamahesan
Enviroment: Microsoft Visual C++ 2012 Express
Description:Enter a temperture then clicke enter to see what chemical corresponds with that temperature
Variables: temperature, answer
Constants: none
Functions: none
*/

#include <iostream>

using namespace std;

void inform();
void input();
void calculations(double surgery_cost, double medication_cost, double miscellaneous_cost, double daily_cost, double insurance_deductible);
void print(double total, double total_insurance, double total_insurance_medication);

int main() {

	inform();
	cout << endl;
	input();

	system("pause");
	return 0;
}

void inform() {
	cout << "This program takes the costs from the user and computes  the  following  for insurance  purposes:  total  cost,  total  cost  less  insurance  deductible,  total  cost  less  cost  of medication and deductible." << endl;
}

void input() {
	int days_hospitalized;
	double surgery_cost;
	double medication_cost;
	double miscellaneous_cost;
	double daily_cost;
	double insurance_deductible;

	cout << "Enter the amount of days hospitalized: ";
	cin >> days_hospitalized;

	cout << "Enter the surgery cost: $";
	cin >> surgery_cost;

	cout << "Enter the medication cost: $";
	cin >> medication_cost;

	cout << "Enter the miscellaneous cost: $";
	cin >> miscellaneous_cost;

	cout << "Enter the daily cost: $";
	cin >> daily_cost;

	cout << "Enter the amount deductible from insurance: $";
	cin >> insurance_deductible;

	calculations(surgery_cost, medication_cost, miscellaneous_cost, (daily_cost * days_hospitalized), insurance_deductible);
}

void calculations(double surgery_cost, double medication_cost, double miscellaneous_cost, double daily_cost, double insurance_deductible) {
	double total;
	double total_insurance;
	double total_insurance_medication;

	total = surgery_cost + medication_cost + miscellaneous_cost + daily_cost;
	total_insurance = total - insurance_deductible;
	total_insurance_medication = total_insurance - medication_cost;

	print(total, total_insurance, total_insurance_medication);
}

void print(double total, double total_insurance, double total_insurance_medication) {
	cout << endl;
	cout << "Total before deduction: $" << total << endl;
	cout << "Total after insurance deduction: $" << total_insurance << endl;
	cout << "Total after insurance and medication deduction: $" << total_insurance_medication << endl;
}