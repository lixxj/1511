/* decrypts text encrypted by substitution.c*/
// Written by XJ LI.

#include <stdio.h>
#include <stdlib.h>
void sub(int shift);

int main(int argc, char *argv[]) {
    int a = getchar();
    while (a != EOF) {
        int shiftt;
        if(a >= 97 && a <= 122) {
            if(a == argv[1][0]) {
                shiftt = 97;        
            }
            else if(a == argv[1][1]) {
                shiftt = 98;        
            }
            else if(a == argv[1][2]) {
                shiftt = 99;        
            }
            else if(a == argv[1][3]) {
                shiftt = 100;        
            }
            else if(a == argv[1][4]) {
                shiftt = 101;        
            }    
            else if(a == argv[1][5]) {
                shiftt = 102;        
            }
            else if(a == argv[1][6]) {
                shiftt = 103;        
            }
            else if(a == argv[1][7]) {
                shiftt = 104;        
            }
            else if(a == argv[1][8]) {
                shiftt = 105;        
            }    
            else if(a == argv[1][9]) {
                shiftt = 106;        
            }
            else if(a == argv[1][10]) {
                shiftt = 107;        
            }
            else if(a == argv[1][11]) {
                shiftt = 108;        
            }
            else if(a == argv[1][12]) {
                shiftt = 109;        
            }    
            else if(a == argv[1][13]) {
                shiftt = 110;        
            }
            else if(a == argv[1][14]) {
                shiftt = 111;        
            }
            else if(a == argv[1][15]) {
                shiftt = 112;        
            }
            else if(a == argv[1][16]) {
                shiftt = 113;        
            }    
            else if(a == argv[1][17]) {
                shiftt = 114;        
            }
            else if(a == argv[1][18]) {
                shiftt = 115;        
            }
            else if(a == argv[1][19]) {
                shiftt = 116;        
            }
            else if(a == argv[1][20]) {
                shiftt = 117;        
            }    
            else if(a == argv[1][21]) {
                shiftt = 118;        
            }
            else if(a == argv[1][22]) {
                shiftt = 119;        
            }
            else if(a == argv[1][23]) {
                shiftt = 120;        
            }
            else if(a == argv[1][24]) {
                shiftt = 121;        
            }    
            else if(a == argv[1][25]) {
                shiftt = 122;        
            }
        }
        
        
        
        else if(a >= 65 && a <= 90) {
            a = a + 32;
            if(a == argv[1][0]) {
                shiftt = 65;        
            }
            else if(a == argv[1][1]) {
                shiftt = 66;        
            }
            else if(a == argv[1][2]) {
                shiftt = 67;        
            }
            else if(a == argv[1][3]) {
                shiftt = 68;        
            }
            else if(a == argv[1][4]) {
                shiftt = 69;        
            }    
            else if(a == argv[1][5]) {
                shiftt = 70;        
            }
            else if(a == argv[1][6]) {
                shiftt = 71;        
            }
            else if(a == argv[1][7]) {
                shiftt = 72;        
            }
            else if(a == argv[1][8]) {
                shiftt = 73;        
            }    
            else if(a == argv[1][9]) {
                shiftt = 74;        
            }
            else if(a == argv[1][10]) {
                shiftt = 75;        
            }
            else if(a == argv[1][11]) {
                shiftt = 76;        
            }
            else if(a == argv[1][12]) {
                shiftt = 77;        
            }    
            else if(a == argv[1][13]) {
                shiftt = 78;        
            }
            else if(a == argv[1][14]) {
                shiftt = 79;        
            }
            else if(a == argv[1][15]) {
                shiftt = 80;        
            }
            else if(a == argv[1][16]) {
                shiftt = 81;        
            }    
            else if(a == argv[1][17]) {
                shiftt = 82;        
            }
            else if(a == argv[1][18]) {
                shiftt = 83;        
            }
            else if(a == argv[1][19]) {
                shiftt = 84;        
            }
            else if(a == argv[1][20]) {
                shiftt = 85;        
            }    
            else if(a == argv[1][21]) {
                shiftt = 86;        
            }
            else if(a == argv[1][22]) {
                shiftt = 87;        
            }
            else if(a == argv[1][23]) {
                shiftt = 88;        
            }
            else if(a == argv[1][24]) {
                shiftt = 89;        
            }    
            else if(a == argv[1][25]) {
                shiftt = 90;        
            }
        }
        else {
            shiftt = a;
        }
        sub(shiftt);
        a = getchar();
    }
    return 0;
}

void sub(int shift) {
    printf("%c", shift);
}



