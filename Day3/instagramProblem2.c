/*Question 2: Payment Gateway Failure (Instagram Ads Payments)
Problem Statement:
Simulate a payment gateway failure for Instagram’s ad payments. 
Assume that the failure probability is 15% (0.15). 
The program should simulate 100 transactions and display the number of failed transactions.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TRANSACTIONS 100
#define FAILURE_PROBABILITY 0.15

int main() {
    int failedTransactions = 0;
    srand(time(0)); // Seed for randomness

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++) {
        if ((rand() % 100) < (FAILURE_PROBABILITY * 100)) { // 15% chance of failure
            failedTransactions++;
        }
    }

    printf("Total Transactions: %d\n", TOTAL_TRANSACTIONS);
    printf("Failed Transactions: %d\n", failedTransactions);
    printf("Failure Rate: %.2f%%\n", (float)failedTransactions / TOTAL_TRANSACTIONS * 100);

    return 0;
}
