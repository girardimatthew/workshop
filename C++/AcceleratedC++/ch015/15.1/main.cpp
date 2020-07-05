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

#include "Picture.h"

void test_picture() {
    cout << "-------- test_picture --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture p(i);
    cout << p << endl;
}

void test_frame() {
    cout << "-------- test_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    cout << q << endl;
}

void test_frame_of_a_frame() {
    cout << "-------- test_frame_of_a_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    cout << frame(q) << endl;
}

void test_horizontal_frame() {
    cout << "-------- test_horizontal_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    Picture r = hcat(q, q);
    cout << r << endl;
}

void test_horizontal_frame_of_a_frame() {
    cout << "-------- test_horizontal_frame_of_a_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    Picture r = hcat(q, q);
    cout << frame(r) << endl;
}

void test_vertical_frame() {
    cout << "-------- test_vertical_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    Picture r = vcat(q, q);
    cout << r << endl;
}

void test_vertical_frame_of_a_frame() {
    cout << "-------- test_vertical_frame_of_a_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    Picture r = vcat(q, q);
    cout << frame(r) << endl;
}

void test_vertical_frame_into_a_horizontal_frame() {
    cout << "-------- test_vertical_frame_into_a_horizontal_frame --------" << endl;
    vector<string> i = { "The quick brown fox", "jumped over the lazy dogs." };
    Picture q = frame(i);
    Picture r = vcat(q, q);
    Picture rh = hcat(r, r);
    cout << frame(rh) << endl;
}

int main() {

    test_picture();
    test_frame();
    test_frame_of_a_frame();
    test_horizontal_frame();
    test_horizontal_frame_of_a_frame();
    test_vertical_frame();
    test_vertical_frame_of_a_frame();
    test_vertical_frame_into_a_horizontal_frame();
    
    return 0;
}