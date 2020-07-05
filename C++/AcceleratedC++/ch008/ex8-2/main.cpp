#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "algo.h"

using std::cin;                 using std::max;
using std::cout;                using std::setprecision;
using std::domain_error;        using std::sort;
using std::endl;                using std::streamsize;
using std::string;              using std::vector;

template <class In>
void print(In begin, In end) {
    cout << "[ ";
    for(In iter = begin; iter != end; ++iter) {
        cout << *iter;
        if (iter != (end - 1))
            cout << ", ";
    }
    cout << " ]" << endl;
}

void test_find() {
    // using std::find with array and pointer:
    int myints[] = { 10, 20, 30, 40 };
    int * p;

    p = my_find(myints, myints+4, 30);
    if (p != myints+4)
        cout << "Element found in myints: " << *p << '\n';
    else
        cout << "Element not found in myints\n";

    // using std::find with vector and iterator:
    vector<int> myvector (myints, myints+4);
    vector<int>::iterator it;

    it = my_find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        std::cout << "Element found in myvector: " << *it << '\n';
    else
        std::cout << "Element not found in myvector\n";
}

void test_copy() {
    vector<int> v_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> v_i_long = { 11, 12, 13, 14, 15, 16, 16, 17, 18, 19, 20, 99, 98, 97, 96, 95, 94, 93 };
    my_copy(v_i.begin(), v_i.end(), v_i_long.begin());
    print(v_i_long.begin(), v_i_long.end());
}

void test_equal() {
    int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
    vector<int>myvector (myints,myints+5);          //   myvector: 20 40 60 80 100

    // using default comparison:
    if ( my_equal(myvector.begin(), myvector.end(), myints) )
        cout << "The contents of both sequences are equal.\n";
    else
        cout << "The contents of both sequences differ.\n";

    vector<int> v_i = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //vector<int> v_n = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 99, 98, 97, 96, 95, 94, 93 }; // 
    vector<int> v_n = { 1, 2, 3, 4, 5, 6 };
    if ( my_equal(v_i.begin(), v_i.end(), v_n.begin()) )
        cout << "The contents of both sequences are equal.\n";
    else
        cout << "The contents of both sequences differ.\n";
}

bool IsOdd (int i) { 
    return ((i % 2) == 1); 
}

void test_remove_copy_if() {
    int myints[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> myvector (9);
    print(myvector.begin(), myvector.end());
    my_remove_copy_if(myints, myints+9, myvector.begin(), IsOdd);
    cout << "myvector contains: ";
    print(myvector.begin(), myvector.end());
}

void test_remove_copy() {
    int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
    vector<int> myvector(8);
    my_remove_copy(myints, myints+8, myvector.begin(), 20); // 10 30 30 10 10 0 0 0
    print(myvector.begin(), myvector.end());
}

int op_increase (int i) { return ++i; }

void test_transform() {
    vector<int> foo;
    vector<int> bar;
    // set some values:
    for (int i=1; i<6; i++)
        foo.push_back (i*10);
    print(foo.begin(), foo.end());
    // allocate space
    bar.resize(foo.size()); 
    // bar: 11 21 31 41 51
    my_transform (foo.begin(), foo.end(), bar.begin(), op_increase);
    print(bar.begin(), bar.end());
}

void test_accumulate() {
    int init = 100;
    int numbers[] = { 10, 20, 30 };
    cout << "using accumulate: ";
    cout << my_accumulate(numbers, numbers+3, init);
    cout << '\n';
}

void test_search() {

}

int main() {

    cout << "========= find " << endl;
    test_find();
    cout << "========= copy " << endl;
    test_copy();
    cout << "========= equal " << endl;
    test_equal();
    cout << "========= remote_copy_if " << endl;
    test_remove_copy_if();
    cout << "========= remote_copy " << endl;
    test_remove_copy();
    cout << "========= transform " << endl;
    test_transform();
    cout << "========= accumulate " << endl;
    test_accumulate();
    // TODO
    // finish to test the functions
    // search
    // find_if
    // remove
    // partition
    
    return 0;
}