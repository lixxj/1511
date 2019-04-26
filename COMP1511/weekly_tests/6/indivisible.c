

#include <stdio.h>

int main(void) {
    int a;
    int all[1000] = {0};
    int indiv[1000] = {0};
    int i = 0;
    while (scanf("%d", &a) == 1) {
        all[i] = a;
        i++;
    }
    int l = 0;
    int s = 0;
    int j = 0;
    int r = 3;
    while (l < i) {
        r = 3;
        j = 0;
        while (j < i) {
            if((all[l] >= all[j]) && (all[l] % all[j] == 0) && (l != j)) {
                r = r + 1;
            }
            j++;
        }
        if(r == 3) {
            indiv[s] = all[l];
            s++;
        }    
        l++;
    }
    int k = 0;
    printf("Indivisible numbers:");
    while (k < s) {
        printf(" %d", indiv[k]);
        k++;
    }
    printf("\n");
    return 0;
}
