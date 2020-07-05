//Drill 007 and 008 and 009
#include <iostream>
#include <vector>

using namespace std;

int main() {
	double din = 0.0, smallest = 0.0, largest = 0.0;
	double toMeter = 0.0;
	double sum = 0.0;
	int wcount = 0;
	string unit = "a";
	
	cout << "---------------------------------------------------------\n";
	cout << "Please enter a sequence of digits followed by a unit: \n";
	cout << "For instance, 10 cm, 2.5 in, 5 ft, 3.33 m \n";
	cout << "Legal units are: cm, in, ft, m. \n";
	cout << endl;
	while(cin >> din >> unit){
		if(din == '|'){
			break;
		}
		else{
			if(wcount == 0){
				if(unit == "cm")
					toMeter = din*0.01;
				else if(unit == "in")
					toMeter = din*0.254;
				else if(unit == "ft")
					toMeter = din*0.3048;
				else if(unit == "m")
					toMeter = din;
				else{
					cout << "Bad input. Unkown unit detected > " << unit << "\n";
					break;
				}
				smallest = toMeter;
				largest = toMeter;
				cout << "#" << wcount+1 << "°n \t" << din << unit << " == " << toMeter << "m\n";
				cout << "\t\t" << "largest: " << largest << "m, smallest: " << smallest << "m" << endl;
				cout << endl;
			}
			else if(wcount > 0){
				if(unit == "cm")
					toMeter = din*0.01;
				else if(unit == "in")
					toMeter = din*0.254;
				else if(unit == "ft")
					toMeter = din*0.3048;
				else if(unit == "m")
					toMeter = din;
				else{
					cout << "Bad input. Unkown unit detected > " << unit << "\n";
					break;
				}
				if(toMeter < smallest){
					smallest = toMeter;
				}
				else if(toMeter > largest){
					largest = toMeter;
				}
				else{
				}
				cout << "#" << wcount+1 << "°n \t" << din << unit << " == " << toMeter << "m\n";
				cout << "\t\t" << "largest: " << largest << "m, smallest: " << smallest << "m" << endl;
				cout << endl;
			}
			++wcount;
			sum += toMeter;
		}
	}
	cout << "-----------------------------------------------------\n";
	cout << "The smallest values so far is: " << smallest << "m" << endl;
	cout << "The largest values so far is: " << largest << "m" << endl;
	cout << "The total amount of values entered is: " << wcount << endl;
	cout << "The sum of values is: " << sum << "m" << endl;
	cout << endl;
}