#include <iostream>
#include "ex04-library.h"

using namespace std;

// Exercise 4 (a)
template <class C>
Monoid<C>::Monoid(C constant){
    // Put your code here
    this->constant = constant;
    m1 = nullptr;
    m2 = nullptr;
}

// Exercise 4 (b)
template <class C>
Monoid<C>::Monoid(Monoid<C> & m1, Monoid<C> & m2){
    // Put your code here
    this->m1 = new Monoid<C>(m1);
    this->m2 = new Monoid<C>(m2);
}

// Exercise 4 (c)
template <class C>
Monoid<C>::Monoid(Monoid & m){
    // Put your code here
    if (m.m1 == nullptr){
        constant = m.constant;
        m1 = nullptr;
        m2 = nullptr;
        return;
    }
    m1 = new Monoid(* m.m1);
    m2 = new Monoid(* m.m2);
}

// Exercise 4 (d)
template <class C>
Monoid<C> Monoid<C>::operator*(Monoid<C> & m){
    // Put your code here
    Monoid<C> m1(* this,m);
    return m1;
}

// Exercise 4 (e)
template <class C>
C Monoid<C>::eval(C (*f)(C,C)){
    // Put your code here
    if (m1 == nullptr) return constant;
    else return f(m1->eval(f),m2->eval(f));
}

// Do not modify
template <class C>
void Monoid<C>::print(void){
    if (m1 == nullptr) cout << constant ;
    else {
        m1->print();
        cout << " * " ;
        m2->print();
    }
}

// Do not modify
template class Monoid<string>;
template class Monoid<unsigned int>;
