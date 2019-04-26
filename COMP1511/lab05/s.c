#include <stdio.h>
#include <string.h>

int rulled_out[10000 / sizeof(int) + 1];
int num_left;

// Try guess GUESS and mark the entries in RULLED_OUT that match the
// numbers that cannot be the secret (i.e. numbers that compared to
// GUESS are not COMP).
void update_rulled_out(int guess, int comp);

// Compare A and B and return M*10+N, where M is the number of digits
// matching and N is the number of digits present.
int compare(int a, int b);

// Figure out the next guess based on RULLED_OUT.
int get_next_guess();

int is_rulled_out(int i);
void mark_rulled_out(int i);

int main() {
        int secret = 0;

        while (secret < 1000 || 9999 < secret) {
                printf("Secret code: ");
                fflush(stdout);
                while (!scanf("%d", &secret))
                        getchar();
        }

        memset(&rulled_out, 0, sizeof(rulled_out));
        num_left = 9000;

        int guess = 1123;       // best initial guess
        while (num_left > 1) {
                printf("Trying guess %d\n", guess);
                mark_rulled_out(guess);
                if (compare(guess, secret) == 40)
                    break;
                update_rulled_out(guess, compare(guess, secret));
                printf("Guesses left: %d\n", num_left);
                guess = get_next_guess();
        }

        printf("The secret is %d\n", guess);

        return 0;
}


int compare(int a, int b) {
        int m = 0, n = 0;
        int va[4], vb[4];
        digits_of(a, va);
        digits_of(b, vb);

        for (int i = 0; i < 4; ++i) {
                if (va[i] == vb[i]) {
                        ++m;
                        continue;
                }
                for (int j = 0; j < 4; ++j)
                        if (va[i] == vb[j]) {
                                ++n;
                                break;
                        }
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
        // Find the guess that minimizes the number possibilities left
        // after making it (assuming the worst case).
        for (int i = 1000; i < 10000; ++i)
                if (!is_rulled_out(i)) {
                        // Find the comparison result that would
                        // maximise the number of possibilites left
                        // after making the guess I.
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
