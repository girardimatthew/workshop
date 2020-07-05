// *********************************************************************************
// Programming in C++ 
// Exercise 002
// Matteo Girardi
// *********************************************************************************
// Prime Factorization
// Write a program that computes the prime factorization of a given positive
// integer. For instance, the factorization of 60 is 2 * 2 * 3 * 5.
// Hints:
// - In C++, the modulus function % gives the remainder of integer division, 
// i.e., x is divisible by y if and only if x%y == 0.
// - Given the number n to factorize, iterate through all the 
// numbers i = 2, 3, 4, 5, . . . and check
// whether i divides n. If so, print out “i *” and continue to check the factorization of n/i.
// Stop when n cannot be further factorised.
// 
// In order to check with CodeJudge, please ensure that (i) the factors are printed in ascending
// order, (ii) between two factors print a space, an asterisk (∗), and another space, 
// (iii) and at the end there is a newline (see example above).
// *********************************************************************************

#include <iostream>

using namespace std;

int main() {
	int in = 0, i = 2;
	cin >> in;

	while (in>1) {
		if (in==i) {
			cout << i << endl;
			break;
		}
		else if (in%i==0) {
			in/=i;
			cout << i << " * ";
		}
		else 
			++i;
	}

	return 0;
}