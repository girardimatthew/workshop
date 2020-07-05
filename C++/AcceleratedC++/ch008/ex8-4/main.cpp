#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

template <class T> void paws(T& x, T& y) {
    //cout << "x: " << x << " y: " << y << endl;
    T tmp_x = x;
    x = y;
    y = tmp_x;
}

template <class Bi> void rreverse(Bi begin, Bi end) {
    while (begin != end) {
        --end;
        if (begin != end) {
            //std::swap(*begin++, *end);
            // *****************************************************
            // to swap it directly we need to know the 
            // type of the element the iterator is pointing at
            paws(*begin++, *end);
        }
    }
}

template <class Bi, class T> void rreverse_nswap(Bi begin, Bi end) {
    
    T tmp;
    
    while (begin != end) {
        --end;
        if (begin != end) {
            tmp = *begin;
            *begin = *end;
            *end = tmp;
            begin++;
        }
    }
}

template <class T>
void print_vector(const vector<T>& vec) {
    cout << "[ ";
    for(typename vector<T>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter;
        if (iter != (vec.end() - 1))
            cout << ", ";
    }
    cout << " ]" << endl;
}

void ex8_4() {
    vector<int> v_i = { 99, 98, 97, 96, 95, 94, 93, 92, 91, 90 };
    // you need to specify the type
    rreverse_nswap<vector<int>::iterator, int>(v_i.begin(), v_i.end());
    print_vector(v_i);
}



int main(int argc, const char * argv[]) {
    
    vector<int> v_i = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    rreverse(v_i.begin(), v_i.end());
    print_vector(v_i);
    // 
    v_i = { 1, 2, 3 };
    rreverse(v_i.begin(), v_i.end());
    print_vector(v_i);
    //
    ex8_4();
}