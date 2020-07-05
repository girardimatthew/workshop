// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include <vector>
#include "median.cpp"

using std::vector;

TEST_CASE("The median of a vector of double of size 9") {
    double expected_median = 4.2;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of double of size 3") {
    double expected_median = 5.3;
    vector<double> v = { 2.0, 9.2, 5.3 };
    double med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of double of size 4") {
    double expected_median = 4.75;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2 };
    double med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 9: expected_median = 5") {
    int expected_median = 5;
    vector<int> v = { 42, 9, 5, 4, 6, 5, 2, 1, 1 }; 
    double med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 9") {
    int expected_median = 4;
    vector<int> v = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 3") {
    int expected_median = 5;
    vector<int> v = { 2, 9, 5 };
    int med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of int of size 4") {
    int expected_median = 6;
    vector<int> v = { 2, 9, 5, 8 };
    //int med = median(v.begin(), v.end());
    int med = median(v.begin(), v.end(), v);
    REQUIRE(med == expected_median);
}

TEST_CASE("The median of a vector of char of size 5") {
    char expected_median = 'l';
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    char med = median(vc.begin(), vc.end(), vc);
    REQUIRE(med == expected_median);
}

// ================== MEDIAN_ITER

TEST_CASE("[Using median_iter]: The median of a vector of double of size 9") {
    double expected_median = 4.2;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med = median_iter<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using median_iter]: The median of a vector of double of size 3") {
    double expected_median = 5.3;
    vector<double> v = { 2.0, 9.2, 5.3 };
    double med = median_iter<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using median_iter]: The median of a vector of double of size 4") {
    double expected_median = 4.75;
    vector<double> v = { 2.0, 9.2, 5.3, 4.2 };
    double med = median_iter<vector<double>::iterator, double>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using median_iter]: The median of a vector of int of size 9: expected_median = 5") {
    int expected_median = 5;
    vector<int> v = { 42, 9, 5, 4, 6, 5, 2, 1, 1 }; 
    int med = median_iter<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using median_iter]: The median of a vector of int of size 9") {
    int expected_median = 4;
    vector<int> v = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med = median_iter<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using median_iter]: The median of a vector of int of size 3") {
    int expected_median = 5;
    vector<int> v = { 2, 9, 5 };
    int med = median_iter<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using mediat_iter]: The median of a vector of int of size 4") {
    int expected_median = 6;
    vector<int> v = { 2, 9, 5, 8 };
    int med = median_iter<vector<int>::iterator, int>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

TEST_CASE("[Using mediat_iter]: The median of a vector of char of size 5") {
    char expected_median = 'l';
    vector<char> v = { 'h', 'e', 'l', 'l', 'o' }; 
    char med = median_iter<vector<char>::iterator, char>(v.begin(), v.end());
    REQUIRE(med == expected_median);
}

