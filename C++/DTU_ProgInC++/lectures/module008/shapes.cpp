/*
 * File: shapes.cpp
 * ---------------
 * This file implements the shapes.h interface.
 */

#include <string>
#include <iostream>
#include <math.h>
#include "shapes.h"

using namespace std;

/* ---------------
 * Shapes
 * ---------------
 */

 Shape::Shape(double x) : m_x(x) {};

/* ---------------
 * Circle
 * ---------------
 */
Circle::Circle(double x) : Shape(x) {};

double Circle::area() {
	return M_PI * (m_x * m_x);
};

double Circle::perimeter() {
	return 2 * M_PI * m_x;
};

double Circle::height() {
	return 2*m_x;
};

double Circle::width() {
	return 2*m_x;
};

void Circle::rotate() {
};

/* ---------------
 * Quadrilateral
 * ---------------
 */

Quadrilateral::Quadrilateral(double x, double y) : Shape(x), m_y(y) {};

double Quadrilateral::height() {
 	return m_x;
};

double Quadrilateral::width() {
 	return m_y;
};

void Quadrilateral::rotate() {
	double tmp;
	tmp = m_x;
	m_x = m_y;
	m_y = tmp;
};

/* ---------------
 * Rectangle
 * ---------------
 */

Rectangle::Rectangle(double x, double y) : Quadrilateral(x,y) {};

double Rectangle::area() {
 	return m_x * m_y;
};

double Rectangle::perimeter() {
 	return 2*(m_x+m_y);
};

/* ---------------
 * Square
 * ---------------
 */

Square::Square(double x) : Quadrilateral(x,x) {};

double Square::area() {
	return m_x*m_x;
};

double Square::perimeter() {
	return 4*m_x;
};