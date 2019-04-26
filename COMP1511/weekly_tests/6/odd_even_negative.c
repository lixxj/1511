//Written by XJ LI

#include<stdio.h>

int main(void) {
    int odd[1000] = {0};
    int even[1000] = {0};
    int x = 0;
    int y = 0;
    int i = 1;
    int a;
    scanf("%d", &a);
    while (a > 0) {
        if (a % 2 != 0) {
            odd[x] = a;
            x++;
        }
        if (a % 2 == 0) {
            even[y] = a;
            y++;
        }
        i++;
        scanf("%d", &a);
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

