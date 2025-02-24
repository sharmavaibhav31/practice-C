
/*Bank Account Management
Write a c program to compute a bank account management system that allows users to deposit, withdraw, and check their account balance. 
Write a program that uses loop logic to:
Update the account balance after each transaction
Display the transaction history, including dates, amounts, and types
Check if the account balance is sufficient for a withdrawal
Assume an initial account balance of $1000.*/

#include <stdio.h>
#include <time.h>
#include <string.h>

#define INITIAL_BALANCE 1000.0
#define MAX_TRANSACTIONS 100

// Structure to store transaction details
typedef struct {
    char type[10];   // "Deposit" or "Withdraw"
    float amount;    // Transaction amount
    char date[20];   // Date of the transaction
} Transaction;

// Global variables
float balance = INITIAL_BALANCE;
Transaction transactions[MAX_TRANSACTIONS]; // Array to store transactions
int transactionCount = 0; // Track number of transactions

// Function to get the current date and time
void getCurrentTime(char* buffer) {
    time_t t;
    time(&t);
    struct tm *timeInfo = localtime(&t);
    strftime(buffer, 20, "%Y-%m-%d %H:%M", timeInfo);
}

// Function to add a transaction to the history
void addTransaction(const char* type, float amount) {
    if (transactionCount < MAX_TRANSACTIONS) {
        strcpy(transactions[transactionCount].type, type);
        transactions[transactionCount].amount = amount;
        getCurrentTime(transactions[transactionCount].date);
        transactionCount++;
    }
}

// Function to deposit money
void deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit", amount);
        printf("Deposit successful! New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}

// Function to withdraw money
void withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction("Withdraw", amount);
        printf("Withdrawal successful! New balance: $%.2f\n", balance);
    } else {
        printf("Insufficient funds or invalid amount!\n");
    }
}

// Function to check balance
void checkBalance() {
    printf("Current balance: $%.2f\n", balance);
}

// Function to display transaction history
void transactionHistory() {
    if (transactionCount == 0) {
        printf("No transactions available.\n");
        return;
    }
    printf("\nTransaction History:\n");
    printf("--------------------------------------\n");
    printf("Type       Amount    Date\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%-10s $%.2f    %s\n", transactions[i].type, transactions[i].amount, transactions[i].date);
    }
}

// Main function to handle banking operations
void bankSystem() {
    int choice;
    float amount;

    printf("Welcome to the Bank Account Management System\n");

    while (1) {
        printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Transaction History\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(amount);
                break;
            case 2: 
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(amount);
                break;
            case 3: 
                checkBalance(); 
                break;
            case 4:
                transactionHistory();
                break;
            case 5: 
                printf("Thank you for banking with us!\n"); 
                return;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function
int main() {
    bankSystem();
    return 0;
}
