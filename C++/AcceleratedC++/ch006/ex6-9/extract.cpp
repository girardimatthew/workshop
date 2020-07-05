#include "extract.h"
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

std::vector<std::string> extract_name(std::vector<Student_info>& students) {
    std::vector<std::string> students_names;
    for (std::vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
        students_names.push_back(iter->name);
    }
    return students_names;
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