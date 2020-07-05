#include <iostream>

using namespace std;

int main() {
	const double pi = 3.14159265359;
	const int max = 17;

	int val = 19;
	int r = 3;
	int v = 2*pi/r;
	double rd = 3.0;
	double vd = 2*pi/rd;

	cout << "pi: " << pi << ", r: " << r << ", v: " << v << ", vd: " << vd << endl;
	cout << "max+2: " << max+2 << " // a constant expression (a const int plus a literal)" << endl;
	cout << "val+2: " << val+2 << " // not a constant expression: it uses a variable" << endl;
}