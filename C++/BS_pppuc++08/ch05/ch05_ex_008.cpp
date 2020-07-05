// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 008
// *********************************************************************************
// Write a program that read a series of numbers and stores them in a vector<int>.
// After the user inputs all the numbers he or she wishes to, ask how many of the 
// numbers the user wants to sum. For an answer N, print the sum of the first N 
// elements of the vector. For example:
// "Please enter some numbers (press "|" at prompt to stop):"
// 12 23 13 24 15
// "Please enter how many of the numbers you wish to sum, starting from the first:"
// 3
// "The sum of the first 3 numbers: 12, 23 and 13 is 48."
// Hanlde all inputs. For example, make sure to give an error message if the user
// asks for a sum of more numbers than there are in the vector.
// *********************************************************************************


#include <cstdlib>
#include <iostream>
//#include "../std_lib_facilities_v2.h"
#include <vector>

using namespace std;

int main() {
	try {
		bool state = true;
		vector<double> numbs;
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

		cout << "The sum of the first " << n << " numbers ( ";
		for (int i=0; i<n; ++i) {
			cout << numbs[i] << " ";
		}
		cout << ") is " << sum << endl;
	}
	catch (runtime_error e) {
		cerr << "runtime error.\n";
	}

}