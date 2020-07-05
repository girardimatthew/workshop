#include "String_list.h"
#include <string>

using std::string;

void String_list::resize() {
    max *= 2;
    string *copy = new string[max];

    for(string::size_type i = 0; i < size; ++i) {
        copy[i] = list[i];
    }
    delete[] list;

    list = copy;
}

String_list::String_list() :
    list(new std::string[1]),
    size(0),
    max(1)
    { }

String_list::~String_list() {
    delete[] list;
}

void String_list::push_back(std::string str) {
    if (size == max) { resize(); }
    list[size++] = str;
}