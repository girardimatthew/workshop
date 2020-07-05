// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.3.2
// Try this
// P. 137
// *********************************************************************************
// Compile-time errors
// Try to compile some wrong examples and see how the compiler responds.
// *********************************************************************************

#include <iostream> 

using namespace std;

int area(int x, int y) {
	return x*y;
}

int main() {
	cout << "area: " << area(7,2) << endl;
	cout << "area: " << area(10,-7) << endl;
	cout << "area: " << area(10.7,9.3) << endl;
	cout << "area: " << area(100, 9999) << endl;
	char x6 = area(100, 9999);
	cout << "area: " << x6 << endl;
}