#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

template <class T>
T max_t(const T& left, const T& right) {
    return left > right ? left : right;
}

template <class L, class R, class Out>
Out max_lr(const L& left, const R& right) {
    return left > right ? left : right;
}

int main(int argc, const char * argv[]) {
    
    string name = "Hello C++ !";
    // using int as type of maxlen, the program won't compile.
    //int maxlen = 0;
    string::size_type maxlen = 0;
    maxlen = max(maxlen, name.size());

    string::size_type max_t_len = 42;
    max_t_len = max_t(max_t_len, name.size());
    cout << maxlen << ", " <<  max_t_len << endl;

    //double n = max_lr<int, int, double>(9, 9.5); // -> truncation.
    double n = max_lr<int, double, double>(9, 9.5); // 
    cout << n << endl;

    // Why doesn't the `max` function use two template parameters,
    // one for each argument type?
    // -------
    // because then you would have to specify the return type
    // and it can cause tricky situations, as for example, truncation
    // 
    // there's no way for the implementation to know what type will be returned when
    // two different arguments types are used
    // the return type must be specified since the compiler can't infer it.
}