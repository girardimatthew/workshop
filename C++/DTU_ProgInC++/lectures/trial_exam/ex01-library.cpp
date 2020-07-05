
#include <iostream>
#include <vector>
#include "ex01-library.h"
using namespace std;
// Exercise 1 (a)
// Check and correct if necessary
void display(double *A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
       for(unsigned int j = 0; j < n; j++){
           cout << A[i*n+j] << " ";
       }
       cout << endl;
    }
};
// Exercise 1 (b)
// Implement this function
void reset(double *A, unsigned int n, double x){
    // Put your code here
	for (unsigned int i=0; i<n*n; i++) {
		A[i] = x;
	}
};
// Exercise 1 (c)
// Implement this function
void reduce(double * A, unsigned int n){
    // Put your code here
    double * B = new double[n*n];

    for (unsigned i=0; i<n; i++) {
    	for (unsigned j=0; j<n; j++) {
    		B[i*n+j] = (i>0 ? A[(i-1)*n + j] : 0)
    		+ (j<(n-1) ? A[(i)*n + (j+1)] : 0)
    		+ (i<(n-1) ? A[(i+1)*n + (j)] : 0)
    		+ (j>0 ? A[i*n+(j-1)] : 0);
    	}
    }

    for (unsigned i=0; i<n; i++) {
    	for (unsigned j=0; j<n; j++) {
    		A[i*n+j] = B[i*n+j];
    	}
    }
};
// Exercise 1 (d)
// Implement this function
vector<double> sumRows(double * A, unsigned int n){
    // Put your code here
    vector<double> v (n,0);
    for (unsigned int i=0; i<n; i++) {
    	for (unsigned int j=0; j<n; j++) {
    		v[i] += A[i*n+j];
    	}
    }

    return v;
};

// Exercise 1 (e)
// Implement this function
vector<double> sumCols(double * A, unsigned int n) {
	// Put your code here
	vector<double> v (n,0);
	for (unsigned int i=0; i<n; i++) {
		for (unsigned int j=0; j<n; j++) {
			v[i] += A[j*n+i];
			//v[j] += A[i*n+j];
		}
	}
	return v;
};

// Do not modify
void print(vector<double> & v) {
	for(unsigned int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
};