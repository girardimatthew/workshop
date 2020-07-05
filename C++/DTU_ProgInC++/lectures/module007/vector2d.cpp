/*
 * File: vector2d.cpp
 * ---------------
 * This file implements the vector2d.h interface.
 */

#include <string>
#include <iostream>
#include <math.h>
#include "vector2d.h"

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * builds a vector (a,b)
 */
v2d::v2d(double a, double b) {
	x = a;
	y = b;
}

/*
 * Implementation notes: Copy constructor
 * ----------------------------------
 * builds a vector that is exactly as v
 */
v2d::v2d(const v2d & v) : x(v.x), y(v.y) {
}

/*
 * Implementation notes: Print
 * ----------------------------------
 * print the values (x,y) of a vector
 */
// void v2d::print() {
// 	cout << "(" << x << ", " << y << ")" << endl;
// }


/*
 * Implementation notes: Deconstructor
 * ----------------------------------
 */
v2d::~v2d(void) {

}

/*
 * Implementation notes: Op. Assignement 
 * ----------------------------------
 * updates the vector to make it as v
 */
v2d & v2d::operator=(const v2d &v) {
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
v2d & v2d::operator+(const v2d &v) {
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
v2d & v2d::operator*(double k) {
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
double v2d::operator*(const v2d &v) {
	double out = 0;
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
double v2d::length(void) {
	return sqrt((x * x) + (y * y));
}