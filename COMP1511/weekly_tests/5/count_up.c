//reads 2 positive integers and prints the integers between them, one per line.
//written by XJ LI

#include <stdio.h>

int main(void) {
	int low, up, i;
	printf("Enter lower: ");
	scanf("%d", &low);
	printf("Enter upper: ");
	scanf("%d", &up);
	for(i = low + 1; i < up; i++) {
	    printf("%d\n", i);
	}
	return 0;
}
