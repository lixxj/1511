#include <stdio.h>

int main(void) {
    int value = 6;
    fprintf(stdout, "%d\n", value);
    
    int a;
    fscanf(stdin, "%d", &a);
    fprintf(stdout, "%d\n", a);
   
    return 0;
}
