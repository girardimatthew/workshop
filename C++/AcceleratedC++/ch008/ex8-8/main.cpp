#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::cout;

// Why didn't we write 
// (begin + end) / 2
// instead of the more complicated
// begin + (end - begin) / 2
// -------------------------------
// Doesn't point to the correct element
// invalid operation
// error: invalid operands to binary expression ('std::__1::__wrap_iter<int *>' and 'std::__1::__wrap_iter<int *>')
        // cout << *((begin + end) / 2) << endl;
        //            ~~~~~ ^ ~~~

template <class Ran, class X> bool t_binary_search(Ran begin, Ran end, const X& x) {
    while (begin < end) {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking only in that part
        if (x < *mid) 
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        // if we got here, then *mid == x so we're done
        else return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {

    int myints[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    std::vector<int> v(myints, myints+9);
    // using default comparison:
    std::sort (v.begin(), v.end());
    cout << "looking for a 3... ";
    if (t_binary_search(v.begin(), v.end(), 3))
        cout << "found!\n"; 
    else 
        cout << "not found.\n";
    
    for(vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter;
        if (iter != (v.end() - 1))
            cout << ", ";
    }
    cout << endl;
}