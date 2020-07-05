// simple and basic pointers example
#include <iostream>

using namespace std;

void ptr_op(int &x, int &y) {
	cout << "--------- ptr_op -------------\n";
	int tmp = x;
	x = y;
	y = tmp;
};

void printing(int &x, int &y, int *p1, int *p2) {
	cout << "--------- printing -------------\n";
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "*p1: " << *p1 << endl;
	cout << "*p2: " << *p2 << endl;
};

int main() {
	int x, y;
	int *p1, *p2;
	// init some variables
	x = -42;
	y = 163;
	// address of some integer objetcs
	p1 = &x;		
	p2 = &y;

	printing(x,y,p1,p2);
	// another name for the variable x
	*p1 -= 5;
	printing(x,y,p1,p2);
	*p1 = 17;
	printing(x,y,p1,p2);
	// copy the value in the variable p2 into variable p1. 
	// pointer assignment. makes p1 and p2 point to the same location.
	p1 = p2;
	printing(x,y,p1,p2);
	// value assignment. copy the value fromt the memory location 
	// addressed by p2 into the location addressed by p1.
	*p1 = *p2;
	printing(x,y,p1,p2);

	ptr_op(x,y);
	printing(x,y,p1,p2);
}