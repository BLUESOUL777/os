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

    int frame[f];

    // initialize frames
    for(int i = 0; i < f; i++)
        frame[i] = -1;

    int hit = 0, fault = 0;

    // STEP 2: Process pages
    for(int i = 0; i < n; i++) {

        int found = 0;

        // check HIT
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hit++;
                break;
            }
        }

        // MISS
        if(found == 0) {
            fault++;

            int index = -1;

            // check empty frame
            for(int j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    index = j;
                    break;
                }
            }

            // if no empty → find optimal replacement
            if(index == -1) {
                int farthest = -1;

                for(int j = 0; j < f; j++) {
                    int k;

                    // check future usage
                    for(k = i+1; k < n; k++) {
                        if(frame[j] == pages[k])
                            break;
                    }

                    // if not used again
                    if(k == n) {
                        index = j;
                        break;
                    }

                    // choose farthest use
                    if(k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }
            }

            // replace page
            frame[index] = pages[i];
        }

        // print frames
        printf("\nPage %d -> %s | Frames: ",
               pages[i],
               found ? "HIT" : "MISS");

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