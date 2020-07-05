// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03 
// 3.4 - Operations and Operators
// P. 66

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	// int count;
	// string name;

	// cout << "Enter value for count: " << endl;
	// cin >> count;
	// cout << "Enter string: " << endl;
	// cin >> name;

	// int c2 = count+2;
	// string s2 = name + " Jr.";

	// int c3 = count-2;
	// //string s3 = name - " Jr. ";				// error: - isn't defined for strings

	// cout << " --------------------------------------- " << endl;
	// cout << "cout: " << count << endl;
	// cout << "name: " << name  << endl;
	// cout << "c2: " << c2 << endl;
	// cout << "s2: " << s2 << endl;
	// cout << "c3: " << c3 << endl;
	// s2 += " is from Chicago!";
	// cout << "s2: " << s2 << endl;

	// cout << " ----------------------------------------- " << endl;
	// cout << " simple program to exercise operators " << endl;

	// cout << "Please enter a floating-point value: ";
	// double n;
	// cin >> n;
	// cout << "Please enter a interger value: ";
	// int x;
	// cin >> x;
	// cout << "n == " << n << ", x == " << x
	// 	 << "\nn+1 == " << n+1 << ", x+1 == " << x+1
	// 	 << "\nthree times n == " << 3*n << ", three times x == " << 3*x
	// 	 << "\ntwice n == " << n+n << ", twice x == " << x+x
	// 	 << "\nn squared == " << n*n << ", x squared == " << x*x
	// 	 << "\nhalf of n == " << n/2 << ", half of x == " << x/2
	// 	 << "\nsquare root of n == " << sqrt(n) << ", square root of x == " << sqrt(double(x))
	// 	 << endl;
	
	// cout << " -------------------------------------------------------- " << endl;
	// cout << " modulo operators example 1" << endl;

	// for (int i = 0; i < 10; ++i) {
	// 	cout << "i == " << i << ", modulo == " << i%2 << endl;
	// }

	// cout << " -------------------------------------------------------- " << endl;
	// int a, b;
	// a = 5;
	// b = 8;
	// cout << "a == " << a << ", b == " << b << endl;
	// cout << "a/b * b + a\%b == a >> " << a/b * b + a%b << endl;

	cout << " ---------------------------------------------------------- " << endl;
	cout << " String comparison - read and compare names" << endl;

	cout << " Please enter two name\n";
	string first, second;

	cin >> first >> second;
	if (first == second) cout << "That's the same name twice\n";
	if (first < second)
		cout << first << " is alphabetically before " << second << endl;
	if (first > second) 
		cout << first << " is alphabetically after " << second << endl;

}