#include <stdio.h>

#define MAX 10

int main() {
    int n, m, i, j, k;
    int alloc[MAX][MAX], request[MAX][MAX];
    int avail[MAX], finish[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Initialize finish array
    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            }
        }
        finish[i] = (flag == 0) ? 1 : 0;
    }

    int work[MAX];
    for(i = 0; i < m; i++)
        work[i] = avail[i];

    int changed = 1;

    while(changed) {
        changed = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                for(j = 0; j < m; j++)
                    if(request[i][j] > work[j])
                        break;

                if(j == m) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    changed = 1;
                }
            }
        }
    }

    int deadlock = 0;
    printf("\nProcesses in Deadlock: ");
    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("None (No Deadlock)");

    printf("\n");
    return 0;
}
