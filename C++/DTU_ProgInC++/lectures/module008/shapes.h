#ifndef __Shape__
#define __Shape__

class Shape {
protected:
	double m_x;
public:
	Shape(double x);
	virtual double area() {};
	virtual double perimeter() {};
	virtual double height() {};
	virtual double width() {};
	virtual void rotate() {};
};


class Circle : public Shape {
public:
	Circle(double x);
	virtual double area();
	virtual double perimeter();
	virtual double height();
	virtual double width();
	virtual void rotate();

};


class Quadrilateral : public Shape {
protected:
	double m_y;
public:
	Quadrilateral(double x, double y);
	virtual double height();
	virtual double width();
	virtual void rotate();
};


class Rectangle : public Quadrilateral {
public:
	Rectangle(double x, double y);
	virtual double area();
	virtual double perimeter();
};


class Square : public Quadrilateral {
public:
	Square(double x);
	virtual double area();
	virtual double perimeter();
};

#endif