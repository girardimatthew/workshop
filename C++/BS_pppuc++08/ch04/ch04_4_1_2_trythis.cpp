// program that converts yen, euros
// and pound into dollars.
#include <iostream>

using namespace std;

int main () {
	const double yen_to_d = 0.00992;
	const double pound_to_d = 1.29289;
	const double euro_to_d = 1.10700;
	const double yuan_to_d = 0.149369;
	const double dankroner_to_d = 0.148804;

	char whichcurr = 'a';
	double val = 0.0;
	string curr = " ";

	cout << "---------------------------------------------------\n";
	cout << "Program that converts some currencies into dollars.\n";
	cout << "Please enter a value followed by a currency.\nAllowed currency are: yen, euro, pound, yuan, kroner.\n";
	cin >> val >> curr;

	if (curr == "yen"){
		whichcurr = 'y';
	}
	else if (curr == "euro"){
		whichcurr = 'e';
	}
	else if (curr == "pound") {
		whichcurr = 'p';
	}
	else if (curr == "yuan") {
		whichcurr = 'u';
	}
	else if (curr == "kroner") {
		whichcurr = 'k';
	}

	switch (whichcurr) {
		case 'y':
			cout << val << "¥ == " << "$" << val*yen_to_d << endl;
			break;
		case 'e':
			cout << val << "€ == " << "$" << val*euro_to_d << endl;
			break;
		case 'p':
			cout << val << "£ == " << "$" << val*pound_to_d << endl;
			break;
		case 'u':
			cout << val << "¥ == " << "$" << val*yuan_to_d << endl;
			break;
		case 'k':
			cout << val << "DK == " << "$" << val*dankroner_to_d << endl;
			break;
		default:
			cout << "Unkown currency " << curr << endl;
			break;
	}

}