#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter head: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    // sort
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(req[i]>req[j]){
                int t=req[i]; req[i]=req[j]; req[j]=t;
            }

    int total=0;

    printf("\nSequence: %d ", head);

    // RIGHT movement
    for(int i=0;i<n;i++){
        if(req[i]>=head){
            total+=abs(head-req[i]);
            head=req[i];
            printf("-> %d ", head);
        }
    }

    // go to end
    total+=abs(head-(size-1));
    head=size-1;
    printf("-> %d ", head);

    // jump to start
    total+=(size-1);
    head=0;
    printf("-> %d ", head);

    // remaining
    for(int i=0;i<n;i++){
        if(req[i]<head){
            total+=abs(head-req[i]);
            head=req[i];
            printf("-> %d ", head);
        }
    }

    printf("\nTotal Seek = %d\n", total);
}