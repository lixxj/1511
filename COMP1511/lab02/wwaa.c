#include <stdio.h>

int main(void)
{
    	printf("Please enter two integers: ");
    
    	int M; 
    	int N;
    	int K = scanf("%d", &M);
	int L = scanf("%d", &N);
	int J = K + L;
	
	if(J == 2){
	
	char *j[21]={"negative ten","negative nine","negative eight","negative seven","negative six","negative five","negative four","negative three","negative two","negative one","zero","one","two","three","four","five","six","seven","eight","nine","ten"};
	
	int sum = M + N;
    	int x = M + 10;
    	int y = N + 10;
	int yx = sum + 10;
    
    	if(M>=-10&&M<=10){printf("%s + ", j[x]);}

    	else{printf("%d + ", M);}
 
    	if(N>=-10&&N<=10){printf("%s", j[y]);}

    	else{printf("%d", N);}

	if(sum>=-10&&sum<=10){printf(" = %s\n", j[yx]);}

    	else{printf(" = %d", sum);}
}
	else {printf("integers!!!\n");}

    	return 0;
}
    
       
