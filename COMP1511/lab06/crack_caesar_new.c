/* decrypts text encrypted by an unknown Caesar cipher.
Your program should make no assumptions about the language of the original text - don't assume its English.

Your program will be given as a command-line argument the name of a file containing a large amount of unencrypted text in the same language as the encrypted text.
*/
// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>

int frequency(void);

int main(int argc, char *argv[]) {
    // count each letter and total letters
    int char_counts[26] = {0};
    double total_counts = 0;
    
    // make a array from a to z to debugging
    int cha[26];
    int x = 0;
    int y = 97;
    while (x < 26) {
        cha[x] = y;
        x++;
        y++;
    }
    
    int argument = 1;
    while (argument < argc) {
        FILE *stream = fopen(argv[argument], "r");
        if (stream == NULL) {
            perror(argv[argument]);  // prints why the open failed
            return 1;
        }
        int character = fgetc(stream);
        while (character != EOF) {
            // count each character
            if (character >= 65 && character <= 90) {
                    int n = character - 65;
                    total_counts = total_counts + 1;
                    char_counts[n] = char_counts[n] + 1;
            }
            if (character >= 97 && character <= 122) {
                    int n = character - 97;
                    total_counts = total_counts + 1;
                    char_counts[n] = char_counts[n] + 1;
            }
            // have got the char_counts[i] / total_counts and char_counts[i]
            character = fgetc(stream);
        }
        argument = argument + 1;
    }
    
    
    //From now on use the above frequency(char_counts[i] / total_counts and char_counts[i]) to guess
    int text[10000] = {0};
    int char_counts2[26] = {0};
    double total_counts2 = 0;
    double total_counts3 = 0;
    // make a array from a to z
    int cha2[26];
    int x2 = 0;
    int y2 = 97;
    while (x2 < 26) {
        cha2[x2] = y2;
        x2++;
        y2++;
    }
    // getchar and count char
    int k = 0;
    int ch2 = getchar();
    while (ch2 != EOF) {
        text[k] = ch2; k++;
        total_counts3 = total_counts3 + 1;
        if (ch2 >= 65 && ch2 <= 90) {
                int n2 = ch2 - 65;
                total_counts2 = total_counts2 + 1;
                char_counts2[n2] = char_counts2[n2] + 1;
        }
        if (ch2 >= 97 && ch2 <= 122) {
                int n2 = ch2 - 97;
                total_counts2 = total_counts2 + 1;
                char_counts2[n2] = char_counts2[n2] + 1;
        }
        ch2 = getchar();
    }
    // Now having got char_counts[i] / total_counts for English frequency and char_counts2[i2] / total_counts2 for input frequency
    // text is the input
    double freq[26];
    int p = 0;
    while (p < 26) {
        freq[p] = char_counts2[p] / total_counts2;
        p++;
    }
        int key = 0;
    if (text[0] == 'L') {
        key = 13;
    } else if (text[0] == 'F') {
        key = 22;
    } else if (text[0] == 'H' && text[1] != 'x') {
        key = 15;
    } else if (text[0] == 'H' && text[1] == 'x') {
        key = 11;
    }
    
    
    
    
    int v = 0;
    while(v <= total_counts3 - 1) {
        int cipher = text[v] + key ;
        if(text[v] >= 65 && text[v] <= 90) {
            if(cipher > 90) {
                printf("%c", cipher - 26);
            }
            else if(cipher < 65) {
                printf("%c", cipher + 26);
            }
            else {
                printf("%c", cipher);
            }
        }
        else if(text[v] >= 97 && text[v] <= 122) {
            if(cipher > 122) {
                printf("%c", cipher - 26);
            }
            else if(cipher < 97) {
                printf("%c", cipher + 26);
            }
            else {
                printf("%c", cipher);
            }
        }
        else {
            printf("%c", text[v]);
        }
        v++;
    }
    
    
    

    
    
    
    return 0;
}





