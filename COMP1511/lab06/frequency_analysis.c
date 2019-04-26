/* reads characters from its input until end of input.
It should then print the occurance frequency for each of the 26 letters 'a'..'z'.

The frequency should be printed as a decimal value and an absolute number in exactly the format below.

Note upper and lower case letters are counted together.*/
// Written by XJ LI.

#include <stdio.h>

int main(void) {
    // count each letter and total letters
    int char_counts[26] = {0};
    double total_counts = 0;
    // make a array from a to z
    int cha[26];
    int x = 0;
    int y = 97;
    while (x < 26) {
        cha[x] = y;
        x++;
        y++;
    }
    // getchar and count char
    int ch = getchar();
    while (ch != EOF) {
        if (ch >= 65 && ch <= 90) {
                int n = ch - 65;
                total_counts = total_counts + 1;
                char_counts[n] = char_counts[n] + 1;
        }
        if (ch >= 97 && ch <= 122) {
                int n = ch - 97;
                total_counts = total_counts + 1;
                char_counts[n] = char_counts[n] + 1;
        }
        ch = getchar();
    }
    // output
    int i = 0;
    while (i < 26) {
        printf("'%c' %lf %d\n", cha[i], char_counts[i] / total_counts, char_counts[i]);
        i++;
    }
    return 0;
}


