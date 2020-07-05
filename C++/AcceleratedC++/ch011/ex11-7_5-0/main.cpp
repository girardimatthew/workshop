#include <iostream>
#include <string>

#include "Vec.h"
#include "split.h"
#include "frame.h"
#include "hcat.h"
#include "vcat.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    
    string s;
    
    // read and split each line of input;
    while (getline(cin, s)) {
        Vec<string> v = split(s);

        // write each word in v
        for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
            cout << v[i] << endl;
        }
        
        // using frame
        Vec<string> vframe = frame(v);
        cout << endl;
        // write the frame
        for (Vec<string>::size_type i = 0; i != vframe.size(); ++i) {
            cout << vframe[i] << endl;
        }
        
        // using hcat
        cout << endl;
        Vec<string> h = hcat(vframe, vframe);
        for (Vec<string>::size_type i = 0; i != h.size(); ++i) {
            cout << h[i] << endl;
        }
        
        // using vcat
        cout << endl;
        Vec<string> vc = vcat(vframe, vframe);
        for (Vec<string>::size_type i = 0; i != vc.size(); ++i) {
            cout << vc[i] << endl;
        }
    }
    
    return 0;
}
