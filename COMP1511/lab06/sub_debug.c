#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        int i = 0;
        while (i < 26) {
            printf("%d\n", argv[1][i]);
            i = i + 1;
        }
    return 0;
}




