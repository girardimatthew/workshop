#pragma once

#include <iostream>

using std::cout;
using std::endl;

// Basic structure to store elements of a list
template <class T>
struct Node {
    T val;          // contains the value
    Node<T> * next;    // pointer to the next element in the list
    Node<T> * prev;    // pointer to the previous element in the list
};

// Class List
template <class T>
class List {
    
public:
    List(void);                 // Constructor
    ~List(void);                // Destructor
    void push_back(T n);        // This should insert n in the list
    void reverse(void);         // This should reverse the list

    void clear();

    void print(void);           // This should print the list
    // useless: just for fun
    void printLast(void);
    void printBackward(void);

    bool empty() const { return first == last; }
    
private:
    Node<T> * first;               // Pointer to the first (if any) element in the list
    Node<T> * last;

    void uncreate(void);
};

// Default Constructor
template <class T>
List<T>::List(void) {
    first = last = 0;
}

// Destructor
template <class T>
List<T>::~List(void) {
    uncreate();
}

template <class T>
void List<T>::uncreate(void) {
    while (!(first == 0)) {    
        Node<T> * tmp = first;
        first = first->next;
        delete tmp;
    }
    first = last = 0;
}

// This should insert n at the end of list
template <class T>
void List<T>::push_back(T n) {
    Node<T> * tmp = new Node<T>;
    if (first == 0 && last == 0) {
        tmp->val = n;
        tmp->next = NULL;
        tmp->prev = NULL;
        first = tmp;
        last = first;
    } else {
        tmp->val = n;
        last->next = tmp;
        tmp->prev = last;
        tmp->next = NULL;
        last = tmp;
    }
}

template <class T>
void List<T>::clear(void) {
    uncreate();
}

// This should reverse the list
template <class T>
void List<T>::reverse(void) {
    if (first==0) {
        return;
    }
    Node<T> * q = first;
    while (q) {
        Node<T> * w = q->prev;
        q->prev = q->next;
        q->next = w;
        q = q->prev;
    }
    Node<T> * s = new Node<T>;
    s = first;
    first = last;
    last = s;
}

// This should print the list
template <class T>
void List<T>::print(void) {
    if (first == 0) {
        return;
    }
    Node<T> * p = first;
    while (p) {
        // cout << p << endl;
        cout << p->val << " ";
        // cout << p->val << endl;
        // cout << p->next << endl;
        // cout << p->prev << endl;
        p = p->next;
        // cout << "--------" << endl;
    }
    cout << endl;
}

// This should print the list
template <class T>
void List<T>::printLast(void) {
    cout << last->val << endl;
}

template <class T>
void List<T>::printBackward(void) {
    if (first == 0) {
        return;
    }
    Node<T> * p = last;
    while (p) {
        // cout << p << endl;
        cout << p->val << " ";
        // cout << p->val << endl;
        // cout << p->next << endl;
        // cout << p->prev << endl;
        p = p->prev;
        // cout << "--------" << endl;
    }
    cout << endl;
}
