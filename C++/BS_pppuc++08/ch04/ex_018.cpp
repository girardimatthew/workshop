// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 18
// P. 128
// *********************************************************************************
// Write a program that solve the quadratic equation:
// ax2+bx+c=0
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h> 

using namespace std;

int main() {
	double a, b, c, x, discrim;

	cout << "Write a program that solve the quadratic equation ax^2+bx+c=0 \n";
	cout << "------------------------------------------------------------- \n";
	cout << "Please enter (only) three values for a, b and c.\n";
	cin>>a>>b>>c;
	if (a==0) {
		cout << "a=" << a << ", the equation is not quadratic.\n";
		exit(0);
	}
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	// finding the solutions...
	discrim=pow(b,2)-(4*a*c);
	if (discrim<0) {
		x=-b/(2*a)==0 ? 0 : (-b/(2*a));
		cout << "------------------------------------------------------------- \n";
		cout << "SOLUTIONS:\n";
		cout << "The discriminant is equals to " << discrim << endl;
		cout << "x1 = " << x << " + " << sqrt(-discrim)/(2*a) << "i" << endl;
		cout << "x2 = " << x << " - " << sqrt(-discrim)/(2*a) << "i" << endl;
	}
	else if (discrim==0) {
		cout << "------------------------------------------------------------- \n";
		cout << "SOLUTIONS:\n";
		cout << "The discriminant is equals to " << discrim << endl;
		cout << "x1 = x2 =" << (-b)/(2*a) << endl;
	}
	else {
		cout << "------------------------------------------------------------- \n";
		cout << "SOLUTIONS:\n";
		cout << "The discriminant is equals to " << discrim << endl;
		cout << "x1 = " << (-b+sqrt(discrim))/(2*a) << endl;
		cout << "x2 = " << (-b-sqrt(discrim))/(2*a) << endl;
	}
}