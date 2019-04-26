#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int *p;

    p = (int*)malloc(sizeof(int) * 10);
    printf("%d\n", p[0]);
	printf("%d\n", p[9]);
	printf("%d\n", p[100]);
	
	free(p);

	return 0;
}

