#include <stdio.h>
#include <math.h>
#define NUM 600851475143
#define ull unsigned long long

ull max_factor(ull);
int isprime(ull);

/* Problem:
find the biggest factor for a given number */

int main(void) {
    printf("%llu", max_factor(NUM));

    return 0;
}

ull max_factor(ull x) {
    // returns the biggest factor of x

    ull i = 2;

    while(!isprime(i) || (x % i)) {
        i++;
    }
    // after the loop, i divides x.
    // so, x / i is the factorization of x without i.
    // if x / i is a prime number, then its the biggest factor of x.
    if(isprime(x / i)) return x / i;
    // else, we need to re-run our algorithm on x / i.
    return max_factor(x / i);
}

int isprime(ull x) {
    // returns true if x is a prime number
    // using naive O(sqrt x) algorithm
    ull limit = (ull)sqrt(x), i;

    for(i = 2; i < limit + 1; i++) {
        if(!(x % i)) return 0;
    }

    return 1;
}