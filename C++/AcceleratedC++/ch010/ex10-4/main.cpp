#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

#include "String_list.h"

template <class Ran>
void print(Ran begin, Ran end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

bool space(char c) {
    return isspace(c) != 0;
}

bool not_space(char c) {
    return !isspace(c);
}

String_list split(const string& str) {
    typedef string::const_iterator iter;
    String_list ret;

    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

void test0001() {
    String_list str_list;
    str_list.push_back("test");
    str_list.push_back("more");
    str_list.push_back("testing");
    str_list.push_back("even more");
    str_list.push_back("yup");

    print(str_list.begin(), str_list.end());
    // or 
    //String_list::iterator iter = str_list.begin();
    // while (iter != str_list.end())
    //     cout << *iter++ << endl;
}

void test0002() {
    String_list anotherStrList;
    anotherStrList.push_back("en");
    anotherStrList.push_back("to");
    anotherStrList.push_back("tre");
    anotherStrList.push_back("fire");
    anotherStrList.push_back("fem");
    String_list::iterator iter = anotherStrList.begin();

    while (iter != anotherStrList.end()) {
        cout << *iter << endl;
        *iter++ = "reverse";
    }

    while (iter != anotherStrList.begin())
        cout << *(--iter) << endl;
}

void test0003() {
    string str = "Please split this amazing string!";
    String_list str_list = split(str);
    print(str_list.begin(), str_list.end());
}

int main() {
    cout << "=========== test 001 " << endl;
    test0001();
    cout << "=========== test 002 " << endl;
    test0002();
    cout << "=========== test 003 " << endl;
    test0003();
    return 0;
}