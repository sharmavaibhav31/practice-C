#include <stdio.h>
#include <windows.h> 
int main() {
    int pos = 0;
    int direction = 1; 
    while (1) {
        system("cls");
        for (int i = 0; i < pos; i++) {
            printf(" ");
        }
        printf((pos % 2 == 0) ? "/" : "\\");
        printf("\n");
        pos += direction;
        if (pos == 100 || pos == 0)
            direction = -direction;
        Sleep(100);
    }
    return 0;
}