// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include <vector>
#include "median.cpp"

using std::vector;

TEST_CASE("The median of a vector of double of size 9") {
    double expected_median = 4.2;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of double of size 3") {
    double expected_median = 5.3;
    vector<double> v = { 2.0, 9.2, 5.3};
    double med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of double of size 4") {
    double expected_median = 4.75;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2};
    double med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 9") {
    int expected_median = 4;
    vector<int> v = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 3") {
    int expected_median = 5;
    vector<int> v = { 2, 9, 5};
    int med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 4") {
    int expected_median = 6;
    vector<int> v = { 2, 9, 5, 8};
    int med = median(v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of char of size 5") {
    char expected_median = 'l';
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    char med = median(vc);
    REQUIRE(med == expected_median);
}
