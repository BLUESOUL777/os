#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m];

    // STEP 1: Input block sizes
    for(int i = 0; i < m; i++) {
        printf("Enter block %d size: ", i+1);
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n];

    // STEP 2: Input process sizes
    for(int i = 0; i < n; i++) {
        printf("Enter process %d size: ", i+1);
        scanf("%d", &process[i]);
    }

    int allocation[n];
    int used[m];

    // Initialize
    for(int i = 0; i < m; i++)
        used[i] = 0;

    for(int i = 0; i < n; i++)
        allocation[i] = -1;

    // STEP 3: Worst Fit logic
    for(int i = 0; i < n; i++) {

        int worstIndex = -1;

        for(int j = 0; j < m; j++) {

            // check if block fits and is unused
            if(used[j] == 0 && block[j] >= process[i]) {

                // choose largest block
                if(worstIndex == -1 || block[j] > block[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        // allocate if found
        if(worstIndex != -1) {
            allocation[i] = worstIndex;
            used[worstIndex] = 1;
        }
    }

    // STEP 4: Output
    printf("\nProcess\tSize\tBlock\n");

    for(int i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("P%d\t%d\tNot Allocated\n", i+1, process[i]);
    }

    return 0;
}