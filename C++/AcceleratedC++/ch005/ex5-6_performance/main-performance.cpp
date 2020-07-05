#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <chrono>
#include "Student_info.h"
#include "fgrade.h"
#include "extract_fails.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::list;
using std::max;
using std::ifstream;
using std::chrono::steady_clock;

int main() {
    
    string file = "students1000.txt";
    ifstream infile;
    
    vector<Student_info> students, failed;
    
    infile.open(file);
    read(infile, students);
    infile.close();
    infile.clear();
    
    steady_clock::time_point begin = std::chrono::steady_clock::now();
    failed = extract_fails(students);
    steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Microseconds to extract failed from " << file << " = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
    
    return 0;
}
