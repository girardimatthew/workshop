#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
#include <time.h>

using namespace std;

int main() {
  try {
  int iRand;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 0 and 9: */
  iRand = rand();
  cout << iRand << endl;
  cout << iRand % 10 << endl;
  cout << iRand / 10 << endl;
    
  }
  catch (runtime_error& e) {
    cerr << "runtime error.\n";
  }
  catch (...) {
    cerr << "Unknown exception!\n";
  }
}