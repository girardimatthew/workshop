//ex4-8
// if the following code is legal, what can we infer about the 
// return type of f?

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

// vector<double> f() {
//     vector<double> vec;
//     vec.push_back(55);
//     vec.push_back(65);
//     vec.push_back(75);
//     return vec;
// }


int foo [5] = { 16, 2, 77, 40, 12071 };
int* f() {	
    return foo;
}

int main() { 

    int n = 0;
    double d = f()[n];
    cout << d << endl;
}