#include <stdio.h>

int main() {
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    // STEP 1: Input pages
    for(int i = 0; i < n; i++) {
        printf("Enter page %d: ", i+1);
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f], time[f];

    // frame[] → stores pages
    // time[] → stores last used time

    for(int i = 0; i < f; i++) {
        frame[i] = -1;  // empty
        time[i] = 0;
    }

    int counter = 0;
    int hit = 0, fault = 0;

    // STEP 2: Process pages
    for(int i = 0; i < n; i++) {

        int found = -1;

        // check HIT
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = j;
                break;
            }
        }

        // HIT
        if(found != -1) {
            hit++;
            time[found] = ++counter;  // update usage time
        }

        // MISS
        else {
            fault++;

            int index = -1;

            // check empty frame first
            for(int j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    index = j;
                    break;
                }
            }

            // if no empty → find least recently used
            if(index == -1) {
                int min = time[0];
                index = 0;

                for(int j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        index = j;
                    }
                }
            }

            // replace page
            frame[index] = pages[i];
            time[index] = ++counter;
        }

        // print frame status
        printf("\nPage %d -> %s | Frames: ",
               pages[i],
               found != -1 ? "HIT" : "MISS");

        for(int j = 0; j < f; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
    }

    // STEP 3: Output
    printf("\n\nTotal Hits = %d", hit);
    printf("\nTotal Faults = %d\n", fault);

    return 0;
}