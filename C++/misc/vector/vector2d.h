#ifndef __v2d__
#define __v2d__

template <typename T>
class v2d {
private:
    // internal representation of a vector
    // with just two doubles x and y
    T x;
    T y;

public:
    // standard constructor
    // builds a vector (a,b)
    v2d(T a, T b);
    
    // copy constructor
    // builds a vector that is exactly as v
    v2d(const v2d & v);
    
    // // destructor
    ~v2d(void);
    
    // assignment
    // updates the vector to make it as v
    v2d<T> & operator=(const v2d<T> &v);
    
    // vector addition
    // updates the vector by adding v
    v2d<T> & operator+(const v2d<T> &v);
    
    // scalar multiplication
    // updates the vector by scaling by k
    v2d<T> & operator*(T k);
    
    // scalar product of the current vector
    // by another vector v 
    T operator*(const v2d &v);    
    
    // computes the length of a vector
    T length(void);

    // print the values (x,y) of a vector
    void print();

    // different implementation for test
    // print the values (x,y) of a vector
    void printvec(const v2d<T> &v);

    // get x value of a vector
    T getX();

    // get Y value of a vector
    T getY();
};

// including a file.cpp is not very appropriate..
#include "vector2d.cpp"

#endif
