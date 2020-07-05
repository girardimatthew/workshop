//Drill 002
#include <iostream>
#include <vector>

using namespace std;

//v0001

// int main() {
// 	int i=0;
// 	int temp, prevt;
// 	cout << "Please enter a sequence of digits (0..9): \n";
// 	cout << "For instance, 1 2 or 4 5 6 7 or 45 69 23 14 \n";
// 	while(cin>>temp){
// 		if(temp=='|'){
// 			break;
// 		}
// 		else{
// 			if(i==1){
// 				if (prevt > temp){
// 					cout << "------------------------------------------\n";
// 					cout << "first input: " << prevt << endl;
// 					cout << "second input: " << temp << endl;
// 					cout << "The smaller value is: " << temp << endl;
// 					cout << "The larger value is: " << prevt << endl;
// 				}
// 				else {
// 					cout << "------------------------------------------\n"; 
// 					cout << "first input: " << prevt << endl;
// 					cout << "second input: " << temp << endl;
// 					cout << "The smaller value is: " << prevt << endl;
// 					cout << "The larger value is: " << temp << endl;
// 				}
// 				i=0;
// 				cout << endl;
// 				cout << "Please enter a sequence of digits: \n";
// 			}
// 			else {
// 				prevt = temp;
// 				++i;
// 			}
// 		}
// 	}
// 	cout << endl;
// }

//v0002

int main() {
	int i=0;
	int in1, in2;
	cout << "Please enter a sequence of digits (0..9): \n";
	cout << "For instance, 1 2 or 4 5 6 7 or 45 69 23 14 \n";
	while(cin >> in1 >> in2){
		if(in1 == '|' || in2 == '|'){
			cout << "Quit.\n";
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