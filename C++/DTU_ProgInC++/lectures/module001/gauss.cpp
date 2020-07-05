#include <iostream>
#include <limits>
using namespace std;

int main() {
	cout << "INT_MAX: " << INT_MAX << "\n";

	int n=0, result=0;
	cin >> n;

	for (int i=1; i<=n; i++) {
		result = result + i;
	}

	int result2 = n*(n+1)/2;
	int wrong2 = n/2*(n+1);
	//int wrong2 = n/2.0*(n+1);

	int result3;
	if (n%2==0)
		result3 = n/2*(n+1);
	else
		result3 = (n+2)/2*n;

	cout << n << ", " << result << ", " << result2 << ", " << wrong2 << "\n";

	if (result!=result3) {
		cout << "WFT!\n";
	}

	return 0;
}
