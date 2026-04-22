#include <stdio.h>

#define MAX 100

void firstFit(int blocks[], int m, int processes[], int n);
void bestFit(int blocks[], int m, int processes[], int n);
void worstFit(int blocks[], int m, int processes[], int n);

int main() {
    int blocks[MAX], processes[MAX];
    int m, n, i;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blocks[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    firstFit(blocks, m, processes, n);
    bestFit(blocks, m, processes, n);
    worstFit(blocks, m, processes, n);

    return 0;
}

// FIRST FIT (no splitting)
void firstFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX], used[MAX] = {0};
    int i, j;

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(!used[j] && blocks[j] >= processes[i]) {
                allocation[i] = j;
                used[j] = 1;
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}

// BEST FIT (no splitting)
void bestFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX], used[MAX] = {0};
    int i, j, bestIdx;

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++) {
        bestIdx = -1;

        for(j = 0; j < m; j++) {
            if(!used[j] && blocks[j] >= processes[i]) {
                if(bestIdx == -1 || blocks[j] < blocks[bestIdx])
                    bestIdx = j;
            }
        }

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            used[bestIdx] = 1;
        }
    }

    printf("\nBest Fit Allocation:\n");
    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}

// WORST FIT (no splitting)
void worstFit(int blocks[], int m, int processes[], int n) {
    int allocation[MAX], used[MAX] = {0};
    int i, j, worstIdx;

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++) {
        worstIdx = -1;

        for(j = 0; j < m; j++) {
            if(!used[j] && blocks[j] >= processes[i]) {
                if(worstIdx == -1 || blocks[j] > blocks[worstIdx])
                    worstIdx = j;
            }
        }

        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            used[worstIdx] = 1;
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}
