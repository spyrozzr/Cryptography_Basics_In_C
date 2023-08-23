#include <stdio.h>
#include <ctype.h>

int main() {
    int shift = 3;
    char plaintext[] = "HELLO WORLD";
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char encrypted = (c - base + shift) % 26 + base;
            printf("%c", encrypted);
        }else {
            printf("%c", c);
        }
    }
    return 0;
}