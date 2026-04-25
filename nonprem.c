#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int wt[n], tat[n], ct[n];
    int done[n];

    // STEP 1: Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority (lower = higher priority): ");
        scanf("%d", &pr[i]);

        done[i] = 0; // not completed
    }

    int time = 0;
    int completed = 0;

    // STEP 2: Scheduling
    while(completed < n) {

        int idx = -1;
        int best_pr = 9999;

        // Find highest priority among arrived processes
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {

                if(pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
            }
        }

        // If no process has arrived → CPU idle
        if(idx == -1) {
            time++;
        }

        else {
            // Calculate waiting time
            wt[idx] = time - at[idx];

            if(wt[idx] < 0)
                wt[idx] = 0;

            // Execute process fully
            time += bt[idx];

            ct[idx] = time; // completion time
            tat[idx] = ct[idx] - at[idx];

            done[idx] = 1;
            completed++;
        }
    }

    // STEP 3: Output
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}