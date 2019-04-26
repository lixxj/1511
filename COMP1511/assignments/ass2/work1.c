#include<stdio.h>

int main(void) {
    int n = 0;
    
    int index1 = 0;
    int index2 = 0;
    
    while (index1 < 10) {
        printf("%d\n", n);
        index2 = 0;
        while (index2 < 5) {
            n++;
            index2++;
        }
        
        printf("%d\n", n);
        
        index1++;
    }
                       
    printf("\nn = %d\n", n);
    
    return 0;
}
