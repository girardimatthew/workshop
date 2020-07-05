#include <stdio.h>

#define ARRAYSIZE 21

int main() {
    int array1[ARRAYSIZE];
    int array2[ARRAYSIZE];
    int output[ARRAYSIZE];
    int i, j;
    
    for (i=0; i<ARRAYSIZE; i++) {
        array1[i] = 2*i;
        array2[i] = 3*i;
        output[i] = array1[i] * array2[i];
        printf("array1[%d]: %d  |  array2[%d]: %d  |  output[%d]: %d\n", i, array1[i], i, array2[i], i, output[i]);
    }
}
