#include <stdio.h>

void swap(int *px, int *py) {
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int a = 3;
    int b = 7;
    
    printf("a: %d, b: %d\n", a, b);
    swap(&a,&b);
    printf("a: %d, b: %d\n", a, b);
}
