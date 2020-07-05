// source file for the median function
#include <algorithm>
#include <stdexcept>
#include "Vec.h"

using std::domain_error;
using std::sort;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
template <class T> T median(Vec<T> v) {

    typedef typename Vec<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0) 
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}