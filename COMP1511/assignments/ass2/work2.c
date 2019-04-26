#include<stdio.h>

int main(void) {
    int n;
    printf("enter a 2 digits integer\n");
    scanf("%d", &n);
    int digit1 = n % 10;
    int digit2 = (n % 100 - n % 10) / 10;
    printf("digit1 = %d\ndigit2 = %d\n", digit1, digit2);
    
    return 0;
}
