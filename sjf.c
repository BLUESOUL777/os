#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int wt[n], tat[n], ct[n];

    // STEP 1: Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];  // remaining time = burst time initially
    }

    int time = 0, completed = 0;

    // STEP 2: Process scheduling
    while(completed < n) {

        int idx = -1;
        int min = 9999;

        // Find process with smallest remaining time
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {

                if(rt[i] < min) {
                    min = rt[i];
                    idx = i;
                }
            }
        }

        // If no process available → CPU idle
        if(idx == -1) {
            time++;
        }

        else {
            rt[idx]--;   // execute for 1 unit
            time++;

            // If process finishes
            if(rt[idx] == 0) {
                completed++;

                ct[idx] = time;  // completion time
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
    }

    // STEP 3: Output
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}