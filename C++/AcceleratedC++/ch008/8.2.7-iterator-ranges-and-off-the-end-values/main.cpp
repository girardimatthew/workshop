#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;      using std::cout;

int main(int argc, const char * argv[]) {

    vector<int> v;
    cout << ((v.begin() == v.end()) == 0 ? "false" : "true") << endl;
    v.push_back(41);
    cout << ((v.begin() == v.end()) == 0 ? "false" : "true") << endl;
}