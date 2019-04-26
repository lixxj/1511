/*reads a integer n from standard input and prints the decomposition of n into prime factors.
If n is prime it should instead print "n is prime" (where n is the integer).*/
//Written by XJ LI

#include <stdio.h>

int main(void) {
	int n, i;
	printf("Enter number: ");
	scanf("%d", &n);
    int number = n;
    for (i = 2; i < n;) {
        if (n % i == 0) {
        n = n / i;
        }
        else {
        i++;
        }
    }
    if(n != number) {printf("The prime factorization of %d is:\n", number);}
    
    n = number;
    for (i = 2; i < n;) {
        if (n % i == 0) {
        printf("%d * ", i);
        n = n / i;
        }
        else {
        i++;
        }
    }
    if(n == number) {
        printf("%d is prime\n", number);
    }
    else {
    printf("%d",n);
    printf(" = %d\n",number);
    }
	return 0;
}
