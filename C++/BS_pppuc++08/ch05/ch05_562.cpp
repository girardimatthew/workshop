// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.6.2
// *********************************************************************************
// Range errors
// *********************************************************************************

#include <iostream>
#include <vector>

using namespace std;

class out_of_range_error {};

int main() {
	try {
		vector<int> v;
		for (int i=0; i<5; ++i) {
			v.push_back(i);
		}
		for (int i=0; i<=v.size(); ++i) {
			cout << "v[" << i << "] == " << v[i] << endl;
		}
		cout << v[-1] << endl;
	}
	catch (out_of_range_error) {
		cerr << "Oops! Range error.\n";
		return 1;
	}
	catch (...) {
		cerr << "Exception: something went wrong.\n";
		return 2;
	}
}