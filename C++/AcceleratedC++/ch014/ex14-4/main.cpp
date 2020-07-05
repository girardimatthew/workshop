#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include <sstream>
using std::stringstream;

#include "../lib/Student_info.h"
#include "../lib/Str.h"

void test_Str_0001() {
    cout << endl;
    Str s1("Hello Str!");
    Str s2 = s1;
    cout << s1 << endl;
    cout << s2 << endl;
    s1 = "Hello !!";
    cout << s1 << endl;
    cout << s2 << endl;
    s1[0] = 'Y';
    cout << s1 << endl;
    cout << s2 << endl;
}

void test_insert_func_on_Str() {
    cout << "==== test_insert_func_on_Str ====" << endl;

    Str test_str_insert = "The quick brown fox jumps over the lazy dog!";
    Str str3 = " _Hello, World!_ ";
    cout << test_str_insert << endl;

    Str::iterator it = test_str_insert.begin() + 5;
    test_str_insert.insert(it, str3.begin(), str3.begin() + (str3.size()));
    cout << test_str_insert << endl;

    cout << endl;
}

int main() {
    Str s("Hello Str!");
    cout << s << endl;
    Str t = "hello";
    s = "hello";
    cout << s[0] << s[1] << s[2] << s[3] << s[4] << endl;

    Str name = "World";
    Str greeting = "Hello, " + name + "!";
    cout << greeting << endl;

    Str temp1("Hello, ");
    Str temp2 = temp1 + name;
    Str temp3("!");
    Str greeting2 = temp2 + temp3;
    cout << greeting2 << endl;

    test_Str_0001();
    test_insert_func_on_Str();
}