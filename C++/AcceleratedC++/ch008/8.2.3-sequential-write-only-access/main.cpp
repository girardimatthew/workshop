#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

template <class In, class Out> Out t_copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

int main(int argc, const char * argv[]) {
    
    vector<int> v_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> v_i_long = { 11, 12, 13, 14, 15, 16, 16, 17, 18, 19, 20, 99, 98, 97, 96, 95, 94, 93 };
    t_copy(v_i.begin(), v_i.end(), v_i_long.begin());
    for(vector<int>::const_iterator iter = v_i_long.begin(); iter != v_i_long.end(); ++iter) {
        cout << *iter;
        if (iter != (v_i_long.end() - 1))
            cout << ", ";
    }
    cout << endl;
}