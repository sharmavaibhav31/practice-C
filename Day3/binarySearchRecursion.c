/*Binary Search Implementation
Write a C program that implements the binary search algorithm to find a target element in a sorted array using recursion.
Requirements:
Accept user input for:
The number of elements in the array.
The sorted array elements.
The target element to search for.
Implement a recursive binary search function that returns the position of the target element (if found) or -1 if not found.
Display appropriate messages for search results.*/

#include <stdio.h>

// Recursive Binary Search Function
int binarySearch(int *arr, int low, int high, int target) {
    if (low > high) return -1; // Base case: Element not found

    int mid = (low + high) / 2;

    if (arr[mid] == target) 
        return mid; // Target found
    else if (arr[mid] > target) 
        return binarySearch(arr, low, mid - 1, target); // Search left subarray
    else 
        return binarySearch(arr, mid + 1, high, target); // Search right subarray
}

int main() {
    int n, target, pos;
    
    // Taking array size input
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];

    // Taking sorted array input
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking target element input
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Performing binary search
    pos = binarySearch(arr, 0, n - 1, target);

    // Displaying the result
    if (pos >= 0)
        printf("Target element %d found at position %d.\n", target, pos + 1);
    else
        printf("Target element %d not found.\n", target);

    return 0;
}
