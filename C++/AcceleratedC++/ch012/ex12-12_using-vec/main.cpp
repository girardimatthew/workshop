#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::string;

#include "../Str_v/Str.h"

using std::streamsize;
using std::domain_error;
using std::sort;

void test_str_char_init() {
    cout << "==== test_str_char_init ====" << endl;
    Str s("Hello Str-world!");
    Str::size_type size = s.size();

    for(Str::iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i;
    }
    cout << endl;
    cout << s[0] << ", " << s[size - 1] <<  endl;

    cout << endl;
}

void test_str_default_init() {
    cout << "==== test_str_default_init ====" << endl;
    Str ds;
    cout << "Size: " << ds.size() << endl;
    ds = "Hello World!";
    cout << "Size: " << ds.size() << endl;
    for(Str::iterator i = ds.begin(); i != ds.end(); ++i) {
        cout << *i;
    }
    cout << endl;
    cout << ds[11] << endl;

    cout << endl;
}

void test_str_operator_plus_equal() {
    cout << "==== test_str_operator_plus_equal ====" << endl;
    Str ds;
    cout << "Size: " << ds.size() << endl;
    ds = "12345";
    cout << "Size: " << ds.size() << endl;
    for(Str::iterator i = ds.begin(); i != ds.end(); ++i) {
        cout << *i;
    }
    cout << endl;
    cout << ds[ds.size() - 1] << endl;

    ds += "67890";
    for(Str::iterator i = ds.begin(); i != ds.end(); ++i) {
        cout << *i;
    }
    cout << endl;
    cout << "Size: " << ds.size() << endl;

    cout << endl;
}

void test_str_output_operator() {
    cout << "==== test_str_output_operator ====" << endl;
    Str ds;
    ds = "12345";
    cout << ds << endl;

    cout << endl;
}

void test_str_input_operator() { 
    cout << "==== test_str_input_operator ====" << endl;

    Str ins;
    cin >> ins;
    cout << ins << endl;
    cout << "Size: " << ins.size() << endl;
    cout << endl;
}

void test_str_plus_operator() { 
    cout << "==== test_str_plus_operator ====" << endl;

    Str ins;
    Str n = "789";
    ins = "123";
    ins = ins + "456";
    ins = ins + n;
    cout << ins << " - size: " << ins.size() << endl;
    cout << endl;
}

void test_str_relational_operators() {
    cout << "==== test_str_relational_operators ====" << endl;

    Str a = "123";
    Str b = "123";
    cout << std::boolalpha; 

    cout << (a == b) << endl;
    cout << (a == "321") << endl;
    cout << (a != b) << endl;
    cout << (a < b) << endl;
    cout << (a <= b) << endl;
    cout << (a > b) << endl;
    cout << (a >= b) << endl;

    cout << endl;
}

void test_str_concatenation() {
    cout << "==== test_str_concatenation ====" << endl;

    Str helloWorld = "Hello, World!";
    Str name = "My name is C++";
    Str helloWorldName = helloWorld + " " + name;

    cout << helloWorldName << endl;
    cout << endl;
}

// Ex 12-6
void test_use_Str_as_a_condition() {
    // define a func within a func
    // with lamdas
    auto if_else_statement = [] (bool condition) {
        if (condition) {
            cout << "Str is not empty" << endl;
        } else { 
            cout << "Str is empty" << endl;
        }
    };
    // define a func within a func
    // with Struct
    struct Condition { 
        static void if_else(bool condition) {
            if (condition) {
                cout << "Str is not empty" << endl;
            } else { 
                cout << "Str is empty" << endl;
            }
        }
    };

    cout << "==== test_use_Str_as_a_condition ====" << endl;

    Str strCondition;
    if_else_statement(strCondition);
    Condition::if_else(strCondition);

    strCondition = "Hello, World!";
    if_else_statement(strCondition);
    Condition::if_else(strCondition);

    cout << endl;
}

// Ex 12-7
void test_random_access_iterators() {
    cout << "==== test_random_access_iterators ====" << endl;
    Str aString = "test_random_access_iterators";
    cout << aString << endl;
    cout << aString[0] << endl;
    cout << aString[aString.size() - 1] << endl;
    aString[0] = '$';
    cout << aString << endl;

    std::string tab = "";
    for(Str::iterator i = aString.begin(); i != aString.end(); ++i) {
        cout << tab << *i << endl;
        tab += " ";
    }
    cout << endl;
}

// Ex 12-12
void test_insert_func_on_std_string() {
    cout << "==== test_insert_func_on_std_string ====" << endl;

    string test_str_insert = "The quick brown fox jumps over the lazy dog!";
    string str3 = " _Hello, World!_ ";
    cout << test_str_insert << endl;

    std::string::iterator it = test_str_insert.begin() + 5;
    test_str_insert.insert(it, str3.begin(), str3.begin() + (str3.size()));
    cout << test_str_insert << endl;

    cout << endl;
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
    test_str_char_init();
    test_str_default_init();

    test_str_operator_plus_equal();

    test_str_output_operator();
    //test_str_input_operator();

    test_str_plus_operator();
    test_str_relational_operators();

    test_str_concatenation();
    test_use_Str_as_a_condition();
    test_random_access_iterators();

    test_insert_func_on_std_string(); 
    test_insert_func_on_Str();
       
    return 0;
}