#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], rt[n], wt[n], tat[n];

    // STEP 1: Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    // STEP 2: Round Robin execution
    while(completed < n) {

        for(int i = 0; i < n; i++) {

            if(rt[i] > 0) {

                // If remaining time > quantum
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }

                // If process finishes
                else {
                    time += rt[i];
                    wt[i] = time - bt[i];  // waiting time
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    }

    // STEP 3: Calculate TAT and print
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];

        printf("%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}