#include <stdio.h>
#include <string.h>

// This is a simple hash function.
// It is not meant to be effective, just simple.

unsigned int simple_hash(const char *str, size_t length) {
    unsigned int hash = 0;
    for (size_t i = 0; i < length; ++i) {
        hash += str[i];
    }
    return hash;
}

int main() {
    const char *input = "Hello, world!";
    size_t length = strlen(input);
    unsigned int hash_value = simple_hash(input, length);
    printf("Input: %s\n", input);
    printf("Hash Value: %u\n", hash_value);
    return 0;
}