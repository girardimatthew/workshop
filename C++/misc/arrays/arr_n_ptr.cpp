// Arrays and pointers
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Constants
const int SIZE = 5;

using namespace std;

// function works exactly the same way
// void printing(int array[], int n) {
void printing(const int *array, int n) {

	// if user passed in a null pointer for array, bail out early!
	if (!array)
		return;

	for (int i=0; i<n; ++i) {
		cout << i << ", " << &array[i] << ": " << array[i] << endl;
	}
	cout << endl;
};

void messing_up(int *array, int n) {
	for (int i=0; i<n; ++i) {
		array[i] = rand() % 10 + 1;
	}
};

void print_int(const int *ptr) {
	cout << ptr << ", " << *ptr << endl;
};

void update(int *ptr) {
	*ptr = 46;
}

int main() {
	int elem[SIZE];
	int *ptr;
	/* initialize random seed: */
	srand (time(NULL));
	// init elem
	for (int i=0; i<SIZE; ++i) {
		// generate secret number between 1 and 10:
		elem[i] = rand() % 10 + 1;
	}
	printing(elem, SIZE);
	ptr = elem;
	messing_up(ptr, SIZE);
	printing(ptr, SIZE);
	printing(elem, SIZE);
	int x = 42;
	print_int(&x);
	update(&x);
	print_int(&x);
}
