#include <iostream>
#include "doubly-linked.h"
 
int main(void) {
     
    List<int> list;
    
    cout << std::boolalpha << "Is the list empty: " << list.empty() << endl;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
     
    // Print list as read from cin
    list.print();
    cout << "Is the list empty: " << list.empty() << endl;
    // 
    list.push_back(42);
    list.push_back(17);
    list.push_back(3);
    //
    list.print();
    // Reverse the list and print it
    list.reverse();
    list.print();
    // Reverse again and print it
    list.reverse();
    list.print();
    //
    list.push_back(11);
    list.push_back(5);
    list.push_back(7);
    //
    list.print();
    list.printLast();
    list.printBackward();
    list.print();

    //
    list.clear();
    cout << "Is the list empty: " << list.empty() << endl;
    list.print();

    list.push_back(11);
    list.push_back(5);
    list.push_back(7);

    list.print();
     
    return 0;
}