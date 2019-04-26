/* takes 3 arguments.
The first & second arguments will specify a range of integers.
The third argument will specify a filename.
YOur program should create a file of this name containing the specified integers.*/
// Written by XJ LI.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 4) {
        FILE *output = fopen(argv[3], "w");
        
        if (output == NULL) {
            perror(argv[3]);  // prints why the open failed
            return 1;
        }
        
        int value1 = 0;  
        int sign1 = 1;  
        assert(argv[1] != NULL);  
        if(*argv[1] == '-')  
        {  
            sign1 = -1;  
            argv[1]++;  
        }else if(*argv[1] == '+')  
        {  
            *argv[1]++;  
        }  
        while(*argv[1])  
        {  
            value1 = value1 * 10 +(*argv[1] - '0');  
            argv[1]++;  
          
        }  
        int lower = sign1 * value1;  
        // printf("%d\n", lower);
        
        int value2 = 0;  
        int sign2 = 1;  
        assert(argv[2] != NULL);  
        if(*argv[2] == '-')  
        {  
            sign2 = -1;  
            argv[2]++;  
        }else if(*argv[2] == '+')  
        {  
            *argv[2]++;  
        }  
        while(*argv[2])  
        {  
            value2 = value2 * 10 +(*argv[2] - '0');  
            argv[2]++;  
          
        }  
        int upper = sign2 * value2;  
        // printf("%d\n", upper);
        
        while (lower <= upper) {
            fprintf(output, "%d\n", lower);
            lower++;
        }
    }
    else {
          fprintf(stderr, "Wrong numbers of arguments!!!!!\n");
    }
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
  
