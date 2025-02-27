/*Student Marks Sorting (Using 2D Arrays)
Problem Statement:
A college stores student marks in a 2D array where:  
- Rows represent students
- Columns represent subjects  
1. Read marks for N students across M subjects.  
2. Calculate and display each student's total marks.  
3. Sort students in descending order of total marks.  

Function Prototypes:  
void calculateTotalMarks(int marks[][M], int n, int totalMarks[]);
void sortStudents(int totalMarks[], int n);
Sample Test Case:  
Input:  
Enter number of students: 3  
Enter number of subjects: 3  
Enter marks:  
Student 1: 70 80 90  
Student 2: 85 90 95  
Student 3: 60 70 75  
Output:
Student 2: Total Marks = 270  
Student 1: Total Marks = 240  
Student 3: Total Marks = 205  */

#include <stdio.h>

void calculateTotalMarks(int marks[][10], int n, int m, int totalMarks[]);
void sortStudents(int totalMarks[], int n, int studentIds[]);

int main() {
    int N, M;
    
    // Get the number of students and subjects
    printf("Enter number of students: ");
    scanf("%d", &N);
    printf("Enter number of subjects: ");
    scanf("%d", &M);

    int marks[N][M];          // 2D array to store marks
    int totalMarks[N];        // Array to store total marks of each student
    int studentIds[N];        // Array to store student IDs for sorting

    // Read student marks
    printf("Enter student marks:\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d: ", i + 1);
        studentIds[i] = i + 1;  // Assign student ID
        for (int j = 0; j < M; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Calculate total marks for each student
    calculateTotalMarks(marks, N, M, totalMarks);

    // Sort students based on total marks (descending order)
    sortStudents(totalMarks, N, studentIds);

    // Display sorted results
    printf("\nSorted Student Marks:\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d: Total Marks = %d\n", studentIds[i], totalMarks[i]);
    }

    return 0;
}

// Function to calculate total marks for each student
void calculateTotalMarks(int marks[][10], int n, int m, int totalMarks[]) {
    for (int i = 0; i < n; i++) {
        totalMarks[i] = 0; // Initialize total marks to 0 for each student
        for (int j = 0; j < m; j++) {
            totalMarks[i] += marks[i][j]; // Sum marks for each student
        }
    }
}

// Function to sort students in descending order of total marks
void sortStudents(int totalMarks[], int n, int studentIds[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (totalMarks[i] < totalMarks[j]) {
                // Swap total marks
                int temp = totalMarks[i];
                totalMarks[i] = totalMarks[j];
                totalMarks[j] = temp;

                // Swap student IDs to maintain mapping
                int tempId = studentIds[i];
                studentIds[i] = studentIds[j];
                studentIds[j] = tempId;
            }
        }
    }
}
