// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include <vector>
#include "median.cpp"

using std::vector;

TEST_CASE("The median of a vector of double of size 9") {
    double expected_median = 4.2;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    vector<double> v_copy = v;
    double med = median<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
    for(int i = 0; i != v.size(); ++i) {
        REQUIRE(v[i] == v_copy[i]);
    }
}

TEST_CASE("The median of a vector of double of size 3") {
    double expected_median = 5.3;
    vector<double> v = { 2.0, 9.2, 5.3 };
    vector<double> v_copy = v;
    double med = median<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
    for(int i = 0; i != v.size(); ++i) {
        REQUIRE(v[i] == v_copy[i]);
    }
}

TEST_CASE("The median of a vector of double of size 4") {
    double expected_median = 4.75;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2 };
    double med = median<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 9") {
    int expected_median = 4;
    vector<int> v = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    vector<int> v_copy = v;
    int med = median<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
    for(int i = 0; i != v.size(); ++i) {
        REQUIRE(v[i] == v_copy[i]);
    }
}

TEST_CASE("The median of a vector of int of size 3") {
    int expected_median = 5;
    vector<int> v = { 2, 9, 5 };
    int med = median<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 4") {
    int expected_median = 6;
    vector<int> v = { 2, 9, 5, 8 };
    int med = median<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of char of size 5") {
    char expected_median = 'l';
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    vector<char> vc_copy = vc; 
    char med = median<vector<char>::iterator, char>(vc.begin(), vc.end());
    REQUIRE(med == expected_median);
    for(int i = 0; i != vc.size(); ++i) {
        REQUIRE(vc[i] == vc_copy[i]);
    }
}

TEST_CASE("The median of an array of int size 5") {
    int expected_median = 6;
    int numbers[] = { 2, 9, 5, 8 };
    int numbers_copy[] = { 2, 9, 5, 8 };
    const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    int med = median<int*, int>(numbers, (numbers + ngrades));
    REQUIRE(med == expected_median);
    for(int i = 0; i != 4; ++i) {
        REQUIRE(numbers[i] == numbers_copy[i]);
    }
}

TEST_CASE("The median of a char array of size 5") {
    char expected_median = 'l';
    char chars_array[] = { 'h', 'e', 'l', 'l', 'o' }; 
    const size_t ngrades = sizeof(chars_array)/sizeof(*chars_array);
    char med = median<char*, char>(chars_array, (chars_array + ngrades));
    REQUIRE(med == expected_median);
}

// Does this make sense ??
TEST_CASE("The median of a char array of size 4") {
    char expected_median = 'j';
    char chars_array[] = { 'h', 'e', 'l', 'l' }; 
    const size_t ngrades = sizeof(chars_array)/sizeof(*chars_array);
    char med = median<char*, char>(chars_array, (chars_array + ngrades));
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a double array of size 9") {
    double expected_median = 4.2;
    double numbers[] = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    double med = median<double*, double>(numbers, (numbers + ngrades));
    REQUIRE(med == expected_median);
}
