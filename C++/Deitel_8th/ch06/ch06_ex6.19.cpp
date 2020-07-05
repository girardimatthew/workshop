// *******************************************************
// Deitel: C++ How to Program
// ch 06 ex 6.17
// Define a function Hypotenuse that calculates the hypotenuse
// of a right triangle when the other two sides are given.
// The function should take two double arguments and return
// the hypotenuse as a double.
// *******************************************************
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double hypotenuse(double s1, double s2) {
	return sqrt( pow(s1,2) + pow(s2,2) );
}

int main() {
	cout << setw(10) << "Triangle" << setw(10) << "Side1" << setw(10) << "Side2" << setw(10) << "Result" << endl;
	cout << setw(7) << "1" << setw(12) << "3.0" << setw(10) << "4.0" << setw(8) << hypotenuse(3.0,4.0) << endl;
	cout << setw(7) << "2" << setw(12) << "5.0" << setw(10) << "12.0" << setw(8) << hypotenuse(5.0,12.0) << endl;
	cout << setw(7) << "3" << setw(12) << "8.0" << setw(10) << "15.0" << setw(8) << hypotenuse(8.0,15.0) << endl;
}