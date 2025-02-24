/* Student Gradebook
Design a student gradebook system that calculates the average grade for a student based on their assignments and exams. 
Write a program that uses loop logic to:
Calculate the total score for each assignment and exam
Calculate the average grade for the student
Display the gradebook details, including assignment and exam scores
Assume a list of assignments and exams with scores:
| Assignment/Exam | Score |
|      --         |  --   |
| Assignment 1    |  80   |
| Assignment 2    |  90   |
| Exam 1          |  85   |*/

#include <stdio.h>

int main() {
    int numberOfScores;  // Number of assignments and exams
    printf("Enter the number of assignments and exams: ");
    scanf("%d", &numberOfScores);

    char categories[numberOfScores][30]; // Stores assignment/exam names
    int scores[numberOfScores];          // Stores scores
    int total = 0;
    float average;

    // Input grades
    for (int i = 0; i < numberOfScores; i++) {
        printf("Enter name of Assignment/Exam %d: ", i + 1);
        scanf(" %[^\n]", categories[i]); // Read string with spaces
        printf("Enter score for %s: ", categories[i]);
        scanf("%d", &scores[i]);
        total += scores[i]; // Calculate total score
    }

    // Calculate average
    average = (float)total / numberOfScores;

    // Display Gradebook
    printf("\nStudent Gradebook:\n");
    printf("-------------------------------\n");
    printf("Assignment/Exam\t Score\n");
    printf("-------------------------------\n");
    for (int i = 0; i < numberOfScores; i++) {
        printf("%s\t %d\n", categories[i], scores[i]);
    }
    printf("-------------------------------\n");
    printf("Total Score: %d\n", total);
    printf("Average Grade: %.2f\n", average);

    // Determine grade category
    if (average >= 90) {
        printf("Final Grade: A (Excellent!)\n");
    } else if (average >= 80) {
        printf("Final Grade: B (Good Job!)\n");
    } else if (average >= 70) {
        printf("Final Grade: C (Needs Improvement)\n");
    } else {
        printf("Final Grade: F (Fail, better luck next time!)\n");
    }

    return 0;
}
