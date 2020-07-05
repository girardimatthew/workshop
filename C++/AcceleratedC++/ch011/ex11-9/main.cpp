#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <chrono>
using std::chrono::steady_clock;

#include "Vec.h"

using std::streamsize;
using std::domain_error;
using std::sort;

int test_grow(int appends) { 
    Vec<int> v1;
    Vec<int> v2;

    steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < appends; i++)
        v1.push_back(i);
    steady_clock::time_point end = std::chrono::steady_clock::now();
    cout 
        << "Microseconds to add " 
        << appends 
        << " to vector using double memory method = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;

    begin = std::chrono::steady_clock::now();
    for (int i = 0; i < appends; i++)
        v2.push_back(i, false);
    end = std::chrono::steady_clock::now();
    cout 
        << "Microseconds to add " 
        << appends 
        << " to vector without using double memory method = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;

    return 0;
}

int main() {

    test_grow(5);
    cout << endl;
    test_grow(10);
    cout << endl;
    test_grow(20);
    cout << endl;
    test_grow(50);
    cout << endl;
    test_grow(100);
    cout << endl;
    test_grow(500);
    cout << endl;
    test_grow(1000);
    cout << endl;
    test_grow(3000);

    return 0;
}