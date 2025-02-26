/*Question 5: Microservices Architecture
Problem Statement:
Simulate microservices architecture in Flipkart’s platform, 
where 5 microservices each have a latency of 0.1 seconds. 
The program should simulate communication between microservices and calculate the total latency.*/

#include <stdio.h>

#define MICROSERVICES 5
#define LATENCY_PER_SERVICE 0.1

int main() {
    float totalLatency = 0.0;

    printf("Simulating Microservices Communication...\n");
    
    for (int i = 1; i <= MICROSERVICES; i++) {
        totalLatency += LATENCY_PER_SERVICE;
        printf("Microservice %d processed. Current Total Latency: %.2f seconds\n", i, totalLatency);
    }

    printf("Total Communication Latency: %.2f seconds\n", totalLatency);

    return 0;
}
