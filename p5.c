#include <stdio.h>
#include <stdlib.h>

/* Problem:
print the smallest number satisfying: all integers in [1,20] divide it.
*/

#define N 20

int minimal_num(void);
int find_minimally_missing_factors(int, const int*, int);

int main(void) {
    printf("%d", minimal_num());

    return 0;
}

int minimal_num(void) {
    // returns the smallest number satisfying: all integers in [1,20] divide it.
    int primes[] = {2,3,5,7,11,13,17,19}; // size: pi(N)
    int i, x = 1;

    for(i = 0; i < sizeof(primes)/sizeof(*primes); i++) x *= primes[i]; // x = Product{p in primes | p < 20}

    for(i = 1; i <= N; i++) {
        if((x % (i))) x *= find_minimally_missing_factors(i , primes, sizeof(primes)/sizeof(*primes));
    }   // if i doesn't divide x, yet

    return x;
}

int find_minimally_missing_factors(int n, const int* primes, int size) {
    // given a list of primes, this function returns n / (prime factors of n)
    int i, x = n;

    for(i = 0; i < size; i++) {
        if(!(n % primes[i])) x /= primes[i];
    }

    return x;
}