// *********************************************************************************
// Write a recursive function that finds and returns the minimum element in an array, 
// where the array and its size are given as parameters.
// *********************************************************************************

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//return the minimum element in a[]
int findmin(int a[], int n) {
	if (n==0)
		return a[n];
	int x = findmin(a,n-1);
	return a[n] > x ?  x : a[n];
}

int main() {
	int n = 7;
	int a[] = {19, 8, 3, 5, -20, 50, 99};
	cout << findmin(a,n-1) << endl;
}