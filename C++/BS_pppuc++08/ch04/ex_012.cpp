// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 12
// P. 127
// *********************************************************************************
// Modify the program described in the previous exercise to take an input
// value max and then find all prime numbers from 1 to max.
// *********************************************************************************

#include <iostream>
#include <vector>

using namespace std;

int isprime(int i) {
	int first;
	vector<int> primes(25);
	primes[0]=2; primes[1]=3; primes[2]=5; primes[3]=7; primes[4]=11; primes[5]=13; 
	primes[6]=17; primes[7]=19; primes[8]=23; primes[9]=29; primes[10]=31; 
	primes[11]=37; primes[12]=41; primes[13]=43; primes[14]=47; primes[15]=53; 
	primes[16]=59; primes[17]=61; primes[18]=67; primes[19]=71; primes[20]=73; 
	primes[21]=79; primes[22]=83; primes[23]=89; primes[24]=97;

	if (i==1) {
		return 0;
	}
	else if (i==2) {
		return 1;
	}
	else {
		for (int j=0; primes[j]<i; ++j) {
			if ((i%primes[j])==0){
				first = 0;
				break;
			}
			else {
				first = 1;
			}
		}
		if (first==0){
			return 0;
		}
		else {
			return 1;
		}
	}
}

int main() {
	vector<int> fprimes;
	int check;
	int max;

	cout << "*** Searching prime numbers ***\n";
	cout << "Please enter a value so that the program will find prime numbers from 1 to value.\n";
	cout << "However the value should not exeed 100.\n";
	cin >> max;

	for (int i=1; i<=max; ++i) {
		check = isprime(i);
		if (check==1){
			fprimes.push_back(i);
		}
		else{
			;
		}
	}

	for (int i=0; i<fprimes.size(); ++i) {
		cout << "fprimes[" << i << "]: " << fprimes[i] << endl;
	}
}