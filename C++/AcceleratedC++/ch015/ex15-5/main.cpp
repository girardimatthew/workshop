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

#include "../Pic/Picture.h"

int main() {
    //vector<string> i = { "The quick", "brown fox", "jumped", "over the lazy", "dogs!" };
    //vector<string> n = { "Pack my box", "with five dozen", "liquor jugs." };

    vector<string> i = { "The quick", "brown fox" };
    vector<string> n = { "Pack my box", "with five", "dozen", "liquor jugs." };
    vector<string> x = { "Pack my box", "with liquor jugs." };
    
    Picture pi = Picture(i);
    Picture pn = Picture(n);

    Picture fpi = frame(pi);
    Picture fpn = frame(pn);

    cout << fpi << endl;
    cout << fpn << endl;
    cout << endl;

    Picture hfpp = hcat(fpi, fpn);
    cout << hfpp << endl;
    cout << frame(hfpp) << endl;
    cout << hcat(frame(hfpp),frame(hfpp)) << endl;
    cout << endl;

    cout << hcat(frame(hfpp),frame(x)) << endl;

    return 0;
}