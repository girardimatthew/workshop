// *********************************************************************************
// struct Example 001
// Matteo Girardi
// *********************************************************************************

#include <iostream>
using namespace std;

struct MyStruct {
	int x;
};

MyStruct updateStruct (MyStruct my_struct) {
	my_struct.x = 10;
	return my_struct;
};

int main () {
	MyStruct my_struct;
    my_struct.x = 5;
    // updateStruct( my_struct ); 						// wrong. struct is not updated.
    my_struct = updateStruct(my_struct);
    cout << my_struct.x << '\n';
}