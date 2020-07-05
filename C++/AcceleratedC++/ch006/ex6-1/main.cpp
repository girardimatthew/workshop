#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include "frame.h"
#include "hcat.h"
#include "vcat.h"

void print_vector(const std::vector<std::string>& v) {
    std::vector<std::string>::const_iterator iter = v.begin();
    while (iter != v.end())
        std::cout << *iter++ << std::endl;
}

int main(int argc, const char * argv[]) {
    
    std::string s = "Hello World!";
    // split words
    vector<string> v = split(s);
    // write each word in v
    std::cout << "\nInput words:" << std::endl;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        std::cout << "\t - " << v[i] << std::endl;
    }
    std::cout << std::endl;

    // using frame
    vector<string> vframe = frame(v);
    
    // write the frame
    std::cout << "Frame:" << std::endl;
    print_vector(vframe);
    
    // using hcat
    std::cout << std::endl;
    std::cout << "Horizontal frame:" << std::endl;
    vector<string> h = hcat(vframe, vframe);
    print_vector(h);
    
    // using vcat
    std::cout << std::endl;
    std::cout << "Vertical frame:" << std::endl;
    vector<string> vc = vcat(vframe, vframe);
    print_vector(vc);
    
    return 0;
}
