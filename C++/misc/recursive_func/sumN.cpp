// *********************************************************************************
// Write a recursive function that computes the sum of all numbers from 1 to n, 
// where n is given as parameter.
// *********************************************************************************

#include <iostream>

using namespace std;

//return the sum 1+ 2+ 3+ ...+ n
int sumN(int n) {
	if (n==0)
		return 0;
	return n+sumN(n-1);
}

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << sumN(n) << endl;
}