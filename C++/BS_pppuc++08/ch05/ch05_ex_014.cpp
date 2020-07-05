// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 014
// *********************************************************************************
// Read (day-of-the-week, value) pairs from standard input. For example:
// 	Tuesday 23 Friday 56 Tuesday -3 Thurday 99
// Collect all the values for each day of the week in a vector<int>. Write out
// the values of the seven day-of-the-week vectors. Print out the sum of the values
// in each vector. Ignore illegal days of the week, such as Funday, but accept common
// synonyms such as Mon and monday. Write out the number of rejected values.
// *********************************************************************************

#include <cstdlib>
#include <iostream>		// for cout
#include <vector>		// for vectors
#include <exception>
#include <string>		// for string
#include <stdexcept>	// for exception, runtime_error, out_of_range

using namespace std;

vector<int> mondays;
vector<int> tuesdays;
vector<int> wednesdays;
vector<int> thursdays;
vector<int> fridays;
vector<int> saturdays;
vector<int> sundays;
vector<int> sum (7,0);
int rejected = 0;

int input_handler(string day, int value) {
	int c = 0;
	if ((day=="Monday" || day=="monday" || day=="Mon" || day=="mon")) {
		mondays.push_back(value);
	}
	else if ((day=="Tuesday" || day=="tuesday" || day=="Tue" || day=="tue")) {
		tuesdays.push_back(value);
	}
	else if ((day=="Wednesday" || day=="wednesday" || day=="Wed" || day=="wed")) {
		wednesdays.push_back(value);
	}
	else if ((day=="Thurday" || day=="thursday" || day=="Thu" || day=="thu")) {
		thursdays.push_back(value);
	}
	else if ((day=="Friday" || day=="friday" || day=="Fri" || day=="fri")) {
		fridays.push_back(value);
	}
	else if ((day=="Saturday" || day=="saturday" || day=="Sat" || day=="sat")) {
		saturdays.push_back(value);
	}
	else if ((day=="Sunday" || day=="sunday" || day=="Sun" || day=="sun")) {
		sundays.push_back(value);
	}
	else if (day=="p" && value==1){
		c=-1;
	}
	else if (day=="q" && value==0) {
		c=-2;
	}
	else {
		cout << "Bad input!\n";
		++rejected;
	}
	return c;
}

void print_day(string day, vector<int> v) {
	int sum = 0;
	cout << day << endl;
	cout << " - values: ";
	for (int i=0; i<v.size(); ++i) {
		cout << v[i] << " ";
		sum+=v[i];

	}
	cout << "\n - sum: " << sum << endl; 
}

void print_results() {
	cout << "---------------------------- RESULTS -----------------------------\n";
	print_day("Monday", mondays);
	print_day("Tuesday", tuesdays);
	print_day("Wednesday", wednesdays);
	print_day("Thurday", thursdays);
	print_day("Friday", fridays);
	print_day("Saturday", saturdays);
	print_day("Sunday", sundays);
	cout << "Rejected input: " << rejected << endl;
}

int main() {
	try {
		string day = " ";
		int value = 0;
		int input;
		bool state = true;
		bool checkday = false;
		bool checkvalue = false;

		cout << "Please enter a day of the week followed by a value: \n";
		cout << "To terminate enter 'q 0'.\n";
		cout << "To print the result enter 'p 1'.\n";
		while(cin>>day>>value) {
			input=input_handler(day,value);
			if (input==-1) {
				print_results();
			}
			else if (input==-2) {
				print_results();
				cout << "Quitting the program...\n";
				exit(1);
			}
		}
		cout << "Bad input. Unknown value!\n";
		cout << "Quitting the program...\n";
	}
	catch (runtime_error &e) {
		cerr << "runtime error! " << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown exception!\n";
	}
}