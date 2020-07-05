#include "extract_fails.h"
#include "fgrade.h"
#include "Student_info.h"
#include <vector>

// Two-pass solution
// std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
//     std::vector<Student_info> fail;
//     remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
//     students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
//     return fail;
// }

// Single-pass solution
std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
    std::vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    std::vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}