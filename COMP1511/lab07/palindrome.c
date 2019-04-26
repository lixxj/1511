// A palindrome is a sequence which is the same forwards as backwards.
// Written by XJ LI.

#include <stdio.h>

int main(void) {
    printf("Enter a string: ");
    int a = getchar();
    int input[4096] = {0};
    int i = 0;
    while (a != '\n') {
        input[i] = a;
        i++;
        a = getchar();
    }
    int n = i;
    int m = i;
    if (n % 2 == 0) {
        int x = 0;
        int u = 3;
        while (x <= m / 2) {
            if (input[x] != input[(m - x - 1)]) {
                u = u + 1;
            }
            x++;
        }
        if (u == 3) {
            printf("String is a palindrome\n");
        }
        else {
            printf("String is not a palindrome\n");
        }
    }
    
    if (m % 2 != 0) {
        int y = 0;
        int v = 3;
        while (y < (m + 1) / 2) {
            if (input[y] != input[(m - y - 1)]) {
                v = v + 1;
            }
            y++;
        }
        if (v == 3) {
            printf("String is a palindrome\n");
        }
        else {
            printf("String is not a palindrome\n");
        }
    }
    return 0;
}
