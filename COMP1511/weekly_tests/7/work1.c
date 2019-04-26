#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // get the chars and convert it to integer
    char nums[30];
    char ch = getchar();
    nums[0] = ch;
    getchar();
    ch = getchar();
    nums[1] = ch;
    getchar();
    ch = getchar();
    nums[2] = ch;
    
    int integer = atoi (nums);
    printf("%d\n", integer);    
        
    return 0;
}











