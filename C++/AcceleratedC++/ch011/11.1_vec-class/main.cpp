#include "Vec.h"
#include "split.h"
#include <iostream>

#include <string>
using std::string;

#include <vector>
using std::vector;

template <class Ran>
void print(Ran begin, Ran end) {
    while (begin != end) {
        std::cout << *begin++ << " ";
    }
    std::cout << std::endl;
}

void print(const std::string& str) {
    print(str.begin(), str.end());
}

int main() {

    // Assignment is not initialization
    string url_ch = "~;/?:@=&$-.+!*'(),";   //initialization
    print(url_ch.begin(), url_ch.end());

    string spaces(url_ch.size(), ' ');      //initialization
    print(spaces.begin(), spaces.end());

    string y;                               //initialization
    y = url_ch;                             // assignment
    print(y.begin(), y.end());
    
    // another example
    string line = "The quick brown fox jumps over the lazy dog!";
    print(line.begin(), line.end());

    vector<string> split(const string&);    // function declaration
    vector<string> v;                       // initialization
    v = split(line);                        // on entry, initialization of split's parameter from line;
                                            // on exit, both initialization of the return value
                                            // and assignment to v
    print(v.begin(), v.end());

    print("\n======================================================\n");

    Vec<string> new_v;
    new_v.push_back("Hello");
    new_v.push_back("World!");
    new_v.push_back("Using");
    new_v.push_back("the");
    new_v.push_back("new");
    new_v.push_back("class");
    new_v.push_back("Vec.");
    print(new_v.begin(), new_v.end());
    
    Vec<string> a_copy_of_new_v = new_v;
    print(a_copy_of_new_v.begin(), a_copy_of_new_v.end());

    Vec<int> new_v_i(10, 42);
    print(new_v_i.begin(), new_v_i.end());

    Vec<int> another_vec_of_int(new_v_i);
    print(another_vec_of_int.begin(), another_vec_of_int.end());

    std::cout << new_v[0] << std::endl;

    return 0;
}