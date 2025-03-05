#include <stdio.h>
#include <windows.h> // For Sleep()
#include <stdlib.h>  // For rand()
#include <time.h>    // For time()

int main() {
    int snakePos = 0;     
    int snakeLength = 1;
    int dashPos;          
    int direction = 1;   

    srand(time(NULL));    
    dashPos = rand() % 100; 
    while (snakeLength <= 5) {
        system("cls"); 
        for (int i = 0; i < 100; i++) {
            if (i == dashPos)
                printf("-");
            else if (i >= snakePos && i < snakePos + snakeLength)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
        snakePos += direction;

        if (snakePos == dashPos) {
            snakeLength++;
            dashPos = rand() % 100; 
        }

        if (snakePos + snakeLength >= 100 || snakePos <= 0)
            direction = -direction;

        Sleep(200); 
    }
    printf("\nGame Over! Snake is fully grown.\n");
    return 0;
}
