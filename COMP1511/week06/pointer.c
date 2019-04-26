#include <stdio.h>

int main(void) {
	int num = 1;
    printf("%d\n", num);
    
    int *numPointer = &num;
    
    *numPointer = 2;
    printf("%d\n", num);
    printf("%d\n", *numPointer);
    
    printf("%p\n", numPointer);
    printf("%p\n", &num);
    
    num = 3;
    printf("%d\n", num);
    printf("%d\n", *numPointer);
    
	return 0;
}
