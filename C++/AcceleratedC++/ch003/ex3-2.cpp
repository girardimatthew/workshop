#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

// Write a program to compute and print the quartiles (that is, the quarter of the numbers with the largest values, the next highest quarter, and so on) of a set of integers.
// https://en.wikipedia.org/wiki/Quartile
// Method 1

using namespace std;

typedef vector<double>::size_type vec_sz;

// // TODO: refactor
// in this case aka Second Quartile or Q2
double median(const vector<double>& set, vec_sz begin, vec_sz end) {
    vec_sz size = begin + end;
    vec_sz mid = size / 2;
    return size % 2 == 0 ?
        (set[mid] + set[mid - 1]) / 2.0 :
        set[mid];
}

void printOut(const vector<double>& set) {
    cout << "The set of number is: ";
    cout << "[";
    for (int i = 0; i < set.size(); ++i) {
        cout << set[i];
        if (i < (set.size() - 1))
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // ask for words
    cout << "**** Quartiles ****" << endl;
    cout << "Please enter a series of number (e.g 1 2 3 4 5 6 7 8) "
            "followed by end-of-file: ";
    
    // the input number
    double number;
    // the number vector
    vector<double> numbers;
    // the size of the set of number
    vec_sz size;
    vec_sz mid;
    vec_sz lower_half_end;
    vec_sz upper_half_begin;
    
    // invariant: until end-of-file
    // TODO: check for type.
    while (cin >> number) {
        numbers.push_back(number);
    }
    // check for no input
    if (numbers.size() == 0) {
        cout << endl << "No data!" << endl;
        return 1;
    }
    //
    size = numbers.size();
    mid = size / 2;
    // order the vector
    sort(numbers.begin(), numbers.end());
    // 
    printOut(numbers);
    // 
    if (size % 2 != 0) {
        // odd
        lower_half_end = mid;
        upper_half_begin = mid;
    } else {
        // even
        lower_half_end = upper_half_begin = mid;
    }

    cout << "Q1: " << median(numbers, 0, lower_half_end) << endl;
    cout << "Q2: " << median(numbers, 0, size) << endl;
    cout << "Q3: " << median(numbers, upper_half_begin, size) << endl;

    cout << endl;
    return 0;
}