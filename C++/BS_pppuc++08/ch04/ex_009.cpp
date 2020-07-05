// *********************************************************************************
// Bjarne Strousstrup
// Programming: Principles and Practice Using C++
// Ex 9
// P. 127
// *********************************************************************************
// Try to calculate the number of rice grains that the inventor 
// asked for (64 squares).
// You'll find that the number is so large that it won't fit
// in an int or double.
// Observe what happen when the number gets too large to represent as an int 
// and as a double.
// What is the largest number of squares for which 
// you can calculate the exact number of grains (using an int)?
// What is the largest number of squares for which
// you can calculate the approximate number of grains (using a double)?
// *********************************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main(){
	// *************************************************************************************
	// using int
	int sq_grains = 1;
	int nsquares = 1;
	int totgr = 0;
	cout << "-------------------------------------------------------------------\n";
	cout << "Uncomment the lines inside the while-loop to observe\n";
	cout << "what happen when the number gets too large to represent\n";
	cout << "as an int.\n";
	cout << "-------------------------------------------------------------------\n";
	while(nsquares<=31){
		//cout << "nsquares: " << nsquares << endl;
		//cout << "current grians for square n°" << nsquares <<" is " << sq_grains << endl;
		totgr+=sq_grains;
		//cout << "totgr: " << totgr << endl;
		sq_grains+=sq_grains;
		++nsquares;
		//cout << "---------------------------------------\n";
	}
	cout << "The largest number of squares for which you can calculate\n";
	cout << "the exact number of grains using an int is: " << nsquares-1 << endl;
	cout << "Total amout of grains: " << totgr << endl;
	cout << "-------------------------------------------------------------------\n";
	sq_grains = 1;
	nsquares = 1;
	totgr = 0;
	cout << "Beyond the largest number of squares the result is: \n";
	while(nsquares<=32){
		//cout << "nsquares: " << nsquares << endl;
		//cout << "current grians for square n°" << nsquares <<" is " << sq_grains << endl;
		totgr+=sq_grains;
		//cout << "totgr: " << totgr << endl;
		sq_grains+=sq_grains;
		++nsquares;
		//cout << "---------------------------------------\n";
	}
	cout << "The number of squares is: " << nsquares-1 << endl;
	cout << "Total amout of grains: " << totgr << endl;

	// *************************************************************************************
	// using double
	double dsq_grains = 1;
	double dnsquares = 1;
	double dtotgr = 0;
	cout << "-------------------------------------------------------------------\n";
	cout << "Uncomment the lines inside the while-loop to observe\n";
	cout << "what happen when the number gets too large to represent\n";
	cout << "as a double.\n";
	cout << "-------------------------------------------------------------------\n";
	while(dnsquares<=19){
		//cout << "nsquares: " << dnsquares << endl;
		//cout << "current grians for square n°" << dnsquares <<" is " << dsq_grains << endl;
		dtotgr+=dsq_grains;
		//cout << "totgr: " << dtotgr << endl;
		dsq_grains+=dsq_grains;
		++dnsquares;
		//cout << "---------------------------------------\n";
	}
	cout << "The largest number of squares for which you can calculate\n";
	cout << "the exact number of grains using an int is: " << dnsquares-1 << endl;
	cout << "Total amout of grains: " << dtotgr << endl;
	cout << "-------------------------------------------------------------------\n";
	dsq_grains = 1;
	dnsquares = 1;
	dtotgr = 0;
	cout << "Beyond the largest number of squares the result is: \n";
	while(dnsquares<=20){
		//cout << "nsquares: " << nsquares << endl;
		//cout << "current grians for square n°" << nsquares <<" is " << sq_grains << endl;
		dtotgr+=dsq_grains;
		//cout << "totgr: " << totgr << endl;
		dsq_grains+=dsq_grains;
		++dnsquares;
		//cout << "---------------------------------------\n";
	}
	cout << "The number of squares is: " << dnsquares-1 << endl;
	cout << "Total amout of grains: " << dtotgr << endl;
}