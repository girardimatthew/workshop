#include "extract_fails.h"
#include "fgrade.h"
#include "Student_info.h"
#include <vector>

#include <iostream>

using namespace std; 

// version 3: iterators but no indexing; still slow
vector<Student_info> extract_fails(vector<Student_info>& students) {    
    
    vector<Student_info> pass;
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
        } else {
            pass.push_back(*iter);
        }
        ++iter;
    }

    // cout << endl;
    // cout << endl;
    // cout << "failing students:" << endl;
    // vector<Student_info>::iterator f_iter = fail.begin();
    // while (f_iter != fail.end()) {
    //     cout << f_iter->name << ", ";
    //     ++f_iter;
    // }
    // cout << endl;

    // cout << "passing students:" << endl;
    // vector<Student_info>::iterator p_iter = pass.begin();
    // while (p_iter != pass.end()) {
    //     cout << p_iter->name << ", ";
    //     ++p_iter;
    // }
    // cout << endl;
    // cout << endl;

    students.insert(students.begin(), pass.begin(), pass.end());
    // cout << "students:" << endl;
    // iter = students.begin();
    // while (iter != students.end()) {
    //     cout << iter->name << ", ";
    //     ++iter;
    // }

    // cout << endl;
    // cout << endl;
    students.resize(pass.size());

    // cout << "students resized:" << endl;
    // iter = students.begin();
    // while (iter != students.end()) {
    //     cout << iter->name << ", ";
    //     ++iter;
    // }

    // cout << endl;
    // cout << endl;

    
    
    return fail;
}
