#include <stdio.h>

int main(void) {
    int i,j,x,a[10]={12,5,4,23,8,18,41,34,15,9};
    printf("delete which num:\n");
    scanf("%d",&x);
    for(i=0;i<10;++i) {
        if(x==a[i]) {
            for(j=i;j<9;++j)  
            a[j]=a[j+1];
            a[9]=0;
            break;
        }
    }
    if(i==10) {
        printf("no such num in array\n");
    } else { 
        for(i=0;i<9;++i)  
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}
