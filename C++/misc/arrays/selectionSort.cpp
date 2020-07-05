// Selection sort with pass-by-reference. This program puts values into an
// array, sorts them into ascending order and prints the resulting array.

#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int * const, const int);
void swap(int * const, int * const);

int main() {
	const int arraySize = 10;
	// int a[arraySize] = {2,6,4,8,12,10,89,68,45,37};
	// int a[arraySize] = {100, 80, 75, 70, 69, 64, 55, 30, 20, 1};
	int a[arraySize] = {1, 80, 75, 70, 69, 64, 55, 30, 20, 100};

	cout << "Data items in original order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

	// sort the array
	selectionSort(a, arraySize);

	cout << "\nData items in ascending order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

	cout << endl;
	return 0;
}

void selectionSort(int * const array, const int size) {
	for (int p = 0; p < size - 1; ++p) {
		for (int i = 0; i < size - 1; ++i) {
			if (array[i] > array[i+1])
				swap(&array[i], &array[i+1]);
		}
	}
}

// void selectionSort(int * const array, const int size) {
// 	int smallest; // index of smallest element
// 	// loop over size - 1 elements
// 	for (int i = 0; i < size - 1; ++i) {
// 		smallest = i;
// 		for (int index = i + 1; index < size; ++index) {
// 			if (array[index] < array[smallest])
// 				smallest = index;
// 		}
// 		swap(&array[i], &array[smallest]);
// 	}
// }

void swap(int * const n, int * const m) {
	int tmp = *n;
	*n = *m;
	*m = tmp;
}