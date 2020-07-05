#pragma once

#include <algorithm>
#include <iterator>

template <class In1, class In2>
bool my_equal(In1 b, In1 e, In2 b2) {
    while(b != e) {
        if (!(*b == *b2)) 
            return false;
        ++b; ++b2;
    }
    return true; 
}

template <class In, class X>
In my_find(In begin, In end, const X& x) {
    while (begin != end && *begin != x) {
        ++begin;
    }
    return begin;
}

template <class InputIt, class UnaryPredicate>
InputIt my_find_if(InputIt begin, InputIt end, UnaryPredicate p) {
    while (begin != end) {
        if (p(*begin)) return begin;
        ++begin;
    }
    return end;
}

template <class In, class Out>
Out my_copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template <class ForwardIterator, class T>
ForwardIterator my_remove(ForwardIterator b, ForwardIterator e, const T& value) {
    ForwardIterator result = b;
    while (b != e) {
        if (!(*b == value))
            *result++ = *b;
        ++b;
    }
    return result;
}

template <class InputIt, class OutputIt, class T>
OutputIt my_remove_copy(InputIt b, InputIt e, OutputIt d, const T& value) {
    while (b != e) {
        if (!(*b == value))
            *d++ = *b;
        ++b;
    }
    return d;
}

template <class InputIt, class OutputIt, class UnaryPredicate>
OutputIt my_remove_copy_if(InputIt b, InputIt e, OutputIt d, UnaryPredicate p) {
    while (b != e) {
        if (!p(*b))
            *d++ = *b;
        ++b;
    }
    return d;
}

template <class InputIt, class OutputIt, class UnaryPredicate>
OutputIt my_transform(InputIt b, InputIt e, OutputIt d, UnaryPredicate f) {
    while (b != e) {
        *d++ = f(*b);
        ++b;
    }
    return b;
}

template <class InputIt, class T>
T my_accumulate(InputIt b, InputIt e, const T value) {
    T v = value;
    while (b != e) {
        v += *b++;
    }
    return v;
}

template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 my_search(ForwardIterator1 b1, ForwardIterator1 e1,
                           ForwardIterator2 b2, ForwardIterator1 e2) {

    if (b2 == e2) return b1;

    while (b1 != e1) {
        ForwardIterator1 it1 = b1;
        ForwardIterator2 it2 = b2;
        while (*it1 == *it2) {
            if (it2 == e2) return b1;
            if (it1 == e1) return e1;
            ++it1;
            ++it2;
        }
        ++b1;
    }
    return e1;
}

// template <class ForwardIterator1, class ForwardIterator2>
// ForwardIterator1 my_search(ForwardIterator1 b1, ForwardIterator1 e1,
//                            ForwardIterator2 b2, ForwardIterator1 e2) {
//     while (b1 != e1) {
//         if (my_equal(b2, e2, b1)) return b1;
//     return e1;
// }

template <class ForwardIterator, class UnaryPredicate>
ForwardIterator my_partition(ForwardIterator b, ForwardIterator e, UnaryPredicate p) {
    while (b != e) {
        while (p(*b)) {
            ++b;
            if (b == e) return b;
    }
    do {
        --e;
        if (b == e) return b;
    } while (!p(*e));
    swap(*b, *e);
    ++b;
    }
    return b;
}

// template <class ForwardIterator, class Predicate>
// ForwardIterator my_partition(ForwardIterator b, ForwardIterator e, UnaryPredicate p) {
//   ForwardIterator first_fail = b;
//   for ( ;b != e; ++b) if (p(*b)) swap(*first_fail++, *b);
//   return first_fail;
// }



