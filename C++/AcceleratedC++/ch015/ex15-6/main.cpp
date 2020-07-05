#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <algorithm>
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include "Picture.h"

int main() {

    Vec<Str> x;
    x.push_back("The five boxing wizards");
    x.push_back("jump quickly");

    Vec<Str> i;
    i.push_back("The quick");
    i.push_back("brown fox");
    i.push_back("jumped");
    i.push_back("over");
    i.push_back("the lazy");
    i.push_back("dogs!");

    // TODO 
    //Vec<Str> n = { "Pack my box", "with five", "dozen", "liquor jugs." };
    Vec<Str> n;
    n.push_back("Pack my box");
    n.push_back("with five");
    n.push_back("dozen");
    n.push_back("liquor jugs");

    Picture px = Picture(x);
    Picture pi = Picture(i);
    Picture pn = Picture(n);
    
    Picture fpx = frame(px);
    Picture fpi = frame(pi);
    Picture fpn = frame(pn);

    cout << fpx << endl;
    cout << fpi << endl;
    cout << fpn << endl;
    cout << endl;

    Picture hfpp = hcat(fpx, hcat(fpi, fpn));
    cout << hfpp << endl;
    cout << frame(hfpp) << endl;
    cout << hcat(frame(hfpp), frame(hfpp)) << endl;
    cout << endl;

    cout << hcat(frame(hfpp), frame(n)) << endl;

    return 0;
}