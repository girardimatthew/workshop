// Passing arrays as parameters
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Constants
const int SIZE = 50;

using namespace std;

void printing(int array[], int n) {
	for (int i=0; i<n; ++i) {
		cout << array[i] << ", ";
	}
	cout << endl;
};

double total(int array[], int n) {
	double total = 0;
	for (int i=0; i<n; ++i) {
		total += array[i];
	} 
	return total;
}

int main() {
	int elem[SIZE];
	double sum = 0;
	double mean = 0;
	/* initialize random seed: */
	srand (time(NULL));
	// init elem
	for (int i=0; i<SIZE; ++i) {
		// generate secret number between 1 and 10:
		elem[i] = rand() % 10 + 1;
	}
	// printing elements 
	printing(elem, SIZE);
	// the sum
	sum = total(elem, SIZE);
	cout << "total: " << sum << endl;
	// the mean
	mean = sum/(double)SIZE;
	cout << "mean: " << mean << endl;
	// size of array
	cout << "size (byte) of array: " << sizeof(elem) << endl; 
	cout << "size (byte) of array[0]: " << sizeof(elem[0]) << endl;
	cout << "Num of elements in array: " << sizeof(elem)/sizeof(elem[0]) << endl;

	return 0;
}