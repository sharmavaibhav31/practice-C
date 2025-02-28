/*1. Undo-Redo Functionality Using Stack 
Problem Statement:
Implement an Undo-Redo system using two stacks:  
- Undo Stack stores the last performed actions.  
- Redo Stack stores undone actions.  

Operations: 
1. Perform Action: Push onto Undo Stack.  
2. Undo: Pop from Undo Stack and push onto Redo Stack.  
3. Redo: Pop from Redo Stack and push back to Undo Stack.  

Function Prototypes:  
void performAction(char action[]);
void undo();
void redo();
void displayStack();

Sample Test Case:  
Input:  
Perform: "Write Code"  
Perform: "Save File"  
Undo  
Redo

Output:
Performed Actions: ["Write Code", "Save File"]  
Undo: "Save File" moved to Redo Stack  
Redo: "Save File" moved back to Undo Stack*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack for Undo and Redo
char undoStack[MAX_SIZE][100];
char redoStack[MAX_SIZE][100];

int undoTop = -1, redoTop = -1;

// Function Prototypes
void performAction(char action[]);
void undo();
void redo();
void displayStack();

// Function to push onto the Undo Stack (Perform an Action)
void performAction(char action[]) {
    if (undoTop == MAX_SIZE - 1) {
        printf("Undo Stack Overflow! Cannot perform more actions.\n");
        return;
    }
    undoTop++;
    strcpy(undoStack[undoTop], action);
    redoTop = -1;  // Clear redo stack when a new action is performed
    printf("Performed Action: %s\n", action);
}

// Function to Undo an Action
void undo() {
    if (undoTop == -1) {
        printf("Undo Stack is empty! Nothing to undo.\n");
        return;
    }
    redoTop++;
    strcpy(redoStack[redoTop], undoStack[undoTop]);
    printf("Undo: %s moved to Redo Stack\n", undoStack[undoTop]);
    undoTop--;
}

// Function to Redo an Action
void redo() {
    if (redoTop == -1) {
        printf("Redo Stack is empty! Nothing to redo.\n");
        return;
    }
    undoTop++;
    strcpy(undoStack[undoTop], redoStack[redoTop]);
    printf("Redo: %s moved back to Undo Stack\n", redoStack[redoTop]);
    redoTop--;
}

// Function to Display Stack Contents
void displayStack() {
    printf("\nUndo Stack:\n");
    for (int i = undoTop; i >= 0; i--) {
        printf(" - %s\n", undoStack[i]);
    }
    
    printf("\nRedo Stack:\n");
    for (int i = redoTop; i >= 0; i--) {
        printf(" - %s\n", redoStack[i]);
    }
    printf("\n");
}

// Main Function
int main() {
    char action[100];
    int choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Perform Action\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display Stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter Action: ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = 0;  // Remove trailing newline
                performAction(action);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
