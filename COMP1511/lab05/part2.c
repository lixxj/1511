int a[34] = {0};
    int b[34] = {0}; 
    int c[34] = {0};
    int d[34] = {0};
    int B[34] = {0};
    int C[34] = {0};
    int j = 0;
    srand(time(NULL));
    int i = turn - 1;
    if(i == 0) {
            d[i] = 3;
            c[i] = 2;
            b[i] = 1;
            a[i] = 1;
            guess[0] = a[i];
            guess[1] = b[i];
            guess[2] = c[i];
            guess[3] = d[i];
    }
    
    else {while(d[i] < 1 || c[i] < 1 || b[i] < 1 || a[i]  < 1 || d[i] > 8 || c[i] > 8 || b[i] > 8 || a[i]  > 8 ){
            d[i] = rand() % 10;
            c[i] = rand() % 10;
            b[i] = rand() % 10;
            a[i] = rand() % 10;
        
            int B1 = 0;
            int C1 = 0;
            B[i] = farnarkles[turn - 1];
            C[i] = arkles[turn - 1];
            
            
            
            
            
            
            while(B1 != B[i] || C1 != C[i]) {
                B1 = 0;
                C1 = 0;
            
        int fernando = 0;
	    int guess_tiles[N_TILES];
	    int hidden_tiles[N_TILES];
	    int farnarkle = 0;
        int arkle = 0;
        
        guess_tiles[0] = a[i]; 
        guess_tiles[1] = b[i];
        guess_tiles[2] = c[i];
        guess_tiles[3] = d[i];
	    hidden_tiles[0] = previous_guesses[turn - 1][0]; 
        hidden_tiles[1] = previous_guesses[turn - 1][1];
        hidden_tiles[2] = previous_guesses[turn - 1][2];
        hidden_tiles[3] = previous_guesses[turn - 1][3];
        int one_in_line1 = hidden_tiles[0];
        int two_in_line1 = hidden_tiles[1];
        int three_in_line1 = hidden_tiles[2];
        int four_in_line1 = hidden_tiles[3];
        int one_in_line2 = guess_tiles[0];
        int two_in_line2 = guess_tiles[1];
        int three_in_line2 = guess_tiles[2];
        int four_in_line2 = guess_tiles[3];
	    int index = 0;
	    while (index < N_TILES) {
            if(guess_tiles[index] == hidden_tiles[index]){
                ++farnarkle;
            }
            ++index;
        }
        if(one_in_line2 == one_in_line1) {
            one_in_line1 = 101;
            one_in_line2 = 102;    
        }
        if(two_in_line1 == two_in_line2) {
            two_in_line1 = 103;
            two_in_line2 = 104;
        }
        if(three_in_line1 == three_in_line2) {
            three_in_line1 = 105;
            three_in_line2 = 106;
        }
        if(four_in_line1 == four_in_line2) {
            four_in_line1 = 107;
            four_in_line2 = 108;
        }
        if(one_in_line2 == two_in_line1) {
            one_in_line2 = 109;
            two_in_line1 = 110;        
            arkle = arkle + 1;
        }
        if(one_in_line2 == three_in_line1) {
            one_in_line2 = 111;
            three_in_line1 = 112;        
            arkle = arkle + 1;
        }
        if(one_in_line2 == four_in_line1) {
            one_in_line2 = 113;
            four_in_line1 = 114;        
            arkle = arkle + 1;
        }
        if(two_in_line2 == one_in_line1) {
            two_in_line2 = 115;
            one_in_line1 = 116;        
            arkle = arkle + 1;
        }
        if(two_in_line2 == three_in_line1) {
            two_in_line2 = 117;
            three_in_line1 = 118;        
            arkle = arkle + 1;
        }
        if(two_in_line2 == four_in_line1) {
            two_in_line2 = 119;
            four_in_line1 = 120;        
            arkle = arkle + 1;
        }
        if(three_in_line2 == one_in_line1) {
            three_in_line2 = 121;
            one_in_line1 = 122;        
            arkle = arkle + 1;
        }
        if(three_in_line2 == two_in_line1) {
            three_in_line2 = 123;
            two_in_line1 = 124;        
            arkle = arkle + 1;
        }
        if(three_in_line2 == four_in_line1) {
            three_in_line2 = 125;
            four_in_line1 = 126;        
            arkle = arkle + 1;
        }
        if(four_in_line2 == one_in_line1) {
            four_in_line2 = 127;
            one_in_line1 = 128;        
            arkle = arkle + 1;
        }
        if(four_in_line2 == two_in_line1) {
            four_in_line2 = 129;
            two_in_line1 = 130;        
            arkle = arkle + 1;
        }
        if(four_in_line2 == three_in_line1) {
            four_in_line2 = 131;
            three_in_line1 = 132;        
            arkle = arkle + 1;
        }
	    B1 = farnarkle;
	    C1 = arkle; 
	    
	
                
                if(B1 != B[i] || C1 != C[i]) {
                    d[i] = rand() % 10;
                    c[i] = rand() % 10;
                    b[i] = rand() % 10;
                    a[i] = rand() % 10;
                }}
            }
            guess[0] = a[i];
            guess[1] = b[i];
            guess[2] = c[i];
            guess[3] = d[i];
            
            
     }
       
