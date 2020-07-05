#pragma once

#include <memory>
#include <algorithm>
#include <cstddef>
#include "iostream"

using std::max;

template <class T> class Vec { 
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vec() { create(); }                                     // constructors
    explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }
    Vec (const Vec& v) { create(v.begin(), v.end()); };       // copy constructor
    Vec& operator=(const Vec&);                             // the assignment operator
    ~Vec() { uncreate(); }                                  // the destructor

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& val);
    void clear();
    iterator erase(iterator position);

    // new operations: size and index
    size_type size() const { return avail - data; }

    // new functions to return iterators
    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    bool empty() const { return data == avail; }

private:
    iterator data;          // pointer to the first element in the Vec. first element in the Vec
    iterator avail;         // pointer to (one past) the last constructed element in the Vec
    iterator limit;         // points to (one past) the last available element (allocated memory)

    // facilities for memory allocation
    std::allocator<T> alloc;     // object to handle memory allocation

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    // check for self-assignment
    if (&rhs != this) {
        // free the array in the left-hand side
        uncreate();
        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create() { 
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> 
void Vec<T>::uncreate() {
    if (data) {
        // destroy (in reverse order) the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        
        // return all the space that was allocated
        alloc.deallocate(data, limit - data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
}

template <class T> 
void Vec<T>::grow()  { 
    // when growing, allocate twice as much space as currently in use
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    // return the old space, destroy the elements there 
    uncreate();
    // reset tpointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T> 
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

// push back operation
template <class T> 
void Vec<T>::push_back(const T& val) {
    if (avail == limit)     // get space if needed
        grow();
    unchecked_append(val);  // append the new element
}

// Removes all elements from the vector (which are destroyed)
// leaving the container with a size of 0.
template <class T> 
void Vec<T>::clear() {
    uncreate();
}

// Removes from the vector either a single element (position) 
// or a range of elements [first, last) 
// This effectively reduces the container size by the 
// number of elements removed, which are destroyed
//
// Return value:
// An iterator pointing to the new location of the element that 
// followed the last element erased by the function call. 
// This is the container end if the operation erased the last element in the sequence.
// Member type iterator is a random access iterator type that points to elements.
template <class T>
typename Vec<T>::iterator Vec<T>::erase(typename Vec<T>::iterator position) {
    if (data && position != avail) {
        std::cout << " > will destroy " << *position << std::endl;
        alloc.destroy(position);
        std::cout << " > destroyed " << *position << std::endl;
        iterator it = position + 1;

        while (it != avail) {
            std::cout << " !position " << *position << std::endl;
            alloc.construct(position++, *it++);
            alloc.destroy(position);
        }
        avail = position;
    }
    return avail;
}
