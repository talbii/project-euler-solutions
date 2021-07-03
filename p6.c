#include <stdio.h>

#define N 100

int sum_of_squares(int);
int square_of_sum(int);

int main(void) {
    printf("%d", square_of_sum(N) - sum_of_squares(N));

    return 0;
}

int sum_of_squares(int n) {
    // returns the sum: Sum(i^2, i in [1, n])

    // proof for formula: 
    /* 
    1. Define P(n) := "1^2 + 2^2 + 3^2 + .. + n^2 = n(n+1)(2n+1)/6".

    - Base case: P(1) = 1^2 = 1*2*3/6 = 1.
    
    2. Assume P(n - 1). Therefore:

    P(n) = 1^2 + 2^2 + ... + (n-1)^2 + n^2 = n(n-1)(2n-1)/6 + n^2
                                           ^ using our induction step

    = n((n-1)(2n-1) + 6n)/6 = n((2n^2 + 3n + 1)) = n(n+1)(2n+1)/6. QED
    
    */

    return n*(n+1)*(2*n+1)/6;
}

int square_of_sum(int n) {
    // returns the square of the sum of all naturals numbers in [1, n].

    // proof for formula:
    /*
    Define: 
        - a_n := n
        - s(n) := Sum(a_i, i in [1, n])
    
    it follows that a_n is arithmetic progression, and we can find a closed formula for its sum:
    s(n) = n(n+1)/2. (I'll spare the proof for this formula, though its quite easy)

    We want to return the square of this sum, so s(n)^2 = n^2(n+1)^2/4.
    */

    return n*n*(++n)*n/4;
}