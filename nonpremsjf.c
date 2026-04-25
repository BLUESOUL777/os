#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];

    // STEP 1: Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // STEP 2: Sort by Burst Time (SJF logic)
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(bt[j] < bt[i]) {
                int temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap pid
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // STEP 3: First process
    wt[0] = 0;
    tat[0] = bt[0];

    // STEP 4: Remaining processes
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    // STEP 5: Output
    float total_wt = 0, total_tat = 0;

    printf("\nOrder (SJF): ");
    for(int i = 0; i < n; i++)
        printf("P%d ", pid[i]);

    printf("\n\nPID\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}