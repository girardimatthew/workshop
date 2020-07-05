#ifndef __vect__
#define __vect__

#include <vector>

using namespace std;

template <typename T>
class Vect {
private:
    // internal representation of a vector
    // with just two doubles x and y
    int _size;
    vector<T> m_v;

public:
    // standard constructor
    // builds a vector (a,b)
    Vect(T &a[], int dim);

    // copy constructor
    // builds a vector that is exactly as v
    Vect(const Vect & v);
    
    // destructor
    ~Vect(void);
    
    // assignment
    // updates the vector to make it as v
    Vect<T> & operator=(const Vect<T> &v);
    
    // vector addition
    // updates the vector by adding v
    Vect<T> & operator+(const Vect<T> &v);
    
    // scalar multiplication
    // updates the vector by scaling by k
    Vect<T> & operator*(T k);
    
    // scalar product of the current vector
    // by another vector v
    T operator*(const Vect &v);
    
    // computes the length of a vector
    T length(void);
    
    // print the values (x,y) of a vector
    void printVect();
    
    // get x value of a vector
    int getSize();
};

// including a file.cpp is not very appropriate..
#include "vect.cpp"

#endif
