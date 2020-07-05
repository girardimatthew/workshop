#include <iostream>
using std::cout;
using std::endl;

int main() {
    // A pointer is a value that represents the address of an object
    // object => unique address => computer's memory that contains the object
    // & address operator
    // * dereference operator
    
    int x;
    int *p;     // *p has type int
    int* pp;    // p has type int*
    pp = &x;
    // but 

    int* ppp, q;    // what does this definition mean?
                    // ppp => an object of type "pointer to int"
                    // q => an object of type int
                    // this is easier to read as follows:
                    // int *p, q;
                    // or 
                    // int (*p), q;
                    // best way is, to make intentions crystal clear
    ppp = &q;
    // =========
    q = 3;
    int* q_clear = &q;
    cout << "q = " << q << endl; 
    cout << "ppp = " << ppp << endl;
    cout << "q_clear = " << q_clear << endl;
    cout << "*ppp = " << *ppp << endl;
    cout << "*q_clear = " << *q_clear << endl;
    *ppp += 1;
    cout << "q = " << q << endl; 
    cout << "ppp = " << ppp << endl;
    cout << "q_clear = " << q_clear << endl;
    cout << "*ppp = " << *ppp << endl;
    cout << "*q_clear = " << *q_clear << endl;

    int qq = 42;
    cout << "qq = " << qq << endl;
    // small program
    x = 5;
    // p points to x
    p = &x;
    cout << "x = " << x; 
    cout << ", p = " << p;
    cout << ", *p = " << *p;
    cout << endl;
    // change the value to x through p
    *p = 6;
    cout << "x = " << x; 
    cout << ", p = " << p;
    cout << ", *p = " << *p;
    cout << endl;
    // *p and x are two different ways of referring to the same object
    // pointer to an object ? 
    // think of it as an iterator that refers to the only 
    // element of the "container" that contains that object and 
    // nothing else.
    return 0;
}