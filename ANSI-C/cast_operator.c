#include <stdio.h>

int main() {
    float exact_length;
    int rough_length;
    
    rough_length = 12;
    exact_length = (float) rough_length;
    printf("exact_length: %f\n", exact_length);
    
    exact_length = 15.55;
    rough_length = (int) exact_length;
    printf("rough_length: %d\n", rough_length);
}
