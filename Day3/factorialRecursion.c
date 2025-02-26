/*Factorial Calculation (Using Recursion)
Problem Statement:
Write a program using a recursive function to compute the factorial of a given number.  
Function Prototype:  
long factorial(int n);
Sample Test Case:
Input: 
Enter a number: 5  
Output:  
Factorial of 5 is 120*/

#include <stdio.h>

// Function to calculate factorial using recursion
long long factorial(int n) {
    if (n == 0 || n == 1)  // Base case: Factorial of 0 or 1 is 1
        return 1;
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", number, factorial(number));
    }

    return 0;
}
