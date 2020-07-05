#include "extract_fails.h"
#include "fgrade.h"
#include "Student_info.h"
#include <vector>


std::vector<Student_info> extract_fails(std::vector<Student_info>& students) {
    return extract(students, pgrade);
}

std::vector<Student_info> extract_didnt_all_hw(std::vector<Student_info>& students) {
    return extract(students, did_all_hw);
}

std::vector<Student_info> extract_best(std::vector<Student_info>& students) {
    return extract(students, tgrade);
}

// Single-pass solution
std::vector<Student_info> extract(
    std::vector<Student_info>& students, 
    bool predicate(const Student_info&)) {

        std::vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), predicate);
        std::vector<Student_info> extr(iter, students.end());
        students.erase(iter, students.end());
        return extr;
}