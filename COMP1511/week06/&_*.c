#include <stdio.h>
int s(int *a);
int main(void) {
	int a = 1;
	printf("a = %d\n", a);
	printf("%p\n", &a);
	
	s(&a);
	
	printf("a = %d\n", a);
	printf("%p\n", &a);
	return 0;
}

int s(int *a) {
    int b = 6;
    printf("b = %d s\n", b);
    *a = b;
    printf("*a = %d s\n", a);
    printf("%p s\n", &a);
    return 0;
}
