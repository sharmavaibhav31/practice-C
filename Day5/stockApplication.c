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

/*
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
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define SYMBOL_LENGTH 10
#define HASH_TABLE_SIZE 101

typedef struct Stock {
    char symbol[SYMBOL_LENGTH];
    float price;
    int quantity;
} Stock;

Stock stocks[MAX_STOCKS];
int stock_count = 0;

int hash_table[HASH_TABLE_SIZE];

int hash(const char *symbol) {
    unsigned long hash = 5381;
    int c;
    while ((c = *symbol++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_TABLE_SIZE;
}

void load_stocks() {
    FILE *file = fopen("stocks.dat", "rb");
    if (file) {
        fread(&stock_count, sizeof(int), 1, file);
        fread(stocks, sizeof(Stock), stock_count, file);
        fclose(file);
        for (int i = 0; i < stock_count; i++) {
            int index = hash(stocks[i].symbol);
            hash_table[index] = i + 1;
        }
    } else {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            hash_table[i] = -1;
        }
    }
}

void save_stocks() {
    FILE *file = fopen("stocks.dat", "wb");
    if (file) {
        fwrite(&stock_count, sizeof(int), 1, file);
        fwrite(stocks, sizeof(Stock), stock_count, file);
        fclose(file);
    }
}

Stock *find_stock(const char *symbol) {
    int index = hash(symbol);
    int stock_index = hash_table[index] - 1;
    if (stock_index >= 0 && stock_index < stock_count && strcmp(stocks[stock_index].symbol, symbol) == 0) {
        return &stocks[stock_index];
    }
    return NULL;
}

void log_transaction(const char *action, const char *symbol, int quantity, float price) {
    FILE *log_file = fopen("transactions.log", "a");
    if (log_file) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s %d shares of %s at $%.2f\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec,
                action, quantity, symbol, price);
        fclose(log_file);
    }
}

void add_stock(const char *symbol, float price, int quantity) {
    if (stock_count < MAX_STOCKS) {
        strcpy(stocks[stock_count].symbol, symbol);
        stocks[stock_count].price = price;
        stocks[stock_count].quantity = quantity;
        int index = hash(symbol);
        hash_table[index] = stock_count + 1;
        stock_count++;
        save_stocks();
        printf("Added stock: %s\n", symbol);
    } else {
        printf("Maximum stock limit reached.\n");
    }
}

void delete_stock(const char *symbol) {
    Stock *stock = find_stock(symbol);
    if (stock) {
        int index = stock - stocks;
        for (int i = index; i < stock_count - 1; i++) {
            stocks[i] = stocks[i + 1];
        }
        stock_count--;
        save_stocks();
        int hash_index = hash(symbol);
        hash_table[hash_index] = -1;
        printf("Deleted stock: %s\n", symbol);
    } else {
        printf("Stock %s not found.\n", symbol);
    }
}

void display_stocks() {
    if (stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }
    printf("Current Stocks:\n");
    for (int i = 0; i < stock_count; i++) {
        printf("Symbol: %s, Price: %.2f, Quantity: %d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
}

void buy_stock(const char *symbol, int quantity) {
    Stock *stock = find_stock(symbol);
    if (stock) {
        stock->quantity -= quantity; // Update the stock quantity
        save_stocks(); // Save the updated stocks
        log_transaction("Bought", symbol, quantity, stock->price); // Log the transaction
        printf("Bought %d shares of %s. New quantity available: %d\n", quantity, symbol, stock->quantity);
    } else {
        printf("Stock %s not found.\n", symbol); // Error if stock not found
    }
}

void sell_stock(const char *symbol, int quantity) {
    Stock *stock = find_stock(symbol);
    if (stock) {
        if (stock->quantity >= quantity) {
            stock->quantity -= quantity; // Decrease the stock quantity
            save_stocks(); // Save the updated stocks
            log_transaction("Sold", symbol, quantity, stock->price); // Log the transaction
            printf("Sold %d shares of %s. New quantity: %d\n", quantity, symbol, stock->quantity);
        } else {
            printf("Not enough shares to sell. Available: %d\n", stock->quantity);
        }
    } else {
        printf("Stock %s not found.\n", symbol); // Error if stock not found
    }
}

void search_stock(const char *symbol) {
    Stock *stock = find_stock(symbol);
    if (stock) {
        printf("Stock found: Symbol: %s, Price: %.2f, Quantity: %d\n", stock->symbol, stock->price, stock->quantity);
    } else {
        printf("Stock %s not found.\n", symbol);
    }
}

int main() {
    load_stocks();
    int choice, role;
    char symbol[SYMBOL_LENGTH];
    float price;
    int quantity;

    while (1) {
        printf("Enter your role (1 for Admin, 2 for Customer, 3 to Exit): ");
        scanf("%d", &role);

        if (role == 3) {
            save_stocks();
            printf("Exiting the program.\n");
            return 0;
        }

        while (1) {
            printf("\nStock Market Simulator\n");

            if (role == 1) { // Admin Menu
                printf("1. Add Stock\n");
                printf("2. Delete Stock\n");
                printf("3. Display Stocks\n");
                printf("4. Switch Role\n");
                printf("5. Exit\n");
            } else if (role == 2) { // Customer Menu
                printf("1. Display Stocks\n");
                printf("2. Search Stock\n");
                printf("3. Buy Stock\n");
                printf("4. Sell Stock\n");
                printf("5. Switch Role\n");
                printf("6. Exit\n");
            }

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    if (role == 1) { // Admin add stock
                        printf("Enter stock symbol: ");
                        scanf("%s", symbol);
                        printf("Enter stock price: ");
                        scanf("%f", &price);
                        printf("Enter stock quantity: ");
                        scanf("%d", &quantity);
                        add_stock(symbol, price, quantity);
                    } else if (role == 2) { // Customer Display
                        display_stocks();
                    }
                    break;
                case 2:
                    if (role == 1) { // Admin delete stock
                        printf("Enter stock symbol to delete: ");
                        scanf("%s", symbol);
                        delete_stock(symbol);
                    } else if (role == 2) { // Customer search stock
                        printf("Enter stock symbol to search: ");
                        scanf("%s", symbol);
                        search_stock(symbol);
                    }
                    break;
                case 3:
                    if (role == 1) { // Admin display stock
                        display_stocks();
                    } else if (role == 2) { // Customer buy stock
                        printf("Enter stock symbol to buy: ");
                        scanf("%s", symbol);
                        printf("Enter quantity to buy: ");
                        scanf("%d", &quantity);
                        buy_stock(symbol, quantity);
                    }
                    break;
                case 4:
                    if (role == 1) { // Admin switch role
                        break; // Break to outer loop to switch role
                    } else if (role == 2) { // Customer sell stock
                        printf("Enter stock symbol to sell: ");
                        scanf("%s", symbol);
                        printf("Enter quantity to sell: ");
                        scanf("%d", &quantity);
                        sell_stock(symbol, quantity);
                    }
                    break;
                case 5:
                    if (role == 1) { // Admin switch role
                        break; // Break to outer loop to switch role
                    } else if (role == 2) { // Customer switch role
                        break; // Break to outer loop to switch role
                    }
                    break;
                case 6:
                    if (role == 2) { // Customer exit
                        save_stocks();
                        printf("Exiting the program.\n");
                        return 0;
                    }
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }

            // If we reach here, it means we need to switch roles
            if (choice == 4 || choice == 5) {
                break; // Break to outer loop to switch role
            }
        }
    }
    return 0;
}