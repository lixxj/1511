#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int main(void) {
    
    struct node *cu2 = malloc(sizeof(struct node));
    struct node *cu1 = cu2;
    
    cu2->data = 17;
    
    printf("%d\n" , cu2->data);printf("%d\n" , cu1->data);
    
    free(cu2); 
    
    printf("%d\n" , cu1->data);
    printf("%d\n" , cu2->data);

    return 0;
}
