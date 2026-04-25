#include <stdio.h>

int main() {
    int n; // number of processes

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n]; // burst time array
    int wt[n]; // waiting time array
    int tat[n]; // turnaround time array

    // Input burst times
    for(int i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // First process waiting time is always 0
    wt[0] = 0;

    // Calculate waiting time for each process
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; 
        // waiting time = sum of previous burst times
    }

    // Calculate turnaround time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; 
        // turnaround time = waiting time + burst time
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");

    // Display values and calculate totals
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate and display averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}