/*
#include <iostream>

using namespace std;

void explain_program(void);
void get_values(float *r, float *v);
float do_calculations(float resistance, float voltage, float *p);
void display_answer(float current, float power);

int main()
{
	float resistor;
	float volts;
	float current;
	float power_;

	explain_program();
	get_values(&resistor, &volts);
	current = do_calculations(resistor, volts, &power_);
	display_answer(current, power_);

	system("pause");
	return 0;
}

void explain_program()
{
	cout << "This program calculates the value of the current\n";
	cout << "in amps. You need to enter the value of the resistor\n";
	cout << "and the voltage in volts.\n";
}

void get_values(float *r, float *v)
{
	float resistance;
	float voltage;

	cout << "\n\n";
	cout << "Input the resistance in ohms = ";
	cin >> resistance;
	cout << "Input the voltage in volts = ";
	cin >> voltage;

	*r = resistance;
	*v = voltage;
}

float do_calculations(float resistance, float voltage, float *p)
{
	float current;
	float power;

	power = (voltage * voltage) / resistance;
	*p = power;
	current = voltage / resistance;

	return current;
}

void display_answer(float current, float power)
{
	cout << endl;
	cout << "The value of the current is " << current << " amps.\n";
	cout << "The value of the power is " << power << " amps. \n";
}
*/

/*
Program Name: Assignment 2 Question 2
Developer: Seyon Umamahesan
Enviroment: Microsoft Visual C++ 2012 Express
Description:This program takes the costs from the user and computes  the  following  for insurance  purposes:  total  cost,  total  cost  less  insurance  deductible,  total  cost  less  cost  of medication and deductible.
Variables: Listed through ou the code
Constants: none
Functions: void print, void calculations, void input(), void inform()
*/

//#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void inform();
void input(int *d_hosp, double *s_cost, double *m_cost, double *misc_cost, double *d_cost, double *i_deductible);
void calculations(double surgery_cost, double medication_cost, double miscellaneous_cost, double daily_cost, double insurance_deductible, double *t, double *t_i, double *t_i_m);
void print(double total, double total_insurance, double total_insurance_medication);


int main(void)
{

	int daysHospitalized_;
	double surgeryCost_, medicationCost_, miscellaneousCost_, dailyCost_, insuranceDeductible_;
	double total_, totalInsurance_, totalInsuranceMedication_;

	inform();
	input(&daysHospitalized_, &surgeryCost_, &medicationCost_, &miscellaneousCost_, &dailyCost_, &insuranceDeductible_);
	calculations(surgeryCost_, medicationCost_, miscellaneousCost_, (dailyCost_ * daysHospitalized_), insuranceDeductible_, &total_, &totalInsurance_, &totalInsuranceMedication_);
	print(total_, totalInsurance_, totalInsuranceMedication_);

	system("pause");
	return 0;
}

void inform() {
	cout << "This program takes the costs from the user and computes  the  following  for insurance  purposes:  total  cost,  total  cost  less  insurance  deductible,  total  cost  less  cost  of medication and deductible." << endl;
	cout << endl;
}

void input(int *d_hosp, double *s_cost, double *m_cost, double *misc_cost, double *d_cost, double *i_deductible) {
	int days_hospitalized;
	double surgery_cost;
	double medication_cost;
	double miscellaneous_cost;
	double daily_cost;
	double insurance_deductible;

	cout << "Enter the amount of days hospitalized: ";
	cin >> days_hospitalized;
	*d_hosp = days_hospitalized;

	cout << "Enter the surgery cost: $";
	cin >> surgery_cost;
	*s_cost = surgery_cost;

	cout << "Enter the medication cost: $";
	cin >> medication_cost;
	*m_cost = medication_cost;

	cout << "Enter the miscellaneous cost: $";
	cin >> miscellaneous_cost;
	*misc_cost = miscellaneous_cost;

	cout << "Enter the daily cost: $";
	cin >> daily_cost;
	*d_cost = daily_cost;

	cout << "Enter the amount deductible from insurance: $";
	cin >> insurance_deductible;
	*i_deductible;
}

void calculations(double surgery_cost, double medication_cost, double miscellaneous_cost, double daily_cost, double insurance_deductible, double *t, double *t_i, double *t_i_m) {
	double total;
	double total_insurance;
	double total_insurance_medication;

	total = surgery_cost + medication_cost + miscellaneous_cost + daily_cost;
	*t = total;

	total_insurance = total - insurance_deductible;
	*t_i = total_insurance;

	total_insurance_medication = total_insurance - medication_cost;
	*t_i_m = total_insurance_medication;
}

void print(double total, double total_insurance, double total_insurance_medication) {
	cout << endl;
	cout << "Total before deduction: $" << total << endl;
	cout << "Total after insurance deduction: $" << total_insurance << endl;
	cout << "Total after insurance and medication deduction: $" << total_insurance_medication << endl;
}
