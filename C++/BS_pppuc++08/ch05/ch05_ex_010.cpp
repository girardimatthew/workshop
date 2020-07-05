// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 010
// *********************************************************************************
// Modify the program from exercise 8 to use double instead of int. Also, make
// a vector of double contraining the N-1 differences between adjacent values and
// write out that vector of differences.
// *********************************************************************************


#include <cstdlib>
#include <iostream>
//#include "../std_lib_facilities_v2.h"
#include <vector>

using namespace std;

int main() {
	try {
		vector<double> numbs;
		vector<double> diff;
		double temp;
		int n=-1;
		double sum = 0.0;

		cout << "Please enter how many of the numbers you wish to sum, starting from the first: ";
		cin>>n;
		if (n<1) {
			cerr << "the number of elements must be a positive integer!\n";
			exit(1);
		}

		cout << "Please enter some numbers (press \"|\" at prompt to stop): ";

		while (cin>>temp) {
			numbs.push_back(temp);
		}

		if (n>numbs.size()) {
			cerr << "Error: " << n << " is bigger than the number of values to be summed.\n";
			cerr << "It should not be bigger than " << numbs.size() << endl;
			exit(1);
		}

		for (int i=0; i<n; ++i) {
			sum+=numbs[i];
		}

		for (int i=0; i<numbs.size()-1; ++i) {
			diff.push_back(numbs[i] - numbs[i+1]);
		}

		cout << "The sum of the first " << n << " numbers ( ";
		for (int i=0; i<n; ++i) {
			cout << numbs[i] << " ";
		}
		cout << ") is " << sum << endl;

		cout << "vector of differences is: " << endl;
		for (int i=0; i<diff.size(); ++i) {
			cout << "diff[" << i << "] == " << diff[i] << endl;
		}
	}
	catch (runtime_error e) {
		cerr << "runtime error.\n";
	}

}