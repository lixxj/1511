/* given a filename as argument prints the first 10 lines of the file. If the file has less than 10 lines the entire file should be printed.
Note this program does not create any files. Its just prints part of the contents of a file to standard output.
It should also be possible to specify that a different number of lines be printed.
This will be done by passing the string "-n" as the first argument to the program
The second argument will be the the number of lines to be printed .
The file will now be the third argument to the program.*/
// Written by XJ LI.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 4) {
        FILE *stream = fopen(argv[3], "r");

        if (stream == NULL) {
            perror(argv[3]);  // prints why the open failed
            return 1;
        }
        
        int value1 = 0;  
        int sign1 = 1;  
        assert(argv[2] != NULL);  
        if(*argv[2] == '-')  
        {  
            sign1 = -1;  
            argv[2]++;  
        }else if(*argv[2] == '+')  
        {  
            *argv[2]++;  
        }  
        while(*argv[2])  
        {  
            value1 = value1 * 10 +(*argv[2] - '0');  
            argv[2]++;  
          
        }  
        int lines = sign1 * value1; 
        
        int c = fgetc(stream);

        int i = 0;

        while (c != EOF && i < lines) {
            if (c == '\n') {
                i++;
            }
            fputc(c, stdout); // write the byte to standard output
            c = fgetc(stream);
        }
    } else if (argc == 2) {
        FILE *stream = fopen(argv[1], "r");

        if (stream == NULL) {
            perror(argv[1]);  // prints why the open failed
            return 1;
        }
        
        int c = fgetc(stream);

        int i = 0;
        
        while (c != EOF && i < 10) {
            if (c == '\n') {
                i++;
            }
            fputc(c, stdout); // write the byte to standard output
            c = fgetc(stream);
        }
    } else {
        fprintf(stderr, "Error: Invalid number of command line arguments\n");
    }
    return 0;
}
