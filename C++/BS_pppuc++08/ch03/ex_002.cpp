// a C++ program that converts from miles to kilometers
#include <iostream>

using namespace std;

int main() {
	double miles;
	double km = 1.60934;
	int i = 1;

	cout << "Please, enter a value as miles: " << endl;
	cin >> miles;
	cout << " ------------------------------------ " << endl;
	cout << miles << " miles == " << km * miles << " km" << endl;
	cout << " ------------------------------------ " << endl;
	while (i < 101) {
		if (i > 9) {
			cout << i << " miles \t" << km * i << " km" << endl;
			i+=5;
		}
		else {
			cout << i << " miles \t" << km * i << " km" << endl;
			++i;
		}
	}
}