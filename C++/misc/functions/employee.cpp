#include <iostream>

using namespace std;

struct Employee {
  string name;
  string title;
  string ssnum;
  double salary;
  int withholding;
};

Employee empRec = {
  "Aieie Brazorf",
  "thief",
  "271-82-8183",
  350.00,
  2
};

void printEmployeeName(const Employee &employee) {
  cout << employee.name << endl;
}

int main() {

  printEmployeeName(empRec);

}
