// program that converts yen, euros
// and pound into dollars.
#include <iostream>

using namespace std;

int main () {
	const double ytod = 0.00992;
	const double ptod = 1.29289;
	const double etod = 1.10700;

	string yen = "yen";
	string euro = "euro";
	string pound = "pound";

	double val = 0.0;
	string curr = " ";

	cout << "Please enter a value followed by a currenty (yen, euro, pound): \n";
	cin >> val >> curr;

	if (curr == yen){
		cout << val << "¥ == " << "$" << val*ytod << endl;
	}
	else if (curr == euro){
		cout << val << "€ == " << "$" << val*etod << endl;
	}
	else if (curr == pound) {
		cout << val << "£ == " << "$" << val*ptod << endl;
	}
	else{
		cout << "Unkown current " << curr << endl;
	}
}