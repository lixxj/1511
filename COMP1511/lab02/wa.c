#include <stdio.h>

int main(void)
{
  printf("Please enter two integers: ");
    
    	int M; 
    	int N;
    	int K = scanf("%d", &M);
	int L = scanf("%d", &N);
	int J = K + L;
	int sum = M + N;
	if (J == 2){
    	
	if (M == 1){ printf("one");}
    	else if (M == 2){ printf("two");}
    	else if (M == 3){ printf("three");}
    	else if (M == 4){ printf("four");}
   	else if (M == 5){ printf("five");}
    	else if (M == 6){ printf("six");}
    	else if (M == 7){ printf("seven");}
    	else if (M == 8){ printf("eight");}
	else if (M == 9){ printf("nine");}
	else if (M == 10){ printf("ten");}
	else if (M == 0){ printf("zero");}
	else if (M == -1){ printf("negative one");}
	else if (M == -2){ printf("negative two");}
	else if (M == -3){ printf("negative three");}
        else if (M == -4){ printf("negative four");}
	else if (M == -5){ printf("negative five");}
	else if (M == -6){ printf("negative six");}
	else if (M == -7){ printf("negative seven");}
	else if (M == -8){ printf("negative eight");}
	else if (M == -9){ printf("negative nine");}
	else if (M == -10){ printf("negative ten");}
	else {printf("%d", M);}
	
	printf(" + ");

	if (N == 1){ printf("one");}
    	else if (N == 2){ printf("two");}
    	else if (N == 3){ printf("three");}
    	else if (N == 4){ printf("four");}
   	else if (N == 5){ printf("five");}
    	else if (N == 6){ printf("six");}
    	else if (N == 7){ printf("seven");}
    	else if (N == 8){ printf("eight");}
	else if (N == 9){ printf("nine");}
	else if (N == 10){ printf("ten");}
	else if (N == 0){ printf("zero");}
	else if (N == -1){ printf("negative one");}
	else if (N == -2){ printf("negative two");}
	else if (N == -3){ printf("negative three");}
        else if (N == -4){ printf("negative four");}
	else if (N == -5){ printf("negative five");}
	else if (N == -6){ printf("negative six");}
	else if (N == -7){ printf("negative seven");}
	else if (N == -8){ printf("negative eight");}
	else if (N == -9){ printf("negative nine");}
	else if (N == -10){ printf("negative ten");}
	else {printf("%d", N);}

        printf(" = ");

	if (sum == 1){ printf("one\n");}
    	else if (sum == 2){ printf("two\n");}
    	else if (sum == 3){ printf("three\n");}
    	else if (sum == 4){ printf("four\n");}
   	else if (sum == 5){ printf("five\n");}
    	else if (sum == 6){ printf("six\n");}
    	else if (sum == 7){ printf("seven\n");}
    	else if (sum == 8){ printf("eight\n");}
	else if (sum == 9){ printf("nine\n");}
	else if (sum == 10){ printf("ten\n");}
	else if (sum == 0){ printf("zero\n");}
	else if (sum == -1){ printf("negative one\n");}
	else if (sum == -2){ printf("negative two\n");}
	else if (sum == -3){ printf("negative three\n");}
        else if (sum == -4){ printf("negative four\n");}
	else if (sum == -5){ printf("negative five\n");}
	else if (sum == -6){ printf("negative six\n");}
	else if (sum == -7){ printf("negative seven\n");}
	else if (sum == -8){ printf("negative eight\n");}
	else if (sum == -9){ printf("negative nine\n");}
	else if (sum == -10){ printf("negative ten\n");}
	else {printf("%d\n", sum);}
}
	else {printf("integers!!!\n");}
	
	return 0;
}
