// compute factorials

#include <stdio.h>
#include <stdlib.h>

int fac(int n)
{
    if (n < 0) {
        return -1;
    } else if (n < 2) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

int main(void)
{
	int x;
	
    printf("Enter number: ");
    scanf("%d", &x);
    
    printf("%d! = %d\n", x, fac(x));
    
    return 0;
}

