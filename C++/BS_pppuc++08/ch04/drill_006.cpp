//Drill 006
#include <iostream>
#include <vector>

using namespace std;

int main() {
	double din = 0, smallest = 0, largest = 0;
	int wcount = 0;
	cout << "Finding the smallest and largest value so far.\n";
	cout << "Please enter a sequence of digits: \n";
	while(cin >> din){
		if(din == '|'){
			break;
		}
		else{
			if(wcount == 0){
				smallest = din;
				largest = din;
				cout << "# " << din << "\t\t" << "largest: " << largest << ", smallest: " << smallest << endl;
			}
			else if(wcount > 0){
				if(din < smallest){
					smallest = din;
					cout << "# " << din << "\t\t" << "largest: " << largest << ", smallest: " << smallest << endl;
				}
				else if(din > largest){
					largest = din;
					cout << "# " << din << "\t\t" << "largest: " << largest << ", smallest: " << smallest << endl;
				}
				else{
					cout << "# " << din << "\t\t" << "largest: " << largest << ", smallest: " << smallest << endl;
				}
			}
			++wcount;
		}
	}
	cout << "-----------------------------------------------------\n";
	cout << "The smallest values so far is: " << smallest << endl;
	cout << "The largest values so far is: " << largest << endl;
	cout << endl;
}