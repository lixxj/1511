/* reads characters from its input and writes the characters to its output encrypted with a Caesar cipher.
The number of positions to shift will be given to your program as a command line argument.
Your program should contain at least one function other than main.*/
// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>
void caesar_cipher(int test, int shift);

int main(int argc, char *argv[]) {

    int shift = 0;
    int i = 1;
    while (i < argc) {
       shift = shift + atoi(argv[i]);
       i = i + 1;
    }
    int a = getchar();
    while (a != EOF) {
        caesar_cipher(a, shift);
        a = getchar();
    }
    return 0;
}

void caesar_cipher(int test, int shift) {
    while(shift < 0) {
        shift = shift + 26;
    }
    while(shift >= 26) {
        shift = shift - 26;
    }
    int cipher = test + shift;
    if(test >= 65 && test <= 90) {
        if(cipher > 90) {
            printf("%c", cipher - 26);
        }
        else if(cipher < 65) {
            printf("%c", cipher + 26);
        }
        else {
            printf("%c", cipher);
        }
    }
    else if(test >= 97 && test <= 122) {
        if(cipher > 122) {
            printf("%c", cipher - 26);
        }
        else if(cipher < 97) {
            printf("%c", cipher + 26);
        }
        else {
            printf("%c", cipher);
        }
    }
    else {
        printf("%c", test);
    }
}






