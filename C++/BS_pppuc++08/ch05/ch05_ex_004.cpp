// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 004
// *********************************************************************************
// Absolute zero is the lowest temperature that can be reached; it is -273.15° C,
// or 0K. Ex 002 will produce erroneous results when given a temperature below this.
// Place a check inside ctok() funtion that will produce an error if a temperature is 
// given below -273.15° C.
// *********************************************************************************

#include <cstdlib>
#include <iostream>
#include "../std_lib_facilities_v2.h"

using namespace std;

double ctok(double c) {
	// convert Celsius to Kelvin
	const double abszero = -273.15;						// absolute zero in Celsius
	if (c<abszero) {
		error("Temperature below absolute zero!");
	}
	const double kk = 273.15;
	double kel = c + kk;
	return kel;
}
int main() {
	try {
		cout << "--------------- Celsius to Kelvin -----------------\n";
		double c=0;
		cin >> c;
		if (!cin) {
			error("Bad input!");
		}
		else {
			double k = ctok(c);
			cout << "Celsius" << "\t\t" << "Kelvin" << endl;
			cout << c << "\t\t" << k << endl;
		}
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