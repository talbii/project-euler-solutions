#include <stdio.h>
#define is_even(x) (!(x % 2))

int sum_fib(int);

/* Problem:
find the sum of all even Fibonacci numbers less then 4 million.
*/

int main(void) {
    printf("%d", sum_fib(4000000));

    return 0;
}

int sum_fib(int max) {
    // sums all even Fibonacci numbers that are less then max
    int a = 1, 
        b = 1, temp,
        sum = 0;

    while(a < max) {
        if(is_even(a)) sum += a;
        temp = a;
        a += b;
        b = temp;
    }

    return sum;
}