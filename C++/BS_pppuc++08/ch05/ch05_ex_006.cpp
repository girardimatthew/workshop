// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 006
// *********************************************************************************
// Write a program that converts from Celsius to Fahrenheit and from 
// Fahrenheit to Celsius.
// However I've extended the program to Celsius-Fahrenheit-Kelvin
// *********************************************************************************

#include <cstdlib>
#include <iostream>
#include "../std_lib_facilities_v2.h"

using namespace std;

// constants
const double abszero_cels = -273.15;				// absolute zero in Celsius
const double abszero_kelv = 0.0;					// absolute zero in Kelvin
const double abszero_fahr = -459.67;				// absolute zero in Fahrenheit

// converting functions
double ktoc(double kelv) {
	// convert Kelvin to Celsius
	if (kelv<abszero_kelv) {
		error("Temperature below absolute zero!");
	}
	double cels = kelv - 273.15;
	return cels;
}

double ktof(double kelv) {
	// convert Kelvin to Fahrenheit
	if (kelv<abszero_kelv) {
		error("Temperature below absolute zero!");
	}
	double fahr = kelv * (9.0/5.0) - 459.67;
	return fahr;
}

double ctok(double cels) {
	// convert Celsius to Kelvin
	if (cels<abszero_cels) {
		error("Temperature below absolute zero!");
	}
	double kelv = cels + 273.15;
	return kelv;
}

double ctof(double cels) {
	// convert Celsius to Fahrenheit
	if (cels<abszero_cels) {
		error("Temperature below absolute zero!");
	}
	double fahr = cels * (9.0/5.0) + 32;
	return fahr;
}

double ftoc(double fahr) {
	// convert Fahrenheit to Celsius
	if (fahr<abszero_fahr) {
		error("Temperature below absolute zero!");
	}
	double cels = (fahr - 32) * (5.0/9.0);
	return cels;

}

double ftok(double fahr) {
	// convert Fahrenheit to Kelvin
	if (fahr<abszero_fahr) {
		error("Temperature below absolute zero!");
	}
	double kelv = (fahr + 459.67) * (5.0/9.0);
	return kelv;
}


int main() {
	try {
		double temp=0.0;
		double cels=0.0, fahr=0.0, kelv=0.0;
		char unit = ' ';

		cout << "-------------------------------------------------------\n";
		cout << "Convert temperature (Celsius, Fahrenheit and Kelvin).\n";
		cout << "Enter temperature to be converted and unit (C, F or K)\n";
		cout << "For instance: '0 f' or '0 c' or '0 k'.\n";
		cout << "-------------------------------------------------------\n";

		cin >> temp >> unit;
		if (unit=='c' || unit=='C') {
			cels=temp;
			fahr=ctof(temp);
			kelv=ctok(temp);
		}	
		else if (unit=='k' || unit=='K') {
			kelv=temp;
			cels=ktoc(temp);
			fahr=ktof(temp);
		}
		else if (unit=='f' || unit=='F') {
			fahr=temp;
			cels=ftoc(temp);
			kelv=ftok(temp);
		}
		else {
			error("Bad unit input! Please use: f, c or k (uppercase or lowercase).");
		}

		cout << "CELSIUS" << "\t\t" << "FAHRENHEIT" << "\t\t" << "KELVIN" << endl;
		cout <<	cels << "\t\t" << fahr << "\t\t\t" << kelv << endl;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unkown exception!\n";
		return 2;
	}
}