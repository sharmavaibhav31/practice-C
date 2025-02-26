/*Hospital Billing System (Using Functions & Decision-Making)
Problem Statement: A hospital needs a program to calculate a patient’s bill based on ward type and number of days admitted.  
1. Charges per Day:
   - General Ward → ₹1000  
   - Semi-Private → ₹2000  
   - Private      → ₹5000  
2. If the patient stays for more than 7 days, they get a 5% discount on the total bill.  
3. Use functions for bill calculation.  
Requirements:  
Input:
  - Patient Name  
  - Ward Type (General/Semi-Private/Private)  
  - Number of Days Admitted  
Output:  
  - Total Bill (Before and After Discount)  
Function Prototype Example:
float calculateBill(char wardType, int days);
Sample Test Case:  
Input:
Enter Patient Name: Rajesh  
Enter Ward Type (G/S/P): S  
Enter Number of Days: 8  
Output:
Patient Name: Rajesh  
Total Bill Before Discount: ₹16000  
Discount Applied: ₹800  
Final Bill Amount: ₹15200*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100
#define DISCOUNT 0.05

// Structure to store patient details
typedef struct {
    char patientName[MAX_NAME_LENGTH];
    char wardType;
    float totalBill;
    int numberOfDays;
} Patient;

Patient patient;
float totalDiscount = 0.0, beforeDiscount = 0.0;

// Function to get patient details
void getPatientInfo() {
    printf("Enter Patient Name: ");
    getchar();  // Clear buffer before taking input
    fgets(patient.patientName, MAX_NAME_LENGTH, stdin);
    patient.patientName[strcspn(patient.patientName, "\n")] = 0; // Remove newline character

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", &patient.wardType); // Space before %c to consume newline

    printf("Enter Number of Days Admitted: ");
    scanf("%d", &patient.numberOfDays);
}

// Function to calculate the bill
float billCalculation(char wardType, int numberOfDays) {
    float totalBill = 0.0;

    switch (wardType) {
        case 'G': totalBill = 1000 * numberOfDays; break;
        case 'S': totalBill = 2000 * numberOfDays; break;
        case 'P': totalBill = 5000 * numberOfDays; break;  // Fixed Private ward charge
        default:
            printf("Error: Invalid ward type! Please enter G, S, or P.\n");
            return -1; // Indicate an error
    }

    beforeDiscount = totalBill;

    // Apply discount if stay > 7 days
    if (numberOfDays > 7) {
        totalDiscount = totalBill * DISCOUNT;
        totalBill -= totalDiscount;
    }

    return totalBill;
}

// Function to display bill summary
void billSummary() {
    printf("\n---- Hospital Billing Summary ----\n");
    printf("Patient Name: %s\n", patient.patientName);
    printf("Ward Type: %c\n", patient.wardType);
    printf("Total Bill Before Discount: ₹%.2f\n", beforeDiscount);
    printf("Discount Applied: ₹%.2f\n", totalDiscount);
    printf("Total Bill After Discount: ₹%.2f\n", patient.totalBill);
}

int main() {
    getPatientInfo();
    
    // Calculate bill and store it in structure
    float totalBill = billCalculation(patient.wardType, patient.numberOfDays);
    
    if (totalBill == -1) {
        printf("Program terminated due to invalid input.\n");
        return 1; // Exit with error
    }
    
    patient.totalBill = totalBill;

    // Display final bill
    billSummary();

    return 0;
}
