#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, dir;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter head: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Direction (0=left,1=right): ");
    scanf("%d", &dir);

    // sort
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(req[i]>req[j]){
                int t=req[i]; req[i]=req[j]; req[j]=t;
            }

    int total = 0;

    printf("\nSequence: %d ", head);

    if(dir==1){
        for(int i=0;i<n;i++)
            if(req[i]>=head){
                total+=abs(head-req[i]);
                head=req[i];
                printf("-> %d ", head);
            }

        total+=abs(head-(size-1));
        head=size-1;
        printf("-> %d ", head);

        for(int i=n-1;i>=0;i--)
            if(req[i]<head){
                total+=abs(head-req[i]);
                head=req[i];
                printf("-> %d ", head);
            }
    }
    else{
        for(int i=n-1;i>=0;i--)
            if(req[i]<=head){
                total+=abs(head-req[i]);
                head=req[i];
                printf("-> %d ", head);
            }

        total+=abs(head-0);
        head=0;
        printf("-> %d ", head);

        for(int i=0;i<n;i++)
            if(req[i]>head){
                total+=abs(head-req[i]);
                head=req[i];
                printf("-> %d ", head);
            }
    }

    printf("\nTotal Seek = %d\n", total);
}