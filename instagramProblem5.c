/*Question 5: Simulating Instagram’s Microservices Architecture
Problem Statement:
Simulate Instagram’s microservices architecture, where 5 microservices (e.g., Feed Service, DM Service, Ads Service, Story Service, Notification Service) each have a latency of 0.2 seconds. 
The program should simulate communication between these microservices and calculate the total latency.*/

#include <stdio.h>

#define MICROSERVICES 5
#define LATENCY_PER_SERVICE 0.2

int main() {
    float totalLatency = 0.0;

    printf("Simulating Microservices Communication in Instagram...\n");
    
    for (int i = 1; i <= MICROSERVICES; i++) {
        totalLatency += LATENCY_PER_SERVICE;
        printf("Microservice %d processed. Current Total Latency: %.2f seconds\n", i, totalLatency);
    }

    printf("Total Communication Latency: %.2f seconds\n", totalLatency);

    return 0;
}
