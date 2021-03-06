#include <stdio.h>

void fizz     (int n) { puts("Fizz"); }
void buzz     (int n) { puts("Buzz"); }
void fizzbuzz (int n) { puts("FizzBuzz"); }
void print    (int n) { printf("%d\n", n); }

int main(void) {
    void (*funcs[15])(int) = { 0 };
    for (int i = 0; i < 15; i += 3) funcs[i] = fizz;
    for (int i = 0; i < 15; i += 5) funcs[i] = buzz;
    funcs[0] = fizzbuzz;
    for (int i = 0; i < 15; i ++) {
        if (funcs[i] == NULL) funcs[i] = print;
    }
    for (int i = 1; i <= 100; i ++) funcs[i%15](i);
    return 0;
}
