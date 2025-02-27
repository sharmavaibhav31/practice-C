/*
Give a problem statement for writing a C program related to the Cloud strike breach
scenario:
Cloud strike, a cloud security provider, has suffered a breach. The attackers compromised customer data, including usernames and passwords. 
Write a C program to simulate the breach and identify potential vulnerabilities.

Objectives
1. Simulate the breach by generating a list of compromised usernames and passwords.
2. Identify potential vulnerabilities in Cloud strike’s password storage system.
3. Evaluate the strength of the compromised passwords.

Input
- A text file containing a list of usernames and passwords (e.g., credentials.txt)
- Each line of the file should contain a username and password separated by a colon (e.g. username:password)

Output
1. A list of compromised usernames and passwords.
2. A report identifying potential vulnerabilities in Cloudstrike's password storage system.
3. A report evaluating the strength of the compromised passwords.

Requirements
1. Use C programming language.
2. Use file input/output operations to read and write data.
3. Use string manipulation functions to process usernames and passwords.
4. Implement a simple password strength evaluation algorithm (e.g., check for length, uppercase, lowercase, digits, and special characters).
    Example Input File (credentials.txt)
    
    user1: password123
    user2: Password123!
    user3: weak password
    
Evaluation Criteria
1. Correctness (40%): Does the program correctly simulate the breach and identify potential vulnerabilities?
2. Code Quality (30%): Is the code well-organized, readable, and maintainable?
3. Password Strength Evaluation (30%): Does the program correctly evaluate the strength of the compromised passwords?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100  // Maximum number of users
#define MAX_LENGTH 100 // Maximum length for username and password

// Function prototypes
void readCredentials(const char *filename, char usernames[][MAX_LENGTH], char passwords[][MAX_LENGTH], int *count);
void checkVulnerabilities(char passwords[][MAX_LENGTH], int count);
int evaluatePasswordStrength(const char *password);
void generateReport(char usernames[][MAX_LENGTH], char passwords[][MAX_LENGTH], int count);

int main() {
    char usernames[MAX_USERS][MAX_LENGTH];
    char passwords[MAX_USERS][MAX_LENGTH];
    int userCount = 0;

    // Read credentials from the file
    readCredentials("credentials.txt", usernames, passwords, &userCount);

    // Identify potential vulnerabilities
    checkVulnerabilities(passwords, userCount);

    // Generate report
    generateReport(usernames, passwords, userCount);

    return 0;
}

// Function to read credentials from a file
void readCredentials(const char *filename, char usernames[][MAX_LENGTH], char passwords[][MAX_LENGTH], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%[^:]:%s\n", usernames[*count], passwords[*count]) == 2) {
        (*count)++;
        if (*count >= MAX_USERS) {
            printf("Warning: Maximum user limit reached!\n");
            break;
        }
    }
    fclose(file);
}

// Function to check potential vulnerabilities
void checkVulnerabilities(char passwords[][MAX_LENGTH], int count) {
    printf("\nPotential Vulnerabilities Found:\n");

    for (int i = 0; i < count; i++) {
        if (strlen(passwords[i]) < 8) {
            printf("Weak password detected: '%s' (Too short!)\n", passwords[i]);
        }
        if (strcmp(passwords[i], "password123") == 0 || strcmp(passwords[i], "123456") == 0) {
            printf("Common password detected: '%s' (Highly insecure!)\n", passwords[i]);
        }
        if (strchr(passwords[i], ' ') != NULL) {
            printf("Password contains spaces: '%s' (May indicate poor storage practices)\n", passwords[i]);
        }
    }
}

// Function to evaluate password strength
int evaluatePasswordStrength(const char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    // Assign scores based on password strength
    if (length >= 12 && hasUpper && hasLower && hasDigit && hasSpecial)
        return 5; // Very strong
    if (length >= 10 && hasUpper && hasLower && (hasDigit || hasSpecial))
        return 4; // Strong
    if (length >= 8 && hasUpper && hasLower)
        return 3; // Moderate
    if (length >= 6)
        return 2; // Weak
    return 1; // Very weak
}

// Function to generate report of compromised accounts
void generateReport(char usernames[][MAX_LENGTH], char passwords[][MAX_LENGTH], int count) {
    printf("\nCompromised Accounts Report:\n");
    for (int i = 0; i < count; i++) {
        int strength = evaluatePasswordStrength(passwords[i]);
        printf("User: %s, Password: %s (Strength: %d/5)\n", usernames[i], passwords[i], strength);
    }
}
