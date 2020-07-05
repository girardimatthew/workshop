// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.6.4
// *********************************************************************************
// Narrowing errors
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../std_lib_facilities_v2.h"

using namespace std;

int main() {
	int x = 2.9;
	char c = 1066;
	cout << x << ", " << c << endl;
	int x1 = narrow_cast<int>(2.9);		// throws
	int x2 = narrow_cast<int>(2.0);		// OK
	char c1 = narrow_cast<char>(1066);	// thows
	char c2 = narrow_cast<char>(86);	// OK
}