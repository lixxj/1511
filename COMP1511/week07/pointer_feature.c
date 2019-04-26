#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int nums[5] = {1, 2, 3, 4, 5};
    
    int value = 6;
    
    int *pointer = &value;
    
    printf("pointer[0] is %d\n", pointer[0]);
    printf("*pointer is %d\n", *pointer);
    printf("value is %d\n", value);
    
    
    // attention: pointers can not be redefinated 
    int *pointer2;
    pointer2 = (int *) malloc(5 * sizeof(int));
    pointer2 = nums;
    
    printf("pointer[0] is %d\n", pointer2[0]);
    printf("*pointer is %d\n", *pointer2);
    printf("nums[0] is %d\n", nums[0]);
    
    free(pointer2);
    
    return 0;
}
