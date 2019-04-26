#include <stdio.h>
int main(void) {
    int n, i;
    printf("Enter number: ");
    scanf("%d",&n);
    int number = n;
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
