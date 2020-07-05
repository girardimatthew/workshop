#include <vector>
using std::vector;

#include <iostream>
using std::cout;          using std::endl;

#include <string>
using std::string;

#include "median.h"

#include <chrono>
using std::chrono::steady_clock;




int main(int argc, const char * argv[]) {
    cout << "==== USING median ====" << endl;
    // int
    vector<int> vi = { 42, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med_i = median(vi.begin(), vi.end(), vi);
    cout << med_i << endl;
    // double
    vector<double> vd = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med_d = median(vd.begin(), vd.end(), vd);
    cout << med_d << endl;
    // char
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    char med_c = median(vc.begin(), vc.end(), vc);
    cout << med_c << endl;

    cout << endl;
    cout << "==== USING median_iter ====" << endl;

    // int
    vector<int> vii = { 42, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med_ii = median_iter<vector<int>::iterator, int>(vii.begin(), vii.end());
    cout << med_ii << endl;
    // double
    vector<double> vdd = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med_dd = median_iter<vector<double>::iterator, double>(vdd.begin(), vdd.end());
    cout << med_dd << endl;
    // char
    vector<char> vcc = { 'h', 'e', 'l', 'l', 'o' }; 
    char med_cc = median_iter<vector<char>::iterator, char>(vcc.begin(), vcc.end());
    cout << med_cc << endl;

    // ********************************************************************************************************
    cout << endl;
    cout << "==== PERFORMANCE OF MEDIAN BY VALUE =====" << endl;

    vector<int> vec1 = { 
        78, 96, 33, 49, 99, 98, 52, 76, 41, 63, 3, 33, 33, 99, 68, 59, 26, 8, 66, 26, 59, 58, 85, 58, 71, 74, 99, 79, 61, 77, 48, 68, 23, 26, 30, 23, 42, 84, 65, 40, 24, 29, 91, 60, 88, 73, 53, 80, 70, 50, 43, 43, 90, 48, 54, 22, 40, 35, 96, 20, 96, 29, 67, 4, 52, 88, 83, 96, 2, 51, 23, 13, 10, 69, 7, 95, 61, 32, 81, 35, 38, 66, 87, 38, 79, 30, 54, 10, 100, 67, 27, 10, 57, 63, 85, 52, 79, 5, 92, 39
    };

    steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++) {
        median_by_value(vec1);
    }
    steady_clock::time_point end = std::chrono::steady_clock::now();

    cout << "Microseconds to run median 100 times = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;

    // ********************************************************************************************************
    cout << endl;
    cout << "==== PERFORMANCE OF MEDIAN ==============" << endl;

    vec1 = { 
        78, 96, 33, 49, 99, 98, 52, 76, 41, 63, 3, 33, 33, 99, 68, 59, 26, 8, 66, 26, 59, 58, 85, 58, 71, 74, 99, 79, 61, 77, 48, 68, 23, 26, 30, 23, 42, 84, 65, 40, 24, 29, 91, 60, 88, 73, 53, 80, 70, 50, 43, 43, 90, 48, 54, 22, 40, 35, 96, 20, 96, 29, 67, 4, 52, 88, 83, 96, 2, 51, 23, 13, 10, 69, 7, 95, 61, 32, 81, 35, 38, 66, 87, 38, 79, 30, 54, 10, 100, 67, 27, 10, 57, 63, 85, 52, 79, 5, 92, 39
    };

    begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++) {
        median(vec1.begin(), vec1.end(), vec1);
    }
    end = std::chrono::steady_clock::now();

    cout << "Microseconds to run median 100 times = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;
    
    // ********************************************************************************************************
    cout << endl;
    cout << "==== PERFORMANCE OF MEDIAN_PASS_SIZE ====" << endl;

    vec1 = { 
        78, 96, 33, 49, 99, 98, 52, 76, 41, 63, 3, 33, 33, 99, 68, 59, 26, 8, 66, 26, 59, 58, 85, 58, 71, 74, 99, 79, 61, 77, 48, 68, 23, 26, 30, 23, 42, 84, 65, 40, 24, 29, 91, 60, 88, 73, 53, 80, 70, 50, 43, 43, 90, 48, 54, 22, 40, 35, 96, 20, 96, 29, 67, 4, 52, 88, 83, 96, 2, 51, 23, 13, 10, 69, 7, 95, 61, 32, 81, 35, 38, 66, 87, 38, 79, 30, 54, 10, 100, 67, 27, 10, 57, 63, 85, 52, 79, 5, 92, 39
    };

    begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++) {
        median_pass_size(vec1.begin(), vec1.end(), vec1.size());
    }
    end = std::chrono::steady_clock::now();

    cout << "Microseconds to run median 100 times = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;

    // ********************************************************************************************************
    cout << endl;
    cout << "==== PERFORMANCE OF MEDIAN_ITER =========" << endl;
    
    vec1 = { 
        78, 96, 33, 49, 99, 98, 52, 76, 41, 63, 3, 33, 33, 99, 68, 59, 26, 8, 66, 26, 59, 58, 85, 58, 71, 74, 99, 79, 61, 77, 48, 68, 23, 26, 30, 23, 42, 84, 65, 40, 24, 29, 91, 60, 88, 73, 53, 80, 70, 50, 43, 43, 90, 48, 54, 22, 40, 35, 96, 20, 96, 29, 67, 4, 52, 88, 83, 96, 2, 51, 23, 13, 10, 69, 7, 95, 61, 32, 81, 35, 38, 66, 87, 38, 79, 30, 54, 10, 100, 67, 27, 10, 57, 63, 85, 52, 79, 5, 92, 39
    };

    begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++) {
        median_iter<vector<int>::iterator, int>(vec1.begin(), vec1.end());
    }
    end = std::chrono::steady_clock::now();

    cout << "Microseconds to run median 100 times = " 
        << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
        << endl;
}