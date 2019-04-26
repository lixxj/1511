// Written by XJ LI
#include <stdio.h>

int main(void) {
    
    int a = getchar();
    while (a != EOF) {
        if (a == '\n' || a == ' ' || (a >= '0' && a <= '9')) 
            printf("%c", a);
        else 
            printf(".");
        
        a = getchar();
    }
    
    return 0;
}
