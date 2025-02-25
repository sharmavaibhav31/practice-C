/*Bus Seat Allocation System
Design a C program to manage bus seat allocations with the following features:

-> Accept bus details (bus number, route, departure time, and number of seats).
-> Accept passenger details (name, age, and contact number).
-> Allocate seats based on availability.
-> Display allocated seat numbers and passenger details.
-> Handle cancellations and reallocate seats accordingly.
-> Implement functions for seat allocation, cancellation, and display.*/

#include <stdio.h>
#include <string.h>

#define MAX_SEATS 20  // Maximum number of seats available

// Structure to store passenger details
typedef struct {
    char name[50];
    int age;
    char contact[15];
    int seatNumber;
    int booked; // 1 if booked, 0 if available
} Passenger;

typedef struct {
    int busNumber;
    char route[100];
    char departureTime[20];
    int totalSeats;
    Passenger seats[MAX_SEATS];  // Array to store seat details
} Bus;

Bus bus;  // Global bus structure

// Function to initialize the bus details
void initializeBus() {
    printf("Enter Bus Number: ");
    scanf("%d", &bus.busNumber);
    getchar(); // Clear buffer
    printf("Enter Route: ");
    fgets(bus.route, sizeof(bus.route), stdin);
    bus.route[strcspn(bus.route, "\n")] = '\0'; // Remove newline
    printf("Enter Departure Time: ");
    fgets(bus.departureTime, sizeof(bus.departureTime), stdin);
    bus.departureTime[strcspn(bus.departureTime, "\n")] = '\0'; // Remove newline
    printf("Enter Total Seats Available (max %d): ", MAX_SEATS);
    scanf("%d", &bus.totalSeats);
    if (bus.totalSeats > MAX_SEATS) bus.totalSeats = MAX_SEATS;

    // Initialize all seats as available
    for (int i = 0; i < bus.totalSeats; i++) {
        bus.seats[i].seatNumber = i + 1;
        bus.seats[i].booked = 0;
    }
}

// Function to allocate a seat
void bookSeat() {
    int seatNumber;
    printf("Enter Seat Number (1-%d): ", bus.totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > bus.totalSeats || bus.seats[seatNumber - 1].booked) {
        printf("Invalid or already booked seat!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    getchar();  // Clear buffer
    fgets(bus.seats[seatNumber - 1].name, 50, stdin);
    bus.seats[seatNumber - 1].name[strcspn(bus.seats[seatNumber - 1].name, "\n")] = '\0'; // Remove newline

    printf("Enter Age: ");
    scanf("%d", &bus.seats[seatNumber - 1].age);
    printf("Enter Contact Number: ");
    scanf("%s", bus.seats[seatNumber - 1].contact);

    bus.seats[seatNumber - 1].booked = 1;
    printf("Seat %d successfully booked!\n", seatNumber);
}

// Function to cancel a seat booking
void cancelSeat() {
    int seatNumber;
    printf("Enter Seat Number to Cancel: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > bus.totalSeats || !bus.seats[seatNumber - 1].booked) {
        printf("Invalid or not booked seat!\n");
        return;
    }

    // Reset seat details
    bus.seats[seatNumber - 1].booked = 0;
    strcpy(bus.seats[seatNumber - 1].name, "");
    bus.seats[seatNumber - 1].age = 0;
    strcpy(bus.seats[seatNumber - 1].contact, "");

    printf("Seat %d booking has been canceled!\n", seatNumber);
}

// Function to display seat allocation details
void displaySeats() {
    printf("\nBus Details:\n");
    printf("Bus Number: %d\n", bus.busNumber);
    printf("Route: %s\n", bus.route);
    printf("Departure Time: %s\n", bus.departureTime);
    printf("\nAllocated Seats:\n");

    int bookedSeats = 0;
    for (int i = 0; i < bus.totalSeats; i++) {
        if (bus.seats[i].booked) {
            printf("Seat %d - Name: %s, Age: %d, Contact: %s\n",
                   bus.seats[i].seatNumber, bus.seats[i].name, bus.seats[i].age, bus.seats[i].contact);
            bookedSeats++;
        }
    }
    
    if (bookedSeats == 0) {
        printf("No seats are booked yet.\n");
    }
}

// Main function to handle the system
int main() {
    int choice;
    initializeBus();

    while (1) {
        printf("\n--- Bus Seat Allocation System ---\n");
        printf("1. Book a Seat\n");
        printf("2. Cancel a Seat\n");
        printf("3. Display Allocated Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookSeat(); break;
            case 2: cancelSeat(); break;
            case 3: displaySeats(); break;
            case 4: printf("Exiting... Thank you!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
