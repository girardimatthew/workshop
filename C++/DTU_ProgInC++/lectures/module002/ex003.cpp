// *********************************************************************************
// Programming in C++ 
// Exercise 003
// Matteo Girardi
// *********************************************************************************
// Compute an approximation of pi using Leibniz’ formula:
// To that end write a function with head double pi(int n) that computes the first n terms
// of the infinite summation (and then multiplies by 4). For instance for n = 1 we get the bad
// approximation 4, and with increasing n, the approximation gets better.
// Hint: the expression (−1)^i.
// could be computed using the function pow, but this is rather
// inefficient (as this causes log2i multiplications for every summand). 
// Can you find a better way, avoiding pow?
// *********************************************************************************

#include <iostream>

using namespace std;

const double num = 1.0;

// recursive
double piR(int n) {
	if (n<0) return 0;
	if (n==0) return 1;
	double op = num/(2.0*n+1);
	op = n%2==0 ? op : -op;
	return op+piR(n-1);
}

// for-loop
double pi(int n) {
	if (n<0) return 0;
	double op;
	double res=1.0;
	for (int i=1; i<=n; ++i) {
		op = num/(2.0*i+1);
		op = i%2==0 ? op : -op;
		res+=op;
	}
	return res;
}

int main() {
	int in = 0;
	cin >> in;
	cout << 4*pi(in-1) << ", " << 4*piR(in-1) << endl;
}

