//Drill 003
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int in1, in2;
	cout << "Please enter a sequence of digits (0..9): \n";
	cout << "For instance, 1 2 or 4 5 6 7 or 45 69 23 14 \n";
	while(cin >> in1 >> in2){
		if(in1 == '|' || in2 == '|'){
			break;
		}
		else{
			if(in1 > in2){
				cout << "------------------------------------------\n";
				cout << "first input: " << in1 << endl;
				cout << "second input: " << in2 << endl;
				cout << "The smaller value is: " << in2 << endl;
				cout << "The larger value is: " << in1 << endl;

			}
			else if(in1 == in2){
				cout << in1 << " == " << in2 << ", the numbers are equal.\n";
			}
			else{
				cout << "------------------------------------------\n"; 
				cout << "first input: " << in1 << endl;
				cout << "second input: " << in2 << endl;
				cout << "The smaller value is: " << in1 << endl;
				cout << "The larger value is: " << in2 << endl;
			}
			cout << endl;
			cout << "Please enter a sequence of digits: \n";
		}
	}
	cout << endl;
}