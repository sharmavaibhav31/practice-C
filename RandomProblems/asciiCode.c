#include <stdio.h>

int main() {
    char input[256];
    
    // Taking input from the user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Display ASCII codes
    printf("\nASCII Codes:\n");
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '\n') { // Ignore newline character
            printf("%c : %d\n", input[i], input[i]);
        }
    }
    
    return 0;
}
