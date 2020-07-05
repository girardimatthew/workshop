// bad_alloc standard exception
#include <iostream>

using namespace std;

int main()
{
    try
    {
        int* myarray = new int[100000000000000];
        delete [] myarray;
    }
    catch(exception& e) //Takes a reference to an 'exception' object
    {
        cout << "Error allocating memory: " << e.what() << endl;
    }
}