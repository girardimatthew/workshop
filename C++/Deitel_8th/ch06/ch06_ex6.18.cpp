// *******************************************************
// Deitel: C++ How to Program
// ch 06 ex 6.17
// Write a function integerPower(base, exponent) that returns
// the value of base.^exponent
// *******************************************************
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int integerPower(int b, int e) {
	if ( e == 0 ){
		return b = 1;
	}
	if ( e == 1 ){
		return b;
	}
	return b * integerPower(b, e-1);
}

int main() {

	cout << setw(5) << "Base" << setw(5) << "Exp" << setw(9) << "Result" << endl;
	int exp = 2;

	for (int i = 0; i < 10; ++i) {
		cout << setw(4) << i << setw(5) << exp << setw(7) << integerPower(i, exp) << endl;
	}

	cout << setw(5) << "Base" << setw(5) << "Exp" << setw(9) << "Result" << endl;
	exp = 3;
	for (int i = 0; i < 10; ++i) {
		cout << setw(4) << i << setw(5) << exp << setw(7) << integerPower(i, exp) << endl;
	}
}