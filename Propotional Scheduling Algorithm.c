#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int n, tickets[MAX];
    int totalTickets = 0;
    int i, cycle, cycles = 10;

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter tickets for P%d: ", i + 1);
        scanf("%d", &tickets[i]);
        totalTickets += tickets[i];
    }

    // Seed random generator
    srand(time(0));

    printf("\nLottery Scheduling Execution (%d cycles):\n", cycles);

    for (cycle = 1; cycle <= cycles; cycle++) {
        int winningTicket = rand() % totalTickets + 1;

        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += tickets[i];

            if (winningTicket <= sum) {
                printf("Cycle %d -> P%d selected (Ticket %d)\n",
                       cycle, i + 1, winningTicket);
                break;
            }
        }
    }

    return 0;
}
