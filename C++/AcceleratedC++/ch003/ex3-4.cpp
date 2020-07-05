#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <array>

// Write a program to report the length of the longest and shortest string in its input

using namespace std;

typedef vector<string>::size_type vec_sz;
typedef string::size_type string_sz;

void printOut(const vector<string>& set) {
    cout << "The elements of the vector are: ";
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
    cout << "**** Report the longest and shortest string  ****" << endl;
    cout << "Please enter a series of words "
            "followed by end-of-file: ";

    string aString;
    // the number vector
    vector<string> strings;
    string_sz max_length = 0;
    string_sz min_length = 0;
    
    // invariant: until end-of-file
    while (cin >> aString) {
        string_sz size = aString.length();
        if (size > max_length)
            max_length = size;
        
        if (min_length == 0 || size < min_length)
            min_length = size;
        strings.push_back(aString);
    }
    // check for no input
    if (strings.size() == 0) {
        cout << endl << "No data!" << endl;
        return 1;
    }
    
    printOut(strings);
    //
    cout << "max length: " << max_length << endl;
    cout << "min length: " << min_length << endl;

    
    cout << endl;
    return 0;
}