#include <iostream>

using namespace std;

int* allocateArray(int size) {
    return new int[size];
}

void messing_up(int *array, int n) {
	for (int i=0; i<n; ++i) {
		array[i] = rand() % 10 + 1;
	}
};

void printing(const int *array, int n) {

	// if user passed in a null pointer for array, bail out early!
	if (!array)
		return;

	for (int i=0; i<n; ++i) {
		cout << i << ", " << &array[i] << ": " << array[i] << endl;
	}
	cout << endl;
};

int main() {
    int *array = allocateArray(25);

    messing_up(array,25);

    printing(array,25);

    delete[] array;
    return 0;
}
