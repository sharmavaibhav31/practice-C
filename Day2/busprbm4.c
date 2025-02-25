/*Bus Tracking and Location System
Develop a C program to track bus locations and provide real-time updates with the following features:

-> Accept bus location updates (GPS coordinates and timestamp).
-> Calculate estimated arrival times based on bus location and route details.
-> Display real-time bus location and estimated arrival times.
-> Handle changes in bus location and route details.
-> Implement functions for location tracking, arrival time estimation, and real-time updates.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAX_BUSES 10
#define EARTH_RADIUS 6371  // Earth's radius in km

// Structure to store bus details
typedef struct {
    int busID;
    char route[50];
    double latitude;
    double longitude;
    double speed;  // in km/h
    int passengers;
    char lastUpdate[30];  // Timestamp
} Bus;

Bus buses[MAX_BUSES];
int busCount = 0;

// Function to calculate distance using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

// Function to estimate arrival time (ETA)
double estimateArrivalTime(double distance, double speed) {
    if (speed <= 0) return -1;  // Bus is not moving
    return distance / speed;  // Time in hours
}

// Function to add a bus
void addBus() {
    if (busCount >= MAX_BUSES) {
        printf("Bus limit reached!\n");
        return;
    }

    Bus newBus;
    printf("\nEnter Bus ID: ");
    scanf("%d", &newBus.busID);
    printf("Enter Route Name: ");
    scanf(" %[^\n]s", newBus.route);
    printf("Enter Current Latitude: ");
    scanf("%lf", &newBus.latitude);
    printf("Enter Current Longitude: ");
    scanf("%lf", &newBus.longitude);
    printf("Enter Speed (km/h): ");
    scanf("%lf", &newBus.speed);
    printf("Enter Number of Passengers: ");
    scanf("%d", &newBus.passengers);

    // Get current timestamp
    time_t now;
    time(&now);
    struct tm *timeinfo = localtime(&now);
    strftime(newBus.lastUpdate, sizeof(newBus.lastUpdate), "%Y-%m-%d %H:%M:%S", timeinfo);

    buses[busCount++] = newBus;
    printf("\nBus added successfully!\n");
}

// Function to update bus location
void updateBusLocation() {
    if (busCount == 0) {
        printf("No buses available to update.\n");
        return;
    }

    int busID;
    printf("Enter Bus ID to update location: ");
    scanf("%d", &busID);

    for (int i = 0; i < busCount; i++) {
        if (buses[i].busID == busID) {
            printf("Enter New Latitude: ");
            scanf("%lf", &buses[i].latitude);
            printf("Enter New Longitude: ");
            scanf("%lf", &buses[i].longitude);
            printf("Enter New Speed (km/h): ");
            scanf("%lf", &buses[i].speed);

            // Update timestamp
            time_t now;
            time(&now);
            struct tm *timeinfo = localtime(&now);
            strftime(buses[i].lastUpdate, sizeof(buses[i].lastUpdate), "%Y-%m-%d %H:%M:%S", timeinfo);

            printf("\nBus location updated successfully!\n");
            return;
        }
    }
    printf("Bus ID not found!\n");
}

// Function to track bus location
void trackBus() {
    if (busCount == 0) {
        printf("No buses available to track.\n");
        return;
    }

    int busID;
    double destLat, destLon;
    printf("Enter Bus ID to track: ");
    scanf("%d", &busID);
    printf("Enter Destination Latitude: ");
    scanf("%lf", &destLat);
    printf("Enter Destination Longitude: ");
    scanf("%lf", &destLon);

    for (int i = 0; i < busCount; i++) {
        if (buses[i].busID == busID) {
            // Calculate distance and ETA
            double distance = calculateDistance(buses[i].latitude, buses[i].longitude, destLat, destLon);
            double eta = estimateArrivalTime(distance, buses[i].speed);

            printf("\n--- Bus Tracking ---\n");
            printf("Bus ID: %d\n", buses[i].busID);
            printf("Route: %s\n", buses[i].route);
            printf("Current Location: (%.6f, %.6f)\n", buses[i].latitude, buses[i].longitude);
            printf("Speed: %.2f km/h\n", buses[i].speed);
            printf("Last Update: %s\n", buses[i].lastUpdate);
            printf("Distance to Destination: %.2f km\n", distance);
            if (eta >= 0)
                printf("Estimated Arrival Time: %.2f hours\n", eta);
            else
                printf("Bus is not moving. ETA unavailable.\n");

            return;
        }
    }
    printf("Bus ID not found!\n");
}

// Function to display all bus details
void displayBuses() {
    if (busCount == 0) {
        printf("No buses available.\n");
        return;
    }
    printf("\n--- Bus Details ---\n");
    for (int i = 0; i < busCount; i++) {
        printf("\nBus ID: %d\n", buses[i].busID);
        printf("Route: %s\n", buses[i].route);
        printf("Location: (%.6f, %.6f)\n", buses[i].latitude, buses[i].longitude);
        printf("Speed: %.2f km/h\n", buses[i].speed);
        printf("Passengers: %d\n", buses[i].passengers);
        printf("Last Update: %s\n", buses[i].lastUpdate);
    }
}

// Main menu function
int main() {
    int choice;
    while (1) {
        printf("\n--- Bus Tracking System ---\n");
        printf("1. Add Bus\n");
        printf("2. Update Bus Location\n");
        printf("3. Track Bus\n");
        printf("4. Display All Buses\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                updateBusLocation();
                break;
            case 3:
                trackBus();
                break;
            case 4:
                displayBuses();
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
