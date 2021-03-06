#include <stdio.h>

int sum_mul(int, int*, int);

/* Problem:
sum of all numbers in [1,1000] divided by either 3 or 5.
*/

int main(void) {
    int divs[] = {3,5};
    printf("%d", sum_mul(1000, divs, 2));

    return 0;
}


int sum_mul(int n, int* x, int size) {
    // returns the sum of all numbers in the
    // range [1,n] that one of the numbers in x is a divisor of.
    // O(n)

    int sum = 0, i, j;

    for(i = 1; i < n; i++) {
        for(j = 0; j < size; j++) {
            if(!(i % *(x+j))) {
                sum += i;
                break;
            }
        }
    }

    return sum;
}