#include <stdio.h>

int main() {
    int n;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pageTable[n];

    // STEP 1: Input page table
    for(int i = 0; i < n; i++) {
        printf("Enter frame number for page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    int pageSize;
    printf("Enter page size: ");
    scanf("%d", &pageSize);

    int logicalAddress;
    printf("Enter logical address: ");
    scanf("%d", &logicalAddress);

    // STEP 2: Break logical address
    int pageNumber = logicalAddress / pageSize;
    int offset = logicalAddress % pageSize;

    // STEP 3: Get frame number
    int frameNumber = pageTable[pageNumber];

    // STEP 4: Calculate physical address
    int physicalAddress = frameNumber * pageSize + offset;

    // OUTPUT
    printf("\nPage Number = %d", pageNumber);
    printf("\nOffset = %d", offset);
    printf("\nFrame Number = %d", frameNumber);
    printf("\nPhysical Address = %d\n", physicalAddress);

    return 0;
}