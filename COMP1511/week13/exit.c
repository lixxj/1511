#include <stdio.h>
#include <stdlib.h>

void one(void) {
    printf("1\n");
    while (1) {
        break;
    }
    printf("2\n");
    
}

void two(void) {
    printf("3\n");
    exit(1);
}

int main (void) {
    one();
    two();
    printf("wwww");    
    
    return 0;
}
