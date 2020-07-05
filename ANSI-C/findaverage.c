//-------------------------------------------------
// Function in C. Simple example
// Find the average of integers
// passing by reference
//-------------------------------------------------
#include <stdio.h>

//-------------------------------------------------
// functions prototypes
//-------------------------------------------------
int main();
float findaverage(float *, float *);

//-------------------------------------------------
//
//-------------------------------------------------
float findaverage(float *a_p, float *b_p) {
	float average;
	average=(*a_p + *b_p)/2;
	return(average);
}

//-------------------------------------------------
//
//-------------------------------------------------
int main() {
	float a, b, result;
	printf("Enter a number: ");
	scanf("%f", &a);
	printf("Enter a number: ");
	scanf("%f", &b);
	
	result = findaverage(&a, &b);
	printf("var1: %f , var2: %f, Average=%f\n", a, b, result);
}
