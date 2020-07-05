#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>
#include <cstring>

using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

using std::copy;

// this function deliverately yerlds an invalid pointer.
// it is intended as a negative example
// DO NOT DO THIS 
int* invalid_pointer() {
    int x;
    return &x;  // INSTANT DISASTER!
}

// This fnction is completely legitimate
int* pointer_to_static() {
    // static => allocate it once and only once.
    // it returns a ponter to the same object!
    static int x;
    return &x;
}

// Dynamic allocation => pointer to a brand new object,
// which stays around until we decide that we no longer want it.

// impose on its caller the responsibility of freeing the object at
// an appropriate time
int* pointer_to_dynamic() {
    return new int(0);
}

char* duplicate_chars(const char* p) { 
    // allocate enough space; remember to add one for the null
    size_t length = strlen(p) + 1;
    char* result = new char[length];
    // copy into our newly allocated space and return pointer to first element
    copy(p, p + length, result);
    return result;
}

int main(int argc, char** argv) {
    
    int* p = new int(42);
    cout << p << ", " << *p << endl;
    ++*p;
    cout << p << ", " << *p << endl;

    delete p;

    // ?? why is this possible ?? 
    cout << p << ", " << *p << endl;
    ++*p;
    cout << p << ", " << *p << endl;

    cout << p << ", " << *p << endl;
    ++*p;
    cout << p << ", " << *p << endl;


    
    return 0;
}