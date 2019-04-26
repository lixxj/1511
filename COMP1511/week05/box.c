


#include <stdio.h>

int main(void) {
    int i = 0;
    int x, y, n;
    scanf("%d", &n);
    while (i < n * n) { 
        x = i % n;
        y = i / n;
        
        printf(" * "); 
        i++;
        if(i / n == 0) {
            printf("\n");
        }
    }
    return 0;
}
