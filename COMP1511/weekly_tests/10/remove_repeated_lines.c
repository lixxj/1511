// Written by XJ LI

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int check_new(int n, char existing[256][256]);

int main(void) {
    char input[256][256];
    int i = 0;
    
    while (fgets (input[i], 256, stdin) != NULL) {
        if (check_new(i, input) == 1){
            printf ("%s", input[i]);
        }
        i++;
    }
    
    return 0;
}

int check_new(int n, char existing[256][256]) {
    int result = 1;
    int i = 0;
    while (i < n) {
        if (strcmp(existing[i], existing[n]) == 0) {
            result = 0;
        }
        i++;
    }

    return result;
}
