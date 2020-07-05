// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 009
// *********************************************************************************
// Modify the program from exercise 6 to write out an error if the result cannot be 
// represented as an int.
// *********************************************************************************

#include <cstdlib>
#include <iostream>
#include "../std_lib_facilities_v2.h"
#include <exception>

using namespace std;

// constants
const double abszero_cels = -273.15;				// absolute zero in Celsius
const double abszero_kelv = 0.0;					// absolute zero in Kelvin
const double abszero_fahr = -459.67;				// absolute zero in Fahrenheit

// converting functions
int ctof(int cels) {
	// convert Celsius to Fahrenheit
	if (cels<abszero_cels) {
		error("Temperature below absolute zero!");
	}
	int fahr = cels * (9.0/5.0) + 32;
	double fahr_d = cels * (9.0/5.0) + 32;
	if (fahr_d != fahr_d) {
		error("Result cannot be represented as an int!");
	}
	return fahr;
}

int ftoc(int fahr) {
	// convert Fahrenheit to Celsius
	if (fahr<abszero_fahr) {
		error("Temperature below absolute zero!");
	}
	int cels = (fahr - 32) * (5.0/9.0);
	double cels_d = (fahr - 32) * (5.0/9.0);
	if (cels != cels_d) {
		error("Result cannot be represented as an int!");
	}
	return cels;
}

int main() {
	try {
		int temp=0.0;
		int cels=0.0, fahr=0.0;
		char unit = ' ';

		cout << "-------------------------------------------------------\n";
		cout << "Convert temperature (Celsius, Fahrenheit).\n";
		cout << "Enter (integer) temperature to be converted and unit (C or F)\n";
		cout << "For instance: '0 f' or '0 c'.\n";
		cout << "-------------------------------------------------------\n";

		cin >> temp >> unit;
		if (unit=='c' || unit=='C') {
			cels=temp;
			fahr=ctof(temp);
		}	
		else if (unit=='f' || unit=='F') {
			fahr=temp;
			cels=ftoc(temp);
		}
		else {
			error("Bad unit input! Please use: f or c (uppercase or lowercase).");
		}

		cout << "CELSIUS" << "\t\t" << "FAHRENHEIT" <<  endl;
		cout <<	cels << "\t\t" << fahr << endl;
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