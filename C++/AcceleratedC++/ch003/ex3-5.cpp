// Write a program that will keep track of grades for several students at once.
// The program could keep two vectors in sync: The first should hold the student's names,
// and the second the final grades that can be computed as input is read.
// For now, you should assume a fixed number of homework grades.
// We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printOut(const vector<string>& set) {
    cout << endl;
    cout << "[";
    for (int i = 0; i < set.size(); ++i) {
        cout << set[i];
        if (i < (set.size() - 1))
            cout << ", ";
    }
    cout << "]" << endl;
}

void printOut(const vector<double>& set) {
    cout << endl;
    cout << "[";
    for (int i = 0; i < set.size(); ++i) {
        cout << set[i];
        if (i < (set.size() - 1))
            cout << ", ";
    }
    cout << "]" << endl;
}

void printStudentsAndFinalGrades(const vector<string>& set, 
                                 const vector<double>& grades) {

    cout << endl << "*********************************" << endl;
    cout << "*** Students and Their final grades ***" << endl;
    for (int i = 0; i < set.size(); ++i) {
        cout << set[i] << ": " << grades[i] << endl;
    }
    cout << endl;
}

// ----------------------
// student name
string studentName;
// 
double midterm, final;
// keep track of the students 
vector<string> students;
// 
vector<double> finalGrades;

int main() { 

    cout << "Please enter the student name, or exit: ";
    // get the names
    while (cin >> studentName) {
        
        students.push_back(studentName);
        // ask for and read the midterm and final grades
        cout << "Please enter the student's midterm and final exam grades: ";
        cin >> midterm >> final; // BUG: one can enter more than two grades, 
                                 // then the third one will be the student name. 

        // ask for the homework grades
        cout << "Enter the student's homework grades, "
                "there should be 5 grades." << endl;

        // the number and sum of grades read so far
        double x;
        vector<double> homework;
        // Invariant: homework contains all the homework grades read so far
        for (int i = 0; i < 5; ++i) {
            cout << "Enter grade N." << i+1 << ": ";
            cin >> x;
            homework.push_back(x);
        }

        // check that the student entered some homework grades
        typedef vector<double>::size_type vec_sz;
        vec_sz size = homework.size();
        if (size == 0) {
            cout << endl << "You must enter your grades.   "    
                            "Please try again." << endl;
            return 1;
        }

        // find the middle element or elements
        vec_sz mid = size/2;
        double median;
        // compute the median homework grade
        median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

        double finalGrade;
        finalGrade = 0.2 * midterm + 0.4 * final + 0.4 * median;
        //cout << finalGrade << endl;
        finalGrades.push_back(finalGrade);

        cout << "Please enter the student name, or exit: ";
    }
    //printOut(students);
    //printOut(finalGrades);

    printStudentsAndFinalGrades(students, finalGrades);

    return 0;
}