// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03 
// 3.9.2 - Unsafe covertions

#include <iostream>

using namespace std;

int main() {
	int a = 20000;
	char c = a;		// try to squeeze a large int into a small char;
	int b = c;

	cout << " -------------- Unsafe conversions -------------------- " << endl;
	cout << " unsafe: a value can be implicitly turned into a value of another type" << endl
		 << " that does not equal the original value." << endl;
	cout << " ---------------------------------------------------- " << endl; 

	cout << "int a == " << a << endl;
	cout << "char c == " << c << endl;
	cout << "int b == " << b << endl;

	if (a!=b)
		cout << "oops!: " << a << "!=" << b << endl;
	else
		cout << "Wow! We have large characters\n";

	cout << "Such conversions are also called \"narrowing\" conversions\n"
		 << "because they put a value into an object that may be too small\n"
		 << "to hold it.\n";

	cout << " ---------------------------------------------------- " << endl; 
	cout << " Another example\n";
	cout << " Please, enter a floating-point value: \n";

	double d = 0;
	while (cin>>d) {	//repeat the statement below
						//as long as we type numbers
		int i = d;		//try to squeeze a double into an int
		char c = i;		//try to squeeze an int into a char
		int i2 = c;		//get the integer value of the character
		cout << "d==" << d << endl		//the original value
			 << "i==" << i << endl		//converted to int
			 << "i2==" << i2 << endl	//int value of char
			 << "char(" << c << ")\n";	//the char

	cout << " ---------------------------------------------------- " << endl; 
	cout << " These conversions are accepted even though thery are unsafe: " << endl;
	cout << "double to int" << endl
		 << "double to char" << endl
		 << "double to bool" << endl
		 << "int to char" << endl
		 << "int to bool" << endl
		 << "char to bool" << endl;
	}
}