// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod10
// doubly-linked lists
// Matteo Girardi
// *********************************************************************************
#include <iostream>
#include "doubly-linked.h"

using namespace std;

// int main(){
//   List newList;

//   for (int i=0; i<10; ++i) {
//     newList.insert(i);
//   }
//   newList.print();

//   // newList.insert(42);
//   // newList.insert(17);
//   // newList.insert(3);
  
//   for (int i=10; i<20; ++i) {
//     newList.insert(i);
//   }

//   newList.print();
//   newList.reverse();
//   newList.print();
// }

#include <iostream>
#include "doubly-linked.h"
 
using namespace std;
 
int main(void){
     
    List l;
    int n;
     
    while(cin >> n){
        l.insert(n);
    }
     
    // Print list as read from cin
    l.print();
    // Reverse the list and print it
    l.reverse();
    l.print();
    // Reverse again and print it
    l.reverse();
    l.print();
     
    return 0;
     
}