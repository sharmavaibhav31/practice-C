/*Electricity Bill Calculation   
Problem Statement:A power distribution company wants to automate electricity bill generation based on the following rules:  
1.  Fixed charge = ₹100  for all consumers.  
2.  Rate per unit:   
   -  Up to 100 units   → ₹5  per unit  
   -  101 to 300 units  → ₹7  per unit  
   -  Above 300 units   → ₹10 per unit  
3.  If the total bill exceeds ₹1000, add a 5% surcharge.   
4. The program should display customer details, total units consumed, bill amount, and surcharge (if any).   
Requirements:   
1.  Input:   
   - Customer Name  
   - Customer ID  
   - Total Units Consumed  
2.  Output:   
   - Base Bill  
   - Surcharge (if applicable)  
   - Total Bill  

Sample Test Case:   
Input:   
Enter Customer Name: Amit Sharma  
Enter Customer ID: 2025  
Enter Total Units Consumed: 350  
  
Output:   
Customer Name: Amit Sharma  
Customer ID: 2025  
Units Consumed: 350  
Base Bill: ₹3050  
Surcharge: ₹152.5  
Total Bill: ₹3202.5*/


#include <stdio.h>
#include <stdlib.h>

#define FIXED_CHARGE 100
#define MAX_NAME_LENGTH 100

// Structure to hold customer details
typedef struct {
    char customerName[MAX_NAME_LENGTH];
    int customerId;
    float totalUnitsConsumed;
    float totalAmount;
    float baseBill;
    float surcharge;
} Customer;

Customer cust;

// Function to get customer details
void getCustomerDetails() {
    printf("\nEnter Customer Details:\n");

    // Clear input buffer before taking name
    getchar();
    
    printf("Enter Customer Name: ");
    fgets(cust.customerName, MAX_NAME_LENGTH, stdin);
    
    printf("Enter Customer ID: ");
    scanf("%d", &cust.customerId);
    
    printf("Enter Total Units Consumed: ");
    scanf("%f", &cust.totalUnitsConsumed);
}

// Function to calculate electricity bill
void customerBillCalculation() {
    cust.totalAmount = 0;
    float units = cust.totalUnitsConsumed;  // Use float to avoid rounding errors

    // Bill calculation based on units consumed
    if (units <= 100) {
        cust.totalAmount = units * 5;
    } else if (units <= 300) {
        cust.totalAmount = (100 * 5) + (units - 100) * 7;
    } else {
        cust.totalAmount = (100 * 5) + (200 * 7) + (units - 300) * 10;
    }

    // Add fixed charge
    cust.baseBill = cust.totalAmount + FIXED_CHARGE;

    // Apply surcharge if applicable
    if (cust.baseBill > 1000) {
        cust.surcharge = cust.baseBill * 0.05;
        cust.totalAmount = cust.baseBill + cust.surcharge;
    } else {
        cust.surcharge = 0;
        cust.totalAmount = cust.baseBill;
    }
}

// Function to display the bill summary
void ebillSummary() {
    printf("\nCustomer Name: %s", cust.customerName);
    printf("Customer ID: %d", cust.customerId);
    printf("\nUnits Consumed: %.2f", cust.totalUnitsConsumed);
    printf("\nBase Bill: ₹%.2f", cust.baseBill);
    printf("\nSurcharge: ₹%.2f", cust.surcharge);
    printf("\nTotal Bill: ₹%.2f\n", cust.totalAmount);
}

// Main function
int main() {
    getCustomerDetails();
    customerBillCalculation();
    ebillSummary();
    return 0;
}
