// Does somethnig with files
// Andrew Bennett
// 2018-04-11

#include <stdio.h>

int main(int argc, char *argv[]) {

    // opens a file called  "output.txt" in "writing" mode
    // step 1. open file
    // "r" = read
    // "a" = append
    // "w" = "overwrite" (delete if existing)
    
    FILE *output_file = fopen("output.txt", "w");

    // prints "Hello!" to the file
    // step 2. 
    fprintf(output_file, "Hello!\n");
    
    // we can also print to stdout (these are the same thing)
    printf("Hello!\n");
    fprintf(stdout, "Hello!\n");
    
    // and also stderr
    fprintf(stderr, "HELP SOMETHING IS BROKEN!!!!!\n");
    
    return 0;
}


