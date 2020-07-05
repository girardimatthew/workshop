// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 5
// P. 126

// Write a program that performs as a very simple calculator. 
// Your calcula­tor should be able to handle the five basic math operations 
// - add, sub­ tract, multiply, divide, and modulus (remainder) - on two input values. 
// Your program should prompt the user to enter three arguments: 
// two double values and a character to represent an operation. 
// If the entry ar­ guments are 35.6, 24.1, and '+', the program output should be "The sum of 35.6 and 24.1 is 59.7." 
// In Chapter 6 we look at a much more sophisti­ cated simple calculator.

#include <iostream>
#include <vector>

using namespace std;

int main() {

	double val[2] = {0,0};
	string oper;


	cout << "Please, enter two values: " << endl;

	for (int i = 0; i < 2; ++i) {
		cin >> val[i];
	}

	cout << "Please, enter an operator: " << endl;
	cin >> oper;

	if (oper == "+"){
		cout << "The sum of " << val[0] << " and " << val[1] << " is " << val[0] + val[1] << endl;
	} 
	else if (oper == "-") {
		cout << "The substraction of " << val[0] << " and " << val[1] << " is " << val[0] - val[1] << endl;
	}
	else if (oper == "*") {
		cout << "The multiplication of " << val[0] << " and " << val[1] << " is " << val[0] * val[1] << endl;
	}
	else if  (oper == "/") {
		cout << "The division of " << val[0] << " and " << val[1] << " is " << val[0] / val[1] << endl;
	}
	else if (oper == "%") {
		cout << "The module of " << val[0] << " and " << val[1] << " is " << int(val[0]) % int(val[1]) << endl;
	}
	else 
		cout << "Wrong operator" << endl;


}