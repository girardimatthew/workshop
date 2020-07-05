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

int main(int argc, char** argv) {
    
    //ifstream infile("in");
    string file = "in";
    ifstream infile(file.c_str());
    ofstream outfile("out");
    
    string s;
    
    while (getline(infile, s))
        outfile << s << endl;
    
    return 0;
}