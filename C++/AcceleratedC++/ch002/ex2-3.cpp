#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ex 2-3: Rewrite the framing program to ask the user to supply the amount of spacing to 
// leave between the frame and the greeting.

int main() {

    // ask for the person's name
    cout << "Please enter your first name: ";
    // read the name
    string name;
    cin >> name;
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
    
    // ask for the amount of space 
    cout << "Please enter the amount of space on the left and right side: ";
    // the number of blanks surrounding the greeting on the X axis
    int padX;
    cin >> padX;

    // ask for the amount of space 
    cout << "Please enter the amount of space on the top and bottom side: ";
    // the number of blanks surrounding the greeting on the Y axis 
    int padY;
    cin >> padY;
    
    // the number of rows and columns to write
    const int minAmountOfRows = 3;
    const int rows = padY * 2 + minAmountOfRows;
    const string::size_type cols = greeting.size() + padX * 2 + 2;
    // write a blank line to separate the output from the input
    cout << endl;
    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++ r) {
        string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            // is it time to write the greeting?
            if (r == padY + 1 && c == padX + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // are we on the border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else 
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}
