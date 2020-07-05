#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>
#include <cstring>

using std::string;

// example implementation of standard-library function
size_t m_strlen(const char* p) {
    size_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
}

int main() {
    
    const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    const string helloS = "Hello";
    const string s(hello); // s("Hello");
    const string sc(hello, hello + strlen(hello));
    // hello -> pointer to the initial character
    // hello + strlen(hello) -> is a pointer to the '\0'


    cout << (hello == helloS) << endl;
    cout << strlen(hello) << endl;
    cout << m_strlen(hello) << endl;

    // size_t => appropriate to contain the size
    // of any array
    cout << s << endl;
    cout << sc << endl;

    return 0;
}