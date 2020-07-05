//
//  main.cpp
//  ex5-2_performace
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

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
#include "StudentInfoContainerType.h"

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
    
    string file = "students10000.txt";
    ifstream infile;
    
    StudentInfoContainerType students, failed;
    
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
