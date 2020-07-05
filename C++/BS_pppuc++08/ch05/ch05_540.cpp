// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.4
// P. 137
// *********************************************************************************
// Link-time errors
// *********************************************************************************

#include <iostream>

using namespace std;

int area(int length, int width);	//calculate area of a rectangle
// int area(int length, int width) {	//calculate area of a rectangle
// 	return length*width;
// }

double area_double(double x, double y);	//calculate area of a rectangle
// double area_double(double x, double y) {
// 	return x*y;
// }

int area(int x, int y, char unit);	//calculate area of a rectangle

int main() {
	int x = area(2,3);
	cout << "area: " << x << endl;
	cout << "area: " << area_double(3.3,2.1) << endl;
}