#include <iostream>

using namespace std;

int divide_numbers(int a, int b) {
	if (b==0)
		throw -1;

	return a/b;
}

int main() {
    int a, b;
    cout << "Number one: ";
    cin >> a;
    cout << "Number two: ";
    cin >> b;

    try {
    	cout << divide_numbers(a, b) << endl;
    }
    catch (int& code) {
    	cout << "ERROR CODE: " << code << endl;
    }
    catch (...) {
    	cout << "An unknown error has occurred." << endl;
    }

    return 0;
}