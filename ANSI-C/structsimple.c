#include <stdio.h>

struct database {
    int id_number;
    int age;
    float salary;
};

int main() {
    struct database employee;
    
    employee.age = 22;
    employee.id_number = 1;
    employee.salary = 12000.21;

    printf("age: %d, ID-Number: %d, Salary: %f\n", employee.age, employee.id_number, employee.salary);
}
