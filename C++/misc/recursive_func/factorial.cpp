// *********************************************************************************
// Factorial with recursion
// *********************************************************************************

#include <iostream>

using namespace std;

int fact(int n) {
	if (n==0)
		return 1;
	return n*fact(n-1);
}

int main() {
	int n = 10;
	for (int i=0; i<=n; ++i) {
		cout << "Factorial of " << i << " is: " << fact(i) << endl;
	}
}