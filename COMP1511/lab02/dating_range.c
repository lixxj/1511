//dating range
//This is a pair exercise to complete with your lab partner. A popular rule for dating is that you should not date anyone younger than half your age + 7
//reads a person's age and calculates the upper and lower age limits of people they should date according to this rule
//XJ

#include <stdio.h>

int main(void)
{
    printf("Enter your age: ");
    int M;
    scanf("%d", &M);
    int N;
    int P;
    N = (0.5 * M) + 7;
    P = ((M - 7) * 2);
    if ( M < 18 ) {
        printf("You are too young to be dating.\n");}
    else          {
        printf("Your dating range is %d to %d years old.\n", N, P);}
    return 0;
}
