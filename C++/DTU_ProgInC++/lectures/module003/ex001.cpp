// *********************************************************************************
// Programming in C++ 
// Exercise 001
// module 003
// Matteo Girardi
// *********************************************************************************
// Histogram
// *********************************************************************************

#include <iostream>
#include <math.h>

using namespace std;

struct hcore {
	int * counter;			
	double maxn;				// maximum number in the dataset
	int sizek;				// size of the intervals
};

hcore histogram(int l, int n) {

	hcore hist;
	hist.counter = new int[l];
	hist.maxn = 0;
	hist.sizek = 0;
	int * dataset = new int[n];
	// init dataset to zero
	for (int i=0; i<n; ++i) {
		dataset[i] = 0;
	}
	// store input values into dataset
	for (int i=0; i<n; ++i) {
		cin >> dataset[i];
		if (dataset[i]>=hist.maxn) hist.maxn=dataset[i];
	}
	// find the size of the intervals
	hist.sizek = ceil(hist.maxn/l);
	// init counter to zero
	for (int i=0; i<l; ++i) {
		hist.counter[i]=0;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<l; ++j) {
			if (dataset[i]>=hist.sizek*j && dataset[i]<=(hist.sizek*(j+1))-1) { hist.counter[j]++; }
		}
	}

	delete [] dataset;
	return hist;
};

int main() {
	int l = 0, n = 0;
	cin >> l >> n;

	hcore histo = histogram(l, n);

	for (int i=0; i<l; ++i) {
		cout << histo.sizek*i << ": " << histo.counter[i] << endl;
	}

	return 0;
}