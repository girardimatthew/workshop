// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 007
// *********************************************************************************
// Quadratic equations are of the form:
// ax^2 + bx + c = 0
// to solve those, one uses the quadratic formula.
// x = (-b +- sqrt(b^2 - 4ac)) / 2a
// There is a probelm though: if b^2 - 4ac is less than zero, then it will fail.
// Write a program that can calculate x for a quadratic equation.
// Create a function that prints out the roots of a quadratic equation, give a,b,c,
// and have it throw an exception if b^2 - 4ac is less than zero. Have the main function
// of the program call the function, and catch the exception if there is an error. 
// When the program detects an equation with no real roots, have it print out a message.
// How do you know that your results are plausible?
// Can you check that they are correct?
// *********************************************************************************

#include <cstdlib>
#include <iostream>
#include "../std_lib_facilities_v2.h"
#include <math.h>

using namespace std;

void solve() {
	cout << "Please enter three floating-point numbers (a b c) to be used as coefficients in ax^2+bx+c=0.\n";
	double a, b, c;

	while (cin>>a>>b>>c) {
		if (a==0) {
			if (b==0) {
				cout << "no root (since x is not used)\n";
			}
			else {
				cout << "x == " << -c/b << endl;
			}
		}
		else if (b==0) {
			double ca = -c/a;
			if (ca==0) {
				cout << "x == 0\n"; 
			}
			else if (ca<0) {
				cout << "no real roots\n";
			}
			else {
				cout << "two real roots: " << sqrt(ca) <<  " and " << -sqrt(ca) << endl;
			}
		}
		else {
			double sq = b*b-4*a*c;
			if (sq==0) {
				cout << "one real root: " << -b/(2*a) << '\n';
			}
			else if (sq<0) {
				cout << "no real roots\n";
			}
			else {
				cout << "two real roots: " << setprecision(12) << (-b+sqrt(sq))/(2*a) << " and " << (-b-sqrt(sq))/(2*a) << '\n';
			}
		}
		cout << "please try again (enter a b c): ";
	}
}

int main() {
	cout << "------------------------------------------------------------- \n";
	cout << "Write a program that solve the quadratic equation ax^2+bx+c=0 \n";
	cout << "------------------------------------------------------------- \n";

	try {
		solve();
	}
	catch (runtime_error e) {
		cout << e.what() << '\n';
		keep_window_open("~");
	}




}