#include <stdio.h>
#include <string.h>

// Also implemented in the exmpl directory.

void caesarEncrypt(char *plaintext, int key) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
    }
}

int main() {
    char plaintext[100];
    int key;
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter encryption key (0-25): ");
    scanf("%d", &key);
    caesarEncrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}