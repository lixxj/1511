// Andrew Taylor - andrewt@unsw.edu.au
// 6/3/2017

// A simple program to check Pythagorean identity

// Demonstrates danger of use == with doubles
// e.g. enter 1 for theta

#include <stdio.h>
#include <math.h>

int main(void) {
    double theta, identity;

    printf("Enter theta: ");
    scanf("%lf", &theta);

//    double sin_squared = sin(theta) * sin(theta);
//    double cos_squared = cos(theta) * cos(theta);
//    identity = 1 - (sin_squared + cos_squared);
    identity = 1 - (sin(theta)*sin(theta) + cos(theta)*cos(theta));

    if (identity == 0.0) {
        printf("True for %lf\n", theta);
    } else {
        printf("Wrong by %g for %lf\n", identity, theta);
    }

    return 0;
}
