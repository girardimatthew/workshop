// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 6.3.1
// First attempt
// *********************************************************************************
#include <iostream>
#include "../std_lib_facilities_v2.h"

int main() {
	cout << "Please enter expression (we can handle +, -, *, and /): ";
	int lval = 0;
	int rval;
	char op;
	int res;
	cin>>lval;		// read leftmost operand
	if (!cin) error("no first operand");
	while (cin>>op) {	// read operator and right-hand operand repeatedly
		cin>>rval;
		if (!cin) error("no second operand");
		switch (op) {
			case '+':
				lval+=rval;		// add: lval = lval + rval
				break;
			case '-':
				lval+=rval;	// substract: lval = lval - rval
				break;
			case '*':
				lval*=rval;
				break;
			case '/':
				lval/=rval;
				break;
			default: 
				cout << "Result: " << lval << '\n';
				keep_window_open();
				return 0;
		}
	}
	error("bad expression");
}