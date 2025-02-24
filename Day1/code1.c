/*Write a C program that implements a Restaurant Ordering and Billing System. The program should allow users to:

Select menu items, place orders, and specify quantities.
Calculate the subtotal for each selected menu item.
Display the order summary, including item names, prices, quantities, subtotal, tax, and tip.
Process payment after confirming the order.
Update the order status to "Paid" after successful payment.
Menu Items and Prices:
| Menu Item	  |  Price |
|  Pizza	  | $15.00 |
|  Burger	  | $10.00 |
|  Fries	  | $5.00  |
|  Drink	  | $3.00  |
Requirements:
* Use a loop to allow users to add multiple menu items.
* Calculate the subtotal based on selected items and quantities.
* Apply an 8% tax and allow users to add a tip if they choose.
* Display the complete bill, including each item, quantity, subtotal, tax, tip, and total.
* Ask for order confirmation before processing payment.
* Update the order status to "Paid" after successful payment.

The program should ensure proper user interaction by handling invalid inputs and providing a seamless ordering experience.*/

#include <stdio.h>
#include <stdlib.h>

#define TAX_RATE 0.08

// Structure to hold menu items
typedef struct {
    char name[20];
    float price;
    int quantity;
} MenuItem;

// Menu list
MenuItem menu[] = {
    {"Pizza", 15.0, 0},
    {"Burger", 10.0, 0},
    {"Fries", 5.0, 0},
    {"Drink", 3.0, 0}
};

// Global variables
int choice, quantity;
float subtotal = 0.0, tip = 0, tax, total;
char confirm;

// Function to display the menu
void displayMenu() {
    printf("\n===== Restaurant Menu =====\n");
    printf("1. Pizza  - $15\n");
    printf("2. Burger - $10\n");
    printf("3. Fries  - $5\n");
    printf("4. Drink  - $3\n");
    printf("5. Checkout\n");
}

// Function to take orders
void orderSystem() {
    printf("\nWelcome to the Restaurant Ordering System\n");
    
    while (1) {
        displayMenu();
        printf("Choose an item (1-5): ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("\nProceeding to checkout...\n");
            break;
        }
        
        if (choice < 1 || choice > 4) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Update quantity and subtotal
        menu[choice - 1].quantity += quantity;
        subtotal += menu[choice - 1].price * quantity;
    }
}

// Function to display the order summary and process payment
void orderSummary() {
    if (subtotal == 0) {
        printf("No items selected. Exiting!\n");
        return;
    }

    printf("\n===== Order Summary =====\n");
    printf("Item\t\tQuantity\tPrice\n");

    for (int i = 0; i < 4; i++) {
        if (menu[i].quantity > 0) {
            printf("%s\t\t%d\t\t$%.2f\n", menu[i].name, menu[i].quantity, menu[i].quantity * menu[i].price);
        }
    }

    printf("\nWould you like to add a tip? Enter amount: ");
    scanf("%f", &tip);

    // Calculate tax and total
    tax = subtotal * TAX_RATE;
    total = subtotal + tax + tip;

    printf("\n===== Payment Summary =====\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax (8%%): $%.2f\n", tax);
    printf("Tip: $%.2f\n", tip);
    printf("Total: $%.2f\n", total);

    // Confirm order
    printf("\nConfirm order and proceed with payment? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("\nOrder Confirmed!\nOrder Status: PAID\nThank you for dining with us!\n");
    } else {
        printf("\nOrder Cancelled. Thank you for visiting!\n");
    }
}

// Main function
int main() {
    orderSystem();
    orderSummary();
    return 0;
}
