// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 011
// *********************************************************************************
// Write a program that writes out the first so many values of the Fibonacci series
// that is, the series that start with 1 1 2 3 5 8 13 21 34.
// The next number of the series is the sum of the two previous ones.
// Find the largest Fibonacci number that fits in an int.
// *********************************************************************************


#include <cstdlib>
#include <iostream>
//#include "../std_lib_facilities_v2.h"
#include <vector>

using namespace std;

int main() {
	try {
		int j = 0;
		int f = 1;
		int n = 47;
		vector<int> fibo;

		// cout << "How many numbers of the Fibonacci series would you like to have?\n";
		// cout << "Please enter a number: ";
		// cin >> n;

		while(j<n) {
			if (j<2) {
				fibo.push_back(f);
			}
			else {
				fibo.push_back(fibo[j-1]+fibo[j-2]);
			}
			++j;
		}

		cout << "-------------- Fibonacci sequence -------------- \n";
		for (int i=0; i<fibo.size(); ++i) {
			cout << " # " << fibo[i] << " " << endl;
		}
		cout << "The largest Fibonacci number that fits in an int is: " << fibo[45] << endl;
	}
	catch (runtime_error& e) {
		cerr << "runtime error.\n";
	}
	catch (...) {
		cerr << "Unknown exception!\n";
	}

}