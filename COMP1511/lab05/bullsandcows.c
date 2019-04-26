#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    int a[30] = {0};
    int b[30] = {0}; 
    int c[30] = {0};
    int d[30] = {0};
    int B[30] = {0};
    int C[30] = {0};
    int B1;
    int C1;
    int i = 0, j = 0;
    srand(time(NULL));
     
    if(i == 0) {
            d[i] = 3;
            c[i] = 2;
            b[i] = 1;
            a[i] = 1;
            printf("\nGuess : %d%d%d%d\n", a[i], b[i], c[i], d[i]);
            printf("Bulls : ");
            scanf("%d", &B[i + 1]);
            if(B[i + 1] != 4) {
                printf("Cows : ");
                scanf("%d", &C[i + 1]);
            }
            else {
                printf("\nuse %d turns\n", i + 1);
            }
            i = i + 1;
    }
    
    
    
    
    for(i = 1; B[i] != 4; i++) {
            d[i] = rand() % 10;
            c[i] = rand() % 10;
            b[i] = rand() % 10;
            a[i] = rand() % 10;printf("%d%d%d%d\n", a[i], b[i], c[i], d[i]);
        
            
            while(B1 != B[i] || C1 != C[i]) {
                B1 = 0;
                C1 = 0;
            
                if(a[i - 1] == b[i] || a[i - 1] == c[i] || a[i - 1] == d[i]) {
                    C1 = C1 + 1;
                }
                else if(a[i - 1] == a[i]) {
                    B1 = B1 + 1;
                }
            
                if(b[i - 1] == a[i] || b[i - 1] == c[i] || b[i - 1] == d[i]) {
                    C1 = C1 + 1;
                }
                else if(b[i - 1] == b[i]) {
                    B1 = B1 + 1;
                } 
            
                if(c[i - 1] == b[i] || c[i - 1] == a[i] || c[i - 1] == d[i]) {
                    C1 = C1 + 1;
                }
                else if(c[i - 1] == c[i]) {
                    B1 = B1 + 1;
                }
            
                if(d[i - 1] == b[i] || d[i - 1] == c[i] || d[i - 1] == a[i]) {
                    C1 = C1 + 1;
                }
                else if(d[i - 1] == d[i]) {
                    B1 = B1 + 1;
                }
                printf("B1 = %d,C1 = %d\n", B1, C1);
                if(B1 != B[i] || C1 != C[i]) {
                    d[i] = rand() % 10;
                    c[i] = rand() % 10;
                    b[i] = rand() % 10;
                    a[i] = rand() % 10;printf("%d%d%d%d>\n", a[i], b[i], c[i], d[i]);
                
                }
            }
            printf("\nGuess : %d%d%d%d\n", a[i], b[i], c[i], d[i]);
            printf("Bulls : ");
            scanf("%d", &B[i + 1]);
            if(B[i + 1] != 4) {
                printf("Cows : ");
                scanf("%d", &C[i + 1]);
            }
            else {
                printf("\nuse %d turns\n", i + 1);
            }
    }
       getchar();
       return 0;
}

