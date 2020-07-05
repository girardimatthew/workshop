#include <iostream>

using namespace std;

struct employeeRecordT {
	string name;
	string title;
	string ssnum;
	double salary;
	int withholding;
};

employeeRecordT empRec = {
	"Ebenezer Scrooge",
	"Partener",
	"271-82-8183",
	250.00,
	1
};

int main() {
	employeeRecordT *empPtr;
	empPtr = &empRec;
	// too much cumbersome, less convenient!
	cout << (*empPtr).salary << endl;
	// dereferencing and selecting operation into a single operator.
	cout << empPtr->salary << endl;

}