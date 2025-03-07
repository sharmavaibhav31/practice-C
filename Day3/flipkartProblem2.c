/*Question 2: Payment Gateway Failure
Problem Statement:
Simulate a payment gateway failure in Flipkart’s platform, assuming that the failure probability is 10% (0.1). 
The program should simulate 100 transactions and display the number of failed transactions.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TRANSACTIONS 100
#define FAILURE_PROBABILITY 0.1

int main() {
    int failedTransactions = 0;
    srand(time(0)); // Seed for randomness

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++) {
        if ((rand() % 10) < (FAILURE_PROBABILITY * 10)) { // 10% chance of failure
            failedTransactions++;
        }
    }

    printf("Total Transactions: %d\n", TOTAL_TRANSACTIONS);
    printf("Failed Transactions: %d\n", failedTransactions);
    printf("Failure Rate: %.2f%%\n", (float)failedTransactions / TOTAL_TRANSACTIONS * 100);

    return 0;
}
