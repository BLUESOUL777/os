#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    // STEP 1: Input requests
    for(int i = 0; i < n; i++) {
        printf("Enter request %d: ", i+1);
        scanf("%d", &req[i]);
    }

    int head, direction;

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    int total_seek = 0;

    // STEP 2: Sort requests
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence: %d ", head);

    int original_head = head;

    // STEP 3: LOOK logic
    if(direction == 1) { // RIGHT

        // Move right side
        for(int i = 0; i < n; i++) {
            if(req[i] >= original_head) {
                total_seek += abs(head - req[i]);
                head = req[i];
                printf("-> %d ", head);
            }
        }

        // Reverse (no going to disk end)
        for(int i = n-1; i >= 0; i--) {
            if(req[i] < original_head) {
                total_seek += abs(head - req[i]);
                head = req[i];
                printf("-> %d ", head);
            }
        }

    } else { // LEFT

        // Move left side
        for(int i = n-1; i >= 0; i--) {
            if(req[i] <= original_head) {
                total_seek += abs(head - req[i]);
                head = req[i];
                printf("-> %d ", head);
            }
        }

        // Reverse (no going to 0)
        for(int i = 0; i < n; i++) {
            if(req[i] > original_head) {
                total_seek += abs(head - req[i]);
                head = req[i];
                printf("-> %d ", head);
            }
        }
    }

    // STEP 4: Output
    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}