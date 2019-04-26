// COMP1511 Farnarkling lab exercises
//
// This program by XINGJIAN, LI (z5190719) on 26 Mar

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N_TILES 4
#define MAX_TILE 8
#define MAX_TURNS 100
#define TRUE 1
#define FALSE 0

// ADD YOUR #defines (if any) here


// You have to write these functions
int count_farnarkles(int tiles1[N_TILES], int tiles2[N_TILES]);
int count_arkles(int tiles1[N_TILES], int tiles2[N_TILES]);
void play_farnarkle(int hidden_tiles[]);
void farnarkle_ai(int turn, int previous_guesses[MAX_TURNS][N_TILES], int farnarkles[MAX_TURNS], int arkles[MAX_TURNS], int guess[N_TILES]);


// Don't change these functions
int test_farnarkle_ai(int hidden_tiles[]);
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]);
int read_tiles(int tiles[N_TILES]);
void print_tiles(int tiles[N_TILES]);
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]);

// ADD PROTOTYPES FOR ANY FUNCTIONS YOU CREATE HERE
int get_arkles(int hidden_tiles[N_TILES], int guesses[N_TILES]);
int get_farnarkles(int hidden_tiles[N_TILES], int guesses[N_TILES]);
int num_left;
int rulled_out[10000 / sizeof(int) + 1];
void update_rulled_out(int guess, int comp);
int compare(int a, int b);
int get_next_guess();
int is_rulled_out(int i);
void mark_rulled_out(int i);

// DO NOT CHANGE THIS FUNCTION
// This main function won't be marked as part of the lab
// It tests the functions you have to write.
// Do not change this main function.  If it does not work with
// your functions you have misunderstood the lab.

int main(void) {
    int call_which_function = 0;

    printf("Enter 0 to call count_farnarkles()\n");
    printf("Enter 1 to call count_arkles()\n");
    printf("Enter 2 to call play_farnarkle()\n");
    printf("Enter 3 to call test_ai_farnarkle_player()\n");
    printf("Call which function: ");
    scanf("%d", &call_which_function);
    
    if (call_which_function == 0) {
    	int tiles1[N_TILES], tiles2[N_TILES];
    	read_two_tile_sequences(tiles1, tiles2);
    	int farnarkles = count_farnarkles(tiles1, tiles2);
    	printf("count_farnarkles returned %d for\n", farnarkles);
    	print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 1) {
    	int tiles1[N_TILES], tiles2[N_TILES];
    	read_two_tile_sequences(tiles1, tiles2);
    	int arkles = count_arkles(tiles1, tiles2);
    	printf("count_arkles returned %d for\n", arkles);
    	print_two_tile_sequences(tiles1, tiles2);
    } else if (call_which_function == 2) {
    	int hidden_tiles[N_TILES];
	    set_tiles_to_pseudo_random_values(hidden_tiles);
	    play_farnarkle(hidden_tiles);
    } else if (call_which_function == 3) {
    	int hidden_tiles[N_TILES];
    	printf("Enter hidden tiles: ");
	    assert(read_tiles(hidden_tiles) == N_TILES);
	    test_farnarkle_ai(hidden_tiles);
    }
    
    return 0;
}

// return number of farnarkles
int count_farnarkles(int tiles1[N_TILES], int tiles2[N_TILES]) {
    int index = 0;
    int farnarkles = 0;
    while (index < N_TILES) {
        if(tiles1[index] == tiles2[index]){
            ++farnarkles;
        }
        ++index;
    }
    return farnarkles;
}
// PUT YOUR CODE HERE
// NOTE DO NOT CHANGE tiles1 or tiles2

