/*Question 4: Technical Debt Reduction (Reducing Buggy Code in Instagram’s Backend)
Problem Statement:
Simulate a technical debt reduction program in Instagram’s backend. 
Assume that the platform has 10,000 lines of code, and each line has a technical debt of 5% (0.05). 
Simulate the reduction over time and display the progress.*/

#include <stdio.h>

#define TOTAL_CODE_LINES 10000
#define INITIAL_DEBT 0.05
#define REDUCTION_PER_CYCLE 0.01

int main() {
    float currentDebt = INITIAL_DEBT * TOTAL_CODE_LINES;
    int cycle = 0;

    printf("Instagram's Backend Code Technical Debt Reduction Simulation:\n");
    
    while (currentDebt > 0) {
        printf("Cycle %d: Remaining Technical Debt: %.2f lines\n", cycle, currentDebt);
        currentDebt -= (TOTAL_CODE_LINES * REDUCTION_PER_CYCLE);
        if (currentDebt < 0) currentDebt = 0;
        cycle++;
    }

    printf("Technical debt fully reduced after %d cycles.\n", cycle);
    
    return 0;
}

