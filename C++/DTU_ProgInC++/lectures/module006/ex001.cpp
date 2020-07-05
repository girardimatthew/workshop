// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod06
// Matteo Girardi
// *********************************************************************************
#include <iostream>

using namespace std;

class Fraction {
private:
    // Internal representation of a Fraction as two integers
    int numerator;
    int denominator;
    void check() {
    	int a = numerator;
    	int b = denominator;
    	while (a != b) {
    		if (a > b) {
    			a -= b;
    		} else {
    			b -= a;
    		}
    	}
    	numerator /= a;
    	denominator /=a;
    }
public:
    // Class constructor
    Fraction(int n, int d) { 
    	numerator = n;
    	denominator = d;
    };
    // Methods to update the Fraction    
    void add(Fraction &f) {
    	numerator = numerator*f.denominator + denominator*f.numerator;
    	denominator *= f.denominator;
    };
    void sub(Fraction &f) {
    	numerator = numerator*f.denominator - denominator*f.numerator;
    	denominator *= f.denominator;
    };
    void mult(Fraction &f) {
    	numerator *= f.numerator;
    	denominator *= f.denominator;
	};
    void div(Fraction f) {
    	numerator *= f.denominator;
    	denominator *= f.numerator;
    };
    // Display method
    void display(void) {
    	check();
    	cout << numerator << " / " << denominator << endl;
    };
};

int main() {

	int a, b, c, d;
	string f1, op, f2;
	int count = 0;

	while (count < 3) {
		cin >> a >> f1 >> b >> op >> c >> f2 >> d;
		Fraction fract1 (a,b);
		Fraction fract2 (c,d);
		if (op == "+") {
			fract1.add(fract2);
		}
		else if (op == "-") {
			fract1.sub(fract2);
		}
		else if (op == "*") {
			fract1.mult(fract2);
		}
		else if (op == "div") {
			fract1.div(fract2);
		}
		fract1.display();
		count += 1;
	}

	return 0;
}