// istream::putback example 0002
#include <iostream>     // cin, cout
#include <string>       // string

using namespace std;    // std::

int main () {
  char c;
  cout << "Enter 'q' to terminate.\n";
  cout << "Please, enter a number or a word: ";
  while(cin) {
    cin >> c;
    if ((c>='0') && (c<='9')) {
      int n;
      cin.putback (c);
      cin >> n;
      cout << "You entered a number: " << n << '\n';
      cout << "c: " << c << endl;
    }
    else if (c=='q') {
      break;
    }
    else {
      string str;
      cin.putback (c);
      getline (cin,str);
      cout << "You entered a word: " << str << '\n';
      cout << "c: " << c << endl;
    }
    cout << "Please, enter a number or a word: ";
  }
  return 0;
}