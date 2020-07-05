//ex4-7
// write a program to calculate the average of the numbers 
// stored in a vector<double>

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main() { 
    vector<double> nums;
    double num;

    while (cin >> num)
        nums.push_back(num);

    // double sum = 0;
    // for(vector<double>::size_type i = 0; i < nums.size(); ++i) {
    //     sum += nums[i];
    // } 
    // cout << sum / nums.size() << endl;

    cout << accumulate(nums.begin(), nums.end(), 0.0) / nums.size() << endl;

}