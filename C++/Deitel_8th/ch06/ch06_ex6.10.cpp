#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

inline double sphereVolume( const double radius) {
	return (4.0/3.0)*PI*pow(radius, 3);
}

int main() {
	double radius;
	cout << "Enter the length of the radius of your sphere: ";
	cin >> radius;

	cout << "Volume of sphere with radius " << radius << " is " << sphereVolume(radius) << endl;
	
}