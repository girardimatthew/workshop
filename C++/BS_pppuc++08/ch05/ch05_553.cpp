// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.5.3
// *********************************************************************************
// Error reporting
// *********************************************************************************

#include <iostream>

using namespace std;

int area(int length, int width) {
	if (length<=0 || width<=0) return -1;
	return length*width;
}

int framed_area(int x, int y) {		// calculate area within frame
	const int frame_width = 2;
	if (x-frame_width<=0 || y-frame_width<=0) {
		cout << "Non-positive area() argument called by framed_area().\n";
		exit(1);
	}
	return area(x-frame_width,y-frame_width);
}

int main() {
	int x, y, z;
	cout << "Please enter three values for x, y and z. (exit: ctrl+c)\n";
	while (cin>>x>>y>>z) {
		cout << "x:" << x << ", y:" << y << ", z:" << z << endl;
		int area1 = area(x,y);
		if (area1<=0) {
			cout << "Non-positive area.\n";
		}
		int area2 = framed_area(x,z);
		int area3 = framed_area(x,y);
		double ratio = double(area1)/area3;

		cout << "area1: " << area1 << endl;
		cout << "area2: " << area2 << endl;
		cout << "area3: " << area3 << endl;
		cout << "ratio: " << ratio << endl;
	}
}