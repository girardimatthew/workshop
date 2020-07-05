#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::string;

#include "../Vec/Vec.h"

int main() {

    Vec<char> v;
    
    char data[] = { 'h', 'e', 'l', 'l', 'o' };
    v.assign(data, data + sizeof(data));

    for (size_t i = 0; i < v.size(); i++)
        cout << v[i];

    cout << endl;
    v.print_vec(cout);

    Vec<char> vc(5, 'x');
    vc.print_vec(cout);

    char xData[] = { 'y', 'y', 'y' };
    vc.assign(xData, xData + sizeof(xData));
    vc.print_vec(cout);
    
    return 0;
}