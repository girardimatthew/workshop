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

    std::cout << "New_v size is: " << new_v.size() << std::endl;
    std::cout << new_v[new_v.size() - 1] << std::endl;
    
    print(new_v.begin(), new_v.end());
    
    Vec<string> a_copy_of_new_v = new_v;
    print(a_copy_of_new_v.begin(), a_copy_of_new_v.end());

    Vec<int> new_v_i(10, 42);
    print(new_v_i.begin(), new_v_i.end());

    Vec<int> another_vec_of_int(new_v_i);
    print(another_vec_of_int.begin(), another_vec_of_int.end());

    std::cout << new_v[0] << std::endl;

    print(new_v.begin(), new_v.end());
    std::cout << "New_v size is: " << new_v.size() << std::endl;

    std::cout << "\n# Removing all elements from vector." << std::endl;
    new_v.clear();
    std::cout << "New_v size is: " << new_v.size() << std::endl;
    new_v.push_back("Hello");
    new_v.push_back("World!");
    new_v.push_back("Using");
    new_v.push_back("x");
    new_v.push_back("new");
    new_v.push_back("class");
    new_v.push_back("Vec.");
    print(new_v.begin(), new_v.end());
    std::cout << "New_v size is: " << new_v.size() << std::endl;
    std::cout << new_v[7] << std::endl;

    std::cout << "\n# Removing the last element from the vector." << std::endl;
    print(new_v.begin(), new_v.end());

    std::cout << "\n# The last element of the vector is: " << *(new_v.end() - 1) << std::endl;
    Vec<string>::iterator last_element = new_v.erase(new_v.end() - 1);
    std::cout << *last_element << std::endl;
    
    std::cout << "\n# The new last element of the vector is: " << *(new_v.end() - 1) << std::endl;
    std::cout << "# New_v size is: " << new_v.size() << std::endl;
    print(new_v.begin(), new_v.end());
    std::cout << new_v[new_v.size() - 1] << std::endl;
    std::cout << new_v[new_v.size()] << std::endl;

    std::cout << "\n# Removing an element from the vector" << std::endl;
    print(new_v.begin(), new_v.end());
    std::cout << *(new_v.end() - 3) << std::endl;
    new_v.erase(new_v.end() - 3);
    print(new_v.begin(), new_v.end());
    std::cout << new_v.size() << std::endl;
    std::cout << new_v[0] << std::endl;
    std::cout << new_v[1] << std::endl;
    std::cout << new_v[2] << std::endl;
    std::cout << new_v[3] << std::endl;
    std::cout << new_v[4] << std::endl;
    std::cout << new_v[5] << std::endl;
    std::cout << new_v[6] << std::endl;
    std::cout << new_v[7] << std::endl;
    
    std::cout << "\n# Removing an element from the vector" << std::endl;
    print(new_v.begin(), new_v.end());
    std::cout << *(new_v.begin()) << std::endl;
    new_v.erase(new_v.begin());
    print(new_v.begin(), new_v.end());
    std::cout << new_v.size() << std::endl;
    std::cout << new_v[0] << std::endl;
    std::cout << new_v[1] << std::endl;
    std::cout << new_v[2] << std::endl;
    std::cout << new_v[3] << std::endl;
    // weird
    std::cout << new_v[4] << std::endl;

    return 0;
}