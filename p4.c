#include <stdio.h>

int is_palindrome(int);
int max_palindrome(int);


int main(void) {
    printf("%d", max_palindrome(3));

    return 0;
}

int max_palindrome(int length) {
    // returns the maximum palindrome created by the product of two numbers with length digits

    int pow = 1;
    while(!length--) pow *= 10;

    int a = pow - 1, b = a, max = -1;
    
    while(a >= 100) {
        if(is_palindrome(a * b)) {
            if(max < (a * b)) max = a * b;
        }
        if(--b < 100) {
            b = --a;
        }

    }

    return max;
}

int is_palindrome(int n) {
    // Returns true if n is a palindrome.
    int reversed = 0, x = n;
    while(x > 0) {
        reversed += x % 10;
        reversed *= 10;
        x /= 10;
    }

    return n == reversed / 10;
}