// *********************************************************************************
// Write a recursive function that computes and 
// returns the sum of all elements in an array, 
// where the array and its size are given as parameters.
// *********************************************************************************

#include <iostream>

using namespace std;

//return the minimum element in a[]
int findsum(int a[], int n) {
	if (n==0)
		return a[n];
	return a[n]+findsum(a,n-1);
}

int main() {
	int n = 5;
	int a[] = {1, 2, 3, 4, 5};
	cout << findsum(a,n-1) << endl;
}