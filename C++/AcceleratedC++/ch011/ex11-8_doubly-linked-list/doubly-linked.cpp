#include <iostream>
#include "doubly-linked.h"

using std::cout;

Node * last = new Node;

// Default Constructor
List::List(void) {
    first = 0;
}

// Destructor
List::~List(void) {
    while (!(first == 0)) {    
        Node * tmp = first;
        first = first->next;
        delete tmp;
    }
}

// This should insert n at the end of list
//void List::insert(int n) {
void List::push_back(int n) {
    Node * tmp = new Node;
    if (first == 0) {
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

// This should reverse the list
void List::reverse(void) {
    if (first==0) {
        return;
    }
    Node * q = first;
    while (q) {
        Node * w = q->prev;
        q->prev = q->next;
        q->next = w;
        q = q->prev;
    }
    Node * s = new Node;
    s = first;
    first = last;
    last = s;
}

// This should print the list
void List::print(void) {
    if (first==0) {
        return;
    }
    Node * p = first;
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