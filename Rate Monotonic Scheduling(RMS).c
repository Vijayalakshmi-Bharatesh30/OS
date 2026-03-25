#include <stdio.h>

int gcd(int a, int b)
{
    while(b!=0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int n, i, time;
    int cap[10], rt[10], period[10];
    int total_time;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Capacity and Period for P%d: ",i+1);
        scanf("%d%d",&cap[i],&period[i]);
        rt[i] = 0;
    }

    total_time = period[0];
    for(i=1;i<n;i++)
        total_time = lcm(total_time, period[i]);

    printf("\nSimulation Time (LCM) = %d\n", total_time);

    printf("\nTime\tProcess\n");

    for(time=0; time<total_time; time++)
    {
        int idx = -1;
        int min_period = 9999;

        for(i=0;i<n;i++)
        {
            if(time % period[i] == 0)
                rt[i] = cap[i];

            if(rt[i] > 0)
            {
                if(period[i] < min_period)
                {
                    min_period = period[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            printf("%d\tP%d\n",time,idx+1);
            rt[idx]--;
        }
        else
        {
            printf("%d\tIdle\n",time);
        }
    }

    return 0;
}
