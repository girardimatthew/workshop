//value parameters
//passing the parameters by value only

#include <stdio.h>

int main (void);
int calculate_bill (int, int, int);

int main() {
    int bill;
    int fred = 25;
    int frank = 32;
    int franny = 27;

    bill = calculate_bill(fred, frank, franny);
    printf("The total bill comes to $%d.00\n", bill);
}

int calculate_bill(int dinner1, int dinner2, int dinner3) {
    int total;
    
    total = dinner1 + dinner2 + dinner3;
    return total;
}
