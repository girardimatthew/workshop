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

    sort(begin, end);
    typename std::iterator_traits<Ran>::difference_type mid = count / 2;
    advance(begin, mid - 1);
    
    Ran bpp = begin + 1;
    return count % 2 == 0 ? (*bpp + *begin) / 2 : *++begin;
    //return count % 2 == 0 ? (*begin++ + *begin) / 2 : *++begin;
}

// The following code:
// return count % 2 == 0 ? (*begin++ + *begin) / 2 : *++begin;
// yields to:
// In file included from median_TestCase.cpp:6:
// ./median.cpp:25:31: warning: unsequenced modification and access to 'begin' [-Wunsequenced]
//     return count % 2 == 0 ? (*++begin + *begin) / 2 : *++begin;
//                               ^          ~~~~~
// median_TestCase.cpp:63:15: note: in instantiation of function template specialization 'median<int *, int>' requested here
//     int med = median<int*, int>(numbers, (numbers + ngrades));
//               ^
// 1 warning generated.