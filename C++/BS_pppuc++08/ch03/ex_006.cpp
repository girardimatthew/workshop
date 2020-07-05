#include <iostream>

using namespace std;

int main() {
	int i1, i2, i3;
	int min, max, mid;
	cout << "Please, enter three integer values: " << endl;
	cin >> i1 >> i2 >> i3;
	//cin >> i2;
	//cin >> i3;

	if (i1 >= i2 && i1 >= i3){ // 8 3 1 - 8 1 3 
		max = i1;
		if (i2 >= i3){
			mid = i2;
			min = i3;
		}
		else{
			mid = i3;
			min = i2;
		}
	}
	else if (i2 >= i1 && i2 >= i3){ // 1 9 4 - 4 9 2
		max = i2;
		if (i1 >= i3){
			mid = i1;
			min = i3;
		}
		else{
			mid = i3;
			min = i1;
		}
	}
	else {
		max = i3;
		if (i1 >= i2){
			mid = i1;
			min = i2;
		}
		else{
			mid = i2;
			min = i1;
		}
	}

	cout << min << ", " << mid << ", " << max << endl;
}
