// Written by XJ LI

#include<stdio.h>

int main(void) {
    char input[256];
    fgets(input, 256, stdin);
    
    int x;
    scanf("%d", &x);
    
    printf("The character in position %d is '%c'\n", x, input[x]);
        
    return 0;
}
