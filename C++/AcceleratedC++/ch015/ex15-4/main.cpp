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
    vector<string> i = {"The quick", "brown fox", "jumped", "over the lazy", "dogs!"};
    Picture p = Picture(i);
    Picture q = frame(p, 'x', 'x', 'x');
    cout << q << endl;
    cout << frame(p) << endl;
    q.reframe('#', '~', '!');
    cout << q << endl;
    cout << endl;

    Picture r = hcat(q, q);
    cout << frame(r, 'o', '-', '|') << endl;
    cout << endl;

    Picture s = vcat(q, r);
    Picture f = frame(hcat(s, vcat(r, q)));
    cout << f << endl;
    f.reframe('$', '-', '|');
    cout << f << endl;

    return 0;
}