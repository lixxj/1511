#include <stdio.h>

int main(void) {
    printf("Enter 6 integers:\n");
    int length = 6;
    int source[6];
    int index = 0;
    while (index < 6) {
        scanf("%d", &source[index]);
        index++;
    }
    int z = 0;
    int dest[length];
    while (z < length) {
        dest[z] = source[z];
        z++;
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; ) {
            if (dest[i] == dest[j]) {
                for (int k = j; k < length - 1; k++) {
                    dest[k] = dest[k + 1];
                }
                length--;
            }
            else {
                j++;
            }
        }
    }
    int y = 0;
    while (y < length) {
        dest[y];
        printf("%d,", dest[y]);
        y++;
    }
    printf("\n");
    return 0;
}

