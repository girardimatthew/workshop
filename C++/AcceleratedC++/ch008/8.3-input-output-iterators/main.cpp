#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;      using std::cout;
using std::cin;         using std::istream_iterator;
using std::copy;        using std::back_inserter;


int main(int argc, const char * argv[]) {

    cout << "Enter some numbers (cmd+d to stop):" << endl;
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    
    for(vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter;
        if (iter != (v.end() - 1))
            cout << ", ";
    }
    cout << endl;
    // write the elements of v each separated from the other by a space
    copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
    // no separation between elements
    copy(v.begin(), v.end(), std::ostream_iterator<int>(cout));
    cout << endl;
}