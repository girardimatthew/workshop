#include <iostream>

using namespace std;

int main() {
	string operation = "";
	double d1, d2 = 0.0;

	cout << "Please, enter an operation: " << endl;
	cout << "for instance: + 100 45" << endl;
	cin >> operation >> d1 >> d2;

	if (operation=="+"){
		cout << d1 << " " << operation << " " << d2 << " == " << d1+d2 << endl;
	}
	else if (operation=="-"){
		cout << d1 << " " << operation << " " << d2 << " == " << d1-d2 << endl;
	}
	else if (operation=="/"){
		cout << d1 << " " << operation << " " << d2 << " == " << d1/d2 << endl;
	}
	else if (operation=="*"){
		cout << d1 << " " << operation << " " << d2 << " == " << d1*d2 << endl;
	}
	else {
		cout << "unknown operator detected" << endl;
	}
}
