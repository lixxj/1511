#include <stdio.h>

#define SIZE_OF_ARRAY 10

int main(void) {
	
	char array[SIZE_OF_ARRAY];
	while (fgets(array, SIZE_OF_ARRAY, stdin) != NULL) {
	
	    printf("%s", array);
	}
	return 0;
}
