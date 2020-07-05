// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>

using std::domain_error;        using std::distance;
using std::sort;                using std::advance;
using std::vector;

// compute the median of a vector<T>
template<class T>
T median_by_value(std::vector<T> v)
{
  typedef typename std::vector<T>::size_type vec_sz;
  vec_sz size = v.size();
  
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  sort(v.begin(), v.end());

  vec_sz mid = size / 2;
  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

// 
template <class In, class T>
T median(In begin, In end, const vector<T>& v) {
    
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();

    if (begin == end)
        throw domain_error("median of an empty vector");
    
    sort(begin, end);

    vec_sz mid = size/2;
    In m_iter = begin + mid;

    return size % 2 == 0 ? ((*m_iter) + (*(--m_iter))) / 2 : *m_iter;
}

// 
template <class In>
int median_pass_size(In begin, In end, const vector<int>::size_type vsize) {
    
    typedef vector<int>::size_type vec_sz;
    //vec_sz size = v.size();

    if (begin == end)
        throw domain_error("median of an empty vector");
    
    sort(begin, end);

    vec_sz mid = vsize / 2;
    In m_iter = begin + mid;

    return vsize % 2 == 0 ? ((*m_iter) + (*(--m_iter))) / 2 : *m_iter;
}

// 
template <class Ran, class T>
T median_iter(Ran begin, Ran end) {
    
    typename std::iterator_traits<Ran>::difference_type count = distance(begin, end);

    if (count == 0)
        throw domain_error("median of an empty vector");
    
    sort(begin, end);

    typename std::iterator_traits<Ran>::difference_type mid = count / 2;
    advance(begin, mid - 1);

    return count % 2 == 0 ? (*begin++ + *begin) / 2 : *++begin;
}