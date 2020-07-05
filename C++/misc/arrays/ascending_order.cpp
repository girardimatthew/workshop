// *********************************************************************************
// Arrange array in ascending order
// Matteo Girardi
// *********************************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	const int arraySize = 10;
	int a[arraySize] = {2,6,4,8,12,10,89,68,45,37};
	int i, hold;

	cout << "Data items in original order\n";
	for (i = 0; i < arraySize; i++) 
		cout << setw(4) << a[i];

	for (int p = 0; p < arraySize - 1; p++) {
		for (i = 0; i < arraySize - 1; i++) {
			if (a[i] > a[i+1]) {
				hold = a[i];
				a[i] = a[i+1];
				a[i+1] = hold;
			}
		}
	}

	cout << "\nData items in ascending order\n";
	for (i = 0; i < arraySize; i++) 
		cout << setw(4) << a[i];

	cout << endl;
	return 0;
}