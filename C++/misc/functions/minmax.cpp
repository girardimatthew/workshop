#include <iostream>

using namespace std;

void minmax(int x, int y, int &minOut, int &maxOut) {
  minOut = x;
  maxOut = y;
  if (x >= y) {
    minOut = y;
    maxOut = x;
  }
}

int main() {
  int x = 99;
  int y = 150;
  int minOut, maxOut;

  minmax(x,y,minOut,maxOut);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "minOut: " << minOut << endl;
  cout << "maxOut: " << maxOut << endl;
}
