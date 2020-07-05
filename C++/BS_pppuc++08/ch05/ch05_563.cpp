// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.6.3
// *********************************************************************************
// Bad input
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// *********************************************************************************
// v001
// *********************************************************************************
void error(string s1) {
	throw runtime_error(s1);
}

double some_function() {
	double d = 0;
	cin >> d;
	if(!cin) error("Couldn't read a double in 'some_function()'.\n");
	else cout << d << ", ok!\n";
}

int main() {
	double d = 0;
	cin >> d;
	if (cin) {
		cout << d << ", ok!\n";
	}
	else {
		error("Something went wrong!");
	}

	some_function();

}

// *********************************************************************************
// v002
// *********************************************************************************
// int main() {
// 	try {
// 		double d = 0;
// 		cin >> d;
// 		cout << d << endl;
// 		//return 0;
// 	}
// 	catch (runtime_error& e) {
// 		cerr << "runtime_error: " << e.what() << '\n';
// 		//keep_window_open();
// 		return 1;
// 	}
// 	catch (...) {
// 		cerr << "Oops! uknown exception!\n";
// 		return 2;
// 	}
// }