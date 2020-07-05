// *********************************************************************************
// Factorial numbers with recursion
// *********************************************************************************

#include <iostream>

using namespace std;

int fibo(int n) {
	if (n<=1)
		return 1;
	return fibo(n-1) + fibo(n-2);
}

int main() {
	int n;
	cout << "Enter the n-th fibonacci number: ";
	cin >> n;
	cout << fibo(n-1) << endl;
}