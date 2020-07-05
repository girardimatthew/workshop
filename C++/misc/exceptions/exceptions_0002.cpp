// exceptions
#include <iostream>
using namespace std;

int main () {
  try {
    //throw 20;
    //throw 'c';
    throw 2.5;
  }
  catch (int e) {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  catch (char e) {
  	cout << "An exception occurred. Exception " << e << '\n';
  }
  catch (...) {
  	cout << "default exception.\n";
  }
  return 0;
}