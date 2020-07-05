//Drill 005
#include <iostream>
#include <vector>

using namespace std;

int main() {
	double in1, in2;
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
				if ((in1 - in2) < (1.0/10000000)){
					cout << "The numbers are almost equal!" << endl;
				}

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
				if((in1 - in2) < (1.0/10000000)){
					cout << "The numbers are almost equal!" << endl;
				}
			}
			cout << endl;
			cout << "Please enter a sequence of digits: \n";
		}
	}
	cout << endl;
}