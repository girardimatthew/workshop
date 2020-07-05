// Pass-by-reference with a pointer argument used to cube a
// variable's value.
#include <iostream>
using namespace std;

void cubeByRef(int *);

int main() {
	int number = 5;

	cout << "The original value of number is " << number;
	// pass number address to cubeByRef
	cubeByRef(&number);
	cout << "\nThe new value of number is " << number << endl;
}

void cubeByRef(int *Ptr) {
	*Ptr = *Ptr * *Ptr * *Ptr;
}