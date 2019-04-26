// reads in a line from standard input and writes out the characters one_per_line per line.
// Do not write a line for the new line character.
// Written by XJ LI

#include <stdio.h>

int main(void) {
    
    printf("Enter a string: ");
    int a = getchar();
    int input[10000] = {0};
    int i = 0;
    while (a != '\n') {
        input[i] = a;
        i++;
        a = getchar();
    }
    int l = 0;
    while (l < i) {
        printf("%c", input[l]);
        printf("\n");
        l++;
    }
    
    return 0;
}
