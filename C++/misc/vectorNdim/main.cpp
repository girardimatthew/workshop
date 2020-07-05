/*
 * this is just a simple program to test your implementation
 *
 */

#include "vect.h"
#include <iostream>

using namespace std;

int main(){
    
    // we crate here some vectors with fixed values
    int dim = 2;
    double a[] = {3,0};
    double b[] = {0,4};
    double c[] = {3,2};
    vect<double> v1(a,dim);
    vect<double> v2(b,dim);
    vect<double> v3(c,dim);

    // // we create here v4 as vector which is like v2
    vect<double> v4(v2);

    v1.print();
    v2.print();
    v3.print();
    cout << "scalar product: v1*v2 = " << v1 * v2 << endl;
    cout << "scalar product: v1*v3 = " << v1 * v3 << endl;
    cout << "scalar product: v2*v3 = " << v2 * v3 << endl;
    
    //
    cout << "Pythagoras holds on perpendicular triangles (a,b,c):\n";
    cout << "a = " << v1.length();
    cout << " , b = " << v2.length();
    
    // we create a new vector v5 here by combining other vectors
    // this vector corresponds to the diagonal of the triangle defined by v1 and v2

    vect<double> v5 = v1 + v2 * (-1);    
    
    cout << " , c = " << v5.length() << endl;
    
    cout << "...but not on non-perpendicular triangles (a,b,c):\n";
    cout << "a = " << v3.length();
    cout << " , b = " << v4.length();
    
    v5 = v3 + v4 * (-1);
    
    cout << " , c = " << v5.length() << endl;
    
    /* Output should be:
     Pythagoras holds on perpendicular triangles:
     a=3 b=4 c=5
     ...but not on non-perpendicular triangles:
     a=3.60555 b=4 c=3.60555
     */
    
    // Note that vector operations like + and *
    // modify the vectors on their lhs!
    
    double nv1[] = {0,0};
    double nv2[] = {1,1};
    double nv3[] = {0,0};
    vect<double> w1(nv1,2);
    vect<double> w2(nv2,2);
    vect<double> w3(nv3,2);
    
    cout << "Before w3 = w1 + w2 the length of w1 is... " << w1.length() << endl;
    w3 = w1 + w2;
    cout << "After  w3 = w1 + w2 the length of w1 is... " << w1.length() << endl;
    
    /* Output should be
     Before w3 = w1 + w2 the length of w1 is... 0
     After  w3 = w1 + w2 the length of w1 is... 1.41421
    */

    return 0;
}
