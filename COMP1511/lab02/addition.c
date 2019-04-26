//"Please enter two integers"
//ask for two integers using the message please enter two integers: then display the sum of the integers as n + n = sum.
//XJ

#include <stdio.h>

int main(void)
{
    printf("Please enter two integers: ");
    int M; 
    int N;
    scanf("%d", &M);
    scanf("%d", &N);
    int sum = M + N;
    printf("%d + %d = %d\n", M, N, sum);
    return 0;
}
