// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 1
// P. 126
// *********************************************************************
// if we define the median of a sequence as 
// "the number for which exactly half of the element of the sequence
// come before it and exactly half come after it," 
// fix the program in §4.6.2 so that it always print out a median. 
// Hint: A median need not to be an element of the sequence.
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> temps;
	double temp, median;
	cout << "-------------------------------------------------------\n";
	cout << "Please enter several temperatures: \n";
	cout << "For instance, 15.5 6.0 4.5 3.33 \n";
	while(cin>>temp){
		temps.push_back(temp);
	}

	cout << "-------------------------------------------------------\n";
	cout << "The temperatues entered are: \n";
	for(int i = 0; i < temps.size(); ++i){
		cout << temps[i] << " ";
	}
	cout << endl;

	//compute mean temperature:
	double sum = 0;
	for(int i = 0; i<temps.size(); ++i){
		sum += temps[i];
	}
	cout << "Average temperature is: " << sum/temps.size() << '\n';
	cout << "-------------------------------------------------------\n";
	//compute median temperature:
	sort(temps.begin(), temps.end()); //sort temps from the beginning to the end
	cout << "The temperatues sorted are: " << endl;
	for(int i=0; i<temps.size(); ++i){
		cout << "temps[" << i << "] == " << temps[i] << endl;
	}
	cout << "-------------------------------------------------------\n";
	cout << "The total amount of values entered is: " << temps.size() << endl;
	if((temps.size()%2)==0){
		median = temps[temps.size()/2] + temps[((temps.size()/2)-1)];
		cout << "Median temperature is: " << median/2 << endl;
	}
	else{
		cout << "Median temperature is: " << temps[temps.size()/2] << endl;
	}
	cout << "The smallest temperature is: " << temps[0] << endl;
	cout << "The highest temperature is: " << temps[temps.size()-1] << endl;
	cout << "-------------------------------------------------------\n";
}