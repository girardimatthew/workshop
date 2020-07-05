// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.8.0
// *********************************************************************************
// Estimation
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "../std_lib_facilities_v2.h"

using namespace std;

double hexagon_area(double side) {
	const double form = (3.0*sqrt(3.0))/2.0;
	return form*pow(side,2);
}

int main() {

	double a = 0;

	cout << "Calculate the area of hexagon.\n";
	cout << "Please enter a value for the hexagon side.\n";
	
	while (cin>>a) {
		if (!cin) {
			cerr << "Bad input!\n";
			//error("Bad input!");
		}
		else {
			cout << "Area: " << hexagon_area(a) << endl;
		}
	}
}