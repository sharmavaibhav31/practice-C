//Authentication Integration in Stock Market Simulator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define SYMBOL_LENGTH 10
#define HASH_TABLE_SIZE 101
#define ADMIN_PASSWORD "admin123"

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

int authenticate_admin() {
    char password[20];
    printf("Enter Admin Password: ");
    scanf("%s", password);
    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("Authentication successful!\n");
        return 1;
    }
    printf("Incorrect password. Access denied.\n");
    return 0;
}

void authenticate_customer(char *username) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Welcome, %s!\n", username);
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

int main() {
    load_stocks();
    int role;
    char username[50];

    while (1) {
        printf("Enter your role (1 for Admin, 2 for Customer, 3 to Exit): ");
        scanf("%d", &role);

        if (role == 3) {
            save_stocks();
            printf("Exiting the program.\n");
            return 0;
        }

        if (role == 1) {
            if (!authenticate_admin()) {
                continue;
            }
        } else if (role == 2) {
            authenticate_customer(username);
        }

        while (1) {
            printf("\nStock Market Simulator\n");
            printf("1. Display Stocks\n");
            printf("2. Switch Role\n");
            printf("3. Exit\n");
            
            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                display_stocks();
            } else if (choice == 2) {
                break; // Switch role
            } else if (choice == 3) {
                save_stocks();
                printf("Exiting the program.\n");
                return 0;
            } else {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    return 0;
}