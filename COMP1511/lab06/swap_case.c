/* reads characters from its input and writes the same characters to its output with lower case letters converted to upper case and upper case letters converted to lower case*/
// Written by XJ LI.

#include <stdio.h>

int main(void) {
    int a = getchar();
    while (a != EOF) {
        int b = a + 32;
        int c = a - 32;
        if(a >= 65 && a <= 90) {
            printf("%c", b);
        }
        else if(a >= 97 && a <= 122) {
            printf("%c", c);
        }
        else {
            printf("%c", a);
        }
        a = getchar();
    }
    return 0;
}
