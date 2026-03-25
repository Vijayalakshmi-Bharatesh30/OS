#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20], q[20], done[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Queue(1-10) for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&q[i]);
        done[i] = 0;
    }

    while(completed < n)
    {
        int idx = -1;
        int best_q = 11;
        int min_at = 9999;

        for(i=0;i<n;i++)
        {
            if(done[i]==0 && at[i]<=time)
            {
                if(q[i] < best_q)
                {
                    best_q = q[i];
                    min_at = at[i];
                    idx = i;
                }
                else if(q[i] == best_q)
                {
                    if(at[i] < min_at)
                    {
                        min_at = at[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1)
        {
            time += bt[idx];

            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = 1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tQ\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],q[i],ct[i],tat[i],wt[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage WT = %.2f",avg_wt/n);
    printf("\nAverage TAT = %.2f\n",avg_tat/n);

    return 0;
}
