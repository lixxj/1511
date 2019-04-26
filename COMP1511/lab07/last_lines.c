// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        FILE *stream = fopen(argv[1], "r");

        if (stream == NULL) {
            perror(argv[1]);  // prints why the open failed
            return 1;
        }
        
        int c = fgetc(stream);

        int total_lines = 0;
        
        while (c != EOF) {
            if (c == '\n') {
                total_lines++;
            }
            c = fgetc(stream);
        }
        fclose(stream);
        
        FILE *stream2 = fopen(argv[1], "r");
        int line = 0;
        int n = 0;
        int h = fgetc(stream2);
        
        while (line < total_lines - 10) {
            if (h == '\n') {
                h = fgetc(stream2);
                line++;
            } else {
                h = fgetc(stream2);
            }
        }
        while (h != EOF && line <= total_lines  && line >= (total_lines - 10) && n < 10) {
            if (h == '\n') {
                n++;
                line++;
            }
            fputc(h, stdout); // write the byte to standard output
            h = fgetc(stream2);
        }
    } else {
        fprintf(stderr, "Error: Invalid number of command line arguments\n");
    }
    return 0;
}
