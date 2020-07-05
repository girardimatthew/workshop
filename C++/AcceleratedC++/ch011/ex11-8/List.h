#pragma once

#include <memory>
#include <algorithm>
#include <cstddef>
#include "iostream"

using std::max;

template <class T> 
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : data(0), next(0), prev(0) {};
    Node(T d) : data(d), next(0), prev(0) {};
};

template <class T>
class NodeIterator {
public:
    NodeIterator(Node<T>* d) : data(d) {};
private:
    Node<T>* data;
};

template <class T> 
class List { 
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    List() { create(); }                                     // constructors
    explicit List(std::size_t n, const T& val = T()) { create(n, val); }
    List (const List& v) { create(v.begin(), v.end()); };       // copy constructor
    List& operator=(const List&);                             // the assignment operator
    ~List() { uncreate(); }                                  // the destructor

    //T& operator[](size_type i) { return data[i]; }
    //const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& val);
    void clear();
    //iterator erase(iterator position);

    // new operations: size and index
    //size_type size() const { return tail - head; }

    // new functions to return iterators
    iterator begin() { return head->data; }
    const_iterator begin() const { return head->data; }

    iterator end() { return tail->data; }
    const_iterator end() const { return tail->data; }

    bool empty() const { return head == tail; }

    void print();

private:
    Node<T>* head;          // pointer to the first element in the List. first element in the List
    Node<T>* tail;          // pointer to (one past) the last constructed element in the List

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T& val);
};

template <class T>
void List<T>::print() {
    if (head == 0) {
        std::cout << "head is 0.";
        return;
    }
    Node<T>* h = head;
    while (h) {
        std::cout << h->data << " ";
        h = h->next;
    }
    std::cout << endl;
}

template <class T>
List<T>& List<T>::operator=(const List& rhs) {
    // check for self-assignment
    // if (&rhs != this) {
    //     // free the array in the left-hand side
    //     uncreate();
    //     // copy elements from the right-hand to the left-hand side
    //     create(rhs.begin(), rhs.end());
    // }
    // return *this;
}

template <class T>
void List<T>::create() { 
    head = tail = 0;
}

template <class T> void List<T>::create(size_type n, const T& val) {
    // data = alloc.allocate(n);
    // limit = avail = data + n;
    // std::uninitialized_fill(data, limit, val);
}

template <class T>
void List<T>::create(const_iterator i, const_iterator j) {
    // data = alloc.allocate(j - i);
    // limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> 
void List<T>::uncreate() {
    if (head) {
        // destroy (in reverse order) the elements that were constructed
        iterator it = tail->prev;
        while (it != head)
            alloc.destroy(--it);
        
        // return all the space that was allocated
        alloc.deallocate(head, limit - head);
    }
    // reset pointers to indicate that the List is empty again
    head = limit = tail = 0;
}

template <class T> 
void List<T>::grow()  { 
    // // when growing, allocate twice as much space as currently in use
    size_type new_size = max(2 * (limit - head), ptrdiff_t(1));
    // // allocate new space and copy existing elements to the new space
    iterator new_head = alloc.allocate(new_size);
    iterator new_tail = std::uninitialized_copy(head, tail, new_head);
    // // return the old space, destroy the elements there 
    uncreate();
    // // reset tpointers to point to the newly allocated space
    head = new_head;
    tail = new_tail;
    limit = head + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T> 
void List<T>::unchecked_append(const T& val) {
    alloc.construct(tail++, val);
}

// push back operation
template <class T> 
void List<T>::push_back(const T& val) {
    if (head == limit)     // get space if needed
        grow();
    unchecked_append(val);  // append the new element
}

// Removes all elements from the Listtor (which are destroyed)
// leaving the container with a size of 0.
template <class T> 
void List<T>::clear() {
    uncreate();
}

// Removes from the Listtor either a single element (position) 
// or a range of elements [first, last) 
// This effectively reduces the container size by the 
// number of elements removed, which are destroyed
//
// Return value:
// An iterator pointing to the new location of the element that 
// followed the last element erased by the function call. 
// This is the container end if the operation erased the last element in the sequence.
// Member type iterator is a random access iterator type that points to elements.
// template <class T>
// typename List<T>::iterator List<T>::erase(typename List<T>::iterator position) {
    // if (data && position != avail) {
    //     std::cout << " > will destroy " << *position << std::endl;
    //     alloc.destroy(position);
    //     std::cout << " > destroyed " << *position << std::endl;
    //     iterator it = position + 1;

    //     while (it != avail) {
    //         std::cout << " !position " << *position << std::endl;
    //         alloc.construct(position++, *it++);
    //         alloc.destroy(position);
    //     }
    //     avail = position;
    // }
    // return avail;
// }
