/* reads characters from its input and writes the characters to its output encrypted with a Substitution cipher.
The mapping will be given to your program as a single command line argument. This command line argument will contain 26 characters: an ordering of the letters 'a'..'z'.
Your program should contain at least one function other than main.*/
// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>
void sub(int letter, int shift);

int main(int argc, char *argv[]) {
    int a = getchar();
    while (a != EOF) {
        int shiftt;
        if(a == 97 || a == 65) {
            shiftt = argv[1][0] - 97;        
        }
        else if(a == 98 || a == 66) {
            shiftt = argv[1][1] - 98;        
        }
        else if(a == 99 || a == 67) {
            shiftt = argv[1][2] - 99;       
        }
        else if(a == 100 || a == 68) {
            shiftt = argv[1][3] - 100;        
        }
        else if(a == 101 || a == 69) {
            shiftt = argv[1][4] - 101;        
        }
        else if(a == 102 || a == 70) {
            shiftt = argv[1][5] - 102;        
        }
        else if(a == 103 || a == 71) {
            shiftt = argv[1][6] - 103;        
        }
        else if(a == 104 || a == 72) {
            shiftt = argv[1][7] - 104;        
        }
        else if(a == 105 || a == 73) {
            shiftt = argv[1][8] - 105;        
        }
        else if(a == 106 || a == 74) {
            shiftt = argv[1][9] - 106;        
        }
        else if(a == 107 || a == 75) {
            shiftt = argv[1][10] - 107;        
        }
        else if(a == 108 || a == 76) {
            shiftt = argv[1][11] - 108;     
        }
        else if(a == 109 || a == 77) {
            shiftt = argv[1][12] - 109;        
        }
        else if(a == 110 || a == 78) {
            shiftt = argv[1][13] - 110;        
        }
        else if(a == 111 || a == 79) {
            shiftt = argv[1][14] - 111;       
        }
        else if(a == 112 || a == 80) {
            shiftt = argv[1][15] - 112;        
        }
        else if(a == 113 || a == 81) {
            shiftt = argv[1][16] - 113;      
        }
        else if(a == 114 || a == 82) {
            shiftt = argv[1][17] - 114;     
        }
        else if(a == 115 || a == 83) {
            shiftt = argv[1][18] - 115;      
        }
        else if(a == 116 || a == 84) {
            shiftt = argv[1][19] - 116;      
        }
        else if(a == 117 || a == 85) {
            shiftt = argv[1][20] - 117;      
        }
        else if(a == 118 || a == 86) {
            shiftt = argv[1][21] - 118;      
        }
        else if(a == 119 || a == 87) {
            shiftt = argv[1][22] - 119;       
        }
        else if(a == 120 || a == 88) {
            shiftt = argv[1][23] - 120;       
        }
        else if(a == 121 || a == 89) {
            shiftt = argv[1][24] - 121;        
        }
        else if(a == 122 || a == 90) {
            shiftt = argv[1][25] - 122; 
        }
        else {
            shiftt = 0;
        }
        sub(a, shiftt);
        a = getchar();
    }
    return 0;
}

void sub(int letter, int shift) {
    int cipher = letter + shift;
    printf("%c", cipher);
}



