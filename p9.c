#include <stdio.h>

#define N 1000

/* Problem:
given natural numbers a,b,c:
- a < b < c
- a^2 + b^2 = c^2
- a + b + c = 1000
- there exist only one unique triplet (a,b,c)

find abc.
*/

int triplet_product(int);

int main(void) {
    printf("%d", triplet_product(N));

    return 0;
}

int triplet_product(int sum) {
    // given sum, find abc when:
    // a, b, c are natural numbers.
    // a + b + c = sum, a^2 + b^2 = c^2

    int a, b;

    for(a = 1; a < sum; a++) {
        for(b = a; b < sum; b++) {
            if(((a*a) + (b*b)) == ((sum - a - b)*(sum - a - b))) return a*b*(sum - a - b);
        }
    } // note; this solution is horrible.
}