// Written by XJ LI

#include<stdio.h>

int main(void) {
    int input[256];
    int index = 1;
    while (1) {
        int size = 0;
        int a = getchar();
        if (a == EOF) {
            break;
        }
        while (a != '\n') {
            input[size] = a;
            size++;
            a = getchar();
        }
        size--;
        while (size >= 0) {
            printf("%c", input[size]);   
            size--; 
        }
        printf("\n");
    }
    
    return 0;
}
