#include <stdio.h>
#include <string.h>

int main(void) {
    char s[5] = "hello";
    int i = strlen(s);
    printf("Length of %s is %d\n", s, i);
    
    return 0;
}
