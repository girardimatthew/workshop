/*
 * File: vector2d.cpp
 * ---------------
 * This file implements the vector2d.h interface.
 * Class for two dimensional vectors, 
 * and mathematical operations on vectors.
 * Using templates
 */

// to compile: g++ test01.cpp

#include "vector2d.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * builds a vector (a,b)
 */
template <typename T>
v2d<T>::v2d(T a, T b) {
	x = a;
	y = b;
}

/*
 * Implementation notes: Copy constructor
 * ----------------------------------
 * builds a vector that is exactly as v
 */
template <typename T>
v2d<T>::v2d(const v2d & v) : x(v.x), y(v.y) {}

/*
 * Implementation notes: Print
 * ----------------------------------
 * print the values (x,y) of a vector
 */
template <typename T>
void v2d<T>::print() {
	cout << "(" << x << ", " << y << ")" << endl;
}

/*
 * Implementation notes: Printvec
 * ----------------------------------
 * print the values (x,y) of a vector
 * different implementation for test
 */
template <typename T>
void printvec(v2d<T> &v) {
    v2d<T> a(1, 0);
    v2d<T> b(0, 1);
    cout << '(' << v*a << ',' << v*b << ')';
}

/*
 * Implementation notes: Getters
 * ----------------------------------
 * get the value x of a vector
 */
template <typename T>
T v2d<T>::getX() {
	return x;
}

/*
 * Implementation notes: Getters
 * ----------------------------------
 * get the value x of a vector
 */
template <typename T>
T v2d<T>::getY() {
	return y;
}

/*
 * Implementation notes: Deconstructor
 * ----------------------------------
 */
template <typename T>
v2d<T>::~v2d(void) {}

/*
 * Implementation notes: Op. Assignement 
 * ----------------------------------
 * updates the vector to make it as v
 */
 
template <typename T>
v2d<T> & v2d<T>::operator=(const v2d<T> &v) {
	if (&v != this) {
		x=v.x;
		y=v.y;
	}
	return *this;
}

/*
 * Implementation notes: Vector addition 
 * ----------------------------------
 * updates the vector by adding v
 */
template <typename T>
v2d<T> & v2d<T>::operator+(const v2d<T> &v) {
	if (&v != this) {
		x+=v.x;
		y+=v.y;
	}
	return *this;
}


/*
 * Implementation notes: scalar multiplication 
 * ----------------------------------
 * updates the vector by scaling by k
 */
template <typename T>
v2d<T> & v2d<T>::operator*(T k) {
	x = x * k;
	y = y * k;
	return *this;
}


/*
 * Implementation notes: scalar product
 * ----------------------------------
 * scalar product of the current vector 
 * by another vector v 
 */
template <typename T>
T v2d<T>::operator*(const v2d &v) {
	T out = 0;
	if (&v != this) {
		out = x * v.x + y * v.y;
	}
	return out;
}    


/*
 * Implementation notes: Length
 * ----------------------------------
 * computes the length of a vector
 */
template <typename T>
T v2d<T>::length(void) {
	return sqrt((x * x) + (y * y));
}