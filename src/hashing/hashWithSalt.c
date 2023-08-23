#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Same as simple hash function, but with salting

void generate_salt(char *salt, size_t length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < length; ++i) {
        salt[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    salt[length] = '\0';
}


unsigned int simple_hash_with_random_salt(const char *str, size_t length) {
    char salt[16]; 
    generate_salt(salt, sizeof(salt) - 1);
    printf("Generated Salt: %s\n", salt);
    unsigned int hash = 0;
    for (size_t i = 0; i < strlen(salt); ++i) {
        hash += salt[i];
    }
    for (size_t i = 0; i < length; ++i) {
        hash += str[i];
    }
    return hash;
}

int main() {
    const char *input = "Hello, world!";
    size_t length = strlen(input);
    unsigned int hash_value = simple_hash_with_random_salt(input, length);
    printf("Input: %s\n", input);
    printf("Hash Value (with random salt): %u\n", hash_value);
    return 0;
}