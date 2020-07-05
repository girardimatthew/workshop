/*
 * File: vect.cpp
 * ---------------
 * This file implements the vect.h interface.
 * Class for two dimensional vectors,
 * and mathematical operations on vectors.
 * Using templates
 */

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include "vect.h"

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * builds a N-dim vector (a[],N-dim)
 */
template <typename T>
Vect<T>::Vect(T &a[], int dim) {
	_size = dim;
	vector<T> m_v;
	for (int i=0; i<dim; ++i) {
		m_v.push_back(a[i]);
	}
}

/*
 * Implementation notes: Copy constructor
 * ----------------------------------
 * builds a vector that is exactly as v
 */
template <typename T>
Vect<T>::Vect(const Vect &v) : _size(v._size), m_v(v.m_v) {}

/*
 * Implementation notes: Print vector
 * ----------------------------------
 * print the values of a vector
 */
template <typename T>
void Vect<T>::printVect() {
	cout << "( ";
	for (int i=0; i<m_v.size(); ++i) {
		cout << m_v[i] << " ";
	}
	cout << ")" << endl;
}

/*
 * Implementation notes: Print
 * ----------------------------------
 * print the values (x,y) of a vector
 */
template <typename T>
int Vect<T>::getSize() {
	return _size;
}

/*
 * Implementation notes: Deconstructor
 * ----------------------------------
 */
template <typename T>
Vect<T>::~Vect(void) {}

/*
 * Implementation notes: Op. Assignement
 * ----------------------------------
 * updates the vector to make it as v
 */
template <typename T>
Vect<T> & Vect<T>::operator=(const Vect<T> &v) {
	if (&v != this) {
		for (int i=0; i<_size; ++i) {
			m_v[i]=v.m_v[i];
		}
	}
	return *this;
}

/*
 * Implementation notes: Vector addition
 * ----------------------------------
 * updates the vector by adding v
 */
template <typename T>
// vect<T> & vect<T>::operator+(const vect<T> &v) {
Vect<T> & Vect<T>::operator+(const Vect<T> &v) {
	if (&v != this) {
		for (int i=0; i<_size; ++i) {
			m_v[i]+=v.m_v[i];
		}
	}
	return *this;
}


/*
 * Implementation notes: scalar multiplication
 * ----------------------------------
 * updates the vector by scaling by k
 */
template <typename T>
Vect<T> & Vect<T>::operator*(T k) {
	for (int i=0; i<_size; ++i) {
		m_v[i]*=k;
	}
	return *this;
}


/*
 * Implementation notes: scalar product
 * ----------------------------------
 * scalar product of the current vector
 * by another vector v
 */
template <typename T>
T Vect<T>::operator*(const Vect<T> &v) {
	T out = 0;
	if (&v != this) {
		for (int i=0; i<_size; ++i) {
			out+=m_v[i] * v.m_v[i];
		}
	}
	return out;
}


/*
 * Implementation notes: Length
 * ----------------------------------
 * computes the length of a vector
 */
template <typename T>
T Vect<T>::length(void) {
	T out = 0;
	T mul = 0;
	for (int i=0; i<m_v.size(); ++i) {
		mul=m_v[i]*m_v[i];
		out+=mul;
	}
	return sqrt(out);
}