// return number of arkles
int count_arkles(int tiles1[N_TILES], int tiles2[N_TILES]) {

    int index_tiles1;
    int index_tiles2;
    int arkles;
    int been_counted_tiles1[N_TILES] = {FALSE};
    int been_counted_tiles2[N_TILES] = {FALSE};
    int arkle_reached;
    
    //initialise
    index_tiles1 = 0;
    arkles = 0;
    //checks for farnarkles
    while(index_tiles1 < N_TILES){
        if(tiles1[index_tiles1] == tiles2[index_tiles1]){
            been_counted_tiles1[index_tiles1] = TRUE;
            been_counted_tiles2[index_tiles1] = TRUE;
        }
        ++index_tiles1;
    }
    //restarts index1
    index_tiles1 = 0;
    //Counts for arkles
    while(index_tiles1 < N_TILES){
        index_tiles2 = 0;
        arkle_reached = FALSE;
        while(index_tiles2 < N_TILES && arkle_reached == FALSE && been_counted_tiles1[index_tiles1] == FALSE){
            if(been_counted_tiles2[index_tiles2] == FALSE && tiles1[index_tiles1] == tiles2[index_tiles2]){
                ++arkles;
                been_counted_tiles1[index_tiles1] = TRUE;
                been_counted_tiles2[index_tiles2] = TRUE;
                arkle_reached = TRUE; 
            } 
            ++index_tiles2;
        }
        ++index_tiles1;
    }
    return arkles;
}


// PUT YOUR CODE HERE
// NOTE DO NOT CHANGE tiles1 or tiles2

// play_farnarkle is given a sequencse hidden tiles
// It reads guesses from a human player,
// printing the number of farnarkles and arkles for each guess,
// until the human player guesses the sequence.

void play_farnarkle(int hidden_tiles[N_TILES]) {
	int fernando = 0;
	int i = 1;
	int guess_tiles[N_TILES];
	
	while(fernando < N_TILES) {
	    printf("Enter guess for turn %d: ", i);
	    i = i + 1;
	    
	    int farnarkle = 0;
        int arkle = 0;
        
        scanf("%d", &guess_tiles[0]);
        scanf("%d", &guess_tiles[1]);
        scanf("%d", &guess_tiles[2]);
        scanf("%d", &guess_tiles[3]);
	    
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
	    printf("%d farnarkles, %d arkles\n", farnarkle, arkle);
	    fernando = farnarkle;
	}
	
	if(fernando == 4) {
	    printf("You win\n");
	}
	// PUT YOUR CODE HERE
}















// farnarkle_ai is given
//
// turn: the turn number
// previous_guesses: an array of turn - 1 previous guesses
// farnarkles: an array of turn - 1 farnarkle counts for previous guesses
// arkles: an array of turn - 1 arkle counts for previous guesses
//
// it should choose a suitable guess and store it in the array guess

void farnarkle_ai(int turn,
                 int previous_guesses[MAX_TURNS][N_TILES],
                 int farnarkles[MAX_TURNS], int arkles[MAX_TURNS],
                 int guess[N_TILES]) {
    int rulled_out[10000 / sizeof(int) + 1];
    int num_left;
    int guesss = 0;                     
    memset(&rulled_out, 0, sizeof(rulled_out));
    num_left = 9000;
	
	if(turn == 1) {
	    guess[0] = 1;
	    guess[1] = 1;
	    guess[2] = 2;
	    guess[3] = 3;
	}
	else {
        while (num_left > 1) {
                mark_rulled_out(guesss);
                if ((10 * farnarkles[turn - 1] + arkles[turn - 1]) == 40)
                    break;
                update_rulled_out(guesss, (10 * farnarkles[turn - 1] + arkles[turn - 1]));
                guesss = get_next_guess();
        }
        guess[0] = (guesss - guesss % 1000) / 1000;
        guess[1] = ((guesss - (guesss - guesss % 1000)) -  (guesss - (guesss - guesss % 1000)) % 100) / 100;
        guess[2] = ((guesss - (guesss - guesss % 1000) - ((guesss - (guesss - guesss % 1000)) -  (guesss - (guesss - guesss % 1000)) % 100)) - (guesss - (guesss - guesss % 1000) - ((guesss - (guesss - guesss % 1000)) -  (guesss - (guesss - guesss % 1000)) % 100)) % 10) / 10;
        guess[3] = guesss - 1000 * guess[0] - 100 * guess[1] - 10 * guess[2];
    }
	
	
	// PUT YOUR CODE HERE

}






















