#include <iostream>

using namespace std;

int main() {
	double dc = 30;
	double df = 0;

	cout << "INTEGER: degree Celsius to degree Fahrenheit" << endl;
	cout << "f = 9/5 * c + 32: " << 9/5 * dc + 32 << " - wrong!" << endl;
	cout << "FLOATING-POINT: degree Celsius to degree Fahrenheit" << endl;
	cout << "f = 9/5 * c + 32: " << 9.0/5.0 * dc + 32 << endl;
}