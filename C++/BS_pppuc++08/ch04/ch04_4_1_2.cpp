#include <iostream>

using namespace std;

int main () {

	cout << "---------------------------------------------------" << endl,
	cout << "Program that converts cm into inch and viceversa" << endl;
	const double cm_per_inch = 2.54;
	double length = 1;
	char unit = 'a';
	cout << "Please enter a length followed by a unit (c or i): \n";
	cin >> length >> unit;

	switch (unit) {
		case 'i':
			cout << length << "in == " << cm_per_inch*length << "cm\n";
			break;
		case 'c':
			cout << length << "cm == " << length/cm_per_inch << "in\n";
			break;
		default:
			cout << "Bad input. Unkown unit " << unit << ".\n" ;
			break;
	}

	cout << "---------------------------------------------------" << endl,
	cout << "same action for a set of values in a switch" << endl;

	cout << "Please enter a digit\n";
	char a;
	cin >> a;

	switch (a){
		case '0': case '2': case '4': case '6': case '8':
			cout << a << " is even\n";
			break;
		case '1': case '3': case '5': case '7': case '9':
			cout << a << " is odd\n";
			break;
		default:
			cout << a << " is not a digit\n";
			break;
	}
}