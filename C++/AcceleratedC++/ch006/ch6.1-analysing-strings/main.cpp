#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include "frame.h"
#include "hcat.h"
#include "vcat.h"

int main(int argc, const char * argv[]) {
    
    std::string s;
    
    // read and split each line of input;
    while (std::getline(std::cin, s)) {
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
        for (vector<string>::size_type i = 0; i != vframe.size(); ++i) {
            std::cout << vframe[i] << std::endl;
        }
        
        // using hcat
        std::cout << std::endl;
        std::cout << "Horizontal frame:" << std::endl;
        vector<string> h = hcat(vframe, vframe);
        for (vector<string>::size_type i = 0; i != h.size(); ++i) {
            std::cout << h[i] << std::endl;
        }
        
        
        // using vcat
        std::cout << std::endl;
        std::cout << "Vertical frame:" << std::endl;
        vector<string> vc = vcat(vframe, vframe);
        for (vector<string>::size_type i = 0; i != vc.size(); ++i) {
            std::cout << vc[i] << std::endl;
        }
    }
    
    return 0;
}
