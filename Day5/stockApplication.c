/*
The Grow application is a popular platform for investing in stocks, mutual funds, and other financial instruments. 
With a user-friendly interface and advanced trading features, Grow aims to make investing easy and accessible for everyone.

Problem:
As the number of users on the Grow platform continues to grow, the application is facing
scalability issues. The current architecture is struggling to handle the increased traffic,
resulting in slow loading times, errors, and a poor user experience.

Objectives:
Your task is to design and implement a scalable architecture for the Grow application, ensuring a seamless and efficient user experience. 
Your solution should address the following objectives:
1. Scalability: Design an architecture that can handle a large number of users and
transactions without compromising performance.
2. High Availability: Ensure that the application is always available and accessible to users,
with minimal downtime.
3. Security: Implement robust security measures to protect user data and prevent
unauthorized access.
4. Performance Optimization: Optimize the application's performance to reduce loading
times and improve the overall user experience.

Requirements
Your solution should meet the following requirements:

1. Cloud-based infrastructure: Design a cloud-based infrastructure using AWS or Azure.
2. Microservices architecture: Implement a microservices architecture to ensure scalability and flexibility.
3. Database design: Design a database schema that can handle large amounts of data and transactions.
4. Security measures: Implement security measures such as authentication, authorization, and encryption.
5. Monitoring and logging: Set up monitoring and logging tools to track application performance and identify issues.

Evaluation Criteria
Your solution will be evaluated based on the following criteria:
1. Scalability: Ability to handle a large number of users and transactions.
2. Performance: Optimization of loading times and overall user experience.
3. Security: Robustness of security measures and protection of user data.
4. Architecture: Design and implementation of a scalable and flexible architecture.
5. Code quality: Cleanliness, readability, and maintainability of the codebase.

Multiple Choice Questions
1. What is the primary function of the create_stock function in the Grow application?
A) To buy stocks
B) To sell stocks
C) To create a new stock
D) To update stock price

2. Which data structure is best suited to store stock information in the Grow application?
A) Array
B) Linked List
C) Stack
D) Queue

3. What is the purpose of the update_price function in the Grow application?
A) To update the quantity of a stock
B) To update the price of a stock
C) To buy a stock
D) To sell a stock

Programming Questions
1. Write a C program to implement a simple stock market simulator. The program should allow users to buy and sell stocks, and display the current stock price and quantity.
2. Implement a search_stock function in C that searches for a specific stock by its symbol and returns its price and quantity.
3. Write a C program to demonstrate the use of a linked list to store stock information. The program should allow users to add, delete, and display stocks.
*/


#include <stdio.h>
#include <string.h>

// Structure to store stock details
typedef struct {
    char symbol[10];
    float price;
    int quantity;
} Stock;

#define MAX_STOCKS 100
Stock stocks[MAX_STOCKS];
int stockCount = 0;

// Function to add a new stock
void create_stock(char symbol[], float price, int quantity) {
    strcpy(stocks[stockCount].symbol, symbol);
    stocks[stockCount].price = price;
    stocks[stockCount].quantity = quantity;
    stockCount++;
}

// Function to update stock price
void update_price(char symbol[], float new_price) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = new_price;
            printf("Stock %s price updated to %.2f\n", symbol, new_price);
            return;
        }
    }
    printf("Stock not found!\n");
}

// Function to buy a stock
void buy_stock(char symbol[], int quantity) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].quantity += quantity;
            printf("Bought %d of %s. New quantity: %d\n", quantity, symbol, stocks[i].quantity);
            return;
        }
    }
    printf("Stock not found!\n");
}

// Function to sell a stock
void sell_stock(char symbol[], int quantity) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            if (stocks[i].quantity >= quantity) {
                stocks[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, symbol, stocks[i].quantity);
            } else {
                printf("Not enough stock available!\n");
            }
            return;
        }
    }
    printf("Stock not found!\n");
}

// Function to search for a stock by symbol
void search_stock(char symbol[]) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Stock: %s | Price: %.2f | Quantity: %d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
            return;
        }
    }
    printf("Stock not found!\n");
}

// Function to display all stocks
void display_stocks() {
    printf("\nStock Market Data:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%s: %.2f | Quantity: %d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

int main() {
    create_stock("AAPL", 150.5, 100);
    create_stock("GOOG", 2800.75, 50);
    create_stock("TSLA", 700.25, 200);
    
    display_stocks();
    
    buy_stock("AAPL", 20);
    sell_stock("GOOG", 10);
    update_price("TSLA", 750.00);
    search_stock("GOOG");
    
    display_stocks();
    return 0;
}
