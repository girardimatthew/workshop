// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03 
// 3.9.1 - Safe conversions

#include <iostream>

using namespace std;

int main() {
	char c = 'x';
	int i1 = c;
	int i2 = 'x';
	char c2 = i1;

	cout << " -------------- Safe conversions -------------------- " << endl; 
	cout << "char c = 'x'" << " - std output: " << c << endl;
	cout << "int i1 = c" << " - std output: " << i1 << endl;
	cout << "int i2 = 'x'" << " - std output: " << i2 << endl; 
	cout << "char c2 = i1" << " - std output: " << c2 << '\n';
	cout << " ---------------------------------------------------- " << endl; 
	cout << " These conversions are safe: " << endl;
	cout << "bool to char" << endl
		 << "bool to int" << endl
		 << "bool to double" << endl
		 << "char to int" << endl
		 << "char to double" << endl
		 << "int to double" << endl;
}