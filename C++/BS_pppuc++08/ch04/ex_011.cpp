// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 11
// P. 127
// *********************************************************************************
// Create a program to find all the prime numbers between 1 and 100. 
// One way to do this is to write a function that will check if a number is prime 
// (i.e., see if the number can be divided by a prime number smaller than it­ self) 
// using a vector of primes in order (so that if the vector is called 
// primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). 
// Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, 
// and stores each prime found in a vector. Write another loop that lists the primes you found. 
// You might check your result by comparing your
// vector of prime numbers with primes. Consider 2 the first prime.
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

	for (int i=1; i<100; ++i) {
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