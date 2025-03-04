#include <stdio.h>
#include <windows.h> // For Sleep()
#include <stdlib.h>  // For rand()
#include <time.h>    // For time()

#define WIDTH 30  // Width of the screen
#define LENGTH 5  // Max length the snake can grow

int main() {
    int snakePos = 0;     // Initial snake position
    int snakeLength = 1;  // Initial length of the snake
    int dashPos;          // Position of the dash
    int direction = 1;    // 1 = moving right, -1 = moving left

    srand(time(NULL));    // Seed for random number generator
    dashPos = rand() % WIDTH; // Place the dash randomly

    while (snakeLength <= LENGTH) {
        system("cls"); // Clear screen for animation effect

        // Print the screen
        for (int i = 0; i < WIDTH; i++) {
            if (i == dashPos)
                printf("-"); // Print dash
            else if (i >= snakePos && i < snakePos + snakeLength)
                printf("O"); // Print snake
            else
                printf(" ");
        }
        printf("\n");

        // Move snake forward
        snakePos += direction;

        // If snake reaches the dash, grow and place a new dash
        if (snakePos == dashPos) {
            snakeLength++;
            dashPos = rand() % WIDTH; // New random dash position
        }

        // Change direction if hitting edges
        if (snakePos + snakeLength >= WIDTH || snakePos <= 0)
            direction = -direction;

        Sleep(200); // Delay for animation
    }

    printf("\nGame Over! Snake is fully grown.\n");
    return 0;
}
