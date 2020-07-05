#include <iostream>

using namespace std;

int divide_numbers(int a, int b) {
	try {
		if (b==0)
			throw 1;

		return a/b;
	}
	catch (int err_code) {
		cout << "Error code: " << err_code << endl;
	}
	return -1;
}

int main() {
    int a, b;
    cout << "Number one: ";
    cin >> a;
    cout << "Number two: ";
    cin >> b;

    cout << divide_numbers(a, b) << endl;

    return 0;
}