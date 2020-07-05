// *********************************************************************************
// struct Example 002
// Matteo Girardi
// *********************************************************************************

#include <iostream>
using namespace std;

struct MyStruct {
	int x;
};

void updateStruct (MyStruct &my_struct) {
	my_struct.x = 10;
};

int main () {
	MyStruct my_struct;
    my_struct.x = 5;
    updateStruct( my_struct ); 						// wrong. struct is not updated.
    cout << my_struct.x << '\n';
}