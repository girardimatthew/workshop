// Accelerated C++ 
// Ex: 5-8 

#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include "frame.h"
#include "hcat.h"
#include "vcat.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void printVector(const vector<string>& v) {

    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << endl;
    }

    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    string s;
    
    // read and split each line of input;
    while (getline(cin, s)) {
        vector<string> v = split(s);

        // print out each word in v
        printVector(v);
        
        // using frame
        vector<string> vframe = frame(v);
        // print the frame
        //printVector(vframe);

        // using hcat
        vector<string> h = hcat(vframe, vframe);
        printVector(h);
        
        // using vcat
        vector<string> vc = vcat(vframe, vframe);
        //printVector(vc);
    }

    cout << "\n== Hard-coded input ==\n" << endl;
    vector<string> v1 = { "Hello World!", "test one" };
    vector<string> v2 = { "The quick brown fox", "jumped over the lazy dogs." };
    vector<string> h = hcat(v1, v2);
    printVector(h);

    vector<string> v1_frame = frame(v1);
    vector<string> v2_frame = frame(v2);
    vector<string> h_frame = hcat(v1_frame, v2_frame);
    printVector(h_frame);
    
    return 0;
}
