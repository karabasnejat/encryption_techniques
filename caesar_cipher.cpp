#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void caesarEncrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
            text[i] = ch;
        }
    }
}

void caesarDecrypt(char *text, int shift) {
    caesarEncrypt(text, 26 - (shift % 26));
}

void encryptDecryptMenu() {
    int choice;
    char text[1024];
    int shift;

    printf("Choose an option:\n");
    printf("1. Caesar Cipher Encryption\n");
    printf("2. Caesar Cipher Decryption\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            printf("Enter a text to encrypt: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0; 
            printf("Enter shift amount: ");
            scanf("%d", &shift);
            caesarEncrypt(text, shift);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            printf("Enter a text to decrypt: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0; 
            printf("Enter shift amount: ");
            scanf("%d", &shift);
            caesarDecrypt(text, shift);
            printf("Decrypted text: %s\n", text);
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
    }
}

int main() {
    while (1) {
        encryptDecryptMenu();
    }
    return 0;
}