// DO NOT CHANGE THE FUNCTIONS BELOW HERE

// DO NOT CHANGE THIS FUNCTION
void print_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
	printf("Sequence 1: ");
	print_tiles(tiles1);
	printf("\n");
	printf("Sequence 2: ");
	print_tiles(tiles2);
	printf("\n");
}

// DO NOT CHANGE THIS FUNCTION
void read_two_tile_sequences(int tiles1[N_TILES], int tiles2[N_TILES]) {
	printf("Enter tile sequence 1: ");
	assert(read_tiles(tiles1) == N_TILES);
	printf("Enter tile sequence 2: ");
	assert(read_tiles(tiles2) == N_TILES);
}

// DO NOT CHANGE THIS FUNCTION
// read N_TILES tiles into array tiles
// returns number of tiles successfully read
int read_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        if (scanf("%d", &tiles[i]) != 1) {
            return i;
        }
        if (tiles[i] < 1 || tiles[i] > MAX_TILE) {
            return i;
        }
        i = i + 1;
    }
    return i;
}

// DO NOT CHANGE THIS FUNCTION
// print tiles on a single line
void print_tiles(int tiles[N_TILES]) {
    int i = 0;
    while (i < N_TILES) {
        printf("%d", tiles[i]);
        if (i < N_TILES - 1) {
            printf(" ");
        }
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION
void set_tiles_to_pseudo_random_values(int tiles[N_TILES]) {
    // seed (initialize) pseudo-random number generate with current time in seconds
    srand(time(NULL));

    int i = 0;
    while (i < N_TILES) {
        // rand() returns a pseudo-random integer in ranger 0 to RAND_MAX inclusive
        // convert to an integer in the range 1..MAX_TILE_template
        tiles[i] = rand() % MAX_TILE + 1;
        i = i + 1;
    }
}

// DO NOT CHANGE THIS FUNCTION

// test_farnarkle_ai is given a sequence of hidden tiles
// It calls the function farnarkle_ai to make a guess
// printing the number of farnarkles and arkles for each guess,
// until farnarkle_ai guesses the sequence.
// number of turns taken is returned

int test_farnarkle_ai(int hidden_tiles[N_TILES]) {
    int guesses[MAX_TURNS][N_TILES] = {{0}};
    int farnarkles[MAX_TURNS] = {0};
    int arkles[MAX_TURNS] = {0};
    int turn_limit =  MAX_TILE * N_TILES;

    int turn = 0;
    while (turn <= turn_limit) {
        
        int i = 0;
        while (i < N_TILES) {
            guesses[turn][i] = -1;
            i = i + 1;
        }
        
        printf("Turn %d: farnarkle AI guess is: ", turn + 1);
        fflush(stdout); // help debugging
        
        farnarkle_ai(turn + 1, guesses, farnarkles, arkles, guesses[turn]);
        
        print_tiles(guesses[turn]);
        printf(" = ");
        
        int j = 0;
        while (j < N_TILES) {
            if (guesses[turn][j] < 1 || guesses[turn][j] > MAX_TILE) {
                printf("Invalid guess\nGame ended\n");
                return 0;
            }
            j = j + 1;
        }

        farnarkles[turn] = get_farnarkles(hidden_tiles, guesses[turn]);
        arkles[turn] = get_arkles(hidden_tiles, guesses[turn]);

        printf("%d farnarkles, %d arkles\n", farnarkles[turn], arkles[turn]);
        
        if (farnarkles[turn] == N_TILES) {
            printf("Farnarkle AI took %d turns to guess the tiles.\n", turn + 1);
            return turn + 1;
        }
        turn = turn + 1;
    }
    printf("Turn limit of %d turns exceeded\nGame ended\n", turn_limit);
    return turn + 1;
    
}

void digits_of(int x, int vx[]) {
        for (int i = 3; i >= 0; --i, x /= 10)
                vx[i] = x % 10;
}

int compare(int a, int b) {
    
    int hidden_tiles[4];
    int guesses[4];
    hidden_tiles[0] = (a - a % 1000) / 1000;
    hidden_tiles[1] = ((a - (a - a % 1000)) -  (a - (a - a% 1000)) % 100) / 100;
    hidden_tiles[2] = ((a - (a -  a% 1000) - ((a - (a -  a% 1000)) -  (a - (a - a % 1000)) % 100)) - (a - (a - a % 1000) - ((a - (a - a % 1000)) -  (a - (a - a % 1000)) % 100)) % 10) / 10;
    hidden_tiles[3] = a - 1000 * hidden_tiles[0] - 100 * hidden_tiles[1] - 10 * hidden_tiles[2];
    
    guesses[0] = (b - b % 1000) / 1000;
    guesses[1] = ((b - (b - b % 1000)) -  (b - (b - b % 1000)) % 100) / 100;
    guesses[2] = ((b - (b - b % 1000) - ((b - (b - b % 1000)) -  (b - (b - b % 1000)) % 100)) - (b - (b - b % 1000) - ((b - (b - b % 1000)) -  (b - (b - b % 1000)) % 100)) % 10) / 10;
    guesses[3] = b - 1000 * guesses[0] - 100 * guesses[1] - 10 * guesses[2];
    
    
    
    
    int m = 0;
    int q = 0;
    while(q < 4) {
        if (hidden_tiles[q] == guesses[q]) {
            m++;
        }
        q++;
    }
    int n = 0;
    int i = 0;
    int j = 0;
    while(i < 4) {
        while(j < 4) {   
            if (hidden_tiles[i] == guesses[j]) {
                        n++;
            }
            j++;
        }
        i++;        
    }
        return (m * 10 + n);
}

int is_rulled_out(int i) {
        return (rulled_out[i / sizeof(int)] & (1 << (i % sizeof(int))));
}

void mark_rulled_out(int i) {
        rulled_out[i / sizeof(int)] |= 1 << (i % sizeof(int));
}

void update_rulled_out(int guess, int comp) {
        for (int i = 1000; i < 10000; ++i)
                if (!is_rulled_out(i) && compare(guess, i) != comp) {
                        mark_rulled_out(i);
                        --num_left;
                }
}

int mock_update_rulled_out(int guess, int comp) {
        int elim = 0;
        for (int i = 1000; i < 10000; ++i)
                if (!is_rulled_out(i) && compare(guess, i) != comp) {
                        ++elim;
                }
        return elim;

}

int get_next_guess() {
        int best_guess = -1, best_left_after = 1000000;
        for (int i = 1000; i < 10000; ++i)
                if (!is_rulled_out(i)) {
                        int max = 0;
                        for (int m = 0; m < 3; ++m)
                                for (int n = 0; n < 4; ++n)
                                        if (m + n <= 4) {
                                                int left_after =
                                                        mock_update_rulled_out(i, m*10+n);
                                                if (left_after > max)
                                                        max = left_after;
                                        }
                        if (max < best_left_after) {
                                best_guess = i;
                                best_left_after = max;
                        }
                }
        return best_guess;
}



int get_farnarkles(int hidden_tiles[N_TILES], int guesses[N_TILES]) {
    int m = 0;
    int q = 0;
    while(q < 4) {
        if (hidden_tiles[q] == guesses[q]) {
            m++;
        }
        q++;
    }
    return m;            
}


int get_arkles(int hidden_tiles[N_TILES], int guesses[N_TILES]) {
    int n = 0;
    int i = 0;
    int j = 0;
    while(i < 4) {
        while(j < 4) {   
            if (hidden_tiles[i] == guesses[j]) {
                        n++;
                }
                j++;
        }
        i++;        
    }
    return n;             
}




