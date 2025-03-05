/*Encrypted Chat Messaging (Strings & Pointers)
Problem Statement:
You are developing a simple encrypted chat system where each message is encoded before being sent. The encoding is done using a modified Caesar Cipher, where each character in the message is shifted based on its position in the string.

Encryption Rules:
1. The first character shifts by 1, the second by 2, the third by 3, and so on.
2. If the shifted character goes beyond 'z' (for lowercase) or 'Z' (for uppercase), it wraps around.
3. Spaces and special characters remain unchanged.*/

#include <stdio.h>
#include <string.h>

void encryptMessage(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char base = (ch >= 'a') ? 'a' : 'A';
            message[i] = base + (ch - base + (i + 1)) % 26; 
        }
    }
}

void decryptMessage(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char base = (ch >= 'a') ? 'a' : 'A';
            message[i] = base + (ch - base - (i + 1) + 26) % 26; 
        }
    }
}

int main() {
    char message[256];
    int choice;
    
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; 
    
    printf("Choose an option:\n1. Encrypt Message\n2. Decrypt Message\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); 

    if (choice == 1) {
        encryptMessage(message);
        printf("Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        decryptMessage(message);
        printf("Decrypted Message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
