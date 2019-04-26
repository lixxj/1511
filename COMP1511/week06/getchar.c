#include <stdio.h>

int main(void) {
    int a = getchar();
    while (a != EOF/*a != EOF*/) {
        
        printf("%c", a);
        
        a = getchar();
    }
    return 0;
}
