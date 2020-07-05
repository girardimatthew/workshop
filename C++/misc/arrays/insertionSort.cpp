// This program sorts an array's values into ascending order.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int arraySize = 10;
	int data[arraySize] = { 34, 56, 4, 10, 77, 51, 93, 30, 5, 52 };
	int insert; // temporary variable to hold element to insert

	cout << "Unsorted array:\n";
	// output original array
	for (int i = 0; i < arraySize; ++i)
		cout << setw(4) << data[i];

	// insertion sort
	// loop over the elements of the array
	for (int next = 1; next < arraySize; ++next) {
		// store the value of the current element
		insert = data[next];
		// initialize the location to place element
		int moveItem = next;
		// search for the location in which to put the current element
		while ((moveItem > 0) && (data[moveItem - 1] > insert)) {
			// shift element one slot to the right
			data[moveItem] = data[moveItem-1];
			moveItem--;
		}
		data[moveItem] = insert; // place insert element into the array
	}

	cout << "\nSorted array:\n";
	// output sorted array
	for (int i = 0; i < arraySize; ++i)
		cout << setw(4) << data[i];

	cout << endl;
}