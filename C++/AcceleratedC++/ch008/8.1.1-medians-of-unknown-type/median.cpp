// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

// compute the median of a vector<T>
template <class T>
T median(vector<T> v) {
    
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0) 
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}