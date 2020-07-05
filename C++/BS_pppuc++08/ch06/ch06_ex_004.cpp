// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 06 Ex 04
// *********************************************************************************
// Define a class Name_value that holds a string and a value. Give it a constructor 
// (a bit like Token). Rework exercise 19 in Chapter 4 to use a vector<Name_value>
// instead of two vectors.
// *********************************************************************************

#include <vector>
#include <string>
// #include "../std_lib_facilities_v2.h"
#include "../lib.h"

using namespace std;

const string quit = "NoMore";
const string print = "p";
const string prompt = "> ";

//------------------------------------------------------------------------------
// Define a class Name_value
class Name_value {
public:
    string name;        					// what kind of token
    double value;     						// for numbers: a value   
    Name_value(string ss, double val)     	// Constructor: make a Name_value from a string and a double
        :name(ss), value(val) { }
};

//------------------------------------------------------------------------------
vector<Name_value> v;

//------------------------------------------------------------------------------
void print_vector() {
	for (int i=0; i<v.size(); ++i) {
		// cout << "\t - (" << v[i].name << ", " << v[i].value << ")\n";
		cout << "\t" << i+1 << " (" << v[i].name << ", " << v[i].value << ")\n";
	}
}

//------------------------------------------------------------------------------
int main() {
	try {

		string inname;
		double inscore;
		bool valid = true;

		cout << "Please enter a name-and-value pairs such as 'John 17'.\n";
		cout << "Enter " << quit << " to quit.\n";
		cout << "Enter " << print << " to print.\n";

		while (cin>>inname && !(inname==quit)) {
			if (inname==print) {
				print_vector();
			}
			else {
				cin >> inscore;
				for (int i=0; i<v.size(); ++i) {
					if (inname==v[i].name) {
						error ("Input name already inserted.\n");
					}
				}
				v.push_back(Name_value(inname,inscore));
			}
		}

		print_vector();
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		keep_window_open("~1"); 
		return 1;
	}
	catch (...) {
		cerr << "Oops: unkown exception!\n";
		keep_window_open("~2");
		return 2;
	}
}