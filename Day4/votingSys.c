/*Election Vote Count (Using Arrays)
Problem Statement:
A city conducts an election with 5 candidates.
Citizens cast their votes (numbers 1 to 5 representing candidates).
Write a program to:  
1. Read N votes into an array.  
2. Count the total votes for each candidate.  
3. Determine the winner (candidate with the highest votes).  

Function Prototypes:
void countVotes(int votes[], int n, int candidateVotes[]);
int findWinner(int candidateVotes[]);
Sample Test Case:  
Input:  
Enter number of votes: 10  
Enter votes (1-5): 1 2 2 3 1 4 2 5 1 1  
Output:
Candidate 1: 4 votes  
Candidate 2: 3 votes  
Candidate 3: 1 vote  
Candidate 4: 1 vote  
Candidate 5: 1 vote  
Winner: Candidate 1*/

#include <stdio.h>

#define CANDIDATES 5  // Number of candidates

void countVotes(int votes[], int n, int candidateVotes[]);
int findWinner(int candidateVotes[]);

int main() {
    int n;
    
    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &n);

    int votes[n];
    int candidateVotes[CANDIDATES] = {0};  // Array to store vote counts for each candidate

    // Read votes
    printf("Enter votes (1-%d):\n", CANDIDATES);
    for (int i = 0; i < n; i++) {
        scanf("%d", &votes[i]);
        if (votes[i] < 1 || votes[i] > CANDIDATES) {
            printf("Invalid vote! Only numbers 1-%d are allowed.\n", CANDIDATES);
            i--; // Repeat the input for the invalid vote
        }
    }

    // Count votes
    countVotes(votes, n, candidateVotes);

    // Display results
    printf("\nElection Results:\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i + 1, candidateVotes[i]);
    }

    // Find and display the winner
    int winner = findWinner(candidateVotes);
    printf("Winner: Candidate %d\n", winner);

    return 0;
}

// Function to count votes
void countVotes(int votes[], int n, int candidateVotes[]) {
    for (int i = 0; i < n; i++) {
        candidateVotes[votes[i] - 1]++;
    }
}

// Function to determine the winner
int findWinner(int candidateVotes[]) {
    int maxVotes = 0, winner = 0;
    for (int i = 0; i < CANDIDATES; i++) {
        if (candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            winner = i + 1;
        }
    }
    return winner;
}
