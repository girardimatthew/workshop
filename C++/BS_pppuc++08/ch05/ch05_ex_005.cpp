// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 005
// *********************************************************************************
// Absolute zero is the lowest temperature that can be reached; it is -273.15° C,
// or 0K. Ex 002 will produce erroneous results when given a temperature below this.
// Place a check inside ctok() funtion that will produce an error if a temperature is 
// given below -273.15° C.
// Add to the program so that it can also convert from Kelvin to Celsius.
// *********************************************************************************

#include <cstdlib>
#include <iostream>
#include "../std_lib_facilities_v2.h"

using namespace std;

double ktoc(double kelv) {
	// convert Kelvin to Celsius
	const double abszero = 0.0;						// absolute zero in Celsius
	const double kk = 273.15;						// constant
	if (kelv<abszero) {
		error("Temperature below absolute zero!");
	}
	double cels = kelv - kk;
	return cels;
}

double ctok(double cels) {
	// convert Celsius to Kelvin
	const double abszero = -273.15;						// absolute zero in Celsius
	const double kk = 273.15;							// constant
	if (cels<abszero) {
		error("Temperature below absolute zero!");
	}
	double kelv = cels + kk;
	return kelv;
}

int main() {
	try {
		double t_conv=0.0;
		double temp=0.0;
		char unit = ' ';
		char unit_conv = ' ';

		cout << "Enter temperature to be converted and unit (C or K)\n";
		cout << "For instance: '0 k' or '0 c'\n";
		cin >> temp >> unit;
		if (unit=='c' || unit=='C') {
			t_conv = ctok(temp);
			cout << "Celsius" << "\t\t" << "Kelvin" << endl;
		}	
		else if (unit=='k' || unit=='K') {
			t_conv = ktoc(temp);
			cout << "Kelvin" << "\t\t" << "Celsius" << endl;
		}
		else {
			error("Bad input!");
		}
		cout << temp << "\t\t" << t_conv << endl;
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