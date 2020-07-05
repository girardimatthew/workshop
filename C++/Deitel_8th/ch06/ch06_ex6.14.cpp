// *******************************************************
// Deitel: C++ How to Program
// ch 06 ex 6.17
// Write a program that defines four functions to round a 
// number x in various way:
// *******************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const double PI = 3.14159;
const double X = 10.0;

// round a number to the nearest integer
template < typename T > 
T roundToInteger( const T x ) {
	return floor( x + .5 );
}

// round a number to the nearest tenth
template < typename T > 
T roundToTenths( const T x ) {
	return floor( x * 10 + .5 ) / 10;
}

// round a number to the nearest hundredth
template < typename T > 
T roundToHundredths( const T x ) {
	return floor( x * 100 + .5 ) / 100;
}

// round a number to the nearest thousandth
template < typename T > 
T roundToThousandths( const T x ) {
	return floor( x * 1000 + .5 ) / 1000;
}

int main() {
	srand( time( 0 ) );
	cout << setw( 10 ) << "Number" << setw( 17 ) << "Integer" << setw( 15 ) << "Tenth" << setw( 19 ) << "Hundredth" << setw( 20 ) << "Thousandth" << endl;
	cout << setw(11) << PI << setw(13) << roundToInteger(PI) << setw(18) << roundToTenths(PI) << setw(18) << roundToHundredths(PI) << setw(20) << roundToThousandths(PI) << endl;

	for (int i = 0; i < 20; ++i) {
		float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
		cout << setw(11) << r2 << setw(13) << roundToInteger(r2) << setw(18) << roundToTenths(r2) << setw(18) << roundToHundredths(r2) << setw(20) << roundToThousandths(r2) << endl;	
	}
}         