// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;
using std::distance;
using std::advance;

// compute the median of a vector<T>
template <class Ran, class T>
T median(Ran begin, Ran end) {

    typename std::iterator_traits<Ran>::difference_type count = distance(begin, end);

    if (count == 0)
        throw domain_error("median of an empty vector");

    vector<T> v(begin, end);
    sort(v.begin(), v.end());

    typename std::iterator_traits<Ran>::difference_type mid = count / 2;

    return count % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}