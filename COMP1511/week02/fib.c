// compute fibonacci numbers

#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if (n < 0) return -1;
    if (n < 2) return 1;
    return fib(n - 1) + fib(n-2);
}

int main(void)
{
	int x;
	
    printf("Enter number: ");
    scanf("%d", &x);
    
    printf("fib %d = %d\n", x, fib(x));
    
    return 0;
}

