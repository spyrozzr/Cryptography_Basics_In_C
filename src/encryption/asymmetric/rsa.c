#include <stdio.h>
#include <stdint.h>

// Power calc function
uint64_t power_mod(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// RSA encryption function
uint64_t rsa_encrypt(uint64_t plaintext, uint64_t e, uint64_t n) {
    return power_mod(plaintext, e, n);
}

// RSA decryption function
uint64_t rsa_decrypt(uint64_t ciphertext, uint64_t d, uint64_t n) {
    return power_mod(ciphertext, d, n);
}

// Prime numbers are intentionally small for simplicity purposes.
int main() {
    uint64_t p = 61;    // Prime number
    uint64_t q = 53;    // Prime number
    uint64_t n = p * q; // Modulus
    uint64_t e = 17;    // Public exponent
    uint64_t d = 413;   // Private exponent

    uint64_t plaintext = 42;
    printf("Plaintext: %lu\n", plaintext);

    uint64_t encrypted = rsa_encrypt(plaintext, e, n);
    printf("Encrypted: %lu\n", encrypted);

    uint64_t decrypted = rsa_decrypt(encrypted, d, n);
    printf("Decrypted: %lu\n", decrypted);

    return 0;
}