#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include "Student_info.h"
#include "List.h"

using std::streamsize;
using std::domain_error;
using std::sort;

void program() {
    
    List<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // TODO .begin() .end()
    // alphabetize the student records
    //sort(students.begin(), students.end(), compare);

    // TODO .size() []
    // write the name and grades
    // for (List<Student_info>::size_type i = 0; i != students.size(); ++i) {
    //     cout << students[i].name()
    //          << string(maxlen + 1 - students[i].name().size(), ' ');
        
    //     double final_grade = students[i].grade();
    //     string grade = students[i].pass_or_fail();
    //     streamsize prec = cout.precision();
        
    //     cout << setprecision(3) 
    //          << grade
    //          << " - "
    //          << final_grade
    //          << setprecision(prec) 
    //          << endl;
    // }
}

void testing() {
    List<int> list;
    list.push_back(0);
    list.push_back(42);
    list.push_back(11);
    list.push_back(5);
    list.print();
    list.clear();
    list.print();
    cout << std::boolalpha << "list is empty: " << list.empty() << endl;

    list.push_back(0);
    list.push_back(42);
    list.push_back(11);
    list.push_back(5);
    list.print();
}

int main() {

    testing();
    //program();

    return 0;
}