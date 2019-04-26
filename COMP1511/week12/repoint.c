#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 3;
    int b = 6;
    
    int *c = &a;
    printf("%d\n" , *c);
    
    c = &b;
    printf("%d\n" , *c);

    return 0;
}
