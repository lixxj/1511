// Say hello to someone
// ...

#include <stdio.h>

int main(void)
{
    char name[4];

    printf("What's your name? ");
    
    scanf("%s", name);
    
    printf("hello, %s, congratulations!!!\n", name);
    
    return 1;
}
