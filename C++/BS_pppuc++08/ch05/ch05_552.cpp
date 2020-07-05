// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.5.2
// *********************************************************************************
// The callee deals with errors
// *********************************************************************************

#include <iostream>

using namespace std;

int area(int length, int width) {	// calculate area of a rectangle
	if (length<=0 || width<=0) {
		cout << "Non-positive area() arguments.\n";
	}
	return length*width;
}

int framed_area(int x, int y) {		// calculate area within frame
	const int frame_width = 2;
	if (x-frame_width<=0 || y-frame_width<=0) {
		cout << "Non-positive area() argument called by framed_area().\n";
	}
	return area(x-frame_width,y-frame_width);
}

int main() {
	int x = -1;
	int y = 2;
	int z = 4;
	// the callee deals with errors
	cout << "area1: " << area(x,y) << endl;
	cout << "area2: " << framed_area(1,z) << endl;
	cout << "area3: " << framed_area(y,z) << endl;
}