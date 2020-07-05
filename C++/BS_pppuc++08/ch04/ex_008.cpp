// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 8
// P. 126
// *********************************************************************
// There is an old story that the emperor wanted to thank the inventor of 
// the game of chess and asked the inventor to name his reward.
// The inventor asked for one grain of rice for the first square, 2 for the second,
// 4 for the third, and so on, doubling for each of the 64 squares.
// Write a program to calculate how many squares are required to give the inventor
// at least 1000 grains of rice, at least 1.000.000 grains, and at least 
// 1.000.000.000 grains.
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int first = 1000;
	const int second = 1000000;
	const int third = 1000000000;

	int sq_grains = 1;
	int ngrains = 1;
	int nsquares = 0;
	int totgr = 0;
	cout << "---------------------------------------------------------------\n";	
	while(totgr<=first){
		++nsquares;
		totgr+=sq_grains;
		sq_grains+=sq_grains;
	}
	cout << "To give the invetor at least " << first << " grains of rice\n";
	cout << "the squares needed are: " << nsquares << endl;
	cout << "total grains: " << totgr << endl;

	cout << "---------------------------------------------------------------\n";	
	while(totgr<=second){
		++nsquares;
		totgr+=sq_grains;
		sq_grains+=sq_grains;
	}
	cout << "To give the invetor at least " << second << " grains of rice\n";
	cout << "the squares needed are: " << nsquares << endl;
	cout << "total grains: " << totgr << endl;

	cout << "---------------------------------------------------------------\n";	
	while(totgr<=third){
		++nsquares;
		totgr+=sq_grains;
		sq_grains+=sq_grains;
	}
	cout << "To give the invetor at least " << third << " grains of rice\n";
	cout << "the squares needed are: " << nsquares << endl;
	cout << "total grains: " << totgr << endl;

}