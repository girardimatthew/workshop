// *********************************************************************************
// Greatest common divisor with recursion
// *********************************************************************************

#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int a, b;
	cout << "Greatest common divisor" << endl;
	cout << "Please enter two numbers: ";
	cin >> a >> b;
	cout << gcd(a,b) << endl;
}