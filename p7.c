#include <stdio.h>
#include <stdlib.h>
#define N 10001

int isprime(int, const int*, int);
int getprime(int);


/* Problem:
print the 10,001st prime number. 
*/

int main(void) {
    printf("%d", getprime(N));

    return 0;
}

int isprime(int n, const int* primes, int size) {
    // Returns true if n is a prime number
    int i;
    for(i = 0; i < size; i++) {
        if(!(n % *(primes + i))) return 0;
    }

    return 1;
}

int getprime(int n) {
    // Returns the n-th prime number

    int* primes = malloc(n * sizeof(primes)), i, count = 2;

    if(!primes) exit(-1); // allocation error

    *primes = 2;
    *(primes + 1) = 3; // load some primes

    while(count != n) {
        i = *(primes + count - 1) + 2; // i = [last prime] + 2 (since, primes must be odd except for 2)

        while(!isprime(i, primes, count)) i += 2;

        *(primes + count++) = i;
    }

    int p = *(primes + n - 1);

    free(primes);

    return p;
}