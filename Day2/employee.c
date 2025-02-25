/*Employee Salary Calculation and Performance Evaluation System

Develop a C program to manage employee salary calculations and performance evaluation based on their attendance. The program should:

Accept employee details (Name, ID, Basic Salary, Working Days).
Calculate the final salary using the following rules:
If working days ≥ 25, add a 5% bonus to the basic salary.
If working days ≤ 10, reduce the salary by 50%.
Otherwise, keep the basic salary unchanged.
Evaluate employee performance based on working days:
≥ 25 days → "Excellent"
16-24 days → "Good"
≤ 15 days → "Needs Improvement"
Display employee details, salary breakdown, and performance.
Ensure input validation, such as restricting working days to ≤ 30.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKING_DAYS 30
#define MAX_NAME_LENGTH 100

// Structure to store employee details
typedef struct {
    char employeeName[MAX_NAME_LENGTH];
    int employeeId;
    float basicSalary;
    int workingDays;
} Employee;

// Function to calculate final salary
float calculateSalary(Employee emp) {
    float finalSalary;

    if (emp.workingDays >= 25) {
        finalSalary = emp.basicSalary + (emp.basicSalary * 0.05); // 5% bonus
    } else if (emp.workingDays <= 10) {
        finalSalary = emp.basicSalary / 2; // 50% salary cut
    } else {
        finalSalary = emp.basicSalary;
    }

    return finalSalary;
}

// Function to display employee statistics
void displayEmployeeStats(Employee emp, float finalSalary) {
    printf("\n---- Employee Salary & Performance Details ----\n");
    printf("Employee Name   : %s\n", emp.employeeName);
    printf("Employee ID     : %d\n", emp.employeeId);
    printf("Basic Salary    : %.2f\n", emp.basicSalary);
    printf("Final Salary    : %.2f\n", finalSalary);
    printf("Working Days    : %d\n", emp.workingDays);

    // Performance evaluation
    printf("Performance     : ");
    if (emp.workingDays >= 25) {
        printf("Excellent\n");
    } else if (emp.workingDays >= 16) {
        printf("Good\n");
    } else {
        printf("Needs Improvement\n");
    }
}

int main() {
    Employee emp;

    // Input employee details
    printf("\nEnter Employee Details:\n");
    printf("Enter Employee Name: ");
    fgets(emp.employeeName, MAX_NAME_LENGTH, stdin);
    emp.employeeName[strcspn(emp.employeeName, "\n")] = 0; // Remove newline character

    printf("Enter Employee ID: ");
    scanf("%d", &emp.employeeId);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basicSalary);

    printf("Enter Total Days Worked: ");
    scanf("%d", &emp.workingDays);

    // Validate working days
    if (emp.workingDays > MAX_WORKING_DAYS || emp.workingDays < 0) {
        printf("Error: Invalid number of working days! Must be between 0 and 30.\n");
        return 1; // Exit program
    }

    // Calculate salary
    float finalSalary = calculateSalary(emp);

    // Display employee details
    displayEmployeeStats(emp, finalSalary);

    return 0;
}
