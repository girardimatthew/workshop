#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::string;

#include "../Vec/Vec.h"

int main() {

    string hw = "Hello, World!";
    cout << hw << endl;

    Vec<char> vc(hw.begin(), hw.end());
    vc.print_vec(cout);
    
    return 0;
}