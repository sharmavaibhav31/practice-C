/*Online Shopping Cart
Write  c Programme to compute online shopping cart system that allows users to add, remove, and update items in their cart. Write a program that uses loop
logic to:
Calculate the total cost of items in the cart
Display the cart contents, including item names, prices, and quantities
Update the cart contents when items are added, removed, or updated
Assume a list of products with prices:
| Product | Price |
|  Shirt  |  $15  |
|  Pants  |  $20  |
|  Shoes  |  $30  |*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 3  // Number of available products

// Structure to store product details
typedef struct {
    char name[20];
    float price;
    int quantity;
} Product;

// List of available products
Product products[MAX_ITEMS] = {
    {"Shirt", 15.0, 0},
    {"Pants", 20.0, 0},
    {"Shoes", 30.0, 0}
};

// Function to display available products
void displayProducts() {
    printf("\n===== Available Products =====\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, products[i].name, products[i].price);
    }
    printf("4. Checkout\n");
}

// Function to display cart contents
void displayCart() {
    float totalCost = 0.0;
    printf("\n===== Your Shopping Cart =====\n");
    printf("Item\t\tQuantity\tTotal Price\n");

    int emptyCart = 1;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (products[i].quantity > 0) {
            printf("%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].quantity, products[i].quantity * products[i].price);
            totalCost += products[i].quantity * products[i].price;
            emptyCart = 0;
        }
    }

    if (emptyCart) {
        printf("Your cart is empty!\n");
    } else {
        printf("\nTotal Cost: $%.2f\n", totalCost);
    }
}

// Function to update cart (add/remove/update)
void updateCart() {
    int choice, quantity;

    while (1) {
        displayProducts();
        printf("Select an item to add/remove/update (1-3) or 4 to checkout: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break; // Proceed to checkout
        }

        if (choice < 1 || choice > MAX_ITEMS) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        choice--; // Convert user input (1-based) to array index (0-based)
        
        printf("Enter quantity (enter 0 to remove item): ");
        scanf("%d", &quantity);

        if (quantity < 0) {
            printf("Invalid quantity! Please enter a positive number.\n");
            continue;
        }

        products[choice].quantity = quantity;
        printf("Cart updated!\n");
    }
}

// Main function
int main() {
    printf("Welcome to the Online Shopping Cart System!\n");

    // Shopping process
    updateCart();
    displayCart();

    printf("\nThank you for shopping with us!\n");
    return 0;
}
