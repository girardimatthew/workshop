// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.09
// CH 05 5.10
// *********************************************************************************
// Debugging
// pre- and post-conditions
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "../std_lib_facilities_v2.h"

using namespace std;

int my_complicated_function(int a, int b, int c) {
	// the arguments are positive and a<b<c
	if (!(0<a && a<b && b<c)) {
		error("Bad arguments for mcf");
	}
	else {
		cout << a << ", " << b << ", " << c << endl;
	}
}

int area(int length, int width) {
	// calculate area of a rectangle;
	// pre-conditions: length and width are positive
	// post-condition: returns a positive value that is the area
	if (length<=0 || width<=0) {
		// cerr << "error: pre-condition!\n";
		// return -1;
		error("area() pre-condition");
	}
	int a = length*width;
	cout << "Area: " << a << endl;
	if (a<=0) {
		// cerr << "error: post-condition!\n";
		// return -1;
		error("area() post-condition");
	}
	return a;
}

int main() {
	int a=2, b=3, c=4;
	int length, width;

	my_complicated_function(a,b,c);

	// while (cin>>length>>width) {
	// 	cout << "Area: " << area(length,width) << endl;
	// }

	try {
		cin >> length >> width;
		int test = area(length,width);
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Oops: Unknown exception!\n";
		return 2;
	}
	
}