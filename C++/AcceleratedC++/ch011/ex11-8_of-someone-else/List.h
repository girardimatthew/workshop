#pragma once

#include <memory>
// #include <algorithm>
// #include <cstddef>
// #include "iostream"

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

    NodeIterator& operator++();
    NodeIterator& operator--();
    bool operator!=(NodeIterator&) const;

private:
    Node<T>* data;
};

template <class T>
NodeIterator<T>& NodeIterator<T>::operator++() {
    data = data->next;
    return *this;
}

template <class T>
NodeIterator<T>& NodeIterator<T>::operator--() {
    data = data->prev;
    return *this;
}

template <class T>
bool NodeIterator<T>::operator!=(NodeIterator& rhs) const {
    return *this->data != rhs.data;
}

template <class T> 
class List { 
public:
    typedef NodeIterator<T> iterator;
    typedef const NodeIterator<T> const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    List() { create(); }                                     // constructors
    explicit List(size_type s, const T& val = T()) { create(s, val); }
    List(const List& l) { create(l.begin(), l.end()); };       // copy constructor
    List& operator=(const List&);                             // the assignment operator
    ~List() { uncreate(); }                                  // the destructor

    void push_back(const T& val);
    void clear();

    // new operations: size and index
    size_type size() const { return s; }

    // new functions to return iterators
    iterator begin() { return iterator(head); }
    const_iterator begin() const { return iterator(head); }

    iterator end() { return iterator(0); }
    const_iterator end() const { return iterator(0); }

    bool empty() const { return head == tail; }

    void print();

private:
    Node<T>* head;          // pointer to the first element in the List. first element in the List
    Node<T>* tail;          // pointer to (one past) the last constructed element in the List
    size_type s;

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    // destroy the elements in the array and free the memory
    void uncreate();
    // 
    void append(const T&);
};

template <class T>
List<T>& List<T>::operator=(const List& rhs) {
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
void List<T>::create() { 
    head = tail = 0; 
    s = 0;
}

template <class T> void List<T>::create(size_type s, const T& val) {
    for (size_type i = 0; i < s; i++)
        append(val);
}

template <class T>
void List<T>::create(const_iterator i, const_iterator j) {
    while (i != j)
        append(*i++);
}

template <class T>
void List<T>::append(const T& t) {
    Node<T>* node = new Node<T>(t);
    if (s == 0) {
        head = node;
    } else if (s == 1) {
        node->prev = head;
        tail = node;
        head->next = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    s++;
}

template <class T> 
void List<T>::uncreate() {    
    Node<T>* node = tail;
    while (node != 0) {
        Node<T>* node_delete = node;
        node = node->prev;
        delete node_delete;
    }
    head = tail = 0;
    s = 0;
}

// push back operation
template <class T> 
void List<T>::push_back(const T& val) {
    append(val);  // append the new element
}

// Removes all elements from the Listtor (which are destroyed)
// leaving the container with a size of 0.
template <class T> 
void List<T>::clear() {
    uncreate();
}

template <class T>
void List<T>::print() {
    if (head == 0) { // empty()
        return;
    }
    Node<T>* h = head;
    while (h) {
        std::cout << h->data << " ";
        h = h->next;
    }
    std::cout << endl;
}