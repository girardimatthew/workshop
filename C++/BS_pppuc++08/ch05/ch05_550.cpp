// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.5
// P. 137
// *********************************************************************************
// Run-time errors
// *********************************************************************************

#include <iostream>

using namespace std;

int area(int length, int width) {	// calculate area of a rectangle
	return length*width;
}

const int frame_width = 2;
int framed_area(int x, int y) {		// calculate area within frame
	return area(x-frame_width,y-frame_width);
}

int main() {
	int x = -1;
	int y = 2;
	int z = 4;
	//...
	int area1 = area(x,y);
	int area2 = framed_area(1,z);
	int area3 = framed_area(y,z);
	double ratio = double(area1)/area3;		// hardware-detected error

	cout << "area1: " << area1 << endl;
	cout << "area2: " << area2 << endl;
	cout << "area3: " << area3 << endl;
	cout << "ratio: " << ratio << endl;

	// the caller deals with errors
	if (x<=0) { 
		cout << "Non-positive x: " << x << "\n";
	}
	if (y<=0) { 
		cout << "Non-positive y: " << y << "\n";
	}
	area1 = area(x,y);
	cout << "area1: " << area1 << endl;

	if (x<=0 || y<=0) {
		cout << "Non-positive area() argument.\n";
	}
	cout << "area1: " << area(x,y) << endl;

	if (1-frame_width<=0 || z-frame_width<=0) {
		cout << "Non-positive 2nd area() argument called by framed_area().\n";
	}
	cout << framed_area(1,z) << endl;

	if (y-frame_width<=0 || z-frame_width<=0) {
		cout << "Non-positive area() argument called by framed_area().\n";
	}
	cout << framed_area(y,z) << endl;
}