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

    // initialize frames as empty
    for(int i = 0; i < f; i++)
        frame[i] = -1;

    int index = 0;  // FIFO pointer
    int hit = 0, fault = 0;

    // STEP 2: Process pages
    for(int i = 0; i < n; i++) {

        int found = 0;

        // check if page already exists (HIT)
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hit++;
                break;
            }
        }

        // if MISS → replace oldest
        if(found == 0) {
            frame[index] = pages[i];
            index = (index + 1) % f;  // circular move
            fault++;
        }

        // print current frame
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