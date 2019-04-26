/*reads 2 positive integers and calculates the product of the odd integers between the first and second integers.
For example, if the two integers entered are 10 and 16 then 2145 should be printed because 11 * 13 * 15 = 2145.
If there are no odd integers between the first and second integers, your program should print 1.*/
//Written by XJ LI

#include <stdio.h>

int main(void) {
	int low, up, i;
	int product = 1;
	printf("Enter lower: ");
	scanf("%d", &low);
	printf("Enter upper: ");
	scanf("%d", &up);
	for(i = low + 1; i < up; i++) {
	    if(i % 2 != 0) {
	        product = product * i;    
	    }
	    else {
	        product = product * 1;
	    }
	}
	printf("%d\n", product);
	return 0;
}
