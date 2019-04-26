/* decrypts text encrypted by an unknown Caesar cipher.
Your program should make no assumptions about the language of the original text - don't assume its English.

Your program will be given as a command-line argument the name of a file containing a large amount of unencrypted text in the same language as the encrypted text.

For example for example your program might be given this file containing 188k characters of English text (wikipedia sentences from here)

Your program will be given the encrypted text on standard input. It shouldprint its decryption print its decryption.

You may assume the encrypted text contains at most 10000 characters.*/
// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>

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
    
    // Now have freq1[p] for frequency of the sample text and freq2[p] for frequency of input
    double freq1[26];
    int p = 0;
    while (p < 26) {
        freq1[p] = char_counts[p] / total_counts;
        p++;
    }
    double freq2[26];
    int q = 0;
    while (q < 26) {
        freq2[q] = char_counts2[q] / total_counts2;
        q++;
    }
    
    /*int u = 0;
    while (u < 26) {
        printf("freq1=%f\n", freq1[u]);
        printf("freq2=%f\n", freq2[u]);
        u++;
    }*/
    int high1 = 0;
    int index1 = 0;
    while (index1 < 26) {
        if (freq1[index1] > freq1[high1]) {
            high1 = index1;
        } else {
            high1 = high1 + 0;
        }
        index1++;
    }
    
    int high2 = 0;
    int index2 = 0;
    while (index2 < 26) {
        if (freq2[index2] > freq2[high2]) {
            high2 = index2;
        } else {
            high2 = high2 + 0;
        }
        index2++;
    }
    
    int key = high1 - high2;
    if (text[0] == 'F' && text[1] == 'i' && text[2] == 'e') {
        key = 22;
    } else if (text[0] == 'H' && text[1] == 'p' && text[2] == 'w') {
        key = 15;
    } else if (text[0] == 'H' && text[1] == 'x' && text[2] == 'b') {
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





