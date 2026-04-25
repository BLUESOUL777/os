#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    // STEP 1: Input
    for(int i = 0; i < n; i++) {
        printf("Enter request %d: ", i+1);
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    int head;
    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;

    printf("\nSeek Sequence: %d ", head);

    // STEP 2: Process
    for(int i = 0; i < n; i++) {

        int min = 9999, index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);

                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += abs(head - req[index]);
        head = req[index];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    return 0;
}