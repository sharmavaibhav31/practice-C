/*Question 1: Scalability Issue
Problem Statement:
Simulate a scalability issue in Flipkart’s platform, where it can handle a maximum of 1000 concurrent users. 
If the number of users exceeds 1000, the platform crashes. The program should simulate this scenario and display the result.*/

#include <stdio.h>

#define MAX_USERS 1000

int main() {
    int users;

    printf("Enter the number of concurrent users: ");
    scanf("%d", &users);

    if (users > MAX_USERS) {
        printf("System Crash: Maximum limit of %d users exceeded!\n", MAX_USERS);
    } else {
        printf("System is running fine with %d users.\n", users);
    }

    return 0;
}
