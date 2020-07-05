#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include "vecN.h"

using namespace std;

int main() {

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};

    int c[] = {1, 3, -5};
    int d[] = {4, -2, -1};

    int sizeofa = sizeof(a) / sizeof(a[0]);
    int sizeofb = sizeof(b) / sizeof(b[0]);
    int sizeofc = sizeof(c) / sizeof(c[0]);
    int sizeofd = sizeof(d) / sizeof(d[0]);
    
    VecN v1(a,sizeofa);
    VecN v2(b,sizeofb);
    VecN v3(c,sizeofc);
    VecN v4(d,sizeofd);

    cout << "-------------------------" << endl;
    cout << "Print vectors: " << endl;
    v1.printVecN();
    v2.printVecN();
    v3.printVecN();
    v4.printVecN();
    cout << "-------------------------" << endl;
    cout << "Dot product: " << endl;
    cout << v1.dotProduct(v2) << endl;
    cout << v3.dotProduct(v4) << endl;
    cout << "-------------------------" << endl;
    cout << "sum of vectors: " << endl;
    v1.vectSum(v2);
    v3.vectSum(v4);
    // cout << v1 + v2 << endl;
    // VecN v3 = v1 + v2;
    // v3.printVect();
    
    // cout << "scalar multiplication: ";
    // Vect<int> v4 = v1 * 2.0;
    // v4.print();
    // cout << "scalar multiplication: " << v2 * 2.0 << endl;
}
