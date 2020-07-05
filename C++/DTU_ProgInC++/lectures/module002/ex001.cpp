// *********************************************************************************
// Programming in C++ 
// Exercise 001
// Matteo Girardi
// *********************************************************************************
// Another sum Write a program that computes the sum of all even integers between 0 and n.
// For instance, for n = 6, the result is 0 + 2 + 4 + 6 = 12
// *********************************************************************************

#include <iostream>

using namespace std;

int main() {
	int n, r = 0;

	cin >> n;
	for (int i=0; i<=n; i+=2) {
		r+=i;
	}
	cout << r << endl;

	return 0;
}