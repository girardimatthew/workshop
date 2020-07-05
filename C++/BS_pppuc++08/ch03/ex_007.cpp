#include <iostream>

using namespace std;

int main() {
	string s1, s2, s3;
	string min, max, mid;
	cout << "Please, enter three integer values: " << endl;
	cin >> s1 >> s2 >> s3;
	//cin >> i2;
	//cin >> i3;

	if (s1 >= s2 && s1 >= s3){ // 8 3 1 - 8 1 3 
		max = s1;
		if (s2 >= s3){
			mid = s2;
			min = s3;
		}
		else{
			mid = s3;
			min = s2;
		}
	}
	else if (s2 >= s1 && s2 >= s3){ // 1 9 4 - 4 9 2
		max = s2;
		if (s1 >= s3){
			mid = s1;
			min = s3;
		}
		else{
			mid = s3;
			min = s1;
		}
	}
	else {
		max = s3;
		if (s1 >= s2){
			mid = s1;
			min = s2;
		}
		else{
			mid = s2;
			min = s1;
		}
	}

	cout << min << ", " << mid << ", " << max << endl;
}
