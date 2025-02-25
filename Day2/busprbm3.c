/*Ticket Booking and Payment System
Design a C program to manage ticket bookings and payments with the following features:

-> Accept booking details (passenger name, age, contact number, and travel dates).
-> Calculate ticket prices based on travel dates and bus type.
-> Accept payment details (method, amount, and transaction ID).
-> Display booking confirmation and payment receipt.
-> Handle cancellations and refunds.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100

// Structure to store booking details
typedef struct {
    char name[50];
    int age;
    char contact[15];
    char travelDate[15];
    char busType[20];
    float ticketPrice;
    char paymentMethod[20];
    char transactionID[20];
    int isCancelled;  // 0 = Active, 1 = Cancelled
} Booking;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

// Function to calculate ticket price
float calculatePrice(char busType[], char travelDate[]) {
    float basePrice;
    if (strcmp(busType, "AC") == 0)
        basePrice = 800;
    else if (strcmp(busType, "Non-AC") == 0)
        basePrice = 500;
    else if (strcmp(busType, "Sleeper") == 0)
        basePrice = 1000;
    else
        return -1;

    // Peak season surcharge (Assuming summer: June & December)
    if (strstr(travelDate, "June") || strstr(travelDate, "December"))
        basePrice *= 1.2; // 20% surcharge

    return basePrice;
}

// Function to book a ticket
void bookTicket() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking limit reached!\n");
        return;
    }

    Booking newBooking;
    printf("\nEnter Passenger Name: ");
    scanf(" %[^\n]s", newBooking.name);
    printf("Enter Age: ");
    scanf("%d", &newBooking.age);
    printf("Enter Contact Number: ");
    scanf("%s", newBooking.contact);
    printf("Enter Travel Date (e.g., 10-June-2025): ");
    scanf("%s", newBooking.travelDate);
    printf("Enter Bus Type (AC/Non-AC/Sleeper): ");
    scanf("%s", newBooking.busType);

    // Calculate ticket price
    newBooking.ticketPrice = calculatePrice(newBooking.busType, newBooking.travelDate);
    if (newBooking.ticketPrice == -1) {
        printf("Invalid bus type! Booking failed.\n");
        return;
    }

    // Payment details
    printf("Ticket Price: ₹%.2f\n", newBooking.ticketPrice);
    printf("Enter Payment Method (Card/UPI/Cash): ");
    scanf("%s", newBooking.paymentMethod);
    printf("Enter Transaction ID: ");
    scanf("%s", newBooking.transactionID);

    newBooking.isCancelled = 0;
    bookings[bookingCount++] = newBooking;
    printf("\nBooking Successful! Your ticket has been confirmed.\n");
}

// Function to display all bookings
void displayBookings() {
    if (bookingCount == 0) {
        printf("No bookings available.\n");
        return;
    }
    printf("\n--- Booking Details ---\n");
    for (int i = 0; i < bookingCount; i++) {
        if (!bookings[i].isCancelled) {
            printf("\nBooking ID: %d\n", i + 1);
            printf("Passenger Name: %s\n", bookings[i].name);
            printf("Age: %d\n", bookings[i].age);
            printf("Contact: %s\n", bookings[i].contact);
            printf("Travel Date: %s\n", bookings[i].travelDate);
            printf("Bus Type: %s\n", bookings[i].busType);
            printf("Ticket Price: ₹%.2f\n", bookings[i].ticketPrice);
            printf("Payment Method: %s\n", bookings[i].paymentMethod);
            printf("Transaction ID: %s\n", bookings[i].transactionID);
            printf("Status: Confirmed\n");
        }
    }
}

// Function to cancel a booking
void cancelBooking() {
    if (bookingCount == 0) {
        printf("No bookings available to cancel.\n");
        return;
    }

    int bookingID;
    printf("Enter Booking ID to Cancel: ");
    scanf("%d", &bookingID);
    if (bookingID < 1 || bookingID > bookingCount || bookings[bookingID - 1].isCancelled) {
        printf("Invalid Booking ID or already cancelled!\n");
        return;
    }

    bookings[bookingID - 1].isCancelled = 1;
    float refundAmount = bookings[bookingID - 1].ticketPrice * 0.9;  // 10% cancellation charge
    printf("Booking Cancelled Successfully!\nRefund Amount: ₹%.2f\n", refundAmount);
}

// Main menu function
int main() {
    int choice;
    while (1) {
        printf("\n--- Ticket Booking System ---\n");
        printf("1. Book a Ticket\n");
        printf("2. View Bookings\n");
        printf("3. Cancel a Booking\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayBookings();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                printf("Exiting system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
