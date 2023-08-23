#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char keyword[] = "KEY";
    char plaintext[] = "HELLO WORLD";
    int keyword_length = strlen(keyword);
    for (int i = 0, j = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = tolower(keyword[j % keyword_length]) - 'a';
            char encrypted = (c - base + shift) % 26 + base;
            printf("%c", encrypted);
            j++;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}