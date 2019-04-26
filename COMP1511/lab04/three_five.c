//Reads a positive integer n and print all the positive integers < n divisible by 3 or 5.
//Written by XJ Li.


#include <stdio.h>

int main (void) {
    int n;
    int m = 1;

    printf("Enter number: ");
    scanf("%d", &n);
    
    while (m < n) {
        if ((m % 3 == 0) || (m % 5 == 0)) {
        printf("%d\n", m);
        }
    m = m + 1;
    }
    
    return 0;
}

