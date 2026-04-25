#include <stdio.h>

int main() {
    int n, m;

    printf("Enter processes: ");
    scanf("%d",&n);

    printf("Enter resources: ");
    scanf("%d",&m);

    int alloc[n][m], req[n][m], avail[m];

    printf("\nAllocation:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nRequest:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("\nAvailable:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&avail[j]);

    int finish[n];
    for(int i=0;i<n;i++) finish[i]=0;

    int count=0;

    while(count<n){
        int found=0;

        for(int i=0;i<n;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<m;j++)
                    if(req[i][j] > avail[j])
                        break;

                if(j==m){
                    for(int k=0;k<m;k++)
                        avail[k]+=alloc[i][k];

                    finish[i]=1;
                    count++;
                    found=1;
                }
            }
        }

        if(!found) break;
    }

    // check deadlock
    for(int i=0;i<n;i++){
        if(!finish[i]){
            printf("\nDeadlock detected!\n");
            return 0;
        }
    }

    printf("\nNo Deadlock\n");
}