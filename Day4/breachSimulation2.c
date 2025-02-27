/*Cloudstrike Breach Simulator
Cloudstrike, a cloud security provider, has suffered a breach. The attackers compromised customer data, including usernames, passwords, and sensitive business information.
Write a C program to simulate the breach and identify potential vulnerabilities.

Objectives
1. Simulate the breach by generating a list of compromised usernames, passwords, andsensitive business information.
2. Identify potential vulnerabilities in Cloudstrike's password storage system, including:
         1. Weak password hashing algorithms.
         2. Insecure password storage mechanisms.
         3. Insufficient password length and complexity requirements.
         3. Evaluate the strength of the compromised passwords using a password strength evaluation algorithm.
         4. Simulate a phishing attack by generating a list of fake emails and evaluating their effectiveness.
5. Identify potential vulnerabilities in Cloudstrike's network security, including:
         1. Unpatched vulnerabilities in network devices.
         2. Weak firewall rules.
         3. Insufficient network segmentation.

Input
1. A text file containing a list of usernames, passwords, and sensitive business information (e.g., credentials.txt).
2. Each line of the file should contain a username, password, and sensitive business information separated by commas (e.g., username, password, business info).
3. A text file containing a list of network devices and their corresponding vulnerabilities (e.g., network_devices.txt).
4. Each line of the file should contain a network device and its corresponding vulnerability separated by commas (e.g., device, vulnerability).

Output
1. A list of compromised usernames, passwords, and sensitive business information.
2. A report identifying potential vulnerabilities in Cloud strike’s password storage system.
3. A report evaluating the strength of the compromised passwords.
4. A list of fake emails and their effectiveness in simulating a phishing attack.
5. A report identifying potential vulnerabilities in Cloudstrike's network security.

Requirements
1. Use C programming language.
2. Use file input/output operations to read and write data.
3. Use string manipulation functions to process usernames, passwords, and sensitive business information.
4. Implement a password strength evaluation algorithm (e.g., check for length, uppercase, lowercase, digits, and special characters).
5. Implement a phishing attack simulator (e.g., generate fake emails and evaluate their effectiveness).
6. Implement a network security vulnerability identifier (e.g., identify unpatched vulnerabilities in network devices).

Example Input Files

credentials.txt
user1, password123,business_info1
user2, Password123!,business_info2
user3, weakpassword, business_info3

network_devices.txt
device1,vulnerability1
device2, vulnerability2
device3,vulnerability3

Evaluation Criteria
1. Correctness (40%): Does the program correctly simulate the breach and identify potential vulnerabilities?
2. Code Quality (30%): Is the code well-organized, readable, and maintainable?
3. Password Strength Evaluation (15%): Does the program correctly evaluate the strength of the compromised passwords?
4. Phishing Attack Simulation (10%): Does the program correctly simulate a phishing attack and evaluate its effectiveness?
5. Network Security Vulnerability Identification (5%): Does the program correctly identify potential vulnerabilities in Cloud strike’s network security?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_DEVICES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char username[50];
    char password[50];
    char business_info[100];
} UserCredential;

typedef struct {
    char device[50];
    char vulnerability[100];
} NetworkDevice;

// Function to evaluate password strength
void evaluatePasswordStrength(const char *password) {
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) upper++;
        else if (islower(password[i])) lower++;
        else if (isdigit(password[i])) digit++;
        else special++;
    }

    printf("Length: %d, Uppercase: %d, Lowercase: %d, Digits: %d, Special: %d\n",
           length, upper, lower, digit, special);

    if (length >= 12 && upper > 0 && lower > 0 && digit > 0 && special > 0)
        printf("Strength: Strong\n");
    else if (length >= 8)
        printf("Strength: Medium\n");
    else
        printf("Strength: Weak\n");
}

// Function to check vulnerabilities in passwords
void identifyPasswordVulnerabilities(const UserCredential users[], int count) {
    printf("\nPotential Password Storage Vulnerabilities:\n");
    for (int i = 0; i < count; i++) {
        if (strlen(users[i].password) < 8)
            printf("Username: %s - Weak password (less than 8 characters).\n", users[i].username);
        if (strstr(users[i].password, "password") || strstr(users[i].password, "1234"))
            printf("Username: %s - Common weak pattern detected in password.\n", users[i].username);
    }
}

// Function to simulate phishing attack
void simulatePhishingAttack() {
    printf("\nPhishing Attack Simulation:\n");
    const char *fakeEmails[] = {
        "urgent-security@cloudstrike.com",
        "account-verification@cloudstrike.com",
        "password-reset@cloudstrike.com"
    };

    for (int i = 0; i < 3; i++) {
        int effectiveness = rand() % 100;
        printf("Fake Email: %s - Effectiveness: %d%%\n", fakeEmails[i], effectiveness);
    }
}

// Function to identify network vulnerabilities
void identifyNetworkVulnerabilities(const NetworkDevice devices[], int count) {
    printf("\nNetwork Security Vulnerabilities:\n");
    for (int i = 0; i < count; i++) {
        printf("Device: %s - Vulnerability: %s\n", devices[i].device, devices[i].vulnerability);
    }
}

// Function to load credentials from file
int loadUserCredentials(const char *filename, UserCredential users[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening credentials file");
        return 0;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) && count < MAX_USERS) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character
        if (sscanf(line, "%49[^,],%49[^,],%99[^\n]", users[count].username, users[count].password, users[count].business_info) == 3)
            count++;
        else
            printf("Skipping malformed line: %s\n", line);
    }

    fclose(file);
    return count;
}

// Function to load network devices from file
int loadNetworkDevices(const char *filename, NetworkDevice devices[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening network devices file");
        return 0;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) && count < MAX_DEVICES) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character
        if (sscanf(line, "%49[^,], %99[^\n]", devices[count].device, devices[count].vulnerability) == 2)
            count++;
        else
            printf("Skipping malformed line: %s\n", line);
    }

    fclose(file);
    return count;
}

int main() {
    UserCredential users[MAX_USERS];
    NetworkDevice devices[MAX_DEVICES];

    int userCount = loadUserCredentials("credentials.txt", users);
    int deviceCount = loadNetworkDevices("network_devices.txt", devices);

    if (userCount == 0) {
        printf("No user credentials found. Exiting.\n");
        return EXIT_FAILURE;
    }

    if (deviceCount == 0) {
        printf("No network devices found. Exiting.\n");
        return EXIT_FAILURE;
    }

    // Output compromised data
    printf("Compromised User Credentials:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s, Password: %s, Business Info: %s\n", users[i].username, users[i].password, users[i].business_info);
    }

    // Identify password vulnerabilities
    identifyPasswordVulnerabilities(users, userCount);

    // Evaluate password strength
    printf("\nPassword Strength Evaluation:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Username: %s\n", users[i].username);
        evaluatePasswordStrength(users[i].password);
        printf("\n");
    }

    // Identify network vulnerabilities
    identifyNetworkVulnerabilities(devices, deviceCount);

    // Simulate phishing attack
    simulatePhishingAttack();

    return EXIT_SUCCESS;
}
