#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

template <class T> void paws(T& x, T& y) {
    T tmp_x = x;
    x = y;
    y = tmp_x;
}

template <class Bi> void rreverse(Bi begin, Bi end) {

    while (begin != end) {
        --end;
        if (begin != end) {
            //std::swap(*begin++, *end);
            paws(*begin++, *end);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> v_i = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    rreverse(v_i.begin(), v_i.end());
    for(vector<int>::const_iterator iter = v_i.begin(); iter != v_i.end(); ++iter) {
        cout << *iter;
        if (iter != (v_i.end() - 1))
            cout << ", ";
    }
    cout << endl;
}