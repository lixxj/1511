//Written by XJ LI

#include <stdio.h>
int main(void) {
    int odd[100] = {0};
    int even[100] = {0};
    int x = 0;
    int y = 0;
    int i = 1;
    int a;
    while (i <= 10) {
        scanf("%d", &a);
        if (a % 2 != 0) {
            odd[x] = a;
            x++;
        }
        if (a % 2 == 0) {
            even[y] = a;
            y++;
        }
        i++;
    }
    int k = 0;
    int l = 0;
    printf("Odd numbers were:");
    while (k < x) {
        printf(" %d", odd[k]);
        k++;
    }
    printf("\n");
    printf("Even numbers were:");
    while (l < y) {
        printf(" %d", even[l]);
        l++;
    }    
    printf("\n");
    return 0;
}

