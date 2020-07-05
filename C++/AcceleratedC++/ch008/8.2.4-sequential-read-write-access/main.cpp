#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

template <class For, class X> void t_replace(For beg, For end, const X& x, const X& y) {
    while (beg != end) {
        if (*beg == x) *beg = y;
        ++beg;
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> v_i = { 3, 12, 3, 14, 15, 3, 16, 17, 3, 19, 20, 3, 98, 97, 3, 95, 3, 93 };
    t_replace(v_i.begin(), v_i.end(), 3, 31);
    for(vector<int>::const_iterator iter = v_i.begin(); iter != v_i.end(); ++iter) {
        cout << *iter;
        if (iter != (v_i.end() - 1))
            cout << ", ";
    }
    cout << endl;
}