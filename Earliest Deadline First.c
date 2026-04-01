#include <stdio.h>

struct Task
{
    int id;
    int capacity;
    int period;
    int deadline;
    int remaining;
    int next_arrival;
};

int main()
{
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];

    for(int i = 0; i < n; i++)
    {
        t[i].id = i + 1;
        printf("\nTask %d\n", i + 1);
        printf("Capacity: ");
        scanf("%d", &t[i].capacity);
        printf("Period: ");
        scanf("%d", &t[i].period);
        printf("Deadline: ");
        scanf("%d", &t[i].deadline);

        t[i].remaining = 0;
        t[i].next_arrival = 0;
    }

    int hyperperiod = 1;

    for(int i = 0; i < n; i++)
    {
        int a = hyperperiod, b = t[i].period;
        while(a != b)
        {
            if(a < b)
                a += hyperperiod;
            else
                b += t[i].period;
        }
        hyperperiod = a;
    }

    printf("\nExecution Order:\n");

    for(int time = 0; time < hyperperiod; time++)
    {
        for(int i = 0; i < n; i++)
        {
            if(time == t[i].next_arrival)
            {
                t[i].remaining = t[i].capacity;
                t[i].next_arrival += t[i].period;
            }
        }

        int idx = -1;
        int min_deadline = 100000;

        for(int i = 0; i < n; i++)
        {
            if(t[i].remaining > 0)
            {
                int abs_deadline = t[i].next_arrival - t[i].period + t[i].deadline;
                if(abs_deadline < min_deadline)
                {
                    min_deadline = abs_deadline;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            printf("P%d -> ", t[idx].id);
            t[idx].remaining--;
        }
        else
        {
            printf("Idle -> ");
        }
    }

    printf("END\n");

    return 0;
}
