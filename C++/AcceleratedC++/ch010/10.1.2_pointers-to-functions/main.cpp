#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int next(int n) {
    return n + 1;
}

template <class T>
T increment(T n) {
    return ++n;
}

bool is_negative(int n) {
    return n < 0;
}
template <class In, class Pred>
In mfind_if(In begin, In end, Pred f) {
    while (begin != end && !(*f)(*begin))
    //while (begin != end && !f(*begin))
        ++begin;
    return begin;
}

int main() {

    int i = 3;
    int (*fp)(int); 
    // these two statement are equivalent
    fp = &next;
    //fp = next;
    cout << "i: " << i << endl;

    // equivalent statement
    i = (*fp)(i);
    //i = fp(i);
    cout << "i: " << i << endl;

    double n = 42;
    cout << "n: " << n << endl;
    double (*tf)(double);
    tf = increment;
    n = tf(n);
    cout << "n: " << n << endl;

    vector<int> v = { 1, 2, 3, 4, -5, 6, 7, 8, 9 };
    vector<int>::iterator viiter = mfind_if(v.begin(), v.end(), &is_negative);
    // vector<int>::iterator viiter = mfind_if(v.begin(), v.end(), is_negative);
    cout << *viiter << endl;
    
    return 0;
}