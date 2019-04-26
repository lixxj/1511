// Written by XJ LI
#include <stdio.h>
#include <ctype.h>         // for isspace()
#include <stdbool.h>       // for bool, true, false

int main(void) {

    char c;                 // read in character
    char prev;              // previous character read
    long n_chars = 0L;      // number of characters
    int n_lines = 0;        // number of lines
    int n_words = 0;        // number of words
    int p_lines = 0;        // number of partial lines
    bool inword = false;    // == true if c is in a word

    prev = '\n';            // used to identify complete lines

    while ((c = getchar()) != EOF) {
        n_chars++;          // count characters
        if (c == '\n') {
            n_lines++; 
        }     // count lines

        if (!isspace(c) && !inword) {
            inword = true;  // starting a new word
            n_words++;      // count word
        }

        if (isspace(c) && inword) {
            inword = false;
        } // reached end of word

        prev = c;           // save character value

    }

    if (prev != '\n') {
        p_lines = 1;
    }

    printf("%d lines %d words %ld characters\n", n_lines, n_words, n_chars);
    
    return 0;

}

        
    

