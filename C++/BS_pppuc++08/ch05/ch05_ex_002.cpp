// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 Exercises
// Ex 002
// *********************************************************************************

#include <cstdlib>
#include <iostream>

using namespace std;

double ctok(double c) {
	const double kk = 273.15;
	double kel = c + kk;
	return kel;
}
int main() {
	cout << "--------------- Celsius to Kelvin -----------------\n";
	double c=0;
	cin >> c;
	double k = ctok(c);
	cout << "Celsius" << "\t\t" << "Kelvin" << endl;
	cout << c << "\t\t" << k << endl;
}