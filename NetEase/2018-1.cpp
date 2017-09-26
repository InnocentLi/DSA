#include <stdio.h>
 
int n;
 
void read() {
    scanf("%d", &n);
}
 
void magic(int n) {
    if (n <= 0) return;
    if (n & 1) {
        magic((n - 1) / 2);
        putchar('1');
    } else {
        magic((n - 2) / 2);
        putchar('2');
    }
}
 
void work() {
    magic(n);
    putchar('\n');
}
 
int main() {
    read();
    work();
    return 0;
}
