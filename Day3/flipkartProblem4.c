/*Question 4: Technical Debt Reduction
Problem Statement:
Simulate a technical debt reduction program in Flipkart’s platform. 
Assume that the platform has 1000 lines of code, and each line has a technical debt of 10% (0.1). 
Simulate the reduction over time and display the progress.*/

#include <stdio.h>

#define TOTAL_CODE_LINES 1000
#define INITIAL_DEBT 0.1
#define REDUCTION_PER_CYCLE 0.02

int main() {
    float currentDebt = INITIAL_DEBT * TOTAL_CODE_LINES;
    int cycle = 0;

    printf("Technical Debt Reduction Simulation:\n");
    
    while (currentDebt > 0) {
        printf("Cycle %d: Remaining Technical Debt: %.2f lines\n", cycle, currentDebt);
        currentDebt -= (TOTAL_CODE_LINES * REDUCTION_PER_CYCLE);
        if (currentDebt < 0) currentDebt = 0;
        cycle++;
    }

    printf("Technical debt fully reduced after %d cycles.\n", cycle);
    
    return 0;
}
