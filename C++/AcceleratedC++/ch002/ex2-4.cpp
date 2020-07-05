#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    // ask for the person's name
    cout << "Please enter your first name: ";
    // read the name
    string name;
    cin >> name;
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
    // the number of blanks surrounding the greeting
    const int pad = 2;
    // the number of rows and columns to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // a blanks space
    const string aSpace = " ";
    string space;
    // build the amount of space on the sides left, right
    for (int i = 0; i != pad; ++i) {
        space += aSpace;
    }
    
    // build the row where the greeting will be at.
    const string greetingRow = space + greeting + space;
    // build the row where there will be only spaces
    const string onlySpaces(greetingRow.size(), ' ');
    
    // write a blank line to separate the output from the input
    cout << endl;
    // write rows rows of output
    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c < cols) {
            // is it time to write the greeting?
            if (r == pad + 1)  {
                cout << "*" << greetingRow << "*";
                c += greetingRow.size() + 2;
            } else {
                // are we on the border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols) {
                    cout << "*";
                    ++c;
                } else {
                    cout << onlySpaces << "*";
                    c += onlySpaces.size() + 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
