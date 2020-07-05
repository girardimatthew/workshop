#include <stdio.h>

#define SIZE 3

int main() {
    int marks[SIZE];
    int i;

    for(i=0; i<SIZE-1; i++) {
        printf("Enter value for marks[%d]: ", i);
        scanf("%d",(marks+i));
    }
    printf("Processing data...\n");
    marks[SIZE-1] = (marks[0] > marks[1]) ? marks[0] : marks[1];
    printf("---- Results ---- \n");
    for(i=0;i<SIZE;i++) {
        (i < SIZE-1) ? printf("Entered marks[%d] is: %d\n", i, *(marks+i)) : printf("The biggest value is: %d\n",*(marks+i));
    }

} 
