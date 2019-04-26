/* reads characters from its input and writes the same characters to its output, except it does not write lower case vowels ('a', 'e','i', 'o', 'u')*/
// Written by XJ LI.

#include <stdio.h>

int main(void) {
    int a = getchar();
    while (a != EOF) {
        if(a != 97 && a != 101 && a != 105 && a != 111 && a != 117) {
            printf("%c", a);
        }
        a = getchar();
    }
    return 0;
}
