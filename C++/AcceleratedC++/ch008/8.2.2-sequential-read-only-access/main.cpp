#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

// non-recursive implementation
template <class In, class X> In find_nr(In begin, In end, const X& x) {
    while (begin != end && *begin != x) 
        ++begin;
    return begin;
}
// recursive version
template <class In, class X> In find_r(In begin, In end, const X& x) {
    while (begin == end || *begin == x) 
        return begin;
    begin++;
    return find(begin, end, x);
}

int main(int argc, const char * argv[]) {
    
    vector<int> v_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::const_iterator vi_iter = find_nr(v_i.begin(), v_i.end(), 2);
    vector<int>::const_iterator vi_iter_r = find_r(v_i.begin(), v_i.end(), 9);
    cout << *vi_iter << ", " << *vi_iter_r << endl;

}