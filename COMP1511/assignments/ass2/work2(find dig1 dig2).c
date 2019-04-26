#include<stdio.h>

int main(void) {
    int n;
    printf("enter a 2 digits integer\n");
    scanf("%d", n);
    int digit1 = number % 10;
    int digit2 = number % 100 - number % 10;
    printf("digit1 = %d\ndigit2 = %d\n", digit1, digit2);
    
    return 0;
}
