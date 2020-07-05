// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 5.7.0
// *********************************************************************************
// Logic errors
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
//#include "../std_lib_facilities_v2.h"

using namespace std;

int main() {

	const int lowest = -1000;
	const int highest = 1000;

	double temp = 0;
	double sum = 0;
	double high_temp = lowest;
	double low_temp = highest;
	int no_of_temps = 0;

	while (cin>>temp) {
		++no_of_temps;
		sum+=temp;
		if (temp>high_temp) high_temp = temp;
		if (temp<low_temp) low_temp = temp;
	}

	cout << "High temperature: " << high_temp << endl;
	cout << "Low temperature: " << low_temp << endl;
	cout << "Average temperature: " << sum/no_of_temps << endl;
}