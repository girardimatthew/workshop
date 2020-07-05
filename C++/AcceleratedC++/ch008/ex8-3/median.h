#ifndef GUARD_median_h
#define GUARD_median_h

// median.h header file
#include <vector>
#include "median.cpp"

template<class T>
T median_by_value(std::vector<T> v);

template <class In, class T>
T median(In begin, In end, const vector<T>& v);

template <class In>
int median_pass_size(In begin, In end, const vector<int>::size_type vsize);

template <class Ran, class T>
T median_iter(Ran begin, Ran end);

#endif