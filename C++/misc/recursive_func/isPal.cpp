// *********************************************************************************
// Write a recursive function that determines whether an array is a palindrome, 
// where the array and its size are given as parameters.
// *********************************************************************************

#include <iostream>

using namespace std;

//returns 1 if a[] is a palindrome, 0 otherwise
int isPal(string a, int n) {
	int m = a.size()-1;
	if (n==0)
		return 1;
	if (a[n]==a[m-n])
		return isPal(a,n-1);
	else 
		return 0;
}

int main() {
	int n;
	string a;
	cout << "Enter a string: ";
	cin >> a;

	n = a.size();
	cout << isPal(a,n-1) << endl;
}