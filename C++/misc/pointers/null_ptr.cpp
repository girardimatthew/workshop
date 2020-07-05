// Passing addresses by reference

#include <iostream>

using namespace std;

void setToNull(int *tempPtr) {
    // we're making tempPtr point at something else, not changing the value that tempPtr points to.
    tempPtr = 0; // use 0 instead if not C++11
}

// tempPtr is now a reference to a pointer, so any changes made to tempPtr will change the argument as well!
void setToNull2(int *&tempPtr) {
    tempPtr = nullptr; // use 0 instead if not C++11
}

int main() {
    // First we set ptr to the address of five, which means *ptr = 5
    int five = 5;
    int *ptr = &five;

    // This will print 5
    cout << *ptr << endl;

    // tempPtr will receive a copy of ptr
    setToNull(ptr);

    // ptr is still set to the address of five!

    // This will print
    if (ptr)
      cout << *ptr << endl;
    else
      cout << " ptr is null" << endl;
    setToNull2(ptr);
    // This will print
    if (ptr)
      cout << *ptr << endl;
    else
      cout << " ptr is null" << endl;
    return 0;
}
