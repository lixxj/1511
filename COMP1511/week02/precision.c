// Andrew Taylor - andrewt@unsw.edu.au
// 6/3/2017

// Demonstrate approximate representation of reals
// The value a can not be precisely represented as a real
// As a result a non-zero value is printed

#include <stdio.h>

int main(void) {
    double a, b;
    a = 0.1;
    b = 1 - (a + a + a + a + a + a + a + a + a + a);
    printf("%g\n", b);
    return 0;
}
