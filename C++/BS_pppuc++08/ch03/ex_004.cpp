#include <iostream>

using namespace std;

int main() {
	double val1, val2;

	cout << "Please, enter a value (floating-point): " << endl;
	cin >> val1;
	cout << "Please, enter a value (floating-point): " << endl;
	cin >> val2;

	cout << "----------------------------------------" << endl;

	if (val1 < val2) {
		cout << "val1 is smaller than val2: " << val1 << " < " << val2 << endl;
	}
	else{
		cout << "val1 is bigger than val2: " << val1 << " > " << val2 << endl;
	}

	cout << "The arithmentic mean is: " << (val1+val2)/2 << endl;
	cout << "The difference is: " << val1 - val2 << endl;
	cout << "The product is: " << val1*val2 << endl;
	cout << "The ratio is: " << val1/val2 << endl;

	cout << "----------------------------------------" << endl;
	cout << "the same operation using integers" << endl;
	cout << "----------------------------------------" << endl;
	int iv1, iv2;
	iv1 = int(val1);
	iv2 = int(val2);

	cout << "integer val1: " << iv1 << endl;
	cout << "integer val2: " << iv2 << endl;
	cout << "The arithmentic mean is: " << (iv1+iv2)/2 << endl;
	cout << "The difference is: " << iv1 - iv2 << endl;
	cout << "The product is: " << iv1*iv2 << endl;
	cout << "The ratio is: " << iv1/iv2 << endl;
}