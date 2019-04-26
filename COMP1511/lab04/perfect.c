//Reads a positive integer n from standard input and prints all the factors of n, their sum and if indicates if n is a perfect number.
//A positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself.
//Written by XJ Li.


#include <stdio.h>

int main(void) {
    
    int n;
    
    printf("Enter number: ");
	scanf("%d",&n);
	printf("The factors of %d are:\n", n);

    int f = 1;
    int sum = 0;
    while(f <= n) {
        if(n % f == 0) {
            printf("%d\n", f);
            sum = sum + f;
            }
    f = f + 1;
    }
    printf("Sum of factors = %d\n", sum);
    
	if(sum == 2 * n) {
	printf("%d is a perfect number\n", n);
    }
	else{
    printf("%d is not a perfect number\n", n);
    }
    
    return 0;
}



	


