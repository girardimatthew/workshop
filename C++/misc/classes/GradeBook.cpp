// Member-function definitions for class GradeBook that
// uses an array to store test grades.
#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

// Constructor initializes courseName and grades array
GradeBook::GradeBook(string name, const int gradesArray[]) {
	setCourseName(name); // initialize CouseName;

	// copy grades from gradesArray to grades data member
	for (int i = 0; i < students; ++i)
		grades[i] = gradesArray[i];
}

// function to set the course name
void GradeBook::setCourseName(string name) {
	courseName = name;
}

// function to retrieve the course name
string GradeBook::getCourseName() {
	return courseName;
}

// display a welcome message to the Gradebook user
void GradeBook::displayMessage() {
	cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}

// perform various operations on the data
void GradeBook::processGrades() {
	outputGrades(); // output grades array
   	
   	// display average of all grades and minimum and maximum grades
   	cout << "\nClass average is " << setprecision(2) << fixed << getAverage() << 
   	"\nLowest grade is " << getMinimum() << "\nHighest grade is " << getMaximum() << endl;

   	outputBarChart(); // print grade distribution chart 
}

// find minimum grade
int GradeBook::getMinimum() {
	int lowGrade = 100;
	// loop through grades array
	for (int i = 0; i < students; ++i) {
		if (grades[i] < lowGrade)
			lowGrade = grades[i];
	}

	return lowGrade;
}

// find maximum grade
int GradeBook::getMaximum() {
	int highGrade = 0;
	// lopp through
	for (int i = 0; i < students; ++i) {
		if (grades[i] > highGrade) 
			highGrade = grades[i];
	}

	return highGrade;
}

// determine average grade for test
double GradeBook::getAverage() {
	int total = 0;
	
	for (int i = 0; i < students; ++i)
		total += grades[i];

	return static_cast<double>(total)/students;
}

// output bar chart displaying grade distribution
void GradeBook::outputBarChart() {
	cout << "\nGrade distribution:" << endl;

	// stores frequency of grades in each range of 10 grades
	const int frequencySize = 11;
	int frequency[frequencySize] = {}; // initialize elements to 0
	// for each grade, increment the appropriate frequency
	for (int i = 0; i < students; ++i)
		++frequency[grades[i]/students];

	// for each grade frequency, print bar in chart
	for (int i = 0; i < frequencySize; ++i) {
		// output bar labels ("0-9:", ..., "90-99:", "100:")
		if (i==0)
			cout << "  0-9: ";
		else if (i==10)
			cout << "  100: ";
		else 
			cout << i*10 << "-" << (i*10)+9 << ": ";

		// print bar of asteriks
		for (int stars = 0; stars < frequency[i]; ++stars)
			cout << "*";

		cout << endl;
	}
}

void GradeBook::outputGrades() {
	cout << "\nThe grades are:\n\n";

	// output each student's grade
	for ( int student = 0; student < students; ++student )
		cout << "Student " << setw( 2 ) << student + 1 << ": " << setw( 3 ) << grades[ student ] << endl;
}