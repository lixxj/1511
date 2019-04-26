#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int nums[100001];
    int count[100001] = {0};
    int i = 0;
    while (scanf("%d", &n) == 1) {
        nums[i] = n;
        count[n] = count[n] + 1;
        i++;
    }
                                                                                    
    int num = 0;
    int most = count[0];
    int index = 100000;
    while (index >= 0) {
        if (count[index] > most) {
            most = count[index];
            num = index;
        } else {
            num = num + 0;
        }
        index--;
    }
    
    printf("%d\n", num);
    return 0;
}



	

