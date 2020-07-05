#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include "../Pic/Picture.h"

int main() {
    
    vector<string> i = { "The quick", "brown fox", "jumped",  "over the lazy", "dogs!" };
    Picture p = Picture(i);
    Picture q = frame(p, 'x', 'x', 'x');
    cout << q << endl;
    cout << frame(p) << endl;
    cout << endl;

    Picture r = hcat(q, q);
    cout << frame(r, 'o', '-', '|') << endl;
    cout << endl;

    Picture s = vcat(q, r);
    cout << frame(hcat(s, vcat(r, q))) << endl;

    return 0;
}