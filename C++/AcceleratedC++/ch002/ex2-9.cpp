#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    
    // write a program that asks the user to enter two numbers
    // and tells the user which number is larger than the other
    cout << "*****************************" << endl;
    cout << "Which number is the largest ?" << endl;
    cout << "*****************************" << endl;
    cout << endl;

    cout << "Please enter the first number: " << endl;
    double first;
    cin >> first;
    cout << "Please enter the second number: " << endl;
    double second;
    cin >> second;

    cout << endl;
    string quote = "Based on your inputs, the largest number is: ";
    if (first > second) {
        cout << quote << first << endl;
    } else if (second > first) {
        cout << quote << second << endl;
    } else {
        cout << "the numbers you input are equal." << endl; 
    }    
}